def pega_notas(qtd_notas):
  return [int(input(f"Informe a nota {i}: ")) 
          for i in range(1, qtd_notas + 1)]

def calcula_media(notas):
  return sum(notas) / len(notas)

def define_conceito(media):
    if media >= 9.5:
        return "A"
    elif media >= 8.0:
        return "B"
    elif media >= 7.0:
        return "C"
    elif media >= 6.0:
        return "D"
    else:
        return "E"

def valida_aproveitamento(conceito):
    return "Aproveita" if conceito in ["A", "B", "C"] else "Não Aproveita"


def processa_disciplina():
    nome_disciplina = input("Informe nome da disciplina: ")
    qtd = int(input("Informe quantidade de notas: "))

    notas = pega_notas(qtd)
    media = calcula_media(notas)
    conceito = define_conceito(media)
    aproveitamento = valida_aproveitamento(conceito)

    return [nome_disciplina, conceito, aproveitamento]

def __main__():
  print("###### Sistema de Aproveitamento ######")

  disciplinas = []
  while True:
        disciplina = processa_disciplina()
        disciplinas.append(disciplina)

        continuar = input("Deseja adicionar outra disciplina? (s/n): ")

        if continuar.lower() != "s":
            break
        
  print(
        f"\n    Doutorado\n"
        f"_______________\n"
        f"{'Disciplina':<20}{'Conceito':<12}{'Aprovação':<15}"
    )

  for disciplina in disciplinas:
    print(
      f"{disciplina[0]:<20}{disciplina[1]:<12}{disciplina[2]:<12}"
  )



__main__()
