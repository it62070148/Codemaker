#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

struct data{
    char username[20];
    char pass[20];
}dat[30], last[30];
/* intefade app */
void home();
void intersignup();
void intermatrix();
void interdecode();
void intersignupbe();
void interchossetype();
void interdecoder();
void interlogin();
void characterin();
void interchossedeoren();
/*-----------------------------------*/

/* option */
int checkpunct(char user[20]);
void chosseoption(char user[]);
int checktaken(char user[20], char key[5]);
int login();
void signup();
void chosseMatrix(char user[]);
void chooseChacircle();

/*---------------------------------------*/


/* Decoder matrix function */
void findcode();
int transintmirror(char c, int ind);
int transint(int sum, int ind);
float determinant(float [][3], float);
void cofactor(float [][3], float, int [], int);
void transpose(float [][3], float [][3], float, int [], int);

/*----------------------------------------------------------------*/

/*Encrypt matrix charactor to matrix 1x3*/

void encrypt(char user[]);
/*------------*/

/* charactor circle */

int startcharactorcircle(void);
int detect_index(char code, char cycle[]);
char transcoded_index(int index, char cycle[], int num_rotate);
char input_condition();
int input_num_rotate();
int is_num(char num[]);

/* -----------------------------------*/
