#include "sgc.h"

int main () {

    printf("-----------------------------\n\n");
    printf("Sistema de Gestão Comercial\n\n");
    printf("-----------------------------\n\n");

    inicializarSistema();

    return 0;
}

void inicializarSistema() {

    printf("Escolha uma opção de login:\n");
    printf("1. Logar como administrador\n");
    printf("2. Logar como usuário convencional\n");
    printf("3. Sair\n");
    printf(">> ");
    int op;
    scanf("%d", &op);

    switch (op) {

        case 1:
            logarAdmin();
            break;
        case 2:
            //logarUser();
            break;
        case 3:
            return 0;
        default:
            printf("op invalida.");
            return 0;
    }

    return 0;

}
