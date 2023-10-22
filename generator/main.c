#include <stdio.h>
#include <conio.h>

void createMain(int num) {
    int i;
    FILE *file;
    file = fopen("feladatok.txt", "w");
    fprintf(file, "#include <stdio.h>\n\n");
    // Most dfeklaraljuk a függvényeket
    for (i = 1; i <= num; i++) {
        fprintf(file, "\nvoid feladat%d();", i);
    }
    fprintf(file, "\n");
    fprintf(file, "\n");
    fprintf(file, "int main() {\n");
    fprintf(file, "    int feladatszam;\n");
    fprintf(file, "    printf(\"Feladatok:  \\n\");\n");
    fprintf(file, "\n");
    for (i = 1; i <= num; i++) {
        fprintf(file,"\tprintf(\"\\t%d.feladat: - \\n\");\n",i);
    }
    fprintf(file, "\n");
    fprintf(file, "    printf(\"%Melyik feladatot szeretne megnezni?:  \");\n");
    fprintf(file, "    scanf(\"%%d\", &feladatszam);\n");
    fprintf(file, "\n");
    fprintf(file, "    switch (feladatszam) {\n");
    for (i = 1; i <= num; i++) {
        fprintf(file, "        case %d:\n", i);
        fprintf(file, "            feladat%d();\n", i);
        fprintf(file, "            break;\n");
    }
    fprintf(file, "        default:\n");
    fprintf(file, "            printf(\"Nem letezik ilyen szamu feladat!\\n\");\n");
    fprintf(file, "            break;\n");
    fprintf(file, "    }\n");
    fprintf(file, "    return 0;\n");
    fprintf(file, "}\n");
    // Most adjuk hozzá a függvények definícióit
    for (i = 1; i <= num; i++) {
        fprintf(file, "\nvoid feladat%d() {\n", i);
        fprintf(file, "    printf(\"%d.feladat\\n\");\n", i);
        fprintf(file, "    // Feladat %d megoldasa\n", i);
        fprintf(file, "}\n");
    }
    fclose(file);
}
int main() {
    int num;
    printf("Hany feladatot szeretne generalni? : ");
    scanf("%d", &num);
    if (num >= 1) {
        createMain(num);
        printf("A fajl letrehozva: feladatok.txt\n");
	printf("Bezrahatja a programot (Nyomjon ENTERT-t)...\n");
        char quit = _getch(); 
        if (quit == 'q' || quit == 'Q') {
            return 0; 
        }
    } else {
        printf("Ervenytelen bemenet! Adjon meg egy szamot ami 1-nel negyobb.\n");
	printf("Bezrahatja a programot (Nyomjon ENTERT-t)...\n");
        char quit = _getch();
        if (quit == 'q' || quit == 'Q') {
            return 0; 
        }
    }
    return 0;
}