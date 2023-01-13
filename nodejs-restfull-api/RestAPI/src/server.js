var http=require('http');
const app = require('./app');
require('dotenv').config();
const port=process.env.SRV_PORT || 5000;
const server=http.createServer(app); 
server.listen(port);