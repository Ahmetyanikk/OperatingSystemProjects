#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[], char**envp2)
{  
   // 'islem topla x y'   için 'x+y' sayilarini toplayıp döndürüyor.
   int x=atoi(argv[2]);
   int y=atoi(argv[3]);
   int sonuc=x+y;
   return sonuc;
}
