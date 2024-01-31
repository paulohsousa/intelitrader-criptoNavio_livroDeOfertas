#include <stdio.h>

// Estrutura para representar uma oferta no livro de ofertas
typedef struct {
    int posicao;    // Posição da oferta no livro
    double valor;   // Valor da oferta
    int quantidade; // Quantidade disponível na oferta
} Oferta;

// Função para inserir uma nova oferta no livro de ofertas
void incluirOferta(Oferta livro[], int *tamanhoLivro, Oferta novaOferta) {
    // Adiciona a nova oferta ao final do livro
    livro[*tamanhoLivro] = novaOferta;
    (*tamanhoLivro)++;
}

// Função para modificar uma oferta no livro de ofertas
void alterarOferta(Oferta livro[], int tamanhoLivro, int posicao, double novoValor, int novaQuantidade) {
    // Procura a oferta na posição especificada e atualiza seus valores
    for (int i = 0; i < tamanhoLivro; i++) {
        if (livro[i].posicao == posicao) {
            livro[i].valor = novoValor;
            livro[i].quantidade = novaQuantidade;
            break; // Termina o loop após encontrar a oferta
        }
    }
}

// Função para excluir uma oferta do livro de ofertas
void excluirOferta(Oferta livro[], int *tamanhoLivro, int posicao) {
    // Procura a oferta na posição especificada e a remove do livro
    for (int i = 0; i < *tamanhoLivro; i++) {
        if (livro[i].posicao == posicao) {
            // Remove a oferta movendo as ofertas restantes
            for (int j = i; j < *tamanhoLivro - 1; j++) {
                livro[j] = livro[j + 1];
            }
            (*tamanhoLivro)--; // Atualiza o tamanho do livro
            break; // Termina o loop após remover a oferta
        }
    }
}

// Função para imprimir o livro de ofertas
void imprimirLivro(Oferta livro[], int tamanhoLivro) {
    // Imprime cada oferta no formato especificado
    for (int i = 0; i < tamanhoLivro; i++) {
        printf("%d,%.2f,%d\n", livro[i].posicao, livro[i].valor, livro[i].quantidade);
    }
}

int main() {
    int numNotificacoes;
    scanf("%d", &numNotificacoes);

    Oferta livro[100];  // Assumindo um máximo de 100 ofertas no livro
    int tamanhoDoLivro = 0;

    // Processa cada notificação
    for (int i = 0; i < numNotificacoes; i++) {
        int posicao, acao, qtd;
        double valor;

        // Lê os valores da notificação
        scanf("%d,%d,%lf,%d", &posicao, &acao, &valor, &qtd);

        Oferta novaOferta;
        novaOferta.posicao = posicao;

        // Executa a ação especificada pela notificação12
        switch (acao) {
            case 0:  // INSERIR
                novaOferta.valor = valor;
                novaOferta.quantidade = qtd;
                incluirOferta(livro, &tamanhoDoLivro, novaOferta);
                break;
            case 1:  // MODIFICAR
                alterarOferta(livro, tamanhoDoLivro, posicao, valor, qtd);
                break;
            case 2:  // DELETAR
                excluirOferta(livro, &tamanhoDoLivro, posicao);
                break;
            default:
                printf("Ação desconhecida\n");
                break;
        }
    }

    // Imprime o resultado do livro de ofertas
    imprimirLivro(livro, tamanhoDoLivro);

    return 0;
}
