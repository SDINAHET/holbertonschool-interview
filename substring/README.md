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
