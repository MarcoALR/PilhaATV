#include <iostream>
#include <string>
#include "Pilha.h"  // Inclu�mos o arquivo de cabe�alho da pilha

// Fun��o para verificar se o s�mbolo � um par�ntese ou colchete de abertura
bool EhAbertura(char c) {
    return c == '(' || c == '[';
}

// Fun��o para verificar se o s�mbolo � um par�ntese ou colchete de fechamento
bool EhFechamento(char c) {
    return c == ')' || c == ']';
}

// Fun��o para verificar se os s�mbolos de abertura e fechamento correspondem
bool Combina(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']');
}

// Fun��o que verifica se a express�o possui os par�nteses e colchetes balanceados
bool VerificarExpressao(const std::string& expressao) {
    Pilha_Construtor();  // Inicializamos a pilha

    // Percorremos cada caractere da express�o
    for (char c : expressao) {
        if (EhAbertura(c)) {
            // Empilhamos os s�mbolos de abertura convertidos para int
            Pilha_Empilhar(static_cast<TipoDado>(c));
        } else if (EhFechamento(c)) {
            // Se for um fechamento, verificamos se h� correspond�ncia com o topo da pilha
            TipoDado topo;
            if (Pilha_Topo(topo)) {
                if (!Combina(static_cast<char>(topo), c)) {
                    Pilha_Destrutor();  // Limpamos a mem�ria da pilha
                    return false;  // Express�o inv�lida
                }
                Pilha_Desempilhar(topo);  // Removemos o topo
            } else {
                Pilha_Destrutor();  // Limpamos a mem�ria da pilha
                return false;  // Express�o inv�lida
            }
        }
    }

    // Verificamos se a pilha est� vazia (se todas as aberturas foram fechadas)
    bool resultado = Pilha_Vazia();
    Pilha_Destrutor();  // Limpamos a mem�ria da pilha
    return resultado;
}

int main() {
    std::string expressao;
    // Solicitamos ao usu�rio a express�o
    std::cout << "Digite uma express�o matem�tica: ";
    std::getline(std::cin, expressao);
    // Verificamos se a express�o � v�lida
    if (VerificarExpressao(expressao)) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Errado" << std::endl;
    }
    return 0;
}