#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 2

typedef struct{
    char nome[20];
    char email[20];
    char sexo[12];
    char endereco[50];
    double altura;
    int vacina;
    int id;
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
    while(u[indice].altura <= 1.0 || u[indice].altura >= 2.0){
        printf("Altura invalida, tente novamente");
        printf("\nDigite a altura do usuario: ");
        scanf("%lf", &u[indice].altura);
    }
}

char validarVacina(usuario u[], int indice) {
    while (u[indice].vacina != 0 && u[indice].vacina != 1) {
        printf("Valor invalido, digite [1] para sim ou [0] para nao: ");
        scanf("%d", &u[indice].vacina);
    }

    return (u[indice].vacina == 1) ? 'A' : 'B';
}

void cadastrar(usuario u[], int indice){

    u[indice].id = rand() % 200;

    printf("\nDigite o nome do usuario: ");
    scanf("%19s", u[indice].nome);

    printf("Digite o e-mail do usuario: ");
    scanf("%19s", u[indice].email);
    validarEmail(u, indice);

    printf("Digite o sexo do usuario: ");
    scanf("%19s", u[indice].sexo);
    validarSexo(u, indice);

    printf("Digite o endereco do usuario: ");
    scanf("%19s", u[indice].endereco);

    printf("Digite a altura do usuario: ");
    scanf("%lf", &u[indice].altura);
    validarAltura(u, indice);

    printf("O usuario tomou a vacina? Digite [1] para sim ou [0] nao: ");
    scanf("%d", &u[indice].vacina);
    validarVacina(u, indice);
}

void buscarRegistro(usuario u[], int totalCadastro, const char buscarEmail[]) {
    if (totalCadastro == 0) {
        printf("\nNao existe cadastros na lista\n");
        return;
    } else {
        for (int i = 0; i < totalCadastro; i++) {
            if (strcmp(u[i].email, buscarEmail) == 0) {
                printf("\nRegistro encontrado: ");
                printf("\nNome: %s", u[i].nome);
                printf("\nId: %d", u[i].id);
                printf("\nSexo: %s", u[i].sexo);
                printf("\nEndereco: %s", u[i].endereco);
                printf("\nAltura: %lf", u[i].altura);
                char vacina = validarVacina(u, i);
                switch(vacina){
                case 'A':
                 printf("\nTomou a vacina");
                break;
                case 'B':
                printf("\nNao tomou avacina");
                break;
            }
                return;
            }
        }
    }
    printf("\nRegistro nao encontrado na lista");
}

void editarRegistro(usuario u[], int totalCadastro, const char buscarEmail[]){
    if(totalCadastro == 0){
        printf("Nenhum usuario foi cadastrado");
        return;
    }else{
        for(int i = 0; i < totalCadastro; i++){
            if(strcmp(u[i].email, buscarEmail) == 0){
                   printf("Alterar nome: ");
                        fflush(stdin);
                        fgets(u[i].nome, sizeof(u[i].nome), stdin);
                        fflush(stdin);
                     printf("Alterar email: ");
                        fflush(stdin);
                        fgets(u[i].email, sizeof(u[i].email), stdin);
                        validarEmail(u, i);
                        fflush(stdin);
                    printf("Alterar sexo: ");
                        fflush(stdin);
                        fgets(u[i].sexo, sizeof(u[i].sexo), stdin);
                        validarSexo(u, i);
                        fflush(stdin);
                    printf("Alterar endereco: ");
                        fflush(stdin);
                        fgets(u[i].endereco, sizeof(u[i].endereco), stdin);
                        fflush(stdin);
                     printf("Alterar altura: ");
                        fflush(stdin);
                        scanf("%lf", &u[i].altura);
                        validarAltura(u, i);
                        fflush(stdin);
                    return;
            }
        }
    }
}

void excluirRegistro(usuario u[], int totalCadastro, const char buscarEmail[]){
        for(int i = 0; i < totalCadastro; i++){
            if(strcmp(u[i].email, buscarEmail) == 0){
               sizeof(u[i].nome);
            }
        }
    }


void imprimir(usuario u[], int totalCadastro){
    if(totalCadastro == 0 ){
        printf("\n\nnao existem usuariaos cadastrados");
    }else{
        for(int i = 0; i < totalCadastro; i++){
            printf("\nId: %d", u[i].id);
            printf("\nNome: %s", u[i].nome);
            printf("\nEmail: %s", u[i].email);
            printf("\nSexo: %s", u[i].sexo);
            printf("\nEndereco: %s", u[i].endereco);
            printf("\nAltura: %lf", u[i].altura);

            char vacina = validarVacina(u, i);
            switch(vacina){
                case 'A':
                 printf("\nTomou a vacina");
                break;
                case 'B':
                printf("\nNao tomou avacina");
                break;
            }

            printf("\n\n");
        }
    }
}

int main(){
    usuario u[TAM];
    int opcao, totalCadastro = 0;
    char buscarEmail[20];

    do{
        printf("\n\nDigite 1 para cadastrar");
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
            case 3:
            printf("Digite o email para buscar: ");
            scanf("%19s", buscarEmail);
            buscarRegistro(u, totalCadastro, buscarEmail);
            break;
            case 4:
            printf("Digite o email do usuario para editar: ");
            scanf("%19s", buscarEmail);
            editarRegistro(u, totalCadastro, buscarEmail);
            break;
            case 5:
            printf("Digite o email do usuario pra excluir: ");
            scanf("%19s", buscarEmail);
            excluirRegistro(u, totalCadastro, buscarEmail);
            break;
        }
    }while(opcao != 0); 
    return 0;
}
