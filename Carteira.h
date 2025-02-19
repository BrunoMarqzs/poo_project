#ifndef CARTEIRA_H
#define CARTEIRA_H

class Carteira {
private:
    char endereco[50]; // Endereço da carteira
    float saldo_btc;   // Saldo de Bitcoin
    float saldo_eth;   // Saldo de Ethereum
    float saldo_brl;   // Saldo em Reais

public:
    // Construtor
    Carteira(const char* endereco, float saldo_btc, float saldo_eth, float saldo_brl);

    // Destrutor
    ~Carteira();

    // Métodos públicos
    void modificar_saldo(float btc, float eth, float brl);
    void exibir_saldo() const;

    // Getters
    const char* get_endereco() const;
    float get_saldo_btc() const;
    float get_saldo_eth() const;
    float get_saldo_brl() const;

    // Setters
    void set_saldo_btc(float saldo);
    void set_saldo_eth(float saldo);
    void set_saldo_brl(float saldo);
};

#endif
