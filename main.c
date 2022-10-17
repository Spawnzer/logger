#include "log.h"

int main(int ac, char **av)
{
	char *str1 = "Hello";
	char *str2 = "world";
	int i = 22;
	log_interface *tlog = conlog.interface;
	tlog->init(&conlog, av[0]);
	ELOG(&conlog, 0);
	CLOG(&conlog, 6, "str1 = ", str1, ", str2 = ", str2, ", i = ", ft_itoa(i));
	FLOG(&conlog, 6, "str1 = ", str1, ", str2 = ", str2, ", i = ", ft_itoa(i));
}
