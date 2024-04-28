#pragma once

//headers
#include <iostream>
#include <string>
#include <random>
#include <SFML/Graphics.hpp> 
#include <vector>

//temp
#include < conio.h>

//macro
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

//Window setting
#define WIDTH 960
#define HEIGHT 720

//Scene list
enum SCENE
{
	MAINMENU, OPTION, CREDIT, QUIT
};