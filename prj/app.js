const express = require('express');
const mysql = require('mysql');
const bodyParser = require("body-parser");
const app = express();
var urlencodedParser = bodyParser.urlencoded({ extended: false })

// Tworzenie połączenia
const db = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : '',
    database : 'fastfood'  
});



// Połączenie
db.connect((err) => {
    if(err){
        throw err;
    }
    console.log('MySql nawiązano połączenie...');
});

app.get('/tworzeniebazy', (req, res) => {
    let sql = 'CREATE DATABASE nodebaza';
    db.query(sql, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Baza danych zostala utworzona...');
    });
});

app.post('/orderform', urlencodedParser, function (req, res) {
    console.log(req.body);
});



app.listen('3000', () => {
    console.log('Server started on port 3000');
});