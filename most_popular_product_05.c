#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_OF_THE_NAME 99

typedef struct item
{
    char name[LENGTH_OF_THE_NAME];
    int count;
} Item;

int is_that_item_saved(Item *array, char *name, int size_of_array, int *number_of_the_element)
{
    for (int i = 0; i <= size_of_array - 1; i++)
    {
        if (!strcmp(array[i].name, name))
        {
            *number_of_the_element = i;
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int N, resScanf, size_of_array = 0, saled = 0;
    char request_sign;

    Item *sorted_count_array = (Item *)malloc(sizeof(Item));

    printf("Pocet sledovanych:\n");
    if (scanf(" %d", &N) != 1 || N <= 0)
    {
        free(sorted_count_array);
        printf("Nespravny vstup.\n");
        return 1;
    }

    printf("Pozadavky:\n");

    while ((resScanf = scanf(" %c", &request_sign)) != EOF)
    {
        if (request_sign == '+')
        {
            char temp_name[110];
            if (scanf(" %s", temp_name) != 1 || strlen(temp_name) > LENGTH_OF_THE_NAME)
            {
                free(sorted_count_array);
                printf("Nespravny vstup.\n");
                return 1;
            }

            int number_of_the_element = 0;
            if (is_that_item_saved(sorted_count_array, temp_name, size_of_array, &number_of_the_element))
            {
                sorted_count_array[number_of_the_element].count++;
                while (number_of_the_element - 1 >= 0 && sorted_count_array[number_of_the_element].count > sorted_count_array[number_of_the_element - 1].count)
                {
                    Item temp = sorted_count_array[number_of_the_element - 1];
                    sorted_count_array[number_of_the_element - 1] = sorted_count_array[number_of_the_element];
                    sorted_count_array[number_of_the_element] = temp;
                    number_of_the_element--;
                }
            }
            else
            {
                sorted_count_array = (Item *)realloc(sorted_count_array, (1 + size_of_array) * sizeof(Item));
                strcpy(sorted_count_array[size_of_array].name, temp_name);
                sorted_count_array[size_of_array].count = 1;
                size_of_array++;
            }

            // counting saled products
            saled = 0;
            int i = 0;
             while (i <= size_of_array - 1 && i <= N - 1)
            {
                int j = 0;
                if (i + 1 <= size_of_array - 1 && sorted_count_array[i].count == sorted_count_array[i + 1].count)
                {
                    j = i + 1;
                    while (j + 1 <= size_of_array - 1 && sorted_count_array[j].count == sorted_count_array[j + 1].count)
                    {
                        j++; 
                    }
                }
                if (j == 0)
                {
                    saled += sorted_count_array[i].count;
                    i++;
                }
                else
                {
                    for (int p = i; p <= j; p++, i++)
                    {
                        saled += sorted_count_array[p].count;
                    }
                }
            }
    
        }
        else if (request_sign == '#')
        {
            int i = 0;
            while (i <= size_of_array - 1 && i <= N - 1)
            {
                int j = 0;
                if (i + 1 <= size_of_array - 1 && sorted_count_array[i].count == sorted_count_array[i + 1].count)
                {
                    j = i + 1;
                    while (j + 1 <= size_of_array - 1 && sorted_count_array[j].count == sorted_count_array[j + 1].count)
                    {
                        j++; 
                    }
                }
                if (j == 0)
                {
                    printf("%d. %s, %dx\n", i + 1, sorted_count_array[i].name, sorted_count_array[i].count);
                    i++;
                }
                else
                {
                    int permanent = i;
                    for (int p = i; p <= j; p++)
                    {
                        printf("%d.-%d. %s, %dx\n", permanent + 1, j + 1, sorted_count_array[p].name, sorted_count_array[p].count);
                        i++;
                    }
                }
            }

            printf("Nejprodavanejsi zbozi: prodano %d kusu\n", saled);
        }
        else if (request_sign == '?')
        {
            printf("Nejprodavanejsi zbozi: prodano %d kusu\n", saled);
        }
        else
        {
            free(sorted_count_array);
            printf("Nespravny vstup.\n");
            return 1;
        }
    }


    free(sorted_count_array);


    return 0;
}
