
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define Number 100

//.......................................

// Δομή για την εμφάνιση αποτελεσμάτων

struct game
{
	int result;
	int moves;
	int duration;
}	;



//....................................

// Έλεγχος λήξης παιχνιδιού

int gameend(int ppos[][4])                                           
{
int i,j,end1,end2;
for	(i=1;i<=3;i++)                                              //Αναζήτηση τριάδας στις σειρές του πίνακα
{
	end1=0;
	end2=0;
	for (j=1;j<=3;j++)
	{
		if (ppos[i][j]==1)
		{
			end1=end1+1;
			if (end1==3)
			{
				printf("\n\nGame Over. You Won!\n\n");
				return 1;
			}
			
		}
		if (ppos[i][j]==2)
		{
			end2=end2+1;
			if (end2==3)
			{
				printf("\n\nGame Over. Computer Won!\n\n");
				return -1;
			}
			
		
		}
	}
}
for	(j=1;j<=3;j++)                                              //Αναζήτηση τριάδας στις στήλες του πίνακα
{
	end1=0;
	end2=0;
	for (i=1;i<=3;i++)
	{
		if (ppos[i][j]==1)
		{
			end1=end1+1;
			if (end1==3)
			{
				printf("\n\nGame Over. You Won!\n\n");
				return 1;
			}
			
		}
		if (ppos[i][j]==2)
		{
			end2=end2+1;
			if (end2==3)
			{
				printf("\n\nGame Over. Computer Won!\n\n");
				return -1;
			}
			
		
		}
	}
}                                                   
end1=0;
end2=0;
for (i=1;i<=3;i++)                                 //Αναζήτηση τριάδας διαγώνια ([1][1]->[3][3]) του πίνακα
{
	if(ppos[i][i]==1)
	{
		end1=end1+1;
		if (end1==3)
		{
			printf("\n\nGame Over. You Won!\n\n");
			return 1;
		}
	}
	if(ppos[i][i]==2)
	{
		end2=end2+1;
		if (end2==3)
		{
			printf("\n\nGame Over. Computer Won!\n\n");
			return -1;
		}
	}
}	
end1=0;
end2=0;
for (i=1;i<=3;i++)                                 //Αναζήτηση τριάδας διαγώνια ([1][3]->[3][1]) του πίνακα
{
	if(ppos[i][4-i]==1)
	{
		end1=end1+1;
		if (end1==3)
		{
			return 1;
			printf("\n\nGame Over. You Won!\n\n");
		}
	}
	if(ppos[i][4-i]==2)
	{
		end2=end2+1;
		if (end2==3)
		{
			printf("\n\nGame Over. Computer Won!\n\n");
			return -1;
		}
	}
}	
return 0;

}








//.............................................

//Γύρος του υπολογιστή

int ai(int ppos[][4], char pgame[][4],int *lpposx, int *lpposy)
{
int win,done,i,j,k;
done=0; 														//Αναζήτηση δύο συμβόλων του υπολογιστή και παίξιμο του τρίτου
for (i=1;i<=3;i++)                                              //Η μεταβλητη done δείχνει αν έχει πραγματοποιηθεί η κίνηση       
{                                                               //Αναζήτηση σε γραμμή
	if (done==1)
	{
		break;
	}
	win=0;
	for (j=1;j<=3;j++)
	{
		if (done==1)
		{
			break;
		}
	
	if (ppos[i][j]==2)
	{
		win=win+1;                                                         
		
		if (win==2)                                           //Αν βρεθούν δύο σύμβολα στην σειρά γίνετε αναζήτηση για την τρίτη κενή θέση ώστε να συμπληρωθεί
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[i][k]==0)	
				{
					ppos[i][k]=2;
					pgame[i][k]='O';
					*lpposx=i;                                // Οι lpposx lpposy συμβολίζουν την τελευταία κίνηση του υπολογιστή
					*lpposy=k;
					done=1;
					break;					
				}
			}		
		}
		
	}
	}	
}	
if (done==0)                                                         // Αναζήτηση σε στήλη
	{
	for (j=1;j<=3;j++)
	{
	if (done==1)
	{
		break;
	}
	win=0;
	for (i=1;i<=3;i++)
	{
		if (done==1)
		{
			break;
		}	
	if (ppos[i][j]==2)
	{
		win=win+1;		
		if (win==2)
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[k][j]==0)	
				{
					ppos[k][j]=2;                          
					pgame[k][j]='O';
					*lpposx=k;
					*lpposy=j;
					done=1;
					break;					
				}
			}		
		}
		
	}	
	
	}	
}	
	}

if (done==0)                                              // αναζήτηση διαγώνια ([1][1]->[3][3])
{
	win=0;
	for (i=1;i<=3;i++)
	{
		if (done==1)
		{
			break;
		}
	if (ppos[i][i]==2)
	{
		win=win+1;
		if (done==1)
		{
		break;
		}	
		if (win==2)
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[k][k]==0)	
				{
					ppos[k][k]=2;
					pgame[k][k]='O';
					*lpposx=k;
					*lpposy=k;
					done=1;
					break;					
				}
			}		
		}
	}	
	
	}	
}
if (done==0)                                             //αναζήτηση διαγώνια ([1][3]->[3][1])
{
	win=0;
	for (i=1;i<=3;i++)
	{
		if (done==1)
		{
			break;
		}
	if (ppos[i][4-i]==2)
	{
		win=win+1;	
		if (win==2)
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[k][4-k]==0)	
				{
					ppos[k][4-k]=2;
					pgame[k][4-k]='O';
					*lpposx=k;
					*lpposy=4-k;
					done=1;
					break;					
				}
			}		
		}
	}	
	
	}	
}
if (done==0)                                                     //Αναζήτηση δύο συμβόλων του παίκτη και αποτροπή ολοκλήρωσης τριάδας
{
 
 for (i=1;i<=3;i++)                                            			 // Αναζήτηση σε γραμμή                 
{
	if (done==1)
	{
		break;
	}
	win=0;
	for (j=1;j<=3;j++)
	{
	if (done==1)
	{
		break;
	}
	if (ppos[i][j]==1)
	{
		if (done==1)
		{
			break;
		}
		win=win+1;		
		if (win==2)
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[i][k]==0)	
				{
					ppos[i][k]=2;
					pgame[i][k]='O';
					*lpposx=i;
					*lpposy=k;
					done=1;
					break;					
				}
			}		
		}
		
	}	
	
	}	
}	
if (done==0)                                               			 //Αναζήτηση σε στήλη
	{
	for (j=1;j<=3;j++)
	{
	if (done==1)
	{
		break;
	}
	win=0;
	for (i=1;i<=3;i++)
	{
	if (ppos[i][j]==1)
	{
		win=win+1;		
		if (win==2)
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[k][j]==0)	
				{
					ppos[k][j]=2;
					pgame[k][j]='O';
					*lpposx=k;
					*lpposy=j;
					done=1;
					break;					
				}
			}		
		}
	}	
	
	}	
}	
	}

if (done==0)                                                 				 //Αναζήτηση διαγώνια ([1][1]->[3][3])
{
	win=0;
	for (i=1;i<=3;i++)
	{
	if (done==1)
	{
		break;
	}
	if (ppos[i][i]==1)
	{
		if (done==1)
	{
		break;
	}
		win=win+1	;	
		if (win==2)
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[k][k]==0)	
				{
					ppos[k][k]=2;
					pgame[k][k]='O';
					*lpposx=k;
					*lpposy=k;
					done=1;
					break;					
				}
			}		
		}

	}	
	
	}	
}
if (done==0)                                                          //αναζήτηση διαγώνια ([1][3]->[3][1])
{
	win=0;
	for (i=1;i<=3;i++)
	{
	if (done==1)
	{
		break;
	}
	if (ppos[i][4-i]==1)
	{
		win=win+1	;	
		if (win==2)
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[k][4-k]==0)	
				{
					ppos[k][4-k]=2;
					pgame[k][4-k]='O';
					*lpposx=k;
					*lpposy=4-k;
					done=1;
					break;					
				}
			}		
		}
	}	
	
	}
}
}

if (done==0)                                                                       // Επιλογή κεντρικού τετραγώνου
{
	if (ppos[2][2]==0)
	{
		ppos[2][2]=2;
		pgame[2][2]='O';
		*lpposx=2;
		*lpposy=2;
		done=1;
	}
}
if (done==0)                                     								// Δημιουργεία δυάδας
{
for(i=1;i<3;i++)
{
	if (done==1)
	{
		break;
	}
	for(j=1;j<3;j++)
	{
		if (ppos[i][j]==2 &&ppos[i+1][j+1]==0)
		{
			ppos[i+1][j+1]=2;
			pgame[i+1][j+1]='O';
			*lpposx=i+1;
			*lpposy=j+1;
			done=1;
			break;
		}
	}
	if(done==1)
	{
		break;
	}
}

for(j=1;j<3;j++)
{
	if (done==1)
	{
		break;
	}
	for(i=1;i<3;i++)
	{
		if (ppos[i][j]==2 &&ppos[i+1][j+1]==0)
		{
			ppos[i+1][j+1]=2;
			pgame[i+1][j+1]='O';
			*lpposx=i+1;
			*lpposy=j+1;
			done=1;
			break;
		}
	}
	if(done==1)
	{
		break;
	}
}
	
}   

if (done==0)                                                           // Επιλογή γωνιακού τετραγώνου
{
	if (ppos[1][1]==0)
	{
		ppos[1][1]=2;
		pgame[1][1]='O';
		*lpposx=1;
		*lpposy=1;
		done=1;
	}
	else if (ppos[3][3]==0)
	{
		ppos[3][3]=2;
		pgame[3][3]='O';
		*lpposx=3;
		*lpposy=3;
		done=1;
	}
	else if (ppos[3][1]==0)
	{
		ppos[3][1]=2;
		pgame[3][1]='O';
		*lpposx=3;
		*lpposy=1;
		done=1;
	}
	else if (ppos[1][3]==0)
	{
		ppos[1][3]=2;
		pgame[1][3]='O';
		*lpposx=1;
		*lpposy=3;
		done=1;
	}
}
if (done==0)                                      					 //Επιλογή τυχαίου τετραγώνου
{
	for (i=1;i<=3;i++)
	{
		if (done==1)
		{
			break;
		}
		for (j=1;j<=3;j++)
		{
			if (ppos[i][j]==0)
			{
				ppos[i][j]=2;
				pgame[i][j]='O';
				*lpposx=i;
				*lpposy=j;
				done=1;
			}
		}
	}
}
}


//...............................................................................

//Γύρος του παίκτη

int playerturn(int ppos[][4], char pgame[][4], int *lpposx, int *lpposy)                     
{
int x,y;
printf("Your turn.\n\n");
do
{                                                                                               //Οι εισαγωγές πραγματοποιούνται σε βρόγχο do{...}while για να αποφευχθουν οι λανθασμενες εισαγωγές
	
	printf("Input number of line\n\n");                                                         // Εισαγωγή αριθμού σειράς
	scanf("%d", &x);
	fflush(stdin);
	do
	{
		if(x<1||x>3)
		{
			printf("\n\aInput denied. Your line should be between numbers 1 and 3.\nReinput number of line.\n");
			scanf("%d", &x);
			fflush(stdin);
		}
	}while(x<1||x>3);
	printf("Input number of collumn\n\n");														// Εισαγωγή αριθμού στήλης
	scanf("%d", &y);
	fflush(stdin);
	do
	{
		if(y<1||y>3)
		{
			printf("\n\aInput denied. Your collumn should be between numbers 1 and 3.\nReinput number of collumn.\n");
			scanf("%d", &y);
			fflush(stdin);
		}
	}while(y<1||y>3);
	
if(!ppos[x][y]==0)
{
	printf("\aSpace is already occupied. Choose an another space.\n\n");
}	
}while(!ppos[x][y]==0);    
	
ppos[x][y]=1;                                                       // Ολοκληρωση της επιλογής του παίκτη
pgame[x][y]='X';
*lpposx=x;                                                      	//Οι μεταβλητές *lpposx *lpposy συμβολίζουν την τελευταία κίνήση του παίκτη
*lpposy=y;
}



//....................................................

// Οπτικοποίηση της Τριλιζας

int field(int ppos[][4], char pgame[][4])
{
system("cls");
printf("     |     |     \n  %c  |  %c  |  %c  \n-----|-----|-----\n  %c  |  %c  |  %c  \n-----|-----|-----\n  %c  |  %c  |  %c  \n     |     |     \n\n",
pgame[1][1],pgame[1][2],pgame[1][3],pgame[2][1],pgame[2][2],pgame[2][3],pgame[3][1],pgame[3][2],pgame[3][3]);  	
}



//...................................................

//Κυρίως Πρόγραμμα


main ()
{
char ans,game[4][4];
int play,pos[4][4],i,j,x,y,over,sumpl,sumg,first,lposx,lposy,ylposx,ylposy,ndraws,nwon,nlost,lostt,wont,minmoves,mindur,nmoves,nsec,minmovespos;
struct game score[Number];
wont=0;
lostt=0;
nmoves=0;
nsec=0;
ndraws=0;
nlost=0;
nwon=0;
sumg=0;
sumpl=0;
srand(time(NULL));                          							//Εκκινηση συνάρτησης τυχαίων αριθμών
time_t start = 0;                          
time_t end = 0;
time_t elapsed = 0;

do                                  	 							//Βασική επανάληψη
{
										
do
	{
	printf("New Game? y/n  \n");                      
	scanf("%c", &ans);
	fflush(stdin);
	if (ans=='n')
	{
		                                                         //Εμφάνιση στατιστικών στοιχείων
		if (sumg!=0)                                             //Απαραίτητη προϋπόθεση να παιχτεί ένα τουλάχιστον παιχνίδι 
		{
			for (i=1;i<=sumg;i++)
			{
				if (score[i].result==0)                          
				{
					printf("\nGame %d resulted in a draw.\n", i);
					ndraws=ndraws+1;
				}
				if (score[i].result==-1)
				{
					printf("\nComputer won game %d.\n",i);
					nlost=nlost+1;
					lostt=1;
					
				}	
				if (score[i].result==1)
				{
					printf("\nYou won game %d.\n",i);
					nwon=nwon+1;
					wont=1;
					
				}
				printf("Duration: %d seconds.\n",score[i].duration);                  //Εμφάνιση διάρκειας παιχνιδιού
				printf("Number of player's valid moves: %d.\n",score[i].moves);               //Εμφάνιση αριθμού κινήσεων του παίκτη
				nmoves=nmoves+score[i].moves;
				nsec=nsec+score[i].duration;
			}
				printf("\nYou won %d times, lost %d times and resulted in %d draws\n",nwon,nlost,ndraws);
				printf("\nAverage player's number of moves: %d\n",nmoves/sumg);               //Εμφάνιση μέσου όρου κινήσεων του παίκτη
				printf("\nAverage duration: %d seconds\n",nsec/sumg);
				if (wont==1)                                                        // Εύρεση καλύτερου παιχνιδιού
				{
					minmoves=10;
					minmovespos=0;
					mindur=999;
					for (i=1;i<=sumg;i++)
					{
						if (score[i].result==1)
						{						
							if (minmoves>=score[i].moves)                            
							{
								if (minmoves=score[i].moves)                         //Πρωτεύων κριτίριο ο αριθμός κινήσεων          
								{
									if (mindur>score[i].duration)                    // Επόμενο κριτίριο η διάρκεια παιχνιδιού
									{
										minmoves=score[i].moves;
										minmovespos=i;
										mindur=score[i].duration;
									}
								}
								if (minmoves>score[i].moves)
								{							
									minmoves=score[i].moves;
									minmovespos=i;
									mindur=score[i].duration;
								}
							}
						}
					}
				printf("\nYour best game was game %d. You won with %d moves in %d seconds\n",minmovespos,minmoves,mindur);
				}
				if (lostt==1)                                                                 //Εύρεση χείριστου παιχνιδιού. Ακολουθείται η ίδια λογική
				{
					minmoves=10;
					minmovespos=0;
					mindur=999;				
					for (i=1;i<=sumg;i++)
					{
						if (score[i].result==-1)
						{
							if (minmoves>=score[i].moves)
							{
								if (minmoves=score[i].moves)
								{
									if (mindur>score[i].duration)
									{
										minmoves=score[i].moves;
										minmovespos=i;
										mindur=score[i].duration;
									}
									if (minmoves>score[i].moves)
									{
										minmoves=score[i].moves;
										minmovespos=i;
										mindur=score[i].duration;
									}
								}
						
							}
						}
					}
				printf("\nYour worst game was game %d. You lost with %d moves in %d seconds\n",minmovespos,minmoves, mindur);
				}
							
							
			
			
			system("pause") ;                                                        
			exit(1);
		}
		exit(1);
	}
	if(ans=='y')
	{
		play=1;
		start = time(NULL);  									//Αρχή χρονομέτρησης
		sumg=sumg+1;
		sumpl=0;
		if (sumg>=Number)
		{
			printf("Memory is full. Game will now exit");
			system("pause");
			exit(2);
		}
	}
	}while(ans!='y'&&ans!='n');	
	
	
	
	
	for(i=0;i<=3;i++)               		 					//Καθαρισμός Τριλιζας/Πινακα
	{
		for (j=0;j<=3;j++)
		{
			pos[i][j]=0;
			game[i][j]=' ';
		}
	}
	over=0;
										
field (pos,game);
first=rand();

if (first%2==0)                                                    //Ο Παίκτης παίζει πρώτος
{
	for (i=1;i<=5;i++)
	{
		playerturn(pos,game,&ylposx,&ylposy);
		field (pos,game);
		over=gameend(pos);
		sumpl=sumpl+1;
		if (over!=0)
		{
			break;
		}
		ai (pos,game,&lposx,&lposy);
		field (pos,game);
		printf("\nYour last choice: (row, col): X (%d,%d)\n", ylposx,ylposy);
		printf("\nComputer last choice: (row, col): O (%d,%d)\n\n", lposx,lposy);
		over=gameend(pos);
		if (over!=0)
		{
			break;
		}
	}
}
if (first%2==1)                                      						//Ο Υπολογιστής παίζει πρώτος
{
	for (i=1;i<=5;i++)
	{
		ai (pos,game,&lposx,&lposy);
		field (pos,game);
		if (i>1)
		{
			printf("\nYour last choice: (row, col): X (%d,%d)\n", ylposx,ylposy);
		}
		printf("\nComputer last choice: (row, col): O (%d,%d)\n\n", lposx,lposy);
		over=gameend(pos);
		if (over!=0||i==5)
		{
			break;
		}
		playerturn(pos,game,&ylposx,&ylposy);
		field (pos,game);
		over=gameend(pos);
		sumpl=sumpl+1;
		if (over!=0)
		{
			break;
		}

	}
}
if (over==0)
{
	printf("Draw!\n\n");
}
score[sumg].result=over;                                            //Εισαγωγή δεδομένων στη δομή
score[sumg].moves=sumpl;

end = time(NULL);  
elapsed = end - start; 
score[sumg].duration=elapsed ;

}while(play=1);	

}








	
	
	
	
	
	
	
	
	
	
	

