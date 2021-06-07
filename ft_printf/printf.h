#include <stdarg.h>
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#include <limits.h>



// - 0 .*

typedef struct		head_fs {
	int		flag_bar;
	int		flag_zero;
	int		width;
	int		precision;
}					type_head; 




int				ft_printf(const char* str, ...);
int				print_fs(char* str, va_list ap);
type_head		put_head_fs(char** str);




//char			is_format_spec(char c);
static int		ft_isspace(char c);

int				ft_atoi(const char* str);
int				count_digit(int num);
void			ft_putnbr(long long nb);

int	print_d_i_affix(long long num, type_head head);
int	print_s_affix(char* str, type_head head);




void		print_c(char* str, type_head head, va_list ap);
void		print_d(char* str, type_head head, va_list ap);
void		print_s(char* str, type_head head, va_list ap);


