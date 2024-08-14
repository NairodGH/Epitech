/*
** EPITECH PROJECT, 2020
** firtree
** File description:
** Function that displays a fir tree_ex based on its given size
*/

// include unistd.h pour write
#include <unistd.h>

int my_get_girth_ex(int size) //return the lenght of the bottom line of a triangle
{
    int i = 0; //counter for the conditionnal while loop depending on the size
    int branches = 1; //counter required to calculate the lenght of the last line of a triangle
    int branch_height = 4; //base height for a tree_ex of size 1
    int girth_max = 1; //lenght of the last line of the bottom triangle

    while (i != size) { //the tree_ex has as many branches as his size
        girth_max = girth_max + (2 * (branch_height - branches)); //calculate the lenght of the last line of the triangle
        branch_height++;
        if (i % 2 == 0) //the separation space between triangles is bigger by 1 for each for one triangle out of two (from top to bottom)
            branches = branches + 1;
        i++; //repeat process depending on size parameter given
    }
    return (girth_max); //return value of the lenght of the last line of the bottom triangle
}

int my_get_height_ex(int size) //return the height of a triangle
{
    int i = 0; //counter for the conditionnal while loop depending on the size
    int crown_height = 0; //height of the tree_ex crown
    int branch_height = 4; //base height for a tree_ex of size 1

    while ( i != size ) { //the tree_ex's triangles height gets bigger by 1 for each (from top to bottom)
        crown_height = crown_height + branch_height; //adds the heighs of the triangles up to the last one to get the crown's height
        branch_height++;
        i++; //repeat process depending on size parameter given
    }
    return (crown_height); //return value of the height of the crown
}

int foliage_ex(int branch)
{
    if (branch % 2 == 0)
        return (1);
    else
        return (0);
}

void my_draw_crown_ex(int air, int leaf, int girth_max, int photo_air) //draw the ' 's and '*'s to draw the crown
{
    air = 0;
    while (air != (girth_max / 2) - photo_air) { //fill right side of the line by spaces
        air++;
        my_putchar(' ');
    }
    leaf = 0;
    while (leaf != 1 + (photo_air * 2)) { //fill the space between the photo_air at the end of the spaces and its double + 1 by stars
        leaf++;
        my_putchar('*');
    }
}

void my_create_crown_ex(int size, int girth_max, int crown_height) //create the shape of the crown to fill it by stars afterward
{
    int i = 0;
    int air; //space
    int leaf; //star
    int photo_air = 0; //space before the first star of a branch line
    int branches = 0; //counter required to calculate the lenght of the last line of a triangle
    int branch = 1; //triangles on themselves
    int twig = my_get_height_ex(branch); //last star of a line

    while (i != crown_height) {
        if (i == twig) {
            branch = branch + 1; 
            twig = my_get_height_ex(branch);
            branches = branches + foliage_ex(branch);
            photo_air = photo_air - (branches + 1);
        }
        my_draw_crown_ex(air, leaf, girth_max, photo_air);
        i++;
        photo_air = photo_air + 1;
        my_putchar('\n');
    }
}

void my_draw_bole_ex(int air, int bark, int girth_max, int trunk_width)
{
    air = 0;
    while (air != (girth_max / 2 - trunk_width / 2)) {
        air++;
        my_putchar(' ');
    }
    bark = 0;
    while (bark != trunk_width) {
        bark++;
        my_putchar('|');
    }
}

void my_create_bole_ex(int size, int girth_max)
{
    int i = 0;
    int air;
    int bark;
    int trunk_width = size;
    int trunk_height = size;

    if (size % 2 == 0)
        trunk_width = trunk_width + 1;
    while (i != trunk_height) {
        my_draw_bole_ex(air, bark, girth_max, trunk_width);
        i++;
        my_putchar('\n');
    }
}

void tree_ex(int size)
{
    int girth_max = my_get_girth_ex(size);
    int crown_height = my_get_height_ex(size);

    if (size > 0) {
        my_create_crown_ex(size, girth_max, crown_height);
        my_create_bole_ex(size, girth_max);
    }
}