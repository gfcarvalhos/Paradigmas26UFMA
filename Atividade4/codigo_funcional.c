#include <stdio.h>

void consultarSaldo(float saldo)
{
  printf("\n===== CONSULTAR SALDO =====\n");
  printf("Saldo atual: R$ %.2f\n", saldo);
  printf("===========================\n");
}

float depositar(float saldo, float valor)
{
  return saldo + valor;
}

float sacar(float saldo, float valor)
{
  return saldo - valor;
}

float menuDeposito(float saldo)
{
  float valor;
  printf("\n===== DEPOSITO =====\n");
  printf("Informe o valor a depositar: R$ ");
  scanf("%f", &valor);

  saldo = depositar(saldo, valor);

  printf("Deposito realizado com sucesso!\n");
  printf("Saldo atual: R$ %.2f\n", saldo);
  printf("====================\n");

  return saldo;
}

float menuSaque(float saldo)
{
  float valor;

  printf("\n===== SAQUE =====\n");
  printf("Informe o valor a sacar: R$ ");
  scanf("%f", &valor);

  if (valor > saldo)
  {
    printf("Saldo insuficiente!\n");
    return saldo;
  }

  saldo = sacar(saldo, valor);

  printf("Saque realizado com sucesso!\n");
  printf("Saldo atual: R$ %.2f\n", saldo);

  return saldo;
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
      menuDeposito(saldo);
      break;
    case 3:
      menuSaque(saldo);
      break;
    case 4:
      printf("\nSistema encerrado.\n");
      break;
    default:
      printf("\nOpcao invalida!\n");
    }
  } while (opcao != 4);
}