#include "celular.hpp"

int Celular::id = 1;

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
                
    this->modelo = modelo;
    this->fabricante = fabricante;
    this->armazenamento = armazenamento;
    this->memoria = memoria;
    this->peso = peso;
    this->cor = cor;
    this->qtd = qtd;
    this->valor = valor;
    this->cod = id;
    id++;              
}

bool Celular::operator<(const Celular& other) {
  if(this->fabricante == other.fabricante)
    return this->modelo < other.modelo;
  return this->fabricante < other.fabricante;  
  return false;
}