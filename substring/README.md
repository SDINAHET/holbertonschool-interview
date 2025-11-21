# substring

```bash
alex@~/holbertonschool-interview_prep/substring$ gcc -Wall -Wextra -Werror -pedantic main.c substring.c
alex@~/holbertonschool-interview_prep/substring$ ./a.out barfoothefoobarman foo bar
Indices -> [0, 9]
alex@~/holbertonschool-interview_prep/substring$ ./a.out wordgoodgoodgoodbestword word good best word
Indices -> []
alex@~/holbertonschool-interview_prep/substring$ ./a.out wordgoodgoodgoodbestword word good best good
Indices -> [8]
alex@~/holbertonschool-interview_prep/substring$
```

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring#  gcc -Wall -Wextra -Werror -pedantic main.c substring.c
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring# ./a.out
Usage: ./a.out <string> [word [word2 ...]]
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring# touch tests.c
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring# nano tests.c
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring# gcc -Wall -Wextra -Werror -pedantic tests.c substring.c
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring# ./a.out
=== Test 1 ===
Expected: [0, 9]
Got     : [0, 9]
Result  : OK
```


```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring# gcc -Wall -Wextra -Werror -pedantic tests.c substring.c -o tests
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring# ./tests
=== Test 1: barfoothefoobarman / [foo, bar] ===
  Expected: [0, 9]
  Got     : [0, 9]
  Result  : OK

=== Test 2: barfoothefoobarman / [foo, bar, man] ===
  Expected: [9]
  Got     : [9]
  Result  : OK

=== Test 3: barfoothefoobarman / [foo, bar, the] ===
  Expected: [0, 6]
  Got     : [0, 6]
  Result  : OK

=== Test 4: barfoothefoobarman / [the, bar, foo] ===
  Expected: [0, 6]
  Got     : [0, 6]
  Result  : OK

=== Test 5: barfoothefoobarman / [the] ===
  Expected: [6]
  Got     : [6]
  Result  : OK

=== Test 6: barfoothefoobarman / [the, bar, man] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 7: barfoothefoobarman / [the, bar, foo, foo] ===
  Expected: [3]
  Got     : [0, 3]
  Result  : FAIL

=== Test 8: barfoothefoobarman / [the, bar, foo, foo, bar] ===
  Expected: [0]
  Got     : [0]
  Result  : OK

=== Test 9: barfoothefoobarman / [the, bar, foo, foo, you] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 10: barfoothefoobarman / [you] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 11: barfoothefoobarman / [foo, foo] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 12: wordgoodgoodgoodbestword / [word, good, best, word] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 13: wordgoodgoodgoodbestword / [word] ===
  Expected: [0, 20]
  Got     : [0, 20]
  Result  : OK

=== Test 14: wordgoodgoodgoodbestword / [good, good] ===
  Expected: [4, 8]
  Got     : [4, 8]
  Result  : OK

=== Test 15: wordgoodgoodgoodbestword / [good, good, good] ===
  Expected: [4]
  Got     : [4]
  Result  : OK

=== Test 16: wordgoodgoodgoodbestword / [good, word, good, good] ===
  Expected: [0]
  Got     : [0]
  Result  : OK

=== Test 17: wordgoodgoodgoodbestword / [best, good, good, good] ===
  Expected: [4]
  Got     : [4]
  Result  : OK

=== Test 18: wordgoodgoodgoodbestword / [good] ===
  Expected: [4, 8, 12]
  Got     : [4, 8, 12]
  Result  : OK

=== Test 19: wordgoodgoodgoodbestword / [test] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 20: wordgoodgoodgoodbestword / [good, test] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 21: ling...cake / [fooo, barr, wing, ding, wing] ===
  Expected: [13]
  Got     : [13]
  Result  : OK

=== Test 22: ling...cake / [ling, barr, wing, ding, wing] ===
  Expected: []
  Got     : []
  Result  : OK

=== Test 23: empty string / [test] ===
  Expected: []
  Got     : []
  Result  : OK

SUMMARY: 22/23 tests OK
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/substring#
```
