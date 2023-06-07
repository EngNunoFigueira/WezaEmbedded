const express = require('express');
const app = express();
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const morgan = require('morgan');
var multer = require('multer');

/*
app.use((req,res, next) => {
    res.header('Access-Control-Allow_Origin', '*');
    res.header(
        "Acces-Control-Allow-Headers",
        "Origin, X-Requested-With, Content-Type, Accept, Authorization"
    );
    if(req.method === 'OPTIONS'){
      res.header('Access-Control-Allow-Methods', 'GET, POST, PUT, PATCH, DELETE');
      return res.status(200).json({});
    }
});*/

app.use(function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
  });

app.use(morgan('dev'));
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());


// DECLARATION OF ROUTES
const utentesRoutes  = require('./api/routes/utentes');
const identidadesRoutes = require('./api/routes/identidades');
const usersAdminRoutes  = require('./api/routes/admins');
const agMedicaRoutes    = require('./api/routes/register');

app.use('/utentes', utentesRoutes);
app.use('/identidades', identidadesRoutes);
app.use('/admins', usersAdminRoutes);
app.use('/register', agMedicaRoutes);

// CONNECTION WITH DATABASE
mongoose.connect('mongodb://localhost:27017/mPainelDb', { useNewUrlParser: true, useUnifiedTopology: true});

// DECLARATION OF CUSTOMIZED ERROR HANDLER MESSAGE
app.use((req,res, next) => {
    const error = new Error('NOT FOUND');
    error.status=404;
    next(error);
})

app.use((error, req,res, next) => {
    res.status(error.status || 500);
    res.json({
        error: {
              message: error.message
        }
    });
});

module.exports = app; 