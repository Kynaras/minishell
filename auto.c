#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "minishell.h"

const char *words[] = {"add", "remove", "rm", "update", "child", "children", "wife", "wifes"};

void *xmalloc (int size)
{
    void *buf;
    buf = malloc (size);
    if (!buf)
    {
        fprintf (stderr, "Error: Out of memory. Exiting.\n");
        exit (1);
    }
    return buf;
}

char *dupstr (const char *str)
{
    char *temp;
    temp = (char *) xmalloc (strlen (str) + 1);
    strcpy (temp, str);
    return (temp);
}

char *my_generator (const char *text, int state)
{
    static int list_index, len;
    const char *name;

    if (!state)
    {
        list_index = 0;
        len = strlen (text);
    }

    while ((name = words[list_index]))
    {
        list_index++;
        if (ft_strncmp(name, text, len) == 0) return dupstr (name);
    }

    // If no names matched, then return NULL.
    return ((char *) NULL);
}

static char **my_completion (const char *text, int start, int end)
{
    char **matches = (char **) NULL;
    if (start == 0)
    {
        matches = rl_completion_matches ((char *) text, &my_generator);
    }
    else rl_bind_key ('\t', rl_abort);
    return matches;
}

int main (int argc, char *argv[])
{
    char *buf;
    rl_attempted_completion_function = my_completion;

    while ((buf = readline(">> ")) != NULL)
    {
        rl_bind_key ('\t', rl_complete);

        if (strcmp (buf, "exit") == 0) break;
        // else if (buf[0] == '\0') continue;
        // else
        // {
        //   //  std::cout << buf << std::endl;
        //     add_history (buf);
        // }
    }
    free (buf);

    return 0;
}
