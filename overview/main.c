#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>
#include <time.h>
#include <uchar.h>

#define MAX 999
#include "myheaderfile.h"
#include "myutils.h"

void myFunction();  // main.c
void myfunction();  // source.c
void foo(char* arg);

typedef struct {
  char c;
  int x;
  double d;
} MyStruct;

struct Node {
  int x;
  struct Node* left;
  struct Node* right;
};

typedef char* string;

_Noreturn void justExist() {
  printf("This function does not return. Existing...\n");
  exit(0);
}

int dowork(void* arg) {
  thrd_t mythreadid = thrd_current();
  for (int i = 0; i < 5; i++) {
    printf("Thread id: %lu, counter: %d, code: %s\n", mythreadid, i,
           (char*)arg);
  }
  return 0;
}

// deprecated definition
[[deprecated]]
void myoldfunction() {
  printf("This is a deprecated function.\n");
}

int main() {
  // this is a comment
  printf("Hello World!\n");

  /* This is an
   * multi-line
   * comment */
  printf("C rocks!\n");

  char myChar;
  myChar = 97;  // 'a'
  printf("The size of '%c' is %zu byte(s)\n", myChar, sizeof(myChar));

  int x, y, z;
  x = 10;   // decimal constant
  y = 017;  // octal constant
  z = 0xA;  // hexadeciam constant

  printf("Decimal: %d Octal: %o Hexadecimal: %X\n", x, y, z);

  unsigned int xu = 123456789u;
  printf("The value of an unsigned integer is: %u\n", xu);

  short xs;
  xs = 1234;
  printf("The value of a short integer is: %d\n", xs);

  long xl;
  xl = 123456789l;
  printf("The value of a long integer is: %ld\n", xl);

  unsigned short xus;
  xus = 1234u;
  printf("The value of an unsigned short integer is: %hu\n", xus);

  unsigned long xul;
  xul = 123456789ul;
  printf("The value of an unsigned long variable is: %lu\n", xul);

  float myFloat;
  myFloat = 123.456f;
  printf("The size of '%.3f' is %zu byte(s)\n", myFloat, sizeof(myFloat));

  double d;
  d = 123.456;
  printf("The size of '%lf' is %zu byte(s)\n", d, sizeof(d));

  myFunction();
  MyStruct myStruct = {.x = 123, .c = 'a', .d = 456.789};

  printf("Member c has a value of %c\n", myStruct.c);
  printf("Member x has a value of %d\n", myStruct.x);
  printf("Member d has a value of %lf\n", myStruct.d);

  MyStruct* structPtr = &myStruct;
  printf("Member c has a value of %c\n", structPtr->c);
  printf("Member x has a value of %d\n", structPtr->x);
  printf("Member d has a value of %lf\n", structPtr->d);

  string s1, s2;
  bool isTrue;
  s1 = "hello";
  s2 = "world";
  printf("%s %s!\n", s1, s2);

  string tmp;
  char* const p = tmp;
  tmp = "hello world";

  void (*fp)();
  fp = myFunction;
  fp();

  void (*fooptr)(char*);
  fooptr = foo;
  fooptr("This is a function argument.");

  printf("The current source code line is: %d\n", __LINE__);
  printf("This source code file is called: %s\n", __FILE__);
#undef MAX

  int* ptr = malloc(sizeof(int));
  if (ptr == nullptr) {
    printf("Error allocating the memory. Exiting.");
    return -1;
  }

  *ptr = 123;
  printf("The value is: %d\n", *ptr);
  free(ptr);

  int* p1 = calloc(2, sizeof(int));
  if (p1) {
    printf("The initial value is: %d\n", *p1);
  }
  free(p1);

  int* p2 = malloc(sizeof(int));
  printf("Allocated %zu bytes.\n", sizeof *p2);
  printf("Resizing allocated memory...\n");
  int* pnew = realloc(p2, 10 * sizeof(int));
  printf("The memory block is now %zu bytes long.\n", sizeof(*pnew));

  puts("This is a puts() message");

  myFunc();

  char myString[] = "Hello World!";
  char mySubstring[] = "World";
  char* posFound = strstr(myString, mySubstring);
  if (posFound) {
    printf("Substring found at position: %ld\n", posFound - myString);
  } else {
    printf("Substring not found.\n");
  }

  int* p3 = malloc(5 * sizeof(int));
  if (p3) {
    memset(p3, 0, 5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
      printf("%d ", p3[i]);
    }
  }
  free(p3);

  char source[] = "Hello World";
  char destination[5];
  memcpy(destination, source, sizeof destination);
  printf("The source is: %s\n", source);
  printf("The destination after copying 5 characters is:\n");
  // write a character, on by one, using the putchar() function
  for (size_t i = 0; i < sizeof destination; i++) {
    putchar(destination[i]);
  }

  MyStruct source1, destination1;
  source1.c = 'a';
  source1.x = 123;
  source1.d = 456.789;
  memcpy(&destination1, &source1, sizeof(destination1));
  printf("The result after copying bytes from source to destination:\n");
  printf("Member destination.c has a value of: %c\n", destination1.c);
  printf("Member destination.x has a value of: %d\n", destination1.x);
  printf("Member destination.d has a value of: %f\n", destination1.d);

  int arr1[] = {10, 20, 30, 40, 50};
  int arr2[] = {10, 20, 25, 40, 50};
  int myResult = memcmp(arr1, arr2, 5 * sizeof(int));
  if (myResult == 0) {
    printf("The arrays values match.\n");
  } else {
    printf("%d, The arrays values do not match.\n", myResult);
  }

  char mystr[] = "Hello World!";
  char* pfound = memchr(mystr, 'W', strlen(mystr));
  if (pfound) {
    printf("Character/byte found at: %s\n", pfound);
  } else {
    printf("Character/byte not found: %s\n", pfound);
  }

  int xx = 123;
  char strbuffer[100];
  int nc = snprintf(strbuffer, sizeof strbuffer, "%d", xx);
  printf("The result is: %s\n", strbuffer);
  printf("The number of characters written is: %d\n", nc);

  static_assert(sizeof(short) == 2, "The size of short is not 2.\n");
  static_assert(sizeof(long) == 8, "The size of long is not 8.\n");

  int* p4 = aligned_alloc(512, 512 * sizeof *p4);
  printf("Allocated a 512-byte aligned memory block.\n");
  printf("The address is: %p\n", (void*)p4);

  char8_t arr8[] = "Our 8-bit wide characters here.\n";
  char16_t arr16[] = u"Our 16-bit wide characters here.\n";
  char32_t arr32[] = U"Our 32-bit wide characters here.\n";

  thrd_t mythreadid = thrd_current();
  printf("Main thread id: %lu\n", mythreadid);

  thrd_t mythread;
  // create a thread that executes a function code
  if (thrd_success != thrd_create(&mythread, dowork, "Hello from a thread!")) {
    printf("Could not create a thread.\n");
    return 1;
  }
  thrd_join(mythread, NULL);

  constexpr int xc = 123;
  constexpr unsigned uc = 456u;
  constexpr char cc[] = {"Hello."};
  printf("The value of xc is: %d\n", xc);
  printf("The value of uc is:%u\n", uc);
  printf("The value of cc is: %s\n", cc);

  constexpr int vl = 10;
  enum Rank { FIRST = vl, SECOND, THIRD };

  // binary integer constant
  int bic = 0b1010;
  printf("The value of the integer variable x is: %d\n", bic);

  int x1 = 100;         // decimal
  int x2 = 0x64;        // hexadecimal
  int x3 = 0144;        // octal
  int x4 = 0b01100100;  // binary
  printf("The value of the variable x1 is: %d\n", x1);
  printf("The value of the variable x2 is: %d\n", x2);
  printf("The value of the variable x8 is: %d\n", x3);
  printf("The value of the variable x4 is: %d\n", x4);

  bool condition = true;
  if (condition) {
    printf("The condition is true.\n");
  } else {
    printf("The condition is false.\n");
  }

  int* p5 = nullptr;
  double* p6 = nullptr;
  MyStruct* p7 = nullptr;
  printf("The value of the p5 pointer is: %p\n", (void*)p5);
  printf("The value of the p6 pointer is: %p\n", (void*)p6);
  printf("The value of the p7 pointer is: %p\n", (void*)p7);

  // empty initializer
  int empty = {};
  struct Class {
    int a;
    double b;
  } s = {};
  int arr3[4] = {};
  printf("The value of x is: %d\n", empty);
  printf("The value of s.a is: %d\n", s.a);
  printf("The value of s.b is: %lf\n", s.b);
  for (int i = 0; i < 4; i++) {
    printf("%d ", arr3[i]);
  }

  myoldfunction();
  printf("Using deprecated code.\n");

  const char* s3 = "This will be duplicated.";
  char* s4 = strdup(s3);
  printf("The result is: %s\n", s4);
  free(s4);

  const char source2[] = "Copy this until ~ is found.";
  char destination2[sizeof source2];
  const char stopchar = '~';
  void* p8 = memccpy(destination2, source2, stopchar, sizeof destination2);
  if (p8) {
    printf("Terminating character found. The result is:\n");
    printf("%s\n", destination2);
  } else {
    printf("Terminating character not found. The result is:\n");
    printf("%s\n", destination2);
  }

  char buff[100];
  printf("Please enter a string: ");
  fgets(buff, 100, stdin);
  printf("The result is: %s\n", buff);

  double dc;
  printf("%lf\n", dc);

  printf("Accesing shared constants from main.c:\n");
  printf("%d, %s, %lf\n", MY_MAX, MY_MESSAGE, MY_PI);
  printf("Accessing shared global variables from source.c:\n");
  printf("%d %lf\n", mysharedint, myshareddouble);
  myfunction();

  time_t mytime = time(nullptr);
  struct tm* now;
  now = localtime(&mytime);
  printf("Obtained and stored the current time.\n");
  char str[70];
  strftime(str, sizeof str, "%T %D", now);
  printf("The time is: %s\n", str);
  printf("Minutes and seconds: %d:%d\n", now->tm_min, now->tm_sec);

  printf("The number of bits in a byte: %d\n", CHAR_BIT);
  printf("The minimum value an int can store is: %d\n", INT_MIN);
  printf("The maximum value an int can store is: %d\n", INT_MAX);
  printf("The maxium value for a float is: %f\n", FLT_MAX);
}

void foo(char* arg) { printf("%s\n", arg); }
void myFunction() { printf("hello from %s\n", __func__); }
