#include "stdio.h"
#include "string.h"
#include "ctype.h"

/* Menu*/
void menu(){
    printf("1 login\n2 sign up\n3 exit\n");
}
/* While Username and password is correct */
int login(char user[20], char pass[20]);
/**/
int usertaken(char check[60][20], int count, char user[20], char checktype[3]);
/* Get data from database */
int getDataUser(char user[20], char check[3]);
/**/
/*Main function*/
int main()
{
    FILE *userDa = fopen("Signup.db", "a");
    char user[20];
    char pass[20];
    int choice;
    menu();
    scanf("%d", &choice);
    if (userDa != NULL)
    {
        
         if(choice == 1){
             do{
            printf("Username: ");
            scanf("%s", user);
            printf("\nPassword: ");
            scanf("%s", pass);
         
         }while(getDataUser(user, "lo") != 0 && getDataUser(pass, "lo") != 0);
            login(user, pass);
         }
    
        else if(choice == 2)
        {
            do{
                printf("Input Username: \n");
                scanf("%s", user);
                }while (getDataUser(user, "si") == 0);
                printf("Input password: \n");
                scanf("%s", pass);
                fprintf(userDa, "%s?", user);
                fprintf(userDa, "%s\n", pass);
                main();
            
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
int login(char user[20], char pass[20]){
    printf("Success");
    main();
}
int getDataUser(char user[20], char check[3]){
    FILE *gdata = fopen("Signup.db", "r");
    int c, ind = 0, ans = 1, po = 0,  count=0;
    char data[20];
    char lis[60][20];
    char blank[20] = "";
    while ((c = fgetc(gdata)) != EOF)
    {
        if (c == 63){
            strcpy(lis[po], data);
            strcpy(data, blank);
            ind = 0;
            po++;
            count++;
        }
        else{
            data[ind] = c;
            ind++;
        }
    }
    ans = usertaken(lis, count, user, check);
    
    return ans;
}
int usertaken(char lis[60][20], int count, char user[20], char check[3]){
    int ans;
    for(int i = 0;i < count;i++){
        ans = strcmp(lis[i], user);
        if (ans == 0 && check == "si"){
            printf("Please try agian\nThis username is already taken.\n");
            break;
        }
        else{
            break;
        }
    }
    return ans;
}