#include <stdio.h> 

int main(void)
{
    char citata1[] = "Qapla'\nnoH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.";
    char citata2[] = "Qapla'\nQu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.";
    char citata3[] = "Qapla'\nqaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.";
    char citata4[] = "Qapla'\nHa'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.";
    char citata5[] = "Qapla'\nleghlaHchu'be'chugh mIn lo'laHbe' taj jej.";
    int vstup; 

    printf("ml\' nob:\n");

    if (scanf("%d", &vstup) != 1 || vstup > 5 || vstup < 1)
    {
        printf("luj\n"); 
        return 1;
    } 

    switch (vstup){
        case 1:
        printf("%s\n", citata1);
        break;
        case 2:
        printf("%s\n", citata2);
        break;
        case 3:
        printf("%s\n", citata3);
        break;
        case 4:
        printf("%s\n", citata4);
        break;
        default:
        printf("%s\n", citata5);
        break;
    }
    return 0; 
}
