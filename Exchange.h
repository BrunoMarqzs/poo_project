#ifndef EXCHANGE_H
#define EXCHANGE_H

class Carteira;
class Transacao;

class Exchange {
private:
    Carteira** carteiras; // Array din�mico de ponteiros para Carteira
    int num_carteiras;
    Transacao** transacoes; // Array din�mico de ponteiros para Transacao
    int num_transacoes;

public:
    // Construtor
    Exchange();

    // Destrutor
    ~Exchange();

    // M�todos p�blicos
    void adicionar_carteira(Carteira* carteira);
    void realizar_transacao(Transacao* transacao);
    void exibir_carteiras() const;
};

#endif
