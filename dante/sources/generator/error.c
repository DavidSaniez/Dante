/*
** EPITECH PROJECT, 2018
** error
** File description:
** By DavidS
*/

int good_dimensions(char *x, char *y)
{
	for (int i = 0; x[i] != '\0'; i++) {
		if (x[i] < '0' || x[i] > '9')
			return (-1);
	}
	for (int i = 0; y[i] != '\0'; i++) {
		if (y[i] < '0' || y[i] > '9')
			return (-1);
	}
	return (0);
}

int my_strcmp(const char *str1, const char *str2)
{
	int i = 0;
	
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str1[i] != str2[i])
		return (1);
	return (0);
}
