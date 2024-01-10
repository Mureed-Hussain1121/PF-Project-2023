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
			printf("\n\n\t\tPress e to go back ...");
			printf("\n\n\t\tPress any other key to try again ...");
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
				printf("\n\n\t\tIncorrect Password !!!");
				printf("\n\n\t\tPress e to go back...");
				printf("\n\n\t\tPress any other key to try again !!!");
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
			printf("\n\n\t\tInvalid Selection !!");
			getch();
			system("cls");
			main();
			break;
		}
	}
