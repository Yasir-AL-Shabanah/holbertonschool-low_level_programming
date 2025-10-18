# 0x17. C - Doubly linked lists

Toolchain: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`  
Style: Betty, ≤ 5 functions/file, no globals.  
Allowed: `malloc`, `free`, `printf`, `exit`.

Files:
- `lists.h`
- `0-print_dlistint.c`
- `1-dlistint_len.c`
- `2-add_dnodeint.c`
- `3-add_dnodeint_end.c`
- `4-free_dlistint.c`
- `5-get_dnodeint.c`
- `6-sum_dlistint.c`
- `7-insert_dnodeint.c`
- `8-delete_dnodeint.c`

Notes:
- Doubly lists traverse forward/backward via `next/prev`.
- Insert/Delete adjust both neighboring links to keep list consistent.
