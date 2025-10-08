# radix_sort


```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
cc1: fatal error: print_array.c: No such file or directory
compilation terminated.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# ^C
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# make
make: Warning: File 'Makefile' has modification time 1.2 s in the future
make: Nothing to be done for 'all'.
make: warning:  Clock skew detected.  Your build may be incomplete.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# remake
Command 'remake' not found, but can be installed with:
apt install remake
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# make -B
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort#

root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# make valgrind
valgrind --leak-check=full --show-leak-kinds=all -s ./radix
==10961== Memcheck, a memory error detector
==10961== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10961== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10961== Command: ./radix
==10961==
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
==10961==
==10961== HEAP SUMMARY:
==10961==     in use at exit: 0 bytes in 0 blocks
==10961==   total heap usage: 2 allocs, 2 frees, 1,064 bytes allocated
==10961==
==10961== All heap blocks were freed -- no leaks are possible
==10961==
==10961== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort#
```

```bash
make          # compile
make run      # lance ./radix
make clean    # supprime le binaire
```

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radix_sort# gcc -std=c89 -Wall -Wextra -Werror -pedantic -g \
    tests/tests_radix.c 0-radix_sort.c print_array.c \
    -I . -o tests_radix
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort# ./tests_radix
71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
[sample-from-subject] PASS
71, 52, 13, 73, 86, 96, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
[already-sorted] PASS
71, 52, 73, 13, 96, 86, 7, 48, 99, 19
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
[reverse] PASS
0, 0, 1, 1, 3, 3, 5, 5, 5, 9, 9
[duplicates] PASS
0, 0, 10, 100, 30, 300, 1, 2, 3
0, 0, 100, 300, 1, 2, 3, 10, 30
0, 0, 1, 2, 3, 10, 30, 100, 300
[zeros-and-small] PASS
1000000, 10, 100, 0, 50000, 1, 999
1000000, 100, 0, 50000, 1, 10, 999
1000000, 0, 50000, 1, 10, 100, 999
1000000, 0, 50000, 1, 10, 100, 999
1000000, 0, 1, 10, 100, 999, 50000
1000000, 0, 1, 10, 100, 999, 50000
0, 1, 10, 100, 999, 50000, 1000000
[wide-range] PASS
[single-element] PASS
[empty] PASS

Summary: 8/8 tests passed
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/radi
x_sort#
```
