#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

extern char **environ;

int main(int argc, char *argv[])
{
  int  count = 0;
  char line[128]= {0};;
  
  FILE *f = NULL;

    if (f = fopen("./TZ", "r") ) {
        if (fgets(line, sizeof(line), f) && strlen(line) ){
            if (line[strlen(line)-1] == '\n')
                line[strlen(line)-1] = '\0';

            char *val = getenv("USER");

            if ( val )
                printf("\n\nCurrent value of environment variable USER is [%s]\n",val);
            else
                printf("\n\nCurrent value of environment variable USER is NULL\n");


            if(setenv("USER",line,1))
            {
                printf("\n setenv() failed\n");
                return 1;
            }

            printf("\n Successfully Added a new value to existing environment variable USER\n");

            val = getenv("USER");
            if ( val )
                printf("\n\nCurrent value of environment variable USER is [%s]\n",val);
            else
                printf("\n\nCurrent value of environment variable USER is NULL\n");
            
        }
        
        fclose(f);
    }
  
  return 0;
}


