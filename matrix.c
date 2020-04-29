#include "stdio.h"
#include "string.h"
#include "math.h"
#include "ctype.h"
int main(){
  char massage[100], cha;
  int c, matrix[3][3], count = 0, ind = 0, code[3][3]
  , len;
  printf("Please input massage\n");
  scanf("%s", massage);
  printf("input code\n");
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
  for(int i =0; i<a;i++){
      printf("%d ", ans[i]);
    }
}