#ifndef UNIT_H
#define UNIT_H

#include "boolean.h"
#include "point.h"
#include "listlinier.h"
#include "movestack.h"

typedef struct{
    char Name[12];
    int id;
    int MaxHealth;
    int Health;
    int Attack;
    int MaximumMove;
    int Move;
    char Type;
    boolean IsAttack;
    POINT Lokasi;
    int harga;
    int Upkeep;
    char Owner;
    char Sym;
    int Heal;
    Stack MoveStack;
} UNIT;

typedef struct{
    POINT Koordinat;
    char Jenis;
    char Owner;
    UNIT Unit;
} MAP;

typedef struct{
    char number;
    int Gold;
    UNIT SelUnit;
    List ListUnit;
    MAP ListVillage[10];
    int Income;
    int Upkeep;
    char Warna;
} PLAYER;

#endif