#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fputs("Invalid arguments. One argument: name of file\n", stderr);
		return -1;
	}
	else
	{
		FILE *f;
		if((f=fopen(argv[1], "w"))==NULL)
		{
			fputs("Can't open the file\n", stderr);
			return -1;
		}
		else
		{
			char symbol = ~'/';
			while (symbol != '/')
			{
				if((symbol = fgetc(stdin)) ==EOF)
				{
					fputs("Can't read the symbol\n", stderr);
					return -1;
				}
				else if(symbol != '/')
				fputc(symbol, f);
			}
			if (fclose(f))
			{
				fputs("Can't close file\n", stderr);
				return -1;
			}
			else return 0; 
		}

	}
}



