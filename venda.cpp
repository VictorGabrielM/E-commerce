#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

void Venda::adicionaCelular(const Celular &celular)
{
  m_celulares.push_back(celular);
}

void Venda::ordena()
{
  m_celulares.sort();
}

void Venda::recarregaEstoque(int cod, int qtd)
{
  std::list<Celular>::iterator it = m_celulares.begin();
  while (1)
  {
    if (it->cod == cod)
    {
      it->qtd += qtd;
      break;
    }
    else
      it++;
  }

}

void Venda::efetuaVenda(int cod, int qtd)
{
  std::list<Celular>::iterator it = m_celulares.begin();
  while (1)
  {
    if (it->cod == cod && it->qtd >= qtd) //se a quantidade comprada
    {                                     //está em estoque
      it->qtd -= qtd;
      break;
    }
    else if (it->cod == cod && it->qtd < qtd)
    {
      break;
    }
    else
      ;
    it++;
  }

}

void Venda::aplicaDesconto(const std::string &fabricante, float desconto)
{
  std::list<Celular>::iterator it;

  for (it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->fabricante == fabricante)
    {
      it->valor -= it->valor * (desconto / 100);
    }
  }
}

void Venda::removeModelo(int cod)
{
  std::list<Celular>::iterator it = m_celulares.begin();

  while (1)
  {
    if (it->cod == cod)
    {
      break;
    }
    it++;
  }
  m_celulares.erase(it);
}

void Venda::imprimeEstoque() const
{
  std::list<Celular>::const_iterator it = m_celulares.begin();
  int i = 1;


  for (it = m_celulares.begin(); it != m_celulares.end(); it++)
  {
    if (it->qtd < 1)
    {
      continue;
    }
    std::cout << std::fixed << std::setprecision(0);
    std::cout << it->fabricante << " " << it->modelo << ", " << it->armazenamento << "GB, ";
    std::cout << it->memoria << "GB RAM, "<< it->peso*1000 << " gramas, ";
    std::cout << (char)toupper(*it->cor.begin());
    int i = 1;
    while (1)
    {
      if (it->cor[i] == *it->cor.end())
      {
        break;
      }
      std::cout << it->cor[i];
      i++;
    }
    std::cout << ", ";
    std::cout << it->qtd;
    if (it->qtd == 1)
    {
      std::cout << " restante, ";
                
    }
    if (it->qtd != 1)
    {
      std::cout << " restantes, ";
                
    }
    std::cout << "R$ " << std::setprecision(2) << it->valor << std::endl;
  }
}