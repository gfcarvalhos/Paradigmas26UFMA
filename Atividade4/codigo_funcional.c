#include <stdio.h>

void exibirMenu()
{
  printf("\n====== MENU PRINCIPAL ======\n");
  printf("1. Consultar Saldo\n");
  printf("2. Depositar\n");
  printf("3. Sacar\n");
  printf("4. Sair\n");
  printf("============================\n");
}

int main()
{
  float saldo = 0.0;
  int opcao;

  do
  {
    exibirMenu();
  } while (opcao != 4);
}