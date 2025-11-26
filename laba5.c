/*#include <stdio.h>        // задание на 5
#define k 5

int F(int chislo){
    if (chislo>9 && chislo<100){
        for (int i = 2; i<=chislo/2; i++){
            if (chislo%i==0){return 0;}
        }
        return 1;
    }
    else{return 0;}
}

int max(int chislo, int massiv[chislo]){
    int maxx = -999;
    for (int i = 0; i<chislo; i++){
            if (maxx<massiv[i]){maxx = massiv[i];}
    }
    return maxx;
}

int main(){
    int Y[k];
    int kol_prost_chisel = 0;
    for (int i = 0; i<k; i++){
        int a; scanf("%d",  &a);
        if (a>9 && a<100 && F(a)==1){kol_prost_chisel+=1;}
        Y[i] = a;
    }
    int maxx_do = max(k, Y);
    if (kol_prost_chisel>2){
        for (int i = 0; i<k; i++){
            if (F(Y[i])==1){Y[i]=0;}
        }
    }
    int maxx_posle = max(k, Y);
    for (int i=0; i<k; i++){
        printf("%d ", Y[i]);
    }
    if (maxx_do!=maxx_posle){printf("\nYes\n");}
    else {printf("\nNo\n");}
    printf("Количество простых двухзначных чисел: %d\n", kol_prost_chisel);
}*/
/*
#include <stdio.h>      //задание на 4
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define K 5

int main(){
    srand(time(0));
    long for_s_e_re = 0;
    long for_s_e_im = 0;
    int massiv[K*2] = {0};
    int max_re = -999999999;
    for (int i=0; i<K*2; i++){
        massiv[i] = rand()%(pow(2, 16))-pow(2, 15);
        if (i%2==0){
            for_s_e_re+=massiv[i]*2;
            if (max_re<massiv[i]){max_re = massiv[i];}
        }
        else {for_s_e_im+=massiv[i]*2;}
    }
    for (int i=0; i<K*2; i+=2){
        printf("massiv[%d] = %d + j*(%d)\n", i/2, massiv[i], massiv[i+1]);
    }
    printf("Энергия сигнала = %ld + j*(%ld)\n", for_s_e_re, for_s_e_im);
    printf("Максимальный элемент среди реальной части равен %d\n", max_re);
}*/

#include <stdio.h>      //задание на *
#include <ctype.h> //подсказали второкурсники на продлёнке
#include <string.h>
#include <stdlib.h>

int *ispravlenie_massiva(char *massiv, int operacia, int *kol_simv_v_isprav_massive){       //0 - сжать; 1 - восстановить
    int razmer_strokovoe_chislo = 0;
    int razmer_massiv_chisel = 0;
    char *strokovoe_chislo = NULL;
    int *massiv_chisel = NULL;
    int i=0;
    while (i!=strlen(massiv)-1){
        if ((strokovoe_chislo != NULL) && isdigit(massiv[i])){      //если это не первая цифра после запятой
            razmer_strokovoe_chislo++;
            char *na_raz = realloc(strokovoe_chislo, razmer_strokovoe_chislo*sizeof(char));
            if (na_raz!=NULL){strokovoe_chislo = na_raz;}
            strokovoe_chislo[razmer_strokovoe_chislo-1] = massiv[i];
        }
        if ((strokovoe_chislo == NULL) && isdigit(massiv[i])){      //если это первая цифра после запятой
            razmer_strokovoe_chislo++;
            strokovoe_chislo = malloc(razmer_strokovoe_chislo*sizeof(char));
            strokovoe_chislo[razmer_strokovoe_chislo-1] = massiv[i];
        }
        if ((massiv[i]==',' || i==strlen(massiv)-2) && strokovoe_chislo!=NULL){     //если это запятая или последний элемент строки
            razmer_massiv_chisel++;
            if (massiv_chisel!=NULL){
                int *na_raz = realloc(massiv_chisel, razmer_massiv_chisel*sizeof(int));
                if (na_raz!=NULL){massiv_chisel = na_raz;}
                massiv_chisel[razmer_massiv_chisel-1] = atoi(strokovoe_chislo);
            }
            else if (massiv_chisel==NULL){
                massiv_chisel = malloc(razmer_massiv_chisel*sizeof(int));
                massiv_chisel[razmer_massiv_chisel-1] = atoi(strokovoe_chislo);
            }
            else if (i==strlen(massiv)-2){
                int *na_raz = realloc(massiv_chisel, razmer_massiv_chisel*sizeof(int));
                if (na_raz!=NULL){massiv_chisel = na_raz;}
                massiv_chisel[razmer_massiv_chisel-1] = atoi(strokovoe_chislo);
            }
            free(strokovoe_chislo); strokovoe_chislo = NULL;
            razmer_strokovoe_chislo = 0;
        }
        i++;
    }
    if (massiv_chisel==NULL){
        printf("В вашем массиве нет цифр.\n");
        return NULL;
    }
    if (razmer_massiv_chisel%2!=0 && operacia==1){
        printf("Восстановить массив невозможно. В нём не хватает данных.\n");
        return NULL;
    }
    *kol_simv_v_isprav_massive = razmer_massiv_chisel;
    return massiv_chisel;
}

int *izmenenie_massiva(int *ispravlenniy_massiv, int operacia, int kol_simv_v_isprav_massive, int *kol_simv_v_itog_massive){
    int *final_massiv = NULL;
    int razmer_final_massiva = 0;
    if (operacia==0){
        int last_chislo = ispravlenniy_massiv[0];
        int kol_same_cisel = 1;
        for (int i=1; i<kol_simv_v_isprav_massive; i++){
            if (ispravlenniy_massiv[i]!=last_chislo){
                razmer_final_massiva += 2;
                if (final_massiv!=NULL){
                    int *na_raz = realloc(final_massiv, razmer_final_massiva*sizeof(int));
                    if (na_raz!=NULL){final_massiv = na_raz;}
                    final_massiv[razmer_final_massiva-2] = last_chislo;
                    final_massiv[razmer_final_massiva-1] = kol_same_cisel;
                }
                if (final_massiv==NULL){
                    final_massiv = malloc(razmer_final_massiva*sizeof(int));
                    final_massiv[razmer_final_massiva-2] = last_chislo;
                    final_massiv[razmer_final_massiva-1] = kol_same_cisel;
                }
                last_chislo = ispravlenniy_massiv[i];
                kol_same_cisel = 1;
            }
            else {kol_same_cisel++;}
        }
        {      //если это последний или единственный (единственный тоже является последним) вид элемента в массиве
        razmer_final_massiva += 2;
        int *na_raz = realloc(final_massiv, razmer_final_massiva*sizeof(int));
        if (na_raz!=NULL){final_massiv = na_raz;}
        final_massiv[razmer_final_massiva-2] = last_chislo;
        final_massiv[razmer_final_massiva-1] = kol_same_cisel;
        }
        if (razmer_final_massiva>=kol_simv_v_isprav_massive){
            printf("Размер массива не изменился или стал больше, что противоречит определению сжатия.\n");
            return NULL;
        }
        else {
            *kol_simv_v_itog_massive = razmer_final_massiva;
            return final_massiv;
        }
    }
    if (operacia==1){
        for (int i=0; i<kol_simv_v_isprav_massive; i+=2){
            if (ispravlenniy_massiv[i+1]==0){
                printf("Данный массив не мог получиться в результате сжатия, соответственно восстановить его невозможно.\n");
                return NULL;
            }
            razmer_final_massiva += ispravlenniy_massiv[i+1];
            if (final_massiv==NULL){
                final_massiv = malloc(razmer_final_massiva*sizeof(int));
                for (int j=razmer_final_massiva-ispravlenniy_massiv[i+1]; j<razmer_final_massiva; j++){
                    final_massiv[j] = ispravlenniy_massiv[i];
                }
            }
            if (final_massiv!=NULL){
                int *na_raz = realloc(final_massiv, razmer_final_massiva*sizeof(int));
                if (na_raz!=NULL){final_massiv = na_raz;}
                for (int j=razmer_final_massiva-ispravlenniy_massiv[i+1]; j<razmer_final_massiva; j++){
                    final_massiv[j] = ispravlenniy_massiv[i];
                }
            }
        }
        *kol_simv_v_itog_massive = razmer_final_massiva;
        return final_massiv;
    }
}

void text(int operacia){
    printf("Инструкция:\n");
    if (operacia==0){
        printf("Если Вы хотите сжать массив, то задавать его нужно следующим образом:\n");
        printf("Число, запятая, число, запятая и т.д.   Пример: 1,4,7,3,9,1212,6\n");
        printf("Количество пробелов не влияет на результат, но лучше их не ставить.\n");
        printf("Буквы и специальные символы не рекомендуется использовать, иначе время выполнения программы увеличится. Данные символы будут отброшены.\n");
        printf("Числа должны быть неотрицательнами и целыми, то есть знаки '-', ',', '.' не учитывается.\n\n");
    }
    else {
        printf("Если Вы хотите восстановить массив, то задавать его нужно следующим образом:\n");
        printf("Число, запятая, число, запятая, пробел (по желанию); число, запятая, число, запятая, пробел и т.д.   Пример: 1,2, 4,3, 6,5, 33,56\n");
        printf("Количество пробелов не влияет на результат.\n");
        printf("Буквы и специальные символы не рекомендуется использовать, иначе время выполнения программы увеличится. Данные символы будут отброшены.\n");
        printf("Числа должны быть неотрицательнами и целыми, то есть знаки '-', ',', '.' не учитывается.\n\n");
    }
}

int main(){
    int operacia;       //просим пользователя выбрать операцию
    while (1){
        printf("Что вы хотите сделать с массивом? 0 - сжать, 1 - восстановить:  ");
        if (scanf("%d%*c", &operacia)==0){return 0;}
        if (operacia==0 || operacia==1){break;}
    }

    text(operacia);
    char *massiv = malloc(3000*sizeof(char));      //создаём массив для строки
    if (massiv == NULL){printf("Память не выделена\n"); return -1;}
    printf("Введите массив: "); fgets(massiv, 3000*sizeof(char), stdin);
    char *na_raz = realloc(massiv, (strlen(massiv)-1)*sizeof(char));
    if (na_raz != NULL){massiv = na_raz;}

    printf("______________________________________\nЗаданный Вами массив:   [");      //вывод на экран заданного массива без иправлений
    for (int i=0; i<strlen(massiv)-1; i++){
        printf("%c", massiv[i]);
    }
    printf("]\n");

    int kol_simv_v_isprav_massive;
    int *ispravlenniy_massiv = ispravlenie_massiva(massiv, operacia, &kol_simv_v_isprav_massive);
    free(massiv); massiv = NULL;
    if (ispravlenniy_massiv!=NULL){
        printf("Исправленный масив:     [");
        if (operacia==0){
            for (int i=0; i<kol_simv_v_isprav_massive; i++){
                printf("%d", ispravlenniy_massiv[i]);
                if (i==kol_simv_v_isprav_massive-1){printf("]\n");}
                else {printf(",");}
            }
        }
        if (operacia==1){
            for (int i=0; i<kol_simv_v_isprav_massive; i++){
                printf("%d", ispravlenniy_massiv[i]);
                if (i!=kol_simv_v_isprav_massive-1){printf(",");}
                if (i%2==1 && i!=kol_simv_v_isprav_massive-1){printf(" ");}
            }
            printf("]\n");
        }
    }
    else {return -1;}

    int kol_simv_v_itog_massive;
    int *itog = izmenenie_massiva(ispravlenniy_massiv, operacia, kol_simv_v_isprav_massive, &kol_simv_v_itog_massive);
    free(ispravlenniy_massiv); ispravlenniy_massiv = NULL;
    float k = (float)kol_simv_v_itog_massive*100/kol_simv_v_isprav_massive;
    if (itog!=NULL){
        if (operacia==0){
            printf("Сжатый массив:          [");
            for (int i=0; i<kol_simv_v_itog_massive; i++){
                printf("%d", itog[i]);
                if (i!=kol_simv_v_itog_massive-1){printf(",");}
                if (i%2==1 && i!=kol_simv_v_itog_massive-1){printf(" ");}
            }
            printf("]\n");
            printf("Коэффициент сжатия: %.2f%c (исходный: %d элементов, сжатый: %d элементов)\n", k, '%', kol_simv_v_isprav_massive, kol_simv_v_itog_massive);
        }
        if (operacia==1){
            printf("Восстановленный массив: [");
            for (int i=0; i<kol_simv_v_itog_massive; i++){
                printf("%d", itog[i]);
                if (i==kol_simv_v_itog_massive-1){printf("]\n");}
                else {printf(",");}
            }
        }
        free(itog); itog = NULL;
    }
    else {return -1;}
}