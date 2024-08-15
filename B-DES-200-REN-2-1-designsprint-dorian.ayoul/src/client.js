var client = io.connect('http://localhost:4000');

let url = null;

let commentNumber = 1;

const info_label = document.getElementById("output");

client.on('connect', () => {
    chrome.tabs.query({'active': true, 'windowId': chrome.windows.WINDOW_ID_CURRENT},
    function(tabs) {
        url = tabs[0].url;

        client.on('valid', (valid) => {
            if (valid) {
                document.getElementById("connection").innerHTML = 'Valid account!';
            } else {
                document.getElementById("connection").innerHTML = 'Unvalid account!';
            }
        });
        client.emit('handshake', '6Gyf9JfgWtY5j4x5Hgu49hK2XFZEu3XnA88U9u39', url);

        client.on('message', (username, message) => {
            if (commentNumber === 1)
                document.getElementById("comment1").innerHTML = message;
            if (commentNumber === 2)
                document.getElementById("comment2").innerHTML = message;
            if (commentNumber === 3)
                document.getElementById("comment3").innerHTML = message;
            commentNumber++;
        });
    });
});

window.onunload = window.onbeforeunload = () => {
    client.close();
};
