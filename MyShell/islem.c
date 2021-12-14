#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char**envp2)
{  

     int sonuc=0;
        int t;
      int f= fork();
      if(f==0)
      {

      //Alınan parametreyi kontrol ediyorum
      if( strcmp(argv[1],"topla")==0|strcmp(argv[1],"cikar")==0){
       t = execve(argv[1],argv,envp2);
       perror("exec: execve failed\n");	
                 }
      else{
          return NULL;
      }
         
      }
      else
      {
          int cpid = wait(&t); // forku bekletiyorum   .    
          sonuc = WEXITSTATUS(t);
          // değeri geri döndürüyorum
      }

   return sonuc;
}
