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