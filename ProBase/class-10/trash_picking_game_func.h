#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")

// インクルードガード
#ifndef __TRASH_PICKING_GAME_FUNC_H__
#define __TRASH_PICKING_GAME_FUNC_H__

#define WIDTH 80
#define HEIGHT 25
#define INTERVAL 1.0
#define LIMIT_TIME 30.0

void input_key(int& ypos, int& xpos, int& figure);
void walk_baltan(int ypos, int xpos, int figure);
void init_screen(short width, short height);
bool check_interval_time();
void throw_out_trash(int map[HEIGHT][WIDTH]);
void print_trash(int map[HEIGHT][WIDTH]);
int check_trash_picking(int ypos, int xpos, int map[HEIGHT][WIDTH]); // 練習6
void start_time();
double get_time();
//void print_remaining_time();
bool print_remaining_time(); // 練習3, 4
void wait_to_push_esc_key(); // 練習5
void print_score(int score); // 練習7

#endif
