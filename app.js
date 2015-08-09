var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var spawn = require('child_process').spawn;
var fs = require ('fs');
var ls;
var out;
//var multer = require('multer'); 

app.use(bodyParser.urlencoded({
  extended: true
}));

app.use(bodyParser.json());
//app.use(multer());
app.use(function(req, res, next){
  if (req.is('text/*')) {
    req.text = '';
    req.setEncoding('utf8');
    req.on('data', function(chunk){ req.text += chunk });
    req.on('end', next);
  } else {
    next();
  }
});


app.post('/compile', function(req, res) {
  fs.writeFile('/Users/rrs94/Desktop/tunahack/p1.c', '#include "Briko.h"\n' + req.text, function (err) {
  if (err) {
    return console.log(err);
  }
  });
  //console.log(req.text);

  ls    = spawn('gcc', ['', '/Users/rrs94/Desktop/tunahack/p1.c']);
  ls.stderr.on('data', function (data) {
    console.log('stderr: ' + data);
  });

  ls.on('close', function (code) {
    console.log('child process exited with code ' + code);
  });
  fs.readFile('a.out', 'utf8', function(err,data){
    if(err) {
      return console.log(err);
    }
    //console.log(data);
    out = data;
    res.send(out);
  })

});


// app.post('/compile', function(req, res) {
//   hola.push(req.body);
//   res.json(true);
// });


app.listen(process.env.PORT || 80);