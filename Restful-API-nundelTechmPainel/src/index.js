const express = require('express')
const app     = express()

require('dotenv').config();
console.log(process.env);

app.get('/', function (req, res) {
  res.send('Hello World!')
})

app.listen(3000, function () {
  console.log('Example app listening on port 3000!')
});
