#include "stdio.h"
#include "string.h"
#include "math.h"
#include "ctype.h"
int main(){
  char massage[100], code[10], cha;
  int c, matrix[3][3], count = 0, ind = 0, indxm = 0;
  printf("Please input massage\n");
  scanf("%s", massage);
  printf("input code\n");
  scanf("%s", code);
  for (int i = 0;i < 3;i++){
    for(int j =0;j<3;j++){
      c = code[indxm];
      cha = c-48;
      matrix[i][j] = cha;
      indxm++;
    }
    
  }
  int len = strlen((massage));
  if(len%3 == 0){
    len--;
  }
  struct test{
    int keep[3];
  }masstrix[len/3], decoder[len/3];
  for(int i = 0;i < strlen(massage);i++){
    c = massage[i];
    masstrix[count].keep[ind] = c;
    ind++;
    if(i%3 == 2 && i!= 0){
      count++;
      ind = 0;
    }
  }
  int row = 0, col = 0, sum = 0, a=0, b = 0;
  for(int i =0;i <= len/3;i++){
    for(int k =0;k <3;k++){
      for(int j =0;j<3;j++){
      ind = masstrix[i].keep[j];
      sum += ((ind*matrix[j][k]));
      }
      decoder[i].keep[k]= sum;
      printf("%d", sum);
      sum = 0;
    }
    printf("\n");
  }
  for(int i =0; i<=len/3;i++){
    for(int j = 0;j<3;j++){
      printf("%d ", decoder[i].keep[j]);
    }
    printf("\n");
  }
  
  
}