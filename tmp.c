#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RET_TRUE 1
#define RET_FALSE 0
#define INPUT_FILE_PATH "inputNodeList.txt"

/* Global parameter */
FILE *p;

int openFile(char *filePATH)
{
    p = fopen(filePATH, "r");
    if (p == NULL)
    {
        printf("Error Path\n");
        return RET_FALSE;
    }

    return RET_TRUE;
}

void closeFile(FILE *p)
{
	(void) fclose(p);
}

char* readLine(FILE *p)
{
    int retVal = -1;
    char *str = NULL;
	size_t len = 0;
	
    retVal = getline(&str, &len, p);
    if (retVal == -1)
    {
        printf("Cannot read line in stream \n");
        return NULL;
    }

	//printf ("String %s\n", str);
    return str;
}

void getInput(char *str)
{
	size_t len = 0;
	
	len = strlen(str);
	if(str[len-3] == ':')
	{
		printf("%s", str);
	}
	else
	{
		printf("####%s", len, str[len-3], str);
	}
}

void main()
{
    char *str;
    openFile(INPUT_FILE_PATH);
    do 
    {
        str = readLine(p);
		getInput(str);
        //printf("%s", str);
    } while(str != NULL);
	
	closeFile(p);
}