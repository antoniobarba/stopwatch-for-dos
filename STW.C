#include <stdio.h>
#include <time.h>
#include <process.h>
int main(int argc, char **argv)
{
	time_t start, finish;
	if (argc == 1)
	{
		printf("Usage: stw <command arg1 arg2... argN>");
		return 0;
	}
	start = time(NULL);

	// build a command string
	{
		int size=0, i;
		char* com = NULL;

		for (i=1; i<argc; ++i)
		{
			int argsize = strlen(argv[i]);
			com = (char*)realloc(com, size+argsize+2);
			sprintf(com + size, "%s ", argv[i]);
			size += argsize + 1;
		}
		//printf(com);
		system(com);
	}

	printf("\n");
	finish = time(NULL);
	printf("Elapsed time: %ld seconds", finish-start);
	return 0;
}
