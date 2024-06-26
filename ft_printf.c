/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/08 13:36:46 by raamorim          #+#    #+#             */
/*   Updated: 2024/05/08 13:36:46 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char c, va_list *ap)
{
	int		chars;

	chars = 0;
	if (c == 'c')
		ft_putchar(va_arg(*ap, int), &chars);
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *), &chars);
	else if (c == 'p')
		ft_ptr(va_arg(*ap, unsigned long int), &chars);
	else if (c == 'd' || c == 'i')
		ft_putnbr((long)(va_arg(*ap, int)), &chars);
	else if (c == 'u')
		ft_putnbr_u(va_arg(*ap, unsigned int), &chars);
	else if (c == 'x')
		ft_putnbr_base_x((long)(va_arg(*ap, unsigned int)), &chars);
	else if (c == 'X')
		ft_putnbr_base_x_upper((long)(va_arg(*ap, unsigned int)), &chars);
	else if (c == '%')
		ft_putchar('%', &chars);
	return (chars);
}

static int	verify(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			counter;

	counter = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (verify(FLAGS, (*(str + 1))))
			{
				str++;
				counter += print_format(*str, &ap);
			}
		}
		else
			counter += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (counter);
}

/* int main()
{

	int counter;
	int counter1;
	counter = ft_printf("%X",UINT_MAX);
	printf("\n");
	counter1 = printf("%X", UINT_MAX);
	printf("\n");
	printf("%d", counter);
	printf("\n");
	printf("%d", counter1);
} */
/*  int	main(void)
 {
	int counter;

	counter = ft_printf("%d\n", -1);
	printf("\n");
	printf(" %d\n", -1);
	printf("\n"); */

// 	int counter1;
// 	int counter2;
// 	int counter3;
// 	int counter4;
// 	int counter5;
// 	int counter6;
// 	int counter7;
// 	int counter8;
// 	int counter9;
// 	int counter10;
// 	int counter11;
// 	int counter12;
// 	int counter13;
// 	int counter14;
// 	int counter15;
// 	int counter16;
// 	int counter17;
// 	int counter18;
// 	char *str = "asd";

// 	counter1 = ft_printf("%c\n", 't');
// 	counter2 = ft_printf("NULL %s NULL\n", NULL);
// 	counter3 = ft_printf("%d\n", INT_MAX);
// 	counter4 = ft_printf("%i\n", INT_MAX);
// 	counter5 = ft_printf("%u\n", INT_MAX);
// 	counter6 = ft_printf("%p\n", &str);
// 	counter7 = ft_printf("%x\n", 16);
// 	counter8 = ft_printf("%X\n", INT_MAX);
// 	counter9 = ft_printf("%%\n\n");
// 	counter10 = printf("%c\n", 't');
// 	counter11 = printf("NULL %s NULL\n", NULL);
// 	counter12 = printf("%d\n", INT_MAX);
// 	counter13 = printf("%i\n", INT_MAX);
// 	counter14 = printf("%u\n", INT_MAX);
// 	counter15 = printf("%p\n", &str);
// 	counter16 = printf("%x\n", 16);
// 	counter17 = printf("%X\n", INT_MAX);
// 	counter18 = printf("%%\n");

// 	printf("%d\n", counter1);
// 	printf("%d\n", counter2);
// 	printf("%d\n", counter3);
// 	printf("%d\n", counter4);
// 	printf("%d\n", counter5);
// 	printf("%d\n", counter6);
// 	printf("%d\n", counter7);
// 	printf("%d\n", counter8);
// 	printf("%d\n\n", counter9);
// 	printf("%d\n", counter10);
// 	printf("%d\n", counter11);
// 	printf("%d\n", counter12);
// 	printf("%d\n", counter13);
// 	printf("%d\n", counter14);
// 	printf("%d\n", counter15);
// 	printf("%d\n", counter16);
// 	printf("%d\n", counter17);
// 	printf("%d\n", counter18);
/* } */