def recebeValor():
    valor = float(input('QUAL O VALOR A SER CONVERTIDO ?'))
    return valor

def converterParaCelsius(valor, unidade):
    naoExisteConversao = unidade == 'C'
    if naoExisteConversao:
        print(str(valor) +'°C')
        return
    
    match unidade:
        case 'F':
            valorConvertido = ((valor - 32) * 5)/9
            print(str(valorConvertido)+'°C')
            return
        case 'K':
            valorConvertido = valor + 273.15
            print(str(valorConvertido)+'°C')
            return
        
def converterParaKelvin(valor, unidade):
    naoExisteConversao = unidade == 'K'
    if naoExisteConversao:
        print(str(valor) +'K')
        return
    
    match unidade:
        case 'F':
            valorConvertido = (valor - 32) * 5/9
            print(str(valorConvertido)+'K')
            return
        case 'C':
            valorConvertido = valor - 273.15
            print(str(valorConvertido)+'K')
            return

def converterParaFahrenheit(valor, unidade):
    naoExisteConversao = unidade == 'F'
    if naoExisteConversao:
        print(str(valor) +'°F')
        return
    
    match unidade:
        case 'K':
            valorConvertido = 1.8*(valor-273.15)+32
            print(str(valorConvertido)+'°F')
            return
        case 'C':
            valorConvertido = (valor * 9/5) + 32
            print(str(valorConvertido)+'°F')
            return
    

def main():
    unidadeInicial = input('QUAL UNIDADE DA TEMPERATURA DESEJA CONVERTER ?').upper()
    unidadeFinal = input('PARA QUAL UNIDADE DA TEMPERATURA DESEJA CONVERTER ?').upper()
    
    match unidadeInicial:
        case 'C':
            converterParaCelsius(recebeValor(), unidadeFinal)
        case 'K':
            converterParaKelvin(recebeValor(), unidadeFinal)
        case 'F':
            converterParaFahrenheit(recebeValor(), unidadeFinal)
        case _:
            print('VALOR INVÁLIDO!')
            

main()