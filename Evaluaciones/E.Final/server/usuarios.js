var express = require('express');
var router = express.Router();

let driver = require('./neo4j').driver;

router.get('/', getUsers);
router.post('/login', loginUser);
router.post('/register', registerUser);

function getUsers(req, res, next) {
  console.log('called');
  let query = req.query;
  let session = driver.session();
  session.run('MATCH (m:User) RETURN collect(m) AS users').then(
    response => {
      let responseRecord = response.records[0];
      // debug("responseRecord",responseRecord);
      let mapedRecords = responseRecord._fields[0].map(record => {
        // debug("record",record);
        let parsedRecord = record.properties;
        parsedRecord.id = record.identity.toInt();
        return parsedRecord;
      });
      res.json({ success: true, items: mapedRecords });
    },
    error => {
      console.log(error);
      return next(new Error('Error buscando las recetas'));
    }
  );
}

function loginUser(req, res, next) {
  let username = req.body.username;
  let password = req.body.password;
  if (username && password) {
    let session = driver.session();
    session
      .run('MATCH (u:User {name: $name}) RETURN u', { name: req.body.username })
      .then(
        response => {
          if (response.records.length == 0) {
            return res.json({
              success: false,
              token: null,
              message: 'No se encontró el usuario'
            });
          }
          let user = response.records[0].get('u');
          if (user.properties.password == req.body.password) {
            res.json({
              success: true
            });
          } else {
            res.json({
              success: false,
              token: null,
              message: 'Contraseña incorrecta'
            });
          }
          session.close();
          driver.close();
        },
        error => {
          return next(new Error('Error buscando el usuario'));
        }
      );
  } else {
    next(new Error('Faltan credenciales'));
  }
}

let userData = ['username', 'password', 'email'];

function registerUser(req, res, next) {
  let body = req.body;
  if (userData.every(value => body.hasOwnProperty(value))) {
    let session = driver.session();
    session
      .run('MATCH (u:User) WHERE u.name = $name OR u.email = $email RETURN u', {
        name: req.body.username,
        email: req.body.email
      })
      .then(
        response => {
          if (response.records.length > 0) {
            return next(new Error('El usuario o correo ya existe '));
          }
          session
            .run(
              'CREATE (u:User {name: $name, password: $password, email: $email}) RETURN u',
              {
                name: req.body.username,
                password: req.body.password,
                email: req.body.email
              }
            )
            .then(
              response => {
                let user = response.records[0].get('u');
                res.json({
                  success: true
                });
                session.close();
                driver.close();
              },
              error => {
                return next(new Error('Error creando el usuario'));
              }
            );
        },
        error => {
          return next(new Error('Error buscando el usuario'));
        }
      );
  } else {
    next(new Error('Faltan datos'));
  }
}

module.exports = router;
