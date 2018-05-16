var express = require('express');
var bodyParser = require('body-parser');

var app = express();

var materiasPrimas = require('./materias-primas');
var recetas = require('./recetas');
var usuarios = require('./usuarios');

app.use((req, res, next) => {
  res.setHeader(
    'Access-Control-Allow-Methods',
    'OPTIONS, GET, POST, PATCH, PUT, DELETE'
  );
  res.setHeader(
    'Access-Control-Allow-Headers',
    'Origin, X-Requested-With, Content-Type, Accept, Authorization'
  );
  res.setHeader('Access-Control-Allow-Origin', '*');
  next();
});

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.use('/materias-primas', materiasPrimas);
app.use('/recetas', recetas);
app.use('/usuarios', usuarios);

app.listen(13001);
