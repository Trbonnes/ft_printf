#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ft;
	int true;
	char *ptr;
	int l;
	int k;
	long long int n;
	long long int f;
	long int a;
	long int b;
	/*short int c;
	short int d;*/

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
	ft = ft_printf("ft: %+i %+7i %-+9i %0+5i\n", 256, 18, -1024, 29);
	true = printf("pf: %+i %+7i %-+9i %0+5i\n", 256, 18, -1024, 29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///u///\n");
	ft = ft_printf("ft: %u %7u %-9u %05u\n", -5, 1024, 0, 29);
	true = printf("pf: %u %7u %-9u %05u\n", -5, 1024, 0, 29);
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
	ft = ft_printf("ft: %s\n %n\n", "0123456789", &l);
	true = printf("pf: %s\n %n\n", "0123456789", &k);
	printf("value ft: %d value pf: %d\n", l, k);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");

	printf("\n///lc///\n");
	ft = ft_printf("ft: %lc %5lc %-4lc\n", L'a', L'	', L'7');
	true = printf("pf: %lc %5lc %-4lc\n", L'a', L'	', L'7');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///ls///\n");
	ft = ft_printf("ft: %ls %10ls %-8ls\n", L"Bonjour", L"Tristan", L"42");
	true = printf("pf: %ls %10ls %-8ls\n", L"Bonjour", L"Tristan", L"42");
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///ld///\n");
	ft = ft_printf("ft: %.*ld %7ld %-9ld %05ld\n", 8, -18l, 18l, 18l, 18l);
	true = printf("pf: %.*ld %7ld %-9ld %05ld\n", 8, -18l, 18l, 18l, 18l);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///li///\n");
	ft = ft_printf("ft: %li %+7li %-+9li %0+5li\n", -18l, 18l, 18l, 18l);
	true = printf("pf: %li %+7li %-+9li %0+5li\n", -18l, 18l, 18l, 18l);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lu///\n");
	ft = ft_printf("ft: %lu %7lu %-9lu %05lu\n", 18l, 18l, 18l, 18l);
	true = printf("pf: %lu %7lu %-9lu %05lu\n", 18l, 18l, 18l, 18l);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///ln///\n");
	ft = ft_printf("ft: %s\n %ln\n", "01234567899876543210", &a);
	true = printf("pf: %s\n %ln\n", "01234567899876543210", &b);
	printf("value ft: %ld value pf: %ld\n", a, b);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lld///\n");
	ft = ft_printf("ft: %.*lld %7lld %-9lld %05lld\n", 8, -18ll, 18ll, 18ll, 18ll);
	true = printf("pf: %.*lld %7lld %-9lld %05lld\n", 8, -18ll, 18ll, 18ll, 18ll);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lli///\n");
	ft = ft_printf("ft: %lli %+7lli %-+9lli %0+5lli\n", -18ll, 18ll, 18ll, 18ll);
	true = printf("pf: %lli %+7lli %-+9lli %0+5lli\n", -18ll, 18ll, 18ll, 18ll);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///llu///\n");
	ft = ft_printf("ft: %llu %7llu %-9llu %05llu\n", 18ll, 18ll, 18ll, 18ll);
	true = printf("pf: %llu %7llu %-9llu %05llu\n", 18ll, 18ll, 18ll, 18ll);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lln///\n");
	ft = ft_printf("ft: %s\n %lln\n", "01234567899876543210", &n);
	true = printf("pf: %s\n %lln\n", "01234567899876543210", &f);
	printf("value ft: %lld value pf: %lld\n", n, f);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");

	/*printf("///hd///\n");
	ft = ft_printf("ft: %.*hd %7hd %-9hd %05hd\n", 8, -18, 18, 18, 18);
	true = printf("pf: %.*hd %7hd %-9hd %05hd\n", 8, -18, 18, 18, 18);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hi///\n");
	ft = ft_printf("ft: %hi %+7hi %-+9hi %0+5hi\n", -18, 18, 18, 18);
	true = printf("pf: %hi %+7hi %-+9hi %0+5hi\n", -18, 18, 18, 18);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hu///\n");
	ft = ft_printf("ft: %hu %7hu %-9hu %05hu\n", 18, 18, 18, 18);
	true = printf("pf: %hu %7hu %-9hu %05hu\n", 18, 18, 18, 18);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hn///\n");
	ft = ft_printf("ft: %s\n %hn\n", "01234567899876543210", &c);
	true = printf("pf: %s\n %hn\n", "01234567899876543210", &d);
	printf("vahue ft: %hd vahue pf: %hd\n", c, d);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");*/
	//printf("%ls\n", L"licorne salee");
	//write(1, L"licorne", sizeof(wchar_t) * 7)
	return (0);
}
