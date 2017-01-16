#ifndef __LIBC_MY__
# define __LIBC_MY__


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <sys/time.h>

/***********/
/* Defines */
/***********/

# define MAX(a, b)      ((a) > (b) ? (a) : (b))
# define MIN(a, b)      ((a) < (b) ? (a) : (b))
# define ISUPPER(c)     (c >= 'A' && c <= 'Z')
# define ISLOWER(c)     (c >= 'a' && c <= 'z')
# define ISALPHA(c)     (ISUPPER(c) || ISLOWER(c))
# define ISPRINTABLE(c) (c >= 0x20 && c <= 0x7E)
# define ISDIGIT(c)     (c >= '0' && c <= '9')
# define VAL_ABS(i)     ((i) < 0 ? -(i) : (i))
# define POW(i)         ((i) * (i))
# define ARROND(i)      ((i) - floor(i) > 0.5 ? ceil(i) : floor(i))

#ifndef NULL
# define NULL ((void *)(0))
#endif /* NULL */

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 1
#endif /* EXIT_SUCCESS */

#ifndef EXIT_FAILURE
# define EXIT_FAILURE -1
#endif /* EXIT_FAILURE */

typedef enum    s_bool
  {
    FALSE,
    TRUE
  }             t_bool;

/**************/
/* Prototypes */
/**************/

int             count_line(char *str);
int             line_len(char *str);
char            *revstr(char *str);
void            *xmalloc(int size);
char            **str_to_wordtab(char *str);
int             xopen(const char *pathname, int flags);
int             put_err(char *error);
int             put_str(char *str);
int             put_nstr(char *str, int len);
int             put_char(char c);
void            put_inttab(int *tab, int tablen);
void            put_strtab(char **str);
void            exit_error(char *error);
void            freetab(char **tab);
unsigned int    get_ms();
unsigned int    get_s();

#endif /* __LIBC_MY__ */