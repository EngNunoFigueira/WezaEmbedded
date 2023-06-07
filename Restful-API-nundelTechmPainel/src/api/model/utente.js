const mongoose = require('mongoose');

const utenteSchema = mongoose.Schema({
      _id: mongoose.Schema.Types.ObjectId,
      name: String,
      room: Number
});

module.exports = mongoose.model('Utente', utenteSchema);