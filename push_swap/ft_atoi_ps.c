#include "push_swap.h"

static int		ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int				ft_atoi_ps(const char *str, int *is_null)
{
	int				sign;
	unsigned long	ret;

	sign = 1;
	*is_null = 1;
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
	if (*str != 0)
		return (0);
	if (ret > (unsigned long)__LONG_MAX__ && sign == 1)
		return (0);
	else if (ret > (unsigned long)__LONG_MAX__ + 1 && sign == -1)
		return (0);
	*is_null = 0;
	return ((int)ret * sign);  //(ret * sign)
}
