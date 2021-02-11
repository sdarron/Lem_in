#!/usr/bin/env python3

import sys
import random
import pygame 
import os
import math
import re
import errno

pygame.init()
WIDTH = 1500
HEIGHT = 1000
FPS = 28

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
DGREEN = (15,  91,  82)
DPINK    = (111,  29,  74)

game_folder = os.path.dirname(__file__)
img_folder = os.path.join(game_folder, 'img')
background = pygame.image.load(os.path.join(img_folder, 'grass.jpg'))
bug_img = pygame.image.load(os.path.join(img_folder, 'bug.png'))
bug_img = pygame.transform.scale(bug_img, (bug_img.get_width()//6, bug_img.get_height()//6))
end_img = pygame.image.load(os.path.join(img_folder, 'end.png'))
end_img = pygame.transform.scale(end_img, (end_img.get_width()//6, end_img.get_height()//6))

font = pygame.font.Font(None, 34)

allantimg = []
ant_img = pygame.image.load(os.path.join(img_folder, 'ant1.png'))
ant_img1 = pygame.image.load(os.path.join(img_folder, 'ant2.png'))
ant_img2 = pygame.image.load(os.path.join(img_folder, 'ant3.png'))

allantimg.append(ant_img)
allantimg.append(ant_img1)
allantimg.append(ant_img2)

class Ant(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = ant_img
        self.rect = self.image.get_rect()
        self.rect.x = X
        self.rect.y = Y
        self.x1 = X
        self.y1 = Y
        self.speed = 5
        self.allantimg = allantimg
        self.index = 0

    def update(self):
        if self.x1 != self.rect.x or self.y1 != self.rect.y:
            if abs(self.x1 - self.rect.x) < 3 and abs(self.y1 - self.rect.y) < 3:
                self.rect.x = self.x1
                self.rect.y = self.y1
            angle = math.atan2((self.y1 - self.rect.y),(self.x1 - self.rect.x))
            self.rect.x += self.speed * math.cos(angle)
            self.rect.y += self.speed * math.sin(angle)
            self.index = (self.index + 1) % len(self.allantimg)
            self.image = allantimg[self.index]

    def remupdate(self, but, numroom):
        n = 0
        while(n < len(alllist)):
            if alllist[n] == '##start\n':
                while (alllist[n][0] == '#'):
                    n = n + 1
                str = alllist[n]
                start_coor = str.split(' ')
                xy = dictroom[start_coor[0]].rect.center
                X = xy[0]
                Y = xy[1]
            n = n + 1
        self.rect.x = X
        self.rect.y = Y
        self.x1 = X
        self.y1 = Y

class Room(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = bug_img
        self.rect = self.image.get_rect()
        self.rect.center = (XR, YR)
        self.startend = 0

    def coliz(self, dictroom):
        listroom = []
        for room in dictroom:
            listroom.append(dictroom[room])
        i = 1
        while(i < len(listroom)):
            if abs(listroom[i].rect.x - listroom[i - 1].rect.x) < 50 and abs(listroom[i].rect.y - listroom[i - 1].rect.y) < 50:
                return 1
            else:
                return 0
            i = i + 1

    def remupdate(self, but, numroom):
        XRYR = self.rect.center
        XR = int(XRYR[0])
        YR = int(XRYR[1])
        if but == 4:
            scale = 1.1
            XR = XR * scale - 20
            YR = YR * scale - 20
        if but == 5 and self.coliz(dictroom) == 0:
            scale = 1.1
            XR = XR / scale + 20
            YR = YR / scale + 20
        self.rect.center = (XR, YR)

    def checkend(self, alllist):
        n = 0
        while(n < len(alllist)):
            if alllist[n] == '##end\n':
                while (alllist[n][0] == '#'):
                    n = n + 1
                str = alllist[n]
                end_coor = str.split(' ')
                xy = dictroom[end_coor[0]].rect.center
            n = n + 1
        if xy == self.rect.center:
            self.startend = 2
            self.image = end_img
        n = 0
        while(n < len(alllist)):
            if alllist[n] == '##start\n':
                while (alllist[n][0] == '#'):
                    n = n + 1
                str = alllist[n]
                end_coor = str.split(' ')
                xy = dictroom[end_coor[0]].rect.center
            n = n + 1
        if xy == self.rect.center:
            self.startend = 2
            self.image = end_img

def print_err(code):
    if code == 'ANTS_ERR':
        print("ERROR")
    elif code == 'READ_ERR':
        print("Read error")
    pygame.quit()
    sys.exit(1)

def readallist(alllist):
    for line in sys.stdin:
        alllist.append(line)

alllist = []

try:
    readallist(alllist)
except FileNotFoundError:
    print_err(READ_ERR)
    
i = 0
if (alllist[i][0] == '#'):
    while (alllist[i][0] == '#'):
        i = i + 1

try:
    counant = int(alllist[i])
except:
    print_err('ANTS_ERR')

text1 = font.render("Let's press the <space> for next step!",True, DPINK)

screen = pygame.display.set_mode([WIDTH, HEIGHT])
pygame.display.set_caption("Lem_in")
clock = pygame.time.Clock()
all_sprites = pygame.sprite.Group()
rooms = pygame.sprite.Group
ants = pygame.sprite.Group

dictroom = {}
for str in alllist:
    pattern = r"([^#-]+\s\d+\s\d+)"
    match = re.match(pattern, str)
    if match:
        room_coor = str.split(' ')
        XR = round(int(room_coor[1])) * 50 + 100
        YR = round(int(room_coor[2])) * 50 + 100
        room = Room()
        room.rect.center = (XR, YR)
        dictroom.setdefault(room_coor[0], room)
        all_sprites.add(room)

for room in dictroom:
    dictroom[room].checkend(alllist)

def startant(alllist, dictroom):
    n = 0
    while(n < len(alllist)):
        if alllist[n] == '##start\n':
            while (alllist[n][0] == '#'):
                n = n + 1
            str = alllist[n]
            start_coor = str.split(' ')
            xy = dictroom[start_coor[0]].rect.center
            X = xy[0]
            Y = xy[1]
        n += 1
    XY = [X, Y]
    return XY

XY = startant(alllist, dictroom)
X = XY[0]
Y = XY[1]

listant = {}
i = 0
for ant in range(counant):
    ant = Ant()
    all_sprites.add(ant)
    listant.setdefault(i + 1, ant)
    i += 1

listways = []
for str in alllist:
    if str[0] == 'L':
        listways.append(str)

def checkstep(listant):
    for ant in listant:
        if listant[ant].rect.x != listant[ant].x1 or listant[ant].rect.y != listant[ant].y1:
            return 1
    else:
        return 0

scale = 1
i = 0
f = 0
running = True
while running:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and i < len(listways) and checkstep(listant) != 1:
                str = listways[i]
                steps = str.split(' ')
                del steps[-1]
                for step in steps:
                    stepone = step.split('-')
                    steproom = stepone[1].rstrip('\n')
                    xy = dictroom[steproom].rect.center
                    antnumb = stepone[0].replace("L", "")
                    listant[int(antnumb)].x1 = xy[0]
                    listant[int(antnumb)].y1 = xy[1]
                i = i + 1
                f = 1
        if f == 0 and event.type == pygame.MOUSEBUTTONDOWN :
            if event.button == 4:
                but = 4
            if event.button == 5:
                but = 5
            for room in dictroom:
                dictroom[room].remupdate(but, room)
            for ant in listant:
                listant[ant].remupdate(but, room)

    screen.blit(background, (0,0))
   
    #new 
    all_sprites.update()
  
    #draw
    all_sprites.draw(screen)

    for str in alllist:
        pattern = r"([^\WL]+-\w+)"
        match = re.match(pattern, str)
        if match:
            roomway = str.split('-')
            steproom1 = roomway[0].rstrip('\n')
            room1 = dictroom[steproom1].rect.center
            x1 = room1[0]
            y1 = room1[1]
            steproom2 = roomway[1].rstrip('\n')
            room2 = dictroom[steproom2].rect.center
            x2 = room2[0]
            y2 = room2[1]  
            pygame.draw.line(screen, DGREEN, [x1, y1], [x2, y2], 5)

    counant = '{}'.format(counant)
    text = font.render(counant +" ants are total",True, DPINK)
    screen.blit(text, [10,10])
    screen.blit(text1, [10,32])
    
    pygame.display.flip()

pygame.quit()
