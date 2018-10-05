
/* NOTES */

/* Stack disusun dengan tabel */
/* TOP adalah INDEKS elemen TERAKHIR */

/* Nil = 0 ,, MaxEl = 10 */
/* Definisi stack S kosong : S.TOP = Nil */
/* Top(S) untuk akses INDEKS top , InfoTop(S) untuk akses value top */



#include "movestack.h"
#include <stdio.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
    TopX(*S) = Nol;
    TopY(*S) = 1;
    TopZ(*S) = 2;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return TopX(S) == Nol && TopY(S) == 1 && TopZ(S) == 2;
}

boolean IsFull (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return TopZ(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X, infotype Y, infotype Z)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmptyStack(*S)){
        TopX(*S) = 1;
        TopY(*S) = 2;
        TopZ(*S) = 3;
    }

    else {
        TopX(*S) += 3;
        TopY(*S) += 3;
        TopZ(*S) += 3;
    }

    InfoTopX(*S) = X;
    InfoTopY(*S) = Y;
    InfoTopZ(*S) = Z;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* X, infotype *Y, infotype *Z)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTopX(*S);
    *Y = InfoTopY(*S);
    *Z = InfoTopZ(*S);

    if (TopX(*S) == 1){
        CreateEmptyStack(S);
    }

    else{
        TopX(*S) -= 3;
        TopY(*S) -= 3;
        TopZ(*S) -= 3;
    }
}

// void PrintStack(Stack S);
void PrintStack(Stack S)
{
    int i, j, k;

    i = TopX(S);
    j = TopY(S);
    k = TopZ(S);
    while(i > -1) {
        while(j > 0){
           while(k > 1){
             printf("%d %d %d", InfoTopX(S), InfoTopY(S), InfoTopZ(S));
             k = k - 3;
           }
            j = j - 3;
        }
        printf("\n");
        i = i - 3;
    }
}

