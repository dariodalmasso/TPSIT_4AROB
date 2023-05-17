from collections.abc import Callable, Iterable, Mapping
import threading
from typing import Any

saldo = 100
mutex = threading.Lock()

class Deposita(threading.Thread):
    def __init__(self):
        super().__init__()
    def run (self):
        global saldo
        for _ in range(100000000):
            mutex.acquire()
            saldo = saldo + 10
        mutex.release()

class Preleva(threading.Thread):
    def __init__(self):
        super().__init__()
    def run (self):
        global saldo
    
        for _ in range(100000000):
            mutex.acquire()
            saldo = saldo - 10
        mutex.release()

Alice = Deposita()
Bob = Preleva()

Alice.start()
Bob.start()

print("aspetto la fine dei thread")
print(threading.enumerate())

Alice.join()
Bob.join()

print(f"il saldo è {saldo}")