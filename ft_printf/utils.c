#include "printf.h"

//char		is_format_spec(char c)
//{
//	if (c == 'c')
//		return ('c');
//	if (c == 's')
//		return ('s');
//	if (c == 'p')
//		return ('p');
//	if (c == 'd')
//		return ('d');
//	if (c == 'i')
//		return ('i');
//	if (c == 'u')
//		return ('u');
//	if (c == 'x')
//		return ('x');
//	if (c == 'X')
//		return ('X');
//	return (0);
//}

static int		ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int				ft_atoi(const char* str)
{
	int				sign;
	unsigned long	ret;

	while (ft_isspace(*str))
		++str;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		ret = (ret * 10) + (*str - '0');
		++str;
	}
	if (ret > (unsigned long)LONG_MAX && sign == 1)
		return (-1);
	else if (ret > (unsigned long)LONG_MAX + 1 && sign == -1)
		return (0);
	return ((int)ret * sign);
}

int		count_digit(int num)
{
	int		ret;

	ret = 1;
	if (ret < 0)
	{
		++ret;
		ret *= -1;
	}
	while (num /= 10)
		++ret;
	return (ret);
}



static void		print(long long nb)
{
	char a;

	a = nb % 10 + 48;
	nb = nb / 10;
	if (nb > 0)
		print(nb, 1);
	_write(1, &a, 1);
}

void			ft_putnbr(long long nb)
{
	if (nb == -(long long)2147483648)
		_write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb *= -1;
		_write(1, "-", 1);
		print(nb);
	}
	else
		print(nb);
}


//진수 변환 넣기

void	ft_put_affix(int num, char c)
{
	while (num--)
		_write(1, &c, 1);
}


size_t		ft_strlen(const char* s)
{
	size_t	ret;

	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}