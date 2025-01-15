#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int MenuPrincipal(){

int escolha;

// Menu de escolhas
printf ("Bem vindo ao Projeto do Diogo | Luis |\n");
printf ("Escolha o que prentende fazer:\n");
printf ("1 - Gerir Estudantes\n");
printf ("2 - Pesquisar Estudantes\n");
printf ("3 - Verificar Listagens\n");
printf ("4 - Exit\n");

scanf("%d",&escolha);

// Validar se o utilizador insere um valor valido no Menu Principal
while (escolha < 1 || escolha > 4)
    {
        printf ("Por favor digite um valor valido\n\n");
        escolha = MenuPrincipal();
    }

return escolha;

}

int Gerir(){

    int escolha;

    // Menu para Gerir
    printf ("O que pretende fazer:\n");
    printf ("1 - Adicionar Aluno\n");
    printf ("2 - Editar um Aluno\n");
    printf ("3 - Remover um Aluno\n");

    scanf ("%d", &escolha);

    // Verificar se o utilizador insere um valor valido em Gerir
    while (escolha < 1 || escolha > 3)
    {
        printf ("Por favor digite um valor valido\n\n");
        escolha = Gerir();
    }

    switch (escolha)
    {
    case 1:
        
        break;

    case 2:
        EditarAluno();
        break;

    case 3:
        RemoverAluno();
        break;
    }

    return escolha;
}

int Pesquisar(){

    int escolha;

    // Menu para Pesquisar
    printf ("Como pretende realizar a sua pesquisa:\n");
    printf ("1 - Pelo primeiro nome\n");
    printf ("2 - Pelo ID\n");

    scanf ("%d", &escolha);

    // Verificar se o utilizador insere um valor valido em Gerir
    while (escolha < 1 || escolha > 2)
    {
        printf ("Por favor digite um valor valido\n\n");
        escolha = Pesquisar();
    }

    switch (escolha)
    {
    case 1:
        PesquisarAluno();
        break;

    case 2:
        PesquisarID();
        break;

    return escolha;
    }
}

int Verificar(){

   int escolha;

    // Menu para Gerir
    printf ("Como pretende ordenar a sua listagem:\n");
    printf ("1 - Por curso\n");
    printf ("2 - Todos os Alunos\n");

    scanf ("%d", &escolha);

    // Verificar se o utilizador insere um valor valido em Gerir
    while (escolha < 1 || escolha > 2)
    {
        printf ("Por favor digite um valor valido\n\n");
        escolha = Verificar();
    }

    switch (escolha)
    {
    case 1:
        VerificarCurso();
        break;

    case 2:
        VerificarAll();
        break;

    return escolha;
} 
}

int main () {


    // Ir para o Menu Principal
    switch (MenuPrincipal())
    {
    case 1: // O utilizador inseriu a opcao 1 - Gerir Utilizadores
        Gerir();
        break;
    
    case 2:
        Pesquisar();
        break;
    
    case 3:
        Verificar();
        break;
    
    case 4:
        printf("Obrigado pelo seu apoio");
        break;    
    }

    return 0;
}