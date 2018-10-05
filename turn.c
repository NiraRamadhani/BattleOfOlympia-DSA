#include "turn.h"
#include <stdio.h>
#include <stdlib.h>
#include "create.h"
#include "point.h"

void Moveable(MATRIKS *Map, UNIT Unit){
  int m;
  boolean atas = true;
  boolean kiri = true;
  boolean bawah = true;
  boolean kanan = true;

  for(m = 1; m <= Unit.Move; m++){
    if( (Elmt((*Map),Unit.Lokasi.X + m,Unit.Lokasi.Y).Unit.Owner != Unit.Owner) && Elmt((*Map),Unit.Lokasi.X + m,Unit.Lokasi.Y).Unit.Sym != '-'){
      bawah = false;
      if((Unit.Lokasi.X + m) >= (*Map).NBrsEff){
        bawah = true;
      }
    }
    if( (Elmt((*Map),Unit.Lokasi.X + m,Unit.Lokasi.Y).Unit.Sym == '-') && bawah){
      Elmt((*Map),Unit.Lokasi.X + m,Unit.Lokasi.Y).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X - m,Unit.Lokasi.Y).Unit.Owner != Unit.Owner) && Elmt((*Map),Unit.Lokasi.X - m,Unit.Lokasi.Y).Unit.Sym != '-'){
      atas = false;
      if((Unit.Lokasi.X - m) < 0){
        bawah = true;
      }
    }
    if( (Elmt((*Map),Unit.Lokasi.X - m,Unit.Lokasi.Y).Unit.Sym == '-') && atas){
      Elmt((*Map),Unit.Lokasi.X - m,Unit.Lokasi.Y).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y + m).Unit.Owner != Unit.Owner) && Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y + m).Unit.Sym != '-'){
      kanan = false;
      if((Unit.Lokasi.Y + m) >= (*Map).NKolEff){
        kanan = true;
      }
    }
    if( (Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y + m).Unit.Sym == '-') && kanan){
      Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y + m).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y - m).Unit.Owner != Unit.Owner) && Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y - m).Unit.Sym != '-'){
      kiri = false;
      if((Unit.Lokasi.Y + m) < 0){
        atas = true;
      }
    }
    if( (Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y - m).Unit.Sym == '-')&& kiri){
      Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y - m).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X + m-1, Unit.Lokasi.Y + m/2).Unit.Sym == '-')&&(bawah || kanan)){
        Elmt((*Map),Unit.Lokasi.X + m-1, Unit.Lokasi.Y + m/2).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X - m+1, Unit.Lokasi.Y - m/2).Unit.Sym == '-')&&(atas || kiri)){
        Elmt((*Map),Unit.Lokasi.X - m+1, Unit.Lokasi.Y - m/2).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X + m-1, Unit.Lokasi.Y - m/2).Unit.Sym == '-')&&(bawah || kiri)){
        Elmt((*Map),Unit.Lokasi.X + m-1, Unit.Lokasi.Y - m/2).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X - m+1, Unit.Lokasi.Y + m/2).Unit.Sym == '-')&&(atas || kanan)){
        Elmt((*Map),Unit.Lokasi.X - m+1, Unit.Lokasi.Y + m/2).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y - m).Unit.Sym == '-')&& kiri){
      Elmt((*Map),Unit.Lokasi.X,Unit.Lokasi.Y - m).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X + m/2, Unit.Lokasi.Y + m-1).Unit.Sym == '-')&&(bawah || kanan)){
        Elmt((*Map),Unit.Lokasi.X + m/2, Unit.Lokasi.Y + m-1).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X - m/2, Unit.Lokasi.Y - m+1).Unit.Sym == '-')&&(atas || kiri)){
        Elmt((*Map),Unit.Lokasi.X - m/2, Unit.Lokasi.Y - m+1).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X + m/2, Unit.Lokasi.Y - m+1).Unit.Sym == '-')&&(bawah || kiri)){
        Elmt((*Map),Unit.Lokasi.X + m/2, Unit.Lokasi.Y - m+1).Unit.Sym = '#';
    }
    if( (Elmt((*Map),Unit.Lokasi.X - m/2, Unit.Lokasi.Y + m-1).Unit.Sym == '-')&&(atas || kanan)){
        Elmt((*Map),Unit.Lokasi.X - m/2, Unit.Lokasi.Y + m-1).Unit.Sym = '#';
    }
  }
}

void Move(MATRIKS *Map,UNIT *Unit){
    /* KAMUS LOKAL */
    int x,y;
    UNIT NewUnit;
    MATRIKS MapTemp;
	boolean bmove = false;

    /* ALGORITMA */
    Push(&(*Unit).MoveStack, (*Unit).Lokasi.X, (*Unit).Lokasi.Y, (*Unit).Move);
	while(!bmove){
    if((*Unit).Move > 0){
      printf(">> Please enter coordinate : ");
		  scanf("%d %d",&x,&y);
      if((x == (*Unit).Lokasi.X)&&(y == (*Unit).Lokasi.Y)){
        printf(">> You didn't move\n");
        bmove = true;
      }else{
        MapTemp = *Map;
        Moveable(&MapTemp,*Unit);
        if(Elmt(MapTemp,x,y).Unit.Sym == '#') {
          (*Unit).Move = (*Unit).Move - (abs((*Unit).Lokasi.X - x) + abs((*Unit).Lokasi.Y - y));
          CreateUnit(&NewUnit, 0, (*Unit).Lokasi, 0);
          Elmt(*Map,(*Unit).Lokasi.X,(*Unit).Lokasi.Y).Unit = NewUnit;
          (*Unit).Lokasi = MakePOINT(x,y);
          Elmt(*Map,(*Unit).Lokasi.X,(*Unit).Lokasi.Y).Unit = *Unit;
          printf(">> You have successfully moved to");
          TulisPOINT(MakePOINT(x,y));
          printf("\n");
          if((Elmt(*Map,x,y).Jenis == 'V')&&(Elmt(*Map,x,y).Owner != (*Unit).Owner)){
            Elmt(*Map,x,y).Owner = (*Unit).Owner;
            Elmt(*Map,x,y).Unit.Move = 0;
            printf(">> You have captured a village.\n\n");
          }
          bmove = true;
        }else{
          printf(">> You can't move there.\n\n");
        }
      }
    }else{
      printf(">> Your unit don't have movement point left.\n\n");
      bmove = true;
    }

	}
}

void Undo(MATRIKS *Map,UNIT *Unit){
    /* KAMUS LOKAL */
    int x,y,z;
    UNIT NewUnit;
	boolean bmove = false;

    /* ALGORITMA */
    if (IsEmptyStack((*Unit).MoveStack)){
    	printf(">> You can't undo. Keep tryin' fighter.\n");
    } else {
    	Pop(&(*Unit).MoveStack, &x, &y, &z);
	    (*Unit).Move = z;
	    while(!bmove){
			if((abs((*Unit).Lokasi.X - x) + abs((*Unit).Lokasi.Y - y)) <= (*Unit).Move){
				(*Unit).Move = (*Unit).Move - (abs((*Unit).Lokasi.X - x) + abs((*Unit).Lokasi.Y - y));
				CreateUnit(&NewUnit, 0, (*Unit).Lokasi, 0);
				Elmt(*Map,(*Unit).Lokasi.X,(*Unit).Lokasi.Y).Unit = NewUnit;
				(*Unit).Lokasi = MakePOINT(x,y);
				Elmt(*Map,(*Unit).Lokasi.X,(*Unit).Lokasi.Y).Unit = *Unit;
				printf("You have successfully gone back to");
				TulisPOINT(MakePOINT(x,y));
				printf("\n");
				bmove = true;
			}
		}
		(*Unit).Move = z;
    }
}

void PrintInfoUnit() {
  printf(">> 1. Archer      | Health 100 | ATK 34 | DEF | 2G\n");
  printf(">> 2. Swordsman   | Health 120 | ATK 30 | DEF | 3G\n");
  printf(">> 3. White Mage  | Health 150 | ATK 40 | DEF | 4G\n");
}

void recruit(MATRIKS *M, PLAYER *P, int Id) {
	int x, y;
	int N;
	char c;
	POINT Lokasii;
	UNIT U;
	boolean cancel;

	if ((*P).SelUnit.Sym == 'K') {
		cancel = false;
		if (Elmt(*M,(*P).SelUnit.Lokasi.X,(*P).SelUnit.Lokasi.Y).Jenis != 'T') {
		  printf(">> You are not even in a tower. Move to the tower first.\n");
		} else {
      printf(">> Enter coordinate of an empty castle: ");
  		do {
  			scanf("%d %d", &x, &y);
  			Lokasii = MakePOINT(x, y);
  			if (Elmt(*M, x, y).Jenis != 'C') {
  				printf(">> It's not even a castle!\n");
  				printf(">> Enter coordinate of an empty castle: ");
  			} else {
  				if ((*P).SelUnit.Owner != Elmt(*M, x, y).Owner) {
  					printf(">> That castle is occupied by another player!\n");
  					printf(">> Do you want to cancel? Y/N\n");
  					scanf("%s", &c);
  					if (c == 'Y'){
  						cancel = true;
  					}
  				} else {
  					printf("\n>> ====== List of Recruits =====\n");
  					PrintInfoUnit();
  					printf(">> Enter no. of unit you want to recruit: ");
  					scanf("%d", &N);
  					CreateUnit(&U, N, Lokasii, Id);
  					PutUnitToList(&U, &(*P));
  					U.Move = 0;
  					//MONEY DECREASE
  				    Elmt(*M,U.Lokasi.X,U.Lokasi.Y).Unit = U;
  					(*P).Gold = (*P).Gold - U.harga;
  					(*P).Upkeep = (*P).Upkeep + U.Upkeep;
  					printf(">> You have recruited a/an ");
  					if (U.Sym == 'A') {
  						printf("Archer\n");
  					}
  					if (U.Sym == 'S') {
  						printf("Swordsman\n");
  					}
  					if (U.Sym == 'W') {
  						printf("White Mage\n");
  					}
  				}
  			}

  		} while (Elmt(*M, x, y).Jenis != 'C' && (cancel==false));
    }
	} else {
		printf(">> Your current unit is not a King! You can't recruit an unit.\n");
	}
}

void info(MATRIKS M) {
	int x, y;
	POINT Lokasi;

	printf(">> Enter the coordinate of the cell: ");
	scanf("%d %d", &x, &y);
	printf("\n");

	printf(">> ======= CELL INFO =======\n");
	switch (Elmt(M, x, y).Jenis){
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
            	printf(">> The cell is an empty cell. \n");
    }

    printf(">> Owned by Player %c\n", Elmt(M, x, y).Owner);

    printf(">> ======= UNIT INFO =======\n");
    if (Elmt(M, x, y).Unit.Sym == 'A') {
    	printf("Archer\n");
	}
	if (Elmt(M, x, y).Unit.Sym == 'S') {
		printf("Swordsman\n");
	}
	if (Elmt(M, x, y).Unit.Sym == 'W') {
		printf("White Mage\n");
	}
  if (Elmt(M, x, y).Unit.Sym == 'K') {
    printf("King\n");
  }
    printf("Owned by Player %c\n", Elmt(M, x, y).Unit.Owner);
    printf("Health %d/%d | ATK %d | DEF  \n", Elmt(M, x, y).Unit.Health, Elmt(M, x, y).Unit.MaxHealth, Elmt(M, x, y).Unit.Attack);
}

void attack(UNIT *A,UNIT *D)
//Unit A menyerang unit D, Kalau unit D tidak mati akan balik serang unit A
{
	//serangan berhasil
	(*D).Health= (*D).Health - (*A).Attack;
	printf(">> Enemy’s %s is damaged by %d\n", (*D).Name,(*A).Attack);
	if((*D).Health>0){//Unit D tidak mati, menyerang balik
		printf(">> Enemy's %s retaliates\n", (*D).Name);
		//serangan balik berhasil
		(*A).Health= (*A).Health - (*D).Attack;
		printf(">> Your %s is damaged by %d\n", (*A).Name,(*D).Attack);
		if((*A).Health<=0){
			printf(">> Your %s is dead\n", (*A).Name);
		}
	} else {//*D.Health<=0
		printf(">> Enemy %s is dead!\n", (*D).Name);
	}
	(*A).IsAttack = false;
}

UNIT SearchUnitbyID(MATRIKS M, int ID){
	boolean found;
	int i, j;
	UNIT U;

	i = 0;
	found = false;
	while(i <= M.NBrsEff && !found){
		j = 0;
		while(j <= M.NKolEff && !found){
			if (Elmt(M,i,j).Unit.id == ID){
				found = true;
				U = Elmt(M,i,j).Unit;
			} else {
				j++;
			}
			i++;
		}
	}
	return U;
}

void change_unit(MATRIKS M, PLAYER *P) {
	UNIT U;
	int ident;
	address N;
	int num = 1;
	int x,y,i,j;

	N = First((*P).ListUnit);
	printf("\n======= LIST OF UNIT =======\n");
	while(N != Nil){
		for(i = 0; i<= M.NBrsEff - 1; i++){
            for(j = 0; j<= M.NKolEff - 1; j++){
                if(Elmt(M,i,j).Unit.id == Info(N)){
                    U = Elmt(M,i,j).Unit;
                }
            }
        }
		printf(">> %d. %s", num, U.Name);
		TulisPOINT(U.Lokasi);
		printf(" | Health %d", U.Health);
		num++;
		printf("\n");
		N = Next(N);
	}
	printf("\n>> Please enter the number of unit you want to select: ");
	scanf("%d", &ident);
	N = First((*P).ListUnit);
	i = 1;
	while(i < ident){
		N = Next(N);
		i++;
	}
	for(i = 0; i<= M.NBrsEff - 1; i++){
        for(j = 0; j<= M.NKolEff - 1; j++){
            if(Elmt(M,i,j).Unit.id == Info(N)){
                U = Elmt(M,i,j).Unit;
            }
        }
    }


	(*P).SelUnit = U;

	printf(">> Your current active unit: ");
	printf("%s", U.Name);
	printf("\n\n");
}

void Heal(UNIT *U, PLAYER *P, MATRIKS *Map) {
  int i, j;

  int x = ((*U).Lokasi.X) - 1;
  int y = ((*U).Lokasi.Y) - 1;
  for (i = x; i< (x+2); i++) {
    for (j = y; j< (y+2); j++) {
      if (Elmt(*Map, i, j).Unit.Sym != '-') {
        if (Elmt(*Map, i, j).Unit.Owner == (*P).SelUnit.Owner) {
          if (Elmt(*Map,i,j).Unit.Health + (*U).Heal >= Elmt(*Map,i,j).Unit.MaxHealth){
            Elmt(*Map,i,j).Unit.Health = Elmt(*Map,i,j).Unit.MaxHealth;
          } else {
            Elmt(*Map,i,j).Unit.Health += (*U).Heal;
          }
        }
      }
    }
  }
}

void SAVE (PLAYER P1, PLAYER P2, MATRIKS Map, PLAYER CurrentPlayer, int id) {
  /* KAMUS */
  address P;
  int i, j, retval;
  FILE *fileku;

  /* ALGORITMA */
  fileku = fopen ("save.dat", "w");

  //Save MAP
  retval = fprintf(fileku, "%d|%d|\n", NBrsEff(Map), NKolEff(Map));
  for (i = 0; i<= (NBrsEff(Map)-1); i++) {
    for (j = 0; j <= (NKolEff(Map)-1); j++) {
        retval = fprintf(fileku, "%d|%d|", i,j);
        retval = fprintf(fileku, "%d|", Elmt(Map,i,j).Jenis);
        retval = fprintf(fileku, "%d|", Elmt(Map,i,j).Owner);
        retval = fprintf(fileku, "%d|", Elmt(Map,i,j).Unit.Sym);
        retval = fprintf(fileku, "%d|", Elmt(Map,i,j).Unit.id);
        retval = fprintf(fileku, "%d|", Elmt(Map,i,j).Unit.Health);
        retval = fprintf(fileku, "%d|", Elmt(Map,i,j).Unit.Move);
        retval = fprintf(fileku, "%d|", Elmt(Map,i,j).Unit.IsAttack);
        retval = fprintf(fileku, "%d\n", Elmt(Map,i,j).Unit.Owner);
    }
  }

  //Save State P1
  retval = fprintf(fileku, "%d|", P1.number);
  retval = fprintf(fileku, "%d|", P1.Gold);
  retval = fprintf(fileku, "%d|", P1.Income);
  retval = fprintf(fileku, "%d|", P1.Upkeep);
  //Save State UNIT P1
  retval = fprintf(fileku, "%d\n", P1.SelUnit.id);

  //Save State P2
  retval = fprintf(fileku, "%d|", P2.number);
  retval = fprintf(fileku, "%d|", P2.Gold);
  retval = fprintf(fileku, "%d|", P2.Income);
  retval = fprintf(fileku, "%d|", P2.Upkeep);
  //Save State UNIT P1
  retval = fprintf(fileku, "%d\n", P2.SelUnit.id);

  retval = fprintf(fileku, "%d|", CurrentPlayer.number);
  retval = fprintf(fileku, "%d.", id);

  fclose(fileku);
  printf(">> The game has been successfully saved.\n");
}

void LOAD (PLAYER * P1, PLAYER * P2, MATRIKS * Map, PLAYER * CurrentPlayer, int * id) {
  /* KAMUS */
  address P;
  int cc,  sym, i, j, X, Y, dd, idx, retval, NB, NK;
  FILE *fileku;
  UNIT NewUnit, U;

  /* ALGORITMA */
  fileku = fopen ("save.dat", "r");

  //Save MAP
  retval = fscanf(fileku, "%d|%d|\n", &NB, &NK);
  MakeMATRIKS(NB, NK, Map);
  (*P1).number = '1';
  (*P2).number = '2';
  CreateEmpty(&(*P1).ListUnit);
  CreateEmpty(&(*P2).ListUnit);

  for (i = 0; i<= (NBrsEff(*Map)-1); i++) {
    for (j = 0; j <= (NKolEff(*Map)-1); j++) {
        retval = fscanf(fileku, "%d|%d|", &X,&Y);
        Elmt(*Map, i, j).Koordinat = MakePOINT(X,Y);
        retval = fscanf(fileku, "%d|", &Elmt(*Map,i,j).Jenis );
        // Elmt(*Map,i,j).Jenis = cc;
        retval = fscanf(fileku, "%d|", &Elmt(*Map,i,j).Owner);
        // Elmt(*Map,i,j).Owner = cc;

        retval = fscanf(fileku, "%d|", &sym);
        retval = fscanf(fileku, "%d|", &idx);
        if (sym == 65) { // Archer
          CreateUnit(&NewUnit, 1, MakePOINT(X,Y), idx-100);
        } else if (sym == 83) { //Swordsman
          CreateUnit(&NewUnit, 2, MakePOINT(X,Y), idx-200);
        } else if (sym == 87) { //White Mage
          CreateUnit(&NewUnit, 3, MakePOINT(X,Y), idx-300);
        } else if (sym == 75) { //King
          CreateUnit(&NewUnit, 4, MakePOINT(X,Y), idx-400);
        } else {
          CreateUnit(&NewUnit, 0, MakePOINT(X,Y), idx);
        }
        retval = fscanf(fileku, "%d|", &dd);
        NewUnit.Health = dd;
        retval = fscanf(fileku, "%d|", &dd);
        NewUnit.Move = dd;
        retval = fscanf(fileku, "%d|", &dd);
        NewUnit.IsAttack = dd;
        retval = fscanf(fileku, "%d\n", &cc);
        if (cc == 49) { //Player1
          PutUnitToList(&NewUnit, P1);
        } else if (cc == 50) { //Player2
          PutUnitToList(&NewUnit, P2);
        } else {
          NewUnit.Owner = '0';
        }
        Elmt((*Map),i,j).Unit = NewUnit;
    }
  }

  //Save State P1
  retval = fscanf(fileku, "%d|", &cc);
  (*P1).number = cc;
  retval = fscanf(fileku, "%d|", &dd);
  (*P1).Gold = dd;
  retval = fscanf(fileku, "%d|", &dd);
  (*P1).Income = dd;
  retval = fscanf(fileku, "%d|", &dd);
  (*P1).Upkeep = dd;
  //Save State UNIT P1
  retval = fscanf(fileku, "%d\n", &dd);
  for(i = 0; i<= NB - 1; i++){
        for(j = 0; j<= NK - 1; j++){
            if(Elmt(*Map,i,j).Unit.id == dd){
                U = Elmt(*Map,i,j).Unit;
            }
        }
    }
  (*P1).SelUnit = U;

  //Save State P2
  retval = fscanf(fileku, "%d|", &cc);
  (*P2).number = cc;
  retval = fscanf(fileku, "%d|", &dd);
  (*P2).Gold = dd;
  retval = fscanf(fileku, "%d|", &dd);
  (*P2).Income = dd;
  retval = fscanf(fileku, "%d|", &dd);
  (*P2).Upkeep = dd;
  //Save State UNIT P1
  retval = fscanf(fileku, "%d\n", &dd);
  for(i = 0; i<= NB - 1; i++){
        for(j = 0; j<= NK - 1; j++){
            if(Elmt(*Map,i,j).Unit.id == dd){
                U = Elmt(*Map,i,j).Unit;
            }
        }
  }
  (*P2).SelUnit = U;

  retval = fscanf(fileku, "%d|", &cc);
  if (cc == 49) { //1
    *CurrentPlayer = *P1;
  } else if (cc ==50) { //2
    *CurrentPlayer = *P2;
  }
  retval = fscanf(fileku, "%d.", &dd);
  *id = dd;

  fclose(fileku);
  printf(">> Load game success.\n");
}
