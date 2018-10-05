#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "matriks.h"
#include "point.h"
#include "unit.h"
#include <stdlib.h>

void PrintMenu();
/* Menampilkan Menu awal ke layar */
int random_int(int min, int max) ;
/* menghasilkan angka random untuk vilage */
void NewGame(MATRIKS *Map, PLAYER *P1, PLAYER *P2);
/* Procedure yang dijalankan jika user memilih new game */


#endif