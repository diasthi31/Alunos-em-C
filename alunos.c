#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char matricula[20], nome[100];
    double nota1, nota2, media;
} tipoAluno;

double calcularMedia(tipoAluno aluno) {
    return (aluno.nota1 + 2 * aluno.nota2) / 3;
}

int menu() {
    int opcao;
    do {
        printf("1. Inserir\n");
        printf("2. Listar todos alunos\n");
        printf("3. Listar aprovados\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%i", &opcao);
    } while (opcao < 1 || opcao > 4);
    return opcao;
}

void lerAluno(tipoAluno *inserir) {
    printf("Matrícula: ");
    scanf("%s", inserir->matricula);
    while (getchar() != '\n');
    printf("Nome: ");
    scanf("%s", inserir->nome);
    while (getchar() != '\n');
    printf("Nota 1: ");
    scanf("%lf", &inserir->nota1);
    printf("Nota 2: ");
    scanf("%lf", &inserir->nota2);
    inserir->media = calcularMedia(*inserir);
}

void inserirAluno(tipoAluno aluno, tipoAluno *turma, int *quantidade) {
    turma[*quantidade] = aluno;
    (*quantidade)++;
}

void listarAlunos(tipoAluno *turma, int quantidade) {
    system("clear");
    printf("Lista de alunos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nMatrícula: %s\n", turma[i].matricula);
        printf("Nome: %s\n", turma[i].nome);
        printf("Média: %.2lf\n", turma[i].media);
        printf("---------------------------------\n");
    }
}

void listarAprovados(tipoAluno *turma, int quantidade) {
    system("clear");
    printf("Alunos aprovados:\n");
    for (int i = 0; i < quantidade; i++) {
        if (turma[i].media >= 6.0) {
            printf("\nMatrícula: %s\n", turma[i].matricula);
            printf("Nome: %s\n", turma[i].nome);
            printf("Média: %.2lf\n", turma[i].media);
            printf("---------------------------------\n");
        }
    }
}

void sair() {
    exit(0);
}

int main() {
    tipoAluno turma[100];
    int quantidade = 0, acabou = 0;

    while(!acabou) {
        switch (menu()) {
            case 1:
                lerAluno(&turma[quantidade]);
                inserirAluno(turma[quantidade], turma, &quantidade);
                system("clear");
                break;
        
            case 2:
                listarAlunos(turma, quantidade);
                printf("\n");
                break;
        
            case 3:
                listarAprovados(turma, quantidade);
                printf("\n");
                break;
        
            case 4:
                printf("Programa encerrado.\n");
                sair();
                break;
        
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}