/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:01:21 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 15:01:30 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

/*
#include <sys/types.h>

size_t 자료형은 ‘현 시스템이 한 번에 처리할 수 있는 최대 크기의 unsigned 정수 자료형’ 이고,
ssize_t 자료형은 ‘현 시스템이 한 번에 처리할 수 있는 최대 크기의 signed 정수 자료형’ 이다.


size_t 는 unsigned int 이며, 문자열이나 메모리의 사이즈를 나타낼 때 사용합니다. "unsigned int"를

typedef unsigned int size_t;

이렇게 size_t 라는 이름으로 정의해 놓은 것입니다.

size_t 는, 32비트 운영체제에서는 "부호없는 32비트 정수"이고, 64비트 운영체제에서는 "부호없는 64비트 정수"입니다.

그러나 "unsigned int" 또는 "int"는, 64비트 OS라고 해서 꼭 64비트 정수는 아닙니다. 여전히 32비트일 수도 있습니다. 이것이 size_t형과 "unsigned int"형의 차이입니다.

메모리나 문자열 등의 길이를 구할 때에는 "unsigned int" 대신 size_t 라는 형으로 길이가 반환됩니다.
만약 코드를 그대로 유지한채 컴퓨터 플랫폼이 바뀌면(극단적으로
64bit -> 32bit ) 문제가 생길 여지가 있다.
 이떄를 대비해 typedef되어있는 녀석을 적절할 자료형으로 바꿔
치기를 할 수 있기 때문이다. 이는 코드의 플랫폼 종속성을 제거할
수 있는 코드가 되므로 버릇을 들이는게 좋다.

출처: https://madprog.tistory.com/entry/sizet-구조체와-사용법-편리성 [Mad Programmer]

https://humonnom.tistory.com/entry/sizet%EB%A5%BC-%EC%93%B0%EB%8A%94-%EC%9D%B4%EC%9C%A0

*/

/*
전위 연산자가 후위 연산자보다 효율적인 이유
*/