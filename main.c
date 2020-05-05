#include "main.h"

char user[20];
char pass[20];
char massage[100];

int main()
{
    FILE *userDa = fopen("Signup.txt", "r");
    int choice;
    home();
    scanf("%d", &choice);
    if (userDa != NULL)
    {
        
         if(choice == 1){
            //  intersignup();
             login();
         }
        else if(choice == 2)
        {
            //    void intersignupbe();
               signup();
        }
        else if(choice == 3){
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
        interlogin(user);
        while(1){
            printf("Username: ");
            scanf("%s", user);
            interlogin(user);
            printf("Password: ");
            scanf("%s", pass);
            if (strcmp(user, "3") == 0){
                main();
            }
            if(checktaken(user, "user") == 0 && checktaken(pass, "pass") == 0){
                break;
            }
            home();
            printf("Invalid Username or password Please try agaian\n");
         }
         chosseoption(user);
}
void signup(){
        FILE *signData = fopen("Signup.txt", "a");
        intersignup();
        while(1){
        printf("Input Username: \n");
        scanf("%s", user);
        if (strcmp(user, "3") == 0){
                main();
            }
        if (checktaken(user, "user") != 0 && checkpunct(user) != 0){
            break;
        }
        intersignupbe();
        printf("Please create username witout punct\n");
        }
        printf("Input password: \n");
        scanf("%s", pass);
        fprintf(signData, "%s\n", user);
        fprintf(signData, "%s\n", pass);
        fclose(signData);
        intersignup();
        login();
}
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
int checkpunct(char user[20]){
    char c;
    int n = 1;
    for(int i =0;i<strlen(user);i++){
        c = user[i];
        if(ispunct(c)){
            printf("Username has punct\n");
            n = 0;
            break;
        }
    }
    return n;
}
void chosseoption(char user[]){
    interchossetype();
    int n;
    scanf("%d", &n);
    if (n == 1){
        chosseMatrix(user);
    }
    else if (n == 2){
        startcharactorcircle();
    }
    else if (n == 3){
        main();
    }
}

void chosseMatrix(char user[]){
    int n;
    interchossedeoren();
    scanf("%d", &n);
    if (n == 1){
        encrypt(user);
    }
    else if(n == 2){
        findcode();
    }
}
