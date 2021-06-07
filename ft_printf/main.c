#include "printf.h"
#include <stdio.h>
int		main(void)
{
	/* char */
	//printf("abc %2c\n", 'd');
	//ft_printf("abc %2c\n\n", 'd');

	//printf("abc %03c\n", 'd');
	//ft_printf("abc %03c\n\n", 'd');

	//printf("abc %.5cq\n", 'd');
	//ft_printf("abc %.5cq\n\n", 'd');

	//printf("abc %.5qc\n", 'd');
	//ft_printf("abc %.5qc\n\n", 'd');

	//char str = 'k';

	//printf("\n<char>\n\n");

	//printf("--%-c/\n", str);
	//ft_printf("--%-c/\n", str);
	//printf("--%-5c/\n", str);
	//ft_printf("--%-5c/\n", str);
	//printf("--%-15c/\n", str)
	//ft_printf("--%-15c/\n", str);
	//printf("\n\n");

	///*flag 순서 바뀌어도 가능*/

	//printf("--%-0c/\n", str);
	//ft_printf("--%-0c/\n", str);
	//printf("--%-05c/\n", str);
	//ft_printf("--%-05c/\n", str);
	//printf("--%0-15c/\n", str);
	//ft_printf("--%0-15c/\n", str);
	//printf("\n\n");



	/* decimal */


	//printf("ab%-5.8d\n", 42); //00000042
	//ft_printf("ab%-5.8d\n", 42);

	//printf("ab%-08d\n", 42);
	//ft_printf("ab%-08d\n", 42);



	//printf("ab%d\n", 011); 
	//ft_printf("ab%d\n\n", 011);

	//printf("ab%-.3d/\n", 011);//009
	//ft_printf("ab%-.3d/\n\n", 011);

	//printf("ab%-10.8d/\n", 011);//000000000009
	//ft_printf("ab%-10.8d/\n\n", 011);

	//printf("ab%-03d/\n", 011);
	//ft_printf("ab%-03d/\n\n", 011);

	//printf("ab%-01d/\n", 011);
	//ft_printf("ab%-01d/\n\n", 011);

	//int a = 8x60;
	//printf("ab%i\n\n", a);
	//ft_printf("ab%d\n\n", a);
	/*
	printf("ab%d\n", 10);
	ft_printf("ab%d\n\n", 10);

	printf("ab%d\n", 010);//8진수 10(8진수) = 8+0 = 8
	ft_printf("ab%d\n\n", 010);

	printf("ab%d\n", 0x10);
	ft_printf("ab%d\n\n", 0x10);
	*/

	//printf("ab%5.8d\n", 42);
	//printf("ab%08d\n", 42);



	//printf("ab%d\n", 011);
	//ft_printf("ab%d\n\n", 011);

	//printf("ab%.3d\n", 011);
	//ft_printf("ab%.3d\n\n", 011);

	//printf("ab%05.8d\n", 011);
	//ft_printf("ab%05.8d\n\n", 011);

	//printf("ab%03d\n", 011);
	//ft_printf("ab%03d\n\n", 011);

	//printf("ab%01d\n", 011);
	//ft_printf("ab%01d\n\n", 011);

	//int a = 0x9c;

	//printf("%d\n", a);
	//printf("%i\n", a);

	//ft_printf("%%d\n\n", a);
	// 
	//printf("ab%d\n", 011);
	//ft_printf("ab%d\n\n", 011);

	//printf("ab%.3d\n", 011);
	//ft_printf("ab%.3d\n\n", 011);

	//printf("ab%05.8d\n", 011);
	//ft_printf("ab%05.8d\n\n", 011);

	//printf("ab%s\n", 011);
	//ft_printf("ab%03d\n\n", 011);

	//printf("ab%01d\n", 011);
	//ft_printf("ab%01d\n\n", 011);


	/*string*/

	char str[10] = "abcdefg";

	printf("--%s\n", str);
	printf("--%5s\n", str);
	printf("--%15s\n", str);// 띄어쓰기 abcdefg
	printf("\n\n");

	printf("--%.5s\n", str);//abcde
	printf("--%.15s\n", str);
	printf("\n\n");

	printf("--%0s\n", str);
	printf("--%05s\n", str);
	printf("--%015s\n", str);//0으로 채우기 abcdefg
	printf("\n\n");

	printf("--%0.5s\n", str);//abcde
	printf("--%0.15s\n", str);
	printf("\n\n");

	printf("--%0s\n", str);



	printf("\n\n<ft_printf>\n\n");

	ft_printf("--%s\n", str);
	ft_printf("--%5s\n", str);
	ft_printf("--%15s\n", str);// 띄어쓰기 abcdefg
	ft_printf("\n\n");

	ft_printf("--%.5s\n", str);//abcde
	ft_printf("--%.15s\n", str);
	ft_printf("\n\n");

	ft_printf("--%0s\n", str);
	ft_printf("--%05s\n", str);
	ft_printf("--%015s\n", str);//0으로 채우기 abcdefg
	ft_printf("\n\n");

	ft_printf("--%0.5s\n", str);//abcde
	ft_printf("--%0.15s\n", str);
	ft_printf("\n\n");

	ft_printf("--%0s\n", str);
	//char str = 'k';

	//printf("\n<bar>\n\n");

	//printf("--%-s/\n", str);
	//printf("--%-5s/\n", str);
	//printf("--%-15s/\n", str);// 띄어쓰기 abcdefg 뒤로
	//printf("\n\n");

	//printf("--%-.5s/\n", str);//abcde
	//printf("--%-.15s/\n", str);
	//printf("\n\n");

	//printf("--%-0s/\n", str);
	//printf("--%-05s/\n", str);
	//printf("--%0-15s/\n", str);//abcdefg 뒤로 띄어쓰기
	//printf("\n\n");

	//printf("--%-0.5s/\n", str);//abcde
	//printf("--%-0.15s/\n", str);
	//printf("\n\n");

	return (0);
}