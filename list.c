#include <string.h>
#include <stdio.h>
#include <stdlib.h>


FILE *lCom, *lTotal, *flist;
int correct_last_char(char *line)
{
    size_t length;
    length = strlen(line);
    line[length - 1] = '\0';
    return 0;
}
int writeList(char *file)
{
    int lRet = -1;
    char* line;
    size_t linelen = 0;
    lCom = fopen(file, "r+");
    lTotal = fopen("zzzdictionary.txt", "w");
    if (lCom != NULL)
    {
        if (lTotal != NULL)
        {
            while (getline(&line, &linelen, lCom) != -1)
            {
                fprintf(lTotal, "%s\n", line);
            }
         //   (void) fclose(flist);
        }
        else
        {
            printf("cannot open lTotal\n");
        }
    }
    else
    {
        printf("cannot open %s\n", file);
    }
    return 0;
}
int readList()
{
    int lRet = -1;
    char* line;
    size_t linelen = 0;
    
    flist = fopen("filename.txt", "r+");
    if (flist != NULL)
    {
        while (getline(&line, &linelen, flist) != -1)
        {
            /* need to fix the last character if filename is created by windows */
            correct_last_char(line);
            writeList(line);
        }
        (void) fclose(flist);
    }
    else
    {
        printf("cannot open list file");
    }
    return 0;
}

int main(void)
{
    printf("program begin \n");
    readList();
    return 0;

}