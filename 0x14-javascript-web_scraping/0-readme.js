#!/usr/bin/node
// Reads and prints the content of a file.
const argv = require('process').argv;
const fs = require('fs');

fs.readFile(argv[2], 'utf-8', (err, data) => {
  if (err) {
    console.error(err);
    return;
  }

  console.log(data.toString());
});
