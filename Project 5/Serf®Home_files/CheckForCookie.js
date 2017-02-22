function GetCookie(cookie_name)
{
  if (document.cookie.length>0)
  {
    cookie_start=document.cookie.indexOf(cookie_name + "=");
    if (cookie_start!=-1)
    {
      cookie_start=cookie_start + cookie_name.length+1;
      cookie_end=document.cookie.indexOf(";",cookie_start);
      if (cookie_end==-1) cookie_end=document.cookie.length;
      return unescape(document.cookie.substring(cookie_start,cookie_end));
    }
  }
  return "";
}

function SetCookie(cookie_name,value,expiredays)
{
  var expiredate=new Date();
  expiredate.setDate(expiredate.getDate()+expiredays);
  document.cookie=cookie_name + "=" + escape(value) + 
     ((expiredays==null) ? "" : ";expires=" + expiredate.toUTCString());
}

function CheckForCookie(cookie_name)
{
  cookie_value=GetCookie(cookie_name);
  if (cookie_value!=null && cookie_value!="")
  {
    alert('The cookie named ' + cookie_name + ' = ' + cookie_value);
  }
  else
  {
    alert('The cookie named ' + cookie_name + ' does not exist.');
  }
}

function startWebNotes(token) {
    
    SetCookie('wn','wnstarted');
    
    var u = 'www.webnotes.net/engine';
    u = location.protocol == 'https:' ? 'https://' + u : 'http://' + u;
    
    var i = new Image();
    i.src = u + '/res/spinner.gif';
    
    var s = document.createElement('script');
    s.type = 'text/javascript';
    s.id = "__wn_bootstrapper";
    s.src = u + '/bookmarklet/bootstrapper.js' + '?v=1&r=' + (new Date()).getTime();
    s.setAttribute('sso', 'token=' + token);
    
    document.getElementsByTagName('head').item(0).appendChild(s);
}