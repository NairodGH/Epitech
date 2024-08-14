/*
** EPITECH PROJECT, 2020
** 101pong.c
** File description:
** calculate position of pong ball after time + n and angle of colision
*/

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void my_101pong(double x0, double y0, double z0, double x1, double y1, double z1, int n)
{
    double speed[3]; //calculate ball speed
    speed[0] = x1 - x0;
    speed[1] = y1 - y0;
    speed[2] = z1 - z0;

    double coords[3]; //calculate ball coords at time n
    coords[0] = x1 + (speed[0] * n);
    coords[1] = y1 + (speed[1] * n);
    coords[2] = z1 + (speed[2] * n);

    double angle; //calculate angle of collision
    angle = fabs(speed[2]) / sqrt(pow(speed[0], 2) + pow(speed[1], 2) + pow(speed[2], 2));
    angle = acos(angle);
    angle = 90 - angle * (180 / M_PI);
    if (90 < angle && angle < 180)
        angle = 180 - angle;

    if ((z1 > 0 && 0 > coords[2]) || (z1 < 0 && 0 < coords[2]) || (z0 == 0 && z1 == 0)) //prints
        printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\nAt time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\nThe incidence angle is:\n%.2f degrees\n", speed[0], speed[1], speed[2], n, coords[0], coords[1], coords[2], angle);
    else
        printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\nAt time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\nThe ball won't reach the paddle.\n", speed[0], speed[1], speed[2], n, coords[0], coords[1], coords[2]);
}

int main(int argc, char **argv)
{
    if (argc != 8) //error: not enough args
        exit(84);
    for (int i = 1; i < 8; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!('0' <= argv[i][j] && argv[i][j] <= '9' || argv[i][j] == '-' || argv[i][j] == '.')) //error: not-number-only args
                exit(84);
        }
    }
    for (int i = 0; argv[7][i] != '\0'; i++) {
        if (argv[7][i] == '-' || argv[7][i] == '.') //error: negative/float time shift
            exit(84);
    }
    my_101pong(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6]), atoi(argv[7]));
    return (0);
}