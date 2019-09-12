#include "minishell.h"
       #include <stdio.h>
       #include <readline/readline.h>
 #include <readline/history.h>// #include <readline.h>
int main(int argc, char **argv)
{
    char *str = readline("Enter here$>");
    printf("You entered %s", str);
    return (0);
}