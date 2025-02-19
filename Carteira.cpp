#include "Carteira.h"
#include <iostream>
#include <cstring>

// Construtor
Carteira::Carteira(const char* endereco, float saldo_btc, float saldo_eth, float saldo_brl) {
    strncpy(this->endereco, endereco, 49);
    this->endereco[49] = '\0'; // Garante que a string termine com '\0'
    this->saldo_btc = saldo_btc;
    this->saldo_eth = saldo_eth;
    this->saldo_brl = saldo_brl;
}

// Método para modificar saldos
void Carteira::modificar_saldo(float btc, float eth, float brl) {
    saldo_btc += btc;
    saldo_eth += eth;
    saldo_brl += brl;
}

// Método para exibir saldos
void Carteira::exibir_saldo() const {
    std::cout << "Endereço: " << endereco << std::endl;
    std::cout << "BTC: " << saldo_btc << std::endl;
    std::cout << "ETH: " << saldo_eth << std::endl;
    std::cout << "BRL: " << saldo_brl << std::endl;
    std::cout << "-------------------------" << std::endl;
}

// Getters
const char* Carteira::get_endereco() const {
    return endereco;
}

float Carteira::get_saldo_btc() const {
    return saldo_btc;
}

float Carteira::get_saldo_eth() const {
    return saldo_eth;
}

float Carteira::get_saldo_brl() const {
    return saldo_brl;
}

// Setters
void Carteira::set_saldo_btc(float saldo) {
    saldo_btc = saldo;
}

void Carteira::set_saldo_eth(float saldo) {
    saldo_eth = saldo;
}

void Carteira::set_saldo_brl(float saldo) {
    saldo_brl = saldo;
}
