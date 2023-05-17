from collections.abc import Callable, Iterable, Mapping
import threading
import random
from typing import Any

posti = 200
mutex = threading.Lock()

class Cassa(threading.Thread):
    def __init__(self):
        super().__init__(self, id)
        self.id = id
    
    def run(self):
        global posti

        
        while(posti > 0):
            mutex.acquire()
            if(posti > 0):
                posti = posti -1
                print(f" la cassa {self.id} ti assegna il posto {posti + 1}")
                mutex.release()
            else:
                mutex.release()
                break
            

def main():

    global posti
    
    cassa1 = Cassa(1)
    cassa2 = Cassa(2)
    cassa3 = Cassa(3)
    cassa4 = Cassa(4)
    cassa5 = Cassa(5)
    cassa6 = Cassa(6)

    cassa1.start()
    cassa2.start()
    cassa3.start()
    cassa4.start()
    cassa5.start()
    cassa6.start()

    cassa1.join()
    cassa2.join()
    cassa3.join()
    cassa4.join()
    cassa5.join()
    cassa6.join()

    
        







if __name__ == "__main__":
    main()
