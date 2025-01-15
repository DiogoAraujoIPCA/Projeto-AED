
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    int id;
    char DataNacimento[15];
    char NomeCompleto[50];
    char Morada[50];
    char Curso[20];
    bool Estado;

} Estudante;

Estudante ListasEstudantes[300];
Estudante ListasEstudantesProcurados[50];

#pragma region LerEstudantes

 // Funcionalidades Principais
    void LerEstudantes()
    {

        int totalEstudantes = 0; // Contador para o número de estudantes

        // Abrir o arquivo para leitura
        FILE *filedp = fopen("C:\\Users\\Diogo Araujo\\Desktop\\Teste\\Lista.txt", "r");
        if (filedp == NULL)
        {
            printf("Erro ao abrir o arquivo para leitura.\n");
        }

        // Definir o delimitador
        const char delimiter[] = ";";
        char linha[256];
        // Ler linha por linha
        while (fgets(linha, sizeof(linha), filedp))
        {

            int posicaotoken = 0; // Reiniciar a posição dos tokens para cada linha

            char *token = strtok(linha, delimiter);

            // Processar cada token
            while (token != NULL)
            {
                switch (posicaotoken)
                {
                case 0:                                                 // ID
                    ListasEstudantes[totalEstudantes].id = atoi(token); // Converter para inteiro
                    break;
                case 1: // Nome Completo
                    strcpy(ListasEstudantes[totalEstudantes].NomeCompleto, token);
                    break;
                case 2: // Data de Nascimento
                    strcpy(ListasEstudantes[totalEstudantes].DataNacimento, token);
                    break;
                case 3: // Morada
                    strcpy(ListasEstudantes[totalEstudantes].Morada, token);
                    break;
                case 4: // Curso
                    strcpy(ListasEstudantes[totalEstudantes].Curso, token);
                    printf("%s", ListasEstudantes[totalEstudantes].Curso);
                    break;
                default:
                    printf("Token desconhecido na posição %d: %s\n", posicaotoken + 1, token);
                    break;
                }
                posicaotoken++;                  // Incrementar a posição do token
                token = strtok(NULL, delimiter); // Pegar o próximo token
            }
            ListasEstudantes[totalEstudantes].Estado = true;
            totalEstudantes++; // Incrementar o número de estudantes
        }

        fclose(filedp); // Fechar o arquivo após a leitura
    }

#pragma endregion LerEstudantes
   
#pragma region PesquisarUtilizador
Estudante PesquisarUtilizador(int ID)
{

    Estudante EstudanteProcurado;
    Estudante *EstudanteProcurado1;

    for (int i = 0; i < 300; i++)
    {

        if (ListasEstudantes[i].id - 1 == ID - 1)
        {

            EstudanteProcurado.id = ListasEstudantes[ID - 1].id;
            strcpy(EstudanteProcurado.NomeCompleto, ListasEstudantes[ID - 1].NomeCompleto);
            strcpy(EstudanteProcurado.Curso, ListasEstudantes[ID - 1].Curso);
            strcpy(EstudanteProcurado.Morada, ListasEstudantes[ID - 1].Morada);
            strcpy(EstudanteProcurado.DataNacimento, ListasEstudantes[ID - 1].DataNacimento);


                return EstudanteProcurado;
            //ExibirDadosEstudante(EstudanteProcurado);
        }
        break;
    }
}

void ExibirDadosEstudante(Estudante DadosEstudante)
{
    printf("ID: %d\n", DadosEstudante.id);
    printf("Nome Completo: %s\n", DadosEstudante.NomeCompleto);
    printf("Curso: %s\n", DadosEstudante.Curso);
    printf("Morada: %s\n", DadosEstudante.Morada);
    printf("Data de Nascimento: %s\n", DadosEstudante.DataNacimento);
}
#pragma endregion PesquisarUtilizador

#pragma region Pesquisar1ºNome
void PesquisarPorPrimeiroNome(char Nome[], Estudante *ListasEstudantesProcurados)
{

    int i = 0, a = 0; // Indicador para Posição na Lista

    bool flag = false; // Flag para verificar se já foi Encontrado Estudante
    char PrimeiroNome[10];

    // Copiar valor de parametro para variavel local e Incrementar o Espaço em branco
    strcpy(PrimeiroNome, Nome);
    strcat(PrimeiroNome, " ");

    char *resultado;

    for (int i = 0; i < 299; i++)
    {

        // Compara a Existencia de Substring com o valor Parameterizado , retornado uma string
        resultado = strstr(ListasEstudantes[i].NomeCompleto, Nome);

        if (resultado != NULL)
        {

            ListasEstudantesProcurados[a] = ListasEstudantes[i];
            a++;
        }
    }
}

void ExibirDadosEstudantesProcurados(Estudante *ListasEstudantesProcurados)
{

    printf("\nDados Estudantes Procurados:\n");

    for (int i = 0; i < 49; i++)
    {

        if (ListasEstudantesProcurados[i].id != 0)
        {
            printf("ID : %d \n", ListasEstudantesProcurados[i].id);
            printf("Nome Completo : %s \n", ListasEstudantesProcurados[i].NomeCompleto);
            printf("Data Nascimento: %s \n", ListasEstudantesProcurados[i].DataNacimento);

            printf("Morada : %s \n", ListasEstudantesProcurados[i].Morada);
            printf("Curso : %s \n", ListasEstudantesProcurados[i].Curso);
        }
    }
}

#pragma endregion Pesquisar1ºNome


int main()
{

    // CriarAluno();
    LerEstudantes();

    PesquisarUtilizador(1);

    char nome[] = "Pedro";
    Estudante *ListasEstudantesProcurados1 = ListasEstudantesProcurados;
    PesquisarPorPrimeiroNome(nome, ListasEstudantesProcurados1);

    ExibirDadosEstudantesProcurados(ListasEstudantesProcurados1);

    return 0;
}


void MenuFimProcesso(){

    int ProximoProcesso;
    printf("Processo conlcuido : \n 1)Realizar Novamente \n 2) Voltar Menu Funcionalidade 3)Sair");
    scanf("%d",&ProximoProcesso);


    switch(ProximoProcesso){

         case 1:


         break;


          case 2:

         break;


          case 3:

         break;



         default:


         break;
    }

   
}

 