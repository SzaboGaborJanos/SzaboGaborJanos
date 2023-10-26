#include <stdio.h>
#include <math.h>
void feladat1();
void feladat2();
void feladat3();
void feladat3_1();
void feladat3_2();
void feladat3_3();
void feladat3_4();
void feladat3_5();
void feladat4();
void feladat5();
void collatz(int);
int kodfejtes(int,int);
int primszamfor(int);
int primszamwhile(int);
void idompben(int,int,int);
void idopercben(int,int,int);
void idooraban(int,int,int);
double wallis(int);
double leibniz(int);
double euler (int);

int main() {
    int feladatszam;

    printf("Melyik feladatot szeretne megnezni?\n\t-1.feladat: Collatz szamsorozat\n\t-2.feladat: Kodfejtes\n\t-3.feladat: Primszam-e\n\t-4.feladat: Ido atvaltas\n\t5.feladat: Pi kiszamitasa");
    printf("\nAdja meg a feladat szamat: ");
    scanf_s("%d", &feladatszam);

    if(feladatszam > 0 && feladatszam < 6){

        switch (feladatszam){
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
                printf("Nincs ilyen feladat!");
                break;

        }
    }
    else{
        printf("Nem letezik ilyen szamu feladat! Bocsi de probald meg ujra! :)");
    }
    return 0;
}

void collatz(int ertek) {
    printf("1.elem: %d\n", ertek);
    int i=2;
    while (ertek != 1) {
        if (ertek % 2 == 0) {
            ertek = ertek / 2;
        } else {
            ertek = 3 * ertek + 1;
        }
        printf("%d.elem: %d\n",i, ertek);
        i++;
    }
}
int kodfejtes(int alsoertek,int felsoertek) {
    int osszeg = 0,i;
    for (i = alsoertek; i <= felsoertek; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            osszeg += i;
        }
    }
    return osszeg;
}
int primszamfor(int szam) {
    int i;
    if (szam < 2) {
        return 0;
    }
    for (i = 2; i < szam; i++) {
        if (szam % i == 0) {
            return 0;
        }
    }

    return 1;
}
int primszamwhile(int szam) {
    if (szam < 2) {
        return 0;
    }

    int i = 2;
    while (i < szam) {
        if (szam % i == 0) {
            return 0;
        }
        i++;
    }

    return 1;
}
void idompben(int ora,int perc,int masodperc) {
    int ido_masodpercekben = ora * 3600 + perc * 60 + masodperc;
    printf("\nAz ido masodpercben: %d masodperc.\n", ido_masodpercekben);
}
void idopercben(int ora,int perc,int masodperc) {
    int ido_percekben = ora * 60 + perc + (masodperc > 0 ? 1 : 0);
    printf("Az ido percben: %d perc.\n", ido_percekben);
}
void idooraban(int ora, int perc, int masodperc) {
    int ido_oraban = ora + (perc > 0 || masodperc > 0 ? 1 : 0);
    printf("Az ido oraban: %d ora.\n", ido_oraban);
}
double wallis(int n) {
    double pi = 1.0;
    for (int i = 1; i <= n; i++) {
        pi *= (4.0 * i * i) / ((4.0 * i * i) - 1);
    }
    return 2 * pi;
}
double leibniz(int n) {
    double pi = 0;
    for (int i = 0; i < n; i++) {
        pi += pow(-1, i) * (4.0 / (2 * i + 1));
    }
    return pi;
}
double euler(int n) {
    double pi = 0;
    for (int i = 1; i <= n; i++) {
        pi += 1.0 / (i * i);
    }
    return sqrt(pi * 6);
}

void feladat1() {
    int szam;

    printf("1.feladat\n");
    printf("Kerem adjon meg egy pozitiv egesz szamot: ");
    scanf_s("%d", &szam);

    if (szam <= 0) {
        printf("A megadott szam nem pozitiv egesz.\n");
        return;
    }
    else{
        printf("Szamsorozat:\n");
        collatz(szam);
    }

}
void feladat2() {
    int alsoertek,felsoertek;

    printf("2.feladat\n");
    printf("Adja meg az interrvallum alsoerteket:");
    scanf_s("%d",&alsoertek);
    printf("Adja meg az interrvallum felsoerteket:");
    scanf_s("%d",&felsoertek);

    int kod = kodfejtes(alsoertek,felsoertek);

    printf("\nA "
           "kincseslada kodja:%d", kod);
}
void feladat3(){
    int f3tipusa;

    printf("3.feladat\n");
    printf("Alfeladatok:\n\t1.-For ciklus\n\t2. -While ciklus\n\t3. -Ciklus megszakitas\n\t4. -Ciklus megszakitas nelkul\n\t5. -Valodi osztok megszamlalasaval\n");
    printf("Melyik tipusu megoldast szeretne megnezni?:");
    scanf_s("%d",&f3tipusa);

    if(f3tipusa > 0 && f3tipusa < 6){
        switch (f3tipusa) {
            case 1:
                feladat3_1();
                break;
            case 2:
                feladat3_2();
                break;
            case 3:
                feladat3_3();
                break;
            case 4:
                feladat3_4();
                break;
            case 5:
                feladat3_5();
                break;
            default:
                printf("Nincs ilyen alfeladat!");
                break;
        }
    }
    else{
        printf("Ilyen megoldasi modszere nincs a 3-as feladatnak!");
        return;
    }
}
void feladat3_1(){
    int szam;

    printf("3.1 - For ciklussal\n");
    printf("Kerem adjon meg egy pozitiv egesz szamot: ");
    scanf_s("%d", &szam);

    if (primszamfor(szam)) {
        printf("%d a(z) egy primszam.\n", szam);
    } else {
        printf("%d a(z) nem egy primszam.\n", szam);
    }

}
void feladat3_2(){
    int szam;

    printf("3.2 - While ciklussal\n");
    printf("Kerem adjon meg egy pozitiv egesz szamot: ");
    scanf_s("%d", &szam);

    if (primszamwhile(szam)) {
        printf("%d a(z) egy primszam.\n", szam);
    } else {
        printf("%d a(z) nem egy primszam.\n", szam);
    }


}
void feladat3_3(){
    printf("3.3 - Ciklus megszakitassal");
}
void feladat3_4(){
    printf("3.4 - Cilus megszakitas nelkul");
}
void feladat3_5(){
    printf("3.5 - Valodi osztok megszamolassaval");
}
void feladat4(){
    int ora, perc, masodperc;

    printf("4.feladat\n");

    printf("Kerem adja meg az idot (ora:perc:masodperc formatumban): ");
    scanf_s("%d:%d:%d", &ora, &perc, &masodperc);

    if (ora >= 0 && ora <= 23 && perc >= 0 && perc <= 59 && masodperc >= 0 && masodperc <= 59) {
        idompben(ora, perc, masodperc);
        idopercben(ora, perc, masodperc);
        idooraban(ora, perc, masodperc);
    } else {
        printf("Nem megfelelo az idoformatum.\n");
    }
}
void feladat5(){
    int n = 10000;
    double wallis_eredmeny,leibniz_eredmeny,euler_eredmeny;

    printf("\n");
    printf("Pi erteke:\n");

    wallis_eredmeny = wallis(n);
    printf("\tWallis-fele formula: %f\n", wallis_eredmeny);

    leibniz_eredmeny = leibniz(n);
    printf("\tLeibniz-fele sorozat: %f\n", leibniz_eredmeny);

    euler_eredmeny = euler(n);
    printf("\tEuler-fele szamitas: %f\n", euler_eredmeny);
}