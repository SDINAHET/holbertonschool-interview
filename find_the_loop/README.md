# find_the_loop

![Find the Loop CI](https://github.com/SDINAHET/holbertonschool-interview/actions/workflows/find_the_loop.yml/badge.svg)


```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop# gcc -Wall -Werror -Wextra -pedantic 0-find_loop.c test_find_loop.c -o tests
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop# gcc -Wall -Werror -Wextra -pedantic 0-find_loop.c test_find_loop.c lib.c -o tests2
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop# ./tests
Running unit tests for find_listint_loop...
All tests passed ✅
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop# ./tests2
Running unit tests for find_listint_loop...
All tests passed ✅
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop#


root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop# gcc -Wall -Werror -Wextra -pedantic 0-find_loop.c lib.c test_checker_like.c -o tests_checker
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop# ./tests_check
er
Running checker-like tests...
OK - two nodes loop to first
OK - single node self-loop
OK - 150 nodes, tail->121st
OK - 150 nodes, no loop
OK - NULL input
OK - 150 nodes, no loop (bis)
All checker-like tests passed ✅
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop#


root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop# ./main
[0x5579a5e51380] 1024
[0x5579a5e51360] 402
[0x5579a5e51340] 98
[0x5579a5e51320] 4
[0x5579a5e51300] 3
[0x5579a5e512e0] 2
[0x5579a5e512c0] 1
[0x5579a5e512a0] 0
[0x5579a5e51300] 1024
[0x5579a5e512e0] 402
[0x5579a5e512c0] 98
[0x5579a5e517d0] 7
[0x5579a5e51890] 6
[0x5579a5e51870] 5
[0x5579a5e51850] 4
[0x5579a5e51830] 3
[0x5579a5e51810] 2
[0x5579a5e517f0] 1
[0x5579a5e512a0] 0
-> [0x5579a5e517d0] 7
Loop starts at [0x5579a5e517d0] 7
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/find_the_loop#
```

