#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{  
   int count =atoi(argv[2]);
   for(int i=0;i<count;i++){
   printf("%s\n",argv[1]);
   } 
   return 0;
}
