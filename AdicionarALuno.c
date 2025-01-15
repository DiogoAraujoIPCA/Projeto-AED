#include <stdio.h>
// Criar a estrutura "Aluno"
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
    typedef struct
    {
        
        int id;
        char nome[100], curso [100];
        datas nascimento;
        morada morada;
    }estudante;

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
        fgets(estudantes[i].morada.rua, sizeof(estudantes[i].morada), stdin);     
        printf ("Nº da Porta: ");
         fgets(estudantes[i].morada.porta, sizeof(estudantes[i].morada), stdin);   
        printf ("Codigo Postal: ");
         fgets(estudantes[i].morada.postal, sizeof(estudantes[i].morada), stdin);        

        printf ("Digite o seu Curso: ");
        fgets(estudantes[i].curso, sizeof(estudantes[i].curso), stdin);

        printf ("Digite a sua data de Nascimento:\n");
        printf ("Ano: ");
        scanf ("%d", &estudantes[i].nascimento.ano);

        printf ("Mes: ");
        scanf ("%d", &estudantes[i].nascimento.mes);

        printf ("Dia: ");
        scanf ("%d", &estudantes[i].nascimento.dia);

        getchar ();
    }

        for (int i = 0; i < a; i++) {

        fprintf(ficheiro,"%d;%s;%s;%s;%d;\n", estudantes[i].id, estudantes[i].nome, estudantes[i].morada, estudantes[i].curso, estudantes[i].nascimento);

    }
    
    fclose(ficheiro);

    printf("Dados guardados com sucesso no ficheiro '%s'!\n", nome_fich);

    return 0;

    //Teste
    
}