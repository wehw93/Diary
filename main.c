#include"funcs.h"
int main(void){
    bool ispass = false;
    int choice;
    printf("Hello, what are you want?\n1 - Write records\n2 - Exit\nYour choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        do
    {
        Password(&ispass);
        if (ispass){
            printf("Correct password\n");
            input();
            break;
        }
        else{  
            printf("Invalid password, try again!\n");
        }
    } while (!ispass);
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}