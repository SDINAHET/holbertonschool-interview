# avl_trees

## Task0

```bashgcc -Wall -Wextra -Werror -pedantic \
binary_tree_node.c binary_tree_print.c \
0-binary_tree_is_avl.c 0-main.c -o 0-is_avl

./0-is_avl

```

```bash
gcc -Wall -Wextra -Werror -pedantic -no-pie \
  binary_tree_print.c \
  0-binary_tree_is_avl.c \
  0-main.c \
  -I . -L . -lavl \
  -o 0-is_avl
```

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# gcc -Wall -Wextra -Werror -pedantic -no-pie \
  binary_tree_print.c \
  0-binary_tree_is_avl.c \
  0-main.c \
  -I . -L . -lavl \
  -o 0-is_avl
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# ./0-is_avl
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)--.
                              (430)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)-------.
                                .--(430)
                              (420)
Is 98 avl: 0
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees#
```


```bash
# désactive PIE au link
gcc -Wall -Wextra -Werror -pedantic -no-pie \
  binary_tree_print.c \
  0-binary_tree_is_avl.c \
  0-main.c \
  -I . -L . -lavl \
  -o 0-is_avl
```

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# gcc -Wall -Wextra -Werror -pedantic -no-pie \
  binary_tree_print.c \
  0-binary_tree_is_avl.c \
  0-main.c \
  -I . -L . -lavl \
  -o 0-is_avl
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# ./0-is_avl
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)
Is 98 avl: 1
Is 12 avl: 1
       .-------(098)-------.
  .--(012)--.         .--(128)--.
(010)     (054)     (097)     (402)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)--.
                              (430)
Is 98 avl: 0
       .-------(098)--.
  .--(012)--.       (128)--.
(010)     (054)          (402)-------.
                                .--(430)
                              (420)
Is 98 avl: 0
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees#
```

https://github.com/hs-hq/0x1C.c
