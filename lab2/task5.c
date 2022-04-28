#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[]) {
	if (argc != 3) 
	{ 
		fputs("Invalid arguments:\n 1st argument - name of the 1st file\n 2nd argument - name of the 2nd file\n",stderr);
		return -1;
	} 
	else 
	{
		FILE *f1, *f2;
		if ((f1 = fopen(argv[1],"r")) == NULL) 
		{
			fputs("Can't open the 1st file\n",stderr);
			return -1;
		} 
		else if ((f2 = fopen(argv[2],"w")) == NULL) 
		{
			fputs("Can't open the 2nd file\n",stderr);
			return -1;
		} 
		else 
		{
			struct stat buf1;
			if (stat (argv[1], &buf1) == -1) 
			{
				fputs("Unable to fill stat structure\n",stderr);
				return -1;
			} 
			else 
			{
				while (!feof(f1)) 
				{
					char c = getc(f1);
					if (c != EOF) putc(c,f2);
				}
				chmod(argv[2], buf1.st_mode);
				if (fclose(f1)) 
				{
					fputs("Can't close the 1st file\n",stderr);
					return -1;
				} else if (fclose(f2)) {
					fputs("Can't close the 2nd file\n",stderr);
					return -1;
				} 
				else 
					return 0;
			}
		}
	}	
}
