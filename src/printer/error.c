#include "../../inc/noel.h"

void	print_error(char *str1, char *str2)
{
	ft_fprintf(2, "Error\n");
	if (str1)
		ft_fprintf(2, "%s ", str1);
	if (!str2)
		write(2, "\n", 1);
	else
		ft_fprintf(2, "%s\n", str2);
}
