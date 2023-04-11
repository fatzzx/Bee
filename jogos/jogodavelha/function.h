// Author -> fatzzx
#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Prof se estiver usando o dev só precisa mudar essa função para rodar
void limpaTerminal()
{
  system("cls"); // Seria system("cls"); no caso
}

void recebe_nome_usuario(char *nome)
{
  fgets(nome, sizeof(char[60]), stdin);
  strtok(nome, "\n");
}

void perguntaNumeroDeJogadores(int *numDeJogadores)
{
  printf("Quantos jogadores vao jogar\n");
  scanf("%d", numDeJogadores);
  getchar();
}

void recebeLinhaseColunas(int *linhas, int *colunas)
{
  printf("Me fale o numero de linhas e colunas");
  scanf("%d  %d", linhas, colunas);
}

int tamanho(char *string)
{
  int contador = 0;
  int i = 0;
  while (string[i] != '\0')
  {
    if (string[i] != ' ')
    {
      contador++;
    }
    i++;
  }
  return contador;
}

void escolheSimbolo(char *s)
{
  printf("Escolha seu simbolo\n");
  scanf(" %c", s);
  // getchar();
}

void recebeNomeVersaoFinal(int numDeJogadores, char jogadores[][60], char *s)
{
  for (int i = 0; i < numDeJogadores; i++)
  {
    printf("Nome e sobrenome do %d usuario:\n", i + 1);
    recebe_nome_usuario(jogadores[i]);
    escolheSimbolo(s);
    getchar();
    s++;
  }
}
// As funções de asterisco servem para deixar o cabeçalho "responsivo" com base na quandidade de letras do total de jogadores de forma que não fique desproporcional
void asterisco(int num_jogadores, char jogadores[][60])
{
  int total = 0;
  for (int i = 0; i < num_jogadores; i++)
  {
    total += strlen(jogadores[i]);
  }
  for (int i = 0; i <= total; i++)
  {
    printf("*");
  }
}

void asterisco2(int num_jogadores, char jogadores[][60])
{
  printf("**");
  int total = 0;
  for (int i = 0; i < num_jogadores; i++)
  {
    total += strlen(jogadores[i]);
  }
  if (total % 2 != 0)
  {
    printf("*");
  }
  for (int i = 0; i <= total / 2; i++)
  {
    printf("*");
  }
}

void cabecalho(int num_jogadores, char jogadores[][60])
{

  limpaTerminal();
  printf("**************************");
  asterisco(num_jogadores, jogadores);
  printf("\n");
  asterisco2(num_jogadores, jogadores);
  printf("*** JOGO DA VELHA ***");
  asterisco2(num_jogadores, jogadores);
  printf("\n");
  printf("**************************");
  asterisco(num_jogadores, jogadores);
  printf("\n\n");
  printf("Nome dos jogadores:\n");
  for (int i = 0; i < num_jogadores; i++)
  {
    printf("Jogador %d: %s\n", i + 1, jogadores[i]);
  }
  printf("Boa sorte jogadores");
  for (int i = 0; i < num_jogadores; i++)
  {
    printf(" %s", jogadores[i]);
  }
  printf("\n\n");
  printf("**************************");
  asterisco(num_jogadores, jogadores);
  printf("\n\n");
}

void inicializaJogoDaVelha(char *jogoDaVelha, int linhas, int colunas)
{
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      *jogoDaVelha = ' ';
      jogoDaVelha++;
    }
  }
}

void cabecalhoCima(int linhas)
{
  int i;
  printf("  ");
  for (i = 1; i <= linhas; i++)
  {
    printf("%d | ", i);
  }
  printf("\n");
}

void linhabaixo(int linhas)
{
  printf("----");
  for (int i = 0; i <= linhas; i++)
  {
    printf("---");
  }
  printf("\n");
}

void imprimir_jogo_da_velha(int numDeJogadores, char *jogo_da_velha, char jogadores[][60], int linhas, int colunas)
{
  limpaTerminal();
  cabecalho(numDeJogadores, jogadores);
  int i, j;
  cabecalhoCima(linhas);
  linhabaixo(linhas);
  for (i = 0; i < colunas; i++)
  {
    printf("%d ", i + 1);
    for (j = 0; j < colunas; j++)
    {
      printf("%c", *jogo_da_velha);
      jogo_da_velha++;
      if (j < colunas)
      {
        printf(" | ");
      }
    }
    printf("\n");
    if (i < colunas)
    {
      linhabaixo(linhas);
    }
  }
}

void perguntaColunaELinha(int *coluna, int *linha)
{
  printf("\n\nQual a coluna que deseja inserir\n");
  scanf("%d", coluna);
  printf("\n\nQual a linha que deseja inserir\n");
  scanf("%d", linha);
}

int verifica_condicoes(int linhas, int colunas, int linha, int coluna, char *jogoDaVelha)
{

  if (linha < 1 || linha > linhas || coluna < 1 || coluna > colunas)
  {
    return 0;
  }
  if (*(jogoDaVelha + (linha - 1) * colunas + coluna - 1) != ' ')
  {
    return 0;
  }
  return 1;
}

void marcaJogoDaVelha(int linhas, int coluna, int linha, char *jogoDaVelha, int colunas, char s)
{

  perguntaColunaELinha(&coluna, &linha);
  while (!verifica_condicoes(linhas, colunas, linha, coluna, jogoDaVelha))
  {
    printf("posicao invalida");
    perguntaColunaELinha(&coluna, &linha);
  }

  jogoDaVelha += (((linha * linhas) - (linhas - coluna)) - 1);

  *jogoDaVelha = s;
}

void marcaJogoDaVelhaGravidadeAoContrario(int numDeJogadores, int linhas, int coluna, int linha, char *jogoDaVelha, int colunas, char s, char jogadores[][60])
{
  perguntaColunaELinha(&coluna, &linha);

  while (!verifica_condicoes(linhas, colunas, linha, coluna, jogoDaVelha))
  {
    printf("posicao invalida");
    perguntaColunaELinha(&coluna, &linha);
  }

  int index = (((linha * linhas) - (linhas - coluna)) - 1);
  int i;
  for (i = linhas - 1; i >= 0; i--)
  {
    index = i * colunas + (coluna - 1);
    if (jogoDaVelha[index] == ' ')
    {
      jogoDaVelha[index] = s;
      imprimir_jogo_da_velha(numDeJogadores, jogoDaVelha, jogadores, linhas, colunas);
      jogoDaVelha[index] = ' ';
      sleep(1);
    }
    else
    {
      break;
    }
  }
  jogoDaVelha[(i + 1) * colunas + (coluna - 1)] = s;
  imprimir_jogo_da_velha(numDeJogadores, jogoDaVelha, jogadores, linhas, colunas);
}

void marcaJogoDaVelhaGravidade(int numDeJogadores, int linhas, int coluna, int linha, char *jogoDaVelha, int colunas, char s, char jogadores[][60])
{
  perguntaColunaELinha(&coluna, &linha);

  while (!verifica_condicoes(linhas, colunas, linha, coluna, jogoDaVelha))
  {
    printf("posicao invalida");
    perguntaColunaELinha(&coluna, &linha);
  }

  int index = (linha - 1) * colunas + (coluna - 1);
  int i;
  for (i = linha - 1; i < linhas; i++)
  {
    index = i * colunas + (coluna - 1);
    if (jogoDaVelha[index] == ' ')
    {
      jogoDaVelha[index] = s;
      imprimir_jogo_da_velha(numDeJogadores, jogoDaVelha, jogadores, linhas, colunas);
      jogoDaVelha[index] = ' ';
      usleep(500 * 1000);
    }
    else
    {
      break;
    }
  }
  jogoDaVelha[(i - 1) * colunas + (coluna - 1)] = s;
  imprimir_jogo_da_velha(numDeJogadores, jogoDaVelha, jogadores, linhas, colunas);
}

int verificaVencedor(int num_jogadores, char jogadores[][60], char *jogo_da_velha, int linhas, int colunas, char simbolo, int condicaoDeVitoria)
{
  // Verifica as linhas
  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j <= colunas - condicaoDeVitoria; j++)
    {
      int linha_vencedora = 1;
      char *p = jogo_da_velha + i * colunas + j;
      for (int k = 0; k < condicaoDeVitoria; k++)
      {
        if (*p != simbolo)
        {
          linha_vencedora = 0;
          break;
        }
        p++;
      }
      if (linha_vencedora)
      {
        return 1;
      }
    }
  }

  // Verifica as colunas
  for (int i = 0; i < colunas; i++)
  {
    for (int j = 0; j <= linhas - condicaoDeVitoria; j++)
    {
      int coluna_vencedora = 1;
      char *p = jogo_da_velha + j * colunas + i;
      for (int k = 0; k < condicaoDeVitoria; k++)
      {
        if (*p != simbolo)
        {
          coluna_vencedora = 0;
          break;
        }
        p += colunas;
      }
      if (coluna_vencedora)
      {
        return 1;
      }
    }
  }

  // Verifica a diagonal principal
  for (int i = 0; i <= linhas - condicaoDeVitoria; i++)
  {
    for (int j = 0; j <= colunas - condicaoDeVitoria; j++)
    {
      int diagonal_principal_vencedora = 1;
      char *p = jogo_da_velha + i * colunas + j;
      for (int k = 0; k < condicaoDeVitoria; k++)
      {
        if (*p != simbolo)
        {
          diagonal_principal_vencedora = 0;
          break;
        }
        p += colunas + 1;
      }
      if (diagonal_principal_vencedora)
      {
        return 1;
      }
    }
  }

  // Verifica a diagonal secundária
  for (int i = 0; i <= linhas - condicaoDeVitoria; i++)
  {
    for (int j = condicaoDeVitoria - 1; j < colunas; j++)
    {
      int diagonal_secundaria_vencedora = 1;
      char *p = jogo_da_velha + i * colunas + j;
      for (int k = 0; k < condicaoDeVitoria; k++)
      {
        if (*p != simbolo)
        {
          diagonal_secundaria_vencedora = 0;
          break;
        }
        p += colunas - 1;
      }
      if (diagonal_secundaria_vencedora)
      {
        return 1;
      }
    }
  }

  // Verifica se houve empate
  char *q = jogo_da_velha;
  for (int i = 0; i < linhas * colunas; i++)
  {
    if (*q == ' ')
    {
      return 0;
    }
    q++;
  }
  return 0;
}

void bemVindo()
{
  printf("       _______\n");
  printf("     _/       \\_\n");
  printf("    / |       | \\ \n");
  printf("   /  |__   __|  \\\n");
  printf("  |__/((o| |o))\\__|\n");
  printf("  |      | |      |\n");
  printf("  |\\     |_|     /|       -----------------\n");
  printf("  | \\           / |      |                 |\n");
  printf("   \\| /  ___  \\ |/   --- |Bem Vindo Soussa |\n");
  printf("    \\ | / _ \\ | /        |                 |\n");
  printf("     \\_________/          -----------------\n");
  printf("      _|_____|_\n");
  printf(" ____|_________|____\n");
  printf("/                   \\\n\n\n");
  sleep(3);
  limpaTerminal();

  printf("       _______\n");
  printf("     _/       \\_\n");
  printf("    / |       | \\ \n");
  printf("   /  |__   __|  \\\n");
  printf("  |__/((o| |o))\\__|\n");
  printf("  |      | |      |\n");
  printf("  |\\     |_|     /|       -----------------------\n");
  printf("  | \\           / |      |                       |\n");
  printf("   \\| /  ___  \\ |/   --- |O menu ja ira aparecer |\n");
  printf("    \\ | / _ \\ | /        |                       |\n");
  printf("     \\_________/          ------------------------\n");
  printf("      _|_____|_\n");
  printf(" ____|_________|____\n");
  printf("/                   \\\n\n\n");
  sleep(3);
  limpaTerminal();
  printf("Bem vindo ao jogo da velha de Fatzzx\n\n");
  printf("                                    @%%%%<\n");
  printf("1 -> Comecar jogo                   ()()-b\n");
  printf("2 -> Regras especiais         .     <   |\n");
  printf("                               \\   \\_C7_|_\n");
  printf("                               8]J=|_:|_|\\3\n");
  printf("                                   /_/_n|\n");

  printf("\n\nDigite 1 ou 2 \n");
}

void perguntaCondicaoVeGravidade(int *n, int *g)
{
  printf("Qual a condicao de vitoria\n");
  scanf("%d", n);
  // getchar();
  printf("Deseja adicionar gravidade, se sim digite 1 e se nao digite 0\n");
  scanf("%d", g);
  while (*g != 1 && *g != 0)
  {
    printf("Digite ou 1 ou 0\n");
    scanf("%d", g);
  }
  getchar();
}

void menu(int *m, int *n, int *g, int *numDeJogadores, int *linhas, int *colunas)
{
  bemVindo();
  while (1)
  {
    scanf("%d", m);
    if (*m == 1)
    {
      break;
    }

    else if (*m == 2)
    {
      perguntaCondicaoVeGravidade(n, g);
      perguntaNumeroDeJogadores(numDeJogadores);
      recebeLinhaseColunas(linhas, colunas);
      break;
    }
    else
    {
      printf("responda certo\n");
    }
  }
  getchar();
}

void parabens(int numDeJogadores, char jogadores[][60])
{
  printf(" /^ ^\\\n");
  printf("/ 0 0 \\\n");
  printf("V\\ Y /V    --> parabens %s, voce venceu!\n", jogadores);
  printf(" / - \\\n");
  printf(" |    \\\n");
  printf(" || (__V\n");
}

#endif