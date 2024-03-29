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
		case 2:{
			getchar();
			login:
			system("cls");
			bankname();	
		printf("\n\n\tEnter Account Number : ");
		gets(acc_num);
		printf("\n\tEnter Account PIN : ");
		gets(pin);
		strcpy(filename,acc_num);
		ptr = fopen(strcat(filename,".bin"),"rb"); 	
		if(ptr==NULL){
			printf("\n\n\t\tACCOUNT NOT FOUND!");
			printf("\n\n\t\tPress e to go back");
			printf("\n\n\t\tPress any other key to try again");
			select = getch();
			if(select == 'e' || select == 'E')
			main();
			else
			goto login;
		}
		
		else{
			fread(&user,sizeof(struct account),1,ptr);
			fclose(ptr);
			if(strcmp(pin,user.password) == 0)
			break;
				
			else{
				printf("\n\n\t\tIncorrect Password");
				printf("\n\n\t\tPress e to go back");
				printf("\n\n\t\tPress any other key to try again");
				select = getch();
				if(select == 'e' || select == 'E')
				main();
				else
				goto login;
		
				}
		}	
			
			break;
		}
		case 3:{
			exit(0);
			break;
		}
		default:{
			printf("\n\n\t\tInvalid Selection");
			getch();
			system("cls");
			main();
			break;
		}
	}
		
		while(cont == 'y' || cont == 'Y'){
					loop:
					system("cls");
					bankname();
					printf("\n\n\t1.View balance\n\n\t2.Deposit money\n\n\t3.Withdraw money\n\n\t4.Money transfer\n\n\t5.Change PIN number\n\n\t6.Account Profile\n\n\t7.Log Out\n\n\t8.exit");
					printf("\n\n\t--> ");
					scanf("%d",&opt);
					
					switch(opt){
						case 1:{
							system("cls");
							bankname();
							printf("\n\n\tYour current balance is Rs.%d",user.balance);
							break;
						}
						case 2:{
							system("cls");
							bankname();
							printf("\n\n\tEnter amount to deposit : ");
							scanf("%d",&amt);
							user.balance += amt;
							ptr = fopen(filename,"w");
							fwrite(&user,sizeof(struct account),1,ptr);
							if(fwrite != NULL)
							printf("\n\n\tRS.%d Successfully deposited",amt);
							else
							printf("\n\n\t\tError in depositing money");
							fclose(ptr);
							break;
						}
						case 3:{
							system("cls");
							bankname();
							printf("\n\n\tEnter amount to withdraw : ");
							scanf("%d",&amt);
							if(amt>user.balance)
							printf("\n\n\tInsufficient amount in your account to be withdrawn");	
							else{
							ptr = fopen(filename,"w");
							user.balance -= amt;	
							fwrite(&user,sizeof(struct account),1,ptr);
							fclose(ptr);
							if(fwrite != NULL)
							printf("\n\n\tYou have withdrawn RS.%d",amt);
							else
							printf("\n\n\t\tError in depositing money");
							
						}
							break;
						}
					case 4:{
						system("cls");
						bankname();
						getchar();
						printf("\n\n\tEnter the account number where you want to tranfer money : ");
						gets(acc_num);
						strcpy(user_acc,user.account_code);
						sprintf(code,"%d",user.account_number);
						strcat(user_acc,code);
						if(strcmp(acc_num,user_acc) == 0){
						printf("\n\n\tCannot tranfer money to your account from your account");
						break;
					}
						printf("\n\tEnter the amount to tranfer : ");
						scanf("%d",&amt);
						ptr = fopen(strcat(acc_num,".bin"),"rb");
						if(ptr==NULL)
							printf("\n\n\n\t\tACCOUNT NOT FOUND!!!");
						else{
							fread(&user1,sizeof(struct account),1,ptr);
							fclose(ptr);
							if(amt > user.balance)
								printf("\n\n\n\t\tInsufficient balance in your account to transfer");
							
							else{
								ptr = fopen(acc_num,"w");
								user1.balance += amt;
								fwrite(&user1,sizeof(struct account),1,ptr);
								fclose(ptr);
								
								if(fwrite != 0){
									printf("\n\n\tRs.%d successfully tranfered to account %s%d",amt,user1.account_code,user1.account_number);
									ptr = fopen(filename,"w");
									user.balance -= amt;
									fwrite(&user,sizeof(struct account),1,ptr);
									fclose(ptr);
								}
								else{
									printf("\n\n\n\t\tError in tranferring money");
								}
							}	
						}
						break;
					}
					case 5:{
						pinchange:
						system("cls");
						bankname();
						getchar();
						printf("\n\n\tEnter current PIN number : ");
						gets(pin);
						ptr = fopen(filename,"r");
						if(ptr==NULL){
							printf("\n\n\n\t\tAn error occurred");
							break;
						}
						fclose(ptr);
						if(strcmp(user.password,pin) == 0){
							printf("\n\tEnter new PIN number : ");
							gets(pin);
							if(strlen(pin)!=4){
							printf("The PIN must be of four digits");
							goto pinchange;
					}
							ptr = fopen(filename,"w");
							strcpy(user.password,pin);
							fwrite(&user,sizeof(struct account),1,ptr);
							fclose(ptr);
							if(fwrite != NULL)
							printf("\n\n\t\tPIN successfully changed");
							else
							printf("\n\n\n\t\tError in changing PIN\n\t\tTry again");
						}
						else
						printf("\n\n\t\tWrong PIN entered");
						
						break;
					}
					case 6:{
						system("cls");
						bankname();
						ptr = fopen(filename,"r");
						if(ptr==NULL){
							printf("\n\n\t\tERROR IN ACCESSING ACCOUNT");
							break;	
						}
						fread(&user,sizeof(struct account),1,ptr);
						printf("\n\n\tAccount Number : %s%d",user.account_code,user.account_number);
						printf("\n\n\tName : %s",user.name);
						printf("\n\n\tCNIC Number : %s",user.CNIC);
						printf("\n\n\tDate of Birth : %s",user.dob);
						printf("\n\n\tContact Number : %s",user.contact);
						printf("\n\n\tEmail ID : %s",user.email);
						printf("\n\n\tCity : %s",user.city);
						printf("\n\n\tAddress : %s",user.address);
						break;
					}	
					case 7:{
						system("cls");
						bankname();
						getchar();
						printf("\n\n\t\tAre you sure you want to log out of this account?[y/n] : ");
						scanf("%c",&logout);
						if(logout == 'y' || logout == 'Y'){
						system("cls");
						main();
					}
						else
						goto loop;

						break;
					}
					case 8:{
						system("cls");
						bankname();
						getchar();
						printf("\n\n\t\tAre you sure you want to exit?[y/n] : ");
						scanf("%c",&end);
						if(end == 'y' || end == 'Y')
						exit(0);
						else
						goto loop;
						
						break;
					}
					default:{
						printf("\n\nInvalid option!");
						getch();
						goto loop;
						break;
					}
					}
					printf("\n\n\n\tDo you want to continue to transaction[y/n] : ");
					cont = getche();
			}	
	
	getch();
	return 0;
}

void bankname(){
	printf("\t\t\t\t\t******SmartStream Bank******");
	printf("\n\t\t\t\t\t----------------------------");
}