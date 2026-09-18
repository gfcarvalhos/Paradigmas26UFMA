#include <stdio.h>

void consultarSaldo(float saldo)
{
  printf("\n===== CONSULTAR SALDO =====\n");
  printf("Saldo atual: R$ %.2f\n", saldo);
  printf("===========================\n");
}

float depositar(float saldo)
{
  float valor;

  printf("\n===== DEPOSITO =====\n");
  printf("Informe o valor a depositar: R$ ");
  scanf("%f", &valor);

  saldo += valor;

  printf("Deposito realizado com sucesso!\n");
  printf("Saldo atual: R$ %.2f\n", saldo);
  printf("====================\n");

  return saldo;
}

float sacar(float saldo)
{
  float valor;

  printf("\n===== SAQUE =====\n");

  do
  {
    printf("Informe o valor a sacar: R$ ");
    scanf("%f", &valor);

    if (valor > saldo)
    {
      printf("\nSaldo insuficiente!\n");
      printf("Saldo atual: R$ %.2f\n", saldo);
      printf("Informe um novo valor.\n\n");
    }

  } while (valor > saldo);

  saldo -= valor;

  printf("\nValor de R$ %.2f foi liberado.\n", valor);
  printf("Saldo atual: R$ %.2f\n", saldo);
  printf("=================\n");

  return saldo;
}

int main()
{
  float saldo = 0.0;
  int opcao;

  do
  {
    printf("\n====== MENU PRINCIPAL ======\n");
    printf("1. Consultar Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sacar\n");
    printf("4. Sair\n");
    printf("============================\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      consultarSaldo(saldo);
      break;

    case 2:
      saldo = depositar(saldo);
      break;

    case 3:
      saldo = sacar(saldo);
      break;

    case 4:
      printf("\nSistema encerrado.\n");
      break;

    default:
      printf("\nOpcao invalida!\n");
      break;
    }

  } while (opcao != 4);

  return 0;
}