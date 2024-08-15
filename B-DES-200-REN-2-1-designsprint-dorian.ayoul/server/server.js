const account = require('./auth/account');
const database = require('./sql');

let server = null;

exports.init = (io) => {
    server = io;

    server.sockets.on('connection', (socket) => {
        console.log("Client connected!");

        socket.on('handshake', (sessionId, currentUrl) => {
            account.isValidSession(sessionId, (valid) => {
                if (valid) {
                    account.getUser(sessionId, (user) => {
                        socket.emit('valid', true);
                        database.con.query('SELECT * FROM `post` WHERE `url` = ?',
                        [currentUrl], (err, rows) => {
                            for (let i = 0; i < rows.length && i < 3; i++) {
                                socket.emit('message', rows[i].user_id, rows[i].message);
                            }
                        });
                    });
                } else {
                    socket.emit('valid', false);
                }
            });
        });
    });
}
