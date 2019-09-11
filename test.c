#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *str = readline("Enter here$>");
	printf("You entered %s", str);
	return (0);
}
