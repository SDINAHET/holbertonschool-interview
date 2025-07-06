# 🧾 Fiche Projet — Holberton School
# 💡 Linear Search in a Skip List (C language)
## 🎯 Objectif
Optimiser la recherche dans une liste chaînée triée en utilisant une voie express (skip list).
Implémenter une fonction linear_skip capable de rechercher une valeur plus rapidement qu’une recherche linéaire classique.

## 📚 Contexte
Dans une skip list, certaines positions-clés disposent d’un raccourci express pour sauter plusieurs nœuds.
Cela réduit considérablement le temps de recherche dans de grandes listes.

## 📐 Prototype attendu
```c
skiplist_t *linear_skip(skiplist_t *list, int value);
```

## 📦 Structure de données utilisée
```c
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;
```

## ⚙️ Comportement de la fonction
Utilise la voie express pour délimiter une zone probable.

Recherche linéaire classique dans cette zone.

Affiche à chaque étape :
✅ "Value checked at index [i] = [x]"
📌 "Value found between indexes [i] and [j]"

🧪 Exemple de sortie

```pgsql
Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11
```

## 📁 Fichiers du projet
Fichier	Description
0-linear_skip.c	Fonction principale linear_skip
search.h	Header avec structure et prototypes
0-main.c	Fichier de test (non requis à pousser)
skiplist/*.c	Fonctions utilitaires fournies pour tester

## 🛠️ Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
./0-linear_skip
```
✅ Contraintes
Ubuntu 14.04 + GCC 4.8.4

Norme Betty

Aucun global

Maximum 5 fonctions par fichier

Tous les prototypes dans search.h

Fichiers header protégés par #ifndef / #define / #endif


https://github.com/hs-hq/0x0E.Linear_search-in_skip_list/tree/main

gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip

