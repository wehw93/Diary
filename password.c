#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>
void Password(bool *ispass){
     FILE * file;
     file = fopen("Password.txt", "rb");
     if (!file){
          fclose(file);
          FILE * password_txt;
          password_txt = fopen("Password.txt", "w");
          printf("Password unfouded\nCreate new passrod: ");
          char * password = malloc(100*sizeof(char));
          scanf("%s", password);
          for (size_t i = 0; i < sizeof(password); i++){
               putc(password[i], password_txt);
          }    
          fclose(password_txt);
          *ispass=true;         
     }
     else {
          printf("Password:");
          char buffer[100];
          size_t scan = fread(buffer,sizeof(char), 100, file);
          char * pass2= malloc(100*sizeof(char));
          scanf("%s", pass2);
          if (!strcmp(buffer, pass2)){
               *ispass = true;
               
          }

     }
}
