def pega_notas(qtd_notas):
  return [int(input(f"Informe a nota {i}: ")) for i in range(1, qtd_notas + 1)]

def calcula_media(notas):
  return sum(notas) / len(notas)

def define_conceito(media):
  conceitos = ["A","B", "C", "D", "E"]
  relacao_conceitos = {"A": 9.5, "B": 9.5, "C": 8.0, "D": 7.0, "E": 6.0}

  conceito_final
  for conceito in conceitos:
    if(media < relacao_conceitos[conceito]):
      conceito_final = conceito

  return conceito_final

def valida_aproveitamento(conceito):
  aprovados = ["A", "B", "C"]

  for aprovado in aprovados:
    if(aprovado == conceito):
      return "Aproveita"
  return "Não Aproveita"


def __main__():
  print("###### Sistema de Aproveitamento ######")
  nome_disciplina = input("Informe nome da disciplina: ")
  qtd = int(input("Informe quantidade de notas: "))

  notas = pega_notas(qtd)
  media = calcula_media(notas)
  conceito = define_conceito(media)
  aproveitamento = valida_aproveitamento(conceito)


  vetor_resposta = [nome_disciplina, conceito, aproveitamento]
  print(f"   Doutorado   \n_______________\nDisciplina   Conceito  Aprovação\n{vetor_resposta[nome_disciplina]}   {vetor_resposta[conceito]}   {vetor_resposta[aproveitamento]}")
  print(vetor_resposta)



__main__()
