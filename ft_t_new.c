t_e_list *ft_t_new(char *str, int start, int len)
{
    int i;
    t_e_list *new;

    new = malloc(sizeof(t_e_list));
    i = 0;
    str = str + start;
    if (new->name = ft_memalloc(len) &&
    new->value = ft_memalloc(ft_strlen(str + len)))
    {
        while (str[i] && i < len)
        {
            new->name[i] = str[i];
            i++;
        }
        i++;
        while (str[i])
        {
            new->value = str[i];
            i++;
        }
    }
    new->next = NULL;
}
