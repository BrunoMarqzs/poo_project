#include "Carteira.h"
#include "Transacao.h"
#include "Exchange.h"
#include <iostream>

int main() {
    Exchange exchange; // Cria a exchange

    // Cria 3 carteiras com saldos iniciais diferentes
    Carteira* carteira1 = new Carteira("0x123abc", 1.5f, 2.0f, 5000.0f); // BTC: 1.5, ETH: 2.0, BRL: 5000
    Carteira* carteira2 = new Carteira("0x456def", 0.0f, 5.0f, 10000.0f); // BTC: 0.0, ETH: 5.0, BRL: 10000
    Carteira* carteira3 = new Carteira("0x789ghi", 3.0f, 0.0f, 2000.0f); // BTC: 3.0, ETH: 0.0, BRL: 2000

    // Adiciona as carteiras à exchange
    exchange.adicionar_carteira(carteira1);
    exchange.adicionar_carteira(carteira2);
    exchange.adicionar_carteira(carteira3);

    // Exibe os saldos iniciais
    std::cout << "=== Estado Inicial das Carteiras ===" << std::endl;
    exchange.exibir_carteiras();

    // Realiza 4 transações
    std::cout << "\n=== Realizando Transacoes ===" << std::endl;

    // Transação 1: Compra de 0.5 BTC (bem-sucedida)
    std::cout << "\nTransacao 1: Compra de 0.5 BTC" << std::endl;
    Transacao* compraBTC = new Transacao("COMPRA", 0.5f, 30000.0f, carteira1, carteira2);
    if (compraBTC->executar_transacao()) {
        std::cout << "Transacao realizada com sucesso!" << std::endl;
    } else {
        std::cout << "Falha na transacao." << std::endl;
    }
    compraBTC->exibir_detalhes();

    // Transação 2: Venda de 1.0 ETH (bem-sucedida)
    std::cout << "\nTransacao 2: Venda de 1.0 ETH" << std::endl;
    Transacao* vendaETH = new Transacao("VENDA", 1.0f, 2000.0f, carteira2, carteira3);
    if (vendaETH->executar_transacao()) {
        std::cout << "Transacao realizada com sucesso!" << std::endl;
    } else {
        std::cout << "Falha na transacao." << std::endl;
    }
    vendaETH->exibir_detalhes();

    // Transação 3: Tentativa de compra de 10.0 BTC (saldo insuficiente)
    std::cout << "\nTransacao 3: Tentativa de compra de 10.0 BTC (saldo insuficiente)" << std::endl;
    Transacao* compraSemSaldo = new Transacao("COMPRA", 10.0f, 30000.0f, carteira1, carteira2);
    if (compraSemSaldo->executar_transacao()) {
        std::cout << "Transacao realizada com sucesso!" << std::endl;
    } else {
        std::cout << "Falha na transacao: Saldo insuficiente." << std::endl;
    }
    compraSemSaldo->exibir_detalhes();

    // Transação 4: Tentativa de venda de 10.0 ETH (quantidade maior que o disponível)
    std::cout << "\nTransacao 4: Tentativa de venda de 10.0 ETH (quantidade maior que o disponivel)" << std::endl;
    Transacao* vendaSemSaldo = new Transacao("VENDA", 10.0f, 2000.0f, carteira2, carteira3);
    if (vendaSemSaldo->executar_transacao()) {
        std::cout << "Transacao realizada com sucesso!" << std::endl;
    } else {
        std::cout << "Falha na transacao: Quantidade maior que o disponivel." << std::endl;
    }
    vendaSemSaldo->exibir_detalhes();

    // Exibe os saldos após as transações
    std::cout << "\n=== Estado Final das Carteiras ===" << std::endl;
    exchange.exibir_carteiras();

    // Libera a memória alocada (não sei se precisa, mas vou fazer mesmo assim)
    delete carteira1;
    delete carteira2;
    delete carteira3;
    delete compraBTC;
    delete vendaETH;
    delete compraSemSaldo;
    delete vendaSemSaldo;

    return 0; // Fim do programa
}
