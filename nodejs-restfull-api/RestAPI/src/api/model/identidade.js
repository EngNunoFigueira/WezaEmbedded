const mongoose = require('mongoose');

const identidadeSchema = mongoose.Schema({
      _id: mongoose.Schema.Types.ObjectId,
      name:     String,
      birthday: String,
      hight:    Number,
      address: {
       home:    String,
       zipcode: String,
       country: String,
       city:    String
      },
      contact: {
         mobile: String,
         phone:  String,
         eamil:  String,
         skype:  String
      } ,
      experiDate: { type: Date, default: Date.now },
      dateOfCreation: { type: Date, default: Date.now }
});

module.exports = mongoose.model('BilheteDeIdentidade', identidadeSchema);