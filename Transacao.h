#ifndef TRANSACAO_H
#define TRANSACAO_H

class Carteira; // Declaração antecipada

class Transacao {
private:
    char tipo[20]; // "COMPRA" ou "VENDA"
    float quantidade;
    float preco_unitario;
    Carteira* carteira_origem;
    Carteira* carteira_destino;

public:
    // Construtor
    Transacao(const char* tipo, float quantidade, float preco_unitario, Carteira* origem, Carteira* destino);

    // Destrutor
    ~Transacao();

    // Métodos públicos
    float calcular_total() const;
    bool executar_transacao(); // Retorna true se a transação for bem-sucedida
    void exibir_detalhes() const;
};

#endif
