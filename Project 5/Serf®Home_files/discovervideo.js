var mydivlayer;
function loadHTML(url, md)
{


mydivlayer = md;

if(document.getElementById(mydivlayer).innerHTML==""){
//load content

if(BrowserDetect.browser == "Safari"){

if(window.XMLHttpRequest && !(window.ActiveXObject)) {
    	try {
			xmlDoc = new XMLHttpRequest();
        } catch(e) {
			xmlDoc = false;
        }
    // branch for IE/Windows ActiveX version
    } else if(window.ActiveXObject) {
       	try {
        	xmlDoc = new ActiveXObject("Msxml2.XMLHTTP");
      	} catch(e) {
        	try {
          		xmlDoc = new ActiveXObject("Microsoft.XMLHTTP");
        	} catch(e) {
          		xmlDoc = false;
        	}
		}
    }
	if(xmlDoc) {
		
		
		xmlDoc.onreadystatechange = processReqChange; //process data when XML is loaded
		xmlDoc.open("GET", url, true);
		xmlDoc.send(null);
	}



} else {
try //Internet Explorer
  {
  xmlDoc=new ActiveXObject("Microsoft.XMLHTTP");

  }
catch(e)
  {
  try //Firefox, Mozilla, Opera, etc.
    {
    //xmlDoc=document.implementation.createDocument("","",null);
   xmlDoc = new XMLHttpRequest();
   	
	
    }
  catch(e)
    {
    alert(e.message);
   // return;
    }
	
  }
	if(xmlDoc) {
		
		xmlDoc.onreadystatechange = processReqChange; //process data when XML is loaded
		xmlDoc.open("GET", url, true);
		xmlDoc.send(null);
	}
}

} else {
//make empty
document.getElementById(mydivlayer).innerHTML ="";

}

return false;
} // end parseXML

function processReqChange()
{
	//XML is loaded and ready to parse data
   if ((xmlDoc.readyState==4)&&(xmlDoc.status == 200))
   {
   document.getElementById(mydivlayer).innerHTML = xmlDoc.responseText;
 return false;
//alert(xmlobj.documentElement);

   } else {
  // 	alert("Problem: " + xmlDoc.statusText);
   }
} 

function updateObjectIframe(which, divname){
	//used for listening lists
	document.getElementById(divname).innerHTML = '';
	//document.getElementById('myln').innerHTML = '&nbsp;&nbsp;<a href="javascript:;" onClick="closeObj()"><font color="white" align="right">CLOSE</font></a><br>';
    document.getElementById(divname).innerHTML += '<'+'object id="discovervideobox" name="discovervideobox" type="text/html" data="'+which.href+'" width="100%" height = "100" border="0"><\/object>';
	showlayer(divname);
}
