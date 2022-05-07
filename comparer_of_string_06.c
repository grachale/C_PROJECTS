#ifndef __PROGTEST__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#endif /* __PROGTEST__ */

typedef struct
{
    char * word;
} WORDS;

int sameWords(const char *a, const char *b)
{
    int memory_for_a = 10, memory_for_b = 10;
    int number_of_words_a = 0, number_of_words_b = 0;

    WORDS *a_sorted = (WORDS *)malloc(memory_for_a * sizeof(*a_sorted));
    WORDS *b_sorted = (WORDS *)malloc(memory_for_b * sizeof(*b_sorted));


    const char *delimeters = "1234567890\t\n.,;:'\"<>{}[]\\!@#$%ˆ&*()_+=-`~§± |";

    char *dup_a = strdup(a);
    char *token1 = strtok(dup_a, delimeters);

    while (token1 != NULL)
    {
        int length_of_token = strlen(token1);
        for (int i = 0; i < length_of_token; i++)
        {
            token1[i] = tolower(token1[i]);
        }
        if (number_of_words_a >= memory_for_a - 1)
        {
            memory_for_a += 10;
            a_sorted = (WORDS *)realloc(a_sorted, memory_for_a * sizeof(*a_sorted));
        }
        a_sorted[number_of_words_a++].word = token1;
        token1 = strtok(NULL, delimeters);
    }

    char *dup_b = strdup(b);
    char *token2 = strtok(dup_b, delimeters);

     while (token2 != NULL)
    {
        int length_of_token = strlen(token2);
        for (int i = 0; i < length_of_token; i++)
        {
            token2[i] = tolower(token2[i]);
        }
        if (number_of_words_b >= memory_for_b - 1)
        {
            memory_for_b += 10;
            b_sorted = (WORDS *)realloc(b_sorted, memory_for_b * sizeof(*b_sorted));
        }
        b_sorted[number_of_words_b++].word = token2;
        token2 = strtok(NULL, delimeters);
    } 

    for (int i = 0; i < number_of_words_a; i++)
    {
        int is_word_in_b = 0;
        for (int j = 0; j < number_of_words_b; j++)
        {
            if (!strcmp(a_sorted[i].word, b_sorted[j].word))
            {
                is_word_in_b++;
                break;
            }
        }
        if (!is_word_in_b)
        {

            free(a_sorted);
            free(dup_a);
            free(dup_b);
            free(b_sorted);
            return 0;
        }
    }

    for (int i = 0; i < number_of_words_b; i++)
    {
        int is_word_in_a = 0;
        for (int j = 0; j < number_of_words_a; j++)
        {
            if (!strcmp(b_sorted[i].word, a_sorted[j].word))
            {
                is_word_in_a++;
                break;
            }
        }
        if (!is_word_in_a)
        {
            free(a_sorted);
            free(dup_a);
            free(dup_b);
            free(b_sorted);
            return 0;
        }
    }
     free(a_sorted);
            free(dup_a);
            free(dup_b);
            free(b_sorted);
            return 1;
}

#ifndef __PROGTEST__
int main(int argc, char *argv[])
{
    assert(sameWords("Hello students.", "HELLO studEnts!") == 1);
    assert(sameWords(" He said 'hello!'", "'Hello.' he   said.") == 1);
    assert(sameWords("He said he would do it.", "IT said: 'He would do it.'") == 1);
    assert(sameWords("one two three", "one two five") == 0);

    assert(sameWords("He said he wouldsdfjkdsjkf do it.", "IT said: 'He wouldsdfjkdsjkf do it.wouldsdfjkdsjkf'") == 1);


    return 0;
}
#endif /* __PROGTEST__ */
