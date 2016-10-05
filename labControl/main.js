isvar http = require("http");
var fs = require("fs");

http.createServer(function (request, response) {

   // Send the HTTP header
   // HTTP Status: 200 : OK
   // Content Type: text/plain
   response.writeHead(200, {'Content-Type': 'text/plain'});

    fs.readFile('input.txt', function (err, data) {
        if (err) return console.error(err);
        console.log(data.toString());
    });
   response.end(data.toString());

}).listen(8081);

// Console will print the message
console.log('Server running at http://127.0.0.1:8081/');
