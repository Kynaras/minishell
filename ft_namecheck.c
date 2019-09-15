#include "minishell.h"

char	*ft_namecheck(char *path)
{
	char *ret;
	char **array;
	int i;

	i = 0;
	array = ft_strsplit(path, '/');
	while (array[i])
	{
		if (ft_strlen(array[i]) > NAME_MAX)
		{
			ret = ft_strdup(array[i]);
			ft_freearray(array);
			return (ret);
		}
		i++;
	}
	ft_freearray(array);
	return (NULL);

}