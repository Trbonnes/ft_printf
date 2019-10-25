#ifdef MINE
# include "ft_printf.h"
# define PRINTF ft_printf
#else
# include <stdio.h>
# define PRINTF printf
#endif

# define TEST(fmt, ...) PRINTF("^ %d bytes written\n", PRINTF(fmt, ##__VA_ARGS__))
# define TEST_N(fmt, type) do {\
	type n;\
	TEST(fmt, &n);\
	PRINTF("-> `n` conversion returned %lld\n", (long long)n);\
} while (0)

int		main(void)
{
#ifdef MINE
	TEST("-- Your implementation --\n");
#else
	TEST("-- Original implementation --\n");
#endif
	TEST("No args\n");
	TEST("A character : %c.\n", 'd');
	TEST("A string: %s.\n", "Hello");
	TEST("A pointer: %p.\n", "aaa");
	TEST("An signed integer: %d.\n", -5);
	TEST("Another signed integer: %i.\n", -5);
	TEST("An unsigned integer: %u.\n", -5);
	TEST("An hexadecimal number: %x.\n", 0xffffffff);
	TEST("Another hexadecimal number, but uppercase: %X.\n", 0xffffffff);
	TEST("A %% character.\n");
	TEST("Blank padding: %3d.\n", 3);
	TEST("Zero padding: %03d.\n", 700);
	TEST("Negative field width padding: %-3d.\n", 7);
	TEST("Minimum field width with character: %5c.\n", 'c');
	TEST("Minimum field width with string: %5s.\n", "Hi");
	TEST("Minimum field width with int: %5d.\n", 5);
	TEST("Minimum field width with int (2): %5i.\n", 5);
	TEST("Minimum field width with pointer: %16p.\n", "");
	TEST("Minimum field width with uint: %5u.\n", 50);
	TEST("Minimum field width with lowerhex: %10x.\n", 0xffffffff);
	TEST("Minimum field width with upperhex: %10X.\n", 0xffffffff);
	TEST("String precision (1.9): %1.9s.\n", "Hello");
	TEST("String precision (2.1): %2.1s.\n", "Hello");
	TEST("String precision (5.1): %5.1s.\n", "Hello");
	TEST("String precision (5.3): %5.3s.\n", "Hello");
	TEST("String precision (4.4): %4.4s.\n", "Hello");
	TEST("String precision (5.4): %5.4s.\n", "Hello");
	TEST("String precision (9.2): %9.2s.\n", "Hello");
	TEST("String precision (5.2): %5.2s.\n", "Hello");
	TEST("Int precision: %.5d.\n", -5);
	TEST("Int precision (2): %.2i.\n", 500);
	TEST("Uint precision: %.5d.\n", 5);
	TEST("Hexa precision: %.9x.\n", 0xdeadbeef);
	TEST("Hexa precision (2): %.9X.\n", 0xdeadbeef);
	TEST("Int precision with padding (10.5): %10.5d.\n", 5);
	TEST("Int precision with zero padding (10.5): %010.5d.\n", 5);
	TEST("Int precision with padding (4.2): %4.2d.\n", 500);
	TEST("Int precision with padding (5.10): %5.10d.\n", 5);
	TEST("Int precision with negative padding (10.5): %-10.5d.\n", 5);
	TEST("Int pad width with *: %*d.\n", 5, 18);
	TEST("Int pad and precision with *: %*.*d.\n", 10, 5, 18);
#ifdef BONUS
	TEST("Char: %hhd.\n", (char) -5);
	TEST("Short: %hd.\n", (short) -5);
	TEST("Int: %d.\n", (int) -5);
	TEST("Long: %ld.\n", (long) -5);
	TEST("Long long: %lld.\n", (long long) -5);
	TEST("Unsigned Char: %hhu.\n", (unsigned char) -5);
	TEST("Unsigned Short: %hu.\n", (unsigned short) -5);
	TEST("Unsigned Int: %u.\n", (unsigned int) -5);
	TEST("Unsigned Long: %lu.\n", (unsigned long) -5);
	TEST("Unsigned Long long: %llu.\n", (unsigned long long) -5);
	TEST("Hex Char: %hhx.\n", (char) -5);
	TEST("Hex Short: %hx.\n", (short) -5);
	TEST("Hex Int: %x.\n", (int) -5);
	TEST("Hex Long: %lx.\n", (long) -5);
	TEST("Hex Long long: %llx.\n", (long long) -5);
	TEST("Upper Hex Char: %hhX.\n", (char) -5);
	TEST("Upper Hex Short: %hX.\n", (short) -5);
	TEST("Upper Hex Int: %X.\n", (int) -5);
	TEST("Upper Hex Long: %lX.\n", (long) -5);
	TEST("Upper Hex Long long: %llX.\n", (long long) -5);
	TEST_N("Char Conv n: %hhn.\n", char);
	TEST_N("Short Conv n: %hn.\n", short);
	TEST_N("Int Conv n: %n.\n", int);
	TEST_N("Long Conv n: %ln.\n", long);
	TEST_N("Long long Conv n: %lln.\n", long long);
	/*TEST("Double Conv f 1.0: %f.\n", 1.0);
	TEST("Double Conv f 2.0: %f.\n", 3.0);
	TEST("Double Conv f 3.0e2: %f.\n", 3.0e2);
	TEST("Double Conv f -3.0e3: %f.\n", -3.0e3);
	TEST("Double Conv f 3.0e4: %f.\n", 3.0e4);
	TEST("Double Conv f 1.002: %f.\n", 1.002);
	TEST("Double Conv f -3.005: %f.\n", -3.005);
	TEST("Double Conv f 3.000005: %f.\n", 3.000005);
	TEST("Double Conv f -3.0000005: %f.\n", -3.0000005);
	TEST("Double Conv f -3.0000004: %f.\n", -3.0000004);
	TEST("Double Conv f 3.0000006: %f.\n", 3.0000006);
	TEST("Double Conv f -0.55: %f.\n", -0.55);
	TEST("Double Conv f 3.5e3: %f.\n", 3.5e3);
	TEST("Double Conv f with precision 0: %.0f.\n", 45654.245);
	TEST("Double Conv f with precision 1: %.1f.\n", 45654.245);
	TEST("Double Conv f with precision 2: %.2f.\n", 45654.245);
	TEST("Double Conv f with precision 9: %.9f.\n", 45654.245);
	TEST("Double Conv f with width and precision: %5.2f.\n", 5.5);
	TEST("Double Conv f with negative width and precision: %-5.2f.\n", 5.5);
	TEST("Double Conv f with NaN: %f.\n", 0.0/0.0);
	TEST("Double Conv f with Inf: %f.\n", 1.0/0.0);
	TEST("Double Conv f with -Inf: %f.\n", -1.0/0.0);
	TEST("Double Conv f with NaN and padding: %9f.\n", 0.0/0.0);
	TEST("Double Conv f with NaN and negative padding: %-9f.\n", 0.0/0.0);
	TEST("Double Conv e 1.0: %e.\n", 1.0);
	TEST("Double Conv e 2.0: %e.\n", 3.0);
	TEST("Double Conv e 3.0e2: %e.\n", 3.0e2);
	TEST("Double Conv e -3.0e3: %e.\n", -3.0e3);
	TEST("Double Conv e 3.0e3: %e.\n", 3.0e3);
	TEST("Double Conv e 3.0e4: %e.\n", 3.0e4);
	TEST("Double Conv e 1.002: %e.\n", 1.002);
	TEST("Double Conv e -3.005: %e.\n", -3.005);
	TEST("Double Conv e 3.000005: %e.\n", 3.000005);
	TEST("Double Conv e -3.0000005: %e.\n", -3.0000005);
	TEST("Double Conv e -3.0000004: %e.\n", -3.0000004);
	TEST("Double Conv e 3.0000006: %e.\n", 3.0000006);
	TEST("Double Conv e -0.55: %e.\n", -0.55);
	TEST("Double Conv e 3.5e3: %e.\n", 3.5e3);
	TEST("Double Conv e with precision 0: %.0e.\n", 45654.245);
	TEST("Double Conv e with precision 1: %.1e.\n", 45654.245);
	TEST("Double Conv e with precision 2: %.2e.\n", 45654.245);
	TEST("Double Conv e with precision 3: %.3e.\n", 400000.0);
	TEST("Double Conv e with precision 9: %.9e.\n", 45654.245);
	TEST("Double Conv e with width and precision: %9.2e.\n", 5.5);
	TEST("Double Conv e with negative width and precision: %-9.2e.\n", 5.5);
	TEST("Double Conv e with NaN: %e.\n", 0.0/0.0);
	TEST("Double Conv e with Inf: %e.\n", 1.0/0.0);
	TEST("Double Conv e with -Inf: %e.\n", -1.0/0.0);
	TEST("Double Conv e with NaN and padding: %5e.\n", 0.0/0.0);
	TEST("Double Conv e with NaN and negative padding: %-5e.\n", 0.0/0.0);
	TEST("Double Conv g 1.0: %g.\n", 1.0);
	TEST("Double Conv g 2.0: %g.\n", 3.0);
	TEST("Double Conv g 3.0e2: %g.\n", 3.0e2);
	TEST("Double Conv g -3.0e3: %g.\n", -3.0e3);
	TEST("Double Conv g 3.0e3: %g.\n", 3.0e3);
	TEST("Double Conv g 1.002: %g.\n", 1.002);
	TEST("Double Conv g -3.005: %g.\n", -3.005);
	TEST("Double Conv g 3.000005: %g.\n", 3.000005);
	TEST("Double Conv g 3.123415: %g.\n", 3.123415);
	TEST("Double Conv g 3.123405: %g.\n", 3.123405);
	TEST("Double Conv g -3.0000005: %g.\n", -3.0000005);
	TEST("Double Conv g -3.0000004: %g.\n", -3.0000004);
	TEST("Double Conv g 3.0000006: %g.\n", 3.0000006);
	TEST("Double Conv g -0.55: %g.\n", -0.55);
	TEST("Double Conv g 3.5e3: %g.\n", 3.5e3);
	TEST("Double Conv g with precision 0: %.0g.\n", 45654.245);
	TEST("Double Conv g with precision 1: %.1g.\n", 45654.245);
	TEST("Double Conv g with precision 2: %.2g.\n", 45654.245);
	TEST("Double Conv g with precision 3: %.3g.\n", 400000.0);
	TEST("Double Conv g with precision 3 (2): %.3g.\n", 45654.245);
	TEST("Double Conv g with precision 4: %.4g.\n", 45654.245);
	TEST("Double Conv g with precision 5: %.5g.\n", 45654.245);
	TEST("Double Conv g with precision 9: %.9g.\n", 45654.245);
	TEST("Double Conv g with width and precision: %9.2g.\n", 5.5);
	TEST("Double Conv g with negative width and precision: %-9.2g.\n", 5.5);
	TEST("Double Conv g with NaN: %g.\n", 0.0/0.0);
	TEST("Double Conv g with Inf: %g.\n", 1.0/0.0);
	TEST("Double Conv g with -Inf: %g.\n", -1.0/0.0);
	TEST("Double Conv g with NaN and padding: %5g.\n", 0.0/0.0);
	TEST("Double Conv g with NaN and negative padding: %-5g.\n", 0.0/0.0);
	TEST("Double Conv g 0.001: %g.\n", 0.001);
	TEST("Double Conv g 0.0001: %g.\n", 0.0001);
	TEST("Double Conv g 0.00001: %g.\n", 0.00001);
	TEST("Double Conv g 0.000001: %g.\n", 0.000001);
	TEST("Double Conv g 0.0000001: %g.\n", 0.0000001);
	TEST("Double Conv g 0.001 with precision 5: %.5g.\n", 0.001);
	TEST("Double Conv g 0.0001 with precision 5: %.5g.\n", 0.0001);
	TEST("Double Conv g 0.00001 with precision 5: %.5g.\n", 0.00001);
	TEST("Double Conv g 0.000001 with precision 5: %.5g.\n", 0.000001);
	TEST("Double Conv g 0.0000001 with precision 5: %.5g.\n", 0.0000001);*/
#endif
	return (0);
}