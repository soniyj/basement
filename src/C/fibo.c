/**
 * Example of Fibonacci Series
 * Copyright (C) 2014. Marco "soniyj" Matascioli
 */
#include<stdio.h>

void fibo_1(int n) {
  int i, first = 0, second = 1, next;
  
  for(i = 0 ; i < n ; i++) {
    if(i <= 1)
      next = i;
    else {
      next   = first + second;
      first  = second;
      second = next;
    }
    printf("%d\n", next);
   }
}

void fibo_2(int n) {
  int i, first = 0, second = 1, next;
  
  printf("%d\n", first);
  printf("%d\n", second);
  
  for(i = 2 ; i < n ; i++) {
    next   = first + second;
    first  = second;
    second = next;
    printf("%d\n", next);
  }     
}

void fibo_3(int n) {
  int i, a=0, b=1, t=1;

  for(i = 0; i < n; i++) {
    t = a+b;
    a = b;
    b = t;
    printf("%d\n",a);
  }
}

int main() {
  int n;

  printf("Enter the number of terms\n");
  scanf("%d",&n);

  printf("First %d terms of Fibonacci series :\n",n);
  
  if(n > 0) {
    fibo_1(n);
    printf("\n");
    fibo_2(n);
  }
  printf("\n");
  fibo_3(n);

  return 0;
}