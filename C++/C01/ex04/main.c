
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* ft_strdup(const char* s)
{
	char* arr;
	int		i;

	i = 0;
    int length = strlen(s); 
    printf("lenghtttttt = %d\n", length);
	// for (int i = 0; i < (sizeof(s) / sizeof(s[0])); i++) {
    //     printf("@%c", s[i]); // Выводим как целое число
    // }
	arr = (char*)malloc(sizeof(char) * (length + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(arr + i) = *(s + i);
		i++;
	}
	*(arr + i) = '\0';
	return (arr);
}
char* foo(void)
{
	char* ptr;

	ptr = (char *)malloc(sizeof(char) * 2);
	ptr[0] = 48;
	ptr[1] = '\0';
	return (ptr);
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char* ft_itoa(int n)
{
	char* arr;
	int		len;
	long	long_n;

	if (n == 0)
		return (foo());
	len = ft_len(n);
	arr =(char *) malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	long_n = (long)n;
	arr[len] = '\0';
	len--;
	if (n < 0)
	{
		arr[0] = '-';
		long_n = -long_n;
	}
	while (long_n != 0)
	{
		arr[len--] = ((long_n % 10) + 48);
		long_n /= 10;
	}
	return (arr);
}
int	check_4_value(char *input_str, char *Ro, int i)
{
	if (i != 0 && input_str[2] == Ro[2] && input_str[3] == Ro[3] && input_str[4] == Ro[4] && input_str[5] == Ro[5])
	{
		i++;
		return (1);
	}
	else
	{
		i++;
		return (-1);
	}
}

int	 if_that_4_value_is_0(char *Ro)
{
	if (Ro[2] == 0 && Ro[3] == 0 && Ro[4] == 0 && Ro[5] == 0)
		return (1);
	return (-1);
}

char* ft_substr(char const* s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char* arr;
    int length = strlen(s);
	j = 0;
	if (!s)
		return (NULL);
    printf("vax=%d\n", length);
	if (length < len + start)
		i = length - start + 1;
	else
		i = len + 1;
	if (start >= length)
		i = 1;
	printf("i ===== %d\n", i);
	arr = (char *)malloc(sizeof(char) * i);
	if (!arr)
		return (NULL);
	while (j < i - 1)
	{
		arr[j] = s[start + j];
		j++;
	}
	arr[j] = '\0';
	 printf("j= %d\n", j);
	printf("ba ste -> %lu\n", sizeof(arr) / sizeof(arr[0]));
	
	return (arr);
}


int func_len_binar_num(int res_num)
{
	int len = 0;
	while (res_num)
	{
		res_num /= 2;
		len++;
	}
	return (len);
}

char *mul_01(char *_R)
{
	printf("ekac _R ");
	for (int i = 0; i < strlen(_R); i++) 
        printf("~%c", _R[i]);
	printf("\n");
	printf("sizeof = %lu\n",strlen(_R));
	int	decimal1 = strtol(_R, NULL, 2);;
	int decimal2 = strtol(_R, NULL, 2);/////ste pti dzvi es mulna sxal
	printf("dec = %d\n", decimal1);
 	int res_num = decimal1 * decimal2;
	printf("res_num  = %d\n", res_num);

	int	len_binar_num = func_len_binar_num(res_num);
	char* res;
	if (len_binar_num == 8)
		res = (char *)malloc(sizeof(char) * (len_binar_num + 1));
	else if (len_binar_num == 7)
		res = (char *)malloc(sizeof(char) * (len_binar_num + 2));
	printf("len binar  = %d\n", len_binar_num);

	int i = 0;
	int temp = len_binar_num;
	if (temp == 7)
	{

		while (res_num >= 0)
		{
			if (res_num % 2 == 0 )
				res[len_binar_num] = '0';
			else
				res[len_binar_num] = '1';
			len_binar_num--;
			if (res_num == 0)
				break ;
			res_num /= 2;
			printf("res = %d\n", res_num);
		}
		printf("stex -> %d\n", len_binar_num);
		printf("incha exe\n");
		if (temp == 7)
		{
			res[temp + 1] = '\0';
		}
		else
			res[temp] = '\0';
	}
	if (temp == 8)
	{
		printf("steenq\n");
		while (res_num > 0)
		{
			if (res_num % 2 == 0 )
				res[len_binar_num - 1] = '0';
			else
				res[len_binar_num - 1] = '1';
			len_binar_num--;
			if (res_num == 0)
				break ;
			res_num /= 2;
			printf("res = %d\n", res_num);
		}
		printf("stex -> %d\n", len_binar_num);
		printf("incha exe\n");
		// if (temp == 7)
		// {
		// 	res[temp + 1] = '\0';
		// }
		// else
			res[temp] = '\0';
	}
	printf("tesnenq    ");
	for (int i = 0; i < strlen(res); i++)
        printf("%c", res[i]);
	return (res);
	printf("binar len = %d\n", len_binar_num);
// //	res = bitset<32>(res_num).to_string();
// 	res = ft_itoa(res_num);
// 	if (sizeof(Ro) / sizeof(Ro[0]) < 8)
// 	{
// 		int i = sizeof(Ro) / sizeof(Ro[0]);
// 		while (i < 8)
// 		{
// 			res[i] = 0;
// 			i++;
// 		}
// 	}
	// return (res);
}



int main()
{
	static int i = 0;
	char	*input_str = ft_strdup("01110001");
    // printf("input = ");
	//  for (int i = 0; i < strlen(input_str); i++) {
    //     printf("%c", input_str[i]); // Выводим как целое число
    // }
    // printf("\n");

	char *Ro = ft_strdup(input_str);
	//     printf("dupic heto Ro ->");
	//  for (int i = 0; i < strlen(Ro); i++) {
    //     printf("%c", Ro[i]); // Выводим как целое число
    // }
    // printf("\n");
	char *_R;
	if (check_4_value(input_str, Ro, i) != 1 && if_that_4_value_is_0(Ro) != 1)
	{
	// 	printf("hrrrr    ");
	// 	for (int i = 0; i < strlen(Ro); i++) {
    //     printf("%c", Ro[i]); // Выводим как целое число
    // }

		_R = ft_substr(Ro, 2, 4);
        printf("_r -> ");
        for (int i = 0; i < strlen(_R); i++)
        {
             printf("^%c", _R[i]); // Выводим как целое число
        }
        printf("\n");
		// printf("groxy tani %lu\n", sizeof(_R));
		Ro = mul_01(_R);
		printf("hly vor senc ->");
        for (int i = 0; i < strlen(Ro); i++) {
            printf("%c", Ro[i]); // Выводим как целое число
    }
	}
    printf("tesnenq -> ");
     for (int i = 0; i < strlen(Ro); i++) {
        printf("%c", Ro[i]); // Выводим как целое число
    }
}

