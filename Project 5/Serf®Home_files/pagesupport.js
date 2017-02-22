<!-- Image Rollover -->

function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  
if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}

function MM_swapImage() { //v3.0

  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}

function indComposerOpen(args){
//FEATURE = COMPOSER PROFILE WINDOW
newWindow=window.open(args,'newCWin','toolbar=no,location=no,scrollbars=no,status=no,width=475,height=475'); 

}
function mapOpen(args){
//FEATURE = COMPOSER MAPS
newWindow=window.open(args,'newMWin','toolbar=no,location=no,scrollbars=no,status=no,width=800,height=600'); 

}
function framesWinOpen(args,w,h){
//FEATURE = ASSESSMENT POINTS / DYK
//alert (w);
myValue = "toolbar=no,location=no,scrollbars=no,status=no,width="+w+",height="+h;


newWindow=window.open(args,'newFWin',myValue); 

}

function framesWinOpen2(args,w,h){
//FEATURE = LISTENING GUIDE
//alert (w);
myValue = "toolbar=no,location=no,scrollbars=yes,status=no,width="+w+",height="+h;


newWindow=window.open(args,'newFWin',myValue);

}

//these two functions: showlayer() and hidelayer() are used to open and close the keywords section at the bottom of page

function showlayer(LayerName) {
//alert("showlayer");
var VState = document.getElementById(LayerName).style.display;
if (VState=="none") {
document.getElementById(LayerName).style.display = "inline";
} else {
hidelayer(LayerName);
}
} //end function
function hidelayer(LayerName) {
//alert("hidelayer");
var VState = document.getElementById(LayerName).style.display;
if (VState=="inline") {
document.getElementById(LayerName).style.display = "none";
}
} //end function

function imgSwap(objID, imgName, layerID){
		var myfile="";
		//check to see if support content is displayed or not and change banner image accordingly
		var VState = document.getElementById(layerID).style.display;
		if(VState=="none"){
			myfile = "http://www.oma.cloud.connect4education.org/images/banner/"+imgName+"_up.png";
		} else {
			myfile = "http://www.oma.cloud.connect4education.org/images/banner/"+imgName+"_down.png";
		}
		document.getElementById(objID).src = myfile;
	}
	
	function wikiOpen(){
		
		var myForm = document.getElementById("searchform");
		var myURL = "http://www.wikipedia.org/search-redirect.php?search="+myForm.search.value+"&language="+myForm.language.value+"&family="+myForm.family.value;
		var w=800;
		var h=600;
		var myValue = "toolbar=no,location=no,scrollbars=yes,status=no,width="+w+",height="+h;
		newWindow=window.open(myURL,'newWikiWin',myValue); 
	}
	
	function updateObjectIframe(which, divname){
	if(document.getElementById(divname)){
	//used for listening lists
	document.getElementById(divname).innerHTML = '';
	//document.getElementById('myln').innerHTML = '&nbsp;&nbsp;<a href="javascript:;" onClick="closeObj()"><font color="white" align="right">CLOSE</font></a><br>';
    document.getElementById(divname).innerHTML += '<'+'object id="discovervideobox" name="discovervideobox" type="text/html" data="'+which.href+'"  width="750" style="overflow: hidden;border=none;margin=0px;padding=0px;"><\/object>';
	showlayer(divname);
	}
}
