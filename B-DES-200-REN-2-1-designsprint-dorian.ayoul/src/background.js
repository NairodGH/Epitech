chrome.contextMenus.create({"id": "Id", "title": "Comment", "contexts": ["selection"]});

// chrome.contextMenus.onClicked.addListener(function(clickData){
//     if (clickData.menuItemId == "Id" && clickData.selectionText) {
//         alert(window.getSelection().toString());
//     }
// })