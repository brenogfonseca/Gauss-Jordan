#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINHAS 3
#define COLUNAS 4

typedef int Fracao[2];

void ImprimeMatriz(Fracao Matriz[LINHAS][COLUNAS]) {
  char Buffer[9], NumberString[50];
  int Numerador, Denominador;
  //imprimindo matriz
  printf("\n");
  for(int I=0;I<LINHAS; I++)
  {
    char Linha[50] = "|";
    for(int J=0;J<COLUNAS; J++)
    {
      Numerador = Matriz[I][J][0];
      Denominador = Matriz[I][J][1];

      if(Denominador != 1)
        sprintf(NumberString, "%d/%d", Numerador, Denominador);
      if(Denominador == 1)
        sprintf(NumberString, "%d", Numerador);
      
      switch(strlen(NumberString)) {
        case 1:
          sprintf(Buffer, "   %c   |", NumberString[0]);
          break;
        case 2:
          sprintf(Buffer, "   %c%c  |", NumberString[0], NumberString[1]);
          break;
        case 3:
          sprintf(Buffer, "  %c%c%c  |", NumberString[0], NumberString[1], NumberString[2]);
          break;
        case 4:
          sprintf(Buffer, "  %c%c%c%c |", NumberString[0], NumberString[1], NumberString[2], NumberString[3]);
          break;
        case 5:
          sprintf(Buffer, " %c%c%c%c%c |", NumberString[0], NumberString[1], NumberString[2], NumberString[3], NumberString[4]);
          break;
        case 6:
          sprintf(Buffer, " %c%c%c%c%c%c|", NumberString[0], NumberString[1], NumberString[2], NumberString[3], NumberString[4], NumberString[5]);
          break;
        case 7:
          sprintf(Buffer, "%c%c%c%c%c%c%c|", NumberString[0], NumberString[1], NumberString[2], NumberString[3], NumberString[4], NumberString[5], NumberString[6]);
          break;
        default:
          sprintf(Buffer, "erro");
          break;
      }
      strcat(Linha, Buffer);
    }
    if(I==0)
      for(int K=0;(unsigned)K<strlen(Linha);K++)
        printf("_");
    printf("\n");
    printf("%s ", Linha);
    printf("\n");
    for(int K=0;(unsigned)K<strlen(Linha);K++)
      printf("-");
  }
  printf("\n");
}

int main()
{
  Fracao Matriz[LINHAS][COLUNAS] = {{{4,1},{-1,1},{-3,1},{15,1}},{{3,1},{-2,1},{5,1},{-7,1}},{{2,1},{3,1},{4,1},{7,1}}};

  ImprimeMatriz(Matriz);
  return 0;
}