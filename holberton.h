#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>
/**
 * struct print - structure for printing various types
 * @t: type to print
 * @f: function to print
 */
typedef struct print
{
	char *t;
	int (*f)(va_list);
} print_t;

/* _putchar */
int _putchar(char c);

/* _printf */
int _printf(const char *format, ...);

#endif  /* _HOLBERTON_H */
