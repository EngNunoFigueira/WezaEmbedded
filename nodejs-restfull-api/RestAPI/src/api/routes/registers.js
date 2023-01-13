const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');

const agMedica = require('../model/register');

router.get('/terminal', (req, res, next) => {
    console.log("Single Weg Page monitor getting called tickets")
    agMedica.find({ status: "called" }).limit(5)
        .exec()
        .then(docs => {
            console.log(docs);
            res.status(200).json({ message: docs });
        })
        .catch(err => {
            console.log("Operation failed with error code...");
            res.status(404).json({});
        });
});

router.get('/', (req, res, next) => {
    agMedica.find({ status: "waiting" })
        .exec()
        .then(docs => {
            console.log("QT-QML desktop app getting new tickets");
            res.status(200).json({ message: docs });
        })
        .catch(err => {
            console.log("Error reading data");
            res.status(404).json({});
        });
});

router.get('/:id', (req, res, next) => {

    const getId = req.params.id;
    agMedica.findById(getId)
        .exec()
        .then(doc => {
            console.log(doc);
            res.status(200).json({ doc });
        })
        .catch(err => {
            console.log(err);
            res.status(500).json({ error: err });
        });
});

router.post('/', (req, res, next) => {
    const newRegisterData = new agMedica({
        _id: new mongoose.Types.ObjectId(),
        counter: req.body.counter,
        code: req.body.code,
        status: req.body.status,
        serviceType: req.body.serviceType,
        openTime: req.body.openTime,
        closeTime: req.body.closeTime
    });
    newRegisterData
        .save()
        .then(result => {
            console.log("QT_QML Terminal create a new ticke " + result);
        })
        .catch(err => console.log(err));

    res.status(201).send('This is the new ticket registered: ' + newRegisterData);
});

router.delete('/:id', (req, res, next) => {
    const getId = req.params.id;
    agMedica.deleteOne({ _id: getId })
        .exec()
        .then(result_msg => {
            console.log(result_msg);
            res.status(200).send(result_msg);
        })
        .catch(err => {
            console.log(err);
            res.status(500).json({
                error: err
            });
        });
});

router.put('/:id', (req, res, next) => {
    const getId = req.params.id;
    console.log("API client: Web single page updating called ticket status to close: " + req.body.closeTime)
    agMedica.updateOne({ _id: getId },
        { status: req.body.status, closeTime: req.body.closeTime },
        { upsert: true })
        .exec()
        .then(result_msg => {
            console.log(result_msg);
            res.status(200).json({ result_msg });
        })
        .catch(err => {
            console.log(err);
        });
});

module.exports = router;
