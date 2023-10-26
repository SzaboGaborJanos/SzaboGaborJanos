#include <stdio.h>

void feladat1();
void feladat2();
void feladat2_0();
void feladat2_1();
int feladat3();
void feladat4();
void feladat5();

void fibonacci(int);
void homerseklet(float,char);
double celsiusbavaltas(double,char);
double homersekletatvaltas(double,char, char);
int szokoev(int);
int napazevben(int,int,int);


int main() {
    int feladatszam;

    printf("Melyik feladatot szeretne megnezni?:\n\t-1.feladat: Fibonacci sorozat\n\t-2.feladat: Homerseklet atvalto\n\t-3.feladat: Hanyadik nap az evben\n\t-4.feladat: \n\t-5.feladat: ");
    printf("\n\nAdja meg a feladat szamat: ");
    scanf_s("%d", &feladatszam);

    if(feladatszam > 0 && feladatszam < 6){

        switch (feladatszam)
        {
            case 1:
                feladat1();
                break;
            case 2:
                feladat2();
                break;
                case 3:
                feladat3();
                break;
            case 4:
                feladat4();
                break;

            default:
                feladat5();
                break;
        }
    }
    else{
        printf("Nem letezik ilyen szamu feladat! Bocsi de probald meg ujra! :)");
    }

    return 0;
}


void fibonacci(int szam) {
    int a = 0, b = 1, c,i;

    printf("\nFibonacci szamsorozat az elso %d elemig:\n", szam);

    for (i = 0; i < szam; i++) {
        if (i <= 1) {
            c = i;
        } else {
            c = a + b;
            a = b;
            b = c;
        }

        printf("%d, ", c);
    }

    printf("\n");
}
void homerseklet(float ertek,char merteke) {
    if (merteke == 'K') {
        printf("\nAz atvaltott homerseklet: %.2f Kelvin\n", ertek + 273.15);
    } else if (merteke == 'F') {
        printf("\nAz atvaltott homerseklet: %.2f Fahrenheit\n", ertek * 1.8 + 32);
    } else {
        printf("\nHibas meretkegyseg! Kerlek, valassz 'K' vagy 'F' kozul.\n");
    }
}
double celsiusbavaltas(double homerseklet1, char merteke) {
    if (merteke == 'K') {
        return homerseklet1 - 273.15;
    } else if (merteke == 'F') {
        return (homerseklet1 - 32) / 1.8;
    } else {
        return homerseklet1;
    }
}
double homersekletatvaltas(double homerseklet, char mirol, char mire) {
    if (mirol != 'C') {
        homerseklet = celsiusbavaltas(homerseklet, mirol);
    }
    if (mire == 'K') {
        return homerseklet + 273.15;
    } else if (mire == 'F') {
        return (homerseklet * 1.8) + 32;
    } else {
        return homerseklet;
    }
}
int szokoev(int ev) {
    return (ev % 4 == 0 && ev % 100 != 0) || (ev % 400 == 0);
}
int napazevben(int ev, int honap, int nap) {
    int i;
    int nap_honapban[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (szokoev(ev) == 1){
        nap_honapban[2] = 29;
    } else {
        nap_honapban[2] = 28;
    }

    if (honap < 1 || honap > 12 || nap < 1 || nap > nap_honapban[honap]) {
        return -1;
    }

    int napszamolo = nap;
    for (i = 1; i < honap; i++) {
        napszamolo += nap_honapban[i];
    }

    return napszamolo;
}

void feladat1(){
    int szam;

    printf("1.feladat\n");
    printf("Kerem adja meg az meddig szeretne megjeleniteni a Fibonacci sorozatot: ");
    scanf_s("%d", &szam);

    if (szam > 0) {
        fibonacci(szam);
    } else {
        printf("\nA megadott ertek nem megfelelo(legyen egy pozitiv egesz szam).\n");
    }
}
void feladat2(){
    int feladatszam2;

    printf("2.feladat\n");
    printf("Melyik alfeladatot szeretne megnezni?:\n\t-1 feladat: Alapfeladat\n\t-2 feladat: Kiegeszitett");
    printf("\n\nAdja meg az alfeladat szamat: ");
    scanf_s("%d", &feladatszam2);

    if(feladatszam2 > 0 && feladatszam2 < 3) {

        switch (feladatszam2) {
            case 1:
                feladat2_0();
                break;
            case 2:
                feladat2_1();
                break;
            default:
                printf("Nincs ilyen alfeladat!");
                break;
        }
    }
    else{
        printf("Nincs ilyen alfeladatszam!");
    }
}
void feladat2_0(){
    float homersekelt1;
    char merteke;

    printf("Adja meg a Celsius fokot:");
    scanf_s("%f", &homersekelt1);

    printf("Add meg a meretkegyseget (K vagy F): ");
    scanf(" %c", &merteke);

    homerseklet(homersekelt1, merteke);

}
void feladat2_1(){
    double homerseklet;
    char mirol, mire;

    printf("Kerem adja meg a homersekletet(pl:12C): ");
    scanf_s("%lf%c", &homerseklet,&mirol);

    printf("Kerem adja megmire szeretne atvalatani (C,K,F): ");
    scanf(" %c", &mire);

    double atvaltotthomersekelt = homersekletatvaltas(homerseklet, mirol, mire);

    printf("\nAz atvaltott homersekelt: %.2f %c\n", atvaltotthomersekelt, mire);
}
int feladat3(){
    int ev, honap, nap,eredmeny,napszamolo;

    printf("Kerem adja meg az evet, honapot es napot (pl. 2023.10.26): ");
    eredmeny = scanf_s("%d.%d.%d", &ev, &honap, &nap);

    if (eredmeny != 3) {
        printf("Kerem adjon meg rendes datumot!\n");
        return 1;
    }

    if (honap < 1 || honap > 12 || nap < 1 || nap > 31) {
        printf("Nem megfelelo a datum formatum.\n");
        return 1;
    }

    napszamolo = napazevben(ev, honap, nap);
    if(napszamolo == -1){
        printf("Nincs ilyen datum az evben.");
    }
    else{
        printf("Az ev %d. napja.\n", napszamolo);
    }

    return 0;
}
void feladat4(){}
void feladat5(){}