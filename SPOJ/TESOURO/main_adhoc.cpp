/* Problema Tesouro - OBI2002
   tesouro.c -- por Guilherme Ottoni 

   Essa solucao nao é minha, mas mostra uma maneira mais eficiente de resolver este problema. 
Naturalmente o problema remete ao problema classico da mochila binária, contudo como ele nao
pede a solucao otima, mas apenas o valor ótimo, podemos resolver de forma mais eficiente cal-
culando todos os possiveis valores obtidos, somando-se os valores dos itens. Ou seja, podemos
calcular se é possivel chegar em um valor objetivo, mas sem dizer como chegar nesse valor.

Perceba que no pior caso, esse algoritmo roda o loop externo N vezes (todos os itens) e para
cada item o FOR interno itera 10500, objetivo maximo (numero exagerado, poderia ser 10100) vezes. 
Essa complexidade de pior caso nao existe puramente, pois os valores dos itens chegam ao maximo de
100, logo seriam necessarios 100 iteracoes para o FOR interno iterar ao valor maximo. E mesmo que
consideremos esse pior caso, a resolucao com P.D. também devolve uma complexidade similar. 
*/

#include <stdio.h>
#include <string.h>

char possivel[10500];
int x, y, n, valores[100];

int main()
{
  int max, objetivo, soma, teste=1, i, j;
  while (scanf("%d %d %d", &x, &y, &n) == 3 && x > 0)
    {
      soma = 0;
      for (i = 0; i < n; i++)
	{
	  scanf("%d", &valores[i]);
	  soma += valores[i];
	}
      printf("Teste %d\n", teste++);
      if ((soma + x + y) % 2 != 0)
	printf("N\n\n");
      else
	{
	  objetivo = (soma + x + y) / 2 - x;
	  memset(possivel, 0, sizeof(possivel));
	  possivel[0] = 1;
	  max = 0;
	  for (i = 0; i < n && !possivel[objetivo]; i++)
	    {
	      for (j = max; j >= 0; j--)
		if (possivel[j])
		  possivel[j+valores[i]] = 1;
	      max += valores[i];
	    }
	  printf("%c\n\n", possivel[objetivo]? 'S' : 'N');
	}      
    }
  return 0;
}
