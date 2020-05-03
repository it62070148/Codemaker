#include "main.h"

void encrypt(char user[]){
  FILE *userDa = fopen("History.txt", "a");
  char massage[100], cha;
  int c, matrix[3][3], count = 0, ind = 0, code[3][3]
  , len;
  printf("Please input massage : ");
  scanf(" %[^\n]s\n", massage);
  printf("input matrix to encrypt : ");
  len = strlen(massage);
  if (len%3 != 0){
    for(int i = 1;i<=len%3;i++){
      strcat(massage, "0");
      len++;
    }
  }
  int matrixmass[len/3][3], ans[len], sum = 0, a = 0;
  for(int i = 0;i< len/3;i++){
    for(int j = 0;j < 3;j++){
    if (massage[ind] == '0'){
      matrixmass[i][j] = 0;
    }
    else{
    matrixmass[i][j] = massage[ind];}
   ind++;}
  }
  for (int i = 0;i < 3;i++){
    for(int j = 0;j< 3;j++){
    scanf("%d", &code[i][j]);
    }
  }
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
  for(int i =0; i<a;i++){
      fprintf(userDa, "%d ", ans[i]);
      printf("%d ", ans[i]);
    }
    fprintf(userDa, "\n");
  fclose(userDa);
  int u;
  printf("1. You will close program\n2. back to manu\n");
  scanf("%d", &u);
  if (u == 2){
    chosseoption(user);} 
}