# Projeto referente à P2 de Paradigmas de Programação
Aluno: Gabriel Felipe Carvalho Silva

# Conversor de Temperatura

Programa de terminal que converte temperaturas entre Celsius (C), Fahrenheit (F) e Kelvin (K), escrito em Python com orientação a objetos.

## Como executar

Requer Python 3.10 ou superior (por causa do `match`).

```bash
python conversor_temperatura.py
```

Exemplo de uso:

```
QUAL UNIDADE DA TEMPERATURA DESEJA CONVERTER? (C, F ou K) c
PARA QUAL UNIDADE DA TEMPERATURA DESEJA CONVERTER? (C, F ou K) f
QUAL O VALOR A SER CONVERTIDO? 100
100.00°C = 212.00°F
```

Se a unidade ou o valor digitado não for válido, o programa mostra `VALOR INVÁLIDO!`.

## Como o código está organizado

O código tem três classes, cada uma com uma responsabilidade:

| Classe | O que faz |
| --- | --- |
| `Temperatura` | Guarda um valor e a sua unidade, valida a unidade e sabe se exibir como texto (ex.: `25.00°C`). |
| `ConversorTemperatura` | Faz as contas. Recebe uma `Temperatura` e devolve outra na unidade pedida. |
| `Aplicacao` | Conversa com o usuário: faz as perguntas, chama o conversor e imprime o resultado. |


## Melhoria

No `codigo_original` foi utilizada uma funcao para cada tipo de conversao com o objetivo de manter cada função com uma única responsabilidade. No código em POO, a classe (`ConversorTemperatura`), que responsável pela conversão, converte sempre o valor inicial para Celsius e na sequencia para a unidade de destino. Tal método é garantido pelo conceito de contexto que a classe representa/se impõe. Então temos uma simplificação de código.