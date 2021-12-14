#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[], char**envp2)
{  
   // 'islem cikar x y'   için sayilari 'x-y' şeklinde çıkartıp döndürüyor döndürüyor.
   int x=atoi(argv[2]);
   int y=atoi(argv[3]);
   int sonuc=x-y;
   return sonuc;
}
