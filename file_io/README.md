# 0x15. C - File I/O

Toolchain: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`  
Style: Betty (≤ 5 functions/file, no globals).  
Allowed syscalls: `open`, `read`, `write`, `close`.  
Allowed libc: `malloc`, `free`, `exit` (+ `dprintf` only in `3-cp.c`).

Files:
- `main.h`
- `0-read_textfile.c`
- `1-create_file.c`
- `2-append_text_to_file.c`
- `3-cp.c`

Notes:
- `read_textfile`: يقرأ حتى `letters` بايت ويكتبهم إلى `STDOUT_FILENO`. يعيد
  عدد البايتات المطبوعة، أو 0 عند أي خطأ فتح/قراءة/كتابة.  
- `create_file`: ينشئ/يقطع الملف بوضع أذونات `0600`، يعيد 1 أو -1.  
- `append_text_to_file`: يفتح للكتابة مع `O_APPEND`؛ إن كانت السلسلة NULL
  نعيد 1 بشرط أن الفتح نجح.  
- `3-cp.c`: يحاكي `cp` بباڤر 1024 وأكواد الخروج `97/98/99/100`.
