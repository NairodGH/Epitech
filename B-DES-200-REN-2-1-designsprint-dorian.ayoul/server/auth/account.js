const database = require('../sql');
const User = require('./user');

module.exports.isValidSession = function(sessionId, callback) {
    database.con.query('SELECT * FROM `user` WHERE `sessionId` = ?',
    [sessionId], (err, rows) => {
        if (rows && rows.length > 0) {
            callback(true);
        } else {
            callback(false);
        }
    });
}

module.exports.getUser = function(sessionId, callback) {
    database.con.query('SELECT * FROM `user` WHERE `sessionId` = ?',
    [sessionId], (err, result) => {
        callback(User.NewUser(result[0]));
    });
}
