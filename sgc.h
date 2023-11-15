#ifndef SGC_H
#define SGC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_USER 900
#define MAX_TAM_SENHA 900
#define MAX_NOME_PROD 900

struct Administrador {
    char nomeAdm[MAX_NOME_USER];
    int senhaAdm;
};

struct User {
    char nomeUser[MAX_NOME_USER];
    int senhaUser;
    int nivel;
};

struct Produto {
    char nomeProd[MAX_NOME_PROD];
    float preco;
    int quantidade;
    int codProduto;
};

void inicializarSistema();

//funções adm
void logarAdmin();
void gerenciaAdmin();
void adicionarProduto();
void listarProdutos();
void adicionarUser();
void listarUsuarios();
void excluirUser();
void salvarProdutos();
void salvarUser();

//funções user
void logarUser();
void gerenciaUser();

#endif