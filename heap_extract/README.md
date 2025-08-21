# heap_extract

# heap_extract

Extract the root of a **Max Binary Heap**.

## Requirements
- Ubuntu 14.04 LTS
- gcc 4.8.4 with `-Wall -Werror -Wextra -pedantic`
- Betty style
- No global variables
- ≤ 5 functions per file
- Prototypes in `binary_trees.h`
- Header include guards
- All files end with a new line

## Files
- `binary_trees.h` — types & prototype
- `0-heap_extract.c` — implementation of `int heap_extract(heap_t **root)`
- *(Optional for local tests)* `0-main.c`, `binary_tree_print.c`, `Makefile`

## Build & Run (local)
```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
./0-heap_extract
```



```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract# gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap
/usr/bin/ld: cannot find -lheap: No such file or directory
collect2: error: ld returned 1 exit status
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract# gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract \
  0-main.c 0-heap_extract.c binary_tree_print.c helpers_for_local_test.c
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract# ./0-heap_extract
                      .-----------------(098)-----------------.



            .-------(095)-------.                   .-------(091)-------.



       .--(087)--.         .--(084)--.         .--(079)--.         .--(062)--.


  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


(032)































































Extracted: 98
                 .-----------------(095)-----------------.



       .-------(087)-------.                   .-------(091)-------.



  .--(047)--.         .--(084)--.         .--(079)--.         .--(062)--.



(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


































































Extracted: 95
                 .-----------------(091)-----------------.



       .-------(087)-------.                   .-------(079)-------.



  .--(047)--.         .--(084)--.         .--(068)--.         .--(062)



(032)     (034)     (002)     (020)     (022)     (021)     (001)



































































Extracted: 91
                 .-----------------(087)-----------------.



       .-------(084)-------.                   .-------(079)--.



  .--(047)--.         .--(020)--.         .--(068)--.       (062)



(032)     (034)     (002)     (001)     (022)     (021)



































































root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract#
```




```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract# make
make: Nothing to be done for 'all'.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract# make
gcc -Wall -Wextra -Werror -pedantic -c 0-main.c -o 0-main.o
gcc -Wall -Wextra -Werror -pedantic -c 0-heap_extract.c -o 0-heap_extract.o
gcc -Wall -Wextra -Werror -pedantic -c binary_tree_print.c -o binary_tree_print.o
gcc -Wall -Wextra -Werror -pedantic -c helpers_for_local_test.c -o helpers_for_local_test.o
gcc -Wall -Wextra -Werror -pedantic -o 0-heap_extract 0-main.o 0-heap_extract.o binary_tree_print.o helpers_for_local_test.o
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract# ./0-heap_extract
                      .-----------------(098)-----------------.



            .-------(095)-------.                   .-------(091)-------.



       .--(087)--.         .--(084)--.         .--(079)--.         .--(062)--.


  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


(032)































































Extracted: 98
                 .-----------------(095)-----------------.



       .-------(087)-------.                   .-------(091)-------.



  .--(047)--.         .--(084)--.         .--(079)--.         .--(062)--.



(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


































































Extracted: 95
                 .-----------------(091)-----------------.



       .-------(087)-------.                   .-------(079)-------.



  .--(047)--.         .--(084)--.         .--(068)--.         .--(062)



(032)     (034)     (002)     (020)     (022)     (021)     (001)



































































Extracted: 91
                 .-----------------(087)-----------------.



       .-------(084)-------.                   .-------(079)--.



  .--(047)--.         .--(020)--.         .--(068)--.       (062)



(032)     (034)     (002)     (001)     (022)     (021)



































































root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract# make run
make valgrind
./0-heap_extract
                      .-----------------(098)-----------------.



            .-------(095)-------.                   .-------(091)-------.



       .--(087)--.         .--(084)--.         .--(079)--.         .--(062)--.


  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


(032)































































Extracted: 98
                 .-----------------(095)-----------------.



       .-------(087)-------.                   .-------(091)-------.



  .--(047)--.         .--(084)--.         .--(079)--.         .--(062)--.



(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


































































Extracted: 95
                 .-----------------(091)-----------------.



       .-------(087)-------.                   .-------(079)-------.



  .--(047)--.         .--(084)--.         .--(068)--.         .--(062)



(032)     (034)     (002)     (020)     (022)     (021)     (001)



































































Extracted: 91
                 .-----------------(087)-----------------.



       .-------(084)-------.                   .-------(079)--.



  .--(047)--.         .--(020)--.         .--(068)--.       (062)



(032)     (034)     (002)     (001)     (022)     (021)



































































valgrind ./0-heap_extract
==2228== Memcheck, a memory error detector
==2228== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2228== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==2228== Command: ./0-heap_extract
==2228==
                      .-----------------(098)-----------------.



            .-------(095)-------.                   .-------(091)-------.



       .--(087)--.         .--(084)--.         .--(079)--.         .--(062)--.


  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


(032)































































Extracted: 98
                 .-----------------(095)-----------------.



       .-------(087)-------.                   .-------(091)-------.



  .--(047)--.         .--(084)--.         .--(079)--.         .--(062)--.



(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)


































































Extracted: 95
                 .-----------------(091)-----------------.



       .-------(087)-------.                   .-------(079)-------.



  .--(047)--.         .--(084)--.         .--(068)--.         .--(062)



(032)     (034)     (002)     (020)     (022)     (021)     (001)



































































Extracted: 91
                 .-----------------(087)-----------------.



       .-------(084)-------.                   .-------(079)--.



  .--(047)--.         .--(020)--.         .--(068)--.       (062)



(032)     (034)     (002)     (001)     (022)     (021)



































































==2228==
==2228== HEAP SUMMARY:
==2228==     in use at exit: 0 bytes in 0 blocks
==2228==   total heap usage: 18 allocs, 18 frees, 1,672 bytes allocated
==2228==
==2228== All heap blocks were freed -- no leaks are possible
==2228==
==2228== For lists of detected and suppressed errors, rerun with: -s
==2228== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-
interview/heap_extract#
```
