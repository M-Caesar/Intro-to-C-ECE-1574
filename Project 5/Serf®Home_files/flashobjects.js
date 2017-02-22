<!-- Flash Activate Control -->


function object_testyourself(myXML, myID){
	if(hasFlash==true){
	document.write('<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=10,0,0,0" width="350" height="300" id="testyourself" align="middle" title="Test Yourself">\n');
   document.write('<param name="allowScriptAccess" value="always" />\n');
   document.write('<param name="movie" value="http://www.images.connect4education.com/oma/swf/testyourself/testyourself.swf?_myfilename=');
   document.write(myXML);
   document.write('&_myID=');
   document.write(myID);
    document.write('"/>\n');
   document.write('<param name="quality" value="high" />\n');
	document.write('<param name="wmode" value="opaque" />\n');
	document.write('<param name="bgcolor" value="#D2EDF8" />\n');
   document.write('<embed src="http://www.images.connect4education.com/oma/swf/testyourself/testyourself.swf?_myfilename=');
   document.write(myXML);
   document.write('&_myID=');
   document.write(myID);
   document.write('" quality="high" bgcolor="#D2EDF8" width="350" height="300" name="testyourself" align="middle" wmode="opaque" allowScriptAccess="always" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />\n');
   document.write('</object>\n');
   }

}

function object_testyourself_quiz(myXML, myID){
	if(hasFlash==true){
	document.write('<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=10,0,0,0" width="350" height="60" id="testyourself" align="middle" title="Test Yourself">\n');
   document.write('<param name="allowScriptAccess" value="always" />\n');
   document.write('<param name="movie" value="http://www.connect4education.org/flash/oma/ty/testyourself_quiz.swf?_myfilename=');
   document.write(myXML);
   document.write('&_myID=');
   document.write(myID);
    document.write('"/>\n');
   document.write('<param name="quality" value="high" />\n');
	document.write('<param name="wmode" value="opaque" />\n');
	document.write('<param name="bgcolor" value="#FFFFFF" />\n');
   document.write('<embed src="http://www.connect4education.org/flash/oma/ty/testyourself_quiz.swf?_myfilename=');
   document.write(myXML);
   document.write('&_myID=');
   document.write(myID);
   document.write('" quality="high" bgcolor="#FFFFFF" width="350" height="60" name="testyourself" align="middle" wmode="opaque" allowScriptAccess="always" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />\n');
   document.write('</object>\n');
   }
}

function object_discovermusic(myDrive, myXML, myID){
	
	if(myDrive.toLowerCase()=="stream"){
	//these are internet folks streaming content from the cloud
		if(hasFlash==true){
		document.write('<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=10,0,0,0" width="365" height="130" id="multi_player" align="middle" title="Discover Music">\n');
   		document.write('<param name="allowScriptAccess" value="always" />\n');
   		document.write('<param name="movie" value="http://www.connect4education.org/flash/oma/dm/mp3_discovermusic_a3.swf?_myfilename=');
   		document.write(myXML);
   		document.write('&_myID=');
   		document.write(myID);
    	document.write('"/>\n');
   		document.write('<param name="quality" value="high" />\n');
		document.write('<param name="wmode" value="opaque" />\n');
		document.write('<param name="bgcolor" value="#FFFFFF" />\n');
   		document.write('<embed src="http://www.connect4education.org/flash/oma/dm/mp3_discovermusic_a3.swf?_myfilename=');
   		document.write(myXML);
   		document.write('&_myID=');
   		document.write(myID);
   		document.write('" quality="high" bgcolor="#FFFFFF" width="365" height="130" name="multi_player" align="middle" wmode="opaque" allowScriptAccess="always" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />\n');
   		document.write('</object>\n');
		}
	} 
}

function object_c4e_multi_player(myXML, myID){
	if(hasFlash==true){
	document.write('<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=10,0,0,0" width="125" height="55" id="multi_player" align="middle" title="player">\n');
   document.write('<param name="allowScriptAccess" value="always" />\n');
   document.write('<param name="movie" value="http://www.images.connect4education.com/oma/swf/dm/c4e_mp3_player_multibtn_a3.swf?_myfilename=');
   document.write(myXML);
   document.write('&_myID=');
   document.write(myID);
    document.write('"/>\n');
   document.write('<param name="quality" value="high" />\n');
	document.write('<param name="wmode" value="transparent" />\n');
	document.write('<param name="bgcolor" value="#FFFFFF" />\n');
   document.write('<embed src="http://www.images.connect4education.com/oma/swf/dm/c4e_mp3_player_multibtn_a3.swf?_myfilename=');
   document.write(myXML);
   document.write('&_myID=');
   document.write(myID);
   document.write('" quality="high" bgcolor="#FFFFFF" width="125" height="55" name="multi_player" align="middle" wmode="transparent" allowScriptAccess="always" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />\n');
   document.write('</object>\n');
	}
}

function callJavascript2(myvalue, starttime, endtime){
  	if(hasFlash==true){
		var sendText = myvalue;
		if (starttime){
   			 window.document.multi_player.updateaudio(sendText, starttime, endtime);
		 } else {
	 		window.document.multi_player.updateaudio(sendText, '', '');
	 	}
	 }
}
	
function object_activity(myname, w, h)
{
   if(hasFlash==true){
   document.write('<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,29,0" width="');
   document.write(w);
   document.write('" height="');
   document.write(h);
   document.write('" id="Connect4Education" align="middle" title="Connect4Education">\n');
   document.write('<param name="allowScriptAccess" value="always" />\n');
   document.write('<param name="movie" value="http://ds519jldi30di.cloudfront.net/');
   document.write(myname);
    document.write('"/>\n');
   document.write('<param name="quality" value="high" />\n');
	document.write('<param name="wmode" value="transparent" />\n');
	document.write('<param name="bgcolor" value="#FFFFFF" />\n');
   document.write('<embed src="http://ds519jldi30di.cloudfront.net/');
   document.write(myname);
   document.write('" quality="high" wmode="transparent" bgcolor="#FFFFFF" width="');
   document.write(w);
   document.write('" height="');
   document.write(h);
   document.write('" name="Connect4Education" align="middle" allowScriptAccess="always" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />\n');
   document.write('</object>\n');
   }
}

var playertabWin = null;

function callDiscoverMusicPlayer(myDrive, musicIndex, musicID, starttime, endtime){
	//display the player	
	var myobject = document.getElementById('menu01');
	if (window.innerWidth){
		myscreenheight = window.innerHeight;
	} else if (document.all) {
		myscreenheight = document.documentElement.clientHeight;
	}

    var playerpostion = Number(myobject.style.top.substr(0, myobject.style.top.length - 2)) + myobject.offsetHeight;
    var playertabheight = document.getElementById('playertab').offsetHeight;
			
	if(playerpostion-playertabheight > myscreenheight){
		//player is hidden so display it
		setMenu('menu01');
	} 
			
	if(myDrive == "stream"){
		if(hasFlash==true){		
			//play music using the Flash player
			if(window.document.multi_player){
				//set the audio
				if (starttime){
   		 			window.document.multi_player.updateaudio(musicIndex, starttime, endtime);
	 			} else {
	 				window.document.multi_player.updateaudio(musicIndex, '', '');
	 			}
			}
		} else {
			alert("Flash is required in order to play this selection.");
		}
    } else {
        if (playertabWin != null)
            playertabWin.close();
        else 
        {
            playertabWin = window.open("", "player");
            playertabWin.close();
        }
        if (typeof starttime == "undefined") {
            playertabWin = window.open(myRAMpath + musicID + ".ram", "player");
        } else {
            playertabWin = window.open(myRAMpath + musicID + (starttime + endtime + ".ram").replace(/:/g, ""), "player");
        }
        window.focus();
	}
}
    
function RenderPlayer(drive, audio, timing, dummy)
{
    if (drive == "stream")
    {	
	    var start = "0";
	    var end = "-1";

	    if (typeof timing != "undefined" && timing != "X")
	    {
		    var timings = new Array();
		    timings = timing.split("-");
		    start = timings[0]; 
		    end = timings[1];
	    }

        document.write("<a style='border:none' class='dPlay " + audio.replace(".mp3", "") + " " + start + " " + end + " no'><img width='20' height='20' border='0' alt='play' src='http://www.oma.cloud.connect4education.org/images/icons/play_button.png'></a>&nbsp;Play<div class='menuControl'><div class='doDock'><span>&nbsp;&mdash;&nbsp;</span></div><img src='http://www.oma.cloud.connect4education.org/images/banner/playertab_close.png' alt='Discover Music player' id='playerimg' border='0' usemap='#playerImgMap' /><map name='playerImgMap'><area shape='rect' coords='75, 0, 100, 15'  id='toggleArea' alt='toggle'/></map><div id='player' class='collapsed'></div></div>");
    }
    else 
    {
        document.write("<a href='" + myRAMpath + "X" + audio.substring(1).replace(".mp3", "") + timing.replace(/:/g, '') + ".ram' target='_blank'><img width='20' height='20' border='0' alt='play' src='http://www.oma.cloud.connect4education.org/images/icons/play_button.png'></a>&nbsp;Play");
    }
}
