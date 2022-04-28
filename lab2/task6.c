#include <stdio.h>
#include <dirent.h>

int dirlist(const char *dirname) 
{
	DIR *dir;
	if (!(dir = opendir(dirname))) 
	{
		fputs("Error of opening the directory", stderr);
		return 1;
	}
	struct dirent *d;
	while((d = readdir(dir))) 
	{
		printf("%s\n",d->d_name);
	}
	if (closedir(dir)) 
	{
		fputs("Error of closing the directory", stderr);
		return 1;
	}
	return 0;
}

int main(int argc, char argv[]) 
{
	printf("Current directory:\n");
	dirlist("./");
	printf("\n");
	printf("Root directory:\n");
	dirlist("/");
}


