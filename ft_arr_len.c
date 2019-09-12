#include "minishell.h"

size_t  ft_arr_len(char **arr)
{
    size_t len;

    len = 0;
    if(arr)
    {
        while(arr[len] != NULL)
            len++;
    }
    return (len);
}