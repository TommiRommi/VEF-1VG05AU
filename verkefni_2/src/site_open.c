#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#ifdef WIN32
#define Comm 	"start"
#define Break	"\\"
#else
#define Comm	"xdg-open"
#define Break	"/"
#endif

#define Html_File_Path 	"html" Break "website.html"
#define Html_Open		Comm " " Html_File_Path
#define Path(x, y)	x Break y

const char *project_files[] = {
	Html_File_Path, Path("css", "stylesheet.css")
}; 


int main(void)
{
	errno = 0;
	FILE *file_ptr;

	for(int x = 0; x < (int)sizeof(project_files) >> 3; x++)
	{
		if((file_ptr = fopen(project_files[x], "r")) == NULL)
		{
			perror(project_files[x]);
			exit(errno);
		}
		else
		{
			fclose(file_ptr);
		}
	}

	if(system(Html_Open) == -1)
	{
		fprintf(stderr, "something went wrong while executing shell command");	
	}

	return(errno);
}
