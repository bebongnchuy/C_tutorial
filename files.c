#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void testFile(FILE *);
int main()
{
    FILE *fp;
    // testFile(fp);

    char buff[255];
    fp = fopen("questions/intq.json", "r");
    fscanf(fp, "%s", buff);
    printf("1: %s\n", buff);

    fgets(buff, 255, fp);
    printf("2: %s\n", buff);

    fgets(buff, 255, (FILE *)fp);
    printf("3: %s\n", buff);

    fclose(fp);

    return 0;
}
void testFile(FILE *fp)
{
    fp = fopen("questions/test.txt", "a+");

    fprintf(fp, "This is testing for printf....\n");
    fputs("This is testing for fputs...\n", fp);

    fclose(fp);
}

void readFile(FILE *fp)
{
    fp = fopen("questions/test.txt", "r+");

    fprintf(fp, "This is testing for printf....\n");
    fputs("This is testing for fputs...\n", fp);

    fclose(fp);
}
