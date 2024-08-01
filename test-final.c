#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define A 300


int ncompQuick=0;
int ntrocaQuick=0;


void quickSort(int *v, int inicio, int fim);
int partition(int *v, int inicio, int fim);
void imprime(int *v);



int main(){
    

    int v[A]={-328,286,550,371,-386,-743,164,114,361,869,195,-711,158,247,-576,544,-83,345,537,274,799,661,-984,432,891,461,-873,630,-320,578,174,-837,959,276,-342,-168,933,-91,537,-153,-83,-588,901,-656,-418,759,-625,-480,651,8,-15,-951,14,-603,909,-918,-835,-50,-817,714,-603,878,495,920,663,-654,22,315,495,924,-683,-445,834,968,-477,90,-492,215,197,-882,356,-805,221,916,553,-84,645,61,577,516,-356,95,551,812,-406,844,-871,-804,-304,-646,-799,802,-346,804,534,-302,-589,284,90,392,-591,-992,-171,-109,302,219,-374,-35,572,867,-793,-597,258,-328,-810,310,279,-680,-113,454,269,-861,-657,955,-156,-431,89,-378,-853,467,-125,666,942,-473,556,-313,222,655,-720,99,-72,842,-659,-218,-15,-791,998,826,998,-858,-6,-764,103,-757,-291,-170,296,77,421,359,354,-984,-617,431,-263,-190,-474,-806,-484,465,469,662,-665,159,866,-145,102,-386,809,-929,949,3,-802,587,-791,508,151,693,556,619,-720,-581,-678,-606,-708,634,-659,806,191,-287,515,-293,666,467,935,-529,978,486,-473,-855,-392,224,301,-746,51,-689,-831,253,-549,257,987,954,-785,733,850,479,119,-486,367,-403,329,-60,-838,-629,751,-945,138,892,917,-409,-327,-196,-858,96,342,-967,219,-336,-504,-89,-699,270,232,424,-711,-106,-970,-99,-580,-577,162,839,-550,637,-976,-41,-473,55,-725,-717,-6,524,387,366,-377,-492,215,426,-243,472,514,94,338,888,445,-413,158,-473,-20,-211
    };

    int tamanho = A/ sizeof(v[0]);

    quickSort(v,0,tamanho-1);

    imprime(v);

    printf("\ncomparacao: %i\ttrocas: %i", ncompQuick,ntrocaQuick);
    return 0;
}



void quickSort(int *v, int inicio, int fim){
    FILE * out;
    int pivo;

    if(inicio>fim){
        pivo = partition(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v,pivo+1,fim);
    }
    int i;
    if ( (out=fopen("saida300Teste-quickSort.txt", "a"))!=NULL){
        fprintf(out,"\n%i comparacoes;%i trocas\n", ncompQuick, ntrocaQuick);
        for(i=0; i< A; i++)
            fprintf(out, "%i,", v[i]); 
        fprintf(out,"\n");
        fclose(out);
    }
}

int partition(int *v, int inicio, int fim){
    int pivo, menorPivo, maiorPivo, aux;
    pivo = v[inicio];
    menorPivo = inicio;
    maiorPivo = fim;

    while(menorPivo<maiorPivo){
        while(menorPivo <= fim && v[menorPivo] <= pivo){
            menorPivo++;
            ncompQuick++;
        }
        while(menorPivo >= 0 && v[maiorPivo] <= pivo){
            maiorPivo++;
            ncompQuick++;
        }
        if(menorPivo < maiorPivo){
            aux = v[menorPivo];
            v[menorPivo] = v[maiorPivo];
            v[maiorPivo] = aux;
            ntrocaQuick++;
        }
        
    }

    v[inicio] = v[maiorPivo];
    v[maiorPivo] = pivo;
    ntrocaQuick++;

    return maiorPivo; 
  
}