#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-branch-clone"
#include <stdio.h>

void feladat1();
void feladat2();
void feladat3();
void feladat4();
void feladat5();
void feladat6();
void feladat7();
int szokoev(int ev);
void melyikszokoev(int elsoevszam,int masodikevszam);

int main() {
    int feladatszam;

    printf("Melyik feladatot szeretne megnezni?:\n\t-1.feladat: Szokoev szamitas\n\t-2.feladat: Fakatoialiszamitas\n\t-3.feladat: Hatvanyozas\n\t-4.feladat: Ket szam osszeadasa\n\t-5.feladat: Telefonszamla kalkulator\n\t-6.feladat: Visszajaro kalkulator\n\t-7.feladat: Alap szamologep");
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
                case 6:
                    feladat6();
                    break;
                default:
                    feladat7();
                    break;
            }
    }
    else{
        printf("Nem letezik ilyen szamu feladat! Bocsi de probald meg ujra! :)");
    }

        return 0;
}

int szokoev(int ev) {
    if ((ev % 4 == 0 && ev % 100 != 0) || (ev % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}
void melyikszokoev(int elsoevszam,int masodikevszam) {
    int ev,i=1;
    printf("Szokoevek %d-%d:\n", elsoevszam, masodikevszam);
    for (ev = elsoevszam; ev <= masodikevszam; ev++) {
        if (szokoev(ev)) {
            printf("\t%d. szokoev - %d \n",i, ev);
            i++;
        }

    }
    printf("\n");
}

void feladat1(){
    int elsoevszam, masodikevszam;

    printf("1.feladat\n");
    printf("Kerem adja meg az elso evszamot:");
    scanf_s("%d", &elsoevszam);

    printf("Kerem adja meg az utolso evszamot:");
    scanf_s("%d", &masodikevszam);

    melyikszokoev(elsoevszam, masodikevszam);
}
void feladat2 () {
    //----------2.feladat:Faktorialis szamitas

    int i,faktorialis=0, szam=1;
    printf("2.feladat\n");
    printf("Kerem addjon meg egy egesz szamot 1-10 kozott: ");
    scanf_s("%d", &faktorialis);


    if(faktorialis > 0 && faktorialis < 10){
        for (i=1;i<=faktorialis;++i){
            szam*=i;
        }
        printf("\n%d - Faktorialisa: %d",i-1, szam);
    }
    else{
        printf("A szam nem megfelelo kerem 1-10 kozott levo egesz szamot adjon meg! ");
    }
}
void feladat3 (){
    //--------3.feladat: Hatványozás

    int i, kitevo, hatvanyalap,eredmeny = 1;

    printf("3.feladat\n");
    printf("Kerem adja meg a hatvanyalap erteket:\n");
    scanf_s("%d", &hatvanyalap );
    printf("Kerem adja meg a kitevo ereteket:\n");
    scanf_s("%d", &kitevo);

    if (kitevo > 0 && hatvanyalap >= 0) {
        for (i = 0; i < kitevo; ++i){
            eredmeny *= hatvanyalap;
        }
    }
    else if(kitevo == 0){
        printf("A(z) %d %d. hatvanya = 1",hatvanyalap,kitevo);
    }
    else{
        printf("Nem megfelelo szamot adott meg.");
    }

    printf("A %d %d.hatvanya = %d",hatvanyalap,kitevo,eredmeny);
}
void feladat4 () {
//---------4.feladat
int szam,osszeg = 0;
    char bekeres;
    int i;
    printf("4.feladat\n");
    printf("Adja meg az 1. szamot (q-val befejez):");

    for (i = 1; 1; i++) {
        if (scanf_s("%d",&szam) == 1) {
            osszeg += szam;
            printf("\tAz eddigi szamok osszege: %d\n", osszeg);
        } else {
            scanf(" %c", &bekeres);
            if (bekeres == 'q') {
                break;
            }
        }
        printf("Adja meg az %d. szamot (q-val befejez):", i + 1);
    }

    printf("\tA szamok vegosszege: %d", osszeg);
}
void feladat5 () {
    //-----------5.feladat
    int hivastipus, idotartama = 1, ara = 0;
    char bekeres;

    printf("5.feladat\n");
    printf("Telefonszamla keszito:\n");
    printf("\t 1.Beloldi hivas * 2.Halozaton kivuli * 3.Kulfoldi * q.Vege a szamlanak\n");

    do {
        idotartama = 0;

        printf("Adja meg milyen tipusu a hivas (1-3), vagy q a vegehez: ");
        scanf(" %c", &bekeres);

        if (bekeres == 'q') {
            printf("Lezarult a szamlazas!");
            break;
        }

        if (bekeres >= '1' && bekeres <= '3') {
            hivastipus = bekeres - '0';

            printf("Adja meg hany percet telefonalt:");
            scanf_s("%d", &idotartama);

            switch (hivastipus) {
                case 3:
                    ara += idotartama * 100;
                    break;
                case 2:
                    ara += idotartama * 60;
                    break;
                default:
                    ara += idotartama * 40;
                    break;
            }
            printf("Eddigi szamla ertekeke: %d Ft\n\n", ara);
        } else {
            printf("Hibas tipus. Kerek 1-3 kozotti szamot.\n\n");
        }
    } while (1);

    printf("\n\n A szamlaja vegosszege: %d Ft", ara);
}
void feladat6 () {
    //--------6.feladat
    int fizetett, visszajaro, maradek;
    int fizetett2, feltetel, szamol200 = 0, szamol100 = 0, szamol50 = 0, szamol20 = 0, szamol10 = 0, szamol5 = 0;

    printf("6.feladat\n");
    printf("Adja meg mennyi a visszajaro(5-el oszthatora kerekitve): ");
    scanf_s("%d", &fizetett);
    maradek = fizetett % 5;

    if (maradek != 0) {
        printf("Rossz a visszajaro osszege. Az osszegnek oszthatonak kell lennie 5-el.\n");
        return; // Függvényből való kilépés
    }
    fizetett2 = fizetett;
    do {
        if(fizetett2 / 5 >= 40) {
            feltetel = 1;
        } else if(fizetett2 / 5 <=39 && fizetett2 / 5 >= 20){
            feltetel = 2;
        } else if(fizetett2 / 5 <=19 && fizetett2 / 5 >= 10){
            feltetel = 3;
        } else if(fizetett2 / 5 <= 9 && fizetett2 / 5 >= 4){
            feltetel = 4;
        } else if(fizetett2 / 5 <=3 && fizetett2 / 5 >= 2){
            feltetel = 5;
        } else if(fizetett2 / 5 == 1) {
            feltetel = 6;
        }

        switch (feltetel){
            case 1:
                fizetett2 -= 200;
                szamol200++;
                break;

            case 2:
                fizetett2 -= 100;
                szamol100++;
                break;

            case 3:
                fizetett2 -= 50;
                szamol50++;
                break;

            case 4:
                fizetett2 -= 20;
                szamol20++;
                break;

            case 5:
                fizetett2 -= 10;
                szamol10++;
                break;

            default:
                fizetett2 -= 5;
                szamol5++;
                break;
        }
    } while (fizetett2 > 0);

    printf("Legkevesebb ermebol kifizetni:\n");
    printf("Cimlett:200 -> %d x 200 = %d Ft\n",szamol200,szamol200*200);
    printf("Cimlett:100 -> %d x 100 = %d Ft\n",szamol100,szamol100*100);
    printf("Cimlett:50  -> %d x 50  = %d Ft\n",szamol50,szamol50*50);
    printf("Cimlett:20  -> %d x 10  = %d Ft\n",szamol20,szamol20*20);
    printf("Cimlett:10  -> %d x 20  = %d Ft\n",szamol100,szamol10*10);
    printf("Cimlett:5   -> %d x 5   = %d Ft\n",szamol5,szamol5*5);

    do {
        visszajaro = 0;
        printf("\nAdja meg mennyi visszajarot adott (200/100/50/20/10/5): ");
        scanf_s("%d", &visszajaro);

        if (visszajaro % 5 == 0){
            switch(visszajaro) {
                case 200:
                    fizetett -= visszajaro;
                    printf("Fentmarado osszeg: %d Ft\n",fizetett);
                    break;
                case 100:
                    fizetett -= visszajaro;
                    printf("Fentmarado osszeg: %d Ft\n",fizetett);
                    break;
                case 50:
                    fizetett -= visszajaro;
                    printf("Fentmarado osszeg: %d Ft\n",fizetett);
                    break;
                case 20:
                    fizetett -= visszajaro;
                    printf("Fentmarado osszeg: %d Ft\n",fizetett);
                    break;
                case 10:
                    fizetett -= visszajaro;
                    printf("Fentmarado osszeg: %d Ft\n",fizetett);
                    break;
                default:
                    fizetett -= visszajaro;
                    printf("Fentmarado osszeg: %d Ft\n",fizetett);
                    break;
            }
        } else {
            printf("Nem megfelelo visszajaro osszeg!\n");
            printf("Fentmarado osszeg: %d Ft\n",fizetett);
        }

        if(fizetett < 0){
            break;
        }
    } while(fizetett > 0);

    printf("\nKifizette a visszajarot!");
}
void feladat7 () {
    //---------7.feladat
    char muvelet,akarja;
    int elsoszam, masodikszam, eredmeny,folytatja;

    printf("7.feladat\n");
    do {
        muvelet = ' ';

        printf("Irja be melyik muveletett szeretne elvegezni (+, -, *, /): ");
        scanf("%s", &muvelet);

        printf("\n");

        printf("Irja be az elso szamot: ");
        scanf_s("%d", &elsoszam);

        printf("Irja be a masodik szamot: ");
        scanf_s("%d", &masodikszam);


        if (muvelet == '/' && masodikszam == 0) {
            printf("Nem lehetseges a 0-val valo osztas");
        }
        else{
            switch (muvelet) {
                case '+':
                    eredmeny = elsoszam + masodikszam;
                    break;
                case '-':
                    eredmeny = elsoszam - masodikszam;
                    break;
                case '*':
                    eredmeny = elsoszam * masodikszam;
                    break;
                case '/':
                    eredmeny = elsoszam / masodikszam;
                    break;
                default:
                    printf("Nincs ilyen muvelet!");
                    break;
            }
            printf("\nA(z) %d %c %d = %d", elsoszam, muvelet, masodikszam, eredmeny);
        }

        printf("\nSzeretne folytatni egy masik szammitassal?(Igen/Nem): ");
        scanf("%s", &akarja);
        printf("\n");

        switch (akarja) {
            case 'I':
                folytatja = 1;
                break;
            case 'N':
                printf("Vegetertek a szamitasok!");
                folytatja = 0;
                break;
            default:
                printf("Nem ertelmezheto hogy szeretne folytatni!\nVegettertek a szamitasok!");
        }

    }while(folytatja == 1);

}