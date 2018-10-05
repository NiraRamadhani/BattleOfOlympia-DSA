#include "unit.h"
#include <stdio.h>
#include "matriks.h"
#include "create.h"

void Moveable(MATRIKS *Map, UNIT Unit);

void Move(MATRIKS *Map,UNIT *Unit);

void recruit(MATRIKS *M, PLAYER *P, int Id);

void info(MATRIKS M);

void PrintInfoUnit();

void attack(UNIT *A,UNIT *D);

void change_unit(MATRIKS M, PLAYER *P);

void SAVE (PLAYER P1, PLAYER P2, MATRIKS Map, PLAYER CurrentPlayer, int id);

void LOAD (PLAYER * P1, PLAYER * P2, MATRIKS * Map, PLAYER * CurrentPlayer, int * id);

void Undo(MATRIKS *Map,UNIT *Unit);

void Heal(UNIT *U, PLAYER *P, MATRIKS *Map);