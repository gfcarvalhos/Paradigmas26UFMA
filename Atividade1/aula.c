#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Cliente
{
  int id_cliente;
  char nome_cliente[50];
  int idade;
  int senha;
  float saldo;
};

struct Produto
{
  int id_produto;
  char nome_produto[20];
  float valor_unitario;
  int estoque;
  bool tem_idade_restrita;
};

struct Compra
{
  int id_compra;
  int id_cliente;
  int id_produto;
  int qtd_desejada;
  float valor_unidade;
  float subtotal;
  float total;
};

int registrarCliente(struct Cliente clientes[], int totalClientes)
{
  printf("\n===== REGRISTRO DE CLIENTE =====\n");
  printf("Informe o primeiro nome do cliente: ");
  scanf("%99s", clientes[totalClientes].nome_cliente);
  printf("Informe a idade do cliente: ");
  scanf("%d", &clientes[totalClientes].idade);
  printf("Informe uma senha (3 digitos): ");
  scanf("%d", &clientes[totalClientes].senha);
  printf("=================================\n");
  clientes[totalClientes].saldo = 100.0;
  return totalClientes + 1;
};

int loginCliente(struct Cliente clientes[], int totalClientes)
{
  char nome[50];
  int senha;
  printf("\n===== LOGIN DE CLIENTE =====\n");
  printf("Informe o primeiro nome do cliente: ");
  scanf("%99s", nome);
  printf("Informar senha para o cliente (3 digitos): ");
  scanf("%d", &senha);
  printf("=================================\n");

  for (int i = 0; i < totalClientes; i++)
  {
    if (strcmp(clientes[i].nome_cliente, nome) == 0 &&
        clientes[i].senha == senha)
    {

      return i;
    }
  }

  return -1;
}

void exibirProdutos(struct Produto produto[], int total)
{
  printf("\n===== CATALOGO DE PRODUTOS =====\n");
  printf("%-6s %-20s %-10s %-10s\n", "Cod", "Nome", "Preco", "Estoque");
  for (int i = 0; i < total; i++)
  {
    printf("%-6d %-20s R$%-8.2f %-10d\n",
           produto[i].id_produto, produto[i].nome_produto,
           produto[i].valor_unitario, produto[i].estoque);
  }
  printf("=================================\n");
};

void exibirMenuCompra(struct Produto produtos[], struct Cliente clientes[], int posicaoCliente, int totalProdutos)
{
  int opcao;
  do
  {
    printf("\n======= SISTEMA DE COMPRA =======");
    printf("\n===== MENU de COMPRA =====\n");
    printf("1. Comprar\n");
    printf("2. Ver saldo\n");
    printf("3. Adicionar Saldo\n");
    printf("4. Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      break;
    case 2:
      printf("\nSaldo atual: %.2f\n", clientes[posicaoCliente].saldo);
      break;
    case 3:
      clientes[posicaoCliente].saldo = clientes[posicaoCliente].saldo + 50.0;
      printf("\nSaldo atual: %.2f\n", clientes[posicaoCliente].saldo);
      break;

    case 4:
      break;

    default:
      printf("\nOpcao nao é válida.\n");
      break;
    }

  } while (opcao != 4);
};

int main()
{
  struct Produto produtos[50] = {
      {1, "Arroz 5kg", 15.90, 30, false},
      {2, "Feijao 1kg", 8.40, 40, false},
      {3, "Oleo de Soja", 7.20, 25, false},
      {4, "Acucar 1kg", 3.50, 50, false},
      {5, "Cafe 500g", 12.30, 20, false},
      {6, "Leite 1L", 8.10, 60, false},
      {7, "Macarrao 500g", 3.90, 35, false},
      {8, "Vinho 1L", 29.50, 45, true},
      {9, "Manteiga 200g", 9.90, 15, false},
      {10, "Cerveja 600ml", 3.40, 28, true}};
  int totalProdutos = 10;
  struct Compra compra[10];
  struct Cliente clientes[10];
  int totalClientes = 0;
  int posicaoCliente;
  int opcao;
  do
  {
    printf("\n======= SISTEMA DE COMPRA =======");
    printf("\n======= Menu Principal =======\n");
    printf("1. Registrar Cliente\n");
    printf("2. Login de Cliente\n");
    printf("3. Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      totalClientes = registrarCliente(clientes, totalClientes);
      posicaoCliente = totalClientes - 1;
      exibirMenuCompra(produtos, clientes, posicaoCliente, totalProdutos);
      break;
    case 2:
      posicaoCliente = loginCliente(clientes, totalClientes);
      if (posicaoCliente == -1)
      {
        printf("\nCliente nao encontrado.\n");
        break;
      }
      exibirMenuCompra(produtos, clientes, posicaoCliente, totalProdutos);
      break;
    case 3:
      printf("\nPrograma finalizado.\n");
      break;

    default:
      printf("\nOpcao nao é válida.\n");
    }
  } while (opcao != 3);

  return 0;
};
