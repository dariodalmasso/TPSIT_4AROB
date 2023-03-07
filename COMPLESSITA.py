import random
import time

n = 1000
#creo random in una lista 10 numeri
lista = [random.uniform(0,1) for _ in range(n)]
#faccio partire il tempo
start_time = time.time()
max = lista[0]
for element in lista:
    if element > max:
        max = element


end_time = time.time()
#fermo il tempo
#stampo per vedere la durata dell'algoritmo
print("durata dell'algoritmo: ")
print(end_time - start_time)