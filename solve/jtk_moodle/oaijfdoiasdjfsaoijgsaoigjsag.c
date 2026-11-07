#include <stdio.h>
int f1(int n);
int f2(int nn);
void f3(int *K, int *L, int *M);
int d=6;

int main() {
   int a=5,b=3,c=4;
   printf("\na = %d , b = %d, c = %d",a,b,c);
   printf("\nIncr f1() = %d",f1(a)+1);
   printf("\nf1(a+1) = %d",f1(a+1));
   printf("\nf2 = %d", f2(a+b));
   f3(&a,&b,&c);
   printf("\na = %d, b= %d, c=%d",a,b,c);
   return 0;  
}
int f1(int number) {
   int a= 4;
   return a*number;
}
int f2(int anu) {
   return d+anu;
}
void f3(int *X, int *Y, int *Z) {
   int a=1, b=2, c=3;
   *X=a;  *Y=b; *Z=c;
}