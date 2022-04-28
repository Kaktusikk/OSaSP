#include <stdio.h>
#include <stdlib.h>

int main (int argc,char* argv[]) 
{
	if (argc != 3) 
	{ 
		fputs("Invalid arguments:\n 1st argument - name of the file\n 2nd argument - number of lines\n",stderr);
		return -1;
	}
	else 
	{
		int N = strtol(argv[2], NULL, 10);
		if (N < 0) 
		{
			fputs("Invalid argument\n 2nd argument should be above zero\n",stderr);
			return -1;
		}
		else 
		{
			FILE *f;
			if ((f = fopen(argv[1],"r")) == NULL) 
			{
				fputs("Can't open the file\n",stderr);
				return -1;
			} 
			else 
			{
				int i = 0;
				while (!feof(f)) 
				{
					if (N == 0) 
					{
						char symbol = getc(f);
						if (symbol != EOF) putc(symbol,stdout);
					} 
					else 
					{
						if (i == N) 
						{ 
							char key = getc(stdin);
							while (key != '\n') 
								key = getc(stdin);
							i = 0;
						}
						char symbol = getc(f);
						if (symbol != EOF) putc(symbol,stdout);
						if (symbol == '\n') i++;
					}
				}
				putc('\n',stdout);
			}
			if (fclose(f)) 
			{
				fputs("Can't close file\n",stderr);
		        	return -1;
			} 
			else 
				return 0;
			
		}
	}
}

