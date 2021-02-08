 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #define A 5

 void preencher_cartela(int mat[A][A]){
     int i=0,j=0,min=1,max=15,x;

     srand((unsigned)time(NULL));
     for(j=0;j<A;j++){
          for(i=0;i<A;i++){
             mat[i][j] = min + rand() % (max - min);
          }
          min = max + 1;
          max = max + 15;
     }
 }

 void comparar(int mat[A][A]){
    int i,j,min=1,max=15,x=1,num=0;

    for(j=0;j<A;j++){
          for(i=0;i<A;i++){
                num = i;
                for(x=num+1;x<A;x++){
                if(mat[x][j]==mat[num][j]){
                    mat[i][j] = min + rand() % (max - min);
                }
                }
          }
          min = max + 1;
          max = max + 15;
    }
 }


 void mostra_cartela(int mat[A][A]){
     int i,j;
     printf("   B  |   I  |   N  |   G  |   O  |\n");
     printf("-----------------------------------\n");
     for(i=0;i<A;i++){
          for(j=0;j<A;j++){

               printf("  %2d  |", mat[i][j]);
          }
          printf("\n-----------------------------------");
          printf("\n");
     }
 }


 int gerar_comparar(int mat[A][A]){
     int i,j,k=0,v[75];
     int up,ok,cont=0,x;
     int soma=0;

    //processo de comparação
    while(k<5){
          v[cont] = 1 + rand() % 75;
          for(x=0;x<cont;x++){
             if(v[x] == v[cont]){
  	       v[cont] = 1 + rand() % 75;
                 x=0;
             }
          }
 	printf("\nNUMERO SORTEADO: %d ",v[cont]);
     for(i=0;i<A;i++){
       for(j=0;j<A;j++){
          if(mat[i][j]==v[cont]){
            printf("<------TEM!\n\n");
            mat[i][j] = 0;

            printf("Digite (5) para atualizar cartela\n");
            scanf("%d",&up);
            if(up==5){
            printf("  B |  I |  N |  G |  O\n");
            printf("-------------------------\n");
            for(i=0;i<A;i++){
              for(j=0;j<A;j++){
                 printf(" %2.d |", mat[i][j]);
              }
              printf("\n-------------------------");
              printf("\n");
             }
             printf("\nCARTELA ATUALIZADA!\n");
            }
            }

          }
        }
        //verifica se as quinas estao nulas
        for(i=0;i<A;i++){
          k=0;
          for(j=0;j<A;j++){
             if(mat[i][j]==0) k++;
          }
           if(k==5) {
          printf("\n\n--------------------------\n");
          printf("BINGOU NA QUINA! PARABENS!\n");
          printf("--------------------------\n\n");
          return 1;
           }
        }

        for(j=0;j<A;j++){
          k=0;
          for(i=0;i<A;i++){
             if(mat[i][j]==0) k++;
          }
           if(k==5){
          printf("\n\n--------------------------\n");
          printf("BINGOU NA QUINA! PARABENS!\n");
          printf("--------------------------\n\n");
          return 1;
           }
        }

        for(i=0;i<A;i++){
          k=0;
          for(j=0;j<A;j++){
             if(i==j){
                if(mat[i][j]==0) k++;
             }
          }
           if(k==5) {
          printf("\n\n--------------------------\n");
          printf("BINGOU NA QUINA! PARABENS! (FIM DE JOGO)\n");
          printf("--------------------------\n\n");
          return 1;
           }
        }

            printf("\n----------------------------------\n");
            printf("Digite (1) para gerar outro numero\n");
            scanf("%d",&ok);
            cont++;
   }
 }

 int main (){
    int aux[A][A],matriz[A][A];
    int op,v,c;

    printf("---------------------\n");
    printf("| 1 - Iniciar Bingo |\n");
    printf("| 2 - sair          |\n");
    printf("---------------------\n");
    printf("R: ");
    scanf("%d",&op);
    if(op==1){
    printf("-----------------------------------\n");
    printf("|      SUA CARTELA DE BINGO       |\n");
    printf("-----------------------------------\n\n");
    preencher_cartela(matriz);
    comparar(matriz);
    mostra_cartela(matriz);}
    else{
       if(op==2) return 1;
    }
    printf("\nDigite (1) para gerar numeros\n");
    scanf("%d",&v);
    if(v==1){
    gerar_comparar(matriz);
    }

    return 0;
 }
