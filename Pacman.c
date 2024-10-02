#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Height 20 
#define Width 70
#define MAX_PASS 20
#define MAX_USER 30
struct user
{
    char pass[MAX_PASS];
    char user[MAX_USER];
    int score;
};
int map()
{
    int i,j;
   char map1[Height][Width];
   for(i=0;i<Height;i++)
   {
       for(j=0;j<Width;j++)
       {
           if(i==0 || j==0 || i==Height-1 || j==Width-1)
           {
               map1[i][j]='#';
           }
           else
           {
               map1[i][j]=' ';
           }
       }
   }
}
void displayMessage()
{
    //To display welcome message
    FILE *fptr = fopen("C:\\1st-Year-Pacaman-C-Package\\Welcome + Rules & Guides.txt","r");
    char buffer[255];
    if(fptr==NULL)
    {
        printf("Unable to open the file\n");
    }
    while(fgets(buffer,255,fptr)!=NULL)
    {
        printf("%s\n",buffer);
    }
    fclose(fptr);
    //To display the leaderboard
    FILE *f1ptr = fopen("C:\\1st-Year-Pacaman-C-Package\\Passwords.txt","r");
    struct user u1;
    printf("\nLEADERBOARD:\n");
    printf("USERNAME\tSCORE\n");
    while(fread(&u1,sizeof(u1),1,fptr))
    {
        printf("%s\n",u1.user);
    }
}
void SignUp()
{
    FILE *fptr = fopen("C:\\1st-Year-Pacaman-C-Package\\Passwords.txt","a");
    if(fptr==NULL)
    {
        fputs("Error cannot open the file\n",stderr);
        exit(1);
    }
    struct user u1;
    char pass[30];
    printf("\nEnter the username:\n");
    fgets(u1.user,30,stdin);
    l1: printf("\nEnter the password:\n");
    fgets(u1.pass,20,stdin);
    fwrite(&u1,sizeof(u1),1,fptr);
    fclose(fptr);
    printf("\nSuccessful Signup!\n\nWelcome %s\n\nEnjoy the game!\n",u1.user);
}
void LogIn()
{
    FILE *fptr = fopen("C:\\1st-Year-Pacaman-C-Package\\Passwords.txt","r");
    if(fptr==NULL)
    {
        fputs("Error cannot open the file\n",stderr);
        exit(1);
    }
    struct user u1;
    char pass[20],user[30];
    l1: printf("\nEnter the username:\n");
    fgets(user,30,stdin);
    printf("\nEnter the password:\n");
    fgets(pass,20,stdin);
    while(fread(&u1,sizeof(u1),1,fptr))
    {
        if(strcmp(pass,u1.pass)!=0 || strcmp(user,u1.user)!=0)
        {
            printf("Wrong credentials");
            fclose(fptr);
            return;
        }
    }
    fwrite(&u1,sizeof(user),1,fptr);
    fclose(fptr);
    printf("Signed in successfully!\n");
}
int main()
{
    int no_players,diff,neworold;
    l1: printf("\nEnter '1' if new user & '0' if existing user:\n");
    scanf("%d",&neworold);
    getchar();
    if(neworold == 1)
    {
        SignUp();
    }
    else if(neworold == 0)
    {
        LogIn();
    }
    else
    {
        printf("Invalid Input, Enter again:\n");
        goto l1;
    }
    return 0;    
}