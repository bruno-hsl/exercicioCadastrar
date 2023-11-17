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
    if(strchr(u[indice].email, '@') == NULL){
        printf("Email invalido, tente novamente");
    }else{

    }
    printf("\n\n");
}

void buscarRegistro(usuario u[], int totalCadastro, int buscarEmail, int indice){
    if(totalCadastro == 0){
        printf("\nNao existe cadastros na lista\n");
        return;
    }else{
        for(int i = 0; i < totalCadastro; i++){
            if(u[i].email == buscarEmail){
                printf("\nNome do registro encontrado: %s", u[i].nome);
                return;
            }
        }
    }
    printf("\nRegistro nao encontrado na lista");
}



void imprimir(usuario u[], int totalCadastro){
    if(totalCadastro == 0 ){
        printf("\n\nnao existem usuariaos cadastrados");
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
          
        }
    }while(opcao != 0); 
}
