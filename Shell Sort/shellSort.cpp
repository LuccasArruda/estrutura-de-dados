void shellsortS(int *vet, int n){
    int i, j, k, indk, aux;

    int vetk[3] = {5, 3, 1};

    for (indk = 0; indk < 3; indk++) {
        k = vetk[indk];

        for (i = k; i < n; i++) {
            aux = vet[i];
            for (j = i-k; j >= 0 && vet[j] > aux; j-=k) {   // ordena de forma ascendente
                vet[j+k] = vet[j];
            }
            vet[j+k] = aux;
        }
    }
}

void shellsortE(int *vet, int n){
    int i, j, k, indk, aux;

    int vetk[3] = {5, 3, 1};

    for (indk = 0; indk < 3; indk++) {
        k = vetk[indk];

        for (i = k; i < n; i++) {
            aux = vet[i];
            for(j = i-k; j >= 0 && vet[j] < aux; j-=k){        // ordena de forma decrescente
                vet[j+k] = vet[j];…
[22:17, 11/03/2024] Ereque: #include <stdio.h>
#include <stdlib.h>

int apoiocrescente(int const *a, int const *b){
    return *a - *b;
}

int apoiodecrescente(int const *a, int const *b){
    return *b - *a;
}



int main(){
    int imp[100000], par[100000], N, x=0, indi=0, indp=0, temp, i;

    scanf("%d", &N);
    while(x<N){
        scanf("%d", &temp);
        if(temp%2 == 0){
            par[indp] = temp;
            indp++;
        }else{
            imp[indi] = temp;
            indi++;
        }
        x++;
    }

    qsort(par, indp, sizeof(int), apoiocrescente);

    qsort(imp, indi, sizeof(int), apoiodecrescente);

    for(i = 0; i < indp; i++){
        printf("%d\n", par[i]);
    }

    for(i = 0; i < indi; i++){
        printf("%d\n", imp[i]);
    }

    return 0;
}
