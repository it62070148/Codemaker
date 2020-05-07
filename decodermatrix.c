#include "main.h"

/*find massage */
void findcode(){
  char txt[100];
  float a[3][3], d, k = 3;
  char code[100], c, word[100];
  int i,ind = 0, j, sum = 0, massint[100], l = 0, inverse[3][3];
  interdecoder(txt);
  printf("Please input matrixcode : ");
  scanf(" %[^\n]s", code);
  strcat(code, " ");
  interdecoder(txt);
  printf("\nEnter the elements of %.0fX%.0f Matrix : ", k, k);
  /*Input matrix of 3x3 ,that to encrypt massage*/
  for (i = 0;i < k; i++){
     for (j = 0;j < k; j++){
        scanf("%f", &a[i][j]);
        }
    }
  // printf("%ld\n", strlen(code));
  /*tranform string to int */
  for (i = 0;i < strlen(code);i++){
    c = code[i];
    if (c != ' '){
      sum += transintmirror(c, ind);
      ind++;
    }
    else{
      sum = transint(sum, ind);
      massint[l] = sum;
      ind = 0;
      sum = 0;
      l++;
    }
  }
  d = determinant(a, k);
  if (d == 0){
   printf("\nInverse of Entered Matrix is not possible\n");
  }
  else{
    cofactor(a, k, massint, l);
  }
}
 
/*For calculating Determinant of the Matrix */
float determinant(float a[3][3], float k)
{
  float s = 1, det = 0, b[3][3];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 /*find cofactor*/
void cofactor(float num[3][3], float f, int massint[100], int l){
 float b[3][3], fac[3][3];
 int p, q, m, n, i, j, inverse[3][3];
 for (q = 0;q < f; q++){
   for (p = 0;p < f; p++){
     m = 0;
     n = 0;
     for (i = 0;i < f; i++){
       for (j = 0;j < f; j++){
          if (i != q && j != p){
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else{
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f, massint, l);
}
/*Finding transpose of matrix to inverse matrix*/ 
void transpose(float num[3][3], float fac[3][3], float r, int massint[100], int l){
  int i, j, k, skip = 0, a = 0, c;
  char txt[100];
  float b[3][3], inverse[3][3], d, sum = 0, ans[100];
  for (i = 0;i < r; i++){
     for (j = 0;j < r; j++){
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
  for(i = 0;i< l/3;++i){
    for(j = 0;j < 3;++j){
      for(k = 0;k<3;++k){
        sum += inverse[k][j]*massint[k+skip];
      }
      ans[a] = sum;
      sum = 0;
      a++;
    }
    skip += 3;
  } 
  for(i = 0;i< a;++i){
    c = round(ans[i]);
    txt[i] = c;
  }
  interdecoder(txt);
  char user[20];
  int u;
  scanf("%d", &u);
  if (u == 3){
    chosseoption(user);} 
}
/*transform strings to int, but int is mirror such as 123 to 321*/
int transintmirror(char c, int ind){
  int  n;
  n = c-48;
  n *= pow(10, ind);
  return n;
}
/*trans mirror to correct int 321 to 123*/
int transint(int sum, int ind){
  int i, ans = 0, c = 0, a = 0;
  ind--;
  for (i = ind;i>= 0;i--){
    c = sum/pow(10, i);
    sum -= c*pow(10, i);
    c *= pow(10, a);
    ans += c;
    a++;
  }
  return ans;
}