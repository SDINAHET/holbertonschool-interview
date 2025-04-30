# Sandpiles

![Project Badge](https://img.shields.io/badge/Project-Sandpiles-blue)
![Status](https://img.shields.io/badge/Level-Amateur-green)
![Author](https://img.shields.io/badge/By-Alexandre%20Gautier-orange)

## Description

This project is an implementation of the **Abelian Sandpile Model**, a mathematical model exhibiting self-organized criticality.
Given two 3x3 grids (sandpiles), this program computes their sum and stabilizes the result by applying the "toppling" rule recursively until the sandpile is stable.

Inspired by the [Numberphile video on Sandpiles](https://www.youtube.com/watch?v=1MtEUErz7Gg).

---

## Requirements

- Ubuntu 14.04 LTS
- GCC 4.8.4 with the flags: `-Wall -Werror -Wextra -pedantic`
- No use of global variables
- Maximum 5 functions per file
- Code must follow the **Betty** coding style
- Header file: `sandpiles.h` (must be include-guarded)

---

## Resources

- 📺 [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg)

---

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o sandpiles
```

---

## Usage Example

### Example: Unstable Grid

```c
int grid1[3][3] = {
    {3, 3, 3},
    {3, 3, 3},
    {3, 3, 3}
};
int grid2[3][3] = {
    {1, 3, 1},
    {3, 3, 3},
    {1, 3, 1}
};

sandpiles_sum(grid1, grid2);
```

Output:

```
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

---

## Function Prototype

```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

- Computes the sum of two 3x3 sandpiles.
- Modifies `grid1` in-place with the stabilized result.
- If the result is unstable (cell > 3), it prints the grid before each toppling.

---

## Files

- `0-sandpiles.c`: Implements the sum and stabilization of sandpiles.
- `sandpiles.h`: Contains function prototypes and macros.
- `0-main.c`: Sample test case (for local testing only, not graded).

---

## Author

**Alexandre Gautier**
Software Engineer at Holberton School
GitHub repository: [holbertonschool-interview](https://github.com/holbertonschool-interview)

