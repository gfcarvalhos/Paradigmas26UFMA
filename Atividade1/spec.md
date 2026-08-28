# Programa com tomada de decisao

## Paradigma: Declarativo

## Entidades:
Cliente (id_cliente, nome_cliente, idade, senha, saldo)  
Produto (id_produto, nome_produto, estoque, valor_unidade. tem_idade_restrita)  
Compra (id_compra, id_cliente, id_produto, qtd_desejada, valor_unidade, subtotal)  

## Regras:

1. Em toda compra realizada por um cliente é necessário validar o saldo e a idade.
2. Quando o cliente não tiver saldo, a compra não deve ser realizada e um comprovante (output) deve informar que o cliente não tem saldo
3. Quando o cliente não tem idade e solicita algum item com restrição de idade, então a compra não deve ser realizada e um comprovante deve informar que o cliente não tem idade para o produto solicitado
4. Quando o cliente não tem saldo e nem idade, então a compra não deve ser realizada e um comprovante deve informar que o cliente não tem saldo e idade
5. Menu principal deve possuir as opções: registrar cliente, login de cliente e sair
6. Menu de compras deve possuir as opçoes: comprar, adicionar saldo e sair
7. Todo novo cliente inicia com saldo 500;
8. Adicionar saldo por padrão deve adicionar 100;

## Pseudocódigo

1.0 Inicio do programa  
Menu principal  
Informar opções:  
1.1 Registrar Cliente  
1.2 Login de Cliente  
1.2 Sair  

1.1 Registrar Cliente  
1.1.1 Ler nome do cliente  
1.1.2 Ler idade do cliente  
1.1.3 Sistema deve registrar cliente e liberar menu de compra  

1.2 Login de Cliente  
1.1.1 Ler nome do cliente  
1.1.2 Ler Senha do cliente  
1.1.2.1 Se senha ou nome invalidos, informar na tela e voltar para 1.1.1  
1.1.3 Login valida, liberar menu de compra  

2.0 Menu de compra  
2.1 Comprar  
2.2 Ver saldo  
2.3 Adiconar Saldo  
2.4 Sair  

2.1 Comprar  
2.1.1 Mostrar lista de produtos disponiveis  
2.1.2 Ler código do produto  
2.1.3 Ler quantidade  
2.1.3.1 Se quantidade indisponivel, informar e solicitar quantidade novamente  
2.1.4 Adicionar no carrinho e opções para adicionar mais produtos, retirar produto ou finalizar compra  

2.2 Ver saldo  
2.2.1 Informar saldo atual  

2.3 Adicionar Saldo  
2.3.1 Informar que saldo foi adicionado  
2.3.2 Mostrar saldo atual  
