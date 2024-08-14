/*
** EPITECH PROJECT, 2020
** animations.c
** File description:
** animations-related functions
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "include/my_hunter.h"

sfIntRect horizontal(game g, duck d)
{
    d.rec.left < 626 && d.speedx != 0 && d.speedy == 0 ?
        (d.sec < 0.1 ? d.rec.left = 0, d.rec.width = 34, d.rec.height = 27 :
        d.sec < 0.2 ? d.rec.left = 34, d.rec.width = 34, d.rec.height = 25 :
        (d.rec.left = 68, d.rec.width = 32, d.rec.height = 28)) :
    d.rec.left < 1252 && d.speedx != 0 && d.speedy == 0 ?
        (d.sec < 0.1 ? d.rec.left = 626, d.rec.width = 34, d.rec.height = 27 :
        d.sec < 0.2 ? d.rec.left = 660, d.rec.width = 34, d.rec.height = 25 :
        (d.rec.left = 694, d.rec.width = 32, d.rec.height = 28)) :
    d.rec.left < 1878 && d.speedx != 0 && d.speedy == 0 ?
        (d.sec < 0.1 ? d.rec.left = 1252, d.rec.width = 34, d.rec.height = 27 :
        d.sec < 0.2 ? d.rec.left = 1286, d.rec.width = 34, d.rec.height = 25 :
        (d.rec.left = 1320, d.rec.width = 32, d.rec.height = 28)) : 1;
    return (d.rec);
}

sfIntRect diagonal(game g, duck d)
{
    d.rec.left < 626 && d.speedx != 0 && d.speedy != 0 ?
        (d.sec < 0.1 ? d.rec.left = 100, d.rec.width = 24, d.rec.height = 30 :
        d.sec < 0.2 ? d.rec.left = 124, d.rec.width = 29, d.rec.height = 29 :
        (d.rec.left = 153, d.rec.width = 27, d.rec.height = 31)) :
    d.rec.left < 1252 && d.speedx != 0 && d.speedy != 0 ?
        (d.sec < 0.1 ? d.rec.left = 726, d.rec.width = 24, d.rec.height = 30 :
        d.sec < 0.2 ? d.rec.left = 750, d.rec.width = 29, d.rec.height = 29 :
        (d.rec.left = 779, d.rec.width = 27, d.rec.height = 31)) :
    d.rec.left < 1878 && d.speedx != 0 && d.speedy != 0 ?
        (d.sec < 0.1 ? d.rec.left = 1352, d.rec.width = 24, d.rec.height = 30 :
        d.sec < 0.2 ? d.rec.left = 1376, d.rec.width = 29, d.rec.height = 29 :
        (d.rec.left = 1405, d.rec.width = 27, d.rec.height = 31)) : 1;
    return (horizontal(g, d));
}

sfIntRect vertical(game g, duck d)
{
    d.rec.left < 626 && d.speedx == 0 && d.speedy != 0 ?
        (d.sec < 0.1 ? d.rec.left = 180, d.rec.width = 24, d.rec.height = 30 :
        d.sec < 0.2 ? d.rec.left = 204, d.rec.width = 32, d.rec.height = 30 :
        (d.rec.left = 236, d.rec.width = 28, d.rec.height = 29)) :
    d.rec.left < 1252 && d.speedx == 0 && d.speedy != 0 ?
        (d.sec < 0.1 ? d.rec.left = 806, d.rec.width = 24, d.rec.height = 30 :
        d.sec < 0.2 ? d.rec.left = 830, d.rec.width = 32, d.rec.height = 30 :
        (d.rec.left = 862, d.rec.width = 28, d.rec.height = 29)) :
    d.rec.left < 1878 && d.speedx == 0 && d.speedy != 0 ?
        (d.sec < 0.1 ? d.rec.left = 1431, d.rec.width = 24, d.rec.height = 30 :
        d.sec < 0.2 ? d.rec.left = 1455, d.rec.width = 32, d.rec.height = 30 :
        (d.rec.left = 1487, d.rec.width = 28, d.rec.height = 29)) : 1;
    d.rec.left < 626 && d.shot ? (d.sec < 0.3 ? d.rec.left = 264, d.rec.width
    = 31, d.rec.height = 29 : (d.rec.left = 295, d.rec.width = 18, d.rec.height
    = 31)) : d.rec.left < 1252 && d.shot ? (d.sec < 0.3 ? d.rec.left = 890,
    d.rec.width = 31, d.rec.height = 29 : (d.rec.left = 921, d.rec.width = 18,
    d.rec.height = 31)) : d.rec.left < 1878 && d.shot ? (d.sec < 0.3 ?
    d.rec.left = 1516, d.rec.width = 31, d.rec.height = 29 :(d.rec.left = 1547,
    d.rec.width = 18, d.rec.height = 31)) : 1;
    return (diagonal(g, d));
}

hound intro(game g, hound h)
{
    h.sec < 0.3 ? h.rec.left = 1877, h.rec.width = 53, h.rec.height = 42 :
    h.sec < 0.6 ? h.rec.left = 1930, h.rec.width = 51, h.rec.height = 43 :
    h.sec < 0.9 ? h.rec.left = 1981, h.rec.width = 52, h.rec.height = 43 :
    h.sec < 1.2 ? h.rec.left = 2033, h.rec.width = 55, h.rec.height = 43 :
    h.sec < 1.5 ? h.rec.left = 2088, h.rec.width = 53, h.rec.height = 43 :
    h.sec < 1.8 ? h.rec.left = 2141, h.rec.width = 53, h.rec.height = 42 :
    h.sec < 2.1 ? h.rec.left = 2194, h.rec.width = 35, h.rec.height = 41 :
    (h.rec.left = 2229, h.rec.width = 33, h.rec.height = 33);
    if (h.sec < 1.5 || h.sec > 1.8) h.pos.x += 0.03;
    if (h.sec > 1.8 && h.sec < 2.1) h.pos.y -= 0.06;
    if (h.sec > 2.1) h.pos.y += 0.06;
    return (h);
}