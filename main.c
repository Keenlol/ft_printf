#include "ft_printf.h"
#include <stdio.h>


int	main(void)
{
	char	*a = "h";
	ft_printf("|return (%d)|\n",ft_printf("%k%k%%%%k%%%k%d",42));
	printf("|return (%d)|\n",printf("%k%k%%%%k%%%k%d",42));
}
