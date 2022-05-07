#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int isItSleapYear(int year)
{
    if ((year % 400 == 0 && year % 4000 != 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;
}

void
consumptionForOneDay (int h1, int i1, int h2, int i2,
                      long long int *consumption)
{
    int data2[] = { 4, 5, 2, 3, 3, 1, 5, 4, 1 };

    int q, k, m, l, q2, k2, m2, l2;



    k = h1 % 10;
    h1 /= 10;
    k2 = h2 % 10;
    h2 /= 10;
    q = h1 % 10;
    q2 = h2 % 10;
    l = i1 % 10;
    i1 /= 10;
    l2 = i2 % 10;
    i2 /= 10;
    m = i1 % 10;
    m2 = i2 % 10;


    for (; q < q2; q++)
    {
        for (; k < 10; k++)
        {
            for (; m < 6; m++)
            {
                for (; l < 9; l++)
                    *consumption += 200 + data2[l];
                l = 0;
                if (m != 5)
                {
                    *consumption = *consumption + 200;
                    *consumption = *consumption + 2;
                    *consumption += data2[m];
                }
            }
            m = 0;
            if (k != 9)
            {
                *consumption += 200;
                *consumption = *consumption + 3 + 2;
                *consumption += data2[k];
            }
        }
        k = 0;
        *consumption += 200;
        *consumption = *consumption + 2 + 3 + 2;
        *consumption += data2[q];


    }


    for (; k < k2; k++)
    {

        for (; m < 6; m++)
        {
            for (; l < 9; l++)
            {
                *consumption += 200 + data2[l];
            }
            l = 0;
            if (m != 5)
            {
                *consumption = *consumption + 200;
                *consumption = *consumption + 2;
                *consumption += data2[m];
            }
        }
        m = 0;

        *consumption += 200;
        *consumption = *consumption + 3 + 2;
        *consumption += data2[k];

    }


    for (; m < m2; m++)
    {

        for (; l < 9; l++)
        {
            *consumption += 200 + data2[l];
        }
        l = 0;

        *consumption = *consumption + 200;
        *consumption = *consumption + 2;
        *consumption += data2[m];
        if (m == m2)
        {
            l = 0;
        }

    }


    for (; l < l2; l++)
    {
        *consumption += 200 + data2[l];

    }
}


int dateToIndex(int day, int month, int year, int *idx, int *i)
{

    if ((year % 400 == 0 && year % 4000 != 0) || (year % 4 == 0 && year % 100 != 0))
        *i = 1;
    if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31 || day < 1)) || ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1)) || (month == 2 && (day > 28 + *i || day < 1)))
        return 1;
    switch (month)
    {
    case 1:
        *idx = day;
        return 0;
    case 2:
        *idx = day + 31;
        return 0;
    case 3:
        *idx = 59 + *i + day;
        return 0;
    case 4:
        *idx = 90 + *i + day;
        return 0;
    case 5:
        *idx = 120 + *i + day;
        return 0;
    case 6:
        *idx = 151 + *i + day;
        return 0;
    case 7:
        *idx = 181 + *i + day;
        return 0;
    case 8:
        *idx = 212 + *i + day;
        return 0;
    case 9:
        *idx = 243 + *i + day;
        return 0;
    case 10:
        *idx = 273 + *i + day;
        return 0;
    case 11:
        *idx = 304 + *i + day;
        return 0;
    case 12:
        *idx = 334 + *i + day;
        return 0;
    }
    return 0;
}


int energyConsumption(int y1, int m1, int d1, int h1, int i1,
                      int y2, int m2, int d2, int h2, int i2,
                      long long int *consumption)
{
    *consumption = 0;
    if (y1 < 1600 || y2 < 1600 || m1 < 1 || m1 > 12 || m2 > 12 || m2 < 1 ||
        h1 < 0 || h1 > 23 || h2 < 0 || h2 > 23 ||
        i1 < 0 || i1 > 59 || i2 < 0 || i2 > 59)
        return 0;

    if (y1 > y2 || (y1 >= y2 && m1 > m2) || (m1 >= m2 && y1 >= y2 && d1 > d2) || (d1 >= d2 && m1 >= m2 && y1 >= y2 && h1 > h2) || (d1 >= d2 && m1 >= m2 && y1 >= y2 && h1 >= h2 && i1 > i2))
        return 0;

    int idx1 = 0, idx2 = 0, p1 = 0, p2 = 0;

    if (dateToIndex(d1, m1, y1, &idx1, &p1) || dateToIndex(d2, m2, y2, &idx2, &p2))
        return 0;

    int deltaD,  years = 0;


    if (y1 == y2)
    {

        deltaD = idx2 - idx1;
    }
    else
    {
        deltaD = ((365 + p1) - idx1) + idx2;
        y1++;
        while (y1 != y2){
            y1++;
            years++;
            if (isItSleapYear(y1))
            {
                deltaD++;
            }
        }
    }

    if (h1 > h2 || i1 > i2)
    {
        deltaD = deltaD - 1;
        *consumption += (long long int)(years) * 106903390 + deltaD * 292886 + 211;
        consumptionForOneDay(h1, i1, 23, 59, consumption);
        consumptionForOneDay(0, 0, h2, i2, consumption);
        return 1;
    }
    else
    {
        *consumption += (long long int)(years) * 106903390 + deltaD * 292886;
        consumptionForOneDay(h1, i1, h2, i2, consumption);
        return 1;
    }
}

#ifndef __PROGTEST__
int main(int argc, char *argv[])
{
    long long int consumption = 0;

    assert(energyConsumption(2021, 10, 1, 13, 15,
                             2021, 10, 1, 18, 45, &consumption) == 1 &&
           consumption == 67116LL);
    assert(energyConsumption(2021, 10, 1, 13, 15,
                             2021, 10, 2, 11, 20, &consumption) == 1 &&
           consumption == 269497LL);
    assert(energyConsumption(2021, 1, 1, 13, 15,
                             2021, 10, 5, 11, 20, &consumption) == 1 &&
           consumption == 81106033LL);
    assert(energyConsumption(2024, 1, 1, 13, 15,
                             2024, 10, 5, 11, 20, &consumption) == 1 &&
           consumption == 81398919LL);
    assert(energyConsumption(1900, 1, 1, 13, 15,
                             1900, 10, 5, 11, 20, &consumption) == 1 &&
           consumption == 81106033LL);
    assert(energyConsumption(2021, 10, 1, 0, 0,
                             2021, 10, 1, 12, 0, &consumption) == 1 &&
           consumption == 146443LL);
    assert(energyConsumption(2021, 10, 1, 0, 15,
                             2021, 10, 1, 0, 25, &consumption) == 1 &&
           consumption == 2035LL);
    assert(energyConsumption(2021, 10, 1, 12, 0,
                             2021, 10, 1, 12, 0, &consumption) == 1 &&
           consumption == 0LL);
    assert(energyConsumption(2021, 10, 1, 12, 0,
                             2021, 10, 1, 12, 1, &consumption) == 1 &&
           consumption == 204LL);
    assert(energyConsumption(2021, 11, 1, 12, 0,
                             2021, 10, 1, 12, 0, &consumption) == 0);
    assert(energyConsumption(2021, 10, 32, 12, 0,
                             2021, 11, 10, 12, 0, &consumption) == 0);
    assert(energyConsumption(2100, 2, 29, 12, 0,
                             2100, 2, 29, 12, 0, &consumption) == 0);
    assert(energyConsumption(2400, 2, 29, 12, 0,
                             2400, 2, 29, 12, 0, &consumption) == 1 &&
           consumption == 0LL);

    energyConsumption(2010, 4, 17, 1, 0,
                      2010, 4, 16, 1, 0, &consumption);

    printf("%lld\n", consumption);

    return 0;
}
#endif /* __PROGTEST__ */
