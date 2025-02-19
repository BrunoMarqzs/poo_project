#ifndef EXCHANGE_H
#define EXCHANGE_H

class Carteira;
class Transacao;

class Exchange {
private:
    Carteira** carteiras; // Array dinâmico de ponteiros para Carteira
    int num_carteiras;
    Transacao** transacoes; // Array dinâmico de ponteiros para Transacao
    int num_transacoes;

public:
    // Construtor
    Exchange();

    // Destrutor
    ~Exchange();

    // Métodos públicos
    void adicionar_carteira(Carteira* carteira);
    void realizar_transacao(Transacao* transacao);
    void exibir_carteiras() const;
};

#endif
