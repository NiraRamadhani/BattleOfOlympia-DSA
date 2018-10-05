#include "layout.h"
#include "pcolor.h"
#include <stdio.h>

void PrintMap(MATRIKS Map,PLAYER P)
/* Menampilkan Map */
{   /* KAMUS LOKAL */
    int i, j, k;
    /* ALGORITMA */
    for(k = 0; k <= (NKolEff(Map)-1); k++){
        if(k == 0){
            printf("     %d  ",k);
        }else if (k >= 10){
            printf("%d  ",k);
        }else{
            printf(" %d  ",k);
        }
    }
    printf("\n");
    for(i = 0; i <= (NBrsEff(Map)-1); i++){
        for(j = 1; j <= 4; j++){
            if(j == 3){
                if(i < 10){
                        printf(" %d ",i);
                    }else{
                        printf("%d ",i);
                    }

            }else{
                printf("   ");
            }
            for(k = 0; k <= (NKolEff(Map)-1); k++){
                if(j == 1){
                    if(k == 0){
                        printf("*****");
                    }else{
                        printf("****");
                    }
                }
                else if(j == 2){
                    printf("* ");
                    if(Elmt(Map,i,k).Owner == '1'){
                        print_red(Elmt(Map,i,k).Jenis);
                    }else if(Elmt(Map,i,k).Owner == '2'){
                        print_blue(Elmt(Map,i,k).Jenis);
                    }else{
                        printf("%c",Elmt(Map,i,k).Jenis);
                    }
                    printf(" ");
                    if(k == (NKolEff(Map)-1)){
                        printf("*");
                    }
                }
                else if(j == 3){
                    printf("* ");
                    if(P.SelUnit.id == Elmt(Map,i,k).Unit.id){
                        print_green(Elmt(Map,i,k).Unit.Sym);
                    }else if(Elmt(Map,i,k).Unit.Owner == '1'){
                        print_red(Elmt(Map,i,k).Unit.Sym);
                    }else if(Elmt(Map,i,k).Unit.Owner == '2'){
                        print_blue(Elmt(Map,i,k).Unit.Sym);
                    }else{
                        printf("%c",Elmt(Map,i,k).Unit.Sym);
                    }
                    printf(" ");
                    if(k == (NKolEff(Map)-1)){
                        printf("*");
                    }
                }
                else if(j == 4){
                    printf("*   ");
                    if(k == (NKolEff(Map)-1)){
                        printf("*");
                    }
                }
            }
            printf("\n");
        }
    }
    for(k = 1; k <= NKolEff(Map); k++){
        if(k == 1){
            printf("   *****");
        }else{
            printf("****");
        }
    }
}

void PrintMove(MATRIKS Map,PLAYER P){
	int m;
  boolean atas = true;
  boolean kiri = true;
  boolean bawah = true;
  boolean kanan = true;

  for(m = 1; m <= P.SelUnit.Move; m++){
    if( (Elmt(Map,P.SelUnit.Lokasi.X + m,P.SelUnit.Lokasi.Y).Unit.Owner != P.number) && Elmt(Map,P.SelUnit.Lokasi.X + m,P.SelUnit.Lokasi.Y).Unit.Sym != '-'){
      bawah = false;
      if((P.SelUnit.Lokasi.X + m) >= Map.NBrsEff){
        bawah = true;
      }
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X + m,P.SelUnit.Lokasi.Y).Unit.Sym == '-') && bawah){
      Elmt(Map,P.SelUnit.Lokasi.X + m,P.SelUnit.Lokasi.Y).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X - m,P.SelUnit.Lokasi.Y).Unit.Owner != P.number) && Elmt(Map,P.SelUnit.Lokasi.X - m,P.SelUnit.Lokasi.Y).Unit.Sym != '-'){
      atas = false;
      if((P.SelUnit.Lokasi.X - m) < 0){
        bawah = true;
      }
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X - m,P.SelUnit.Lokasi.Y).Unit.Sym == '-') && atas){
      Elmt(Map,P.SelUnit.Lokasi.X - m,P.SelUnit.Lokasi.Y).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y + m).Unit.Owner != P.number) && Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y + m).Unit.Sym != '-'){
      kanan = false;
      if((P.SelUnit.Lokasi.Y + m) >= Map.NKolEff){
        kanan = true;
      }
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y + m).Unit.Sym == '-') && kanan){
      Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y + m).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Owner != P.number) && Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Sym != '-'){
      kiri = false;
      if((P.SelUnit.Lokasi.Y + m) < 0){
        atas = true;
      }
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Sym == '-')&& kiri){
      Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X + m-1, P.SelUnit.Lokasi.Y + m/2).Unit.Sym == '-')&&(bawah || kanan)){
        Elmt(Map,P.SelUnit.Lokasi.X + m-1, P.SelUnit.Lokasi.Y + m/2).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X - m+1, P.SelUnit.Lokasi.Y - m/2).Unit.Sym == '-')&&(atas || kiri)){
        Elmt(Map,P.SelUnit.Lokasi.X - m+1, P.SelUnit.Lokasi.Y - m/2).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X + m-1, P.SelUnit.Lokasi.Y - m/2).Unit.Sym == '-')&&(bawah || kiri)){
        Elmt(Map,P.SelUnit.Lokasi.X + m-1, P.SelUnit.Lokasi.Y - m/2).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X - m+1, P.SelUnit.Lokasi.Y + m/2).Unit.Sym == '-')&&(atas || kanan)){
        Elmt(Map,P.SelUnit.Lokasi.X - m+1, P.SelUnit.Lokasi.Y + m/2).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Sym == '-')&& kiri){
      Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y + m-1).Unit.Sym == '-')&&(bawah || kanan)){
        Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y + m-1).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y - m+1).Unit.Sym == '-')&&(atas || kiri)){
        Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y - m+1).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y - m+1).Unit.Sym == '-')&&(bawah || kiri)){
        Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y - m+1).Unit.Sym = '#';
    }
    if( (Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y + m-1).Unit.Sym == '-')&&(atas || kanan)){
        Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y + m-1).Unit.Sym = '#';
    }

/*	for(m = 1; m <= P.SelUnit.Move; m++){
		if( Elmt(Map,P.SelUnit.Lokasi.X + m,P.SelUnit.Lokasi.Y).Unit.Sym == '-'){
			Elmt(Map,P.SelUnit.Lokasi.X + m,P.SelUnit.Lokasi.Y).Unit.Sym = '#';
		}
		if( Elmt(Map,P.SelUnit.Lokasi.X - m,P.SelUnit.Lokasi.Y).Unit.Sym == '-'){
			Elmt(Map,P.SelUnit.Lokasi.X - m,P.SelUnit.Lokasi.Y).Unit.Sym = '#';
		}
		if( Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y + m).Unit.Sym == '-'){
			Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y + m).Unit.Sym = '#';
		}
		if( Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Sym == '-'){
			Elmt(Map,P.SelUnit.Lokasi.X,P.SelUnit.Lokasi.Y - m).Unit.Sym = '#';
		}
    if( Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y + m/2).Unit.Sym == '-'){
        Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y + m/2).Unit.Sym = '#';
    }
    if( Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y - m/2).Unit.Sym == '-'){
        Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y - m/2).Unit.Sym = '#';
    }
    if( Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y - m/2).Unit.Sym == '-'){
        Elmt(Map,P.SelUnit.Lokasi.X + m/2, P.SelUnit.Lokasi.Y - m/2).Unit.Sym = '#';
    }
    if( Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y + m/2).Unit.Sym == '-'){
        Elmt(Map,P.SelUnit.Lokasi.X - m/2, P.SelUnit.Lokasi.Y + m/2).Unit.Sym = '#';
    } */
	}
    /// PrintMap ///
    /* KAMUS LOKAL */
    int i, j, k;
    /* ALGORITMA */
    for(k = 0; k <= (NKolEff(Map)-1); k++){
        if(k == 0){
            printf("     %d  ",k);
        }else if (k >= 10){
            printf("%d  ",k);
        }else{
            printf(" %d  ",k);
        }
    }
    printf("\n");
    for(i = 0; i <= (NBrsEff(Map)-1); i++){
        for(j = 1; j <= 4; j++){
            if(j == 3){
                if(i < 10){
                        printf(" %d ",i);
                    }else{
                        printf("%d ",i);
                    }

            }else{
                printf("   ");
            }
            for(k = 0; k <= (NKolEff(Map)-1); k++){
                if(j == 1){
                    if(k == 0){
                        printf("*****");
                    }else{
                        printf("****");
                    }
                }
                else if(j == 2){
                    printf("* ");
                    if(Elmt(Map,i,k).Owner == '1'){
                        print_red(Elmt(Map,i,k).Jenis);
                    }else if(Elmt(Map,i,k).Owner == '2'){
                        print_blue(Elmt(Map,i,k).Jenis);
                    }else{
                        printf("%c",Elmt(Map,i,k).Jenis);
                    }
                    printf(" ");
                    if(k == (NKolEff(Map)-1)){
                        printf("*");
                    }
                }
                else if(j == 3){
                    printf("* ");
                    if(P.SelUnit.id == Elmt(Map,i,k).Unit.id){
                        print_green(Elmt(Map,i,k).Unit.Sym);
                    }else if(Elmt(Map,i,k).Unit.Owner == '1'){
                        print_red(Elmt(Map,i,k).Unit.Sym);
                    }else if(Elmt(Map,i,k).Unit.Owner == '2'){
                        print_blue(Elmt(Map,i,k).Unit.Sym);
                    }else{
                        printf("%c",Elmt(Map,i,k).Unit.Sym);
                    }
                    printf(" ");
                    if(k == (NKolEff(Map)-1)){
                        printf("*");
                    }
                }
                else if(j == 4){
                    printf("*   ");
                    if(k == (NKolEff(Map)-1)){
                        printf("*");
                    }
                }
            }
            printf("\n");
        }
    }
    for(k = 1; k <= NKolEff(Map); k++){
        if(k == 1){
            printf("   *****");
        }else{
            printf("****");
        }
    }
}

void PrintTurn(PLAYER P)
{   /* KAMUS LOKAL */

    /* ALGORITMA */
    printf("\n>> PLAYER %c's TURN\n",P.number);
    printf("\n>> |======== LIST OF COMMAND ========| ");
    printf("\n>> |   MOVE  | CHANGE_UNIT |   UNDO  | ");
    printf("\n>> | RECRUIT |    ATTACK   |    MAP  | ");
    printf("\n>> |   INFO  |   END_TURN  |   SAVE  | ");
    printf("\n>> |         |     EXIT    |         | ");
    printf("\n\n>> Cash : %dG | Income: %dG | Upkeep: %dG \n",P.Gold,P.Income,P.Upkeep);
    printf(">> Unit : %s",P.SelUnit.Name);
    TulisPOINT(P.SelUnit.Lokasi);
    printf(" | Movement Point: %d | Can Attack: ",P.SelUnit.Move);
    if(P.SelUnit.IsAttack){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}

void PrintListOfRecruits()
{

}

void PrintListOfUnits()
{

}
