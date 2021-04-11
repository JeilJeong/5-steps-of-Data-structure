#include "../includes/ft_list.h"

void	ft_error_indent(int len)
{
	while (len)
	{
		printf("%c", ' ');
		len--;
	}
}

void	ft_sub_error(char *file, const char *func, int line, char *msg)
{
	ft_error_indent(line_indent);
	printf("%s:%s:%d: %s\n", file, func, line, msg);
	line_indent++;
}

void	ft_main_error(char *file, const char *func, int line, char *msg)
{
	ft_error_indent(line_indent);
	printf("%s:%s:%d: %s\n", file, func, line, msg);
	line_indent = 0;
}