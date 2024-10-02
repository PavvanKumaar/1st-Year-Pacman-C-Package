#include <stdio.h>
#include <string.h>
int main()
{
    char Username[255],Password[255];
    printf("Enter the Username:");
    l1: scanf("%[^\n]s",Username);
    if(strlen(Username)>255)
    {
        printf("Invalid Username, Enter a username of length lesser than 255:\n");
        goto l1;
    }
    else if(strlen(Username)<1)
    {
        printf("Invalid Username, Enter a Username of length greater than 1:\n");
        goto l1;
    }
    //Username
    FILE *uptr = fopen("C:\\1st-Year-Pacaman-C-Package\\Usernames.txt","a");
    fprintf(uptr,Username);
    fclose(uptr);
    //Passwords
    printf("Enter the password");
    l2: scanf("%[^\n]s",Password);
    if(strlen(Username)>128)
    {
        printf("Invalid Password, Enter a username of length lesser than 128:\n");
        goto l2;
    }
    else if(strlen(Username)<1)
    {
        printf("Invalid Password, Enter a Username of length greater than 6:\n");
        goto l2;
    }
    FILE *pptr = fopen("C:\\1st-Year-Pacaman-C-Package\\Password.txt","a");
    fprintf(pptr,Password);
    fclose(pptr);
    return 0;
}