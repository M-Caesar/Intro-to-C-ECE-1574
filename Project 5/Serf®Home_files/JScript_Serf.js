/* JScript_raw */

// Copy of JSON to get JSON.stringify. It didn't load at one point, so I have copied it into this file, raw, to be safe.
var JSON;
if (!JSON) {
    JSON = {};
}

(function () {
    "use strict";

    function f(n) {
        // Format integers to have at least two digits.
        return n < 10 ? '0' + n : n;
    }

    if (typeof Date.prototype.toJSON !== 'function') {

        Date.prototype.toJSON = function (key) {

            return isFinite(this.valueOf()) ?
                this.getUTCFullYear() + '-' +
                f(this.getUTCMonth() + 1) + '-' +
                f(this.getUTCDate()) + 'T' +
                f(this.getUTCHours()) + ':' +
                f(this.getUTCMinutes()) + ':' +
                f(this.getUTCSeconds()) + 'Z' : null;
        };

        String.prototype.toJSON =
            Number.prototype.toJSON =
            Boolean.prototype.toJSON = function (key) {
                return this.valueOf();
            };
    }

    var cx = /[\u0000\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
        escapable = /[\\\"\x00-\x1f\x7f-\x9f\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g,
        gap,
        indent,
        meta = {    // table of character substitutions
            '\b': '\\b',
            '\t': '\\t',
            '\n': '\\n',
            '\f': '\\f',
            '\r': '\\r',
            '"': '\\"',
            '\\': '\\\\'
        },
        rep;


    function quote(string) {

        // If the string contains no control characters, no quote characters, and no
        // backslash characters, then we can safely slap some quotes around it.
        // Otherwise we must also replace the offending characters with safe escape
        // sequences.

        escapable.lastIndex = 0;
        return escapable.test(string) ? '"' + string.replace(escapable, function (a) {
            var c = meta[a];
            return typeof c === 'string' ? c :
                '\\u' + ('0000' + a.charCodeAt(0).toString(16)).slice(-4);
        }) + '"' : '"' + string + '"';
    }


    function str(key, holder) {

        // Produce a string from holder[key].

        var i,          // The loop counter.
            k,          // The member key.
            v,          // The member value.
            length,
            mind = gap,
            partial,
            value = holder[key];

        // If the value has a toJSON method, call it to obtain a replacement value.

        if (value && typeof value === 'object' &&
                typeof value.toJSON === 'function') {
            value = value.toJSON(key);
        }

        // If we were called with a replacer function, then call the replacer to
        // obtain a replacement value.

        if (typeof rep === 'function') {
            value = rep.call(holder, key, value);
        }

        // What happens next depends on the value's type.

        switch (typeof value) {
            case 'string':
                return quote(value);

            case 'number':

                // JSON numbers must be finite. Encode non-finite numbers as null.

                return isFinite(value) ? String(value) : 'null';

            case 'boolean':
            case 'null':

                // If the value is a boolean or null, convert it to a string. Note:
                // typeof null does not produce 'null'. The case is included here in
                // the remote chance that this gets fixed someday.

                return String(value);

                // If the type is 'object', we might be dealing with an object or an array or
                // null.

            case 'object':

                // Due to a specification blunder in ECMAScript, typeof null is 'object',
                // so watch out for that case.

                if (!value) {
                    return 'null';
                }

                // Make an array to hold the partial results of stringifying this object value.

                gap += indent;
                partial = [];

                // Is the value an array?

                if (Object.prototype.toString.apply(value) === '[object Array]') {

                    // The value is an array. Stringify every element. Use null as a placeholder
                    // for non-JSON values.

                    length = value.length;
                    for (i = 0; i < length; i += 1) {
                        partial[i] = str(i, value) || 'null';
                    }

                    // Join all of the elements together, separated with commas, and wrap them in
                    // brackets.

                    v = partial.length === 0 ? '[]' : gap ?
                    '[\n' + gap + partial.join(',\n' + gap) + '\n' + mind + ']' :
                    '[' + partial.join(',') + ']';
                    gap = mind;
                    return v;
                }

                // If the replacer is an array, use it to select the members to be stringified.

                if (rep && typeof rep === 'object') {
                    length = rep.length;
                    for (i = 0; i < length; i += 1) {
                        if (typeof rep[i] === 'string') {
                            k = rep[i];
                            v = str(k, value);
                            if (v) {
                                partial.push(quote(k) + (gap ? ': ' : ':') + v);
                            }
                        }
                    }
                } else {

                    // Otherwise, iterate through all of the keys in the object.

                    for (k in value) {
                        if (Object.prototype.hasOwnProperty.call(value, k)) {
                            v = str(k, value);
                            if (v) {
                                partial.push(quote(k) + (gap ? ': ' : ':') + v);
                            }
                        }
                    }
                }

                // Join all of the member texts together, separated with commas,
                // and wrap them in braces.

                v = partial.length === 0 ? '{}' : gap ?
                '{\n' + gap + partial.join(',\n' + gap) + '\n' + mind + '}' :
                '{' + partial.join(',') + '}';
                gap = mind;
                return v;
        }
    }

    // If the JSON object does not yet have a stringify method, give it one.

    if (typeof JSON.stringify !== 'function') {
        JSON.stringify = function (value, replacer, space) {

            // The stringify method takes a value and an optional replacer, and an optional
            // space parameter, and returns a JSON text. The replacer can be a function
            // that can replace values, or an array of strings that will select the keys.
            // A default replacer method can be provided. Use of the space parameter can
            // produce text that is more easily readable.

            var i;
            gap = '';
            indent = '';

            // If the space parameter is a number, make an indent string containing that
            // many spaces.

            if (typeof space === 'number') {
                for (i = 0; i < space; i += 1) {
                    indent += ' ';
                }

                // If the space parameter is a string, it will be used as the indent string.

            } else if (typeof space === 'string') {
                indent = space;
            }

            // If there is a replacer, it must be a function or an array.
            // Otherwise, throw an error.

            rep = replacer;
            if (replacer && typeof replacer !== 'function' &&
                    (typeof replacer !== 'object' ||
                    typeof replacer.length !== 'number')) {
                throw new Error('JSON.stringify');
            }

            // Make a fake root object containing our value under the key of ''.
            // Return the result of stringifying the value.

            return str('', { '': value });
        };
    }


    // If the JSON object does not yet have a parse method, give it one.

    if (typeof JSON.parse !== 'function') {
        JSON.parse = function (text, reviver) {

            // The parse method takes a text and an optional reviver function, and returns
            // a JavaScript value if the text is a valid JSON text.

            var j;

            function walk(holder, key) {

                // The walk method is used to recursively walk the resulting structure so
                // that modifications can be made.

                var k, v, value = holder[key];
                if (value && typeof value === 'object') {
                    for (k in value) {
                        if (Object.prototype.hasOwnProperty.call(value, k)) {
                            v = walk(value, k);
                            if (v !== undefined) {
                                value[k] = v;
                            } else {
                                delete value[k];
                            }
                        }
                    }
                }
                return reviver.call(holder, key, value);
            }


            // Parsing happens in four stages. In the first stage, we replace certain
            // Unicode characters with escape sequences. JavaScript handles many characters
            // incorrectly, either silently deleting them, or treating them as line endings.

            text = String(text);
            cx.lastIndex = 0;
            if (cx.test(text)) {
                text = text.replace(cx, function (a) {
                    return '\\u' +
                        ('0000' + a.charCodeAt(0).toString(16)).slice(-4);
                });
            }

            // In the second stage, we run the text against regular expressions that look
            // for non-JSON patterns. We are especially concerned with '()' and 'new'
            // because they can cause invocation, and '=' because it can cause mutation.
            // But just to be safe, we want to reject all unexpected forms.

            // We split the second stage into 4 regexp operations in order to work around
            // crippling inefficiencies in IE's and Safari's regexp engines. First we
            // replace the JSON backslash pairs with '@' (a non-JSON character). Second, we
            // replace all simple value tokens with ']' characters. Third, we delete all
            // open brackets that follow a colon or comma or that begin the text. Finally,
            // we look to see that the remaining characters are only whitespace or ']' or
            // ',' or ':' or '{' or '}'. If that is so, then the text is safe for eval.

            if (/^[\],:{}\s]*$/
                    .test(text.replace(/\\(?:["\\\/bfnrt]|u[0-9a-fA-F]{4})/g, '@')
                        .replace(/"[^"\\\n\r]*"|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g, ']')
                        .replace(/(?:^|:|,)(?:\s*\[)+/g, ''))) {

                // In the third stage we use the eval function to compile the text into a
                // JavaScript structure. The '{' operator is subject to a syntactic ambiguity
                // in JavaScript: it can begin a block or an object literal. We wrap the text
                // in parens to eliminate the ambiguity.

                j = eval('(' + text + ')');

                // In the optional fourth stage, we recursively walk the new structure, passing
                // each name/value pair to a reviver function for possible transformation.

                return typeof reviver === 'function' ?
                    walk({ '': j }, '') : j;
            }

            // If the text is not JSON parseable, then a SyntaxError is thrown.

            throw new SyntaxError('JSON.parse');
        };
    }
} ());

// End JSON definition, begin BB-specific logic 

$.noConflict();
jQuery(document).ready(function ($) {

    // cwang: 10/2/11: initialize
    $('.menuControl').removeAttr('style');

    // Instantiate Flash player
    $('#player').html('<div id="flashwarn">You need to upgrade your Flash player in order to listen to music.<br/><br/><a href="http://get.adobe.com/flashplayer" target="_blank">Download it from Adobe</a></div>');
    $('#player').flash({
        swf: 'http://www.connect4education.org/flash/omaplayer.swf?rand=' + Math.floor(Math.random() * 10000).toString(),
        allowScriptAccess: 'always',
        quality: 'high',
        wmode: 'opaque',
        width: 365,
        height: 130,
        bgcolor: '#FFFFFF'
    });

    // Make music links tab accessible
    $('a.dPlay').each(function () {
        var aClass = $(this).attr('class');
        $(this).removeAttr('class');
        $(this).attr('href', '#');
        $(this).attr('class', aClass);
    });

    $('#player').css('opacity', '0.0');
    $('.hlink').css('color', '#2B8CBA');
    $('.hlink').css('font-weight', 'bolder');
    $('.hlink').css('text-decoration', 'none');
    $('.hlink').css('cursor', 'pointer');

    // Simplify links to Music Dictionary from godawfully long javascript calls  within HTML
    $('.hlink').click(function () {
        var classnames = $(this).attr('class').replace(/\n/g, '');
        var temp = new Array();
        temp = classnames.split(" ");
        var href_piece = temp[1].toLowerCase();
        var href = "http://dictionary.onmusic.org/terms/" + href_piece;
        window.open(href, 'newwin', 'toolbar=yes,location=no,status=no,menubar=no,scrollbars=yes,resizable=yes,width=1024,height=768');
    });

    /* For Serf exams, disable autocomplete */
    $('.item input').attr('autocomplete', 'off');

    // cwang: 10/2/11: Initialize
    $('#spacer').remove();
    $('body').append("<div id='spacer' style='height:140px'/>");
    $('#spacer').hide();

    $('.goTop').click(function () {
        $('html, body').animate({ scrollTop: 0 }, 0);
    });

    var lgH;
    var lgW;
    var lgUrl;

    var classname = $('#supportContent').attr('class');
    var playingTY = false;

    $('.menuControl').css('left', '0px');
    $('.menuControl').css('top', 'inherit');
    $('.menuControl').css('bottom', '0px');

    $('#loimg').wrap('<a href="#" id="loimg_a"/>');
    $('#loimg_a').click(function (event) {
        event.preventDefault();
        popUpShow('#lo_view', true);
    });

    // Set up music links on click
    var ramWindow = null;
    function dPlaySetup() {
        $('.dPlay').click(function (event) {
            event.preventDefault();
            var classnames = $(this).attr('class').replace(/\n/g, '');
            var temp = new Array();
            temp = classnames.split(" ");
            var start = '';
            var end = '';
            if (temp.length >= 4) {
                start = temp[2];
                var temp2 = new Array();
                temp2 = start.split(":");
                if (temp2.length > 1) {
                    var val = parseFloat(temp2[temp2.length - 1]) + parseFloat(temp2[temp2.length - 2]) * 60;
                    start = val.toString();
                }
                end = temp[3];
                temp2 = end.split(":");
                if (temp2.length > 1) {
                    var val = parseFloat(temp2[temp2.length - 1]) + parseFloat(temp2[temp2.length - 2]) * 60;
                    end = val.toString();
                }
            }

            if (myDrive != "stream") {
                if (ramWindow != null)
                    ramWindow.close();
                if (start == '' || (start == '-1' && end == '-1'))
                    ramWindow = window.open(myRAMpath + temp[1] + ".ram", "player");
                else
                    ramWindow = window.open(myRAMpath + temp[1] + (start + end + ".ram").replace(/:/g, ""), "player");
                window.focus();
                return;
            }

            try {
                $('#player').flash(
                                function () {
                                    this.stopPlayer(false);
                                });
            } catch (err) {
                alert("Sorry, the player has not finished loading. Please expand the player tab and try again when you see the player has loaded");
                return;
            }
            togglePlayer("show");
            if (temp.length > 4 && temp[4] == "no") {
                // No as 5th element indicates we do not want to show the track name
                $('#player').flash(
                                function () {
                                    this.updatePlayer(temp[1], start, end, "Audio Selection", "");
                                    playingTY = false;
                                });
            }
            else {
                $.ajax({
                    url: "http://www.c4edu.mobi/jsonp.asmx/getTrackInfo",
                    dataType: "jsonp",
                    data: { track: JSON.stringify(temp[1]) },
                    success: function (data) {
                        $('#player').flash(
                                function () {
                                    this.updatePlayer(temp[1], start, end, data.d[0], data.d[1]);
                                    playingTY = false;
                                });

                    },
                    complete: function (jqXHR, status) {
                        if (status != "success") {
                            $('#player').flash(
                                function () {
                                    this.updatePlayer(temp[1], start, end, "Unable to load track info", "");
                                    playingTY = false;
                                });
                        }
                    }
                });
            }
        });

        // cwang: 10/2/11: Initialize
        $('#cpdiv').remove();
        $('#boxes').append('<div id="cpdiv" class="window"></div>');

        // Set up composer profile on click
        $('.cp').click(function (event) {
            event.preventDefault();
            var classnames = $(this).attr('class').replace(/\n/g, '');
            var temp = new Array();
            temp = classnames.split(" ");
            $('#cpdiv').flash({
                swf: 'http://www.connect4education.org/flash/composer_profile.swf?composer_id=' + temp[1],
                allowScriptAccess: 'always',
                quality: 'high',
                width: 520,
                height: 574
            });
            $('#cpdiv').append('<a href="#" class="close-window"></a>');
            popUpShow('#cpdiv', true);
        });
    }

    // Set up listening guides on click
    function lgSetup() {
        // cwang: 10/2/11: Initialize
        $('#lgdiv').remove();
        $('#boxes').append('<div id="lgdiv" class="window"></div>');

        $('.lg').click(function (event) {
            event.preventDefault();
            var classnames = $(this).attr('class').replace(/\n/g, '');
            var temp = new Array();
            temp = classnames.split(" ");
            $('#lgdiv').empty();

            lgH = Math.min($(window).height(), 666);
            lgW = Math.floor(1.45 * lgH);
            lgUrl = 'http://www.oma.cloud.connect4education.org/lg/web/' + temp[1] + '.html';
            $('#lgdiv').append('<iframe width="' + lgW + ' " height="' + lgH + '" src="' + lgUrl + '" frameborder="0"></iframe><a class="close-window"></a>');

            popUpShow('#lgdiv', true);
        });
    }

    if ($.browser.mozilla) {
        // On firefox, flash element has to be within visible area of page or else it isn't
        // instantiated in time
        $('.menuControl').css({ bottom: function (index, value) { return '4px' } });
    }

    // Load Discover Music / Listening Guide
    // DM is visible by default, so no lazy evaluation benefit from waiting, and LG is based on DM
    // so easier just to do it at once rather than have to call the ws twice.
    var cursor = 0;
    var dmContent = "<table><thead><tr><th style='width:10%'></th><th style='width:65%'>Title</th><th style='width:25%'>Composer</th></tr></thead><tbody>";
    var lgContent = "<table><thead><tr><th style='width:10%'></th><th style='width:65%'>Title</th><th style='width:25%'>Composer</th></tr></thead><tbody>";
    if (typeof classname == "undefined")
        dPlaySetup();
    else getDM(cursor, dmContent, lgContent);

    function getDM(cursor, dmContent, lgContent) {
        var hasLg = false;
        var hasDm = false;
        var x;
        try {
            $.ajax({ url: "http://www.c4edu.mobi/jsonp.asmx/getDM_raw_core",
                data: { section: JSON.stringify(classname), segment: cursor },
                dataType: "jsonp",
                success: function (data) {
                    var i = 0;
                    var lgfile;
                    x = data.d;
                    var str;
                    while (i < x.length) {
                        hasDm = true;
                        afile = x[i++];
                        lgfile = x[i++];
                        piece = x[i++];
                        cid = x[i++];
                        comp = x[i++];

                        str = "<tr><td><a href='#' class='dPlay " + afile + "'><img src='http://www.oma.cloud.connect4education.org/images/icons/playbutton_discovermusic.png' alt='play' width='20' height='20' /></a></td><td>" +
                        (lgfile != '' ? "<a href='#' class='lg " + lgfile + "'>" : "") + piece + (lgfile != '' ? "</a>" : "") + "</td><td class='tdComp'>" +
                        (cid != "-1" ? "<a href='#' class='cp " + cid + "'>" : "") + comp + (cid != "-1" ? "</a>" : "") + "</td></tr>";
                        dmContent += str;
                        if (lgfile != '') {
                            hasLg = true;
                            lgContent += str;
                        }
                    }
                },
                complete: function () {
                    if (hasDm && cursor == 0) {
                        // cwang: 9/27/11: Initialize first
                        $('#dMusic').remove();
                        $('#supportContent').append('<div id="dMusic"><img src="http://www.oma.cloud.connect4education.org/images/buttons/button_discover_music.png" alt="Discover Music" id="img_dm"/><div id="dm_view"></div></div>');
                        if (hasLg && classname != "all") {

                            // cwang: 9/27/11: Initialize first
                            $('#lGuides').remove();

                            $('#supportContent').append('<div id="lGuides"><a href="#" id="img_lg_a"><img src="http://www.oma.cloud.connect4education.org/images/buttons/button_lg_closed.png" id="img_lg" alt="Listening Guide" /></a><div id="lg_view" style="display:none;"></div></div>');
                        }
                    }
                    if (x.length < 500 && (x.length > 0 || cursor > 0)) {
                        dmContent += "</tbody></table>";
                        lgContent += "</tbody></table>";
                        $('#dm_view').append(dmContent);
                        $('#lg_view').html(lgContent);
                        // Can't use toggle? For screen reader compliance need the item to behave as an anchor tag
                        $('#img_lg_a').click(function (event) {
                            event.preventDefault();
                            // If closed, then open
                            if ($('#lg_view').is(':hidden')) {
                                $('#lg_view').show("slow");
                                $('#img_lg').attr('src', 'http://www.oma.cloud.connect4education.org/images/buttons/button_lg_open.png');
                            } else {
                                $('#lg_view').hide("slow");
                                $('#img_lg').attr('src', 'http://www.oma.cloud.connect4education.org/images/buttons/button_lg_closed.png');
                            }
                        });

                        dPlaySetup();
                        lgSetup();
                        otherContentSetup();

                        if (classname == "all") {
                            $('#img_dm').hide();
                            $('#dm_view').css('max-height', 'inherit').css('height', 'inherit').css('overflow-y', 'hidden');
                            $('#dMusic').css('width', '100%');
                            $('.event').css('height', $('h1').height() * 2 + $('#dm_view').height());

                        }
                    }
                    else {
                        // recurse and get next 100 results
                        getDM(++cursor, dmContent, lgContent);
                    }
                },
                error: function () {
                    dPlaySetup();
                }
            });
        } catch (err) {
            dPlaySetup();
        }
    }

    function otherContentSetup() {
        // On the other hand, for TY, KW, PM, and DV, do lazy eval. But first figure out if these are even
        // existing elements.
        try {
            // setup learning objectives here
            // cwang: 9/27/11: initialize
            $('#lo_view').remove();
            $('#boxes').append('<div id="lo_view" class="window"><div class="lo_framing"></div></div>');

            $.ajax({ url: "http://c4edu.mobi/jsonp.asmx/getlo",
                data: { section: JSON.stringify(classname) },
                dataType: "jsonp",
                success: function (data) {
                    $('.lo_framing').html("<div class='title'>Be ready to...</div><ul id='loitems'></ul>");
                    var los = data.d;
                    for (var i = 0; i < los.length; i++) {
                        $('#loitems').append("<li>" + los[i] + "</li>");
                    }
                }
            });

            var ty = 1;
            var kw = 2;
            var cm = 4;
            var dv = 8;

            $.ajax({ url: "http://c4edu.mobi/jsonp.asmx/elementInfo",
                data: { section: JSON.stringify(classname) },
                dataType: "jsonp",
                success: function (data) {
                    var res = data.d;
                    if ((res & ty) != 0) {
                        // cwang: 9/27/11: Initialize first
                        $('#tYourself').remove();
                        $('#supportContent').append('<div id="tYourself"><a href="#" id="img_ty_a"><img src="http://www.oma.cloud.connect4education.org/images/buttons/button_ty_closed.png" id="img_ty" alt="Test Yourself" /></a><div id="ty_view" style="display:none;"></div></div>');
                        $('#img_ty_a').click(function (event) {
                            event.preventDefault();
                            if (!$(this).hasClass("doOnce")) {
                                loadTY();
                                $(this).addClass("doOnce");
                            } else {
                                if ($(this).hasClass("open")) {
                                    $('#ty_view').hide("slow");
                                    $(this).removeClass("open");
                                    $('#img_ty').attr('src', 'http://www.oma.cloud.connect4education.org/images/buttons/button_ty_closed.png');
                                } else {
                                    $('#ty_view').show("slow");
                                    $(this).addClass("open");
                                    $('#img_ty').attr('src', 'http://www.oma.cloud.connect4education.org/images/buttons/button_ty_open.png');
                                }
                            }
                        });
                    }
                    if ((res & dv) != 0) {
                        // cwang: 9/27/11: Initialize first
                        $('#discoverVideo').remove();
                        $('#supportContent').append('<div id="discoverVideo"><img id="img_dv" src="http://www.oma.cloud.connect4education.org/images/buttons/button_discover_video.png" alt="Discover Video" /></div>');
                        $('#img_dv').click(function () {
                            if (dvText == "") dvSetup();
                            else {
                                $('#dvdiv').append(dvText);
                                popUpShow('#dvdiv', true);
                            }
                        });
                    }

                    if (classname == 'renaissance' || classname == 'baroque' || classname == 'classical' || classname == 'romantic' || classname == 'contemporary') {
                        // cwang: 9/27/11: Initialize first
                        $('#periodMaps').remove();
                        if (classname != 'contemporary')
                            $('#supportContent').append('<div id="periodMaps"><img class="img_cm" src="http://www.oma.cloud.connect4education.org/images/buttons/button_period_map.png" alt="Period Maps" /></div>');
                        else {
                            $('#supportContent').append('<div id="periodMaps"><img class="img_cm" id="_europe" src="http://www.oma.cloud.connect4education.org/images/buttons/button_period_map_europe.png" alt="Period Maps" /></div><div id="periodMaps"><img class="img_cm" id="_americas" src="http://www.oma.cloud.connect4education.org/images/buttons/button_period_map_americas.png" alt="Period Maps" /></div>');
                        }
                        // cwang: 9/27/11: Initialize first
                        $('#cmdiv').remove();
                        $('#cp4cmdiv').remove();
                        $('#boxes').append('<div id="cmdiv" class="window"></div><div id="cp4cmdiv" class="window"></div>');

                        $('.img_cm').click(function () {
                            var suffix = "";
                            if (typeof $(this).attr('id') != "undefined")
                                suffix = $(this).attr('id');

                            $('#cmdiv').flash({
                                swf: 'http://www.connect4education.org/flash/composerMap.swf?',
                                allowScriptAccess: 'always',
                                quality: 'high',
                                flashvars: 'period=' + classname + suffix,
                                width: 800,
                                height: 600
                            });
                            $('#cmdiv').append('<a class="close-window"></a>');
                            popUpShow('#cmdiv', true);
                        });
                    }

                    if ((res & kw) != 0) {
                        // cwang: 9/27/11: Initialize first
                        $('#keyWords').remove();
                        $('#supportContent').append('<div id="keyWords"><img id="img_kw" src="http://www.oma.cloud.connect4education.org/images/buttons/button_keywords.png" alt="Keywords" /></div>');

                        $('#img_kw').click(function () {
                            if (!$('#img_kw').hasClass('doOnce')) {
                                kwSetup();
                                $('#img_kw').addClass('doOnce');
                            } else {
                                popUpShow('#kwdiv', true);
                            }
                        });
                    }
                }
            });
        } catch (err) {
        }
    }

    function loadTY() {
        $.ajax({ url: "http://www.c4edu.mobi/jsonp.asmx/getTYCount",
            data: { section: JSON.stringify(classname) },
            dataType: "jsonp",
            success: function (data) {
                var x = data.d;
                if (x != 0) {
                    $('#ty_view').append("<div id='qhead'>Question #<label id='qnum'></label><span id='alphas'></span></div><div id='qtext'/><br /><div id='atext' />");
                    for (var i = 1; i <= x; i++) {
                        $('#alphas').append("<a class='tyqnum q" + i + "'>" + i + "</a>");
                    }
                    $('.tyqnum').click(function () {
                        getTy($(this).html());
                    });
                }
                getTy(1);
                $('#ty_view').show("slow");
                $('#img_ty').addClass("open");
                $('#img_ty').attr('src', 'http://www.oma.cloud.connect4education.org/images/buttons/button_ty_open.png');
            }
        });
    }

    function nextQuestion(nextQ) {
        if (jQuery('#correct').length > 0) {
            getTy(nextQ);
        }
    }

    function getTy(aQnum) {
        if (playingTY) {
            $('#player').flash(
                        function () {
                            this.stopPlayer(true);
                        });
        }
        $('#qnum').html(aQnum);
        $('.tyqnum').removeClass('hilite');
        $('.q' + aQnum).addClass('hilite');
        $.ajax({ url: "http://www.c4edu.mobi/jsonp.asmx/getTY",
            data: { section: JSON.stringify(classname), qnum: aQnum },
            dataType: "jsonp",
            success: function (data) {
                var x = data.d;
                $('#qtext').html(x[0]);
                if (x[1] != "") {
                    $('#qtext').append("<br style='line-height:20px'/>&nbsp;&nbsp;<img style='display:inline' src='http://www.oma.cloud.connect4education.org/images/icons/play_button.png' id='' class='tPlay " + x[1] + " " + x[2] + " " + x[3] + "' width='20' height='20' border='0' alt='Click to Listen'>&nbsp;Play");
                }
                $('#atext').html('');
                for (var i = 4; i < x.length; ) {
                    var atext = "<div class='tya'><input type='radio' class='aRadio' name='aRadio' value='" + x[i++] + "'/>&nbsp;";
                    if (x[i] != '') {
                        atext += "<img style='display:inline' id='Answer #" + i / 5 + "' src='http://www.oma.cloud.connect4education.org/images/icons/play_button.png' class='tPlay " + x[i++] + " " + x[i++] + " " + x[i++] + "' width='20' height='20' border='0' alt='Click to Listen'>&nbsp;";
                    } else { i += 3; };
                    atext += x[i] + (x[i++] == 'Excerpt' ? " #" + (i - 4) / 5 : "") + "</div>";
                    $('#atext').append(atext);
                }
                $('#atext').append("<br/>");
                $('.aRadio').click(function () {
                    $('#wrong').empty().remove();
                    $.ajax({
                        url: "http://www.c4edu.mobi/jsonp.asmx/ansRes",
                        dataType: "jsonp",
                        data: { aid: $(this).val() },
                        success: function (data) {
                            var atext = data.d.substring(1);
                            if (data.d.charAt(0) == '1') {
                                var nextQ = parseInt(aQnum) + 1;
                                if ($('.q' + nextQ).length == 0)
                                    nextQ = 1;
                                $('#atext').html("<div id='correct'>" + atext + "<br/><span style='float:right'>Next Question</span><br/></div>");
                                $('#correct').fadeIn(2000);
                                $('#correct').click(function () {
                                    $('#correct').unbind('click');
                                    $('#correct').empty().remove();
                                    getTy(nextQ);
                                });
                            } else {
                                $('#atext').append("<div id='wrong'>" + atext + "</div>");
                                $('#wrong').fadeIn(1000);
                            }
                        }
                    });

                });

                $('.tPlay').click(function (event) {
                    event.preventDefault();
                    var classnames = $(this).attr('class');
                    var temp = new Array();
                    temp = classnames.split(" ");
                    var start = '';
                    var end = '';
                    if (temp.length == 4) {
                        start = temp[2];
                        end = temp[3];
                    }
                    var id = $(this).attr("id");
                    togglePlayer("show");
                    try {
                        $('#player').flash(
                        function () {
                            this.stopPlayer(false);
                            this.updatePlayer(temp[1], start, end, "Test Yourself", id);
                            playingTY = true;
                        });
                    } catch (err) {
                        alert("Sorry, the player hasn't finished loading yet. Please try again when you see the player loaded.");
                        return;
                    }
                });
            }
        });
    }

    function popUpShow(element, doShow) {

        //Set height and width to mask to fill up the whole screen
        $('#mask').css({ 'width': $(window).width(), 'height': $(document).height() });

        //Set the popup window to center
        if (element == "#kwdiv") {
            $(element).css('top', '5%');
            $(element).css('left', '35%');
            $(element).css('height', $(window).height() * .85);

        } else if (element == "#dvdiv") {
            var width = numDVperRow * 270;
            $(element).css('width', width);
            $(element).css('height', $(window).height() * .80);

            //Set the popup window to center
            $(element).css('top', '5%');
            $(element).css('left', ($(window).width() - width) / 2);
        } else if (element == '#lgdiv') {
            //Set the popup window to center
            $(element).css('width', lgW);
            $(element).css('height', Math.min($(window).height() - 10, lgH));
            if (lgH > $(window).height() - 10) {
                $(element).css('overflow-y', 'scroll');
            } else {
                $(element).css('overflow-y', 'hidden');
            }
            $(element).css('top', Math.max(0, ($(window).height() - lgH) / 2));
            $(element).css('left', ($(window).width() - lgW) / 2);
        } else if (element == '#cpdiv') {
            //Set the popup window to center
            $(element).css('width', Math.min(520, $(window).width()));
            $(element).css('height', Math.min(574, $(window).height()));
            $(element).css('top', Math.max(0, ($(window).height() - 574) / 2));
            $(element).css('left', Math.max(0, ($(window).width() - 520) / 2));
        } else if (element == '#cmdiv') {
            //Set the popup window to center
            var elmW = Math.min(750, $(window).width());
            var elmH = Math.min(570, $(window).height());
            var elmL = Math.max(0, ($(window).width() - 750) / 2);
            $(element).css('width', elmW);
            $(element).css('height', elmH);
            $(element).css('top', Math.max(0, ($(window).height() - 570) / 2));
            $(element).css('left', elmL);
            $('#cp4cmdiv').css('top', $(element).css('top'));
            $('#cp4cmdiv').css('left', elmL + Math.max(0, (elmW - 520) / 2));
            $('#cp4cmdiv').css('width', Math.min(elmW, 520));
            $('#cp4cmdiv').css('height', Math.min(elmH, 574));
            $('#cp4cmdiv').hide();
        } else if (element == '#lo_view') {
            //Set the popup window to center
            $(element).css('height', Math.floor($(window).height() * .8));
            $(element).css('top', '20px');
            $(element).css('left', Math.floor(($(window).width() - $(element).width()) / 2));
        }

        //transition effect 
        if (doShow) {
            $('#mask').fadeIn(1000);
            $('#mask').fadeTo("slow", 0.6);
            $(element).fadeIn(2000);
        }
        // Functionality for the close button in top right of div
        $('.close-window').click(function (event) {
            event.preventDefault();
            $(this).parent().hide();
            $('#dvdiv').empty();
            if (!$('.window').is(':visible'))
                $('#mask').hide();
        });
    }

    $('#mask').click(function () {
        $('#mask').hide();
        $('#dvdiv').empty();
        $('#lgdiv').empty();
        $('.window').hide();
        $('#lo_view').hide();
    });

    $(window).resize(function () {

        var newnumDVperRow = Math.floor(($(window).width() - 20) / 270);
        if (newnumDVperRow == 0) newnumDVperRow = 1;

        if (newnumDVperRow != numDVperRow) {
            numDVperRow = newnumDVperRow;
            dvAddLineBreaks();
            $('#dvdiv').html(dvText);
        }
        lgH = Math.min($(window).height(), 666);
        lgW = Math.floor(1.45 * lgH);

        if ($("#dvdiv").is(":visible"))
            popUpShow('#dvdiv', false);
        if ($("#lgdiv").is(":visible")) {
            popUpShow('#lgdiv', false);
            $('#lgdiv').empty();
            $('#lgdiv').append('<iframe width="' + lgW + ' " height="' + lgH + '" src="' + lgUrl + '" frameborder="0"></iframe><a href="#" class="close-window"></a>');
            popUpShow('#lgdiv', false);
            /*
            $('#lgdiv').flash({
            swf: lgUrl,
            allowScriptAccess: 'always',
            quality: 'high',
            width: lgW,
            height: lgH,
            bgcolor: '#FFFFFF'
            });*/
        }

        if ($("#kwdiv").is(":visible"))
            popUpShow('#kwdiv', false);
        if ($("#lo_view").is(":visible"))
            popUpShow('#lo_view', false);
        if ($("#cpdiv").is(":visible"))
            popUpShow('#cpdiv', false);
        if ($("#cmdiv").is(":visible")) {
            var cpVis = $("#cp4cmdiv").is(":visible");
            popUpShow('#cmdiv', false);
            if (cpVis)
                $('#cp4cmdiv').show();
        }

    });

    function kwSetup() {
        // cwang: 10/2/11: initialize
        $('#kwdiv').remove();
        $('#boxes').append('<div id="kwdiv" class="window"><a href="#" class="close-window"></a><div class="title">Keywords</div><br/></div>');
        try {
            $.ajax({ url: "http://www.c4edu.mobi/jsonp.asmx/getKW",
                data: { section: JSON.stringify(classname) },
                dataType: "jsonp",
                success: function (data) {
                    var x = data.d;
                    for (var i = 0; i < x.length; ) {
                        var kw = x[i++];
                        var url = x[i++];
                        if (url == "") url = kw;
                        $('#kwdiv').append("<span class='kw' id='" + url + "'>" + kw + "</span><br/>");
                    }
                    popUpShow('#kwdiv', true);
                    $('.kw').click(function (e) {
                        e.preventDefault();
                        var urlword = $(this).attr('id');
                        var url = "http://dictionary.onmusic.org/terms/" + urlword;
                        window.open(url, 'newwin', 'toolbar=yes,location=no,status=no,menubar=no,scrollbars=yes,resizable=yes,width=1024,height=768');
                    });
                }
            });
        } catch (err) {
            alert("Could not load keywords");
        }
    }

    var dvText = "";
    var numDVperRow = 1;

    function dvAddLineBreaks() {
        dvText = dvText.replace(/<\/div><p style='clear:both'\/>/g, "</div>");
        var divs = new Array();
        divs = dvText.split('<newdiv>');
        for (var i = numDVperRow + 1; i < divs.length; i += numDVperRow) {
            divs[i] = "<p style='clear:both'/>" + divs[i];
        }
        dvText = "";
        for (i = 0; i < divs.length; i++) {
            dvText += divs[i];
        }
    }

    function dvSetup() {
        numDVperRow = Math.floor(($(window).width() - 20) / 270);
        if (numDVperRow == 0) numDVperRow = 1;

        // cwang: 10/2/11: initialize
        $('#dvdiv').remove();
        $('#boxes').append('<div id="dvdiv" class="window"></div>');
        try {
            $.ajax({ url: "http://c4edu.mobi/jsonp.asmx/getDV",
                data: { section: JSON.stringify(classname) },
                dataType: "jsonp",
                success: function (data) {

                    var x = data.d;
                    var counter = 0;
                    dvText = '<a href="#" class="close-window"></a><div class="title">Discover Video</div><br/>';
                    for (var i = 0; i < x.length; ) {
                        var mainText = x[i++];
                        var subText = x[i++];
                        var ytUrl = x[i++];
                        
                        dvText += '<newdiv><div class="iDiv"><iframe class="ytFrame" src="' + (ytUrl.indexOf("http") >= 0 ? ytUrl : "http://www.youtube.com/embed/" + ytUrl) + '" frameborder="0" allowfullscreen></iframe><br/><div><strong>' + mainText + '</strong><br/><span style="font-size:smaller">' + subText + '</span></div></div>';
                    }
                    dvAddLineBreaks();
                    $('#dvdiv').html(dvText);
                    popUpShow('#dvdiv', true);
                }
            });
        } catch (err) {
            alert("Could not load videos");
        }
    }

    $('#toggleArea').click(function () {
        togglePlayer();
    });

    function togglePlayer(action) {
        if ($('#player').hasClass('collapsed') && action != "hide") {
            $('#spacer').show();
            $('#playerimg').attr('src', 'http://www.oma.cloud.connect4education.org/images/banner/playertab_open.png');
            if (!$('#player').hasClass('dragged'))
                $('.menuControl').css({ bottom: function (index, value) { return '130px' } });
            else $('.doDock').show();
            $('#player').css('opacity', '1.0');
            $('#player').removeClass('collapsed');
        } else if (action != "show") {
            $('#playerimg').attr('src', 'http://www.oma.cloud.connect4education.org/images/banner/playertab_close.png');
            if (!$('#player').hasClass('dragged')) {
                if ($.browser.mozilla) {
                    // On firefox, flash element has to be within visible area of page or else it isn't
                    // instantiated in time
                    $('.menuControl').css({ bottom: function (index, value) { return '4px' } });
                } else $('.menuControl').css({ bottom: function (index, value) { return '0px' } });
            }
            else $('.doDock').hide();
            $('#player').css('opacity', '0.0');
            $('#player').addClass('collapsed');
            if (!$.browser.mozilla)
                $('#spacer').hide();
        }
    }
    var dragOpts = {
        cursor: "move",
        cancel: "#player, .doDock",
        distance: 30,
        scroll: false,
        drag: function (event) {
            if (!$('#player').hasClass('dragged')) {
                $('#player').addClass('dragged');
                $('.menuControl').css('bottom', 'inherit');
                if ($('#player').css('opacity') == 1.0)
                    $('.doDock').show();
            }
        }
    };

    // Draggability works funky in IE, so disable it there
    // Also FF
    if (!$.browser.msie && !$.browser.mozilla)
        $('.menuControl').draggable(dragOpts);

    $('.doDock').click(function () {
        $('.doDock').hide();
        $('#player').removeClass('dragged');
        togglePlayer("hide");
        $('.menuControl').css('left', '0px');
        $('.menuControl').css('top', 'inherit');
    });


    // If they exist, instantiate Flash elements

    $('#oct_enharm').flash({
        swf: 'http://www.connect4education.org/flash/2_oct_enharm.swf',
        allowScriptAccess: 'always',

        quality: 'high',
        width: 522,
        height: 250
    });

    $('#staff').flash({
        swf: 'http://www.connect4education.org/flash/staff.swf',
        allowScriptAccess: 'always',
        quality: 'high',
        width: 575,
        height: 400
    });

    $('#notes_staff').flash({
        swf: 'http://www.connect4education.org/flash/notes_on_staff.swf',
        allowScriptAccess: 'always',
        quality: 'high',
        width: 400,
        height: 150
    });

    $('#hilo').flash({
        swf: 'http://www.connect4education.org/flash/higher_lower_pitches.swf',
        allowScriptAccess: 'always',
        quality: 'high',
        width: 280,
        height: 165
    });

    $('#note_equiv').flash({
        swf: 'http://www.connect4education.org/flash/note_equivalents.swf',
        allowScriptAccess: 'always',
        quality: 'high',
        width: 601,
        height: 431
    });

    $('#note_elements').flash({
        swf: 'http://www.connect4education.org/flash/note_elements.swf',
        allowScriptAccess: 'always',
        quality: 'high',
        width: 300,
        height: 190
    });

    $('#octv').flash({
        swf: 'http://www.connect4education.org/flash/2_octv.swf',
        allowScriptAccess: 'always',
        quality: 'high',
        width: 522,
        height: 250
    });
});

function getCp(cid) {
    jQuery('#cp4cmdiv').flash({
        swf: 'http://www.connect4education.org/flash/composer_profile.swf?composer_id=' + cid,
        allowScriptAccess: 'always',
        quality: 'high',
        width: 520,
        height: 574
    });
    jQuery('#cp4cmdiv').append('<a href="#" class="close-window"></a>');
    jQuery('.close-window').click(function () {
        jQuery(this).parent().hide();
        jQuery('#dvdiv').empty();
        if (!jQuery('.window').is(':visible'))
            jQuery('#mask').hide();
    });
    jQuery('#cp4cmdiv').show();
}