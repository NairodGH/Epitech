var stringToHTML = function (str) {
	var parser = new DOMParser();
	var doc = parser.parseFromString(str, 'text/html');
	return doc.body;
};

function Aff_msgs(msgtabs) {
    if (msgtabs == null || msgtabs[0] == "")
        document.getElementById("output").innerHTML = ["No comments to show"];
    else
        document.getElementById("output").innerHTML = msgtabs[0];
    document.getElementById("rect").innerHTML = document.body;
}

// Document.body == parcourir le DOM pour inserer html

/*chrome.tabs.executeScript( {
    code: "window.getSelection().toString();"
}, function(selection) {
    if (selection == null || selection == "")
        selection[0] = ["No selection"];
    document.getElementById("output").innerHTML = selection[0];
});*/
