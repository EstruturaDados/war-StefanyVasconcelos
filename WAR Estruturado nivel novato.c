#include <stdio.h>     // Biblioteca para entrada/saída (ex: printf, fgets)
#include <string.h>    // Biblioteca para manipulação de strings (ex: strcspn)

// Definição da struct Territorio
// Um "molde" que representa um território do jogo, com nome, cor e número de tropas
struct Territorio {
    char nome[30];     // Nome do território (máx. 29 caracteres + '\0')
    char cor[10];      // Cor do exército (máx. 9 caracteres + '\0')
    int tropas;        // Número de tropas nesse território
};

// (Opcional) Função para limpar o buffer de entrada
// Útil se usassemos scanf, mas neste código não é necessária, pois usamos fgets
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Descarta todos os caracteres até a próxima linha
}
int main() {
    struct Territorio territorios[5];  // Declara um array com 5 territórios
    char buffer[20];  // Buffer auxiliar para ler números como string (para depois converter)

    // Início do cadastro
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");

    // Loop para cadastrar os 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("Cadastrando território %d:\n", i + 1);

        // Lê o nome do território (com espaços)
        printf("Nome do território: ");
        fgets(territorios[i].nome, 30, stdin); 
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Remove o '\n' final da string

        // Lê a cor do exército
        printf("Cor do exército (ex: Azul, Verde): ");
       fgets(territorios[i].cor, 10, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';   // Remove o '\n' final

        // Lê o número de tropas como string, e converte para int
        printf("Número de tropas: ");
        fgets(buffer, 20, stdin);   
        sscanf(buffer, "%d", &territorios[i].tropas); // Converte string para int usando sscanf

        printf("\n");  // Espaçamento entre cadastros
    }

    // Exibe todos os dados cadastrados
    printf("------------------------------------------\n\n");
    printf("    MAPA DO MUNDO - ESTADO ATUAL \n\n");
    printf("------------------------------------------\n\n");

    // Loop para exibir os dados de cada território
    for (int i = 0; i < 5; i++) {
        printf("- Território %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);        // Mostra o nome
        printf("  Cor do Exército: %s\n", territorios[i].cor); // Mostra a cor
        printf("  Tropas: %d\n", territorios[i].tropas);    // Mostra as tropas
        printf("-----------------------------------\n");    // Linha separadora
    }

    return 0;  // Encerra o programa
}