#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find_max(int **matrica, int razmer_matrici){
    int max = -101;
    int max_x; int max_y;
    for (int i=0; i<razmer_matrici; i++){
        for (int j=0; j<razmer_matrici; j++){
            if (max<matrica[i][j]){
                max = matrica[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }
    printf("Максимальный элемент: %d\n", max);
    matrica[max_x][max_y] = matrica[razmer_matrici-1][0];
    matrica[razmer_matrici-1][0] = max;
}

void modul(int **matrica, int razmer_matrici){
    printf("Матрица с модулями: \n");
    for (int i=0; i<razmer_matrici; i++){
        for (int j=0; j<razmer_matrici; j++){
            if (matrica[i][j]<0){matrica[i][j] = 0-matrica[i][j];}
            printf("%d  ", matrica[i][j]);
        }
        printf("\n");
    }
}

void domnojenie(int **matrica, int razmer_matrici){
    int kol_0 = 0;
    printf("Домноженная матрица: \n");
    for (int i=0; i<razmer_matrici; i++){
        if (matrica[i][razmer_matrici-i-1]==0){kol_0++;}
    }
    for (int i=0; i<razmer_matrici; i++){
        for (int j=0; j<razmer_matrici; j++){
            matrica[i][j]*=kol_0;
            printf("%d  ", matrica[i][j]);
        }
        printf("\n");
        free(matrica[i]); matrica[i]=NULL;
    }
}

int main(){
    srand(time(0));
    int razmer_matrici; printf("Введите размер матрицы: "); scanf("%d", &razmer_matrici);
    int **matrica = malloc(razmer_matrici*sizeof(*matrica));
    if (matrica==NULL){printf("Память не выделена\n"); return 0;}
    for (int i=0; i<razmer_matrici; i++){
        matrica[i] = malloc(razmer_matrici*sizeof(**matrica));
        if (matrica[i]==NULL){printf("Память не выделена\n"); return 0;}
        for (int j=0; j<razmer_matrici; j++){
            matrica[i][j] = rand()%11-5;
            printf("%d  ", matrica[i][j]);
        }
        printf("\n");
    }
    find_max(matrica, razmer_matrici);
    modul(matrica, razmer_matrici);
    domnojenie(matrica, razmer_matrici);

    free(matrica); matrica=NULL;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *init_cache(int razmer_kesha){
    int *massiv = calloc(razmer_kesha, sizeof(*massiv));
    if (massiv==NULL){printf("Память не выделена/n"); return NULL;}
    return massiv;
}

void print_cache(int *cache, int *usage, int razmer_kesha){
    printf("[ ");
    for (int i=0; i<razmer_kesha; i++){
        printf("%d(%d) ", cache[i], usage[i]);
    }
    printf("]\n");
}

void get_value(int *cache, int *usage, int razmer_kesha){
    int x=1;
    int _0_in_usage_ = 1;
    do{
        int a; printf("Запрос: ");
        if (scanf("%d", &a)==0){break;}
        for (int i=0; i<razmer_kesha; i++){
            if (a==cache[i]){
                usage[i] = x;
                break;
            }
            if (i==razmer_kesha-1){
                if (_0_in_usage_ == 0){
                    int min=100000;
                    for (int j=0; j<razmer_kesha; j++){
                        if (usage[j]<min){min=usage[j];}
                    }
                    for (int j=0; j<razmer_kesha; j++){
                        if (usage[j]==min){
                            cache[j]=a;
                            usage[j]=x;
                            break;
                        }
                    }
                }
                if (_0_in_usage_ == 1){
                    for (int j=0; j<razmer_kesha; j++){
                        if (usage[j]==0){
                            if (j==razmer_kesha-1){_0_in_usage_=0;}
                            cache[j] = a;
                            usage[j] = x;
                            break;
                        }
                    }
                }
            }
        }
        print_cache(cache, usage, razmer_kesha);
        x++;
    } while(1);
}

int main(){
    int razmer_kesha; printf("Введите размер кэша: "); scanf("%d", &razmer_kesha);
    int *cache = init_cache(razmer_kesha);
    int *usage = init_cache(razmer_kesha);
    if (cache==NULL || usage==NULL){return 0;}
    get_value(cache, usage, razmer_kesha);
    free(cache); cache=NULL;
    free(usage); usage=NULL;
}*/