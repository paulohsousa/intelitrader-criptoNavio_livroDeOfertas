#include <stdio.h>
#include <stdlib.h>

// Função para inverter os dois últimos bits de cada byte (8 bits)
unsigned char trocarUltimosDoisBits(unsigned char mensagem) {
    return mensagem ^ 0b00000011;
}

// Função para trocar os 4 bits mais significativos pelos 4 bits menos significativos
unsigned char trocarOs4Bits(unsigned char mensagem) {
    return ((mensagem & 0b11110000) >> 4) | ((mensagem & 0b00001111) << 4);
}

// Função para descriptografar a mensagem
void descriptografarMensagem(unsigned char *descriptografia, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        // Aplica a inversão dos dois últimos bits
        descriptografia[i] = trocarUltimosDoisBits(descriptografia[i]);
        
        // Aplica a troca dos 4 bits mais significativos pelos 4 bits menos significativos
        descriptografia[i] = trocarOs4Bits(descriptografia[i]);
    }
}

int main() {
    // Mensagem criptografada representada em binário usando a notação 0b
    unsigned char mensagemCriptografada[] = {
        0b10010110, 0b11110111, 0b01010110, 0b00000001,
        0b00010111, 0b00100110, 0b01010111, 0b00000001,
        0b00010111, 0b01110110, 0b01010111, 0b00110110,
        0b11110111, 0b11010111, 0b01010111, 0b00000011
    };

    // Tamanho da mensagem em bytes
    int tamanhoDaMensagem = sizeof(mensagemCriptografada) / sizeof(mensagemCriptografada[0]);

    // Descriptografa a mensagem
    descriptografarMensagem(mensagemCriptografada, tamanhoDaMensagem);

    // Exibe a mensagem descriptografada
    printf("Mensagem descriptografada: ");

    // Imprime cada caractere da mensagem descriptografada
    for (int i = 0; i < tamanhoDaMensagem; i++) {
        printf("%c", mensagemCriptografada[i]);
    }
    printf("\n");

    return 0;
}
