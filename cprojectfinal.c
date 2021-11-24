/*Phonebook management system
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[35];
    long int mobile_no;
    char sex[6];
    char email[100];
    char citizenship_no[20];
	};

void menu();//This function is used to display the main menu.
void got();//This function is used to display details.
void start();//This functions calls the menu function mentioned above.
void back();//This function is used to go back to start.
void addrecord();// It adds a new Phonebook record.
void listrecord();//This function is used to view list of added records in file.
void modifyrecord();//This function is used to modify added records.
void deleterecord();// It deletes record from file.
void searchrecord();// It searches for added record by name.
int main()//main function started
{
  char username[20]; // for username
  char userpwd[8]; // for storing password 
  int i; 
   
  printf("Enter your username : "); 
  scanf("%s",username); 
  printf("Enter your password : "); 
  for(i=0;i<8;i++) 
  { 
   userpwd[i]=getch(); 
   printf("*");   	 
  } 
  userpwd[i]='\0';  
  getch(); 
 if(!strcmp(username,"admin") && !strcmp(userpwd,"12345678")) 
 { 
  printf("\n\nLogged In Successful"); 
  
 
  menu();
  
  
 }else 
 { 
  printf("\n\nIncorrect username or password"); 
 } 

	
    return 0;
}

void back()//This function is used to go back to start.
{
    start();
}
void start()//This functions calls the menu function mentioned above.
{
    menu();
}
void menu()//This function is used to display the main menu.
{
    system("cls");
//printf("\n*****************************************************************************");
//printf("\n************************   WELCOME TO PHONEBOOK By Shishir And NETRA  ***************************");
//printf("\n*****************************************************************************");
//printf("\n\n**********************************   MENU   *********************************\n\n");
printf("\n1) Add New Record\n2) View List\n3) Modify \n4) Search\n5) Delete\n6) Exit");

switch(getch())
{
    case '1':
	addrecord();
    break;
   case '2': 
   listrecord();
    break;
    case '3': 
	modifyrecord();
    break;
    case '4':
    searchrecord();
	break;
    case '5':
    deleterecord();
    break;
    case '6':
    exit(0);
    break;
    default:
	system("cls");
    printf("\nEnter your choice : ");
    printf("\n Enter from 1 to 6 ");
    getch();
	menu();
}
}
        void addrecord()//this function is used to add a new phone book record
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        printf("\nEnter Name: ");
        got(p.name);
        printf("\nEnter Address: ");
        got(p.address);
        printf("\nEnter Father Name: ");
        got(p.father_name);
        printf("\nEnter Mother Name: ");
        got(p.mother_name);
        printf("\nEnter Phone Number: ");
        scanf("%ld",&p.mobile_no);
        printf("Enter Gender: ");
        got(p.sex);
        printf("\nEnter E-Mail: ");
         got(p.email);
        printf("\nEnter Citizenship Number: ");
        got(p.citizenship_no);
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        printf("\nRecord Saved !!");

fclose(f);

    printf("\n\nEnter Any Key");

	 getch();
    system("cls");
    menu();
}
void listrecord()//This function is used to view list of added records in file.
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nFile Opening Error In Listing :");

exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
    printf("\n\n\n YOUR RECORD IS\n\n ");
	printf("\nName : %s",p.name);
	printf("\naddress : %s",p.address);
	printf("\nFather name : %s",p.father_name);
	printf("\nMother name : %s",p.mother_name);
	printf("\nMobile number : %ld",p.mobile_no);
	printf("\nGender : %s",p.sex);
	printf("\nE-Mail : %s",p.email);
	printf("\nCitizenship number : %s",p.citizenship_no);
	getch();
	system("cls");
}
fclose(f);
 printf("\nEnter Any Key");
 getch();
    system("cls");
menu();
}
void searchrecord()//this function is used to searches for added record by name.
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\nError In Opening\a\a\a\a");
    exit(1);

}
printf("\nEnter Name of the Person to Search\n");
got(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
		printf("\nName : %s",p.name);
		printf("\nAddress : %s",p.address);
		printf("\nFather name : %s",p.father_name);
		printf("\nMother name : %s",p.mother_name);
		printf("\nMobile number : %ld",p.mobile_no);
		printf("\nGender : %s",p.sex);
		printf("\nE-Mail : %s",p.email);
		printf("\nCitizenship number : %s",p.citizenship_no);
	}
        else
        printf("Error ! File Not Found !!");

}
 fclose(f);
  printf("\nEnter Any Key");

	 getch();
    system("cls");
menu();
}
void deleterecord()//this function is used to deletes record from file.
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("\nUSERS DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("File Opening Error");
		else

        {


		printf("\nEnter USERS NAME: ");
		got(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{
		printf("\nNO CONACT'S RECORD TO DELETE.");
		remove("temp.txt");
	}
		else
		{
			remove("project");
			rename("temp.txt","project");
			printf("\nRECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\nEnter Any Key");

	 getch();
    system("cls");
menu();
}
void modifyrecord()//This function is used to modify added records.
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("\nCONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\nEnter Name: ");
                    got(s.name);
                    printf("\nEnter Address: ");
                    got(s.address);
                    printf("\nEnter Father Name: ");
                    got(s.father_name);
                    printf("\nEnter Mother Name: ");
                    got(s.mother_name);
                    printf("\nEnter Phone Number: ");
                    scanf("%ld",&s.mobile_no);
                    printf("Enter Gender: ");
                    got(s.sex);
                    printf("\nEnter E-Mail: ");
                    got(s.email);
                    printf("\nEnter Citizenship Number: ");
                    got(s.citizenship_no);
                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;
				}
                fflush(stdin);
			}
            if(flag==1)
            {
                printf("\nYour Data is Modified");

            }
            else
            {
                    printf(" \nData Not Found");

            }
            fclose(f);
	}
	 printf("\nEnter Any Key");
	 getch();
    system("cls");
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
