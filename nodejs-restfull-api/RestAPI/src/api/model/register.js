const mongoose = require('mongoose');

const registerSchema = mongoose.Schema({
      _id: mongoose.Schema.Types.ObjectId,
      counter: Number,
      code: String,
      status: String,
      serviceType: String,
      openTime: String,
      closeTime: String
});

module.exports = mongoose.model('agMedica', registerSchema);


