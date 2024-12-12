#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>

#ifndef __SHOOTING_GAME_FUNC_H__
#define __SHOOTINE_GAME_FUNC_H__

#define WIDTH 80
#define HEIGHT 25

void init_screen(short width, short height);
void input_key(int& move, int& shoot);
void updatePosFighter(int& xpos, int move);
void setPosBullet(int ypos_f, int xpos_f, int& ypos_b, int& xpos_b);
void updatePosBullet(int& ypos, int move);
bool checkCollision(int ypos_f, int xpos_f, int ypos_b, int xpos_b);
void updateScreen(int ypos_of, int xpos_of, int ypos_ef, int xos_ef, int ypos_ob, int xpos_ob, int ypos_eb, int xpos_eb);

#endif
