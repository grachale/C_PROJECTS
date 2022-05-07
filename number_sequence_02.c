#include <stdio.h>

int main(void)
{
    int position, system, scanfRes;

    printf("Pozice a soustava:\n");

    while ((scanfRes = scanf(" %d %d", &position, &system)) != EOF)
    {
        if (scanfRes != 2 || system != 10 || position < 0)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }

        if (position < 10)
        {
            printf("%d\n^\n", position);
        }
        else
        {
            int reference = 10, k = 2, b = 90, c = 1, num = 10;

            while (position > reference)
            {
                reference = reference + k * b;
                k++;
                b *= 10;
                c++;
            }

            b = 90;
            k = 2;

            if (c == 2)
            {
                position -= 10;
            }
            else
            {
                position -= 10;
                for (int i = c - 1; i > 1; i--)
                {
                    num += b;
                    position -= b * k;
                    b *= 10;
                    k++;
                }
            }
            num = num + position / c;
            printf("%d\n", num);
            for (int space = position % c; space > 0; space--)
            {
                printf(" ");
            }
            printf("^\n");
        }
    }
    return 0;
}
