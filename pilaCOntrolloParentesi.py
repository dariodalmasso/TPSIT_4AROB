def main():
    dizPar = {'(': ')', '[': ']', '{': '}'}
    pilaPar = []
    stringa = input("stringa: ")

    for i,l in enumerate(stringa):
        if l in dizPar:
            pilaPar.append(l)
            continue
        if len(pilaPar) > 0:
            par = pilaPar.pop()
        if l in dizPar.values() and dizPar[par] != l:
            print(f"error al carattere '{l}', serviva '{dizPar[par]}' all'indice {i}")
            exit()
    
    if len(pilaPar) > 0:
        print(f"non hai chiuse le parentesi {pilaPar}")
    else:
        print("controllo corretto")

if __name__ == '__main__':
    main()