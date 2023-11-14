#include <stdio.h>
#define TAM 2


typedef struct{
    char nome[20];
    char email[20];
}usuario;

void cadastrar(usuario u[], int indice){
    printf("\nDigite o nome do usuario: ");
    fflush(stdin);
    fgets(u[indice].nome, sizeof(u[indice].nome), stdin);
    fflush(stdin);
    printf("Digite o e-mail do usuario: ");
    fflush(stdin);
    fgets(u[indice].email, sizeof(u[indice].email), stdin);
    fflush(stdin);
    printf("\n\n");
}

void alterarRegistro(usuario u[], int totalCadastro, int buscarEmail){
    int opcaoEscolhida;
    if(totalCadastro == 0 ){
        printf("Lista vazia");
        return;
    }else{
        for(int i = 0 ; i < totalCadastro; i++){
            if(u[i].email == buscarEmail){
                printf("\nNome: %s ", u[i].nome);
                printf("\nIdade: %s ", u[i].email);
                printf("\nAlterar os dados: ");

                printf("Digite 1 para alterar o nome, Digite 2 para alterar a idade, Digite 3 para alterar todos os campos");
                scanf("%d", &opcaoEscolhida);
                switch (opcaoEscolhida){
                    case 1: 
                        printf("Alteracao do nome: ");
                         fflush(stdin);
                        fgets(u[i].nome, sizeof(u[i].nome), stdin);
                         fflush(stdin);
                    break;
                    case 2: 
                        printf("Alteracao da idade: ");
                         fflush(stdin);
                         fgets(u[i].email, sizeof(u[i].email), stdin);
                         fflush(stdin);
                    break;
                    case 3:
                        printf("Alteracao do nome: ");
                        fflush(stdin);
                        fgets(u[i].nome, sizeof(u[i].nome), stdin);
                        fflush(stdin);
                        printf("Alteracao da idade: ");
                        fgets(u[i].email, sizeof(u[i].email), stdin);
                        fflush(stdin);
                }
            }
        }
    }
}

void imprimir(usuario u[], int totalCadastro){
    if(totalCadastro == 0 ){
        printf("\n\nnao existem alunos cadastrados");
    }else{
        for(int i = 0; i < totalCadastro; i++ ){
            printf("\nNome: %s", u[i].nome);
            printf("\nEmail: %s", u[i].email);
            printf("\n\n");
        }
    }
}



int main(){
    usuario u[TAM];
    int opcao, totalCadastro = 0, buscarEmail;

    do{
        printf("\nDigite 1 para cadastrar");
        printf("\nDigite 2 para imprimir os cadastros");
        printf("\nDigite 3 para buscar um cadastro");
        printf("\nDigite 4 para alterar um cadastro");
        printf("\nDigite 5 para excluir um cadastro");
        printf("\nDigite 0 para encerrar o programa");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            if(opcao < TAM){
                cadastrar(u, totalCadastro);
                totalCadastro++;
            }else{
                printf("Limite de cadastros alcancado");
            }
            break;
            case 2:
            imprimir(u, totalCadastro);
            break;
            case 3:
            printf("Digite o e-mail para buscar: ");
            fgets(u[indice].email, sizeof(u[indice].email), stdin);
            alterarRegistro(u,totalCadastro, buscarEmail);
            break;
        }
    }while(opcao != 0); 
}