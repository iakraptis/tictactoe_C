
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define Number 100

//.......................................

// Structure for the end game statistics 

struct game
{
	int result;
	int moves;
	int duration;
}	;



//....................................

// Game ending check

int gameend(int ppos[][4])                                           
{
int i,j,end1,end2;
for	(i=1;i<=3;i++)                                              //search the rows
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
for	(j=1;j<=3;j++)                                              //Collumn search
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
for (i=1;i<=3;i++)                                 //Search main diagonal ([1][1]->[3][3]) 
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
for (i=1;i<=3;i++)                                 //Search the secondary diagonal ([1][3]->[3][1]) 
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

//AI turn

int ai(int ppos[][4], char pgame[][4],int *lpposx, int *lpposy)
{
int win,done,i,j,k;
done=0; 														//Search for two symbols and play a third one
for (i=1;i<=3;i++)                                              //Done is used to show if the move has been played       
{                                                               //Row Search
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
		
		if (win==2)                                           //If there are two symbols, check and play the third one
		{
			for (k=1;k<=3;k++)
			{
				if (ppos[i][k]==0)	
				{
					ppos[i][k]=2;
					pgame[i][k]='O';
					*lpposx=i;                                //  lpposx lpposy: Coordinates of the latest AI move
					*lpposy=k;
					done=1;
					break;					
				}
			}		
		}
		
	}
	}	
}	
if (done==0)                                                         // Collumn Search
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

if (done==0)                                              // Diagonal search ([1][1]->[3][3])
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
if (done==0)                                             //Diagonal search ([1][3]->[3][1])
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
if (done==0)                                                     //Search two symbol of the rival player and block his triplet
{
 
 for (i=1;i<=3;i++)                                            			 // Row Search                 
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
if (done==0)                                               			 //Collumn Search
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

if (done==0)                                                 				 //Diagonal Search ([1][1]->[3][3])
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
if (done==0)                                                          //Diagonal Search ([1][3]->[3][1])
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

if (done==0)                                                                       // choose the center
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
if (done==0)                                     								// Create two of a kind
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

if (done==0)                                                           // Choose one of the edges
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
if (done==0)                                      					 //pick a random place
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

//Player's Turn

int playerturn(int ppos[][4], char pgame[][4], int *lpposx, int *lpposy)                     
{
int x,y;
printf("Your turn.\n\n");
do
{                                                                                               //Use Do...while to ensure correct scanfs
	
	printf("Input number of line\n\n");                                                         // Input row number
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
	printf("Input number of collumn\n\n");														// Input collumn number
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
	
ppos[x][y]=1;                                                       // Finish player's selection
pgame[x][y]='X';
*lpposx=x;                                                      	// *lpposx *lpposy : these are the player's last position
*lpposy=y;
}



//....................................................

// Visualize the Board

int field(int ppos[][4], char pgame[][4])
{
system("cls");
printf("     |     |     \n  %c  |  %c  |  %c  \n-----|-----|-----\n  %c  |  %c  |  %c  \n-----|-----|-----\n  %c  |  %c  |  %c  \n     |     |     \n\n",
pgame[1][1],pgame[1][2],pgame[1][3],pgame[2][1],pgame[2][2],pgame[2][3],pgame[3][1],pgame[3][2],pgame[3][3]);  	
}



//...................................................

//Main


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
srand(time(NULL));                          							// Initialize Random number generator 
time_t start = 0;                          
time_t end = 0;
time_t elapsed = 0;

do                                  	 							//Main
{
										
do
	{
	printf("New Game? y/n  \n");                      
	scanf("%c", &ans);
	fflush(stdin);
	if (ans=='n')
	{
		                                                         //Visualize statistics
		if (sumg!=0)                                             //Needs at least one played game
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
				printf("Duration: %d seconds.\n",score[i].duration);                  //Show game's duration
				printf("Number of player's valid moves: %d.\n",score[i].moves);               //Show number of players moves
				nmoves=nmoves+score[i].moves;
				nsec=nsec+score[i].duration;
			}
				printf("\nYou won %d times, lost %d times and resulted in %d draws\n",nwon,nlost,ndraws);
				printf("\nAverage player's number of moves: %d\n",nmoves/sumg);               //show average number of player moves
				printf("\nAverage duration: %d seconds\n",nsec/sumg);
				if (wont==1)                                                        // Find best game
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
								if (minmoves=score[i].moves)                         //First criteria is number of moves          
								{
									if (mindur>score[i].duration)                    // Second criteria is time
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
				if (lostt==1)                                                                 //Find the worst game
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
		start = time(NULL);  									//start timing
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
	
	
	
	
	for(i=0;i<=3;i++)               		 					//Clear the game state
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

if (first%2==0)                                                    //Player plays first
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
if (first%2==1)                                      						//AI plays first
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
score[sumg].result=over;                                            //Insert data to structure
score[sumg].moves=sumpl;

end = time(NULL);  
elapsed = end - start; 
score[sumg].duration=elapsed ;

}while(play=1);	

}








	
	
	
	
	
	
	
	
	
	
	

