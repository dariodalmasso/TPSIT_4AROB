import Thread, Lock
from time import slee

psw = 5000#password da trovare

trovato = False#variabile per controllare se la psw è stata trovata

mutex = Lock()

class hacker(Thread):#classe del thread dell'hacker
    def _init_(self, id, nome):
        Thread._init_(self)
        self.id = id#id utilizzato per capire se incrementare o decrementare il contatore
        self.nome = nome#nome da stampare se viene trovata la psw

    def run(self):
        cont = 0#dichiaro il contatore
        #global psw#utilizzo psw e variabile trovato globali
        global trovato
        if self.id % 2 == 0: #se l'id è pari incremento il contatore
            cont = 1#inizializzo cont
            while trovato == False:#ciclo se non è ancora stata trovata la psw
                if cont == psw:#controllo se la psw è stata trovata
                    mutex.acquire()
                    trovato = True#setto trovato a true e stampo il nome dell'hacker
                    mutex.release()
                    print(f"password: {cont} trovata da: {self.nome}")
                else:
                    cont+=1#incremento il contatore
                sleep(0.005)#delay di 5ms
        else:#se l'id è deispari il cont decrementa
            cont = 9999#inizializzo il cont
            while trovato == False:#ciclo se trovato è false
                if cont == psw:#se la psw viene trovata
                    mutex.acquire()
                    trovato = True#setto trovato a true e stampo il nome dell'hacker
                    mutex.release()
                    print(f"password: {cont} trovata da: {self.nome}")
                else:
                    cont-=1#decremento il contatore
                sleep(0.005)

class poliziotto(Thread):#classe per thread poliziotto
    def _init_(self, nome):
        Thread._init_(self)
        self.nome = nome#setto il nome del poliziotto

    def run(self):
        #global trovato#utilizzo trovato globale 
        i = 10#contatore secondi rimanenti
        while i >= 1 and trovato == False:#cicla per contatore maggiore del numero minimo di secondi e trovato false
            sleep(1.0)#delay di 1 sec
            print(f"nome: {self.nome} tempo mancante{i}")#stampo il tempo mancante
            i-=1#decremento i secondi
        if i == 0:#se il tempo è finito significa che i ladri non hanno trovato la psw
            print("ladri catturati")#stampo il messaggio di cattura

def main():
    p = poliziotto("marco")
    l1 = hacker(1, "topolino")
    l2 = hacker(2, "pippo")

    p.start()
    l1.start()
    l2.start()
    
    p.join()
    l1.join()
    l2.join()


if __name__ == "_main_":
    main()