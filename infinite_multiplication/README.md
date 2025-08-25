# 📌 Infinite Multiplication








## 📖 Description

Ce projet consiste à implémenter un programme en C qui multiplie deux grands nombres positifs, même si ceux-ci dépassent la capacité des types standards (int, long, etc.).
L’objectif est de manipuler les chaînes de caractères pour effectuer une multiplication infinie.

## ✅ Requirements
General

Allowed editors: vi, vim, emacs

Compilation sur Ubuntu 14.04 LTS

Compiler : gcc 4.8.4 avec les flags :

-Wall -Werror -Wextra -pedantic


Chaque fichier doit se terminer par une nouvelle ligne

Un fichier README.md est obligatoire

Respect du style Betty (vérifié avec betty-style.pl et betty-doc.pl)

Pas de variables globales

Maximum 5 fonctions par fichier

Seules fonctions autorisées de la libc :

malloc

free

exit

Les fonctions interdites : printf, puts, calloc, realloc, etc.

Utilisation de _putchar permise

Le fichier _putchar.c n’a pas à être push (il sera fourni)

Tous les prototypes doivent être regroupés dans un fichier holberton.h

## 📝 Task
# 0. Infinite Multiplication (mandatory)

Écrire un programme qui multiplie deux nombres positifs :

🔹 Usage :
./mul num1 num2

🔹 Contraintes :

num1 et num2 seront donnés en base 10

Afficher le résultat suivi d’un retour à la ligne

Si le nombre d’arguments est incorrect → afficher Error + exit 98

Si un argument contient autre chose que des chiffres → afficher Error + exit 98

Possibilité d’utiliser plus de 5 fonctions dans le fichier

Vérification possible avec bc :

echo "num1 * num2" | bc

## 💻 Compilation & Exemples
Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-mul.c _putchar.c -o mul
```

Exécution
```bash
$ ./mul 10 98
980
```

```bash
$ ./mul 235234693269436436223446526546334576437634765378653875874687649698659586695898579 \
28658034365084365083426083109679137608216408631430814308651084650816406134060831608310853086103769013709675067130586570832760732096730978014607369739567864508634086304807450973045703428580934825098342095832409850394285098342509834209583425345267413639235755891879970464524226159074760914989935413350556875770807019893069201247121855122836389417022552166316010013074258781583143870461182707893577849408672040555089482160343085482612348145322689883025225988799452329290281169927532160590651993511788518550547570284574715925006962738262888617840435389140329668772644708
6741363923575589187997046452422615907476091498993541335055687577080701989306920124712185512283638941702255216631601001307425878158314387046118270789357784940867204055508948216034308548261234814532268988302522598879945232929028116992753216059081057377926651337612618248332113256902485974371969385156015068813868274000683912187818601667058605418678284322237297213673482412392922068159291496274311170208689056585352782844484721140846367741649962638649229509281867896067208474178402156294978940712959518351846413859141792380853313812015295333546716634344284086426775480775747808150030732119704867805688704303461042373101473485092019906795014369069932
```

📂 Repo

GitHub repository: holbertonschool-interview

Directory: infinite_multiplication

File: 0-mul.c


```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/infinite_multiplication# ./test0-mul.c
=== Tests OK ===
✅ OK 123 * 456 == 56088
```


```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/infinite_multiplication# gcc -Wall -Wextra -Werror -pedantic test0b-mul.c -o tes
t_mul
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/infinite_multiplication# ./test_mul
✅ 123 * 456
✅ 0 * 0
✅ 000000 * 42
✅ 98 * 765
✅ big * big
✅ alpha arg
✅ bad digit
✅ no args
✅ one arg
✅ three args

Summary: 10 pass / 0 fail
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/infinite_multiplication#
```

