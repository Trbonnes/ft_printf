# 42 Cursus ft_printf

Extract from the Project Subject :

" This project is pretty straight forward. You will recode printf. Fortunetaly
you will be able to reuse it in future projects as a legit function of your libft. You will
mainly learn how to use variadic arguments. "

---

My ft_printf
===============

### Overview
This project is written in C.
My ft_printf handles : 
- the following conversions : c s p d i u x X n f %
- the following length modifiers : l h ll hh
- the following flag characters : 0 - + *
- the field width and the precision

This project is based on printf  documentation : https://linux.die.net/man/3/printf

### Test
This project is designed to work on MacOS.
To compile the library libftprintf simply run make.
To compile with tests run make test, it will compile the library with this main.c where ft_printf is compared to the real printf.

### Contact
trbonnes@student.42.fr