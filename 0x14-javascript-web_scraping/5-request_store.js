#!/usr/bin/node
// Gets the contents of a webpage and stores it in a file.
const argv = require('process').argv;
const request = require('request');
const fs = require('fs');

request
  .get(argv[2])
  .on('error', err => {
    console.log(err);
  })
  .pipe(fs.createWriteStream(argv[3], 'utf-8'));
