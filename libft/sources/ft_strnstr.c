#include "libft.h"

int		find_str(const char *ptr, const char *to_find, \
size_t n, int *ptr_idx, int to_find_len)
{
	int		to_find_idx;

	to_find_idx = 0;
	while (ptr[*ptr_idx] == to_find[to_find_idx])
	{
		++*ptr_idx;
		++to_find_idx;
		if (to_find_idx != to_find_len)
			continue;
		return (1);	
	}
	++*ptr_idx;
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	char	*ptr;
	int		to_find_len;
	int		ptr_idx;
	int		result;

	to_find_len =  ft_strlen(to_find);
	ptr = str;
	if (!to_find)
		return (ptr);
	while (ptr_idx < n && ptr[ptr_idx])
	{
		if (find_str(ptr, to_find, n, &ptr_idx, to_find_len))
			return (ptr[ptr_idx - to_find_len]);
	}
	return (0);
}

/*
양을 줄이는 것이 좋은 것인가
빨리 끝내게 하는 것이 좋은건인가
*/