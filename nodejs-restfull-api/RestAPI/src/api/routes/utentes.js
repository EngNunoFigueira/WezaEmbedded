const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');

const Utente = require('../model/utente');

router.get('/', (req, res, next) => {

Utente.find()
    .exec()
    .then(docs => {
        console.log(docs);
        res.status(200).json({ message: 'GET the list of UTENTES' + docs});
    })
    .catch(err => {
        console.log(err);
        res.status(404).json({});
    });
});

router.get('/:id', (req, res, next) => {

    const getId = req.params.id;
    Utente.findById(getId)
          .exec()
          .then(doc => {
              console.log(doc);
              res.status(200).json({doc});
          })
          .catch(err => {
            console.log(err);
            res.status(500).json({error: err});
          });
});

router.post('/', (req, res, next) => {
    const utentesData = new Utente ({
           _id: new mongoose.Types.ObjectId(),
           name: req.body.name,
           room: req.body.room
    });
    utentesData
        .save()
        .then(result => {
           console.log(result);
        })
        .catch(err => console.log(err)); 

    res.status(201).send('This is the utente info: '+ utentesData);
});

router.delete('/:id', (req,res, next) => {
   const getId = req.params.id;
   Utente.deleteOne({_id : getId})
    .exec()
    .then(result_msg => {
        console.log(result_msg);
        res.status(200).send(result_msg);
    })
    .catch(err => {
        console.log(err);
        res.status(500).json({
            error:err
        });
    });
});

router.patch('/:id', (req,res,next) => {
    const getId = req.params.id;
    Utente.updateOne({_id : getId }, { name: req.body.name}, { upsert: true})
    .exec()
    .then(result_msg =>{
        console.log(result_msg);
        res.status(200).json({result_msg});
    })
    .catch(err => {
        console.log(err);

    });
});

module.exports = router;