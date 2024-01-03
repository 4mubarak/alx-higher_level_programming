#!/usr/bin/node
// Prints the number of movies where the character “Wedge Antilles” is present.
const argv = require('process').argv;
const request = require('request');

let count = 0;
request(argv[2], (error, response, body) => {
  if (error) {
    console.log(error);
  }
  const films = JSON.parse(body).results;
  // Loop through the films
  for (const x in films) {
    // Loop through the characters in each film
    for (const y in films[x].characters) {
      // Check if Wedge Antilles' id is in the characters
      if (films[x].characters[y].includes('18')) {
        count += 1;
        break;
      }
    }
  }
  console.log(count);
});
