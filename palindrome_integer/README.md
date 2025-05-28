palindrome_integer


alex@~/palindrome_integer$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
alex@~/palindrome_integer$ ./palindrome 1
1 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 11
11 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 112
112 is not a palindrome.
alex@~/palindrome_integer$ ./palindrome 121
121 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
alex@~/palindrome_integer$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
alex@~/palindrome_integer$






```c
#include "palindrome.h"
```
➡️ Cette ligne inclut le fichier d'en-tête palindrome.h, qui contient la déclaration de la fonction is_palindrome. Cela permet au compilateur de savoir à l'avance que cette fonction existe.

```c
/**
 * is_palindrome - Checks if an unsigned long integer is a palindrome
 * @n: The number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
```
➡️ Ceci est un commentaire de documentation (docstring au format Betty).
Il explique :

Le nom de la fonction,

Le paramètre pris en entrée (n),

La valeur de retour (1 si palindrome, 0 sinon).

```c
int is_palindrome(unsigned long n)
```
➡️ Déclaration de la fonction :

Elle s'appelle is_palindrome,

Elle prend un paramètre n de type unsigned long (donc un nombre positif ou nul),

Elle retourne un int (1 ou 0).

```c
    unsigned long reversed = 0, original = n, digit;
```
➡️ Déclaration de 3 variables locales :

reversed : stockera le nombre inversé (par ex. 123 ➜ 321).

original : sauvegarde la valeur initiale de n, car n va être modifié dans la boucle.

digit : stocke le chiffre isolé à chaque itération (unités, dizaines, etc.).

```c
    while (n != 0)
```
➡️ Boucle while qui tourne tant que n n’est pas égal à 0.
Elle sert à construire le nombre inversé.

```c
        digit = n % 10;
```
➡️ On récupère le dernier chiffre du nombre n.
Exemple : si n = 123, alors digit = 3.

```c
        reversed = reversed * 10 + digit;
```
➡️ On ajoute le chiffre récupéré à la fin du nombre inversé.
Exemple :

reversed = 0, digit = 3 ➜ reversed = 0*10 + 3 = 3

digit = 2 ➜ reversed = 3*10 + 2 = 32

etc.

```c
        n /= 10;
```
➡️ On retire le dernier chiffre de n (division entière par 10).
Exemple : 123 ➜ 12 ➜ 1 ➜ 0

```c
    return (original == reversed);
```

➡️ Une fois la boucle terminée, on compare :

le nombre initial (original)

avec son miroir (reversed)

Si les deux sont égaux, c’est un palindrome, donc on retourne 1. Sinon, 0.

✅ Exemple :
Si n = 121, alors :

reversed = 121 → égal à original

donc return 1.

Si n = 123, alors :

reversed = 321 ≠ original

donc return 0.

Souhaites-tu un schéma visuel étape par étape pour un exemple comme 12321 ?

```c
```


Voici un schéma visuel étape par étape pour t’expliquer comment la fonction is_palindrome traite le nombre 12321 :

🔢 Étape initiale
```c
n = 12321
original = 12321
reversed = 0
```
🔁 Boucle while (n != 0)
🧮 1re itération :
```c
digit = n % 10 = 12321 % 10 = 1
reversed = reversed * 10 + digit = 0 * 10 + 1 = 1
n = n / 10 = 12321 / 10 = 1232
```
🧮 2e itération :
```c
digit = 1232 % 10 = 2
reversed = 1 * 10 + 2 = 12
n = 1232 / 10 = 123
```
🧮 3e itération :
```c
digit = 123 % 10 = 3
reversed = 12 * 10 + 3 = 123
n = 123 / 10 = 12
```
🧮 4e itération :
```c
digit = 12 % 10 = 2
reversed = 123 * 10 + 2 = 1232
n = 12 / 10 = 1
```
🧮 5e itération :
```c
digit = 1 % 10 = 1
reversed = 1232 * 10 + 1 = 12321
n = 1 / 10 = 0
```
✅ Fin de la boucle
```c
n == 0 ➜ fin
original = 12321
reversed = 12321
```
📌 Résultat final
```c
return (original == reversed) ➜ return (12321 == 12321) ➜ return 1
```
✅ Résultat affiché :
```csharp
12321 is a palindrome.
```
