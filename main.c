#include "log.h"

int main(int ac, char **av)
{
	char str[50];
	log_interface *tlog = conlog.interface;
	tlog->init(&conlog, av[0]);
	CLOG(&conlog, 2, "test 1", "test 2");
	ELOG(&conlog, 2, "test 3", "test 4");
}
