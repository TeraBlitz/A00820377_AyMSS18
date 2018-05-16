var express = require('express');
var router = express.Router();

let driver = require('./neo4j').driver;

router.get('/', getRecetas);
router.get('/:id', getReceta);
router.post('/', addReceta);
router.put('/:id', updateReceta);
router.delete('/:id', deleteReceta);

function getRecetas(req, res, next) {
  console.log('called');
  let query = req.query;
  let session = driver.session();
  session.run('MATCH (m:Receta) RETURN collect(m) AS recetas').then(
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

function getReceta(req, res, next) {
  let recteaId = parseInt(req.params.id);
  if (!recteaId) {
    return next(new Error('No se seleccionó rectea'));
  }
  let session = driver.session();
  let query = [
    'MATCH (r:Receta)',
    'WHERE ID(r)={recteaId}',
    'return {',
    'name: r.name, id: id(r),',
    'cost: r.cost, quantity: r.quantity',
    '} as recetea'
  ].join(' ');
  session.run(query, { recteaId: recteaId }).then(
    response => {
      let records = response.records;
      let item = null;
      if (records.length > 0) {
        item = records[0].toObject().recetea;
        item.id = item.id.toInt();
      }
      res.json({ success: item ? true : false, item: item });
    },
    error => {
      return next(new Error('Error buscando las materias primas'));
    }
  );
}

let recteasData = ['name', 'cost', 'quantity'];

function addReceta(req, res, next) {
  let body = req.body;
  if (recteasData.every(value => body.hasOwnProperty(value))) {
    let session = driver.session();
    session
      .run('MATCH (m:Receta {name: $name}) RETURN m', { name: req.body.name })
      .then(
        response => {
          if (response.records.length > 0) {
            // debug("match response",response);
            return next(new Error('La receta ya existe'));
          }
          session
            .run(
              `CREATE (m:Receta {
          name: $name,
          cost: $cost,
          quantity: $quantity
        }) RETURN m`,
              {
                name: req.body.name,
                cost: req.body.cost,
                quantity: req.body.quantity
              }
            )
            .then(
              response => {
                let receta = response.records[0].get('m').properties;
                receta.id = response.records[0].get('m').identity.toInt();
                res.json({ success: true, item: receta });
                session.close();
                driver.close();
              },
              error => {
                return next(new Error('Error creando la receta'));
              }
            );
        },
        error => {
          return next(new Error('Error buscando la receta'));
        }
      );
  } else {
    next(new Error('Faltan datos'));
  }
}

function updateReceta(req, res, next) {
  let recetaId = parseInt(req.params.id);
  let body = req.body;
  // debug("recetaId",recetaId);
  if (recteasData.some(value => body.hasOwnProperty(value))) {
    let session = driver.session();
    let query = [
      'MATCH (m:Receta)',
      'WHERE id(m) = {recetaId}',
      'SET m += {props}',
      'RETURN m'
    ].join(' ');
    session.run(query, { recetaId: recetaId, props: body }).then(
      response => {
        if (!response.records.length > 0) {
          return next(new Error('No se encontró la receta'));
        } else {
          res.json({ success: true });
        }
      },
      error => {
        return next(new Error('Error buscando la receta'));
      }
    );
  } else {
    next(new Error('Datos incorrectos'));
  }
}

function deleteReceta(req, res, next) {
  let recetaId = parseInt(req.params.id);
  // debug("recetaId",recetaId);
  let session = driver.session();
  let query = [
    'MATCH (m:Receta)',
    'WHERE id(m) = {recetaId}',
    'OPTIONAL MATCH (m)-[r]-()',
    'DELETE m, r'
  ].join(' ');
  session.run(query, { recetaId: recetaId }).then(
    response => {
      if (!response.summary.updateStatistics.nodesDeleted() > 0) {
        return next(new Error('No se encontró la receta'));
      } else {
        res.json({ success: true });
      }
    },
    error => {
      return next(
        new Error('Error eliminando la receta, puede que aún tenga relaciones')
      );
    }
  );
}

module.exports = router;
