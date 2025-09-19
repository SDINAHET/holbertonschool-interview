# Merge_sort


```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview# cd merge_sort/
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/merge_sort# gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
0-main.c:3:10: fatal error: sort.h: No such file or directory
    3 | #include "sort.h"
      |          ^~~~~~~~
compilation terminated.
0-merge_sort.c:3:10: fatal error: sort.h: No such file or directory
    3 | #include "sort.h"
      |          ^~~~~~~~
compilation terminated.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/merge_sort# gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/merge_sort# ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
Merging...
[left]: 19, 48
[right]: 13, 71, 99
[Done]: 13, 19, 48, 71, 99
Merging...
[left]: 52
[right]: 96
[Done]: 52, 96
Merging...
[left]: 86
[right]: 7
[Done]: 7, 86
Merging...
[left]: 73
[right]: 7, 86
[Done]: 7, 73, 86
Merging...
[left]: 52, 96
[right]: 7, 73, 86
[Done]: 7, 52, 73, 86, 96
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/merge_sort#
```
