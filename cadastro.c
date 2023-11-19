#include <stdio.h>
#include <string.h>
#define TAM 2


typedef struct{
    char nome[20];
    char email[20];
    char sexo[10];
    char endereco[50];
    double altura;
}usuario;

void validarEmail(usuario u[], int indice){
    while(strchr(u[indice].email, '@') == NULL){
        printf("\nEmail invalido, tente novamente");
        printf("\nDigite o e-mail do usuario: ");
        fflush(stdin);
        fgets(u[indice].email, sizeof(u[indice].email), stdin);
        fflush(stdin);
    }
}

void validarSexo(usuario u[], int indice){
    while(!(strcmp(u[indice].sexo, "Masculino") == 0 ||
            strcmp(u[indice].sexo, "Feminino") == 0 ||
            strcmp(u[indice].sexo, "Indiferente") == 0)){
                 printf("Sexo invalido, tente novamente: ");
                 fflush(stdin);
                 fgets(u[indice].sexo, sizeof(u[indice].sexo), stdin);
                 fflush(stdin);
               }
}

void validarAltura(usuario u[], int indice){
    while(u[indice].altura < 1.0 && u[indice].altura > 2.0){
        printf("Altura invalida, tente novamente");
        printf("Digite a altura do usuario: ");
        fflush(stdin);
        scanf("%lf", &u[indice].altura);
        fflush(stdin);
    }
}

void cadastrar(usuario u[], int indice){

    printf("\nDigite o nome do usuario: ");
    fflush(stdin);
    fgets(u[indice].nome, sizeof(u[indice].nome), stdin);
    fflush(stdin);

    printf("Digite o e-mail do usuario: ");
    fflush(stdin);
    fgets(u[indice].email, sizeof(u[indice].email), stdin);
    fflush(stdin);
    validarEmail(u, indice);

    printf("Digite o sexo do usuario: ");
    fflush(stdin);
    fgets(u[indice].sexo, sizeof(u[indice].sexo), stdin);
    fflush(stdin);
    validarSexo(u, indice);

    printf("Digite o endereco do usuario: ");
    fflush(stdin);
    fgets(u[indice].endereco, sizeof(u[indice].endereco), stdin);
    fflush(stdin);

     printf("Digite a altura do usuario: ");
     fflush(stdin);
     scanf("%lf", &u[indice].altura);
     fflush(stdin);
     validarAltura(u, indice);

}

void buscarRegistro(usuario u[], int totalCadastro, int buscarEmail) {
    if (totalCadastro == 0) {
        printf("\nNao existe cadastros na lista\n");
        return;
    } else {
        for (int i = 0; i < totalCadastro; i++) {
            if (strcmp(u[i].email, buscarEmail) == 0) {
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
            printf("Email: %s", u[i].email);
            printf("Sexo: %s", u[i].sexo);
            printf("\nEndereco: %s", u[i].endereco);
             printf("Altura: %lf", u[i].altura);
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
        printf("\nDigite 0 para encerrar o programa\n");
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
