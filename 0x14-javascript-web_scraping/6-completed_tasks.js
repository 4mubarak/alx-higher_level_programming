#!/usr/bin/node
// Computes the number of tasks completed by user id.
const argv = require('process').argv;
const request = require('request');

request(argv[2], (error, response, body) => {
  if (error) {
    console.log(error);
  }
  const todos = JSON.parse(body);
  const todosStatus = {};

  for (const x in todos) {
    if (todos[x].completed === true) {
      todosStatus[todos[x].userId] = (todosStatus[todos[x].userId] + 1) || 1;
    }
  }

  console.log(todosStatus);
});
