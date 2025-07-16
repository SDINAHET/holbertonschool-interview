#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, (error, response, body) => {
  if (error) return console.error(error);

  const film = JSON.parse(body);
  const characters = film.characters;

  const printCharacters = (index) => {
    if (index >= characters.length) return;

    request(characters[index], (err, res, characterBody) => {
      if (err) return console.error(err);
      const character = JSON.parse(characterBody);
      console.log(character.name);
      printCharacters(index + 1);
    });
  };

  printCharacters(0);
});
