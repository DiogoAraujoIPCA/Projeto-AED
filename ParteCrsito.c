#include <stdio.h>

// Criar a estrutura "Aluno"
    typedef struct
    {
        int id;
        char nome[100], curso [100];
        datas nascimento;
        morada morada;
    }estudante;

    typedef struct
    {
        int ano, mes, dia;
    }datas;

     typedef struct
    {
        char rua;
        char porta;
        char postal;
    }morada;

int MenuPrincipal(){

int escolha;

// Menu de escolhas
printf ("Bem vindo\n");
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

void EditarAluno(){
    printf ("Editar Aluno");
}

void RemoverAluno(){
    printf ("Remover Aluno");
}

int AdicionarAluno(){

    int a;
    FILE *ficheiro;
    char nome_fich[] = "ListaAlunos.txt";

    printf ("Quantos estudantes vai inserir: ");
    scanf ("%d", &a);
    getchar ();

    estudante estudantes[2500];
    

    ficheiro = fopen(nome_fich, "a");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return 1;
    }

    //Criar o(s) Aluno(s)
    for (int i = 0; i < a; i++)
    {
        printf ("\nDigite o seu Numero Mecanografico: ");
        scanf ("%d", &estudantes[i].id);

        printf ("Digite o seu nome Completo: ");
        fgets(estudantes[i].nome, sizeof(estudantes[i].nome), stdin);
        getchar ();

        printf ("Digite a sua Morada:\n");
        printf ("Rua: ");
        printf ("Nº da Porta: ");
        printf ("Codigo Postal: ");
        fgets(estudantes[i].morada, sizeof(estudantes[i].morada), stdin);        

        printf ("Digite o seu Curso: ");
        fgets(estudantes[i].curso, sizeof(estudantes[i].curso), stdin);

        printf ("Digite a sua data de Nascimento:\n");
        printf ("Ano: ");
        scanf ("%d", &estudantes[i].);

        printf ("Mes: ");
        scanf ("%d", &estudantes[i].mes);

        printf ("Dia: ");
        scanf ("%d", &estudantes[i].dia);

        getchar ();
    }

        for (int i = 0; i < a; i++) {

        fprintf(ficheiro,"%d;%s;%s;%s;%d;%d;%d\n", estudantes[i].id, estudantes[i].nome, estudantes[i].morada, estudantes[i].curso, estudantes[i].mes, estudantes[i].dia, estudantes[i].ano);

    }
    
    fclose(ficheiro);

    printf("Dados guardados com sucesso no ficheiro '%s'!\n", nome_fich);

    return 0;
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
        AdicionarAluno();
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

int PesquisarAluno(){

}

int PesquisarID(){

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

int VerificarCurso(){

}

int VerificarAll(){

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