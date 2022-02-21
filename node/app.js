const express = require('express');
const mysql = require('mysql');

// Tworzenie połączenia
const db = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : '',
    database : 'nodebaza'  

});

// Połączenie
db.connect((err) => {
    if(err){
        throw err;
    }
    console.log('MySql nawiązano połączenie...');
});

const app = express();

// Tworzenie bazy danych
app.get('/tworzeniebazy', (req, res) => {
    let sql = 'CREATE DATABASE nodebaza';
    db.query(sql, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Baza danych zostala utworzona...');
    });
});

// Tworzenie tabeli
app.get('/tworzenietabeli', (req, res) => {
    let sql = 'CREATE TABLE osoby(id int AUTO_INCREMENT, imie VARCHAR(50), nazwisko VARCHAR(50), PRIMARY KEY(id))';
    db.query(sql, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Tabela zostala utworzona...');
    });
});

// Dodawanie 1 rekordu
app.get('/dodajrekord1', (req, res) => {
    let post = {imie:'Adam', nazwisko:'Kowalski'};
    let sql = 'INSERT INTO osoby SET ?';
    let query = db.query(sql, post, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Rekord 1 zostal dodany...');
    });
});

// Dodawanie 2 rekordu
app.get('/dodajrekord2', (req, res) => {
    let post = {imie:'Marek', nazwisko:'Owczarek'};
    let sql = 'INSERT INTO osoby SET ?';
    let query = db.query(sql, post, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Rekord 2 zostal dodany...');
    });
});

// Wyświetlanie rekordów
app.get('/wyswietlrekordy', (req, res) => {
    let sql = 'SELECT * FROM osoby';
    let query = db.query(sql, (err, results) => {
        if(err) throw err;
        console.log(results);
        res.send('Rekordy wyswietlone...');
    });
});

// Wyświetlanie pojedynczego rekordu po id
app.get('/wyswietlrekord/:id', (req, res) => {
    let sql = `SELECT * FROM osoby WHERE id = ${req.params.id}`;
    let query = db.query(sql, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Rekord wyswietlony...');
    });
});

// Aktualizacja rekordu
app.get('/aktualizujrekord/:id', (req, res) => {
    let newImie = 'Zaktualizowanie imie';
    let sql = `UPDATE osoby SET imie = '${newImie}' WHERE id = ${req.params.id}`;
    let query = db.query(sql, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Rekord zostal zaktualizowany...');
    });
});

// Usuwanie rekordu
app.get('/usunrekord/:id', (req, res) => {
    let sql = `DELETE FROM osoby WHERE id = ${req.params.id}`;
    let query = db.query(sql, (err, result) => {
        if(err) throw err;
        console.log(result);
        res.send('Rekord zostal usuniety...');
    });
});

app.listen('3000', () => {
    console.log('Server started on port 3000');
});