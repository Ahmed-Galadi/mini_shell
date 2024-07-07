#include "../utils/get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int	input = open("input.txt", O_RDWR);
	if (input == -1)
	{
		printf("error accured!!\n");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", get_next_line(input));
	close(input);
	return (0);
}