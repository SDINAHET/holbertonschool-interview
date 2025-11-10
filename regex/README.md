# regex


```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/regex# gcc -Wall -Wextra -Werror -pedantic main.c regex.c
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/regex# ./a.out
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/regex#
```

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/regex# gcc -Wal
l -Wextra -Werror -pedantic main_1.c regex.c -o regex_tests
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/regex# ./regex
-bash: ./regex: No such file or directory
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/regex# ./regex_
tests
[PASS] regex_match("A", "A") -> "A" ~~ "A" (got=1)
[PASS] regex_match("A", "") -> "A" ~~ "" (got=0)
[PASS] regex_match("", "A") -> "" ~~ "A" (got=0)
[PASS] regex_match("", "") -> "" ~~ "" (got=1)
[PASS] regex_match("AA", "A") -> "AA" ~~ "A" (got=0)
[PASS] regex_match("A", "AA") -> "A" ~~ "AA" (got=0)
[PASS] regex_match("A", "A*") -> "A" ~~ "A*" (got=1)
[PASS] regex_match("AA", "A*") -> "AA" ~~ "A*" (got=1)
[PASS] regex_match("AAAAA", "A*") -> "AAAAA" ~~ "A*" (got=1)
[PASS] regex_match("AAAAAAAAAA", "A*") -> "AAAAAAAAAA" ~~ "A*" (got=1)
[PASS] regex_match(40x"A", "A*") -> "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ~~ "A*" (got=1)
[PASS] regex_match(160x"A", "A*") -> "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" ~~ "A*" (got=1)
[PASS] regex_match("", "A*") -> "" ~~ "A*" (got=1)
[PASS] regex_match("B", "A*") -> "B" ~~ "A*" (got=0)
[PASS] regex_match("AB", "A*") -> "AB" ~~ "A*" (got=0)
[PASS] regex_match("BA", "A*") -> "BA" ~~ "A*" (got=0)
[PASS] regex_match("AB", "AB") -> "AB" ~~ "AB" (got=1)
[PASS] regex_match("AB", "AB*") -> "AB" ~~ "AB*" (got=1)
[PASS] regex_match("ABB", "AB*") -> "ABB" ~~ "AB*" (got=1)
[PASS] regex_match("A", "AB*") -> "A" ~~ "AB*" (got=1)
[PASS] regex_match("A", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*") -> "A" ~~ "ABCDEFGHIJKLMNOPQRSTUVWXYZ*" (got=0)
[PASS] regex_match("AZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ") -> "AZ" ~~ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" (got=0)
[PASS] regex_match("AZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*") -> "AZ" ~~ "ABCDEFGHIJKLMNOPQRSTUVWXYZ*" (got=0)
[PASS] regex_match("AFJLOSWZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*") -> "AFJLOSWZ" ~~ "ABCDEFGHIJKLMNOPQRSTUVWXYZ*" (got=0)
[PASS] regex_match("AFJPLOSWZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*") -> "AFJPLOSWZ" ~~ "ABCDEFGHIJKLMNOPQRSTUVWXYZ*" (got=0)
[PASS] regex_match("AB", "A.") -> "AB" ~~ "A." (got=1)
[PASS] regex_match("ABC", "A.C") -> "ABC" ~~ "A.C" (got=1)
[PASS] regex_match("ABC", "A..") -> "ABC" ~~ "A.." (got=1)
[PASS] regex_match("ABC", "A.") -> "ABC" ~~ "A." (got=0)
[FAIL] regex_match(ALPHABET, "A + 25 dots") -> "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ~~ "A................................." (got=0, expect=1)
[FAIL] regex_match(ALPHABET, "A + 24 dots + Z") -> "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ~~ "A................................Z" (got=0, expect=1)
[PASS] regex_match(ALPHABET, "A + 23 dots + Z (should fail)") -> "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ~~ "A...............................Z" (got=0)
[PASS] regex_match("", ".") -> "" ~~ "." (got=0)
[PASS] regex_match("", ".*") -> "" ~~ ".*" (got=1)
[PASS] regex_match("A", ".*") -> "A" ~~ ".*" (got=1)
[PASS] regex_match("AA", ".*") -> "AA" ~~ ".*" (got=1)
[PASS] regex_match("AABB", ".*") -> "AABB" ~~ ".*" (got=1)
[PASS] regex_match("Lorem...", ".*") -> "Lorem ipsum dolor si amet" ~~ ".*" (got=1)
[PASS] regex_match("ABC", "ZA.") -> "ABC" ~~ "ZA." (got=0)
[PASS] regex_match("ABC", "ZAB.") -> "ABC" ~~ "ZAB." (got=0)
[PASS] regex_match("ABC", "ZABC.") -> "ABC" ~~ "ZABC." (got=0)
[PASS] regex_match("ABC", "Z.") -> "ABC" ~~ "Z." (got=0)
[PASS] regex_match("ABC", ".*") -> "ABC" ~~ ".*" (got=1)
[PASS] regex_match("ABC", "..") -> "ABC" ~~ ".." (got=0)
[PASS] regex_match("ABC", 20 dots) -> "ABC" ~~ "...................." (got=0)
[PASS] regex_match("", 20 dots) -> "" ~~ "...................." (got=0)
[PASS] exact long sentence -> "Lorem ipsum dolor si amet" ~~ "Lorem ipsum dolor si amet" (got=1)
[PASS] prefix partial with .* -> "Lorem ipsum dolor si amet" ~~ "Lor.*m ipsum dolor si amet" (got=1)
[PASS] prefix partial 2 with .* -> "Lorem ipsum dolor si amet" ~~ "Lore.*m ipsum dolor si amet" (got=1)
[PASS] leading .* -> "Lorem ipsum dolor si amet" ~~ ".*Lorem ipsum dolor si amet" (got=1)
[PASS] trailing .* -> "Lorem ipsum dolor si amet" ~~ "Lorem ipsum dolor si amet.*" (got=1)
[PASS] both sides '.' require extra chars -> "Lorem ipsum dolor si amet" ~~ ".Lorem ipsum dolor si amet." (got=0)
[PASS] two dots require two chars between 'Lorem' and 'ipsum' -> "Lorem ipsum dolor si amet" ~~ ".Lorem..ipsum dolor si amet.*" (got=0)
[PASS] one leading '.' still fails at start (needs extra char) -> "Lorem ipsum dolor si amet" ~~ ".Lorem.ipsum dolor si amet.*" (got=0)
[PASS] leading and trailing '.' -> need extra chars -> "Lorem ipsum dolor si amet" ~~ ".Lorem ipsum dolor si amet." (got=0)
[PASS] requires leading char then >=4 chars before 'dolor' -> "Lorem ipsum dolor si amet" ~~ ".Lorem .....*dolor si amet." (got=0)
[PASS] requires leading char and two chars before 'dolor' -> "Lorem ipsum dolor si amet" ~~ ".Lorem ..dolor si amet." (got=0)
[PASS] dot covers 'L' at start -> "Lorem ipsum dolor si amet" ~~ ".orem ipsum dolor si amet" (got=1)
[PASS] dot covers final 't' -> "Lorem ipsum dolor si amet" ~~ "Lorem ipsum dolor si ame." (got=1)

Summary: 57/59 passed
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/regex#
```
