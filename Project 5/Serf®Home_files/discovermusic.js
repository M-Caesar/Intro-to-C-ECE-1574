//PLACING AUDIO

function tryInterval(myobj, myID, starttime, endtime){

			  var v = document.getElementsByTagName("audio")[(myID-1)];
			  var mybtn;
			  
			  if(v.paused){
			  	v.play(); 
				
				mybtn = document.getElementById("dmplaybtn"+myID);
				mybtn.src= "http://www.images.connect4education.com/oma/images/icons/playbutton_discovermusic_stop.png";
				
				if(starttime!=0){
					int_timerseek = self.setInterval("timer_seek("+myID+", "+starttime+", "+endtime+")",1000);
				}
			
			  } else{
			  	v.pause();
				mybtn = document.getElementById("dmplaybtn"+myID);
				mybtn.src= "http://www.oma.cloud.connect4education.org/images/icons/playbutton_discovermusic.png";
			  }
			 
			}
			
			function timer_seek(myID, startTime, endTime){

				var v = document.getElementsByTagName("audio")[myID];
				if(v.currentTime < startTime){
					v.pause();
					v.currentTime= startTime;
					v.play();
				} else {
					//this works in firefox not safari on iphone
					/*
					if(v.currentTime >= endTime){
						v.pause();
						window.clearInterval(int_timerseek);
					}
					*/
				}
				
				window.clearInterval(int_timerseek);
			}
function placeAudioBtn(myaudio, myid, starttime, endtime){
 		var myobjname = "dm_audio"+myid;
		var pathing = "http://www.oma.cloud.connect4education.org/audio/";
		
			starttime = 0;
			endtime = 0;
		var txtstr ="";

		txtstr +="<a href=\"#\" onclick=\"javascript:tryInterval('myplayer"+myid+"', "+myid+", "+starttime+", "+endtime+");\"><img src='http://www.oma.cloud.connect4education.org/images/icons/playbutton_discovermusic.png' width='20' height='20' border='0' alt='Play Music' id='dmplaybtn"+myid+"'></a>";
		
		return txtstr;

}
function placeAudioTag(myaudio, myid, starttime, endtime){

 		var myobjname = "dm_audio"+myid;
		var pathing = "http://www.oma.cloud.connect4education.org/audio/";
		//myaudio = myaudio;
			starttime = 0;
			endtime = 0;
		var txtstr ="";

		txtstr +="<audio src=\"http://www.oma.cloud.connect4education.org/audio/"+myaudio+"\" id=\"myplayer"+myid+"\">Your browser does not support the <code>audio</code> element.</audio>";
		
		return txtstr;

}

function placeAudio(myaudio, myid){
 		
		var myobjname = "dm_audio"+myid;
		myaudio = myaudio.substr(0, myaudio.length-4);
		var txtstr ="";
		
		 //if (navigator.platform =="Win32"||(BrowserDetect.browser == "Firefox" && BrowserDetect.OS =="Mac")){
		 if (navigator.platform =="Win32"||BrowserDetect.OS =="Mac"){
			//javascript:callDiscoverMusicPlayer('cd|', 16, 'N6654A', '00:06:03.0', '00:07:17.0');
		 	txtstr += "<a href=\"javascript:callDiscoverMusicPlayer('"+myDrive+"', "+myid+", '"+myaudio+"');\"><img src='http://www.oma.cloud.connect4education.org/images/icons/playbutton_discovermusic.png' width='20' height='20' border='0' alt='Play Music'></a>";
		} else {
           
			myaudio = myaudio+".mp3";
			starttime = 0;
			endtime = 0;
			
			var pathing = "http://www.oma.cloud.connect4education.org/audio/";
			txtstr +="<audio src=\"http://www.oma.cloud.connect4education.org/audio/"+myaudio+"\" id=\"myplayer"+myid+"\">Your browser does not support the <code>audio</code> element.</audio>";
			txtstr +="<a href=\"#\" onclick=\"javascript:tryInterval('myplayer"+myid+"', "+myid+", "+starttime+", "+endtime+");\"><img src='http://www.oma.cloud.connect4education.org/images/icons/playbutton_discovermusic.png' width='20' height='20' border='0' alt='Play Music'></a>";
		
        }
		
		return txtstr;

}

function loadmyXML(myxmlfile)
{

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
		
		//var url = "http://www.connect4education.org/flash/oma/dm/dm_romantic2.xml"; //not certain if absolute path is needed
		var url = myxmlfile;
        xmlDoc.onreadystatechange = processReqChange; //process data when XML is loaded
		xmlDoc.open("GET", url, true);
		xmlDoc.send("");
	}



} else {

try //Internet Explorer
  {
  xmlDoc=new ActiveXObject("Microsoft.XMLDOM");
  }
catch(e)
  {
  try //Firefox, Mozilla, Opera, etc.
    {
    xmlDoc=document.implementation.createDocument("","",null);
	
    }
  catch(e)
    {
   // alert(e.message);
   // return;
    }
  }
 
xmlDoc.async=false;
//xmlDoc.load("http://www.connect4education.org/flash/oma/dm/dm_romantic2.xml");
xmlDoc.load(myxmlfile);
//x=xmlDoc.getElementsByTagName("playlist")[0];
x = xmlDoc.documentElement.childNodes;

parsemyXML();
}

} // end loadmyXML

function processReqChange()
{
	
	//XML is loaded and ready to parse data
   if ((xmlDoc.readyState==4)&&(xmlDoc.status == 200))
   {
   var xmlobj=xmlDoc.responseXML;
   x=xmlDoc.responseXML.getElementsByTagName("item");
  // x = xmlDoc.responseXML.childNodes;
  // alert(x.length);
   parsemyXML();
   if (xmlobj.parseError.errorCode != 0)
 {
	//alert(xmlobj.parseError.reason);
	//return;
	}
//alert(xmlobj.documentElement);

   }
} 
	
var a_myobj = new Array(); //musicid, title, artist, filename : this array used to multi-sort
var a_filename = new Array();
var a_title = new Array();
var a_composer = new Array();
var a_musicID = new Array();
var flag_xmlloaded = false;

Array.prototype.multiSort = function(index){
// Written By: WillyDuitt@hotmail.com | 03-10-2005 \\;
for(var i=0; i<this.length; i++){
var temp = this[i].splice(index,1);
this[i].unshift(temp);
} return this.sort();
}

function parsemyXML(){
	
   // alert("parsemyXML"); //page is loading before xml is complete
        var counter = 0;
		
		for (i=0;i<x.length;i++) {
  		
        if (x[i].nodeType==1)
  			{//Process only element nodes (type 1)
			
			a_musicID[counter] = x[i].getElementsByTagName("musicID")[0].childNodes[0].nodeValue;
			a_filename[counter] = x[i].getElementsByTagName("filename")[0].childNodes[0].nodeValue;
			a_title[counter] = x[i].getElementsByTagName("title")[0].childNodes[0].nodeValue;
			a_composer[counter] = x[i].getElementsByTagName("artist")[0].childNodes[0].nodeValue;
			
			a_myobj[counter] = [a_musicID[counter] , a_title[counter], a_composer[counter], a_filename[counter]];
			counter++;
 			}
		}
	flag_xmlloaded = true;
	
	//getInformation(); //called by timer set in the page
	
} //end function

function timer_xmlloading(){
	if(flag_xmlloaded == true){
		window.clearInterval(int_timerxmlloading);
		getInformation();
	} 
}

function getInformation(){
	
   // alert("getInformation"); //page is loading before xml is complete
        
		var myDiv = document.getElementById('discoverMusic');
        var myTitle = document.getElementById('myChapter');
        var mystr = "";	
		
        var tbl = document.getElementById("dmtable");     
		
		//grab how many rows are in the table
      	var lastRow = tbl.rows.length;
		//var lastRow = 1; //if a new list is selected from the chapter dropdown, overwrite the old table data
      	var rowID = lastRow;
		var myfirststr = "<i>";
		var mysecondstr = "</i>";

		a_myobj.shift(); //remove the zero placeholder before alphabetize listing
		a_myobj.multiSort(2); //sort the multiarray object by artist lastname
		document.getElementById("numDM").innerHTML = (a_myobj.length);	//displays the total number of songs in playlist
		
  		for (i=a_myobj.length-1;i>=0;i--) {
		
		//a_myobj[i][0] = artist lastname, firstname
		//a_myobj[i][1] = musicID
		//a_myobj[i][2] = title
		//a_myobj[i][3]  = filename
		
			//var afilename = x[i].getElementsByTagName("filename")[0].childNodes[0].nodeValue;
			//var mytitle = x[i].getElementsByTagName("title")[0].childNodes[0].nodeValue;
			//var mycomposer = x[i].getElementsByTagName("artist")[0].childNodes[0].nodeValue;
			mystr +=a_myobj[i][3]+a_myobj[i][2]+a_myobj[i][0]+"<br>";
			
			// get the reference for the body
        	
			//initialize the cell count
      		var cellNumber = 0;

			//insert a new row at the end of the table
      		var row = tbl.insertRow(lastRow);
			
			//create the first column
			//if(BrowserDetect.OS =="iPad" || (BrowserDetect.browser == "Safari" && BrowserDetect.OS =="Mac")){
			
			if(BrowserDetect.OS =="iPad" || BrowserDetect.OS =="iPhone"){
				var mycopy = placeAudioBtn(a_myobj[i][3], a_myobj[i][1]); //placeAudio(filename, musicID) 
			} else {
				var mycopy = placeAudio(a_myobj[i][3], a_myobj[i][1]); //placeAudio(filename, musicID) 
			}
			var musicCell = row.insertCell(cellNumber++);
			var cellText = document.createTextNode("");
			musicCell.appendChild(cellText); 	
			musicCell.innerHTML = mycopy;
			
			var titleCell = row.insertCell(cellNumber++);
			var cellText = document.createTextNode("");
			titleCell.appendChild(cellText);
			
			//var replcetxt = a_myobj[i][2].replace(/\<i>/gi, "<cite>");
			//replcetxt =  replcetxt.replace(/\<\/i\>/gi, "</cite>");
			var mytempaudio = a_myobj[i][3].substring(0, a_myobj[i][3].length-4);
			mytitlecopy = "<a href=\"javascript:callDiscoverMusicPlayer('"+myDrive+"', "+a_myobj[i][1]+", '"+mytempaudio+"');\">" + a_myobj[i][2] + "</a>";
      		
			
			titleCell.innerHTML = mytitlecopy;
			
			//add a row to house the <audio>
			//if(BrowserDetect.OS =="iPad" || BrowserDetect.OS =="Mac"){
			if(BrowserDetect.OS =="iPad" || BrowserDetect.OS =="iPhone"){
				titleCell.innerHTML += "<br>";
				titleCell.innerHTML += placeAudioTag(a_myobj[i][3], a_myobj[i][1]); //placeAudio(filename, musicID)
			}
			
			var composerCell = row.insertCell(cellNumber++);
			var cellText = document.createTextNode("");
			composerCell.appendChild(cellText);
			//check for a composer profile
			var mycurl = composerProfileCheck(a_myobj[i][0]);
			
			if (mycurl==""){
				composerCell.innerHTML = a_myobj[i][0]; //artist name no profile
			} else {
				
				
				
				//var mycpath = mycurl[0];
				composerCell.innerHTML = "<a href=\""+mycurl[0] + mycurl[1]+ "\" target=\"_composer\">" + a_myobj[i][0]+"</a>"; //artist name with profile
			}
			
			
			
 		}
		

		//set the height of the div container so that five elements are displayed at most and the remaining scroll
		if(document.getElementById("container_dmlist").offsetHeight>253){
			if(hasFlash==true){
				//keeps the layout short and adds a scroll
				document.getElementById("container_dmlist").style.height = "253px";
			} else {
				//for ipad and iphone must display entire listing so that user can see the whole list, they can't scroll
				document.getElementById("container_dmlist").style.height = tbl.offsetHeight = "px";
			}
		}
		
} //end function
var flag_player = 0;
var flag_open = 0;
var slideSpeed = 5;
var object = null;

function moveMenu(){
	if(hasFlash==true){
	flag_open = 0;
	var myscreenwidth;
	var myvalue;
	var myscreenheight = document.body.clientHeight;
	var object = document.getElementById('menu01');
	var margin;
	
	if (window.innerWidth){
		myscreenwidth = window.innerWidth;
		myscreenheight = window.innerHeight;
		//myscreenheight = document.body.clientHeight; //this is the entire document height
		//margin = 150; //if flag is set to 1, player visisble at start
		var playertabheight = document.getElementById('playertab').offsetHeight;
		margin = 20;
	} else if (document.all) {
		myscreenwidth = document.body.clientWidth;
		//myscreenheight = document.body.clientHeight; //this is the entire document height
		myscreenheight = document.documentElement.clientHeight;
		margin = object.offsetHeight;
	}
	
	object.style.top = myscreenheight - margin + 'px';
	
	object.style.display="inline";
	}
}



function setMenu(objectID){
var playertab = document.getElementById('playertab');
if(window.innerWidth){
	//run on firefox: ie barfing
	//update the player tab image
	
	
	var openimgheight = document.getElementById('playertab').height + 5;
	if (window.innerWidth){ 
		openimgheight = (openimgheight *2) -10;
	}
 	var object = document.getElementById(objectID);
 	
	if (flag_open){
				
		//player is not displayed
		playertab.src = "http://www.oma.cloud.connect4education.org/images/banner/playertab_close.png"; //display the open image (img graphics are backwards)
 		
		fY = object.offsetTop + object.offsetHeight - openimgheight;
		cY = object.offsetTop;
		flag_open = 0;
 	} else {
		//player is displayed
		playertab.src = "http://www.oma.cloud.connect4education.org/images/banner/playertab_open.png"; //display the closing image (img graphics are backwards)
 		
		fY = object.offsetTop - object.offsetHeight + openimgheight;
		cY = object.offsetTop;
		object.style.top = cY + 'px';
		flag_open = 1;
 	} 
 	//alert("cY"+cY);
 	//alert("fY"+fY);
 	slideMenu(cY, fY);
} else {
//set IE player to a static position
	playertab.src = "http://www.oma.cloud.connect4education.org/images/banner/playertab.png"; //display the open image (img graphics are backwards)
	myscreenheight = document.documentElement.clientHeight;
	var myobject = document.getElementById('menu01');
	myobject.style.top = (myscreenheight - myobject.offsetHeight - playertab.offsetHeight) + 'px';
}

}

function slideMenu(cY, fY){
	var object = document.getElementById('menu01');
	if ((flag_open==1) && (cY > fY)){
		//open the player
		cY -= slideSpeed;
		object.style.top = cY + 'px';
		setTimeout('slideMenu(' + cY + ',' + fY + ')', 0);
	} else if ((flag_open==0) && (cY <= fY)){
		//close the player
		cY += slideSpeed;
		object.style.top = cY + 'px';
		setTimeout('slideMenu(' + cY + ',' + fY + ')', 0);
	}
	
}

	//run on firefox: ie barfing
window.onresize = function(){
	if(window.innerWidth){
		moveMenu();
	}
}

