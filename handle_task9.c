#include "main.h"

/**
 * _check_next_flag - handles multiple flags when printing numbers
 * @format: format string
 * @i: index
 * @inputs: input arguments
 * Return: int (chars printed)
 */

int _check_next_flag(const char *format, int *i, va_list inputs)
{
	int has_plus = 0, has_space = 0, has_hash = 0, 
	    has_minus = 0, has_zero = 0;
	int reached_i_or_d = 0, *j;
	int counter = 0, width = -1, c;

	j = i;
	while (reached_i_or_d == 0)
	{
		switch (format[*j])
		{
			case '+':
				has_plus = 1; /*flag*/
				j++; /*check next char for flag*/
				break; /*exit*/
			case ' ':
				has_space = 1;
				j++;
				break;
			case '#':
				has_hash = 1;
				j++;
				break;
			case '-':
				has_minus = 1;
				j++;
				break;
			case '0':
				has_zero = 1;
				j++;
				break;
			case 'i':
			case 'd':
				counter += _print_int_with_flags(inputs, has_plus, 
						has_space, has_hash, has_minus, has_zero, width);
				reached_i_or_d = 1; /*end while loop*/
				break;
			default:
				/*check if it's a number*/
				if ((int)format[*j] < 10 && (int)format[*j] > 0)
				{
					width = (int)format[*j];
					j++;
					break;
				}
				else /*did not end with i / d*/
				{
					_putchar('%');
					counter++;
					for (c = *i; c <= *j; c++)
					{ /*loop through flags to print*/
						_putchar(format[c]);
						counter++;
					} /*for*/
					reached_i_or_d = -1;
				} /*else*/
				break;
			} /*switch*/
		} /*while*/
	return (counter);
} /*check next flag*/

/**
 * _print_int_with_flags - handles multiple flags
 * @inputs:  i
 * @has_plus: i
 * @ has_space: i
 * @has_hash: i
 * @has_minus: i
 * @has_zero: i
 * @width: i
 * Return: int
 */

int _print_int_with_flags( va_list inputs,  int  has_plus, int has_space, int has_hash, 
		int has_minus, int has_zero, int width)
{
	/*order to exe: */
	/* +/space for sign*/
	/*-/0 eiter left justify or leading zeros*/
	/*will use width when doing -/0*/
	int counter = 0, nr;
	char c = ' '; /*the char to buffer with*/

	if (has_zero == 1)
	{
		c = '0';
	}
	nr = va_arg(inputs, int);
	/*handle flags before int*/
	if (width <= 0)
	{ /*no width specified*/
		/* + or space for sign*/
		if (has_plus = 1)
			counter += _print_plus(format, i, inputs);
		else if (has_space = 1)
			counter += _print_space(inputs);
		/*next set: zero, - does nothing without width*/
		if (has_zero = 1)
			counter += _print_zero(inputs);
		/*print int*/
		counter += _print_int(nr);
	}
	else 
	{ /*width specified*/
		/* + or space for sigh*/
		if (has_plus = 1)
			counter += _print_plus(inputs);
		else if (has_space = 1)
			counter += _print_plus(inputs);
		/* next set: pad zero or - left justify*/
		if (has_zero = 1)
			counter += _print_zero_width(inputs, width, counter);
		else if (has_minus = 1)
			counter += _print_minus_width(inputs, width, counter);
		/*print int with width*/
		counter += _print_int(nr, width, c);
	}
	return (counter);
} /*handle multiple flags*/

