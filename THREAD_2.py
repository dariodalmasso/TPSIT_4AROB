from random import random
from time import sleep
from threading import Thread


class Task(Thread):
    def __int__(self, id, temp):
        Thread.__init__(self)
        self.id = id
        self.temp = temp

    def run(self):
        print(f"start thead {self.id}")
        sleep(self.temp)
        print(f"finish thread{self.id}")


# creo 2 thread
listaThread = []
tempo = random()

for i in range(0, 10):
    i = Task(i, tempo)
    listaThread.append(i)

for elementi in listaThread:
    elementi.start()
    elementi.join()

"""t1 = Task()
t2 = Task()
# inizializzo thread
t1.start() # start == run
t2.start()


# aspetto tempo di attesa
t1.join() # chiude thread
t2.join()"""
