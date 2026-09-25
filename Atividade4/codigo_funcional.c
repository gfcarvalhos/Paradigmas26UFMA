#include <stdio.h>

void consultarSaldo(float saldo)
{
  printf("\n===== CONSULTAR SALDO =====\n");
  printf("Saldo atual: R$ %.2f\n", saldo);
  printf("===========================\n");
}

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

    switch (opcao)
    {
    case 1:
      consultarSaldo(saldo);
      break;
    case 2:
    // depositar
    case 3:
    // sacar
    case 4:
    // encerrar
    default:
      printf("\nOpcao invalida!\n");
    }
  } while (opcao != 4);
}