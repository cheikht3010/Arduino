import pygame
from pygame.locals import *
from serial import *
with Serial(port="COM7", baudrate=9600, timeout=1, writeTimeout=1) as port_serie:
    if port_serie.isOpen():
        while True:

            ## ecoute de l'arduino
            ligne = port_serie.read()
            ##print (str(object=ligne, encoding='utf-8', errors='strict'))
            stri = str(object=ligne, encoding='utf-8', errors='strict')
            if stri == "1" :
            	##print ("appuyée")
            	pygame.mixer.init()
            	son = pygame.mixer.Sound("ding.wav")
            	son.play()

            ## envoi de signal à l'arduino
            nombre = 0
            for event in pygame.event.get() :
                if event.type == KEYDOWN :
                    nombre = 1
            port_serie.write(nombre.encode('ascii'))