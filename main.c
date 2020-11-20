#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int     main(int argc, char **argv)
{
	int				fd;
	char			*line;
	int				result;
	unsigned int	count_line;
	(void)			argc;

	fd = open(argv[1], O_RDONLY);
	count_line = 1;
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("STATUS : %i\n", result);
		printf("RETURN : %s\n", line);
		free(line);
		printf("---- \n\n");
		count_line++;
	}

	if (result < 0)
		{
			printf("RETURN ERROR\n");
			return (0);
		}
	printf("STATUS : %i\n", result);
	printf("RETURN : %s\n", line);
	free(line);
	printf("---- \n\n");
	printf("LIGNE LU : %i \n\n", count_line);
	return (0);
}
