# 0x12. C - Singly linked lists

Toolchain: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`  
Style: Betty (≤ 5 functions/file, no globals).  
Allowed: `malloc`, `free`, `exit` (+ `printf` in 0, `strdup` in 2/3).

Files:
- `lists.h`
- `0-print_list.c`
- `1-list_len.c`
- `2-add_node.c`
- `3-add_node_end.c`
- `4-free_list.c`

Notes:
- `print_list`: يطبع `[0] (nil)` عندما `str == NULL`.
- `add_node(_end)`: يكرر النص باستخدام `strdup` ويضبط `len`.
- `free_list`: يحرر `str` ثم العقدة بالتسلسل.
