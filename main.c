#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ft;
	int true;
	char *ptr;
	int n;
	int f;

	ptr = malloc(1);
	printf("\n///c///\n");
	ft = ft_printf("ft: %c %5c %-4c\n", 'a', '	', '7');
	true = printf("pf: %c %5c %-4c\n", 'a', '	', '7');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///s///\n");
	ft = ft_printf("ft: %s %10s %-8s\n", "Bonjour", "Tristan", "42");
	true = printf("pf: %s %10s %-8s\n", "Bonjour", "Tristan", "42");
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///p///\n");
	ft = ft_printf("ft: %p %15p %-15p\n", ptr, ptr, ptr);
	true = printf("pf: %p %15p %-15p\n", ptr, ptr, ptr);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///d///\n");
	ft = ft_printf("ft: %.*d %7d %-9d %05d\n", 8, -256, 1024, 0, 29);
	true = printf("pf: %.*d %7d %-9d %05d\n", 8, -256, 1024, 0, 29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///i///\n");
	ft = ft_printf("ft: %i %7i %-9i %05i\n", 256, 1024, 0, 29);
	true = printf("pf: %+i %+7i %-9i %+05i\n", 256, 1024, 0, 29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///u///\n");
	ft = ft_printf("ft: %u %7u %-9u %05u\n", 256, 1024, 0, 29);
	true = printf("pf: %u %7u %-9u %05u\n", 256, 1024, 0, 29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///x///\n");
	ft = ft_printf("ft: %#x %7x %-9x %05x\n", 256, 1024, 0, 29);
	true = printf("pf: %#x %7x %-9x %05x\n", 256, 1024, 0, 29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///X///\n");
	ft = ft_printf("ft: %X %7X %-9X %05X\n", 256, 1024, 0, 29);
	true = printf("pf: %X %7X %-9X %05X\n", 256, 1024, 0, 29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///%%///\n");
	ft = ft_printf("ft: %%\n");
	true = printf("pf: %%\n");
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///n///\n");
	ft = ft_printf("ft: %s\n %n\n", "0123456789", &n);
	true = printf("pf: %s\n %n\n", "0123456789", &f);
	printf("value ft: %d value pf: %d\n", n, f);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	return (0);
}
