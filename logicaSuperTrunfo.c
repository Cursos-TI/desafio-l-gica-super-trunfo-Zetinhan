//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

#define numestados 2
#define cidadesporestado 1

//Classe da Cidade
typedef struct {
    char estado;
    char cidade;
    long populacao;
    long pib;
    float area;
    int ponturistico;
} Cidade;

//Cadastro de cidade
int CadastrarCidade(Cidade *cidade)
{
    printf("\n Cadastro da Cidade %c%02d\n", cidade -> estado, cidade -> cidade );
    printf("\n Digite a População: \n");
    if (scanf("%ld", &cidade -> populacao) != 1) return 0; //retorna 0 caso esteja errado
    printf("\n Digite o PIB: \n");
    if (scanf("%ld", &cidade -> pib) != 1) return 0; //retorna 0 caso esteja errado
    printf("\n Digite a área: \n");
    if (scanf("%2f", &cidade -> area) != 1) return 0; //retorna 0 caso esteja errado
    printf("\nDigite a Quantidade de Pontos Turísticos que possui: \n");
    if (scanf("%d", &cidade -> ponturistico) != 1) return 0; //retorna 0 caso esteja errado
    return 1; //caso esteja tudo certo
}

//Exibição de cidade
int ExibirCidade(Cidade cidade)
{
    printf("\nCidade %c%02d", cidade.estado, cidade.cidade);
    printf("\n Com %ld pessoas residentes\n", cidade.populacao);
    printf("\n Com o PIB de %ld", cidade.pib);
    printf("\n De área %2f", cidade.area);
    printf("\n Com %d pontos turísticos", cidade.ponturistico);
    return 1; //caso dê tudo certo
}


//Comparação entre cidades e definindo vencedor
int CompararCidade(Cidade cidade1, Cidade cidade2)
{
    int pontos1 = 0, pontos2 = 0;

    if (cidade1.populacao > cidade2.populacao) pontos1++;
    else if (cidade2.populacao > cidade1.populacao) pontos2++;

    if (cidade1.pib > cidade2.pib) pontos1++;
    else if (cidade2.pib > cidade1.pib) pontos2++;

    if (cidade1.area > cidade2.area) pontos1++;
    else if (cidade2.area > cidade1.area) pontos2++;

    if (cidade1.ponturistico > cidade2.ponturistico) pontos1++;
    else if (cidade2.ponturistico > cidade1.ponturistico) pontos2++;

    printf("\n Comparando as cidades %c%02d e %c%02d\n", cidade1.estado, cidade1.cidade, cidade2.estado, cidade2.cidade);
    if (pontos1 > pontos2)
    {
        printf("\n A Cidade %c%02d é a vencedora \n", cidade1.estado, cidade1.cidade);
    }
    else if (pontos2 > pontos1)
    {
        printf("\n A cidade %c%02d é a vencedora \n", cidade2.estado, cidade2.cidade);
    }
    else
    {
        printf("Empate");
    }

    return 1;//pra caso o código dê certo
}
    

    
int main()
{
    Cidade cidades[numestados][cidadesporestado];
    char estados[] = {'A', 'B'};

    //Cadastro de cidade
    for (int i = 0; i < numestados; i++)
    {
        for (int j = 0; j < cidadesporestado; j++)
        {
            cidades[i][j].estado = estados[i];
            cidades[i][j].cidade = j + 1;

            if (!CadastrarCidade(&cidades[i][j]))
            {
                printf("\n Erro ao cadastrar cidade %c%02d\n", estados[i], j + 1);
                return 1;//retornando em caso de erro.
            }
        }
    }

    //Exibição da Cidade
    for (int i = 0; i < numestados; i++)
    {
        for (int j = 0; j < cidadesporestado; j++)
        {
            if (!ExibirCidade(cidades[i][j]))
            {
                printf("\n Erro ao exibir Cidade %c%02d\n", estados[i], j + 1);
                return 1;//retornando em caso de erro.
            }
        }
    }

    //Comparação das cidades
    CompararCidade(cidades[0][0], cidades[1][0]);
    
    return 0;
    
}