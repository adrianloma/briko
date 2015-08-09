// app.use(require('./server/error-shutdown')(5000, server));
// app.use(require('serve-favicon')(__dirname + '/public/img/favicon.ico'));



// var apiRouter = require('./api/routes/main');
// app.use('/api', apiRouter);
// require('./server/error-handlers')(app);



//############################
var express = require('express'),
    path = require('path');
var app = express();
var server;

var bodyParser = require('body-parser');
var spawn = require('child_process').spawn;
var fs = require ('fs');
var ls;
var out;
var send = require('send');
//var multer = require('multer'); 
// app.set('port', process.env.PORT || 3000);



app.use(bodyParser.urlencoded({
  extended: true
}));

app.use(bodyParser.json());
//app.use(multer());

app.use(express.static(path.join(__dirname, 'public')));
app.use(express.static(path.join(__dirname, 'webApp')));



// var startServer = function () {
//     server = require('http').createServer(app).listen(app.get('port'),
//       function () {
//         console.log('Server started.');
//       }
//     );
// };

// startServer();

// });


// app.post('/compile', function(req, res) {
//   hola.push(req.body);
//   res.json(true);
// });




app.get('/', function(req, res){
  // fs.readFile(__dirname + 'webApp/index.html', function (err,data) {
  //   if (err) {
  //     res.writeHead(404);
  //     res.end(JSON.stringify(err));
  //     return;
  //   }
  //   res.writeHead(200);
  //   res.end(data);
  // });
  res.sendFile('./webApp/index.html');
});

app.post('/compile', function(req, res) {

  console.log(req.body.code);

  fs.writeFile( __dirname + '/p1.c', '#include "math.h"\n' + req.body.code, 
    function (err) {
      if (err) {
        return console.log(err);
      }
    });
//   //console.log(req.text);


/*
avr-g++  {FILE LOC} -o {FILE LOC}.o


avr-gcc -w -Os -Wl,--gc-sections -mmcu=atmega32u4 -o {FILE LOC}.elf {FILE LOC}.o tmp/core/core.a -Ltmp -lm 

avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 {FILE LOC}.elf {FILE LOC}.eep 
avr-objcopy -O ihex -R .eeprom {FILE LOC}.elf {FILE LOC}.hex 


*/
// avr-g++ ./p1.c -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10000 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 -DUSB_MANUFACTURER="Unknown" -DUSB_PRODUCT="Arduino Leonardo"  -I./sourceCompiler/cores/arduino -I./sourceCompiler/leonardo   -o ./public/a.out
  var flags1 = '-c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10000 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 -DUSB_MANUFACTURER="Unknown" -DUSB_PRODUCT="Arduino Leonardo"';
  var flags2 = "-I" + __dirname + "/sourceCompiler/cores/arduino -I" + __dirname + "/sourceCompiler/leonardo ";
  var gcc = spawn('avr-g++', [__dirname + '/p1.c', flags1, flags2,  '-o', __dirname + '/public/a.out']);
  gcc.stderr.on('data', function (data) {
    console.log('stderr: ' + data);
  });
  gcc.on('close', function (code) {
    //console.log('child process exited with code ' + code);
    // if(code == 0){
    //     var gcc2 = spawn('avr-g++', [ '-w -Os -Wl,--gc-sections -mmcu=atmega32u4', '-o ', __dirname + '/public/a.out.elf', __dirname + '/public/a.out', __dirname + '/tmp/core/core.a -Ltmp -lm']);
    //     gcc2.stderr.on('data', function (data) {
    //       console.log('stderr: ' + data);
    //     });
    //     gcc2.on('close', function (code) {
    //       //console.log('child process exited with code ' + code);
    //       if(code == 0){
    //           var gcc3 = spawn('avr-objcopy', [ '-O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0',  __dirname + '/public/a.out.elf',  __dirname + '/public/a.out.eep']);
    //           gcc3.stderr.on('data', function (data) {
    //             console.log('stderr: ' + data);
    //           });
    //           gcc3.on('close', function (code) {
    //             //console.log('child process exited with code ' + code);
    //             if(code == 0){
    //               var gcc4 = spawn('avr-objcopy', ['-O ihex -R .eeprom', __dirname + '/public/a.out.elf', __dirname + '/public/a.hex']);
    //               gcc4.stderr.on('data', function (data) {
    //                 console.log('stderr: ' + data);
    //               });
    //               gcc4.on('close', function (code) {
    //                 //console.log('child process exited with code ' + code);
    //                 if(code == 0){
    //                   send(req, 'public/a.hex').pipe(res);
    //                   return;
    //                 }
    //               });
    //             }
    //           });
    //       }
    //     })
    //   }
    });
      res.set('Content-Type', 'text/plain');
      res.send(500, 'error');
      return;
    });

  // gcc = spawn('avr-g++', [__dirname + '/p1.c', flags1, flags2,  '-o', __dirname + '/public/a.out']);
  // gcc.stderr.on('data', function (data) {
  //   console.log('stderr: ' + data);
  // });

  // gcc.on('close', function (code) {
  //   console.log('child process exited with code ' + code);
  //   if(code == 0){
  //     send(req, 'public/a.out').pipe(res);
  //   } else{
  //     res.set('Content-Type', 'text/plain');
  //     // util = require("util");
  //     // var obj_str = util.inspect(res);
  //     // console.log(obj_str);
  //     res.send(500, 'error');
  //   }
    
  // });
  // fs.readFile('public/a.out', 'utf8', 
  //   function(err,data){
  //     if(err) {
  //       return console.log(err);
  //     }
  //     //console.log(data);
  //     out = data;
  //     res.send(out);
  //   });


  // cleanUp = function(){
  //   rm = spawn('rm', ['-rf', __dirname + '/public/a.out', __dirname + '/p1.c']);
  //   gcc.stderr.on('data', function (data) {
  //   console.log('stderr: ' + data);
  // });
  // }



  
  //.on('end', cleanUp),
// });


//   var options = {
//     root: __dirname,
//     dotfiles: 'deny',
//     headers: {
//         'x-timestamp': Date.now()
//     }
//   };
//   var fileName = 'a.out';
//   res.sendFile(fileName, options, function (err) {
//     if (err) {
//       console.log(err);
//       res.status(err.status).end();
//     }
//     else {
//       console.log('Sent:', fileName);
//     }
//   });
// });


app.listen(process.env.PORT || 80);

/*

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




  */