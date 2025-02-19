#include "Transacao.h"
#include "Carteira.h"
#include <iostream>
#include <cstring>

// Construtor
Transacao::Transacao(const char* tipo, float quantidade, float preco_unitario, Carteira* origem, Carteira* destino) {
    strncpy(this->tipo, tipo, 19);
    this->tipo[19] = '\0'; // Garante que a string termine com '\0'
    this->quantidade = quantidade;
    this->preco_unitario = preco_unitario;
    this->carteira_origem = origem;
    this->carteira_destino = destino;
}


// M�todo para calcular o valor total da transa��o
float Transacao::calcular_total() const {
    return quantidade * preco_unitario;
}

// M�todo para executar a transa��o
bool Transacao::executar_transacao() {
    if (strcmp(tipo, "COMPRA") == 0) {
        // Verifica se a carteira de origem tem saldo suficiente em BRL
        if (carteira_origem->get_saldo_brl() < calcular_total()) {
            std::cout << "Erro: Saldo insuficiente para compra." << std::endl;
            return false;
        }
        // Executa a compra
        carteira_origem->modificar_saldo(quantidade, 0, -calcular_total());
        carteira_destino->modificar_saldo(-quantidade, 0, calcular_total());
    } else if (strcmp(tipo, "VENDA") == 0) {
        // Verifica se a carteira de origem tem saldo suficiente em ETH/BTC
        if (carteira_origem->get_saldo_btc() < quantidade || carteira_origem->get_saldo_eth() < quantidade) {
            std::cout << "Erro: Saldo insuficiente para venda." << std::endl;
            return false;
        }
        // Executa a venda
        carteira_origem->modificar_saldo(-quantidade, 0, calcular_total());
        carteira_destino->modificar_saldo(quantidade, 0, -calcular_total());
    }
    return true;
}

// M�todo para exibir os detalhes da transa��o
void Transacao::exibir_detalhes() const {
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Quantidade: " << quantidade << std::endl;
    std::cout << "Pre�o Unit�rio: " << preco_unitario << std::endl;
    std::cout << "Total: " << calcular_total() << std::endl;
    std::cout << "-------------------------" << std::endl;
}
