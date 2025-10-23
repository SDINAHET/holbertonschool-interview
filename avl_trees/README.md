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


## test

```bash
echec
sudo apt update && sudo apt install -y criterion-dev
make test


echec
sudo add-apt-repository -y universe
sudo apt update
sudo apt install -y criterion-dev
make test


sudo apt update
sudo apt install -y git cmake ninja-build pkg-config libffi-dev build-essential
git clone --depth=1 https://github.com/Snaipe/Criterion.git
cd Criterion
# tu es déjà dans le repo Criterion
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build
sudo cmake --install build
sudo ldconfig   # met à jour le cache des libs
apt install m# 3) build & install (Meson)
meson setup build --buildtype=release
meson compile -C build
sudo meson install -C build
sudo ldconfig   # maj du cache des libs
# 4) vérifier que c'est en place
test -f /usr/local/include/criterion/criterion.h && echo "criterion headers OK"
test -f /usr/local/lib/libcriterion.so && echo "criterion lib OK" # maj du cache des libs
```


























```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make test
gcc -Wall -Wextra -Werror -pedantic -I . -c binary_tree_node.c -o binary_tree_node.o
gcc -Wall -Wextra -Werror -pedantic -I . -c 0-binary_tree_is_avl.c -o 0-binary_tree_is_avl.o
gcc -Wall -Wextra -Werror -pedantic -I . -I .    -c tests/test_is_avl.c -o tests/test_is_avl.o
tests/test_is_avl.c:1:10: fatal error: criterion/criterion.h: No such file or directory
    1 | #include <criterion/criterion.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make: *** [Makefile:35: tests/test_is_avl.o] Error 1
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo apt update && sudo apt install -y criterion-dev
Get:1 http://security.ubuntu.com/ubuntu jammy-security InRelease [129 kB]
Get:2 http://security.ubuntu.com/ubuntu xenial-security InRelease [106 kB]
Hit:3 https://deb.nodesource.com/node_20.x nodistro InRelease
Get:4 http://security.ubuntu.com/ubuntu jammy-security/main amd64 Packages [2771 kB]
Hit:5 https://ppa.launchpadcontent.net/openjdk-r/ppa/ubuntu jammy InRelease
Hit:6 http://archive.ubuntu.com/ubuntu jammy InRelease
Get:7 http://archive.ubuntu.com/ubuntu jammy-updates InRelease [128 kB]
Get:8 http://security.ubuntu.com/ubuntu jammy-security/main Translation-en [403 kB]
Get:9 https://dl.google.com/linux/chrome/deb stable InRelease [1825 B]
Get:10 http://archive.ubuntu.com/ubuntu jammy-backports InRelease [127 kB]
Ign:11 https://packages.adoptium.net/artifactory/deb stable InRelease
Get:12 https://dl.google.com/linux/chrome/deb stable/main amd64 Packages [1214 B]
Hit:13 https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 InRelease
Get:14 http://archive.ubuntu.com/ubuntu jammy-updates/main amd64 Packages [3027 kB]
Hit:15 https://repo.mongodb.org/apt/ubuntu jammy/mongodb-org/8.0 InRelease
Err:16 https://packages.adoptium.net/artifactory/deb stable Release
  404  Not Found [IP: 8.47.69.8 443]
Get:17 http://archive.ubuntu.com/ubuntu jammy-updates/main Translation-en [469 kB]
Get:18 http://archive.ubuntu.com/ubuntu jammy-updates/universe amd64 Packages [1242 kB]
Reading package lists... Done
W: http://security.ubuntu.com/ubuntu/dists/xenial-security/InRelease: Key is stored in legacy trusted.gpg keyring (/etc/apt/trusted.gpg), see the DEPRECATION section in apt-key(8) for details.
E: The repository 'https://packages.adoptium.net/artifactory/deb stable Release' does not have a Release file.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make test
gcc -Wall -Wextra -Werror -pedantic -I . -I .    -c tests/test_is_avl.c -o tests/test_is_avl.o
tests/test_is_avl.c:1:10: fatal error: criterion/criterion.h: No such file or directory
    1 | #include <criterion/criterion.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make: *** [Makefile:35: tests/test_is_avl.o] Error 1
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo apt update
Hit:1 http://archive.ubuntu.com/ubuntu jammy InRelease
Hit:2 http://security.ubuntu.com/ubuntu jammy-security InRelease
Hit:3 https://dl.google.com/linux/chrome/deb stable InRelease
Hit:4 https://deb.nodesource.com/node_20.x nodistro InRelease
Hit:5 http://archive.ubuntu.com/ubuntu jammy-updates InRelease
Hit:6 http://security.ubuntu.com/ubuntu xenial-security InRelease
Hit:7 http://archive.ubuntu.com/ubuntu jammy-backports InRelease
Hit:8 https://ppa.launchpadcontent.net/openjdk-r/ppa/ubuntu jammy InRelease
Hit:9 https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 InRelease
Hit:10 https://repo.mongodb.org/apt/ubuntu jammy/mongodb-org/8.0 InRelease
Ign:11 https://packages.adoptium.net/artifactory/deb stable InRelease
Err:12 https://packages.adoptium.net/artifactory/deb stable Release
  404  Not Found [IP: 8.6.112.8 443]
Reading package lists... Done
W: http://security.ubuntu.com/ubuntu/dists/xenial-security/InRelease: Key is stored in legacy trusted.gpg keyring (/etc/apt/trusted.gpg), see the DEPRECATION section in apt-key(8) for details.
E: The repository 'https://packages.adoptium.net/artifactory/deb stable Release' does not have a Release file.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo apt install -y criterion-dev
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
E: Unable to locate package criterion-dev
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo rm -f /etc/apt/sources.list.d/adoptium*.list
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# grep -Rni 'xenial' /etc/apt/sources.list /etc/apt/sources.list.d/ || true
/etc/apt/sources.list:43:deb http://security.ubuntu.com/ubuntu xenial-security main
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo sed -i 's|^deb http://security.ubuntu.com/ubuntu xenial-security main|# &|' /etc/apt/sources.list
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# grep -Rni 'xenial' /etc/apt/sources.list /etc/apt/sources.list.d/ || true
/etc/apt/sources.list:43:# deb http://security.ubuntu.com/ubuntu xenial-security main
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo add-apt-repository -y universe
Adding component(s) 'universe' to all repositories.
Hit:1 https://ppa.launchpadcontent.net/openjdk-r/ppa/ubuntu jammy InRelease
Hit:2 http://archive.ubuntu.com/ubuntu jammy InRelease
Hit:3 https://dl.google.com/linux/chrome/deb stable InRelease
Hit:4 https://deb.nodesource.com/node_20.x nodistro InRelease
Hit:5 http://archive.ubuntu.com/ubuntu jammy-updates InRelease
Hit:6 http://security.ubuntu.com/ubuntu jammy-security InRelease
Hit:7 http://archive.ubuntu.com/ubuntu jammy-backports InRelease
Hit:8 https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 InRelease
Hit:9 https://repo.mongodb.org/apt/ubuntu jammy/mongodb-org/8.0 InRelease
Reading package lists... Done
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo apt update
Hit:1 http://security.ubuntu.com/ubuntu jammy-security InRelease
Hit:2 https://ppa.launchpadcontent.net/openjdk-r/ppa/ubuntu jammy InRelease
Hit:3 http://archive.ubuntu.com/ubuntu jammy InRelease
Hit:4 https://dl.google.com/linux/chrome/deb stable InRelease
Hit:5 http://archive.ubuntu.com/ubuntu jammy-updates InRelease
Hit:6 https://deb.nodesource.com/node_20.x nodistro InRelease
Hit:7 http://archive.ubuntu.com/ubuntu jammy-backports InRelease
Hit:8 https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 InRelease
Hit:9 https://repo.mongodb.org/apt/ubuntu jammy/mongodb-org/8.0 InRelease
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
78 packages can be upgraded. Run 'apt list --upgradable' to see them.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo apt install -y criterion-dev
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
E: Unable to locate package criterion-dev
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make test
gcc -Wall -Wextra -Werror -pedantic -I . -I .    -c tests/test_is_avl.c -o tests/test_is_avl.o
tests/test_is_avl.c:1:10: fatal error: criterion/criterion.h: No such file or directory
    1 | #include <criterion/criterion.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make: *** [Makefile:35: tests/test_is_avl.o] Error 1
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# sudo apt update
sudo apt install -y git cmake ninja-build pkg-config libffi-dev build-essential
Hit:1 http://archive.ubuntu.com/ubuntu jammy InRelease
Hit:2 https://deb.nodesource.com/node_20.x nodistro InRelease
Hit:3 https://dl.google.com/linux/chrome/deb stable InRelease
Hit:4 http://archive.ubuntu.com/ubuntu jammy-updates InRelease
Hit:5 http://archive.ubuntu.com/ubuntu jammy-backports InRelease
Hit:6 http://security.ubuntu.com/ubuntu jammy-security InRelease
Hit:7 https://ppa.launchpadcontent.net/openjdk-r/ppa/ubuntu jammy InRelease
Hit:8 https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 InRelease
Hit:9 https://repo.mongodb.org/apt/ubuntu jammy/mongodb-org/8.0 InRelease
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
78 packages can be upgraded. Run 'apt list --upgradable' to see them.
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
build-essential is already the newest version (12.9ubuntu3).
build-essential set to manually installed.
libffi-dev is already the newest version (3.4.2-4).
libffi-dev set to manually installed.
pkg-config is already the newest version (0.29.2-1ubuntu3).
git is already the newest version (1:2.34.1-1ubuntu1.15).
The following packages were automatically installed and are no longer required:
  libdvdnav4 libdvdread8 libmujs1 libplacebo192 libsixel1 libva-wayland2 mpv python3-brotli python3-mutagen
  python3-pycryptodome python3-pyxattr python3-websockets rtmpdump
Use 'sudo apt autoremove' to remove them.
Suggested packages:
  cmake-doc cmake-format
The following NEW packages will be installed:
  cmake cmake-data dh-elpa-helper libjsoncpp25 librhash0 ninja-build
0 upgraded, 6 newly installed, 0 to remove and 78 not upgraded.
1 not fully installed or removed.
Need to get 7246 kB of archives.
After this operation, 32.2 MB of additional disk space will be used.
Get:1 http://archive.ubuntu.com/ubuntu jammy/main amd64 libjsoncpp25 amd64 1.9.5-3 [80.0 kB]
Get:2 http://archive.ubuntu.com/ubuntu jammy/main amd64 librhash0 amd64 1.4.2-1ubuntu1 [125 kB]
Get:3 http://archive.ubuntu.com/ubuntu jammy/main amd64 dh-elpa-helper all 2.0.9ubuntu1 [7610 B]
Get:4 http://archive.ubuntu.com/ubuntu jammy-updates/main amd64 cmake-data all 3.22.1-1ubuntu1.22.04.2 [1913 kB]
Get:5 http://archive.ubuntu.com/ubuntu jammy-updates/main amd64 cmake amd64 3.22.1-1ubuntu1.22.04.2 [5010 kB]
Get:6 http://archive.ubuntu.com/ubuntu jammy/universe amd64 ninja-build amd64 1.10.1-1 [111 kB]
Fetched 7246 kB in 3s (2619 kB/s)
Selecting previously unselected package libjsoncpp25:amd64.
(Reading database ... 114739 files and directories currently installed.)
Preparing to unpack .../0-libjsoncpp25_1.9.5-3_amd64.deb ...
Unpacking libjsoncpp25:amd64 (1.9.5-3) ...
Selecting previously unselected package librhash0:amd64.
Preparing to unpack .../1-librhash0_1.4.2-1ubuntu1_amd64.deb ...
Unpacking librhash0:amd64 (1.4.2-1ubuntu1) ...
Selecting previously unselected package dh-elpa-helper.
Preparing to unpack .../2-dh-elpa-helper_2.0.9ubuntu1_all.deb ...
Unpacking dh-elpa-helper (2.0.9ubuntu1) ...
Selecting previously unselected package cmake-data.
Preparing to unpack .../3-cmake-data_3.22.1-1ubuntu1.22.04.2_all.deb ...
Unpacking cmake-data (3.22.1-1ubuntu1.22.04.2) ...
Selecting previously unselected package cmake.
Preparing to unpack .../4-cmake_3.22.1-1ubuntu1.22.04.2_amd64.deb ...
Unpacking cmake (3.22.1-1ubuntu1.22.04.2) ...
Selecting previously unselected package ninja-build.
Preparing to unpack .../5-ninja-build_1.10.1-1_amd64.deb ...
Unpacking ninja-build (1.10.1-1) ...
Setting up ninja-build (1.10.1-1) ...
Setting up dh-elpa-helper (2.0.9ubuntu1) ...
Setting up libjsoncpp25:amd64 (1.9.5-3) ...
Setting up postfix (3.6.4-1ubuntu1.3) ...

Postfix (main.cf) configuration was not changed.  If you need to make changes,
edit /etc/postfix/main.cf (and others) as needed.  To view Postfix
configuration values, see postconf(1).

After modifying main.cf, be sure to run 'systemctl reload postfix'.

Running newaliases
newaliases: fatal: bad string length 0 < 1: mydomain =
dpkg: error processing package postfix (--configure):
 installed postfix package post-installation script subprocess returned error exit status 75
Setting up librhash0:amd64 (1.4.2-1ubuntu1) ...
Setting up cmake-data (3.22.1-1ubuntu1.22.04.2) ...
Install emacsen-common for emacs
emacsen-common: Handling install of emacsen flavor emacs
Install cmake-data for emacs
install/cmake-mode-3.22.1: Handling install of emacsen flavor emacs
install/cmake-mode-3.22.1: byte-compiling for emacs
Setting up cmake (3.22.1-1ubuntu1.22.04.2) ...
Processing triggers for man-db (2.10.2-1) ...
Processing triggers for libc-bin (2.35-0ubuntu3.11) ...
Errors were encountered while processing:
 postfix
E: Sub-process /usr/bin/dpkg returned an error code (1)
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# git clone --depth=1 https://github.com/Snaipe/Criterion.git
cd Criterion
Cloning into 'Criterion'...
remote: Enumerating objects: 325, done.
remote: Counting objects: 100% (325/325), done.
remote: Compressing objects: 100% (293/293), done.
remote: Total 325 (delta 82), reused 129 (delta 16), pack-reused 0 (from 0)
Receiving objects: 100% (325/325), 932.59 KiB | 2.63 MiB/s, done.
Resolving deltas: 100% (82/82), done.
Updating files: 100% (290/290), done.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion# # tu es déjà dans le repo Criterion
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build
sudo cmake --install build
sudo ldconfig   # met à jour le cache des libs
CMake Error: The source directory "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion" does not appear to contain CMakeLists.txt.
Specify --help for usage, or press the help button on the CMake GUI.
Error: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build is not a directory
CMake Error: Error processing file: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/cmake_install.cmake
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion# test -f /usr/local/include/criterion/criterion.h && echo "criterion headers OK"
test -f /usr/local/lib/libcriterion.so && echo "criterion lib OK"
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion# cd ..
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make test
gcc -Wall -Wextra -Werror -pedantic -I . -I .    -c tests/test_is_avl.c -o tests/test_is_avl.o
tests/test_is_avl.c:1:10: fatal error: criterion/criterion.h: No such file or directory
    1 | #include <criterion/criterion.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make: *** [Makefile:35: tests/test_is_avl.o] Error 1
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# meson setup build --buildtype=release
meson compile -C build
sudo meson install -C build
sudo ldconfig
Command 'meson' not found, but can be installed with:
apt install meson
Command 'meson' not found, but can be installed with:
apt install meson
sudo: meson: command not found
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# cd Criterion/
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion# meson setup build --buildtype=release
meson compile -C build
sudo meson install -C build
sudo ldconfig
Command 'meson' not found, but can be installed with:
apt install meson
Command 'meson' not found, but can be installed with:
apt install meson
sudo: meson: command not found
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion# apt install meson
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
The following packages were automatically installed and are no longer required:
  libdvdnav4 libdvdread8 libmujs1 libplacebo192 libsixel1 libva-wayland2 mpv python3-brotli python3-mutagen
  python3-pycryptodome python3-pyxattr python3-websockets rtmpdump
Use 'apt autoremove' to remove them.
The following NEW packages will be installed:
  meson
0 upgraded, 1 newly installed, 0 to remove and 78 not upgraded.
1 not fully installed or removed.
Need to get 519 kB of archives.
After this operation, 3333 kB of additional disk space will be used.
Get:1 http://archive.ubuntu.com/ubuntu jammy/universe amd64 meson all 0.61.2-1 [519 kB]
Fetched 519 kB in 1s (553 kB/s)
Selecting previously unselected package meson.
(Reading database ... 117836 files and directories currently installed.)
Preparing to unpack .../meson_0.61.2-1_all.deb ...
Unpacking meson (0.61.2-1) ...
Setting up meson (0.61.2-1) ...
Setting up postfix (3.6.4-1ubuntu1.3) ...

Postfix (main.cf) configuration was not changed.  If you need to make changes,
edit /etc/postfix/main.cf (and others) as needed.  To view Postfix
configuration values, see postconf(1).

After modifying main.cf, be sure to run 'systemctl reload postfix'.

Running newaliases
newaliases: fatal: bad string length 0 < 1: mydomain =
dpkg: error processing package postfix (--configure):
 installed postfix package post-installation script subprocess returned error exit status 75
Processing triggers for man-db (2.10.2-1) ...
Errors were encountered while processing:
 postfix
E: Sub-process /usr/bin/dpkg returned an error code (1)
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion# meson setup build --buildtype=release
meson compile -C build
sudo meson install -C build
sudo ldconfig
The Meson build system
Version: 0.61.2
Source dir: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion
Build dir: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build
Build type: native build
Project name: criterion
Project version: 2.4.3
C compiler for the host machine: cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
C linker for the host machine: cc ld.bfd 2.38
Host machine cpu family: x86_64
Host machine cpu: x86_64
Program git found: YES (/usr/bin/git)
C++ compiler for the host machine: c++ (gcc 11.4.0 "c++ (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
C++ linker for the host machine: c++ ld.bfd 2.38
Compiler for C supports arguments -Wno-unused-parameter: YES
Compiler for C supports arguments -Wno-unused-value: YES
Compiler for C supports arguments -fvisibility=hidden: YES
Compiler for C supports arguments -fexceptions: YES
Compiler for C supports arguments /SAFESEH:NO: NO
Compiler for C supports arguments /source-charset:utf-8: NO
Checking for function "clock_gettime" : YES
Checking for function "fopencookie" : YES
Checking for function "funopen" : NO
Checking for function "getcwd" : YES
Checking for function "isatty" : YES
Checking for function "nl_langinfo" : YES
Checking for function "open_memstream" : YES
Checking for function "strtok_r" : YES
Checking for function "strtok_s" : NO
Header <time.h> has symbol "CLOCK_MONOTONIC_RAW" : YES
Checking for function "GetCurrentDirectory" : NO
Checking for function "PathIsRelative" : NO
Has header "synchapi.h" : NO
Program gettext found: YES (/usr/bin/gettext)
WARNING: Gettext not found, all translation targets will be ignored.
Found pkg-config: /usr/bin/pkg-config (0.29.2)
Found CMake: /usr/bin/cmake (3.22.1)
Run-time dependency debugbreak found: NO (tried pkgconfig and cmake)
Looking for a fallback subproject for the dependency debugbreak
Cloning into 'debugbreak'...
remote: Enumerating objects: 190, done.
remote: Counting objects: 100% (20/20), done.
remote: Compressing objects: 100% (15/15), done.
remote: Total 190 (delta 10), reused 11 (delta 5), pack-reused 170 (from 1)
Receiving objects: 100% (190/190), 45.85 KiB | 2.29 MiB/s, done.
Resolving deltas: 100% (103/103), done.
HEAD is now at 83bf7e9 Use __builtin_debugtrap wherever available

Executing subproject debugbreak

debugbreak| Project name: debugbreak
debugbreak| Project version: undefined
debugbreak| C compiler for the host machine: cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
debugbreak| C linker for the host machine: cc ld.bfd 2.38
debugbreak| Build targets in project: 0
debugbreak| Subproject debugbreak finished.

Dependency debugbreak from subproject subprojects/debugbreak found: YES undefined
Run-time dependency klib found: NO (tried pkgconfig and cmake)
Looking for a fallback subproject for the dependency klib
Cloning into 'klib'...
remote: Enumerating objects: 1414, done.
remote: Counting objects: 100% (54/54), done.
remote: Compressing objects: 100% (33/33), done.
remote: Total 1414 (delta 29), reused 21 (delta 21), pack-reused 1360 (from 2)
Receiving objects: 100% (1414/1414), 1.25 MiB | 3.49 MiB/s, done.
Resolving deltas: 100% (808/808), done.
HEAD is now at cdb7e92 Merge pull request #62 from innoink/master

Executing subproject klib

klib| Project name: klib
klib| Project version: undefined
klib| C compiler for the host machine: cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
klib| C linker for the host machine: cc ld.bfd 2.38
klib| Build targets in project: 0
klib| Subproject klib finished.

Dependency klib from subproject subprojects/klib found: YES undefined
Run-time dependency threads found: YES
Run-time dependency nanomsg found: NO (tried pkgconfig and cmake)
Cloning into 'nanomsg'...
remote: Enumerating objects: 399, done.
remote: Counting objects: 100% (399/399), done.
remote: Compressing objects: 100% (358/358), done.
remote: Total 399 (delta 187), reused 124 (delta 39), pack-reused 0 (from 0)
Receiving objects: 100% (399/399), 451.74 KiB | 2.40 MiB/s, done.
Resolving deltas: 100% (187/187), done.
Note: switching to 'ccd7f20c1b756f7041598383baffcdc326246db7'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

Updating files: 100% (369/369), done.

Executing subproject nanomsg-cmake method cmake

nanomsg-cmake| Found CMake: /usr/bin/cmake (3.22.1)

| Configuring the build directory with CMake version 3.22.1
| Running CMake with: -G Ninja -DCMAKE_INSTALL_PREFIX=/usr/local -DNN_TESTS=False -DNN_TOOLS=False -DNN_STATIC_LIB=True -DBUILD_SHARED_LIBS=False -DCMAKE_POSITION_INDEPENDENT_CODE=True -DCMAKE_POLICY_VERSION_MINIMUM=3.5
|   - build directory:          /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanomsg/__CMake_build
|   - source directory:         /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/subprojects/nanomsg
|   - toolchain file:           /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanomsg/__CMake_build/CMakeMesonToolchainFile.cmake
|   - preload file:             /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/meson-private/data/preload.cmake
|   - trace args:               --trace-expand --trace-format=json-v1 --no-warn-unused-cli --trace-redirect=cmake_trace.txt
|   - disabled policy warnings: [CMP0025, CMP0047, CMP0056, CMP0060, CMP0065, CMP0066, CMP0067, CMP0082, CMP0089, CMP0102]

| Running with expanded trace output on.
| Not searching for unused variables given on the command line.
| Trace will be written to cmake_trace.txt
| -- The C compiler identification is GNU 11.4.0
| -- Detecting C compiler ABI info
| -- Detecting C compiler ABI info - done
| -- Check for working C compiler: /usr/bin/cc - skipped
| -- Detecting C compile features
| -- Detecting C compile features - done
| -- Detected nanomsg ABI v6 (v6.0.1)
| -- Looking for pthread.h
| -- Looking for pthread.h - found
| -- Performing Test CMAKE_HAVE_LIBC_PTHREAD
| -- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
| -- Found Threads: TRUE
| -- OS System is Linux
| -- OS Version is 5.15.167.4-microsoft-standard-WSL2
| -- Looking for gethrtime
| -- Looking for gethrtime - not found
| -- Looking for socketpair
| -- Looking for socketpair - found
| -- Looking for eventfd
| -- Looking for eventfd - found
| -- Looking for pipe
| -- Looking for pipe - found
| -- Looking for pipe2
| -- Looking for pipe2 - found
| -- Looking for accept4
| -- Looking for accept4 - found
| -- Looking for epoll_create
| -- Looking for epoll_create - found
| -- Looking for kqueue
| -- Looking for kqueue - not found
| -- Looking for poll
| -- Looking for poll - found
| -- Looking for getaddrinfo_a in anl
| -- Looking for getaddrinfo_a in anl - found
| -- Looking for clock_gettime in rt
| -- Looking for clock_gettime in rt - found
| -- Looking for sem_wait in rt
| -- Looking for sem_wait in rt - found
| -- Looking for sem_wait in pthread
| -- Looking for sem_wait in pthread - found
| -- Looking for gethostbyname in nsl
| -- Looking for gethostbyname in nsl - found
| -- Looking for socket in socket
| -- Looking for socket in socket - not found
| -- Looking for CLOCK_MONOTONIC
| -- Looking for CLOCK_MONOTONIC - found
| -- Looking for atomic_cas_32
| -- Looking for atomic_cas_32 - not found
| -- Looking for AF_UNIX
| -- Looking for AF_UNIX - found
| -- Looking for backtrace_symbols_fd
| -- Looking for backtrace_symbols_fd - found
| -- Performing Test NN_HAVE_MSG_CONTROL
| -- Performing Test NN_HAVE_MSG_CONTROL - Success
| -- Performing Test NN_HAVE_GCC_ATOMIC_BUILTINS
| -- Performing Test NN_HAVE_GCC_ATOMIC_BUILTINS - Success
| CMake Warning at CMakeLists.txt:294 (message):
| Could not find asciidoctor: skipping docs


| -- Configuring done
| -- Generating done
| -- Build files have been written to: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanomsg/__CMake_build

nanomsg-cmake| CMake configuration: SUCCEEDED
nanomsg-cmake| CMake project nanomsg has 2 build targets.

cmake-ast| Processing generated meson AST
cmake-ast| Build file: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanomsg/meson.build

nanomsg-cmake| Project name: nanomsg
nanomsg-cmake| Project version: undefined
nanomsg-cmake| C compiler for the host machine: cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
nanomsg-cmake| C linker for the host machine: cc ld.bfd 2.38
nanomsg-cmake| Build targets in project: 2
nanomsg-cmake| Subproject nanomsg-cmake finished.


Library anl found: YES
Library ws2_32 found: NO
Library mswsock found: NO
Run-time dependency nanopb found: NO (tried cmake)
Cloning into 'nanopb'...
remote: Enumerating objects: 9688, done.
remote: Counting objects: 100% (3397/3397), done.
remote: Compressing objects: 100% (590/590), done.
remote: Total 9688 (delta 2980), reused 2812 (delta 2807), pack-reused 6291 (from 1)
Receiving objects: 100% (9688/9688), 4.28 MiB | 3.97 MiB/s, done.
Resolving deltas: 100% (6337/6337), done.
Updating files: 100% (647/647), done.
HEAD is now at cad3c18 Releasing 0.4.9.1 bugfix release

Executing subproject nanopb-cmake method cmake


| Configuring the build directory with CMake version 3.22.1
| Running CMake with: -G Ninja -DCMAKE_INSTALL_PREFIX=/usr/local -Dnanopb_BUILD_GENERATOR=False -DBUILD_SHARED_LIBS=False -DCMAKE_C_FLAGS=-DPB_ENABLE_MALLOC=1 -DPB_NO_PACKED_STRUCTS=1 -DCMAKE_POSITION_INDEPENDENT_CODE=True
|   - build directory:          /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanopb/__CMake_build
|   - source directory:         /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/subprojects/nanopb
|   - toolchain file:           /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanopb/__CMake_build/CMakeMesonToolchainFile.cmake
|   - preload file:             /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/meson-private/data/preload.cmake
|   - trace args:               --trace-expand --trace-format=json-v1 --no-warn-unused-cli --trace-redirect=cmake_trace.txt
|   - disabled policy warnings: [CMP0025, CMP0047, CMP0056, CMP0060, CMP0065, CMP0066, CMP0067, CMP0082, CMP0089, CMP0102]

| Running with expanded trace output on.
| Not searching for unused variables given on the command line.
| Trace will be written to cmake_trace.txt
| -- The C compiler identification is GNU 11.4.0
| -- Detecting C compiler ABI info
| -- Detecting C compiler ABI info - done
| -- Check for working C compiler: /usr/bin/cc - skipped
| -- Detecting C compile features
| -- Detecting C compile features - done
| -- Found Python: /usr/bin/python3.10 (found version "3.10.12") found components: Interpreter
| -- Python install dir: /usr/lib/python3/dist-packages
| -- Configuring done
| -- Generating done
| -- Build files have been written to: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanopb/__CMake_build

nanopb-cmake| CMake configuration: SUCCEEDED
nanopb-cmake| CMake project nanopb has 1 build targets.

cmake-ast| Processing generated meson AST
cmake-ast| Build file: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/nanopb/meson.build

nanopb-cmake| Project name: nanopb
nanopb-cmake| Project version: undefined
nanopb-cmake| C compiler for the host machine: cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
nanopb-cmake| C linker for the host machine: cc ld.bfd 2.38
nanopb-cmake| Build targets in project: 3
nanopb-cmake| Subproject nanopb-cmake finished.


Run-time dependency libgit2 found: NO (tried pkgconfig and cmake)
Cloning into 'libgit2'...
remote: Enumerating objects: 129408, done.
remote: Counting objects: 100% (129408/129408), done.
remote: Compressing objects: 100% (35354/35354), done.
remote: Total 129408 (delta 91951), reused 129397 (delta 91943), pack-reused 0 (from 0)
Receiving objects: 100% (129408/129408), 70.45 MiB | 4.96 MiB/s, done.
Resolving deltas: 100% (91951/91951), done.
Updating files: 100% (11940/11940), done.
warning: unable to unlink 'tests/util/process/win32.c': Permission denied
Updating files: 100% (10976/10976), done.
HEAD is now at 2fcb8705e Merge pull request #4076 from libgit2/cmn/sec-update-25

Executing subproject libgit2-cmake method cmake


| Configuring the build directory with CMake version 3.22.1
| Running CMake with: -G Ninja -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_SHARED_LIBS=False -DBUILD_CLAR=False -DUSE_ICONV=False -DUSE_SSH=False -DUSE_GSSAPI=False -DUSE_OPENSSL=False -DVALGRIND=False -DCURL=False -DWINHTTP=False -DCMAKE_DISABLE_FIND_PACKAGE_HTTP_Parser=True -DCMAKE_DISABLE_FIND_PACKAGE_ZLIB=True -DCMAKE_DISABLE_FIND_PACKAGE_Iconv=True -DCMAKE_DISABLE_FIND_PACKAGE_Security=True -DCMAKE_POSITION_INDEPENDENT_CODE=True -DCMAKE_POLICY_VERSION_MINIMUM=3.5
|   - build directory:          /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/libgit2/__CMake_build
|   - source directory:         /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/subprojects/libgit2
|   - toolchain file:           /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/libgit2/__CMake_build/CMakeMesonToolchainFile.cmake
|   - preload file:             /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/meson-private/data/preload.cmake
|   - trace args:               --trace-expand --trace-format=json-v1 --no-warn-unused-cli --trace-redirect=cmake_trace.txt
|   - disabled policy warnings: [CMP0025, CMP0047, CMP0056, CMP0060, CMP0065, CMP0066, CMP0067, CMP0082, CMP0089, CMP0102]

| Running with expanded trace output on.
| Not searching for unused variables given on the command line.
| Trace will be written to cmake_trace.txt
| -- The C compiler identification is GNU 11.4.0
| -- Detecting C compiler ABI info
| -- Detecting C compiler ABI info - done
| -- Check for working C compiler: /usr/bin/cc - skipped
| -- Detecting C compile features
| -- Detecting C compile features - done
| CMake Deprecation Warning at CMakeLists.txt:15 (CMAKE_MINIMUM_REQUIRED):
| Compatibility with CMake < 2.8.12 will be removed from a future version of
| CMake.

| Update the VERSION argument <min> value or use a ...<max> suffix to tell
| CMake that the project does not need compatibility with older versions.


| -- Found PkgConfig: /usr/bin/pkg-config (found version "0.29.2")
| -- Performing Test HAVE_STRUCT_STAT_ST_MTIM
| -- Performing Test HAVE_STRUCT_STAT_ST_MTIM - Success
| -- Performing Test HAVE_STRUCT_STAT_ST_MTIMESPEC
| -- Performing Test HAVE_STRUCT_STAT_ST_MTIMESPEC - Failed
| -- Performing Test HAVE_STRUCT_STAT_MTIME_NSEC
| -- Performing Test HAVE_STRUCT_STAT_MTIME_NSEC - Failed
| -- Performing Test HAVE_STRUCT_STAT_NSEC
| -- Performing Test HAVE_STRUCT_STAT_NSEC - Success
| -- http-parser was not found or is too old; using bundled 3rd-party sources.
| -- zlib was not found; using bundled 3rd-party sources.
| -- LIBSSH2 not found. Set CMAKE_PREFIX_PATH if it is installed outside of the default search path.
| -- Performing Test IS_WDOCUMENTATION_SUPPORTED
| -- Performing Test IS_WDOCUMENTATION_SUPPORTED - Failed
| CMake Warning (dev) at /usr/share/cmake-3.22/Modules/Internal/CheckSourceCompiles.cmake:121 (set):
| Policy CMP0126 is not set: set(CACHE) does not remove a normal variable of
| the same name.  Run "cmake --help-policy CMP0126" for policy details.  Use
| the cmake_policy command to set the policy and suppress this warning.

| For compatibility with older versions of CMake, normal variable
| "IS_WDOCUMENTATION_SUPPORTED" will be removed from the current scope.
| Call Stack (most recent call first):
| /usr/share/cmake-3.22/Modules/Internal/CheckCompilerFlag.cmake:71 (cmake_check_source_compiles)
| /usr/share/cmake-3.22/Modules/CheckCCompilerFlag.cmake:40 (cmake_check_compiler_flag)
| cmake/Modules/AddCFlagIfSupported.cmake:11 (CHECK_C_COMPILER_FLAG)
| CMakeLists.txt:493 (ADD_C_FLAG_IF_SUPPORTED)
| This warning is for project developers.  Use -Wno-dev to suppress it.

| -- Performing Test IS_WNO-MISSING-FIELD-INITIALIZERS_SUPPORTED
| -- Performing Test IS_WNO-MISSING-FIELD-INITIALIZERS_SUPPORTED - Success
| -- Performing Test IS_WSTRICT-ALIASING=2_SUPPORTED
| -- Performing Test IS_WSTRICT-ALIASING=2_SUPPORTED - Success
| -- Performing Test IS_WSTRICT-PROTOTYPES_SUPPORTED
| -- Performing Test IS_WSTRICT-PROTOTYPES_SUPPORTED - Success
| -- Performing Test IS_WDECLARATION-AFTER-STATEMENT_SUPPORTED
| -- Performing Test IS_WDECLARATION-AFTER-STATEMENT_SUPPORTED - Success
| -- Performing Test IS_WNO-UNUSED-CONST-VARIABLE_SUPPORTED
| -- Performing Test IS_WNO-UNUSED-CONST-VARIABLE_SUPPORTED - Success
| -- Performing Test IS_WNO-UNUSED-FUNCTION_SUPPORTED
| -- Performing Test IS_WNO-UNUSED-FUNCTION_SUPPORTED - Success
| -- Looking for regcomp_l
| -- Looking for regcomp_l - not found
| -- Looking for futimens
| -- Looking for futimens - found
| -- Looking for qsort_r
| -- Looking for qsort_r - found
| -- Looking for qsort_s
| -- Looking for qsort_s - not found
| -- Looking for pthread.h
| -- Looking for pthread.h - found
| -- Performing Test CMAKE_HAVE_LIBC_PTHREAD
| -- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
| -- Found Threads: TRUE
| -- Looking for clock_gettime in rt
| -- Looking for clock_gettime in rt - found
| -- Configuring done
| -- Generating done
| -- Build files have been written to: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/libgit2/__CMake_build

libgit2-cmake| CMake configuration: SUCCEEDED
libgit2-cmake| CMake project libgit2 has 1 build targets.

cmake-ast| Processing generated meson AST
cmake-ast| Build file: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/subprojects/libgit2/meson.build

libgit2-cmake| Project name: libgit2
libgit2-cmake| Project version: undefined
libgit2-cmake| C compiler for the host machine: cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
libgit2-cmake| C linker for the host machine: cc ld.bfd 2.38
libgit2-cmake| Build targets in project: 4
libgit2-cmake| Subproject libgit2-cmake finished.


Run-time dependency boxfort found: NO (tried pkgconfig and cmake)
Looking for a fallback subproject for the dependency boxfort
Cloning into 'boxfort'...
remote: Enumerating objects: 1437, done.
remote: Counting objects: 100% (268/268), done.
remote: Compressing objects: 100% (98/98), done.
remote: Total 1437 (delta 208), reused 189 (delta 170), pack-reused 1169 (from 1)
Receiving objects: 100% (1437/1437), 292.81 KiB | 3.90 MiB/s, done.
Resolving deltas: 100% (1003/1003), done.
HEAD is now at 1018a44 Merge pull request #54 from MrAnno/main-decl

Executing subproject boxfort

boxfort| Project name: boxfort
boxfort| Project version: 0.0.1
boxfort| C compiler for the host machine: cc (gcc 11.4.0 "cc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0")
boxfort| C linker for the host machine: cc ld.bfd 2.38
boxfort| Program python3 found: YES (/usr/bin/python3)
boxfort| Program git found: YES (/usr/bin/git)
boxfort| Compiler for C supports arguments -Wno-unused-parameter: YES (cached)
boxfort| Compiler for C supports arguments -Wno-unused-value: YES (cached)
boxfort| Compiler for C supports arguments -fvisibility=hidden: YES (cached)
boxfort| Compiler for C supports arguments /SAFESEH:NO: NO (cached)
boxfort| Compiler for C supports arguments /source-charset:utf-8: NO (cached)
boxfort| Dependency threads found: YES unknown (cached)
boxfort| Library rt found: YES
boxfort| Library m found: YES
boxfort| Checking for function "clock_gettime" : YES
boxfort| Checking for function "gettimeofday" : YES
boxfort| Checking for function "mincore" : YES
boxfort| Checking for function "prctl" : YES
boxfort| Checking for function "procctl" : NO
boxfort| Checking for function "shm_open" : YES
boxfort| Checking for function "mach_vm_protect" : NO
boxfort| Checking for function "__builtin___clear_cache" : YES
boxfort| Header <sys/prctl.h> has symbol "PR_SET_PDEATHSIG" : YES
boxfort| Header <sys/procctl.h> has symbol "PROC_PDEATHSIG_CTL" : NO
boxfort| Header <time.h> has symbol "CLOCK_MONOTONIC_RAW" : YES (cached)
boxfort| Header <unistd.h> has symbol "environ" : YES
boxfort| Header <link.h> has symbol "_r_debug" : YES
boxfort| Header <link.h> has symbol "_DYNAMIC" : YES
boxfort| Configuring config.h using configuration
boxfort| Compiler for C supports arguments -DBXF_STATIC_LIB=1: YES
boxfort| Compiler for C supports link arguments -Wl,--exclude-libs,ALL: YES
boxfort| Compiler for C supports arguments -fvisibility=default: YES
boxfort| Compiler for C supports arguments -fvisibility=default: YES (cached)
boxfort| Compiler for C supports arguments -fvisibility=default: YES (cached)
boxfort| Compiler for C supports arguments -fvisibility=default: YES (cached)
boxfort| Program sh found: YES (/usr/bin/sh)
boxfort| Program cram cram3 found: NO
boxfort| Build targets in project: 9
boxfort| NOTICE: Future-deprecated features used:
boxfort| * 0.55.0: {'ExternalProgram.path'}
boxfort| Subproject boxfort finished.

Dependency boxfort from subproject subprojects/boxfort found: YES 0.0.1
Run-time dependency libffi found: YES 3.4.2
Library rt found: YES
Library m found: YES
Library intl found: NO
Header <libintl.h> has symbol "gettext" with dependency -lintl: YES
Configuring config.h using configuration
Compiler for C supports link arguments -Wl,--exclude-libs,ALL: YES (cached)
Program sh found: YES (/usr/bin/sh)
Program cram found: NO
Build targets in project: 53
NOTICE: Future-deprecated features used:
 * 0.56.0: {'meson.source_root'}

criterion 2.4.3

  Subprojects
    boxfort      : YES 1 warnings
    debugbreak   : YES
    klib         : YES
    libgit2-cmake: YES
    nanomsg-cmake: YES
    nanopb-cmake : YES

  User defined options
    buildtype    : release

Found ninja-1.10.1 at /usr/bin/ninja

ERROR: Clock skew detected. File /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/meson-private/coredata.dat has a time stamp 4.1926s in the future.

A full log can be found at /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/meson-logs/meson-log.txt

ERROR: Current directory is not a meson build directory: `/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build`.
Please specify a valid build dir or change the working directory to it.
It is also possible that the build directory was generated with an old
meson version. Please regenerate it in this case.

ERROR: No such build data file as "'/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion/build/meson-private/build.dat'".
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion#
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees/Criterion# cd ..
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make test
gcc -Wall -Wextra -Werror -pedantic -I . -I .    -c tests/test_is_avl.c -o tests/test_is_avl.o
tests/test_is_avl.c:1:10: fatal error: criterion/criterion.h: No such file or directory
    1 | #include <criterion/criterion.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make: *** [Makefile:35: tests/test_is_avl.o] Error 1
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make test-nocrit
make: *** No rule to make target 'test-nocrit'.  Stop.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees#
```




```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make
gcc -Wall -Wextra -Werror -pedantic -I . -c binary_tree_print.c -o binary_tree_print.o
gcc -Wall -Wextra -Werror -pedantic -I . -c 0-main.c -o 0-main.o
gcc -Wall -Wextra -Werror -pedantic -I . binary_tree_node.o binary_tree_print.o 0-binary_tree_is_avl.o 0-main.o -o 0-is_avl
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/avl_trees# make test
gcc -Wall -Wextra -Werror -pedantic -I . -I . -c tests/test_runner.c -o tests/test_runner.o
gcc -Wall -Wextra -Werror -pedantic -I . tests/test_runner.o binary_tree_node.o 0-binary_tree_is_avl.o -o tests/test_runner
./tests/test_runner
[OK]   null_tree_returns_0
[OK]   single_node_is_avl
[OK]   perfect_small_avl
[OK]   bst_violation_left_child_greater
[OK]   unbalanced_height_violation
[OK]   balanced_but_not_bst_on_deeper_node
[OK]   example_initial_is_avl
[OK]   example_after_insert_not_avl

All tests passed ✅
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
