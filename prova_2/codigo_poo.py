class Temperatura:
    SIMBOLOS = {'C': '°C', 'F': '°F', 'K': 'K'}

    def __init__(self, valor, unidade):
        unidade = unidade.upper()
        if unidade not in self.SIMBOLOS:
            raise ValueError(f'Unidade inválida: {unidade}')
        self.valor = valor
        self.unidade = unidade

    def __str__(self):
        return f'{self.valor:.2f}{self.SIMBOLOS[self.unidade]}'


class ConversorTemperatura:
    def converter(self, temperatura, unidade_destino):
        unidade_destino = unidade_destino.upper()
        celsius = self._para_celsius(temperatura)
        valor_convertido = self._de_celsius(celsius, unidade_destino)
        return Temperatura(valor_convertido, unidade_destino)

    def _para_celsius(self, temperatura):
        match temperatura.unidade:
            case 'C':
                return temperatura.valor
            case 'F':
                return (temperatura.valor - 32) * 5 / 9
            case 'K':
                return temperatura.valor - 273.15

    def _de_celsius(self, celsius, unidade_destino):
        match unidade_destino:
            case 'C':
                return celsius
            case 'F':
                return celsius * 9 / 5 + 32
            case 'K':
                return celsius + 273.15
            case _:
                raise ValueError(f'Unidade inválida: {unidade_destino}')


class Aplicacao:
    def __init__(self):
        self.conversor = ConversorTemperatura()

    def executar(self):
        try:
            unidade_inicial = input('QUAL UNIDADE DA TEMPERATURA DESEJA CONVERTER? (C, F ou K) ')
            unidade_final = input('PARA QUAL UNIDADE DA TEMPERATURA DESEJA CONVERTER? (C, F ou K) ')
            valor = float(input('QUAL O VALOR A SER CONVERTIDO? '))

            origem = Temperatura(valor, unidade_inicial)
            resultado = self.conversor.converter(origem, unidade_final)
            print(f'{origem} = {resultado}')
        except ValueError:
            print('VALOR INVÁLIDO!')


if __name__ == '__main__':
    Aplicacao().executar()