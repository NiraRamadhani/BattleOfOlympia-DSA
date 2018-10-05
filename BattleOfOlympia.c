#include "unit.h"
#include "menu.h"
#include "matriks.h"
#include <stdio.h>
#include <string.h>
#include "layout.h"
#include "create.h"
#include "turn.h"
#include "mesinkata.h"


int main(){
    /* KAMUS */
    char Menu[10];
    char Command[10];
    PLAYER P1,P2;
    MATRIKS Map;
    PLAYER CurrentPlayer;
    boolean Loop = true;
    int id = 0;
    int i, j, x, y, cnt;
    UNIT King, Enemy, Empty, U;
    Kata Movee, Recruit, Undoo, Attack, New_Game, Info, Change_Unit, End_Turn, KataCommand, Mapp;

    Movee.TabKata[0] = 'M';
    Movee.TabKata[1] = 'O';
    Movee.TabKata[2] = 'V';
    Movee.TabKata[3] = 'E';
    Movee.Length = 4;

    Recruit.TabKata[0] = 'R';
    Recruit.TabKata[1] = 'E';
    Recruit.TabKata[2] = 'C';
    Recruit.TabKata[3] = 'R';
    Recruit.TabKata[4] = 'U';
    Recruit.TabKata[5] = 'I';
    Recruit.TabKata[6] = 'T';
    Recruit.Length = 7;

    Undoo.TabKata[0] = 'U';
    Undoo.TabKata[1] = 'N';
    Undoo.TabKata[2] = 'D';
    Undoo.TabKata[3] = 'O';
    Undoo.Length = 4;

    Attack.TabKata[0] = 'A';
    Attack.TabKata[1] = 'T';
    Attack.TabKata[2] = 'T';
    Attack.TabKata[3] = 'A';
    Attack.TabKata[4] = 'C';
    Attack.TabKata[5] = 'K';
    Attack.Length = 6;

    New_Game.TabKata[0] = 'N';
    New_Game.TabKata[1] = 'E';
    New_Game.TabKata[2] = 'W';
    New_Game.TabKata[3] = '_';
    New_Game.TabKata[4] = 'G';
    New_Game.TabKata[5] = 'A';
    New_Game.TabKata[6] = 'M';
    New_Game.TabKata[7] = 'E';
    New_Game.Length = 8;

    Info.TabKata[0] = 'I';
    Info.TabKata[1] = 'N';
    Info.TabKata[2] = 'F';
    Info.TabKata[3] = 'O';
    Info.Length = 4;

    Change_Unit.TabKata[0] = 'C';
    Change_Unit.TabKata[1] = 'H';
    Change_Unit.TabKata[2] = 'A';
    Change_Unit.TabKata[3] = 'N';
    Change_Unit.TabKata[4] = 'G';
    Change_Unit.TabKata[5] = 'E';
    Change_Unit.TabKata[6] = '_';
    Change_Unit.TabKata[7] = 'U';
    Change_Unit.TabKata[8] = 'N';
    Change_Unit.TabKata[9] = 'I';
    Change_Unit.TabKata[10] = 'T';
    Change_Unit.Length = 11;

    End_Turn.TabKata[0] = 'E';
    End_Turn.TabKata[1] = 'N';
    End_Turn.TabKata[2] = 'D';
    End_Turn.TabKata[3] = '_';
    End_Turn.TabKata[4] = 'T';
    End_Turn.TabKata[5] = 'U';
    End_Turn.TabKata[6] = 'R';
    End_Turn.TabKata[7] = 'N';
    End_Turn.Length = 8;

    Mapp.TabKata[0] = 'M';
    Mapp.TabKata[1] = 'A';
    Mapp.TabKata[2] = 'P';
    Mapp.Length = 3;

    printf("\n");
    /* ALGORITMA */
    printf("▀█████████▄     ▄████████     ███         ███      ▄█          ▄████████       ▄██████▄     ▄████████       ▄██████▄   ▄█       ▄██   ▄     ▄▄▄▄███▄▄▄▄      ▄███████▄  ▄█     ▄████████ \n");
    printf("  ███    ███   ███    ███ ▀█████████▄ ▀█████████▄ ███         ███    ███      ███    ███   ███    ███      ███    ███ ███       ███   ██▄ ▄██▀▀▀███▀▀▀██▄   ███    ███ ███    ███    ███ \n");
    printf("  ███    ███   ███    ███    ▀███▀▀██    ▀███▀▀██ ███         ███    █▀       ███    ███   ███    █▀       ███    ███ ███       ███▄▄▄███ ███   ███   ███   ███    ███ ███▌   ███    ███ \n");
    printf(" ▄███▄▄▄██▀    ███    ███     ███   ▀     ███   ▀ ███        ▄███▄▄▄          ███    ███  ▄███▄▄▄          ███    ███ ███       ▀▀▀▀▀▀███ ███   ███   ███   ███    ███ ███▌   ███    ███ \n");
    printf("▀▀███▀▀▀██▄  ▀███████████     ███         ███     ███       ▀▀███▀▀▀          ███    ███ ▀▀███▀▀▀          ███    ███ ███       ▄██   ███ ███   ███   ███ ▀█████████▀  ███▌ ▀███████████ \n");
    printf("  ███    ██▄   ███    ███     ███         ███     ███         ███    █▄       ███    ███   ███             ███    ███ ███       ███   ███ ███   ███   ███   ███        ███    ███    ███ \n");
    printf("  ███    ███   ███    ███     ███         ███     ███▌    ▄   ███    ███      ███    ███   ███             ███    ███ ███▌    ▄ ███   ███ ███   ███   ███   ███        ███    ███    ███ \n");
    printf("▄█████████▀    ███    █▀     ▄████▀      ▄████▀   █████▄▄██   ██████████       ▀██████▀    ███              ▀██████▀  █████▄▄██  ▀█████▀   ▀█   ███   █▀   ▄████▀      █▀     ███    █▀  \n");
    printf("                                                  ▀                                                                   ▀                                                                  \n");
    PrintMenu();
    while (Loop){
        scanf("%s",&Menu[0]); /* Menerima input menu */
        if(strcmp(Menu,"NEW_GAME")==0){ /*New Game*/
            NewGame(&Map,&P1,&P2);
            CurrentPlayer = P1;
            Loop = false;
        }else if(strcmp(Menu, "LOAD")==0){
            LOAD (&P1, &P2, &Map, &CurrentPlayer, &id);
            Loop = false;
        }else{
            printf(">> Input salah.\n");
            printf(">> ");
        }
    }
    Loop = true;
    while(Loop){
        PrintMap(Map, CurrentPlayer);
        printf("\n");
        PrintTurn(CurrentPlayer);
        printf("\n>> YOUR INPUT : ");
        scanf("%s",&Command[0]);
        for (i = 0; i < strlen(Command); ++i)
        {
            KataCommand.TabKata[i] = Command[i];
        }
        KataCommand.Length = strlen(Command);
        if(isKataSama(Movee,KataCommand)){
            //Move();
            printf("1\n");
            PrintMove(Map, CurrentPlayer);
            printf("\n");
            Move(&Map,&CurrentPlayer.SelUnit);
            cnt = 0;
            for(i = 0; i <= Map.NBrsEff; i++){
                for(j = 0; j <= Map.NKolEff; j++){
                    if((Elmt(Map,i,j).Jenis == 'V')&&(Elmt(Map,i,j).Owner == CurrentPlayer.number)){
                        cnt += 1;
                    }
                }
            }
            CurrentPlayer.Income = 2*(cnt+1);
        }else if(isKataSama(Recruit,KataCommand)){
            recruit(&Map,&CurrentPlayer, id);
            id++;
        }else if(isKataSama(Undoo,KataCommand)){
            Undo(&Map,&CurrentPlayer.SelUnit);
        }else if(isKataSama(Change_Unit,KataCommand)){
            change_unit(Map, &CurrentPlayer);
            //change_unit(Map, &CurrentPlayer);
            //printf("\n");
        }else if(isKataSama(Attack,KataCommand)){
            printf(">> Enter the coordinate of the enemy you want to attack: ");
            scanf("%d %d", &x, &y);
            if(abs(CurrentPlayer.SelUnit.Lokasi.X - x) + abs(CurrentPlayer.SelUnit.Lokasi.Y - y) == 1){
                if(Elmt(Map,x,y).Unit.Sym != '-'){
                    if(Elmt(Map,x,y).Unit.Owner != CurrentPlayer.number){
                        attack(&CurrentPlayer.SelUnit, &(Elmt(Map, x, y)).Unit);
                        Elmt(Map,CurrentPlayer.SelUnit.Lokasi.X,CurrentPlayer.SelUnit.Lokasi.Y).Unit = CurrentPlayer.SelUnit;
                         //jika Unit mati
                        if (CurrentPlayer.SelUnit.Health <= 0) {
                            if (CurrentPlayer.SelUnit.Sym == 'K') {
                                printf(">> G A M E  O V E R\n");
                                if (CurrentPlayer.number == '1') {
                                    printf(">> === THE WINNER IS PLAYER 2 ===\n");
                                } else {
                                    printf(">> === THE WINNER IS PLAYER 1 ===\n");
                                }
                            } else {
                                DelP(&CurrentPlayer.ListUnit, (CurrentPlayer.SelUnit.id));
                                CreateUnit(&Empty, 0, CurrentPlayer.SelUnit.Lokasi, 0);
                                Elmt(Map, CurrentPlayer.SelUnit.Lokasi.X, CurrentPlayer.SelUnit.Lokasi.Y).Unit = Empty;
                            }
                        }
                        if (Elmt(Map, x, y).Unit.Health <= 0) {
                            if (CurrentPlayer.number == '1') { 
                                    if (Elmt(Map, x, y).Unit.Sym == 'K') {
                                        printf("G A M E  O V E R\n");
                                        printf("=== THE WINNER IS PLAYER 1 ===\n");
                                        break;
                                    } else {
                                        DelP(&CurrentPlayer.ListUnit, (Elmt(Map, x, y).Unit.id));
                                        CreateUnit(&Empty, 0, Elmt(Map, x, y).Unit.Lokasi, 0);
                                        Elmt(Map, Elmt(Map, x, y).Unit.Lokasi.X, Elmt(Map, x, y).Unit.Lokasi.Y).Unit = Empty;
                                        DelP(&P2.ListUnit, (Elmt(Map, x, y).Unit.id));
                                    }
                            } else {
                                if (Elmt(Map, x, y).Unit.Sym == 'K') {
                                    printf(">> G A M E  O V E R\n");
                                    printf(">> === THE WINNER IS PLAYER 2 ===\n");
                                    break;
                                } else {
                                        DelP(&CurrentPlayer.ListUnit, (Elmt(Map, x, y).Unit.id));
                                        CreateUnit(&Empty, 0, Elmt(Map, x, y).Unit.Lokasi, 0);
                                        Elmt(Map, Elmt(Map, x, y).Unit.Lokasi.X, Elmt(Map, x, y).Unit.Lokasi.Y).Unit = Empty;
                                        DelP(&P1.ListUnit, (Elmt(Map, x, y).Unit.id));
                                }
                            }
                        }
                    }else{
                        printf(">> You can't attack your own unit!\n");
                    }
                }else{
                    printf(">> There ain't anybody there.\n");                
                }
            }else{
                printf(">> Your target is too far.\n");
            }
            printf("\n");
        } else if(isKataSama(Mapp,KataCommand)){
            PrintMap(Map, CurrentPlayer);
            printf("\n");
        }else if(isKataSama(Info,KataCommand)){
            info(Map);
            printf("\n");
        }else if((isKataSama(End_Turn,KataCommand))){
            CurrentPlayer.Gold = CurrentPlayer.Gold + CurrentPlayer.Income - CurrentPlayer.Upkeep;
            // reset unit move & attack//
            for(i = 0; i <= Map.NBrsEff - 1; i++){
                for(j = 0; j <= Map.NKolEff - 1; j++){
                    Elmt(Map,i,j).Unit.Move = Elmt(Map,i,j).Unit.MaximumMove;
                    Elmt(Map,i,j).Unit.IsAttack = true;
                }
            }
            // white mage & village heal//
            for (int i = 0; i <= Map.NBrsEff; ++i){
                for (int j = 0; j <= Map.NKolEff; ++j){
                    if (Elmt(Map,i,j).Unit.Sym == 'W' && Elmt(Map,i,j).Unit.Owner == CurrentPlayer.number)
                    {
                        Heal(&Elmt(Map,i,j).Unit, &CurrentPlayer, &Map);
                    }
                    if (Elmt(Map,i,j).Jenis == 'V' && Elmt(Map,i,j).Unit.Owner == CurrentPlayer.number){
                        Elmt(Map,i,j).Unit.Health = Elmt(Map,i,j).Unit.Health + 50;
                        if(Elmt(Map,i,j).Unit.Health > Elmt(Map,i,j).Unit.MaxHealth){
                            Elmt(Map,i,j).Unit.Health = Elmt(Map,i,j).Unit.MaxHealth;
                        }
                    }
                }
            }
            // Change Player //
            if(CurrentPlayer.number == '1'){
                P1 = CurrentPlayer;
                CurrentPlayer = P2;
                for(i = 0; i<= Map.NBrsEff - 1; i++){
                    for(j = 0; j<= Map.NKolEff - 1; j++){
                        if(Elmt(Map,i,j).Unit.id == 402){
                            King = Elmt(Map,i,j).Unit;
                        }
                    }
                }
                CurrentPlayer.SelUnit = King;
            }else{
                P2 = CurrentPlayer;
                CurrentPlayer = P1;
                for(i = 0; i<= Map.NBrsEff - 1; i++){
                    for(j = 0; j<= Map.NKolEff - 1; j++){
                        if(Elmt(Map,i,j).Unit.id == 401){
                            King = Elmt(Map,i,j).Unit;
                        }
                    }
                }
                CurrentPlayer.SelUnit = King;
            }
            
        }else if(strcmp(Command,"SAVE")==0){
            SAVE (P1, P2, Map, CurrentPlayer, id);
        }else if(strcmp(Command,"EXIT")==0){
            break;
        }else{
            printf("Input salah. \n");
        }

    }
    return 0;
}
