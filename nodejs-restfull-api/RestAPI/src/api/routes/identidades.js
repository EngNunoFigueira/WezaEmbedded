const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');
const multer = require('multer');

const storage = multer.diskStorage({
    destination: function (req, file, cb) {
        cb(null, '/media/nundelTech/Restful-API-nundelTechmPainel/src/api/ImagesBi');
    },
    filename: function (req, file, cb) {
        cb(null, new Date().toDateString() + file.originalname);
    }
});

const uploadFiles = multer({
    storage: storage, limits: {
        fileSize: 1024 * 1024 * 5
    }
});

const BilheteDeIdentidade = require('../model/identidade');

router.get('/', (req, res, next) => {

    BilheteDeIdentidade.find()
        .exec()
        .then(docs => {
            console.log(docs);
            res.status(200).json({ message: 'GET the list of BIs' + docs });
        })
        .catch(err => {
            console.log(err);
            res.status(404).json({});
        });
});
router.get('/:id', (req, res, next) => {

    const getId = req.params.id;
    BilheteDeIdentidade.findById(getId)
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

router.post('/', uploadFiles.single('Biphoto'), (req, res, next) => {
    console.log(req.file);
    const biData = new BilheteDeIdentidade({
        _id: new mongoose.Types.ObjectId(),
        name: req.body.name,
        birthday: req.body.birthday,
        hight: req.body.hight,
        address: {
            home: req.body.home,
            zipcode: req.body.zipcode,
            country: req.body.country,
            city: req.body.city
        },
        contact: {
            mobile: req.body.mobile,
            phone: req.body.phone,
            eamil: req.body.eamil,
            skype: req.body.skype
        },
        experiDate: req.body.experiDate,
        dateOfCreation: req.body.dateOfCreation
    });
    biData
        .save()
        .then(result => {
            console.log(result);
        })
        .catch(err => console.log(err));

    res.status(201).send('This is the BI data: ' + biData);
});

router.delete('/:id', (req, res, next) => {
    const getId = req.params.id;
    BilheteDeIdentidade.deleteOne({ _id: getId })
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

router.patch('/:id', (req, res, next) => {
    const getId = req.params.id;
    BilheteDeIdentidade.updateOne({ _id: getId }, { name: req.body.name }, { upsert: true })
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