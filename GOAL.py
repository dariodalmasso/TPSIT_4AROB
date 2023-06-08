import numpy as np
import sys
import serial
import pygame as pg
import threading
import queue
import time

# Pygame config
width = 1200
height = 800
screen = pg.display.set_mode((width, height))
clock = pg.time.Clock()
ball = pg.image.load("C:\\Users\\Lorena\\Documents\\SCUOLA\\QUARTA\\TPSIT\\ES_THREAD_7\\intro_ball.gif")
omino = pg.image.load("C:\\Users\\Lorena\\Documents\\SCUOLA\\QUARTA\\TPSIT\\ES_THREAD_7\\derio.png")
ballrect = ball.get_rect()
ballrect.centerx = width // 2
ballrect.centery = height // 2
vite = 10

larghezza_porta = 300
altezza_porta = 50
goal_left = width / 2 - larghezza_porta / 2
goal_top = height - altezza_porta - 20
disegna_porta = pg.Rect(goal_left, goal_top, larghezza_porta, altezza_porta)

speed = [0, 0]
obstacles = []  # Lista degli ostacoli
obstacle_speed = 5  # Velocità di movimento degli ostacoli
score = 0  # Punteggio del giocatore

black = 0, 0, 0
dt = 1
gamma = 0.05
q = queue.Queue()

class ReadMicrobit(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self._running = True

    def terminate(self):
        self._running = False

    def run(self):
        # Serial config
        port = "COM11"
        s = serial.Serial(port)
        s.baudrate = 115200
        while self._running:
            data = s.readline().decode()
            acc = [float(x) for x in data[1:-3].split(",")]
            q.put(acc)
            time.sleep(0.01)


def verifico_goal_effettuato():
    if ballrect.colliderect(disegna_porta):
        print("GOAL!")
        font = pg.font.Font(None, 36)
        text = font.render("GOOOLL!!", True, (255, 255, 255))
        text_rect = text.get_rect(center=(width // 2, height // 2))
        screen.blit(text, text_rect)
        pg.display.flip()

def draw_obstacle(x, y):
   
   immagine_2 = pg.transform.scale(omino,(150,150))
   screen.blit(immagine_2, (x, y))


running = True
rm = ReadMicrobit()
rm.start()
pg.init()
speed = [0, 0]
while running:
    acc = q.get()
    speed[0] = (1. - gamma) * speed[0] + dt * acc[0] / 1024.
    speed[1] = (1. - gamma) * speed[1] + dt * acc[1] / 1024.
    q.task_done()
    ballrect = ballrect.move(speed)
    if ballrect.left < 0 or ballrect.right > width:
        speed[0] = -speed[0]
    if ballrect.top < 0 or ballrect.bottom > height:
        speed[1] = - speed[1]


    # Controllo collisione con gli ostacoli
    for obstacle in obstacles:
        if ballrect.colliderect(obstacle):
            vite -= 1
            break

    if(vite <

    screen.fill(black)
    screen.blit(ball, ballrect)

    # Generazione e movimento degli ostacoli (funzione di chatgpt)
    if np.random.random() < 0.05:  # Probabilità di generazione di un nuovo ostacolo
        obstacle_x = 10
        obstacle_y = np.random.randint(0, height + 100)  # Posizione verticale casuale dell'ostacolo
        obstacles.append(pg.Rect(obstacle_x, obstacle_y, 50, 50))

    for obstacle in obstacles:
        obstacle.x += obstacle_speed  # Movimento degli ostacoli verso sinistra
        draw_obstacle(obstacle.x, obstacle.y)

        

    # Rimozione degli ostacoli fuori dallo schermo
    obstacles = [obstacle for obstacle in obstacles if obstacle.x > -50]
    pg.draw.rect(screen, (255, 255, 255), disegna_porta)
    pg.display.flip()
    clock.tick(10)
    verifico_goal_effettuato()
    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False
            pg.quit()

rm.terminate()
rm.join()