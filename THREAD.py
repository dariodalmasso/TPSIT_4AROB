from time import sleep
from threading import Thread

#esecuzione simultanea

class Task(Thread):
    def __init__(self, id, temp):
        Thread.__init__(self)
        self.id = id
        self.temp = temp

    def run(self):
        print(f'START THREAD ...')
        sleep(self.temp)
        print(f'FINISH THREAD ....')


#listaThread = []

#for Thread in listaThread:
    #listaThread(Thread).Task()

#creo due nuovi thread e passo l'Id e il tempo che voglio che rimangano in attesa
t1 = Task(1, 5)
#inizializzo i thread
t1.start()
#aspetto il tempo di attesa del thread
#t1.join()

t2 = Task(1, 3)
# = run
t2.start()
#spegne il thread, lo chiude
#t2.join()



