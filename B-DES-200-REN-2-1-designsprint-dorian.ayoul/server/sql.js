const mysql = require('mysql');

const con = mysql.createConnection({
    host: 'localhost',
    user:'root',
    password: 'password',
    database: 'garage'
});

module.exports.connect = function(callback) {
    con.connect(function(err) {
        callback(err);
    });
};

exports.con = con;
