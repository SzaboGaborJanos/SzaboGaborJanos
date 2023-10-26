#include <stdio.h>
#include <math.h>

void feladat1();
void feladat2();
void feladat3();
void feladat4();
void feladat5();
void feladat6();

int main() {
    int feladatszam;

    printf("Melyik feladatot szeretne megnezni?:\n\t-1.feladat: Masodfoku egyenlet\n\t-2.feladat: Lehetnek a haromszog oldalai\n\t-3.feladat: Milyen nap\n\t-4.feladat: Melyik napon terel haza\n\t-5.feladat: Szokoev-e\n\t-6.feladat: Erdemjegy kalkulator");
    printf("\n\nAdja meg a feladat szamat: ");
    scanf_s("%d", &feladatszam);

    if(feladatszam > 0 && feladatszam < 8){

        switch (feladatszam)
        {
            case 1:
                feladat1();
                break;
            case 2:
                feladat2();
                break
                        ;case 3:
                feladat3();
                break;
            case 4:
                feladat4();
                break;
            case 5:
                feladat5();
                break;
            default:
                feladat6();
                break;

        }
    }
    else{
        printf("Nem letezik ilyen szamu feladat! Bocsi de probald meg ujra! :)");
    }

    return 0;
}

void feladat1(){
    int a, b, c, diszkriminans;
    double gyok1,gyok2;

    printf("1.feladat\n");
    printf("Kerem adja meg a masodfoku egyenlet egyutthatoinak erteket!\n");

    printf("Adja meg a a egyutthato erteket:");
    scanf_s("%d", &a);
    printf("Adja meg a b egyutthato erteket:");
    scanf_s("%d", &b);
    printf("Adja meg a c egyutthato erteket:");
    scanf_s("%d", &c);
    printf("\n");

    diszkriminans = b*b - 4*a*c;

    if (diszkriminans >= 0) {
         gyok1 = (-b + sqrt(diszkriminans)) / (2*a);
         gyok2 = (-b - sqrt(diszkriminans)) / (2*a);

        printf("Az egyenlet valos gyokei: %.2f es %.2f\n", gyok1, gyok2);
    } else {
        printf("Az egyenletnek nincsenek valos gyokei.\n");
    }

}
void feladat2(){
    int a, b, c;

    printf("2.feladat\n");
    printf("Kerem adja meg az a oldal hosszat (a): ");
    scanf_s("%d", &a);

    printf("Kerem adja meg a b oldal hosszat (b): ");
    scanf_s("%d", &b);

    printf("Kerem adja meg a c oldal hosszat (c): ");
    scanf_s("%d", &c);

    if (a + b > c && a + c > b && b + c > a) {
        printf("\nEzek a szamok lehetnek egy haromszog oldalainak ertekei.\n");
    } else {
        printf("\nEzek a szamok nem lehetne egy haromszog oldalainak ertekei.\n");
    }
}
void feladat3(){
    int napSorszam;
    printf("Kerem adja meg a nap sorszamat (1-365): ");
    scanf_s("%d", &napSorszam);

    if (napSorszam >= 1 && napSorszam <= 365) {
        switch (napSorszam%7) {
            case 1:
                printf("Hetfo\n");
                break;
            case 2:
                printf("Kedd\n");
                break;
            case 3:
                printf("Szerda\n");
                break;
            case 4:
                printf("Csutortok\n");
                break;
            case 5:
                printf("Pentek\n");
                break;
            case 6:
                printf("Szombat\n");
                break;
            default:
                printf("Vasarnap\n");
                break;
        }
    } else {
        printf("Ilyen nap mar nincs a naptárban (1-365 napbol all egy ev)!\n");
    }
}
void feladat4(){
    int indulas, tavol, hazateres;

    printf("Melyik napon indulsz? ");
    scanf_s("%d", &indulas);

    printf("Hany napot leszel tavol? ");
    scanf_s("%d", &tavol);

    hazateres = (indulas + tavol) % 7;

    printf("\n");
    switch (hazateres) {
        case 1:
            printf("Hetfon erkezel haza\n");
            break;
        case 2:
            printf("Kedden erkezel haza\n");
            break;
        case 3:
            printf("Szerdan erkezel haza\n");
            break;
        case 4:
            printf("Csutortokon erkezel haza\n");
            break;
        case 5:
            printf("Penteken erkezel haza\n");
            break;
        case 6:
            printf("Szombaton erkezel haza\n");
            break;
        default:
            printf("Vasarnap erkezel haza\n");
            break;

    }

}
void feladat5(){
    int ev;

    printf("5.feladat\n");
    printf("Kerem adja meg az evszamot: ");
    scanf_s("%d", &ev);

    if ((ev % 4 == 0 && ev % 100 != 0) || (ev % 400 == 0)) {
        printf("%d. szokoev.\n", ev);
    } else {
        printf("%d. nem szokoev.\n", ev);
    }
}
void feladat6(){
    int pontszam;

    printf("6.feladat\n");
    printf("Kerem adja meg a dolgozat pontszamot: ");
    scanf_s("%d", &pontszam);

    if (pontszam >= 0 ) {
        if (pontszam >= 90) {
            printf("Erdemjegye: Jeles\n");
        } else if (pontszam >= 80) {
            printf("Erdemjegye: Jo\n");
        } else if (pontszam >= 70) {
            printf("Erdemjegye: Kozepes\n");
        } else if (pontszam >= 60) {
            printf("Erdemjegye: Elegseges\n");
        } else {
            printf("Erdemjegye: Elegtelen\n");
        }
    }
    else{
        printf("Nem megfelelo pontszam nem lehet a pontszama negativ!");
    }
}