#include <stdio.h>
#include "menu.h"
#include "create.h"

void PrintMenu(){
    printf(">> NEW GAME\n");
    printf(">> LOAD\n");
    printf(">> ");
}

int random_int(int min, int max) 
{
   return min + rand() % (max - min);
}

void NewGame(MATRIKS *Map,PLAYER *P1, PLAYER *P2){
    int NB,NK,i,j,x,y;
    UNIT NewUnit;
    POINT Lokasi;
    boolean random;

    printf(">> MAP SIZE :");
    scanf("%d %d", &NB, &NK);
    /* Make Map */
    MakeMATRIKS(NB, NK, Map);
    for(i = 0; i <= NB-1; i++){
        for(j = 0; j <= NK-1; j++){
            Elmt(*Map,i,j).Koordinat = MakePOINT(i,j);
            Elmt(*Map,i,j).Jenis = '-';
            Elmt(*Map,i,j).Owner = '-';
            CreateUnit(&NewUnit, 0, MakePOINT(i,j), 0);
            Elmt(*Map,i,j).Unit = NewUnit;
        }
    }
    /* Init Player 1 */
    (*P1).number = '1';
    (*P1).Gold = 50;
    (*P1).Income = 2;
    (*P1).Upkeep = 1;
    Lokasi = MakePOINT(NB-2, 1);
    CreateUnit(&NewUnit, 4, Lokasi, 1);
    CreateEmpty(&(*P1).ListUnit);
    PutUnitToList(&NewUnit, &(*P1));
    (*P1).SelUnit = NewUnit;
    Elmt(*Map, NB-2, 0).Jenis = 'C';
    Elmt(*Map, NB-2, 0).Owner = '1';
    Elmt(*Map, NB-3, 1).Jenis = 'C';
    Elmt(*Map, NB-3, 1).Owner = '1';
    Elmt(*Map, NB-2, 1).Jenis = 'T';
    Elmt(*Map, NB-2, 1).Owner = '1';
    Elmt(*Map, NB-2, 1).Unit = NewUnit;
    Elmt(*Map, NB-1, 1).Jenis = 'C';
    Elmt(*Map, NB-1, 1).Owner = '1';
    Elmt(*Map, NB-2, 2).Jenis = 'C';
    Elmt(*Map, NB-2, 2).Owner = '1';
    /* Init Player 2 */
    (*P2).number = '2';
    (*P2).Gold = 50;
    (*P2).Income = 2;
    (*P2).Upkeep = 1;
    Lokasi = MakePOINT(1, NK-2);
    CreateUnit(&NewUnit, 4, Lokasi, 2);
    CreateEmpty(&(*P2).ListUnit);
    PutUnitToList(&NewUnit, &(*P2));
    (*P2).SelUnit = NewUnit;
    Elmt(*Map, 0, NK-2).Jenis = 'C';
    Elmt(*Map, 0, NK-2).Owner = '2';
    Elmt(*Map, 1, NK-3).Jenis = 'C';
    Elmt(*Map, 1, NK-3).Owner = '2';
    Elmt(*Map, 1, NK-2).Jenis = 'T';
    Elmt(*Map, 1, NK-2).Owner = '2';
    Elmt(*Map, 1, NK-2).Unit = NewUnit;
    Elmt(*Map, 1, NK-1).Jenis = 'C';
    Elmt(*Map, 1, NK-1).Owner = '2';
    Elmt(*Map, 2, NK-2).Jenis = 'C';
    Elmt(*Map, 2, NK-2).Owner = '2';

    for(i = 1; i <= ((NB*NK)/10); i++){
        do{
            random = true;
            x = random_int(0, NB-1);
            y = random_int(0, NK-1);
            if(Elmt(*Map,x,y).Jenis == '-'){
                Elmt(*Map,x,y).Jenis = 'V';
                random = false;
            }
        }while(random);
    }
}

