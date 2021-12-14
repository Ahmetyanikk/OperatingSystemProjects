#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char komutlarim[5][10]={
                    "tekrar","islem","bash","cat","clear"
};
char input[250];
char temp[250];
int control=0;
int cokMuKontrol=0;
int parametreHesapla(char input[]){
    strcpy(temp,input);
    int girisAdet=0;
    char * parca=strtok(temp," ");
    while(parca!=NULL){
    parca=strtok(NULL," ");
    girisAdet++;
    }
    return girisAdet;
}
int anaProgram(char input[]){
    strcpy(temp,input);
    int komut=0;
    char * parca=strtok(temp," ");
    int i=0;
  while(i<4){
   if(strcmp(parca,komutlarim[i])==0){
       control++;
       komut=i;
       break;
   }
   i=i+1;


  }
  if(control!=0){
          // komut var ise komutun id'sine göre fonksiyon çağırıyoruz.
      if(komut==0){
      tekrarCalis(input);
      }else if(komut==1){
      islemCalis(input);
      }else if(komut==2){
      bashCalis(input);
      }else if(komut==3){
      catCalis(input);
      }
      else if(komut==4){
      clearCalis();}


  }else{
  printf("Komut Bulunamadi!!!\n");
  }
  return 0;
  }
int tekrarCalis(char input[]){
    int girisAdet=parametreHesapla(input);
    if(girisAdet==3){
        char *parametreler[4];
        girisAdet=0;
        char * parca=strtok(temp," ");
        while(parca!=NULL){
        parca=strtok(NULL," ");
        parametreler[girisAdet]=parca;
        girisAdet++;
        }
        int t;
        int f;
        f= fork();
        if(f==0)
             {
                // printf("Ana program: Exec calisti\n");
                 t = execve("tekrar",parametreler);
                 perror("exec: execve failed\n");
             }
             else
             {
                 int cpid = wait(&t);
        //fork beklemesi oluyor
        }


    }
    else{
        printf("Parametre Hatasi\n");
    }
return 0;

}
int islemCalis(char input[]){
    int girisAdet=parametreHesapla(input);
    if(girisAdet==4){
        char *parametreler[5];
        girisAdet=0;
        char * parca=strtok(temp," ");
        while(parca!=NULL){
        parca=strtok(NULL," ");
        parametreler[girisAdet]=parca;
        girisAdet++;
        }
        int t;
        int f;
        f= fork();
              if(f==0)
              {
                  t = execve("islem",parametreler);
                  perror("exec: execve failed\n");
              }
              else
              {
                  int cpid = wait(&t); }
    }
    else{
        printf("Parametre Hatasi\n");

    }
    return 0;
}
int bashCalis(char input[]){
    char input2[250];

    strcpy(temp,input);
    char * parca=strtok(temp," ");
    while(strcmp(parca,"exit")==0){
        printf("bash>>");
        gets(input2);
        int girisAdet=parametreHesapla(input);
        char *parametreler[5];
        girisAdet=0;
        char * parca=strtok(temp," ");
        while(parca!=NULL){
        parca=strtok(NULL," ");
        parametreler[girisAdet]=parca;
        girisAdet++;
        }
        int t;
        int f;
        f= fork();
              if(f==0)
              {
                  t = execve("/bin/bash",parametreler);
                  perror("exec: execve failed\n");
              }
              else
              {
                  int cpid = wait(&t); }
    }

        printf("cikis yapiliyor");
        //burda shell'e geri dönüş yaparken problem yaşadım

return 0;
}
int catCalis(char input[]){
    strcpy(temp,input);

    char *parametreler[3];
    int i=0;
    char * parca=strtok(temp," ");
    while(parca!=NULL){
    parametreler[i]=parca;
    i++;
    parca=strtok(NULL," ");
    }
    parametreler[2]=NULL;
    int t;
    int f;
    f= fork();
          if(f==0)
          {
              t = execve("/bin/cat",parametreler);
              perror("exec: execve failed\n");
          }
          else
          {
              int cpid = wait(&t);
          }

    return 0;

}
int clearCalis(){
char *parametreler[2];
parametreler[0]="clear";
parametreler[1]=NULL;
     int t;
     int f;
      f= fork();
      if(f==0)
      {
          t = execve("/bin/clear",parametreler);
          perror("exec: execve failed\n");
      }
      else
      {
          int cpid = wait(&t);
      }
      return 0;
}

int main(){
while(1){
control=0;
cokMuKontrol=0;
printf("myshell>> ");
gets(input);

// birden fazla fonksiyon girilmiş mi diye '|' karakterini inputun içinde aratıyorum
for(int i=0;i<strlen(input);i++){
 if(input[i]=='|'){
     cokMuKontrol++;
 }
}
if(cokMuKontrol!=0){
    //çoklu fonksiyon girilmişse burda devam ediyoruz
    strcpy(temp,input);
    char * Eparca=strtok(temp," ");
    if(strcmp(Eparca,"exit")==0){
        printf("shell kapaniyor");
        break;
    }
    char *cokluKomutlar[10];
    int count=0;
     char * parca=strtok(temp,"|");
            while(parca!=NULL){
            cokluKomutlar[count]=parca;
            count++;
            parca=strtok(NULL,"|");
            }
            for (int i=0;i<count ;i++ ) {
               anaProgram(cokluKomutlar[i]);
            }
}
else{
    // Tek fonksiyon girildiyse burda devam ediyoruz
    strcpy(temp,input);
    char * Eparca=strtok(temp," ");
    if(strcmp(Eparca,"exit")==0){
        printf("shell kapaniyor");
        break;
    }
anaProgram(input);
}
}
return 0;
    
}
