#include "log.h"

int main(int ac, char **av)
{
	char str[50];
	char *str1 = "Hello";
	char *str2 = "world";
	int i = 25;
	log_interface *tlog = conlog.interface;
	tlog->init(&conlog, av[0]);
	CLOG(&conlog, 2, "test 1 ", "test 2");
	ELOG(&conlog, 0);
	CLOG(&conlog, 6, "str1 = ", str1, ", str2 = ", str2, ", i = ", ft_itoa(i));

}
