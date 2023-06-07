/* THIS IS A SERVER DEVELOPED IN NODE.js
const http= require('http');
const server = http.createServer((req,res) => {

        if(req.url === '/') { 
           res.write('Hello Nundel Tech');
           res.end();
        }

        if(req.url === '/api/utentes') {
           res.write(JOSN.stringfy([1, 2, 3]) );
           req.end();
        }
});

server.listen(3000);
console.log('The Nundel Tech ResFull Server Listening on Port 3000 .....');
*/


/*THIS IS A SERVER CREATED ON NODE.js with EXPRESS*/

const express = require('express');
const app = express();
app.use(express.json());

// SIMPLES EXAMPLE OF DATA MODEL:
 const courses = [
 {id: 1, name: 'Chemistry'},
 {id: 2, name: 'Electronics'},
 {id: 3, name: 'Electricity'},
 {id: 4, name: 'Telecom & Computer'},
 {id: 5, name: 'Informatic Technologies'}
];

// API METHOS:
//Now we can create all API methods such as : GET POST PUT DELETE
app.get('/', function (req,res){
  res.send('Hello Nundel Tech ! This is our first API developed in node.js');
});

app.get('/api/utentes', function (req,res){
  res.send([1, 2, 3]);
});

app.get('/api/utentes/:id', function (req,res){
    const course = courses.find(c => c.id === parseInt(req.params.id));	
    if(!course) res.status(404).send('OBJECT NOT FOUND');
     res.send(course);
   //res.send(req.params.id);
});

app.post('/api/utentes/', function (req,res) {
    const course = {
       id: courses.length + 1,
       name: req.body.name
    };
    courses.push(course);
    res.send(course);

    // Such as the user data came from http body, we need reading this 
    // data accessing the body part.
});

app.put('/api/utentes/:id', function (req,res) {
    //const id = course.length +1;
    // Such as the user data came from http body, we need reading this 
    // data accessing the body part.

    //const name = req.params.
});
//app.put();
//app.delete();

// ATT: On production environment the Server Port Number is dynamically added, so we must change our hardcoded metho to support it.
// this is the code:
const port = process.env.PORT || 3000;
app.listen(port, function(){ 
	console.log('This is the port Number:' + port);
});
