#include <stdio.h>
#include "unit.h"
#include "point.h"
#include "listlinier.h"

void change_unit(MAP M, PLAYER P) {
	UNIT U;
	int ident;

	printf("=== LIST OF UNIT ===\n");
	ShowPlayersUnit(P); //current

	printf("Your active unit: ");
	U = SearchUnitbyID(P.SellUnit);
	printf(U.Name);
	printf("\n");

	printf(">Enter the ID of Unit You Want to Select:\n");
	scanf("%d", &ident);
	P.Current_unit = ident;
	U = SearchUnitbyID(P.SellUnit);

	printf("Your current active unit: ");
	printf(U.Name);
	printf("\n");
}


void info(MAP M) {
	int x, y;
	POINT Lokasi;

	printf("Enter the coordinate of the cell: ");
	scanf("%d %d", &x, &y);
	printf("\n");
	Lokasi = MakePoint(x,y);
	M.Koordinat = Lokasi;

	printf("=== CELL INFO ===\n");
	switch (M.Jenis){
            case 'V' :
            	printf("VILLAGE\n");
            	break;
            case 'C' :
            	printf("CASTLE\n");
            	break;
            case 'T' :
            	printf("TOWER\n");
            	break;
            default	 :
            	printf("The cell is an empty cell. \n");
    }

    printf("Owned by Player %d\n", M.Owner);

    printf("=== UNIT INFO ===\n");
    printf("%s", M.Unit.Name);
    printf("Owned by Player %d\n", M.Owner);
    printf("Health %d/%d | ATK %d | DEF %d \n", M.Unit.Health, M.Unit.MaxHealth, M.Unit.Attack, M.Unit.Def);
}
