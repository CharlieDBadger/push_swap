#include "libft.h"
#include <stdio.h>

void    ft_print_array_main(char **array)
{
    int i;

    if (!array)
        return;
    i = 1;
    while (array[i])
    {
        ft_printf("%s\n", array[i]);
        i++;
    }
}

int	main(int argc, char **argv)
{
	t_list	*data_set;
	char	**data;
	int		i;


	ft_print_array_main(argv);
	if (argc == 1)
	{
		ft_putchar('\n');
		return (1);
	}

	if (argc == 2)
		data = ft_split(argv[1], ' ');
	else
		data = argv;
	
	ft_print_array_main(data);
	
	data_set = data_set_generator(data);
	if (!data_set)
	{
		ft_printf("Error: Invalid data or duplicates found.\n");
		return (1);
	}

	i = 1;
	while (data_set)
	{
		ft_printf("Elemento #%i: %i\n", i, (long)data_set->content);
		data_set = data_set->next;
		i++;
	}

	// Liberar la memoria
	ft_lstclear(&data_set, free);

	return (0);
}



/*
int main(int argc, char **argv)
{
	char	**data;	
	
	if(argc == 1)
	{
		ft_putchar('\n');
		return 1;
	}
	if(argc == 2)
		data = ft_split(argv[1], ' ');
	else
		data = argv;
	
	
	
	
	return 0;
}
*/
