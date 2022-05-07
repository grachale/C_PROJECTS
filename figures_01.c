
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>

int isItTriangle(double a, double b, double c)
{
    return !((a + b - c <= DBL_EPSILON * 100 * c) || (a + c - b <= DBL_EPSILON * 100 * b) || (c + b - a <= DBL_EPSILON * 100 * a) || a <= 0 || b <= 0 || c <= 0);
}

int main(void)
{

    char obrazec1, obrazec2;
    double a1, b1, c1, a2, b2, c2, obvod1 = 0, obvod2 = 0, obsah1 = 0, obsah2 = 0;
    char nazev1[20], nazev2[20];

    printf("Obrazec #1\n");
    if (scanf(" %c", &obrazec1) != 1 || (obrazec1 != 'T' && obrazec1 != 'S' && obrazec1 != 'R'))
    {
        printf("Nespravny vstup.\n");
        return 1;
    };

    switch (obrazec1)
    {
    case 'T':
        strcpy(nazev1, "trojuhelnik");
        scanf(" %lf %lf %lf", &a1, &b1, &c1);
        if (isItTriangle(a1, b1, c1))
        {
            obvod1 = a1 + b1 + c1;
            obsah1 = sqrt(obvod1 / 2 * (obvod1 / 2 - a1) * (obvod1 / 2 - b1) * (obvod1 / 2 - c1));
        }
        else
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        break;
    case 'S':
        strcpy(nazev1, "ctverec");
        if (scanf(" %lf", &a1) != 1 || a1 <= 0)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        obvod1 = a1 * 4;
        obsah1 = a1 * a1;
        break;
    case 'R':
        strcpy(nazev1, "obdelnik");
        if (scanf(" %lf %lf", &a1, &b1) != 2 || a1 <= 0 || b1 <= 0 || a1 == b1)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        obvod1 = a1 * 2 + b1 * 2;
        obsah1 = a1 * b1;
        break;
    default:
        printf("Nespravny vstup.\n");
        return 1;
    }

    printf("Obrazec #2\n");
    while (getchar() != '\n')
        continue;
    if (scanf(" %c", &obrazec2) != 1 || (obrazec2 != 'T' && obrazec2 != 'S' && obrazec2 != 'R'))
    {
        printf("Nespravny vstup.\n");
        return 1;
    }

    switch (obrazec2)
    {
    case 'T':
        strcpy(nazev2, "trojuhelnik");
        scanf(" %lf %lf %lf", &a2, &b2, &c2);
        if (a2 <= 0 || b2 <= 0 || c2 <= 0 || !(isItTriangle(a2, b2, c2)))
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        obvod2 = a2 + b2 + c2;
        obsah2 = sqrt(obvod2 / 2 * (obvod2 / 2 - a2) * (obvod2 / 2 - b2) * (obvod2 / 2 - c2));
        break;
    case 'S':
        strcpy(nazev2, "ctverec");
        if (scanf(" %lf", &a2) != 1 || a2 <= 0)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        obvod2 = a2 * 4;
        obsah2 = a2 * a2;
        break;
    case 'R':
        strcpy(nazev2, "obdelnik");
        if (scanf(" %lf %lf", &a2, &b2) != 2 || a2 <= 0 || b2 <= 0 || a2 == b2)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        obvod2 = a2 * 2 + b2 * 2;
        obsah2 = a2 * b2;
        break;
    default:
        printf("Nespravny vstup.\n");
        return 1;
    }

    if (fabs(obvod1 - obvod2) <= DBL_EPSILON * obvod2 * 100)
    {
        printf("Obvod: %s #1 = %s #2\n", nazev1, nazev2);
        if (fabs(obsah1 - obsah2) <= DBL_EPSILON * obsah2 * 100)
        {
            printf("Obsah: %s #1 = %s #2\n", nazev1, nazev2);
        }
        else if (obsah1 > obsah2)
        {
            printf("Obsah: %s #1 > %s #2\n", nazev1, nazev2);
        }
        else
            printf("Obsah: %s #1 < %s #2\n", nazev1, nazev2);
    }
    else if (obvod1 > obvod2)
    {
        printf("Obvod: %s #1 > %s #2\n", nazev1, nazev2);
        if (fabs(obsah1 - obsah2) <= DBL_EPSILON * obsah2 * 100)
        {
            printf("Obsah: %s #1 = %s #2\n", nazev1, nazev2);
        }
        else if (obsah1 > obsah2)
        {
            printf("Obsah: %s #1 > %s #2\n", nazev1, nazev2);
        }
        else
            printf("Obsah: %s #1 < %s #2\n", nazev1, nazev2);
    }
    else
    {
        printf("Obvod: %s #1 < %s #2\n", nazev1, nazev2);
        if (fabs(obsah1 - obsah2) <= DBL_EPSILON * obsah2 * 100)
        {
            printf("Obsah: %s #1 = %s #2\n", nazev1, nazev2);
        }
        else if (obsah1 > obsah2)
        {
            printf("Obsah: %s #1 > %s #2\n", nazev1, nazev2);
        }
        else
            printf("Obsah: %s #1 < %s #2\n", nazev1, nazev2);
    }

    return 0;
}
