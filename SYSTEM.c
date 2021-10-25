
/*-----------------------------
* Version: C99                *
* Project: Library Managemen System*
* Author:  Latipa Mudaki       *
* Date:    June,2021          *
* License: MIT                *
******************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
//adding name:
//name
//id
//contact
//is_staff


struct user{
	char name[100];
	int id;
	char tel[13];
	int is_staff;
};




//Function prototype
void execute_action(int action);
void close();
int menu();
void add_user();


int main()
{


    int action;

   while(1) {

   		action = menu();
  		 execute_action(action);
   		printf("press any key to continue");
   		getchar();
   		getch();
  		system("cls");
}

       return 0;
}

void execute_action(int action) {
    switch(action) {
   case 1:
       add_user();
       break;
   case 2:
      printf("Adding a book");
      break;
   case 3:
    printf("Existing/n");
    close();
 default:
         printf("unknown action.\n");
  }
}

void close() {
    printf("Thank you for using the system\n");
    printf("bye\n");
    Sleep(5000);
    exit(0);
}

int menu() {
     // Navigation menu
     int action;
do {
     printf("\tCounty Library Management System!\n");
     printf("Welcome Latipa\n");
        printf("1. Add user\n");
        printf("2. Add Book\n");
        printf("3. Exit\n");
        printf("Select action(1-3): ");
        scanf("%d",&action);
        // validate input
        if (action < 1 || action > 3)
            printf("Invalid action. Try again\n");
            Sleep(2000);
            system("cls");


            {

            }
    } while(action < 1 || action > 3);

return 0;
}

void add_user(){



	struct user u;
	FILE *fp;
	if((fp =fopen("user","ab"))==NULL) {printf("cannot open file./n");
	exit(1);
	}


	printf("name:");
	getchar();
	gets(u.name);
	printf("ID number:");
	scanf("%d", &u.id);
	printf("phone number:");
	scanf("%d",&u.tel);
	printf("user type(1 for staff, 0 for ordinary user:");
	scanf("%d", &u.is_staff);
	fwrite(&u, sizeof(struct user), 1,fp);
	fclose(fp);
	printf("user successfully added\n");
}













