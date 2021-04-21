#include <stdio.h>
#include <stdlib.h>
#define tamanho 30

int pessoas[tamanho];
int numeroPessoas;
int quantum;

void produtos()
{
    int produtosComprar;

    for(int i = 1; i <= numeroPessoas; i++)
    {
        printf("\nDigite o numero de produtos para comprar da pessoa %d: ", i);
        scanf("%d", &produtosComprar);
        pessoas[i] = produtosComprar;
    }
}

void fila()
{
    int contagemFila = numeroPessoas;
    int primeiroFila = 1;
    
    while (contagemFila !=0)
    {
        while (pessoas[primeiroFila] <= 0)
        {
            primeiroFila++;
            if (primeiroFila >= numeroPessoas)
            {
                primeiroFila = 0;
            }
        }
        printf("\n\nA pessoa %d vai ao caixa com %d produtos", primeiroFila,pessoas[primeiroFila]);
        printf("\npaga ate %d produtos", quantum);
        pessoas[primeiroFila] = pessoas[primeiroFila] - quantum;
        if (pessoas[primeiroFila] <= 0)
        {
            printf("\nE sai do caixa");
            contagemFila--;
        }
        else
        {
            printf("\nE vai pro final da fila com %d produtos a pagar restantes.\n",pessoas[primeiroFila]);
        };
        primeiroFila++;
        if (primeiroFila > numeroPessoas)
        {
            primeiroFila = 0;
        }
    }
}

int main()
{
    printf("\nDigite o numero maximo de produtos a pagar no caixa:");
    scanf("%d", &quantum);
    printf("\nDigite o numero de pessoas na fila do caixa:");
    scanf("%d", &numeroPessoas);
    produtos();
    fila();
    printf("\n\nFila vazia!");
    getchar();
    return 0;
}