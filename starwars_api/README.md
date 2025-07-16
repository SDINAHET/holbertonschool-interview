starwars_api

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_
speFS/algo/holbertonschool-interview/starwars_api# node -v
v20.19.0
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_
speFS/algo/holbertonschool-interview/starwars_api# semistandard --version
17.0.0
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_
speFS/algo/holbertonschool-interview/starwars_api# npm list -g request
/usr/lib
└── (empty)

npm notice
npm notice New major version of npm available! 10.9.2 -> 11.4.2
npm notice Changelog: https://github.com/npm/cli/releases/tag/v11.4.2
npm notice To update run: npm install -g npm@11.4.2
npm notice
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_
speFS/algo/holbertonschool-interview/starwars_api#
```



1. Va dans le dossier starwars_api :
bash
Copier le code
cd starwars_api
2. Initialise un projet local :
bash
Copier le code
npm init -y
→ Cela crée un fichier package.json.

3. Installe request et semistandard localement :
bash
Copier le code
npm install request
npm install --save-dev semistandard
4. Teste si request fonctionne :
Ton script 0-starwars_characters.js peut maintenant faire :

js
Copier le code
const request = require('request');
et fonctionnera, car node va chercher node_modules/request localement.
