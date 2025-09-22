C - Variadic functions

Tasks:
0) int sum_them_all(const unsigned int n, ...);
1) void print_numbers(const char *separator, const unsigned int n, ...);
2) void print_strings(const char *separator, const unsigned int n, ...);
3) void print_all(const char * const format, ...);

Notes:
- Uses stdarg macros (va_start, va_arg, va_end).
- Task #3 respects constraints: no for/goto/else/do...while, max 2 while, max 2 if, max 9 variables.
- Betty style compliant.
