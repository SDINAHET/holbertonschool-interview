# double_circular_linked_list

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list# gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
0-add_node.c:2: error: ISO C forbids an empty translation unit [-Werror=pedantic]
cc1: all warnings being treated as errors
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list# gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-add_node.c
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list# ./a.out
Added to the end:
Holberton
        ->prev: Engineer
        ->next: School
School
        ->prev: Holberton
        ->next: Full
Full
        ->prev: School
        ->next: Stack
Stack
        ->prev: Full
        ->next: Engineer
Engineer
        ->prev: Stack
        ->next: Holberton
Added to the beginning:
Engineer
        ->prev: Holberton
        ->next: Stack
Stack
        ->prev: Engineer
        ->next: Full
Full
        ->prev: Stack
        ->next: School
School
        ->prev: Full
        ->next: Holberton
Holberton
        ->prev: School
        ->next: Engineer
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list# git add .
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list# git commit -m 'task0'
[main 091d1ac] task0
 2 files changed, 95 insertions(+)
 create mode 100644 double_circular_linked_list/a.out
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list# git push
Enumerating objects: 8, done.
Counting objects: 100% (8/8), done.
Delta compression using up to 8 threads
Compressing objects: 100% (5/5), done.
Writing objects: 100% (5/5), 3.89 KiB | 306.00 KiB/s, done.
Total 5 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/SDINAHET/holbertonschool-interview.git
   31e70e6..091d1ac  main -> main
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list#


root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list# gcc -Wall -Wextra -Werror -pedantic -D_POSIX_C_SOURCE=200809L \
    tests/test_add_nodes.c 0-add_node.c -o tests/test_runner
./tests/test_runner
Running tests for double circular linked list...
[ OK ] add_node_end basic
[ OK ] add_node_begin basic
[ OK ] singleton cases
=> All tests passed ✅
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview
/double_circular_linked_list#



```
