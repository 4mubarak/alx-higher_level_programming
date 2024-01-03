#!/usr/bin/node
// Writes a string to a file
const argv = require('process').argv;
const fs = require('fs');

fs.writeFile(argv[2], argv[3], 'utf-8', err => {
  if (err) {
    console.error(err);
  }
});
