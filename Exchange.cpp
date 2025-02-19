#include "Exchange.h"
#include "Carteira.h"
#include "Transacao.h"

// Construtor
Exchange::Exchange() {
    carteiras = nullptr;
    num_carteiras = 0;
    transacoes = nullptr;
    num_transacoes = 0;
}

// Destrutor
Exchange::~Exchange() {
    // Libera a memória alocada para as carteiras
    for (int i = 0; i < num_carteiras; i++) {
        delete carteiras[i];
    }
    delete[] carteiras;

    // Libera a memória alocada para as transações
    for (int i = 0; i < num_transacoes; i++) {
        delete transacoes[i];
    }
    delete[] transacoes;
}

// Método para adicionar uma carteira
void Exchange::adicionar_carteira(Carteira* carteira) {
    // Cria um novo array com tamanho aumentado
    Carteira** novo_array = new Carteira*[num_carteiras + 1];

    // Copia as carteiras existentes para o novo array
    for (int i = 0; i < num_carteiras; i++) {
        novo_array[i] = carteiras[i];
    }

    // Adiciona a nova carteira
    novo_array[num_carteiras] = carteira;

    // Libera o array antigo e substitui pelo novo
    delete[] carteiras;
    carteiras = novo_array;
    num_carteiras++;
}

// Método para realizar uma transação
void Exchange::realizar_transacao(Transacao* transacao) {
    if (transacao->executar_transacao()) {
        // Adiciona a transação ao array
        Transacao** novo_array = new Transacao*[num_transacoes + 1];
        for (int i = 0; i < num_transacoes; i++) {
            novo_array[i] = transacoes[i];
        }
        novo_array[num_transacoes] = transacao;

        delete[] transacoes;
        transacoes = novo_array;
        num_transacoes++;
    }
}

// Método para exibir as carteiras
void Exchange::exibir_carteiras() const {
    for (int i = 0; i < num_carteiras; i++) {
        carteiras[i]->exibir_saldo();
    }
}
