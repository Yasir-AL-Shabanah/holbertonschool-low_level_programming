# 0x12. C - Singly linked lists

- Toolchain: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Style: Betty
- No globals; ≤ 5 functions per file.
- Only `malloc`, `free`, `exit` allowed globally.
- Task-specific allowances:
  - `printf` allowed in `0-print_list.c`.
  - `strdup` allowed in `2-add_node.c` and `3-add_node_end.c`.
- Header: `lists.h` with include guard and prototypes.

## Files
- `0-print_list.c` — print nodes; prints `[0] (nil)` if `str == NULL`.
- `1-list_len.c` — count nodes.
- `2-add_node.c` — add at beginning (duplicates `str`).
- `3-add_node_end.c` — add at end (duplicates `str`).
- `4-free_list.c` — free all nodes and their `str`.

## Quick test (optional)
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
#     0-print_list.c 1-list_len.c 2-add_node.c 3-add_node_end.c 4-free_list.c \
#     your_main.c -o test && ./test
