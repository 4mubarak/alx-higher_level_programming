#!/usr/bin/node
// Displays the status of a GET request
const argv = require('process').argv;
const request = require('request');

request(argv[2], (error, response, body) => {
  if (error) {
    console.log(error);
  }
  console.log('code:', response.statusCode);
});
