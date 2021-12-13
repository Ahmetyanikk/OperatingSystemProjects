#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem");
            break;
         }
 }
 return number;
}

int main(int argc, char *argv[], char**envp2)
{  
   // 'islem cikar x y'   için sayilari 'x-y' şeklinde çıkartıp döndürüyor döndürüyor.
   int x=strtoint(argv[2]);
   int y=strtoint(argv[3]);
   int sonuc=x-y;
   return sonuc;
}
