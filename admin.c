#include "sgc.h"

    //logar administrador
void logarAdmin() {
    struct Administrador *adm = (struct Administrador *)malloc(sizeof(struct Administrador));
    strcpy(adm[0].nomeAdm, "lulu");       
    adm[0].senhaAdm = 666;
    char nomeAdm[50];
    int senhaAdm;
    printf("Usuário: ");
    scanf(" %[^\n]s", nomeAdm);
    printf("Senha: ");
    scanf("%d", &senhaAdm);
    
    if (adm == NULL) {
        printf("Não há memória disponível.");
    }
    
    if ((strcmp(nomeAdm, adm[0].nomeAdm) == 0) && (senhaAdm == adm[0].senhaAdm)) {
        gerenciaAdmin();
    } 
    
    else {
        printf("Usuário não encontrado ou inexistente.");
    }
}

    //menu do administrador
void gerenciaAdmin(struct Produto *produto, struct User *user, int *tamanho, int *tam){
    
    int op;
    printf("\n----------------------------\n\n");
    printf("Página do Administrador\n");
    printf("\n----------------------------\n\n");
    
    do {
        printf("1. Adicionar novo produto ao estoque\n");
        printf("2. Exibir a lista de produtos\n");
        printf("3. Adicionar novo usuário\n");
        printf("4. Exibir lista de usuários\n");
        printf("5. Excluir usuário\n");
        printf("6. Retornar ao menu de login\n");
        printf("7. Encerrar\n");
        printf(">> ");
    
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                listaProdutos();
                break;
            case 3:
                adicionarUser();
                break;
            case 4:
                listaUsuarios();
                break;
            case 5:
                excluirUser();
                break;
            case 6:
                logarAdmin();
                break;
            case 7:
                printf("Obrigada pela interação. Até mais!");
                exit(1);
            default:
                printf("Alternativa inválida.");
                break;
        }
    } while (op != 7);
}

    //adiciona produto ao estoque
void adicionarProduto(struct Produto *produto, int *tamanho) {
    
    struct Produto produtoAdic;

    produtoAdic.nomeProd == (char *)malloc(MAX_NOME_PROD * sizeof(char));

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", produtoAdic.nomeProd);

    printf("Digite o preço do produto: ");
    scanf("%f", &produtoAdic.preco);
    
    printf("Digite a quantidade disponível: ");
    scanf("%d", &produtoAdic.quantidade);

    produto[(*tamanho)++] = produtoAdic;
    
    printf("Novo produto adicionado!\n");
    
    salvarProdutos(produto, tamanho);
}

    //lista produtos em estoque
void listaProdutos(struct Produto *produto, int tamanho) {
    if (tamanho > 0){    
        printf("Lista de produtos em estoque:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("Nome : %s \n", produto[i].nomeProd);
            printf("Preço: R$ %.2f\n", produto[i].preco);
            printf("Quantidade disponível: %d\n", produto[i].quantidade);
            printf("\n");
        }
    }
    else{
        printf("Não há produtos no estoque.\n");
    }
}

    //adiciona usuário
void adicionarUser(struct User *user, int *tam) {
    struct User userAdic;

    userAdic.nomeUser == (char *)malloc(MAX_NOME_USER * sizeof(char));

    int escolha;

    if (userAdic.nomeUser == NULL){
        printf("Erro na alocação de memória.\n");
    }

    printf("Defina o nível de privilégio do novo usuário:\n");
    printf("1. Administrador\t 2. Convencional\n");
    scanf("%d", &escolha);
    
    if (escolha == 1){
        userAdic.nivel = 1;
    }
    else if (escolha == 2){
        userAdic.nivel = 2;
    }
    else{
        printf("Escolha impossível.\n");
    }
    printf("Nome do usuário: ");
    scanf(" %[^\n]s", userAdic.nomeUser);

    printf("Senha do usuário:");
    scanf(" %[^\n]s", userAdic.senhaUser);

    
    user[(*tam)++] = userAdic;
    
    printf("Cadastro de novo usuário realizado.\n");
    
    salvarUser(user, tam);

}

    //mostra lista de usuários
void listaUsuarios(struct User *user, int tam) {
        if (tam > 0){
        printf("\n----------------------------\n\n");
        printf("Lista de Usuários\n");
        
        for (int i = 0; i < tam; i++){
            printf("--------------------------------------------------------\n\n");
            printf("Nome: %s\n", user[i].nomeUser);
            printf("Senha: %s\n", user[i].senhaUser);
            printf("Nível: %s\n", (user[i].nivel == 1) ? "Administrador" : "Convencional");
            printf("\n--------------------------------------------------------\n\n");
        }
    }
    else{
        printf("Nenhum usuário.\n");
    }
}

    //exclui usuário do sistema
void excluirUser(struct User *user, int *tam) {
    int nome, userEncontrado = 0;
    
    printf("Digite o nome do usuário que deseja excluir:\n");
    scanf("%d", &nome);
    
    for (int i = 0; i < *tam; i++) {
        if (nome == user[i].nomeUser) {
            printf("Nome: %s\n", user[i].nomeUser);
            printf("Senha: %s\n", user[i].senhaUser);
            printf("Nível: %s\n", user[i].nivel  ? "Administrador" : "Convencional");
            userEncontrado = 1;
            
            for (int j = i; j < *tam - 1; j++) {
                user[j] = user[j + 1];
            }
            printf("Exclusão realizada.\n");
            (*tam)--;
        }
    }
    
    if (!userEncontrado) {
        printf("Usuário não encontrado.\n");
    }
}

    //adiciona novo produto
void salvarProdutos(struct Produto *produto, int *tamanho){
    FILE *fp;
    fp = fopen("estoque.txt", "w");
    
    if (fp == NULL) {
        printf("Erro na abertura do arquivo de usuários.\n");
        exit(1);
    }
    
    for (int i = 0; i < *tamanho; i++) {
        printf("\n----------------------------\n\n");
        fprintf(fp,"Nome: %s\n", produto[i].nomeProd);
        fprintf(fp,"Estoque: %d\n", produto[i].quantidade);
        fprintf(fp,"Preço: %.2f\n", produto[i].preco);
        printf("\n----------------------------\n\n");
    }
    
    fclose(fp);
}

    //salva usuário
void salvarUser(struct User *user, int *tam) {
    FILE *fp;
    fp = fopen("user.txt", "w");
    
    if (fp == NULL) {
        printf("Erro!\n");
        exit(1);
    }
    
    for (int i = 0; i < *tam; i++) {
        fprintf(fp, "\nNome : %s\n", user[i].nomeUser);
        fprintf(fp, "Senha : %s\n", user[i].senhaUser);
    }
    
    fclose(fp);
}