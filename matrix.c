#include "main.h"
/*include library from main.h*/

/*Function of Encrypt, that encrypt by matrix 3*3 x matrix 1x3 of word. And Matrix 1x3 of word came from ascii code of 
3 character*/
void encrypt(char user[]){
  char txt[100];
  FILE *userDa = fopen("History.txt", "a");
  char massage[100], cha;
  int c, matrix[3][3], count = 0, ind = 0, code[3][3]
  , len;
  intermatrix(txt);
  printf("Please input massage : ");
  scanf(" %[^\n]s\n", massage);
  intermatrix(txt);
  printf("input matrix to encrypt : ");
  len = strlen(massage);
  /*If 3 charactor of last has 2 charactor fill 0 until 3*/
  if (len%3 != 0){
    for(int i = 1;i<=len%3;i++){
      strcat(massage, "0");
      len++;
    }
  }
  int matrixmass[len/3][3], ans[len], sum = 0, a = 0;
  /*Transfrom string 0 to int 0*/
  for(int i = 0;i< len/3;i++){
    for(int j = 0;j < 3;j++){
    if (massage[ind] == '0'){
      matrixmass[i][j] = 0;
    }
    else{
    matrixmass[i][j] = massage[ind];}
   ind++;}
  }
  /*input matrix 3x3 to encrypt with masage*/
  for (int i = 0;i < 3;i++){
    for(int j = 0;j< 3;j++){
    scanf("%d", &code[i][j]);
    }
  }
  /*Multiple matrix*/
  for (int i =0;i< len/3;i++){
     for(int k = 0;k < 3;k++){
       for(int j = 0;j < 3;j++){
         sum = sum + (matrixmass[i][j]*code[j][k]);
       }
      ans[a] = sum;
      sum = 0;
      a++;
     }
  }
  fprintf(userDa, "%s\n", user);
  intermatrix(txt);
  for(int i =0; i<a;i++){
      fprintf(userDa, "%d ", ans[i]);
      printf("%d ", ans[i]);
    }
    
    fprintf(userDa, "\n");
  fclose(userDa);
  int u;
  scanf("%d", &u);
  if (u == 3){
    chosseoption(user);} 
}