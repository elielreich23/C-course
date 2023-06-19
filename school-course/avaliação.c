// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     int cred = 0, disc = 0;
//     char curso, vl, vl1, vl2, vl5, curso1[4] = {0}, curso2[4] = {0};

//     printf("Digite seu curso (C para Ciência da Computação):\n");
//     scanf(" %c", &curso);

//     if (curso == 'C' || curso == 'c')
//     {
//         int fase;
//         printf("Qual a sua fase (1 ou 2)?\n");
//         scanf("%d", &fase);
//         getchar();

//         if (fase == 1)
//         {
//             cred = 20;
//             disc = 5;

//             printf("Tentar Validacao (S ou N)?\n");
//             scanf(" %c", &vl);
//             getchar();

//             if (vl == 'S' || vl == 's')
//             {
//                 printf("Vai validar AGT (S ou N)?\n");
//                 scanf(" %c", &vl1);
//                 getchar();

//                 if (vl1 == 'S' || vl1 == 's')
//                 {
//                     strcpy(curso1, "AGT");
//                 }

//                 printf("Vai Validar TGS (S ou N)?\n");
//                 scanf(" %c", &vl2);
//                 getchar();

//                 if (vl2 == 'S' || vl2 == 's')
//                 {
//                     strcpy(curso2, "TGS");
//                 }
//             }

//             printf("_______________\n");
//             printf("Matricula compulsoria em:\n");
//             printf("\nPrimeira fase-------------Cred.Teo-------------Cred.Prat-----------------|\n");
//             printf("    AGT0001                   02                   02                    |\n");
//             printf("    GAN0001                   04                   00                    |\n");
//             printf("    ICD0001                   04                   00                    |\n");
//             printf("    LMA0001                   02                   00                    |\n");
//             printf("    TGS0001                   02                   02                    |\n");
//         }
//         else if (fase == 2)
//         {
//             printf("Vai fazer ALI (S ou N)?\n");
//             scanf(" %c", &vl);
//             getchar();

//             if (vl == 'S' || vl == 's')
//             {
//                 printf("Ja fez GAM (S ou N)?\n");
//                 scanf(" %c", &vl1);
//                 getchar();

//                 if (vl1 == 'S' || vl1 == 's')
//                 {
//                     cred += 4;
//                     disc++;
//                 }
//             }

//             printf("Vai fazer CDI (S ou N)?\n");
//             scanf(" %c", &vl);
//             getchar();

//             if (vl == 'S' || vl == 's')
//             {
//                 cred += 4;
//                 disc++;
//             }
//             else
//             {
//                 printf("Vai validar CDI (S ou N)?\n");
//                 scanf(" %c", &vl2);
//                 getchar();

//                 if (vl2 == 'S' || vl2 == 's')
//                 {
//                     strcpy(curso1, "CDI");
//                 }
//             }

//             printf("Vai fazer ECC (S ou N)?\n");
//             scanf(" %c", &vl);
//             getchar();

//             if (vl == 'S' || vl == 's')
//             {
//                 cred += 2;
//                 disc++;
//             }

//             printf("_______________\n");
//             printf("Matricula compulsoria em:\n");
//             printf("\nSegunda fase------------C");
//         }
//         else if ((curso == 'E') || (curso == 'e'))
//         {
//             printf("Digite a quantidade de creditos:\n");
//             scanf("%s", &vl5);
//             getchar();

//             if (strcmp(vl5, "22") == 0)
//             {

//                 printf("Alocado em\n");
//                 printf("\nTeoria da Computacao\n");
//                 printf("\nLaboratorio de Programacao II\n");
//                 printf("\nSistemas Operacionais\n");
//                 printf("\nLogica Matematica para Ciencia da Computacao\n");
//                 printf("\nMatematica Discreta II\n");
//                 printf("\nGrafos\n");
//                 printf("\nOrganizacao e Arquitetura de Computadores\n");
//                 printf("\nAlgoritmos e Estruturas de Dados III\n");
//                 printf("\nEngenharia de Software I\n");
//                 printf("\nRedes de Computadores I\n");
//                 printf("\nBanco de Dados I\n");
//                 printf("\nCalculo III\n");
//                 printf("\nFisica III\n");
//                 printf("\nAlgebra Linear I\n");
//             }
//             else if (strcmp(vl5, "26") == 0)
//             {

//                 printf("Alocado em\n");
//                 printf("\nTeoria da Computacao\n");
//                 printf("\nLaboratorio de Programacao II\n");
//                 printf("\nSistemas Operacionais\n");
//                 printf("\nLogica Matematica para Ciencia da Computacao\n");
//                 printf("\nMatematica Discreta II\n");
//                 printf("\nGrafos\n");
//                 printf("\nOrganizacao e Arquitetura de Computadores\n");
//                 printf("\nAlgoritmos e Estruturas de Dados III\n");
//                 printf("\nEngenharia de Software I\n");
//                 printf("\nRedes de Computadores I\n");
//                 printf("\nBanco de Dados I\n");
//                 printf("\nCalculo III\n");
//                 printf("\nFisica III\n");
//                 printf("\nAlgebra Linear I\n");
//                 printf("\nTopicos em Programacao\n");
//             }
//             else
//             {
//                 printf("Quantidade de creditos invalida.\n");
//             }
//         }
//         else
//         {
//             printf("Curso invalido.\n");
//         }

//         return 0;
//     }
// }

/**
 * C program to search element in array
 */

#include <stdio.h>

#define MAX_SIZE 100  // Maximum array size

int main()
{
    int arr[MAX_SIZE];
    int size, i, toSearch, found;

    /* Input size of array */
    printf("Enter size of array: ");
    scanf("%d", &size);

    /* Input elements of array */
    printf("Enter elements in array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &toSearch);

    /* Assume that element does not exists in array */
    found = 0; 
    
    for(i=0; i<size; i++)
    {
        /* 
         * If element is found in array then raise found flag
         * and terminate from loop.
         */
        if(arr[i] == toSearch)
        {
            found = 1;
            break;
        }
    }

    /*
     * If element is not found in array
     */
    if(found == 1)
    {
        printf("\n%d is found at position %d", toSearch, i + 1);
    }
    else
    {
        printf("\n%d is not found in the array", toSearch);
    }

    return 0;
}