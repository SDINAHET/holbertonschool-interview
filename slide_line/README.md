# 2048 - Single Line

Reproduction du mécanisme du jeu 2048 sur une ligne unique d'entiers, sans allocation dynamique.

# 📀 Prérequis

Ubuntu 22.04 LTS

GCC 4.8.4 avec les flags : -Wall -Wextra -Werror -pedantic

Style Betty respecté (vérifié par betty-style.pl et betty-doc.pl)

Aucun usage de variables globales

Maximum 5 fonctions par fichier

Aucun malloc / calloc / realloc

# 🔧 Compilation

gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c

# 🧠 Prototype

int slide_line(int *line, size_t size, int direction);

line : pointeur vers un tableau d'entiers

size : taille du tableau

direction : SLIDE_LEFT (0) ou SLIDE_RIGHT (1)

Retourne 1 en cas de succès, 0 en cas d'échec

# 📁 Structure du projet

'''bash
slide_line/
├── 0-slide_line.c      // logique principale
├── slide_line.h        // macros + prototype
├── 0-main.c            // fichier de test (optionnel)
└── README.md
'''

## 💵 Exemples d'exécution

'''bash
$ ./0-slide_line L 2 2 2 2
Line: 2, 2, 2, 2
Slide to the left
Line: 4, 4, 0, 0
'''

'''bash
$ ./0-slide_line R 2 2 2 2 2
Line: 2, 2, 2, 2, 2
Slide to the right
Line: 0, 0, 2, 4, 4
'''

'''bash
$ ./0-slide_line L 2 4 8 16
Line: 2, 4, 8, 16
Slide to the left
Line: 2, 4, 8, 16
'''

🔹 Macros
'''bash
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1
'''

## 📈 Astuce

Fusionne les nombres identiques (séparés ou non par des zéros)

Chaque case ne peut fusionner qu'une seule fois par mouvement

On pousse les éléments non-nuls avant et après la fusion

# 👤 Auteur

Projet par Alexandre Gautier, Software Engineer @ Holberton SchoolREADME rédigé par Stéphane Dinahet

📄 Licence

Projet réalisé dans le cadre du programme Holberton School, à but éducatif.
