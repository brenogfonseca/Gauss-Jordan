#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LINHAS 3
#define COLUNAS 4
#define T 2

typedef char String[50];

int Mdc(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int numPlaces (int n) {
    if (n < 0) n = (n == INT_MIN) ? INT_MAX : -n;
    if (n < 10) return 1;
    if (n < 100) return 2;
    return 0;
}

void CopiaFracao (int CopiaFracao[T], int Fracao[T]) 
{
  CopiaFracao[0] = Fracao[0];
  CopiaFracao[1] = Fracao[1];
}

void ImprimeMatriz(int Matriz[LINHAS][COLUNAS][T], int LinhaMensagem, char Mensagem[50]) {
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

      // if(Denominador == 1) 
      //   sprintf(NumberString, "%d", Numerador);
      // if(Denominador != 1)
      //   sprintf(NumberString, "%d / %d", Numerador, Denominador);
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
    if(LinhaMensagem == I)
      printf("%s", Mensagem);
    printf("\n");
    for(int K=0;(unsigned)K<strlen(Linha);K++)
      printf("-");
  }
  printf("\n");
}

int ComparaFracao(int Fracao1[T], int Fracao2[T]) {
  int NumIgual = 0;
  int DenIgual = 0;
  if(Fracao1[0] == Fracao2[0])
    NumIgual = 1;

  if(Fracao1[1] == Fracao2[1])
    DenIgual = 1;
  return NumIgual && DenIgual;
}

void SomaFracoes(int Fracao1[T], int Fracao2[T], int Resultado[T]) {
  int Mmc = (Fracao1[1] * Fracao2[1]) / Mdc(Fracao1[1], Fracao2[1]);
  
  int Num1 = Fracao1[0] * (Mmc / Fracao1[1]);
  int Num2 = Fracao2[0] * (Mmc / Fracao2[1]);

  
  int NumResultado = Num1 + Num2;
  int DenResultado = Mmc;


  int Divisor = Mdc(NumResultado, DenResultado);

  NumResultado /= Divisor;
  DenResultado /= Divisor;

  Resultado[0] = NumResultado;
  Resultado[1] = DenResultado;


}

void MultiplicaFracoes(int Fracao1[T], int Fracao2[T], int Resultado[T]) {
  int num_resultado = Fracao1[0] * Fracao2[0];
  int den_resultado = Fracao1[1] * Fracao2[1];

  int divisor = Mdc(num_resultado, den_resultado);
  num_resultado /= divisor;
  den_resultado /= divisor;

  Resultado[0] = num_resultado;
  Resultado[1] = den_resultado;
}

char NomeVariaveis(int id) {
  switch(id)
  {
    case 0:
      return 'x';
    case 1:
      return 'y';
    case 2:
      return 'z';
    default:
      return 'k';
  }
}


int main()
{
  int Matriz[LINHAS][COLUNAS][T] = {{{4,1},{-1,1},{-3,1},{15,1}},{{3,1},{-2,1},{5,1},{-7,1}},{{2,1},{3,1},{4,1},{7,1}}};
  int FracaoUm[T] = {1,1}, Resultado[T], FracaoInversa[T];
  int I, I2, J, J2, FlagColuna, IndexLinhaTroca, Auxiliar[T], FracaoOriginal[T],FracaoTroca[T], Num, Den;
  String Mensagem, MensagemVazia = "";

  for(I=0;I<LINHAS; I++)
    for(J=0;J<COLUNAS; J++)
    {
      system("cls");
      
      printf("Digite o Numerador de  %c%i\n", NomeVariaveis(J), I + 1);
      scanf("%i", &Num);

      printf("Digite o Denominador de  %c%i\n", NomeVariaveis(J), I + 1);
      scanf("%i", &Den);

      system("cls");

      Matriz[I][J][0] = Num;
      Matriz[I][J][1] = Den;
    }
  system("cls");
  strcpy(Mensagem, MensagemVazia);
  ImprimeMatriz(Matriz, -1, Mensagem);
  J =0;
  while(J < COLUNAS - 1)
  {
    for(I=0;I<LINHAS;I++)
    {
      if(I==J) {
        if(Matriz[I][J][0] == 0) {
          strcpy(Mensagem, MensagemVazia);
          sprintf(Mensagem, "L%i <-> L%i", I + 1, I2 + 1);
          ImprimeMatriz(Matriz, I, Mensagem);
          IndexLinhaTroca = 0;
          for(I2 = I; I2 < LINHAS; I2++) {
            if(Matriz[I2][J][0] != 0)
              IndexLinhaTroca = I2;
          }
          for(J2 = 0; J2 < COLUNAS; J2++) {
            CopiaFracao(FracaoOriginal, Matriz[I][J2]);
            CopiaFracao(FracaoTroca, Matriz[IndexLinhaTroca][J2]);

            CopiaFracao(Auxiliar, FracaoOriginal);
            CopiaFracao(Matriz[I][J2], FracaoTroca);
            CopiaFracao(Matriz[IndexLinhaTroca][J2], Auxiliar);
          }
          strcpy(Mensagem, MensagemVazia);
          ImprimeMatriz(Matriz, -1, Mensagem);
        } 
        if(Matriz[I][J][0] != 1) {
            FracaoInversa[0] = Matriz[I][J][1];
            FracaoInversa[1] = Matriz[I][J][0];
            strcpy(Mensagem, MensagemVazia);
            sprintf(Mensagem, "L%i = L%i * %d / %d ", I + 1, I + 1, FracaoInversa[0], FracaoInversa[1]);
            ImprimeMatriz(Matriz, I, Mensagem);

            
            for(J2 = J; J2 < COLUNAS; J2++)
            {
              MultiplicaFracoes(Matriz[I][J2], FracaoInversa, Resultado);

              Matriz[I][J2][0] = Resultado[0];
              Matriz[I][J2][1] = Resultado[1];
            }
            strcpy(Mensagem, MensagemVazia);
            ImprimeMatriz(Matriz, I, Mensagem);
        }
      } else {
        if(ComparaFracao(Matriz[J][J], FracaoUm) && Matriz[I][J][0] != 0) {
            //Oposto do número [-4/1]
            int FracaoOposta[T];
            FracaoOposta[0] = Matriz[I][J][0] * -1; 
            FracaoOposta[1] = Matriz[I][J][1];

            strcpy(Mensagem, MensagemVazia);
            sprintf(Mensagem, "L%i = L%i + L%i * %d / %d ", I + 1, I + 1, J + 1, FracaoOposta[0], FracaoOposta[1]);
            ImprimeMatriz(Matriz, I, Mensagem);

            for(J2 = J;J2 <COLUNAS ;J2++){
              //Multiplicando o oposto da fração pelo elemento da diagonal principal na mesma coluna Jc
              int ResultadoMult[T];
              MultiplicaFracoes(Matriz[J][J2], FracaoOposta, ResultadoMult);

              int ResultadoSoma[T];
              SomaFracoes(Matriz[I][J2], ResultadoMult, ResultadoSoma);

              Matriz[I][J2][0] = ResultadoSoma[0];
              Matriz[I][J2][1] = ResultadoSoma[1];
            }
            strcpy(Mensagem, MensagemVazia);
            ImprimeMatriz(Matriz, I, Mensagem);
        }
      }
    }
    FlagColuna = 0;
    for(I = 0; I < LINHAS; I++)
    {
      if(I == J) 
        if(Matriz[I][J][0])
          FlagColuna++;
      if(I != J)
        if(!Matriz[I][J][0])
          FlagColuna++;
    }
    if(FlagColuna == LINHAS)
      J++;
  }
  printf("\n\n");
  for(I=0;I<LINHAS;I++)
  if(Matriz[I][COLUNAS -1][1] == 1)
    printf("Valor de %c: %i\n", NomeVariaveis(I), Matriz[I][COLUNAS -1][0]);
  else
    printf("Valor de %c: %i/%i\n", NomeVariaveis(I), Matriz[I][COLUNAS -1][0], Matriz[I][COLUNAS -1][1]);
  return 0;
}
