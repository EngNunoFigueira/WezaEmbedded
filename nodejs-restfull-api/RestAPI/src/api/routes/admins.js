const express = require('express');
const router = express.Router();
const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const checkAuth = require("../middleware/checkAuth");

const UserAdmin = require('../model/admin');

router.get('/', (req, res, next) => {

    UserAdmin.find()
    .exec()
    .then(docs => {
        console.log(docs);
        res.status(200).json({ message: docs});
    })
    .catch(err => {
        console.log( err);
        res.status(404).json({});
    });
});

router.get('/:id', (req, res, next) => {

    const getId = req.params.id;
    UserAdmin.findById(getId)
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

router.post('/login', (req, res, next) => {
    const userEmail= req.body.email;
    console.log(userEmail);
    UserAdmin.findOne({email: userEmail})
    .exec()
    .then( user => {
        if(user)
        { 
          //console.log("this is the password: "+user.password);
          bcrypt.compare(req.body.password, user.password, (err, result) => {
            if(err){
                return res.status(401).json({
                    message: "authentication failed" 
                });
            }

            var token = jwt.sign(
                 {
                  Email: user.email,
                  userId: user._id
                 },
                  process.env.JWT_KEY,
                 {
                   expiresIn: "1h"
                 }
              );

            if(result){
                console.log("The result is: ");
                return res.status(200).json({
                    message: "authentication successful",
                    token: token
                });
            } 
           });    
        }
        else{
              return res.status(404).json({ message: "USER NOT FOUND"}); 
        } 
    })
    .catch( err => {
        console.log(err);
        res.status(500).json({
            error: err
        });
    });
});

router.post('/register', (req,res, next) =>{
    const userEmail= req.body.email;
    UserAdmin.find({email: userEmail}).countDocuments()
    .exec()
    .then(docs => {
        if(docs == 0){
            bcrypt.hash(req.body.password, 10, (err, hash) => {
                if(err){
                    return res.status(500).json({
                        error: err
                    });
                }
                else {
                    const newUserRegister = new UserAdmin ({
                        _id: new mongoose.Types.ObjectId(),
                        email: req.body.email,
                        password: hash
                 });
                }
                newUserRegister
                .save()
                .then(result => {
                   console.log(result);
                })
                .catch(err => console.log(err)); 
                 res.status(201).send('Register successful');
              });
        }else{
            res.status(200).json({ message: 'The e-mail exists:'+ docs});
        }
    })
    .catch(err => {
        console.log(err);
        res.status(404).json({});
    });
});

router.delete('/:id', (req,res, next) => {
   const getId = req.params.id;
   UserAdmin.deleteOne({_id : getId})
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

router.patch('/:id', checkAuth, (req,res,next) => {
    const getId = req.params.id;
    UserAdmin.updateOne({_id : getId }, { email: req.body.email}, { upsert: true})
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
