
						
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
				
					