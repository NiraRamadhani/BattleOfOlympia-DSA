/*------------------*/
/* Jessin Donnyson  */
/*     13516112     */
/*   Praktikum 05   */
/*   20 Sept 2017   */
/*------------------*/

/* State Mesin Kata */
#include "mesinkata.h"

boolean EndKata;    /* bisa diakses dimana saja */
Kata CKata;         /* bisa diakses dimana saja */

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
   while ((CC == BLANK) && (CC != MARK))
   {
       ADV();
   }
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    EndKata = false;
    START();
    IgnoreBlank();
    ADVKATA();
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi        <<< TAKE NOTE OF THIS , ( salin then ignore blank )
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;
    }
    else{
        SalinKata();
    }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata               <<< TAKE NOTE OF THIS char pertama bukan blankspace
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong"            <<<< this.... -_-
*/
{
    int i = 1;
    do {

        CKata.TabKata[i] = CC;

        ADV();
        i++;

    }while ( (CC != MARK) && (CC != BLANK) && (i < NMax));

    CKata.Length = i-1;
}

boolean isKataSama(Kata K1, Kata K2)
/* Mengembalikan true jika K1 = K2;
   dua kata dikatakan sama jika panjangnya sama dan
   urutan karakter yang menyusun kata juga sama.
   Dua kata kosong adalah kata yang sama. */
{
  boolean bKataSama;
  int i;
  
  if (K1.Length == K2.Length) {
    bKataSama = true;
    i = 0;
    
    while (bKataSama && i < K1.Length) {
      if (K1.TabKata[i] != K2.TabKata[i]) {
        bKataSama = false;
      }
      i = i+1;
    }
  } else /* K1.Length != K2.Length */ {
    bKataSama = false;
  }
  
  return bKataSama;
}
