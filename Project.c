#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct account{
	char name[40];
	char dob[11];
	char contact[15];
	char email[40];
	char city[15];
	char address[60];
	char CNIC[20];
	char password[8];
	char account_code[6] = "ACC-";
	int account_number = 1000;
	int balance;
};

void bankname();

int main()
{
	system("cls");
	bankname();
	int choice;
	printf("\n\n\t1.Create Account\n\n\t2.Login Account\n\n\t3.Exit");
	printf("\n\n\t--> ");
	scanf("%d",&choice);
	struct account user,user1;
	char filename[20],acc_num[20],pin[20],code[20],user_acc[20];
	char cont = 'y',logout,end,select;
	int opt,amt;
	FILE *ptr;
	
	switch(choice){
		case 1:{
			system("cls");
			bankname();
			FILE *file = fopen("Account Number Generator.txt","rb+");
			if(file==NULL){
				printf("\n\t\t\tSystem error occured!!!");
				return 1;
			}
		getchar();
		printf("\n\tEnter Your Name : ");
		gets(user.name);
		printf("\n\tEnter Your Date OF Birth (date-month-year) : ");
		gets(user.dob);
		printf("\n\tEnter Your Phone Number eg(+92XXX-XXXXXXX) : ");
		gets(user.contact);
		printf("\n\tEnter Your Email-ID : ");
		gets(user.email);
		printf("\n\tEnter Your City : ");
		gets(user.city);
		printf("\n\tEnter Your Residential Address : ");
		gets(user.address);
		printf("\n\tEnter Your CNIC Number eg(XXXXX-XXXXXXX-X) : ");
		gets(user.CNIC);
		pword:
		printf("\n\tEnter four digit PIN number for your Account : ");
		gets(user.password);
		if(strlen(user.password)!=4){
			printf("\n\tThe PIN must be of four digits");
			goto pword;
		}
		user.balance = 0;
		
		fread(&user.account_number,sizeof(user.account_number),1,file); 	//Read the value from file pointer
		user.account_number++;	//Increment the previous file pointer value
		fseek(file,0,SEEK_SET);		//Move the file pointer to the beginning
		fwrite(&user.account_number,sizeof(user.account_number),1,file); 	//Write the incremented value to the file pointer
		fclose(file);
		
		sprintf(filename,"%d",user.account_number);
		strcpy(code,user.account_code);
		strcat(code,filename);
		strcpy(filename,code);	
		ptr = fopen(strcat(filename,".bin"),"w");
		fwrite(&user,sizeof(struct account),1,ptr);
		if(fwrite!=0){
		printf("\n\n\tAccount successfully created");
		printf("\n\n\n\tYour Account Number is %s%d",user.account_code,user.account_number);
		printf("\n\tYour Account PIN is %s",user.password);
		getch();
	}	
		else{
		printf("\nSomething went wrong please try again");
		return 1;
	}
		fclose(ptr);	
			break;
		}

    getch();
    return 0;
}

void bankname(){
	printf("\t\t\t\t\t******SmartStream Bank******");
	printf("\n\t\t\t\t\t----------------------------");
}