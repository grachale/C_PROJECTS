
#include <stdio.h>
#include <stdlib.h> 

#define MAX_LENGTH 1000000

int isThatNumberInArray(int const *array, int number, int to)
{

    for (int i = 0; i <= to; i++)
    {
        if (number == array[i])
            return 1;
    }
    return 0;
}

int main(void)
{

    char sign;
    int scanfRes, ID, from, to, sizeOfArray = 0, *array = (int *)malloc(sizeof(int)), array2[MAX_LENGTH];

    for(int i = 0; i <= MAX_LENGTH - 1; i++){
        array2[i] = 0;
    }

    printf("Pozadavky:\n");

    while ((scanfRes = scanf(" %c", &sign) != EOF))
    {
        if (sign == '+')
        {
            if (scanf(" %d", &ID) != 1 || sizeOfArray + 1 > MAX_LENGTH || ID < 0 || ID > 99999)
            {
                printf("Nespravny vstup.\n");
                return 1;
            } 
            array = (int *) realloc(array,(1 + sizeOfArray) * sizeof(int));
            array[sizeOfArray++] = ID;
            array2[ID]++;

            if (array2[ID] == 1)
            {
                printf("> prvni navsteva\n");
            }
            else
            {
                printf("> navsteva #%d\n", array2[ID]);
            }
            
        }
        else if (sign == '?')
        {
            if (scanf(" %d %d", &from, &to) != 2 || from < 0 || sizeOfArray == -1 || to > sizeOfArray - 1 || from > to)
            {
                printf("Nespravny vstup.\n");
                return 1;
            }
          

           int unique = 0, i = 0, j = 0;

            for (i = from; i <= to; i++)
            {
                for (j = from; j <= i; j++)
                {
                    if (array[j] == array[i])
                    {
                        break; 
                    }
                }
                if (i == j)
                {
                    unique++;
                }
            }



            printf("> %d / %d\n", unique, to - from + 1);
        }
        else
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
    }

    free(array);

    return 0;
}
