#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>

void add_customer();
void show_customer();
void edit_customer();
void delete_customer();
void search_customer();

struct Customer_Infos
{
	char room_number[15];
	char name[25];
	char address[30];
	char phone_number[20];
	char nationality[20];	
	char email[25];
	char period[15];
	char arrival_date[20];
}s;
void login()
{
    char username[15]; 
    char password[15];
    char username1[15]="hotel";
    char password1[15]="123";
    
	system("cls");
	
    printf("\n Please Enter Your Username: ");
	scanf("%s", &username); 
	printf("\n Please Enter Your Password: ");
	scanf("%s",&password);
	 
	if(strcmp(username,username1)==0 && strcmp(password,password1)==0)
	{
	printf("\n      Welcome! Successfully Logged!");
	
	printf("\n\n      Press Any Key to Continue to Main Menu!");
	
	getch();
	}
	else
	{
		printf("\n      Sorry! Unsuccessful Login!");
		
		getch();
		
		exit(0);
	}
}
int main()
{	
	char customer_name;
	char option;

	system("cls");
	
	printf("\n");
	printf(" ###################################################################################################\n");
	printf(" ##                                                                                               ##\n");
	printf(" ##  #   # ##### ##### ##### #       ##### ####  #     # # #   #   ##### ##### #   # ##### #      ##\n");
	printf(" ##  #   # #   #   #   #     #       #   # #   # ##   ##   ##  #   #   # #   # ##  # #     #      ##\n");
	printf(" ##  ##### #   #   #   ###   #       ##### #   # # # # # # # # #   ##### ##### # # # ###   #      ##\n");
	printf(" ##  #   # #   #   #   #     #       #   # #   # #  #  # # #  ##   #     #   # #  ## #     #      ##\n");
	printf(" ##  #   # #####   #   ##### #####   #   # ####  #     # # #   #   #     #   # #   # ##### #####  ##\n");
	printf(" ##                                                                                               ##\n");
	printf(" ###################################################################################################\n");
	
/*
    printf("########################################################################################################################################################################################################### \n");
	printf("##                                                                                                                                                                                                       ## \n");
	printf("##   ##      ##  ##########  ##########  ##########  ##           ###         ###  ##########  ###       ##  ##########  ##########  ##########  ###         ###  ##########  ###       ##  ##########   ## \n");
	printf("##   ##      ##  ##      ##      ##      ##          ##           ## ##     ## ##  ##      ##  ## ##     ##  ##      ##  ##          ##          ## ##     ## ##  ##          ## ##     ##      ##       ## \n");
	printf("##   ##      ##  ##      ##      ##      ##          ##           ##  ##   ##  ##  ##      ##  ##  ##    ##  ##      ##  ##          ##          ##  ##   ##  ##  ##          ##  ##    ##      ##       ## \n");
	printf("##   ##########  ##      ##      ##      ######      ##           ##   ## ##   ##  ##########  ##   ##   ##  ##########  ##  ######  ######      ##   ## ##   ##  ######      ##   ##   ##      ##       ## \n");
	printf("##   ##      ##  ##      ##      ##      ##          ##           ##    ###    ##  ##      ##  ##    ##  ##  ##      ##  ##      ##  ##          ##    ###    ##  ##          ##    ##  ##      ##       ## \n");
	printf("##   ##      ##  ##      ##      ##      ##          ##           ##           ##  ##      ##  ##     ## ##  ##      ##  ##      ##  ##          ##           ##  ##          ##     ## ##      ##       ## \n");
	printf("##   ##      ##  ##########      ##      ##########  ##########   ##           ##  ##      ##  ##       ###  ##      ##  ##########  ##########  ##           ##  ##########  ##       ###      ##       ## \n");
	printf("##                                                                                                                                                                                                       ## \n");
	printf("########################################################################################################################################################################################################### \n");
*/
	printf("\n								        Brought to You by.Enis&Eren!");
	printf("\n\n Welcome To The Hotel 'XXXXX'!");
	printf("\n Press Any Key to Continue!");
	
	getch();
	
    system("cls");
    
    login();
    
    system("cls");
    
	while (1)
	{
		system("cls");

		printf("\n        <===> MAIN MENU <==>\n");
		printf("\n Press 1 ==> Book a Room!");
		printf("\n Press 2 ==> View Customer Records!");
		printf("\n Press 3 ==> Delete a Record!");
		printf("\n Press 4 ==> Search a Record!");
		printf("\n Press 5 ==> Edit a Record!");
		printf("\n Press 6 ==> Exit the Program!");
		
		option=getche();
		
		switch(option)
		{	
			case '1':
				add_customer();
				
				break;
				
			case '2':
				show_customer();
				
				break;
				
			case '3':
				delete_customer();
				
				break;
				
			case '4':
				search_customer();
				
				break;
				
			case '5':
				edit_customer();
				
				break;
				
			case '6':
				system("cls");
				
				printf("\n\t Thanks For Trusting Our Service!");

				exit(0);
				
				break;
				
			default:
				system("cls");
				
				printf("\n Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}
void add_customer()
{
	FILE *fp;
	
	char esc;
	
	fp=fopen("booking.txt","a+");
	
	while(1)
	{
		system("cls");
		
		printf("\n Enter Room Number: ");
		scanf("%s",s.room_number);
		fflush(stdin);
		printf("\n Enter Name: ");
		scanf("%s",s.name);
		printf("\n Enter Adress: ");
		scanf("%s",s.address);
		printf("\n Enter Phone Number: ");
		scanf("%s",s.phone_number);
		printf("\n Enter Nationality: ");
		scanf("%s",s.nationality);
		printf("\n Enter Email: ");
		scanf(" %s",s.email);
		printf("\n Enter Period(\'x\'days): ");
		scanf("%s",&s.period);
		printf("\n Enter Arrival Date(DD/MM/YYYY): ");
		scanf("%s",&s.arrival_date);
		
		fwrite(&s,sizeof(s),1,fp);
		fflush(stdin);
		
		printf("\n\n Room is successfully booked!");
		printf("\n\n Press 'ESC' Key to Exit or Any Other Key to Add Another Customer Detail!");
		
		esc=getche();
		
		if(esc==27)
		{
			break;
		}
	}
	fclose(fp);
}
void show_customer()
{
	FILE *fp;
	
	if((fp=fopen("booking.txt","r"))==NULL)
	{
		exit(0);
	}
	system("cls");
	
	printf("\n <ROOM>   ");
	printf("<NAME>      ");
	printf("<ADRESS>      ");
	printf("<PHONE NUMBER>      ");
	printf("<NATIONALITY>      ");
	printf("<EMAIL>         ");
	printf("<PERIOD>      ");
	printf("<ARRIVAL DATE> ");
	
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		printf("\n\n %s   ",s.room_number);
		printf("%s      ",s.name);
		printf("%s      ",s.address);
		printf("%s      ",s.phone_number);
		printf("%s      ",s.nationality);
		printf("%s   ",s.email);
		printf("%s            ",s.period);
		printf("%s",s.arrival_date);
	}
	fclose(fp);
	
	getch();
}
void delete_customer()
{
	FILE *fp,*tp;
	
	int a=1;
	char room_number[20];
	
	if((tp=fopen("delete.txt","w"))==NULL)
	{
		exit(0);
	}
	if((fp=fopen("booking.txt","r"))==NULL)
	{
		exit(0);
	}
	system("cls");
	
	printf("\n Enter a Room Number to Delete: ");
	fflush(stdin);
	scanf("%s",room_number);
	
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		if(strcmp(s.room_number,room_number)==0)
		{       
			a=0;
			
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,tp);
	}
	if(a==1)
	{       
		printf("\n\n Record Doesn't Exist!");
		printf("\n\n Press Any Key to Go Back To Main Menu!");
		
		getch();
		
		fclose(tp);
		fclose(fp);
	}
	else
	{
	fclose(fp);
	fclose(tp);
	
	remove("booking.txt");
	rename("delete.txt","booking.txt");
	
	printf("\n\n Customer is Successfully Removed!");
	printf("\n\n Press Any Key to Go Back To Main Menu!");
	
	fclose(fp);
	fclose(tp);
	
	getch();
	}
}
void search_customer()
{
	system("cls");
	
	FILE *fp;
	
	char room_number[20];
	int flag=1;
	
	fp=fopen("booking.txt","r+");
	
	if(fp==0)
	{
		exit(0);
	}
	fflush(stdin);
	printf("\n Enter a Room Number to Have Access to Details of Customer: ");
	scanf("%s", room_number);
	
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		if(strcmp(s.room_number,room_number)==0)
		{
			flag=0;
			
			printf("\n\t <Record Found> \n");
			printf("\n Room Number : %s",s.room_number);
			printf("\n Name        : %s",s.name);
			printf("\n Address     : %s",s.address);
			printf("\n Phone Number: %s",s.phone_number);
			printf("\n Nationality : %s",s.nationality);
			printf("\n Email       : %s",s.email);
			printf("\n Period:     : %s",s.period);
			printf("\n Arrival Date: %s",s.arrival_date);
			printf("\n\n Press Any Key to Go Back To Main Menu!");
			
			flag=0;
			
			break;
		}
	}
	if(flag==1)
	{	
		printf("\n Requested Customer Could not be Found!");
		printf("\n\n Press Any Key to Go Back To Main Menu!");
	}
	getch();
	
	fclose(fp);
}
void edit_customer()
{
	FILE *fp;
	
	int k=1;
	char room_number[20];
	
	long int size=sizeof(s);
	
	if((fp=fopen("booking.txt","r+"))==NULL)
	{
		exit(0);
	}
	system("cls");
	
	printf("\n Enter Room Number to Edit a Customer: ");
	scanf("%[^\n]",room_number);
	fflush(stdin);
	
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		if(strcmp(s.room_number,room_number)==0)
		{
			k=0;
			
			printf("\n Enter Room Number : ");
			gets(s.room_number);
			printf("\n Enter Name        : ");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\n Enter address     : ");
			scanf("%s",&s.address);
			printf("\n Enter Phone number: ");
			scanf("%f",&s.phone_number);
			printf("\n Enter Nationality :");
			scanf("%s",&s.nationality);
			printf("\n Enter Email       : ");
			scanf("%s",&s.email);
			printf("\n Enter Period      : ");
			scanf("%s",&s.period);
			printf("\n Enter Arrival date: ");
			scanf("%s",&s.arrival_date);
			
			fseek(fp,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,fp);
			
			break;
		}
	}
	if(k==1)
	{
		printf("\n\n Record Doesn't Exist!");
		fclose(fp);
		
		getch();
	}
	else
	{
		fclose(fp);
		printf("\n\n Record is Successfully Edited!");
		printf("\n\n Press Any Key to Go Back To Main Menu!");
	
		getch();
}
}
