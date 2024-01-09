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