//Author -> fatzzx
#include <stdio.h>
#include "function.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



int main() {
  int coluna, linha, colunas = 3, linhas = 3, numDeJogadores = 2, condicaoDeV = 3, gravidade = 0, m = 0;
  int contador = 0;
   menu(&m, &condicaoDeV, &gravidade, &numDeJogadores, &linhas, &colunas);
  char jogadores[numDeJogadores][60], s[numDeJogadores];
  recebeNomeVersaoFinal(numDeJogadores, jogadores, s);
  char jogodavelha[linhas][colunas];
  inicializaJogoDaVelha(jogodavelha[0], linhas, colunas);
  imprimir_jogo_da_velha(numDeJogadores, jogodavelha[0], jogadores, linhas, colunas);
  switch(gravidade){
    case 0:
       while(1){
        marcaJogoDaVelha(linhas, coluna, linha, jogodavelha[0],colunas,s[contador%numDeJogadores]);
        imprimir_jogo_da_velha(numDeJogadores, jogodavelha[0], jogadores, linhas, colunas);
        if(verificaVencedor(jogodavelha[0],  linhas,  colunas, s[contador%numDeJogadores], condicaoDeV) == 1){
          parabens(jogadores[contador%numDeJogadores]);
          break;
        }
        contador++;
      }
    break;
    case 1:
       while(1){
         marcaJogoDaVelhaGravidade(numDeJogadores, linhas, coluna, linha, jogodavelha[0], colunas, s[contador % numDeJogadores],jogadores);
        imprimir_jogo_da_velha(numDeJogadores, jogodavelha[0], jogadores, linhas, colunas);
        if(verificaVencedor(jogodavelha[0],  linhas,  colunas, s[contador%numDeJogadores], condicaoDeV) == 1){
          parabens(jogadores[contador%numDeJogadores]);
          break;
        }
        contador++;
      }
    break;

    default:
      break;
  }

  return 0;
}