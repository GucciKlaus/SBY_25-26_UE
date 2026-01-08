#include <stdlib.h>

int main(int argc, char **argv)
{
	char *newmemory = malloc(100);
	if (newmemory)
	{
		newmemory[0] = 42;
		char *anothermemory = malloc(100);
		if (anothermemory)
		{
			anothermemory[1] = 42;
			anothermemory[23] = 323;
			anothermemory[100] = 234;
		}
		free(newmemory);
		free(anothermemory);
		return 0;
	}
	return -1;
}
