// #include<stdio.h>
// #include<string.h>

// int main(){
//     int soma;
//     int fase = 0, cred = 0, disc = 0;
//     char curso, vl,vl1, vl2, curso1[4], curso2[4], vl5[4];

//     printf("Digite seu curso:\n");
//     scanf("%c", &curso);
//     if((curso == 'C') || (curso == 'c')){
//         printf("Qual a sua fase?\n");
//         scanf("%d", &fase);
//         getchar();

//         if (fase == 1){
//             cred = 20;
//             disc = 5;
//             printf("Tentar Validacao?\n");
//             scanf("%c", &vl);
//             getchar();

//             if((vl == 'S' || vl == 's')){
//                 printf("\nVai validar AGT?\n");
//                 scanf("%c", &vl1);
//                 if ((vl1 == 'S') || (vl1 == 's')){
//                     strcpy(curso1, "AGT");
//                 }
//                 getchar();
//                 printf("\nVai Validar TGS?\n");
//                 scanf("%c", &vl2);
//                 if((vl2 == 'S') || (vl2 == 's')){
//                     strcpy(curso2, "TGS");
//                 }
//             }

//             printf("_______________");
//             printf("\n     Matricula compulsoria em:\n");
//             printf("\nPrimeira fase-------------Cred.Teo-------------Cred.Prat-----------------|\n");
//             printf("    AGT0001                   02                   02                    |\n");
//             printf("    GAN0001                   04                   00                    |\n");
//             printf("    ICD0001                   04                   00                    |\n");
//             printf("    LMA0001                   02                   00                    |\n");
//             printf("    TGS0001                   02                   02                    |\n");

//             printf("\nTotal de Creditos: %d", cred);
//             printf("\nTotal de Diciplinas: %d", disc);
//             printf("\nPedidos de validacao: %s, %s\n", curso1, curso2);

//         } else { //AQUI ENTRA CASO A FASE SEJA 2

//             printf("Vai fazer ALI?\n");
//             scanf("%c", &vl);
//             getchar();
//             if ((vl == 'S') || (vl == 's'))
//             {
//                 printf("Ja fez GAM?\n");
//                 scanf("%c",&vl1);
//                 getchar();
//                 if ((vl1 == 'S') || (vl1 == 's'))
//                 {
//                     soma = soma + 1;
//                     cred = cred + 4;
//                     disc = disc + 1;
//                 }
//             }

//             printf("Vai fazer CDI?\n");
//             scanf("%c", &vl);
//             getchar();

//             if ((vl == 'S') || (vl == 's'))
//             {
//                 soma = soma + 1;
//                 cred = cred + 4;
//                 disc = disc + 1;
//             } else {
//                 printf("Vai validar CDI?\n");
//                 scanf("%c", &vl2);
//                 getchar();
//                 if ((vl2 == 'S') || (vl2 == 's'))
//                 { // COPIA CDI PARA A STRING CURSO1
//                     strcpy(curso1, "CDI");
//                 }
//             }

//             printf("Vai fazer ECC?\n");
//             scanf("%c", &vl);
//             getchar();

//             if ((vl == 'S') || (vl == 's'))
//             {

//                 soma = soma + 1;
//                 cred = cred + 2 ;
//                 disc = disc + 1;
//             }
//             printf("_______________");
//             printf("\n     Matricula compulsoria em:\n");
//             printf("\nPrimeira fase-------------Cred.Teo-------------Cred.Prat-----------------|\n");
//             printf("    ALI0001                   04                   00                    |\n");
//             printf("    CDI0001                   04                   00                    |\n");
//             printf("    ECC0001                   02                   00                    |\n");

//             if (disc > 0)
//             {
//                 printf("\nTotal de Creditos: %d", cred);
//                 printf("\nTotal de Diciplinas: %d", disc);
//                 printf("\nPedidos de validacao: %s\n", curso1);
//             } else{
//                 printf("\nSua matricula vai constar como trancada. É preciso preciso escolher ao menos uma diciplina\n");
//                 printf("\nTotal de Creditos: %d", cred);
//                 printf("\nTotal de Diciplinas: %d\n", disc);
//             }
//         }
//     }
// }
