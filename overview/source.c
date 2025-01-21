#include <stdio.h>

#include "myheaderfile.h"

// shared constants definitions
const int MY_MAX = 123;
const char* MY_MESSAGE = "This is a constant string.";
const double MY_PI = 3.14;

// shared variables definitions
int mysharedint = 123;
double myshareddouble = 456.789;

void myfunction() {
  printf("\n Accessing shared constants from source.c:\n");
  printf("%d, %s, %lf\n", MY_MAX, MY_MESSAGE, MY_PI);
  printf("Accessing shared global variables from source.c:\n");
  printf("%d %lf\n", mysharedint, myshareddouble);
}
