#include <stdio.h>
#define Height 20 
#define Width 70
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

}
void inputUserPass()
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
    fprintf("%s\n",Username);
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
    fprintf("%s\n",Password);
    fclose(pptr);
}
int main()
{
    int no_players,diff;
    return 0;

}

