/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:25:04 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/12 15:42:55 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	short int c;
	short int d;
	signed char w;
	signed char q;

	ptr = malloc(1);
	printf("\n///c///\n");
	ft = ft_printf("ft: %c %5c %-4c\n", 'a', '	', '7');
	true = printf("pf: %c %5c %-4c\n", 'a', '	', '7');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///s///\n");
	ft = ft_printf("ft: %.15s %10s %-8.35s\n", "Coco", "Tristan", NULL);
	true = printf("pf: %.15s %10s %-8.35s\n", "Coco", "Tristan", NULL);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///p///\n");
	ft = ft_printf("ft: %----24p et hello %2p %12p %53p\n", ptr, ptr, NULL, ptr);
	true = printf("pf: %----24p et hello %2p %12p %53p\n", ptr, ptr, NULL, ptr);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///d///\n");
	ft = ft_printf("ft: %10.*d %7d %-9d %05d %*d %0*d\n", 8, -18, 18, 18, 18, -8, 18, -8, 18);
	true = printf("pf: %10.*d %7d %-9d %05d %*d %0*d\n", 8, -18, 18, 18, 18, -8, 18, -8, 18);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///i///\n");
	ft = ft_printf("ft: %i %7i %-9i %05i\n", 256, 18, -1024, 29);
	true = printf("pf: %i %7i %-9i %05i\n", 256, 18, -1024, 29);
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
	ft = ft_printf("ft: %% %5% %08% %-3% %.8%\n");
	true = printf("pf: %% %5% %08% %-3% %.8%\n");
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
	ft = ft_printf("ft: %lc %5lc %-4lc\n", L'Ö', L'	', L'7');
	true = printf("pf: %lc %5lc %-4lc\n", L'Ö', L'	', L'7');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///ls///\n");
	ft = ft_printf("ft: %.3ls %10ls %-8ls\n", L"Bonjour", L"Tristan", L"42");
	true = printf("pf: %.3ls %10ls %-8ls\n", L"Bonjour", L"Tristan", L"42");
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///ld///\n");
	ft = ft_printf("ft: %10.*ld %7ld %-9ld %05ld\n", 8, -18l, 18l, 18l, 18l);
	true = printf("pf: %10.*ld %7ld %-9ld %05ld\n", 8, -18l, 18l, 18l, 18l);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///li///\n");
	ft = ft_printf("ft: %li %7li %-9li %05li\n", -18l, 18l, 18l, 18l);
	true = printf("pf: %li %7li %-9li %05li\n", -18l, 18l, 18l, 18l);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lu///\n");
	ft = ft_printf("ft: %lu %7lu %-9lu %05lu\n", 18l, 18l, 18l, 18l);
	true = printf("pf: %lu %7lu %-9lu %05lu\n", 18l, 18l, 18l, 18l);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lx///\n");
	ft = ft_printf("ft: %#lx %7lx %-9lx %05lx\n", 256l, 1024l, 0l, 29l);
	true = printf("pf: %#lx %7lx %-9lx %05lx\n", 256l, 1024l, 0l, 29l);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lX///\n");
	ft = ft_printf("ft: %lX %7lX %-9lX %05lX\n", 256l, 1024l, 0l, 29l);
	true = printf("pf: %lX %7lX %-9lX %05lX\n", 256l, 1024l, 0l, 29l);
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
	ft = ft_printf("ft: %10.*lld %7lld %-9lld %05lld %*lld %0*lld\n", 8, -18ll, 18ll, 18ll, 18ll, -8, 18ll, -8, 18ll);
	true = printf("pf: %10.*lld %7lld %-9lld %05lld %*lld %0*lld\n", 8, -18ll, 18ll, 18ll, 18ll, -8, 18ll, -8, 18ll);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///lli///\n");
	ft = ft_printf("ft: %lli %7lli %-9lli %05lli\n", -18ll, 18ll, 18ll, 18ll);
	true = printf("pf: %lli %7lli %-9lli %05lli\n", -18ll, 18ll, 18ll, 18ll);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///llu///\n");
	ft = ft_printf("ft: %llu %7llu %-9llu %05llu\n", 18ll, 18ll, 18ll, 18ll);
	true = printf("pf: %llu %7llu %-9llu %05llu\n", 18ll, 18ll, 18ll, 18ll);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///llx///\n");
	ft = ft_printf("ft: %#llx %7llx %-9llx %05llx\n", 256ll, 1024ll, 0ll, 29ll);
	true = printf("pf: %#llx %7llx %-9llx %05llx\n", 256ll, 1024ll, 0ll, 29ll);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///llX///\n");
	ft = ft_printf("ft: %llX %7llX %-9llX %05llX\n", 256ll, 1024ll, 0ll, 29ll);
	true = printf("pf: %llX %7llX %-9llX %05llX\n", 256ll, 1024ll, 0ll, 29ll);
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

	printf("///hd///\n");
	ft = ft_printf("ft: %.*hd %7hd %-9hd %05hd\n", 8, (short)-18, (short)18, (short)18, (short)18);
	true = printf("pf: %.*hd %7hd %-9hd %05hd\n", 8, (short)-18, (short)18, (short)18, (short)18);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hi///\n");
	ft = ft_printf("ft: %hi %7hi %-9hi %05hi\n", (short)-18, (short)18, (short)18, (short)18);
	true = printf("pf: %hi %7hi %-9hi %05hi\n", (short)-18, (short)18, (short)18, (short)18);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hu///\n");
	ft = ft_printf("ft: %hu %7hu %-9hu %05hu\n", (short)18, (short)18, (short)18, (short)18);
	true = printf("pf: %hu %7hu %-9hu %05hu\n", (short)18, (short)18, (short)18, (short)18);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hx///\n");
	ft = ft_printf("ft: %#hx %7hx %-9hx %05hx\n", (short)256, (short)1024, (short)0, (short)29);
	true = printf("pf: %#hx %7hx %-9hx %05hx\n", (short)256, (short)1024, (short)0, (short)29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hX///\n");
	ft = ft_printf("ft: %hX %7hX %-9hX %05hX\n", (short)256, (short)1024, (short)0, (short)29);
	true = printf("pf: %hX %7hX %-9hX %05hX\n", (short)256, (short)1024, (short)0, (short)29);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hn///\n");
	ft = ft_printf("ft: %s\n %hn\n", "01234567899876543210", &c);
	true = printf("pf: %s\n %hn\n", "01234567899876543210", &d);
	printf("value ft: %hd value pf: %hd\n", c, d);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hhd///\n");
	ft = ft_printf("ft: %.*hhd %7hhd %-9hhd %05hhd\n", (signed char)'c', (signed char)'c', (signed char)'c', (signed char)'c', (signed char)'c');
	true = printf("pf: %.*hhd %7hhd %-9hhd %05hhd\n", (signed char)'c', (signed char)'c', (signed char)'c', (signed char)'c', (signed char)'c');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hhi///\n");
	ft = ft_printf("ft: %hhi %7hhi %-9hhi %05hhi\n", (signed char)'=', (signed char)'=', (signed char)'=', (signed char)'=');
	true = printf("pf: %hhi %7hhi %-9hhi %05hhi\n", (signed char)'=', (signed char)'=', (signed char)'=', (signed char)'=');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hhu///\n");
	ft = ft_printf("ft: %hhu %7hhu %-9hhu %05hhu\n", (unsigned char)'|', (unsigned char)'|', (unsigned char)'|', (unsigned char)'|');
	true = printf("pf: %hhu %7hhu %-9hhu %05hhu\n", (unsigned char)'|', (unsigned char)'|', (unsigned char)'|', (unsigned char)'|');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hhx///\n");
	ft = ft_printf("ft: %#hhx %7hhx %-9hhx %05hhx\n", (unsigned char)'<', (unsigned char)'<', (unsigned char)'<', (unsigned char)'<');
	true = printf("pf: %#hhx %7hhx %-9hhx %05hhx\n", (unsigned char)'<', (unsigned char)'<', (unsigned char)'<', (unsigned char)'<');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hhX///\n");
	ft = ft_printf("ft: %hhX %7hhX %-9hhX %05hhX\n", (unsigned char)'>', (unsigned char)'>', (unsigned char)'>', (unsigned char)'>');
	true = printf("pf: %hhX %7hhX %-9hhX %05hhX\n", (unsigned char)'>', (unsigned char)'>', (unsigned char)'>', (unsigned char)'>');
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");
	printf("///hhn///\n");
	ft = ft_printf("ft: %s\n %hhn\n", "01234567899876543210", &w);
	true = printf("pf: %s\n %hhn\n", "01234567899876543210", &q);
	printf("value ft: %hhd value pf: %hhd\n", w, q);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");

	printf("\n///f///\n");
	ft = ft_printf("ft: %10.*f %10.2f %7f %-9f %05f %*f %0*f\n", 7, 123.456, 123.456, 0.0/0.0, 123.456, 123.456, -8, 123.456, -8, 123.456);
	true = printf("pf: %10.*f %10.2f %7f %-9f %05f %*f %0*f\n", 7, 123.456, 123.456, 0.0/0.0, 123.456, 123.456, -8, 123.456, -8, 123.456);
	printf("ft: %d\n", ft);
	printf("pf: %d\n", true);
	printf("\n");

	//printf("%ls\n", L"licorne salee");
	//write(1, L"licorne", sizeof(wchar_t) * 7)

	printf("\n///TEST///\n");
	printf("\n");
	ft_printf("FT String precision (1.9): %1.9s.\n", "Hello");
	printf("PF String precision (1.9): %1.9s.\n\n", "Hello");

	ft_printf("FT String precision (2.1): %2.1s.\n", "Hello");
	printf("PF String precision (2.1): %2.1s.\n\n", "Hello");

	ft_printf("FT String precision (5.1): %5.1s.\n", "Hello");
	printf("PF String precision (5.1): %5.1s.\n\n", "Hello");

	ft_printf("FT String precision (5.3): %5.3s.\n", "Hello");
	printf("PF String precision (5.3): %5.3s.\n\n", "Hello");

	ft_printf("FT String precision (4.4): %4.4s.\n", "Hello");
	printf("PF String precision (4.4): %4.4s.\n\n", "Hello");

	ft_printf("FT String precision (5.4): %5.4s.\n", "Hello");
	printf("PF String precision (5.4): %5.4s.\n\n", "Hello");

	printf("FT String precision (9.2): %9.2s.\n", "Hello");
	printf("PF String precision (9.2): %9.2s.\n\n", "Hello");

	ft_printf("FT String precision (5.2): %5.2s.\n", "Hello");
	printf("PF String precision (5.2): %5.2s.\n\n", "Hello");


	ft_printf("FT Int precision with padding (10.5): %10.5d.\n", 5);
	printf("PF Int precision with padding (10.5): %10.5d.\n\n", 5);

	ft_printf("FT Int precision with zero padding (10.5): %010.5d.\n", 5);
	printf("PF Int precision with zero padding (10.5): %010.5d.\n\n", 5);

	ft_printf("FT Int precision with padding (4.2): %4.2d.\n", 500);
	printf("PF Int precision with padding (4.2): %4.2d.\n\n", 500);

	ft_printf("FT Int precision with padding (5.10): %5.10d.\n", 5);
	printf("PF Int precision with padding (5.10): %5.10d.\n\n", 5);

	ft_printf("FT Int precision with negative padding (10.5): %-10.5d.\n", 5);
	printf("PF Int precision with negative padding (10.5): %-10.5d.\n\n", 5);

	ft_printf("ft Int pad width with *: %*d.\n", 5, 18);
	printf("PF Int pad width with *: %*d.\n\n", 5, 18);

	ft_printf("FT Int pad and precision with *: %*.*d.\n", 10, 5, -18);
	printf("PF Int pad and precision with *: %*.*d.\n\n", 10, 5, -18);


	printf("\n///BONUS///\n");
	printf("\n");

	ft_printf("FT Char: %hhd.\n", (char) -5);
	printf("PF Char: %hhd.\n\n", (char) -5);

	ft_printf("FT Short: %hd.\n", (short) -5);
	printf("PF Short: %hd.\n\n", (short) -5);

	ft_printf("FT Int: %d.\n", (int) -5);
	printf("PF Int: %d.\n\n", (int) -5);

	ft_printf("FT Long: %ld.\n", (long) -5);
	printf("PF Long: %ld.\n\n", (long) -5);

	ft_printf("FT Long long: %lld.\n", (long long) -5);
	printf("PF Long long: %lld.\n\n", (long long) -5);

	ft_printf("FT Unsigned Char: %hhu.\n", (unsigned char) -5);
	printf("PF Unsigned Char: %hhu.\n\n", (unsigned char) -5);

	ft_printf("FT Unsigned Short: %hu.\n", (unsigned short) -5);
	printf("PF Unsigned Short: %hu.\n\n", (unsigned short) -5);

	ft_printf("FT Unsigned Int: %u.\n", (unsigned int) -5);
	printf("PF Unsigned Int: %u.\n\n", (unsigned int) -5);

	ft_printf("FT Unsigned Long: %lu.\n", (unsigned long) -5);
	printf("PF Unsigned Long: %lu.\n\n", (unsigned long) -5);

	ft_printf("FT Unsigned Long long: %llu.\n", (unsigned long long) -5);
	printf("PF Unsigned Long long: %llu.\n\n", (unsigned long long) -5);

	ft_printf("FT Hex Char: %hhx.\n", (char) -56);
	printf("PF Hex Char: %hhx.\n\n", (char) -56);

	ft_printf("FT Hex Short: %hx.\n", (short) -5);
	printf("PF Hex Short: %hx.\n\n", (short) -5);

	ft_printf("FT Hex Int: %x.\n", (int) -5);
	printf("PF Hex Int: %x.\n\n", (int) -5);

	ft_printf("FT Hex Long: %lx.\n", (long) -5);
	printf("PF Hex Long: %lx.\n\n", (long) -5);

	ft_printf("FT Hex Long long: %llx.\n", (long long) -5);
	printf("PF Hex Long long: %llx.\n\n", (long long) -5);

	ft_printf("FT Upper Hex Char: %hhX.\n", (char) -11);
	printf("PF Upper Hex Char: %hhX.\n\n", (char) -11);

	ft_printf("FT Upper Hex Short: %hX.\n", (short) -5);
	printf("PF Upper Hex Short: %hX.\n\n", (short) -5);

	ft_printf("FT Upper Hex Int: %X.\n", (int) -5);
	printf("PF Upper Hex Int: %X.\n\n", (int) -5);

	ft_printf("FT Upper Hex Long: %lX.\n", (long) -5);
	printf("PF Upper Hex Long: %lX.\n\n", (long) -5);

	ft_printf("FT Upper Hex Long long: %llX.\n", (long long) -5);
	printf("PF Upper Hex Long long: %llX.\n\n", (long long) -5);
	return (0);
}