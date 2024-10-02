#include <stdio.h>
#include <string.h>
struct user
{
    char pass[255];
    char user[255];
};
int main()
{
    FILE *fptr = fopen("C:\\1st-Year-Pacaman-C-Package\\Passwords.txt","r");
    if(fptr==NULL)
    {
        fputs("Error opening the file!",stderr);
    }
    struct user u1;
    char pass[255],user[255];
    l1: printf("\nEnter the username:\n");
    fgets(user,30,stdin);
    printf("\nEnter the password:\n");
    fgets(pass,20,stdin);
    while(fread(&u1,sizeof(u1),1,fptr))
    {
        if(strcmp(pass,u1.pass)==0 && strcmp(user,u1.user))
        {
            printf("Successful Login\n");
        }
        else
        {
            printf("Incorrect Username or Password\nPlease enter the correct credentials\n");
        }
    }
    return 0;
}