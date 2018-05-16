var express = require('express');
var router = express.Router();

let driver = require('./neo4j').driver;

router.get('/', getMateriasPrimas);
router.get('/:id', getMateriaPrima);
router.post('/', addMateriaPrima);
router.put('/:id', updateMateriaPrima);
router.delete('/:id', deleteMateriaPrima);

let materiasPrimasData = ['name', 'cost', 'category'];

function getMateriasPrimas(req, res, next) {
  let query = req.query;
  let session = driver.session();
  session.run('MATCH (m:MateriaPrima) RETURN collect(m) AS materias').then(
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
      return next(new Error('Error buscando las materias primas'));
    }
  );
}

function getMateriaPrima(req, res, next) {
  let materiaId = parseInt(req.params.id);
  if (!materiaId) {
    return next(new Error('No se seleccionó materia prima'));
  }
  let session = driver.session();
  let query = [
    'MATCH (mp:MateriaPrima)',
    'WHERE ID(mp)={materiaId}',
    'RETURN {',
    'name: mp.name, id: id(mp),',
    'cost: mp.cost, category: mp.category',
    '} as materiaPrima'
  ].join(' ');
  session.run(query, { materiaId: materiaId }).then(
    response => {
      let records = response.records;
      let item = null;
      if (records.length > 0) {
        item = records[0].toObject().materiaPrima;
        item.id = item.id.toInt();
      }
      res.json({ success: item ? true : false, item: item });
    },
    error => {
      return next(new Error('Error buscando las materias primas'));
    }
  );
}

function addMateriaPrima(req, res, next) {
  let body = req.body;
  if (materiasPrimasData.every(value => body.hasOwnProperty(value))) {
    let session = driver.session();
    session
      .run('MATCH (m:MateriaPrima {name: $name}) RETURN m', {
        name: req.body.name
      })
      .then(
        response => {
          if (response.records.length > 0) {
            return next(new Error('La materia prima ya existe'));
          }
          session
            .run(
              `CREATE (m:MateriaPrima {
          name: $name,
          cost: $cost,
          category: $category
        }) RETURN m`,
              {
                name: req.body.name,
                cost: req.body.cost,
                category: req.body.category
              }
            )
            .then(
              response => {
                let materia = response.records[0].get('m').properties;
                materia.id = response.records[0].get('m').identity.toInt();
                res.json({ success: true, item: materia });
                session.close();
                driver.close();
              },
              error => {
                return next(new Error('Error creando la materia prima'));
              }
            );
        },
        error => {
          return next(new Error('Error buscando la materia prima'));
        }
      );
  } else {
    next(new Error('Faltan datos'));
  }
}

function updateMateriaPrima(req, res, next) {
  let materiaId = parseInt(req.params.id);
  let body = req.body;
  if (materiasPrimasData.some(value => body.hasOwnProperty(value))) {
    let session = driver.session();
    let query = [
      'MATCH (m:MateriaPrima)',
      'WHERE id(m) = {materiaId}',
      'SET m += {props}',
      'RETURN m'
    ].join(' ');
    session.run(query, { materiaId: materiaId, props: body }).then(
      response => {
        if (!response.records.length > 0) {
          return next(new Error('No se encontró la materia prima'));
        } else {
          res.json({ success: true });
        }
      },
      error => {
        return next(new Error('Error buscando la materia prima'));
      }
    );
  } else {
    next(new Error('Datos incorrectos'));
  }
}

function deleteMateriaPrima(req, res, next) {
  let materiaId = parseInt(req.params.id);
  let session = driver.session();
  let query = [
    'MATCH (m:MateriaPrima)',
    'WHERE id(m) = {materiaId}',
    'OPTIONAL MATCH (m)-[r]-()',
    'DELETE m, r'
  ].join(' ');
  session.run(query, { materiaId: materiaId }).then(
    response => {
      if (!response.summary.updateStatistics.nodesDeleted() > 0) {
        return next(new Error('No se encontró la materia prima'));
      } else {
        res.json({ success: true });
      }
    },
    error => {
      return next(
        new Error(
          'Error eliminando la materia prima, puede que aún tenga relaciones'
        )
      );
    }
  );
}

module.exports = router;
