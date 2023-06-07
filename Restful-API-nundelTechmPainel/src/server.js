var http=require('http');
const app = require('./app');
require('dotenv').config();
const port=process.env.SRV_PORT || 5000;
const server=http.createServer(app); 
server.listen(port, '192.168.250.137', function(){
    console.log("The server is listening on  port:"+ port);
});
