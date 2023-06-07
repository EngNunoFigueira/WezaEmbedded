/*
# Year   : 2019/07 
# Autor  : Nuno Figueira
# Company: Nundel Technologies
# Project: Node.js Sever to host HTML page
*/

var http = require('http');
http.createServer(function (req, res) {
res.writeHead(200, {'Content-Type': 'text/plain'});
var currentDate = new Date();
res.end('Hello World'+ currentDate);
}).listen(9000, '127.0.0.1');
console.log('Server running at http://127.0.0.1:9000/');

/*
function module(nuno){	
 console.log('Hello World from Node.js');
}

module('Miguel');
*/

/*

*/