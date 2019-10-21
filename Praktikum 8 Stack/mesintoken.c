#include "mesintoken.h"

/* State Mesin Kata */
boolean EndToken;
Token CToken;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
  while((CC == BLANK) && (CC != MARK)) {
    ADV();
  }

}

void STARTTOKEN(){
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
  START();
  IgnoreBlank();
  if (CC == MARK) {
    EndToken = true;
  } else {
    EndToken = false;
    SalinToken();
  }
}

void ADVTOKEN(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
  IgnoreBlank();
  if (CC == MARK) {
    EndToken = true;
  } else {
    SalinToken();
    IgnoreBlank();
  }
}

void SalinToken(){
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
  int i = 1;
  CToken.val = 0;

  while ((CC != MARK) && (CC != BLANK) && (i <= NMax)) {
    if ((CC != '+') && (CC != '-') && (CC != '*') && (CC != '/') && (CC != '^')) {
      switch(CC) {
        case '1' :
          CToken.val = CToken.val*10 + 1;
          break;
        case '2' :
          CToken.val = CToken.val*10 + 2;
          break;
        case '3' :
          CToken.val = CToken.val*10 + 3;
          break;
        case '4' :
          CToken.val = CToken.val*10 + 4;
          break;
        case '5' :
          CToken.val = CToken.val*10 + 5;
          break;
        case '6' :
          CToken.val = CToken.val*10 + 6;
          break;
        case '7' :
          CToken.val = CToken.val*10 + 7;
          break;
        case '8' :
          CToken.val = CToken.val*10 + 8;
          break;
        case '9' :
          CToken.val = CToken.val*10 + 9;
          break;
        default :
          CToken.val = CToken.val*10 + 0;
          break;
      }
      CToken.tkn = 'b';
    } else {
      CToken.tkn = CC;
      CToken.val = -1;
    }
    ADV();
    i++;
  }
}
