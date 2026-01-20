import pygame
from pygame.locals import *
pygame.init()

#Screen settings
screen = pygame.display.set_mode((859, 561))
scene = pygame.image.load("background.jpg").convert()
scenewidth = screen.get_width()

#skins
r_stand = pygame.image.load("rstand.png")
l_stand = pygame.transform.flip(r_stand, True, False)
r_walk = [pygame.image.load("rwalk1.png"), pygame.image.load("rwalk2.png"), pygame.image.load("rwalk3.png"), pygame.image.load("rwalk4.png"), pygame.image.load("rwalk5.png"), pygame.image.load("rwalk6.png")]
l_walk = [pygame.image.load("lwalk1.png"), pygame.image.load("lwalk2.png"), pygame.image.load("lwalk3.png"), pygame.image.load("lwalk4.png"), pygame.image.load("lwalk5.png"), pygame.image.load("lwalk6.png")]
r_jump = [pygame.image.load("rjump1.png"), pygame.image.load("rjump2.png"), pygame.image.load("rjump3.png")]
l_jump = [pygame.image.load("ljump1.png"), pygame.image.load("ljump2.png"), pygame.image.load("ljump3.png")]
r_crouch = [pygame.image.load("rcrouch1.png"), pygame.image.load("rcrouch2.png"), pygame.image.load("rcrouch3.png")]
l_crouch = [pygame.image.load("lcrouch1.png"), pygame.image.load("lcrouch2.png"), pygame.image.load("lcrouch3.png")]
r_fireball = [pygame.image.load("rfireball1.png"), pygame.image.load("rfireball2.png"), pygame.image.load("rfireball3.png"), pygame.image.load("rfireball4.png"), pygame.image.load("rfireball5.png"), pygame.image.load("rfireball6.png"), pygame.image.load("rfireball7.png"), pygame.image.load("rfireball8.png"), pygame.image.load("rfireball9.png"), pygame.image.load("rfireball10.png")]
l_fireball = [pygame.image.load("lfireball1.png"), pygame.image.load("lfireball2.png"), pygame.image.load("lfireball3.png"), pygame.image.load("lfireball4.png"), pygame.image.load("lfireball5.png"), pygame.image.load("lfireball6.png"), pygame.image.load("lfireball7.png"), pygame.image.load("lfireball8.png"), pygame.image.load("lfireball9.png"), pygame.image.load("lfireball10.png")]

fbcount = 0

class player1():
    def __init__(self):
        self.x = 79
        self.y = 432
        self.speed = 0.1
        self.width = 15
        self.right = False
        self.left = False
        self.jumping = False
        self.jumpvar = 100
        self.jumpcount = 0
        self.walking = False
        self.walkCount = 0
        self.crouching = False
        self.crouchcount = 0
        self.hitbox = (self.x, self.y, 16, 45)
        self.fbcd = 0
        self.hp = 10
        self.alive = True

    def draw(self, screen):
        if self.alive:
            if self.walking == False and self.jumping == False and self.crouchcount == 0:
                if self.left == False:
                    screen.blit(r_stand, (self.x, self.y))
                if self.left == True:
                    screen.blit(l_stand, (self.x, self.y))
                self.hitbox = (self.x, self.y, 16, 45)
                self.height = 45

    #WALKING ANIMATION

            if self.walking == True and self.jumping == False and self.crouchcount == 0:
                if self.right == True:
                    screen.blit(r_walk[self.walkCount//300], (self.x, self.y))
                if self.left == True:
                    screen.blit(l_walk[self.walkCount//300], (self.x, self.y))
                self.walkCount += 1
                if self.walkCount >= 1800:
                    self.walkCount = 0
                self.walking = False
                self.hitbox = (self.x, self.y, 16, 45)
                self.height = 45

    #JUMPING ANIMATION

            if self.jumping == True:
                if self.left == False:
                    screen.blit(r_jump[self.jumpcount//534], (self.x, self.y))
                if self.left == True:
                    screen.blit(l_jump[self.jumpcount//534], (self.x, self.y))
                self.jumpcount += 1
                if self.jumpcount >= 1602:
                    self.jumpcount = 0
                self.hitbox = (self.x, self.y, 16, 45)
                self.height = 45

    #CROUCHING ANIMATION

            if self.jumping == False and self.crouchcount != 0:
                if self.left == False:
                    screen.blit(r_crouch[self.crouchcount//100], (self.x, self.y + (self.crouchcount//100 * 7)))
                if self.left == True:
                    screen.blit(l_crouch[self.crouchcount//100], (self.x, self.y + (self.crouchcount//100 * 7)))
                self.hitbox = (self.x, self.y + 13, 19, 33)
                self.height = 33
            if self.crouchcount < 299 and self.crouching == True and self.jumping == False:
                    self.crouchcount += 1
            if self.crouchcount > 0 and self.crouching == False and self.jumping == False:
                    self.crouchcount -= 1

            pygame.draw.rect(screen, (255,0,0), (self.hitbox[0] - 15, self.hitbox[1] - 15, 50, 10))
            pygame.draw.rect(screen, (0,255,0), (self.hitbox[0] - 15, self.hitbox[1] - 15, 50 - (5 * (10 - self.hp)), 10))
    def hit(self):
        if self.hp > 0:
            self.hp -= 1
        else:
            self.alive = False

class player2(player1):
    def __init__(self):
        super().__init__()
        self.x = 780

class fb():
    def __init__(self, x, y, facing, fbcount):
        self.x = x
        self.y = y
        self.facing = facing
        self.fbcount = fbcount

    def draw(self, screen):
        if self.facing > 0:
            screen.blit(r_fireball[self.fbcount//200], (self.x, self.y))
        if self.facing < 0:
            screen.blit(l_fireball[self.fbcount//200], (self.x, self.y))
        self.fbcount += 1
        if self.fbcount == 2000:
            self.fbcount = 1000

def UpdateScreen():
    screen.blit(scene, (0,0))
    player1.draw(screen)
    player2.draw(screen)
    for fireball in fireballs:
        fireball.draw(screen)
    pygame.display.flip()

#MAIN LOOP
player1 = player1()
player2 = player2()
fireballs = []
while pygame.display.get_active() == True:
#SETUP QUIT
    for event in pygame.event.get():
        if event.type == QUIT:
            exit()
    keys = pygame.key.get_pressed()

#SETUP FIREBALLS

    for fireball in fireballs:
        if fireball.fbcount < 1000:
            if fireball.facing == -1:
                if fireball.x - fireball.fbcount/150 < player2.hitbox[0] + player2.hitbox[2] and fireball.x - fireball.fbcount/150 > player2.hitbox[0] and fireball.y + 10 < player2.hitbox[1] + player2.hitbox[3]  and fireball.y + 10 > player2.hitbox[1]:
                    player2.hit()
                    fireballs.remove(fireball)
                if fireball.x - fireball.fbcount/150 < player1.hitbox[0] + player1.hitbox[2] and fireball.x - fireball.fbcount/150 > player1.hitbox[0] and fireball.y + 10 < player1.hitbox[1] + player1.hitbox[3]  and fireball.y + 10 > player1.hitbox[1]:
                    player1.hit()
                    fireballs.remove(fireball)
            else:
                if fireball.x + fireball.fbcount/50 < player2.hitbox[0] + player2.hitbox[2] and fireball.x + fireball.fbcount/50 > player2.hitbox[0] and fireball.y + 10 < player2.hitbox[1] + player2.hitbox[3]  and fireball.y + 10 > player2.hitbox[1]:
                    player2.hit()
                    fireballs.remove(fireball)
                if fireball.x + fireball.fbcount/50 < player1.hitbox[0] + player1.hitbox[2] and fireball.x + fireball.fbcount/50 > player1.hitbox[0] and fireball.y + 10 < player1.hitbox[1] + player1.hitbox[3]  and fireball.y + 10 > player1.hitbox[1]:
                    player1.hit()
                    fireballs.remove(fireball)
        elif fireball.fbcount >= 1000:
            if fireball.facing == -1:
                if fireball.x + 10 < player2.hitbox[0] + player2.hitbox[2] and fireball.x + 10 > player2.hitbox[0] and fireball.y + 10 < player2.hitbox[1] + player2.hitbox[3]  and fireball.y + 10 > player2.hitbox[1]:
                    player2.hit()
                    fireballs.remove(fireball)
                if fireball.x + 10 < player1.hitbox[0] + player1.hitbox[2] and fireball.x + 10 > player1.hitbox[0] and fireball.y + 10 < player1.hitbox[1] + player1.hitbox[3]  and fireball.y + 10 > player1.hitbox[1]:
                    player1.hit()
                    fireballs.remove(fireball)

            else:
                if fireball.x + 60 < player2.hitbox[0] + player2.hitbox[2] and fireball.x + 60 > player2.hitbox[0] and fireball.y + 10 < player2.hitbox[1] + player2.hitbox[3]  and fireball.y + 10 > player2.hitbox[1]:
                    player2.hit()
                    fireballs.remove(fireball)
                if fireball.x + 60 < player1.hitbox[0] + player1.hitbox[2] and fireball.x + 60 > player1.hitbox[0] and fireball.y + 10 < player1.hitbox[1] + player1.hitbox[3]  and fireball.y + 10 > player1.hitbox[1]:
                    player1.hit()
                    fireballs.remove(fireball)
        if fireball.x < scenewidth and fireball.x > 0:
            fireball.x += fireball.facing * 0.2
        else:
            fireballs.remove(fireball)
            fbcount = 0
    if player1.fbcd > 0:
        player1.fbcd -= 1
    if player2.fbcd > 0:
        player2.fbcd -= 1

#LEFT PLAYER 1

    if keys[pygame.K_LEFT] and player1.x > player1.speed:
            player1.walking = True
            player1.left = True
            player1.right = False
            player1.x -= player1.speed

#LEFT PLAYER 2

    if keys[pygame.K_q] and player2.x > player2.speed:
            player2.walking = True
            player2.left = True
            player2.right = False
            player2.x -= player2.speed

#RIGHT PLAYER 1

    if keys[pygame.K_RIGHT] and player1.x < scenewidth - player1.width - player1.speed:
            player1.walking = True
            player1.right = True
            player1.left = False
            player1.x += player1.speed

#LEFT PLAYER 2

    if keys[pygame.K_d] and player2.x < scenewidth - player2.width - player2.speed:
            player2.walking = True
            player2.right = True
            player2.left = False
            player2.x += player2.speed

#JUMP PLAYER 1
    if not(player1.jumping):
        if keys[pygame.K_UP]:
            player1.jumping = True
            player1.jumpcount = 0
    else:
        if player1.jumpvar >= -100:
            neg = 1
            if player1.jumpvar < 0:
                neg = -1
            player1.y -= ((player1.jumpvar/100) ** 2) * 0.3 * neg
            player1.jumpvar -= 0.125
        else:
            player1.jumping = False
            player1.jumpvar = 100

#JUMP PLAYER 2

    if not(player2.jumping):
        if keys[pygame.K_z]:
            player2.jumping = True
            player2.jumpcount = 0
    else:
        if player2.jumpvar >= -100:
            neg = 1
            if player2.jumpvar < 0:
                neg = -1
            player2.y -= ((player2.jumpvar/100) ** 2) * 0.3 * neg
            player2.jumpvar -= 0.125
        else:
            player2.jumping = False
            player2.jumpvar = 100

#CROUCH PLAYER 1

    if keys[pygame.K_DOWN] and player1.walking == False:
        player1.crouching = True
    else:
        player1.crouching = False

#CROUCH PLAYER 2

    if keys[pygame.K_s] and player2.walking == False:
        player2.crouching = True
    else:
        player2.crouching = False

#FIREBALL PLAYER 1

    if keys[pygame.K_KP1] and player1.fbcd == 0:
        if player1.left:
            facing = -1
        else:
            facing = 1
        fireballs.append(fb(player1.x, player1.y, facing, 0))
        player1.fbcd = 3000

#FIREBALL PLAYER 2

    if keys[pygame.K_e] and player2.fbcd == 0:
        if player2.left:
            facing = -1
        else:
            facing = 1
        fireballs.append(fb(player2.x, player2.y, facing, 0))
        player2.fbcd = 3000

    UpdateScreen()