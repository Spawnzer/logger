#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CLOG(log, ...) (log)->interface->info(log, __FILE__, __FUNCTION__, ft_itoa(__LINE__), __VA_ARGS__)
#define ELOG(log, ...) (log)->interface->error(log, __FILE__, __FUNCTION__, ft_itoa(__LINE__), __VA_ARGS__)

typedef struct logger logger;

typedef struct log_interface {
	int 	(*init)(logger *self, char *name);
	void 	(*info)(struct logger *self, char *file, const char *function, char *line, ...);
	void	(*error)(struct logger *self, char *file, const char *function, char *line, ...);
	void 	(*close)(logger *self);
} log_interface;

struct logger {
	log_interface	*interface;
	char *data;
};

extern logger conlog;

char	*ft_itoa(int n);
int	ft_len(int nb);
char	*ft_make_itoa(char *str, int n, int len);


