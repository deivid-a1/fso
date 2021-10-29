#include <stdio.h>

int main(int argc,char **argv)
{

long int tam1, tam2;
char txt1, txt2;

int flag = 0;

FILE *file1, *file2;
int i;
int j;

for (i = 1; i < argc; i++)
{
    for (j = i+1; j < argc; j++)
    {
        flag = 0;
        file1 = fopen(argv[i], "r");
        file2 = fopen(argv[j], "r");

        fseek(file1, 0, SEEK_END);
        fseek(file2, 0, SEEK_END);

        tam1 = ftell(file1);
        tam2 = ftell(file2);
        
        if(tam1 != tam2)
        {
            printf("%s %s diferentes\n", argv[i], argv[j]);
            fclose(file1);
            fclose(file2);
            continue;
        }
        else
        {
            fseek(file1, 0, SEEK_SET);
            fseek(file2, 0, SEEK_SET);

            for(int k = 0; k < tam2; k++)
            {
                fread(&txt1, 1, 1, file1);
                fread(&txt2, 1, 1, file2);
                
                if(txt1 != txt2)
                {
                    fclose(file1);
                    fclose(file2);
                    flag = 1;
                    printf("%s %s diferentes\n", argv[i], argv[j]);
                    break;
                }
            }
            if(flag == 0)
            {
                printf("%s %s iguais\n", argv[i], argv[j]);
                fclose(file1);
                fclose(file2);
            }
        }
    }
}

return 0;
}