# How to use it:

1. Git clone the logger in your active C project
2. Add #include "$PATH/log.h" to your main header
3. Add the C files to your makefile rules
4. Initialize the logger with the following 2 lines of code:
      	log_interface *tlog = conlog.interface;
	tlog->init(&conlog, argv[0]);
5. Use the macros to print to the desired fd (CLOG for STDOUT, ELOG for STDERR & FLOG to write to a file)

The logger takes a minimum of 2 arguments:
1. Itself
2. The # of strings you wish to print (can be 0 to use the logger as a way to see if you reach a part of your code)
3+. The strings you wish to print **(note that this logger can only print strings as of right now)**

Example of use:

	char *str1 = "Hello";
	char *str2 = "world";
	int i = 25;
	log_interface *tlog = conlog.interface;
	tlog->init(&conlog, av[0]);
	CLOG(&conlog, 2, "test 1 ", "test 2");
	ELOG(&conlog, 0);
	CLOG(&conlog, 6, "str1 = ", str1, ", str2 = ", str2, ", i = ", ft_itoa(i));
  
Will print:

On line 11 in main/main.c :

test 1 test 2

On line 12 in main/main.c :

On line 13 in main/main.c :

str1 = Hello, str2 = world, i = 25

