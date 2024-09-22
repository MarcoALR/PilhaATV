#include <iostream>
#include <string>
#include "Pilha.h"  // Incluímos o arquivo de cabeçalho da pilha

// Função para verificar se o símbolo é um parêntese ou colchete de abertura
bool EhAbertura(char c) {
    return c == '(' || c == '[';
}

// Função para verificar se o símbolo é um parêntese ou colchete de fechamento
bool EhFechamento(char c) {
    return c == ')' || c == ']';
}

// Função para verificar se os símbolos de abertura e fechamento correspondem
bool Combina(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']');
}

// Função que verifica se a expressão possui os parênteses e colchetes balanceados
bool VerificarExpressao(const std::string& expressao) {
    Pilha_Construtor();  // Inicializamos a pilha

    // Percorremos cada caractere da expressão
    for (char c : expressao) {
        if (EhAbertura(c)) {
            // Empilhamos os símbolos de abertura convertidos para int
            Pilha_Empilhar(static_cast<TipoDado>(c));
        } else if (EhFechamento(c)) {
            // Se for um fechamento, verificamos se há correspondência com o topo da pilha
            TipoDado topo;
            if (Pilha_Topo(topo)) {
                if (!Combina(static_cast<char>(topo), c)) {
                    Pilha_Destrutor();  // Limpamos a memória da pilha
                    return false;  // Expressão inválida
                }
                Pilha_Desempilhar(topo);  // Removemos o topo
            } else {
                Pilha_Destrutor();  // Limpamos a memória da pilha
                return false;  // Expressão inválida
            }
        }
    }

    // Verificamos se a pilha está vazia (se todas as aberturas foram fechadas)
    bool resultado = Pilha_Vazia();
    Pilha_Destrutor();  // Limpamos a memória da pilha
    return resultado;
}

int main() {
    std::string expressao;
    // Solicitamos ao usuário a expressão
    std::cout << "Digite uma expressão matemática: ";
    std::getline(std::cin, expressao);
    // Verificamos se a expressão é válida
    if (VerificarExpressao(expressao)) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Errado" << std::endl;
    }
    return 0;
}