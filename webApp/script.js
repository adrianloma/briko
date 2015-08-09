// The ID of the extension we want to talk to.

var sendToCompile;
var sendToChromeApp;

window.onload = function(){

	var editorExtensionId = "hahmbmmempgfigbedcioanbelajcmfbo";

	var sending = false;

    var editor = ace.edit("editor");
    editor.setTheme("ace/theme/monokai");
    editor.getSession().setMode("ace/mode/c_cpp");

	

	

	sendForCompile = function()
	{
		var xmlhttp = new XMLHttpRequest();

		xmlhttp.onreadystatechange=function()
	 	{
		  if (xmlhttp.readyState==4 && xmlhttp.status==200)
		    {
		    	if(xmlhttp.responseText){
		    		console.log(xmlhttp.responseText);
	    			setTimeout(function() { alert('Archivo recibido, subiendo a briko...'); }, 1);
	    			sendToChromeApp(xmlhttp.responseText);
		    	}
		    	
		    } else{
		    	if(xmlhttp.readyState==4 && xmlhttp.status==500 && xmlhttp.responseText){
		    		setTimeout(function() { alert('Hubo un error al compilar, intenta otra vez!'); }, 1);
		    	}
		    	
		    }
		}
		var params = "code=" +  editor.getValue();
		xmlhttp.open("POST", "compile", true);

		//Send the proper header information along with the request
		xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		// xmlhttp.setRequestHeader("Content-length", params.length);
		// xmlhttp.setRequestHeader("Connection", "close");
		xmlhttp.send(params);
	}


	sendToChromeApp = function (data){
	chrome.runtime.sendMessage(editorExtensionId, {data: data},
	  function(response) {
		  	console.log(response)
	  });
	};

	document.getElementById("compile").addEventListener("click", sendForCompile);
};
