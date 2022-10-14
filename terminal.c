#include "log.h"

int init_terminal(logger *self, char *name)
{
	self->data = name;
	return 0;
}

void info_terminal(struct logger *self, char *file, const char *function, char *line, ...)
{
	va_list ap;
	char 	*arg;
	unsigned i = 0;
	unsigned int len;

	printf("On line %s in %s/%s :\n",line, function,file);
	va_start(ap, line);
	len = va_arg(ap, int);
	while(i < len)
	{
		arg = va_arg(ap, char*);
		write(1, arg, strlen(arg));
		write(1, "\n", 1);
		i++;
	}
	va_end(ap);
}

void error_terminal(struct logger *self, char *file, const char *function, char *line, ...)
{

	va_list ap;
	char 	*arg;
	unsigned int i = 0;
	unsigned int len;

	printf("On line %s in %s/%s :\n",line, function,file);
	va_start(ap, line);
	len = va_arg(ap, int);
	while(i < len)
	{
		arg = va_arg(ap, char*);
		write(2, arg, strlen(arg));
		write(2, "\n", 1);
		i++;
	}
	va_end(ap);
	//fprintf(stderr, "On line %s in %s/%s :\n%s\n",line, function,file, msg);
}

void close_terminal(logger *self)
{

}

log_interface terminal = {
		.init = init_terminal,
		.info = info_terminal,
		.error = error_terminal,
		.close = close_terminal
};

logger conlog = {
		.interface = &terminal
};

