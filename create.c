#include "create.h"
#include <string.h>

void CreateUnit(UNIT *U, int N, POINT Lokasi, int Id){
    if(N == 1){ // ARCHER
        strcpy((*U).Name,"Archer");
        (*U).MaxHealth = 100;
        (*U).Health = 100;
        (*U).Attack = 34;
        (*U).MaximumMove = 3;
        (*U).Move = 3;
        (*U).Type = 'R'; // ranged
        (*U).IsAttack = true;
        (*U).Lokasi = Lokasi;
        (*U).harga = 2;
        (*U).Upkeep = 1;
        (*U).Sym = 'A';
        (*U).id = 100 + Id;
    } else if (N == 2) { // SWORDSMAN
        strcpy((*U).Name,"Swordsman");
        (*U).MaxHealth = 120;
        (*U).Health = 120;
        (*U).Attack = 30;
        (*U).MaximumMove = 1;
        (*U).Move = 1;
        (*U).Type = 'M'; // melee
        (*U).IsAttack = true;
        (*U).Lokasi = Lokasi;
        (*U).harga = 3;
        (*U).Upkeep = 2;
        (*U).Sym = 'S';
        (*U).id = 200 + Id;
    } else if (N == 3) { // WHITE MAGE
        strcpy((*U).Name,"White Mage");
        (*U).MaxHealth = 150;
        (*U).Health = 150;
        (*U).Attack = 40;
        (*U).MaximumMove = 2;
        (*U).Move = 2;
        (*U).Type = 'R'; // ranged
        (*U).IsAttack = true;
        (*U).Lokasi = Lokasi;
        (*U).harga = 4;
        (*U).Upkeep = 3;
        (*U).Sym = 'W';
        (*U).Heal = 90;
        (*U).id = 300 + Id;
    } else if (N == 4) { // KING
        strcpy((*U).Name,"King");
        (*U).MaxHealth = 200;
        (*U).Health = 200;
        (*U).Attack = 50;
        (*U).MaximumMove = 2;
        (*U).Move = 2;
        (*U).Type = 'M'; // melee
        (*U).IsAttack = true;
        (*U).Lokasi = Lokasi;
        (*U).harga = 10;
        (*U).Upkeep = 1;
        (*U).Sym = 'K';
        (*U).id = 400 + Id;
    } else if(N == 0){ // Empty Unit
        strcpy((*U).Name,"-");
        (*U).MaxHealth = 0;
        (*U).Health = 0;
        (*U).Attack = 0;
        (*U).MaximumMove = 0;
        (*U).Move = 0;
        (*U).Type = '-'; // melee
        (*U).IsAttack = false;
        (*U).Lokasi = Lokasi;
        (*U).harga = 0;
        (*U).Upkeep = 0;
        (*U).Sym = '-';
        (*U).id = 0;
    }
    CreateEmptyStack(&(*U).MoveStack);
}

void PutUnitToList(UNIT *U, PLAYER *P){
    (*U).Owner = (*P).number;
    InsVLast(&(*P).ListUnit,(*U).id);
}