#!/usr/bin/node
// Prints the title of a Star Wars movie where the episode number matches a given integer.
const argv = require('process').argv;
const request = require('request');

const url = 'https://swapi-api.hbtn.io/api/films/' + argv[2];

request(url, (error, response, body) => {
  if (error) {
    console.log(error);
  }
  const film = JSON.parse(body);
  console.log(film.title);
});
