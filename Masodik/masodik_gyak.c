#include <stdio.h>
#include <math.h>

void feladat1();
void feladat2();
void feladat3();
void feladat4();
void feladat5();
void feladat6();
void feladat7();
void feladat8();
void feladat9();


int main() {
    int feladatszam;

    printf("Melyik feladatot szeretne megnezni?:\n\t-1.feladat: Hello World!\n\t-2.feladat: Keplet kiszamitas\n\t-3.feladat: X++ ++X kozotti kulonbseg\n\t-4.feladat: Teglalap kerulet, terulet\n\t-5.feladat: Kor kerulet,terulet\n\t-6.feladat: Atfogo szamitasa\n\t-7.feladat: Paros vagy paratlan\n\t-8.feladat: Ebresztoora\n\t-9.feladat: Kamatos kamatozas");
    printf("\n\nAdja meg a feladat szamat: ");
    scanf_s("%d", &feladatszam);

    if(feladatszam > 0 && feladatszam < 11){

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
            case 7:
                feladat7();
                break;
            case 8:
                feladat8();
                break;
            default:
                feladat9();
                break;

        }
    }
    else{
        printf("Nem letezik ilyen szamu feladat! Bocsi de probald meg ujra! :)");
    }

    return 0;
}

void feladat1(){
    printf("1.feladat\n");
    printf("Hello World!");
}
void feladat2(){
    printf("2.feladat\n");
    int eredmenyint;
    float eredmenyfloat,eredmenyfloathelyes;


    eredmenyint = 6 * 2 / 3 + 5 / 2 - 7 * 3 % 2;
    eredmenyfloat = 6 * 2 / 3 + 5 / 2 - 7 * 3 % 2;
    eredmenyfloathelyes = 6,0 * 2 / 3 + 5 / 2 - 7 * 3 % 2;

    printf("Az eredmeny int-ben tarolva: %d\n",eredmenyint);
    printf("Az eredmeny float-ban  tarolva: %.2f\n",eredmenyfloat);
    printf("Az eredmeny float-ban helyesen tarolva: %.2f\n",eredmenyfloathelyes);

}
void feladat3(){
    int x = 2, y = 5,eredmeny1,eredmeny2;

    printf("3.feladat:\n");


    eredmeny1 = (x++) + y * (--y) / (++x);

    x = 2, y = 5;

    eredmeny2 = (x++) + y * (y--) / (++x);

    printf("A (x++) + y * (--y) / (++x) eredmenye: %d\n",eredmeny1);
    printf("A (x++) + y * (y--) / (++x) eredmenye: %d\n",eredmeny2);

}
void feladat4(){
    int a,b,terulet,kerulet;

    printf("Adja meg az a oldal hosszat (cm):");
    scanf_s("%d",&a);
    printf("Adja meg a b oldal hosszat (cm):");
    scanf_s("%d",&b);
    printf("\n");

    terulet = a * b;
    kerulet = 2 * (a + b);

    printf("A teglalap kerulete: %d cm\n",kerulet);
    printf("A teglalap kerulete: %d cm2\n",terulet);

}
void feladat5(){
    double r;
    printf("5.feladat\n");

    printf("Kerem adja meg a kor sugarat: ");
    scanf_s("%lf", &r);
    printf("\n");

    double terulet = M_PI * r * r;
    double kerulet = 2 * M_PI * r;

    printf("A kor kerulete: %lf cm\n", kerulet);
    printf("A kor terulete: %lf cm2\n", terulet);
}
void feladat6(){
    double a, b, c;

    printf("6.feladat\n");
    printf("Kerem adja meg az elso befogo hosszat: ");
    scanf_s("%lf", &a);
    printf("Kerem adja meg a masodik befogo hosszat: ");
    scanf_s("%lf", &b);
    printf("\n");

    c = sqrt(a*a + b*b);

    printf("A haromszog atfogoja: %lf\n", c);
}
void feladat7(){
    int szam;
    printf("7.feladat\n");
    printf("Kerem adjon meg egy pozitiv egesz szamot: ");
    scanf_s("%d", &szam);

    if(szam % 2 == 0){
        printf("A szam paros");
    }
    else{
        printf("A szam paratlan");
    }

}
void feladat8(){
    int mostaniido, mikorszoljon;

    printf("Kerem adja meg az aktualis orat (0-23): ");
    scanf_s("%d", &mostaniido);

    printf("Hany oraval kesobb szolaljon meg az ebresztoora: ");
    scanf_s("%d", &mikorszoljon);

    int ebreszto_ora = (mostaniido + mikorszoljon) % 24;

    printf("\n");
    printf("Az ebresztoora %d orakor fog megszolalni.\n", ebreszto_ora);

}
void feladat9(){
    double r = 0.08, alaptoke, FV,hatvanyalap,kitevo;
    int kamatozasokszama = 12, evekszama;

    printf("9.feladat\n");
    printf("Kerem adja meg az alaptoke erteket (Ft): ");
    scanf_s("%lf", &alaptoke);

    printf("Kerem adja meg hany evig van lekotve az osszeg: ");
    scanf_s("%d", &evekszama);

    hatvanyalap = 1 + r / kamatozasokszama;
    kitevo = kamatozasokszama * evekszama;

    FV = alaptoke * pow(hatvanyalap,kitevo );

    printf("\n");
    printf("%d ev mulva a futamido vegen nezett osszeg: %.2lf Ft\n", evekszama, FV);

}
