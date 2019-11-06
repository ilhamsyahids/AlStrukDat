/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */

#ifndef __MESINTOKEN_H__
#define __MESINTOKEN_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct {
  char tkn; /* token yang dibaca */
  int val;  /* nilai bilangan jika tkn = 'b' */
} Token;

/* State Mesin Kata */
extern boolean EndToken;
extern Token CToken;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN();
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken();
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif
