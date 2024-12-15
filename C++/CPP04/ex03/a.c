#include <stdio.h>
#include <string.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (!((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')) && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i++] -= 32;
        while ((str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			i++;
		}
		while (!((str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'a' && str[i] <= 'z')||
			(str[i] >= 'A' && str[i] <= 'Z')) && str[i] != '\0')
			i++;
	}
	return (str);
}
int main()
{
    // char*str = "isalut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	//char c[1000]="isalut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s",ft_strcapitalize(strdup("isalut, comMent tu vas ? 42mots quarante-deux; cinquante+et+un")));
	return (0);
}