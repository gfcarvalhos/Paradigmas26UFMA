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
  char produto[20];
  int qtd_desejada;
  float valor_unidade;
  float subtotal;
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

void exibirProdutos(struct Produto produtos[], int totalProdutos)
{
  printf("\n===== CATALOGO DE PRODUTOS =====\n");
  printf("%-6s %-20s %-10s %-10s\n", "Cod", "Nome", "Preco", "Estoque");
  for (int i = 0; i < totalProdutos; i++)
  {
    printf("%-6d %-20s R$%-8.2f %-10d\n",
           produtos[i].id_produto, produtos[i].nome_produto,
           produtos[i].valor_unitario, produtos[i].estoque);
  }
  printf("=================================\n");
};

void gerarPainelOnlineDeCompras(struct Produto produtos[], struct Compra compra[], int item)
{
  float total;
  printf("\n===== Carrinho =====\n");
  printf("%-6s %-20s %-10s %-10s\n", "Cod", "Nome", "Qtd", "Subtotal");
  if (item != 0)
  {
    for (int i = 0; i < item; i++)
    {
      printf("%-6d %-20s %-10d R$%-8.2f\n",
             compra[i].id_produto + 1, produtos[compra[i].id_produto].nome_produto,
             compra[i].qtd_desejada, compra[i].subtotal);
      total = total + compra[i].subtotal;
    }
  }
  printf("\nTotal: %.2f\n", total);
  printf("=================================\n");
}

int removerProdutoDaCompra(struct Compra compra[], int item, int codigo)
{
  int posicao = -1;
  for (int i = 0; i < item; i++)
  {
    if (compra[i].id_produto == codigo - 1)
    {
      posicao = i;
      break;
    }
  }
  if (posicao == -1)
  {
    printf("\nProduto nao encontrado!\n");
    return item;
  }
  for (int i = posicao; i < item - 1; i++)
  {
    compra[i] = compra[i + 1];
  }

  printf("\nProduto removido com sucesso!\n");

  return item - 1;
};

bool finalizarCompra(struct Compra compra[], float saldoCliente, int items)
{
  if (items == 0)
  {
    printf("\nCarrinho vazio. Nenhuma compra realizada.\n");
    return false;
  }
  bool clienteTemSaldoParaCompra;
  int numeracao = 1;
  float totalGeral = 0;

  printf("\n========== NOTA DE COMPRA ==========\n");
  printf("%-20s %-6s %-10s %-10s\n", "Produto", "Qtd", "Unit.", "Subtotal");

  for (int i = 0; i < items; i++)
  {
    totalGeral += compra[i].subtotal;
    printf("%-20s %-6d R$%-8.2f R$%-8.2f\n",
           compra[i].produto, compra[i].qtd_desejada,
           compra[i].valor_unidade, compra[i].subtotal);
  }
  int opcao;
  clienteTemSaldoParaCompra = saldoCliente >= totalGeral;

  if (!clienteTemSaldoParaCompra)
  {
    printf("\n===== ATENCAO =====\n");
    printf("Cliente nao possui saldo suficiente.\n");
    printf("Saldo atual R$%.2f\n", saldoCliente);
    numeracao = 0;
  }
  do
  {
    printf("\n===== ACOES =====\n");
    if (clienteTemSaldoParaCompra)
      printf("%d. Finalizar compra\n", numeracao);
    printf("%d. Cancelar compra\n", numeracao + 1);
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      if (!clienteTemSaldoParaCompra)
        return false;
      return true;
    case 2:
      if (!clienteTemSaldoParaCompra)
      {
        printf("\nOpcao nao e valida.\n");
        opcao = 3;
        break;
      }
      return false;
    default:
      printf("\nOpcao nao e valida.\n");
      break;
    }
  } while (opcao != 2);
};

void finalizarCompraComRestricao(struct Compra compra[], float saldoCliente, int items)
{
}

int gerarCarrinhoDeCompras(struct Produto produtos[], struct Compra compra[], int totalProdutos)
{
  int opcao;
  int item = 0;
  int codigo;
  int qtd;
  do
  {
    exibirProdutos(produtos, totalProdutos);
    gerarPainelOnlineDeCompras(produtos, compra, item);
    printf("\n===== ACOES =====\n");
    printf("1. Adicionar um produto\n");
    printf("2. Remover um produto\n");
    printf("3. Finalizar compra\n");
    printf("4.Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("\nInforme o codigo do produto: ");
      scanf("%d", &codigo);
      if (codigo > totalProdutos + 1 || codigo < 0)
      {
        printf("Codigo invalido!\n");
        break;
      }
      printf("Informe a quantidade: ");
      scanf("%d", &qtd);
      if (qtd > produtos[codigo - 1].estoque || qtd < 0)
      {
        printf("\nQuantidade invalida!\n");
        break;
      }
      compra[item].id_produto = codigo - 1;
      compra[item].qtd_desejada = qtd;
      compra[item].valor_unidade = produtos[codigo - 1].valor_unitario;
      compra[item].subtotal = produtos[codigo - 1].valor_unitario * qtd;
      strcpy(compra[item].produto, produtos[codigo - 1].nome_produto);
      item = item + 1;
      break;
    case 2:
      printf("\nInforme o codigo do produto: ");
      scanf("%d", &codigo);
      item = removerProdutoDaCompra(compra, item, codigo);
      break;
    case 3:
      return item;
    case 4:
      break;

    default:
      printf("\nOpcao nao e valida.\n");
      break;
    }
    printf("=================================\n");
  } while (opcao != 4);
  return -1;
};

void exibirMenuCompra(struct Produto produtos[], struct Cliente clientes[], int posicaoCliente, int totalProdutos)
{
  int opcao;
  int items;
  float saldoCliente = clientes[posicaoCliente].saldo;
  bool clienteMenorDeIdade;
  struct Compra compra[10];

  do
  {
    printf("\n======= SISTEMA DE COMPRA =======");
    printf("\n===== MENU DE COMPRA =====\n");
    printf("1. Comprar\n");
    printf("2. Ver saldo\n");
    printf("3. Adicionar Saldo\n");
    printf("4. Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      items = gerarCarrinhoDeCompras(produtos, compra, totalProdutos);
      if (items == -1)
      {
        break;
      }
      clienteMenorDeIdade = clientes[posicaoCliente].idade < 18;
      if (clienteMenorDeIdade)
      {
        finalizarCompraComRestricao(compra, saldoCliente, items);
      }
      finalizarCompra(compra, saldoCliente, items);
      opcao = 4;
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
    printf("=================================\n");
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
    printf("=================================\n");
  } while (opcao != 3);

  return 0;
};
