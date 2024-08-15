const http = require('http');
const express = require('express');
const app = express();

const server = http.createServer(app);
const io = require('socket.io').listen(server);

const manager = require('./server');
const database = require('./sql');

app.use(express.json());
app.use(express.urlencoded({
  extended: true
}));

database.connect((err) => {
    if (err) {
        console.log("Connecting to DB...");
        return;
    }
    console.log('Connection established');
});

server.listen(4000, () => {
    console.log(`Server listening at 4000`);
});

app.post("/", (req, res) => {
    database.con.query('INSERT INTO `post` (`message`, `user_id`, `url`, `user_answer`, `like`, `dislike`) VALUES (?, ?, ?, ?, ?, ?)',
    [req.body.message, 1, 'chrome://extensions/', 0, 0, 0], (err) => {
        if (err) {
            console.log(err.sqlMessage);
        }
    });
});

manager.init(io);
