#include "stdio.h"
#include "string.h"
#include "ctype.h"


char user[20];
char pass[20];

struct data{
    char username[20];
    char pass[20];
}dat[30];
int checktaken(char user[20], char key[5]){
    FILE *gdata = fopen("Signup.txt", "r");
    int c, ind = 0, ansuser = 1, po = 2,  count=0;
    char data[20];
    char blank[20] = "";
    while ((fgets(data, 20, gdata)) != NULL)
    {
        if (po%2 == 0){
            strcpy(dat[ind].username, data);
            po++;
        }
        else{
            strcpy(dat[ind].pass, data);
            ind++;
            po++;
        }
        count++;
    }
    if (key == "user"){
    for(int i =0;i<= count;i++){
        ansuser = strcmp(user, dat[i].username)+10;
        if (ansuser == 0){
            break;
            }
        }
    }
    if(key == "pass"){
        for(int i =0;i<= count;i++){
        ansuser = strcmp(user, dat[i].pass)+10;
        if (ansuser == 0){
            break;
            }
        }
    }
    return ansuser;
}
void menu(){
    printf("1 login\n2 sign up\n3 exit\n");
}
int login();
void signup(){
        FILE *signData = fopen("Signup.txt", "a");
        printf("Input Username: \n");
        scanf("%s", user);
        printf("Input password: \n");
        scanf("%s", pass);
        fprintf(signData, "%s\n", user);
        fprintf(signData, "%s\n", pass);
        fclose(signData);
        login();
}
int main()
{
    FILE *userDa = fopen("Signup.txt", "r");
    int choice;
    menu();
    scanf("%d", &choice);
    if (userDa != NULL)
    {
        
         if(choice == 1){
             login();
         }
        else if(choice == 2)
        {
               signup();
        }
        else{
            printf("Programs is closing");
        }
    
    }
    else
    {
        printf("Could open file");
    }
    
    fclose(userDa);
}
int login(){

    do{
            printf("Username: ");
            scanf("%s", user);
            printf("Password: ");
            scanf("%s", pass);
         }while(checktaken(user, "user") != 0 && checktaken(pass, "pass") != 0);
         printf("end");
}