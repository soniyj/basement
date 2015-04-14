/**
 * Example of Factorial Sequence
 * Copyright (C) 2014. Marco "soniyj" Matascioli
 */
#include<stdio.h>

double fact(int n) {
  int i;
  double f = 1;
  
  if(n==0)
    return 1;
  
  for(i=1; i<n+1; i++)
    f = f * i;
  
  return f;
}

int main() {
  int n;

  printf("Enter the number you wish to calculate\n");
  scanf("%d",&n);
  
  printf("Factorial %d! is :\n",n);
  
  printf("%.0lf\n", fact(n));
  
  return 0;
}