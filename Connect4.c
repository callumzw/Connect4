
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10
void menu();
void printBoard(char *board, int rows,int columns);
void newGame();
void loadGame();
void instructions();
void customGame();
void opposition(int winThreshold);
void botLevel(int winThreshold);
void play(char *board, int rows, int columns, int winThreshold);
void playBotEasy(char *board, int rows, int columns, int winThreshold);
void playBotMedium(char *board, int rows, int columns, int winThreshold);
void playBotHard(char *board, int rows, int columns, int winThreshold);
int takeTurn(char *board, int player,int row, int columns);
int checkWin(char* board, int rows, int columns , int winThreshold);
int checkFour(char *board, int, int, int, int);
int horizontalCheck(char *board, int rows, int columns , int winThreshold);
int horizontalCheck(char *board, int rows, int columns , int winThreshold);
int verticalCheck(char *board, int rows, int columns, int winThreshold);
int diagonalCheck(char *board, int rows, int columns, int winThreshold);
int i =0;
int choice;
bool invalidInput;
int winThreshold;
void printNewGame();
void printCustomColumns();
void printCustomWin();
void printCustomRows();
const char *PIECES = "XO";
char player_one[20];
char player_two[20];
char board6x7[SIX * SEVEN];
char board6x8[SIX * EIGHT];
char board6x9[SIX * NINE];
char board6x10[SIX * TEN];
char board7x7[SEVEN * SEVEN];
char board7x8[SEVEN * EIGHT];
char board7x9[SEVEN * NINE];
char board7x10[SEVEN * TEN];
char board8x7[EIGHT * SEVEN];
char board8x8[EIGHT * EIGHT];
char board8x9[EIGHT * NINE];
char board8x10[EIGHT * TEN];
char board9x7[NINE * SEVEN];
char board9x8[NINE * EIGHT];
char board9x9[NINE * NINE];
char board9x10[NINE * TEN];


int main(int argc, char *argv[]){
	
	menu();
	
	return 0;
	
}
void printMenu(){
	system("cls");
	for(i=0;i<5;i++)printf("\n");
	printf("		         Connect 4");
	for(i=0;i<2;i++)printf("\n");	
	printf("		..........................\n"
			"		| 1         Play         |\n"
           "		..........................\n"
           "		| 2     Instructions     |\n"
           "		..........................\n "
		    "		| 0         Exit         |\n"
           "		..........................\n"
           "\n\n");
}
void menu()
{
	system("COLOR 0A");
	invalidInput = true;
	bool i =0;
	while (invalidInput){
	printMenu();
	if (i > 0){
	printf("Invalid Option, Try Again\n");
	}
	scanf("%d",&choice);	//GET THE USER CHOOSE
    switch(choice){
        case 1: newGame(); invalidInput=false; break;
        case 2: instructions(); invalidInput=false; break;
		case 0: invalidInput=false; break;
        default: i=1; break;
		}
	}
}
void printNewGame(){
	system("cls");
	for(i=0;i<5;i++)printf("\n");
	printf("		      Type of Board?");              		
	for(i=0;i<2;i++)printf("\n");
	printf("		..........................\n"
			"		| 1     Standard (6x7)   | \n"                
           "		.......................... \n"              
           "		| 2    5-in-a-row (6x9)  |  \n"
           "		..........................\n"
           "		| 3      Custom (?x?)    | \n"
           "		..........................\n"
		   "		| 0        Back          | \n"
           "		..........................\n"
           "\n\n");
}
void newGame(){
	printNewGame();
	invalidInput = true;
	bool i =0;
	while (invalidInput){
	printNewGame();
	if (i > 0){
	printf("Invalid Option, Try Again\n");
	}
	scanf("%d",&choice);                                                        // GET THE USER CHOOSE
    switch(choice){
        case 1: opposition(4); invalidInput=false; break;
        case 2: opposition(5); invalidInput=false; break;
        case 3: customGame(); invalidInput=false; break;
		case 0: invalidInput=false; break;
        default:i=1; break;
		}
	}


   menu();   
	
	
}
void printOpposition() {
	system("cls");
	for (i = 0; i < 5; i++)printf("\n");
	printf("		      Opponent type?");
	for (i = 0; i < 2; i++)printf("\n");
	printf("		..........................\n"
		"		| 1       2 Player       |\n"
		"		..........................\n"
		"		| 2       Computer       |\n"
		"		..........................\n"
		"		| 0         Back         |\n"
		"		..........................\n"
		"\n\n");
}
void opposition(winThreshold) {
	printOpposition();
	invalidInput = true;
	bool i = 0;
	while (invalidInput) {
		printOpposition();
		if (i > 0) {
			printf("Invalid Option, Try Again\n");
		}
		scanf("%d", &choice);
		if (winThreshold = 4) {
			switch (choice) {
			case 1: play(board6x7, SIX, SEVEN, 4); invalidInput = false; break;
			case 2: botLevel(4); invalidInput = false; break;
			case 0: newGame(); invalidInput = false; break;
			default:i = 1; break;
			}
		}
		else {
			switch (choice) {
			case 1: play(board6x9, SIX, NINE, 5); invalidInput = false; break;
			case 2: botLevel(5);; invalidInput = false; break;
			case 0: newGame(); invalidInput = false; break;
			default:i = 1; break;
			}
		}
	}
}
void printBotLevel(winThreshold) {
	system("cls");
	for (i = 0; i < 5; i++)printf("\n");
	printf("		      Opponent type?");
	for (i = 0; i < 2; i++)printf("\n");
	printf("		..........................\n"
		"		| 1         Easy          |\n"
		"		..........................\n"
		"		| 2        Medium         |\n"
		"		..........................\n"
		"		| 3         Hard          |\n"
		"		..........................\n"
		"		| 0         Back          |\n"
		"		..........................\n"
		"\n\n");
}
void botLevel(winThreshold) {
		printBotLevel();
		invalidInput = true;
		bool i = 0;
		while (invalidInput) {
			printBotLevel();
			if (i > 0) {
				printf("Invalid Option, Try Again\n");
			}
			scanf("%d", &choice);
			if (winThreshold = 4) {
				switch (choice) {
				case 1: playBotEasy(board6x9, SIX, SEVEN, 4); invalidInput = false; break;
				case 2: playBotMedium(board6x9, SIX, SEVEN, 4); invalidInput = false; break;
				case 3: playBotHard(board6x9, SIX, SEVEN, 4); invalidInput = false; break;
				case 0: opposition(4); invalidInput = false; break;
				default:i = 1; break;
				}
			}
			else {
				switch (choice) {
				case 1: playBotEasy(board6x9, SIX, NINE, 5); invalidInput = false; break;
				case 2: playBotMedium(board6x9, SIX, NINE, 5); invalidInput = false; break;
				case 3: playBotHard(board6x9, SIX, NINE, 5); invalidInput = false; break;
				case 0: opposition(5); invalidInput = false; break;
				default:i = 1; break;
				}
			}
		}
	}

void printCustomColumns(){
	system("cls");
		for(i=0;i<5;i++)printf("\n");
	printf("		      No. of Columns?");              		
	for(i=0;i<2;i++)printf("\n");
	printf("		..........................\n"
			"		|            7           |\n"                
            "		..........................\n"              
            "		|            8           |\n"
            "		..........................\n"
            "		|            9           |\n"
            "		..........................\n"
			"		|           10           |\n"                
            "		..........................\n"
           "\n\n");
}
void printCustomRows(){
	system("cls");
		for(i=0;i<5;i++)printf("\n");
	printf("		       No. of Rows?");              		
	for(i=0;i<2;i++)printf("\n");
	printf("		..........................\n"
			"		|            6           |\n"                
            "		..........................\n"              
            "		|            7           |\n"
            "		..........................\n"
            "		|            8           |\n"
            "		..........................\n"
		 	"		|            9           |\n"                
            "		..........................\n"
           "\n\n");
}
void printCustomWin(){
	system("cls");
		for(i=0;i<5;i++)printf("\n");
	printf("		       Win Threshold?");              		
	for(i=0;i<2;i++)printf("\n");
	printf("		..........................\n"
			"		|            4           |\n"                
           "		..........................\n"              
           "		|            5           |\n"
           "		..........................\n"
           "\n\n");
}

void customGame(){
	int columns;
	int rows;
	int botLevel;
	// Get Number of Columns
	printCustomColumns();
	scanf("%d",&choice);
	if (choice >= 7 && choice <= 10){columns = choice;}
    else{printCustomColumns(); printf("Invalid Option, Try Again\n"); scanf("%d",&choice);}
		
	// Get Number of Rows
	printCustomRows();
	scanf("%d",&choice);
	if (choice >= 6 && choice <= 9){rows = choice;}
    else{printCustomRows(); printf("Invalid Option, Try Again\n"); scanf("%d",&choice);}
	
	// If Custom board allows,Get 4 Or 5 connected to win
	if (columns > 8)
	{
		printCustomWin();
		scanf("%d",&choice);
		if (choice == 4 || choice == 5){winThreshold = choice;}
		else{printCustomWin(); printf("Invalid Option, Try Again\n"); scanf("%d",&choice);}
	}
	else{
		winThreshold = 4;
	}
	
	// Play Custom Board
	switch(columns){
        case 7: 
		switch(rows){
			case 6: play(board6x7,rows,columns, winThreshold); break;
			case 7:  play(board7x7,rows,columns, winThreshold); break;
			case 8:  play(board8x7,rows,columns, winThreshold); break;
			case 9:  play(board9x7,rows,columns, winThreshold); break;
			}  
		break;
        case 8:
		switch(rows){
			case 6: play(board6x8,rows,columns, winThreshold); break;
			case 7:  play(board7x8,rows,columns, winThreshold); break;
			case 8:  play(board8x8,rows,columns, winThreshold); break;
			case 9:  play(board9x8,rows,columns, winThreshold); break;
			}		
		break;
        case 9: 
		switch(rows){
			case 6: play(board6x9,rows,columns, winThreshold); break;
			case 7:  play(board7x9,rows,columns, winThreshold); break;
			case 8:  play(board8x9,rows,columns, winThreshold); break;
			case 9:  play(board9x9,rows,columns, winThreshold); break;
			}
		break;
		case 10:
		switch(rows){
			case 6: play(board6x10,rows,columns, winThreshold); break;
			case 7:  play(board7x10,rows,columns, winThreshold); break;
			case 8:  play(board8x10,rows,columns, winThreshold); break;
			case 9:  play(board9x10,rows,columns, winThreshold); break;
			}
		break;
		} 
}
void customGameBot(){
	int columns;
	int rows;
	int botLevel;
	// Get Number of Columns
	printCustomColumns();
	scanf("%d",&choice);
	if (choice >= 7 && choice <= 10){columns = choice;}
    else{printCustomColumns(); printf("Invalid Option, Try Again\n"); scanf("%d",&choice);}

	// Get Number of Rows
	printCustomRows();
	scanf("%d",&choice);
	if (choice >= 6 && choice <= 9){rows = choice;}
    else{printCustomRows(); printf("Invalid Option, Try Again\n"); scanf("%d",&choice);}

	// If Custom board allows,Get 4 Or 5 connected to win
	if (columns > 8)
	{
		printCustomWin();
		scanf("%d",&choice);
		if (choice == 4 || choice == 5){winThreshold = choice;}
		else{printCustomWin(); printf("Invalid Option, Try Again\n"); scanf("%d",&choice);}
	}
	else{
		winThreshold = 4;
	}
	system("cls");
    	for (i = 0; i < 5; i++)printf("\n");
    	printf("		      Opponent type?");
    	for (i = 0; i < 2; i++)printf("\n");
    	printf("		..........................\n"
    		"		| 1         Easy          |\n"
    		"		..........................\n"
    		"		| 2        Medium         |\n"
    		"		..........................\n"
    		"		| 3         Hard          |\n"
    		"		..........................\n"
    		"\n\n");
    		scanf("%d",&choice);
            		if (choice == 1 || choice == 3){botLevel = choice;}
            		else{printCustomWin(); printf("Invalid Option, Try Again\n"); scanf("%d",&choice);}

	// Play Custom Board
	switch(botLevel){
	case 1:
	switch(columns){
        case 7:
		switch(rows){
			case 6: playBotEasy(board6x7,rows,columns, winThreshold); break;
			case 7:  playBotEasy(board7x7,rows,columns, winThreshold); break;
			case 8:  playBotEasy(board8x7,rows,columns, winThreshold); break;
			case 9:  playBotEasy(board9x7,rows,columns, winThreshold); break;
			}
		break;
        case 8:
		switch(rows){
			case 6: playBotEasy(board6x8,rows,columns, winThreshold); break;
			case 7:  playBotEasy(board7x8,rows,columns, winThreshold); break;
			case 8:  playBotEasy(board8x8,rows,columns, winThreshold); break;
			case 9:  playBotEasy(board9x8,rows,columns, winThreshold); break;
			}
		break;
        case 9:
		switch(rows){
			case 6: playBotEasy(board6x9,rows,columns, winThreshold); break;
			case 7:  playBotEasy(board7x9,rows,columns, winThreshold); break;
			case 8:  playBotEasy(board8x9,rows,columns, winThreshold); break;
			case 9:  playBotEasy(board9x9,rows,columns, winThreshold); break;
			}
		break;
		case 10:
		switch(rows){
			case 6: playBotEasy(board6x10,rows,columns, winThreshold); break;
			case 7:  playBotEasy(board7x10,rows,columns, winThreshold); break;
			case 8:  playBotEasy(board8x10,rows,columns, winThreshold); break;
			case 9:  playBotEasy(board9x10,rows,columns, winThreshold); break;
			}
		break;
		}
		case 2:
		switch(columns){
                case 7:
        		switch(rows){
        			case 6: playBotMedium(board6x7,rows,columns, winThreshold); break;
        			case 7:  playBotMedium(board7x7,rows,columns, winThreshold); break;
        			case 8:  playBotMedium(board8x7,rows,columns, winThreshold); break;
        			case 9:  playBotMedium(board9x7,rows,columns, winThreshold); break;
        			}
        		break;
                case 8:
        		switch(rows){
        			case 6: playBotMedium(board6x8,rows,columns, winThreshold); break;
        			case 7:  playBotMedium(board7x8,rows,columns, winThreshold); break;
        			case 8:  playBotMedium(board8x8,rows,columns, winThreshold); break;
        			case 9:  playBotMedium(board9x8,rows,columns, winThreshold); break;
        			}
        		break;
                case 9:
        		switch(rows){
        			case 6: playBotMedium(board6x9,rows,columns, winThreshold); break;
        			case 7:  playBotMedium(board7x9,rows,columns, winThreshold); break;
        			case 8:  playBotMedium(board8x9,rows,columns, winThreshold); break;
        			case 9:  playBotMedium(board9x9,rows,columns, winThreshold); break;
        			}
        		break;
        		case 10:
        		switch(rows){
        			case 6: playBotMedium(board6x10,rows,columns, winThreshold); break;
        			case 7:  playBotMedium(board7x10,rows,columns, winThreshold); break;
        			case 8:  playBotMedium(board8x10,rows,columns, winThreshold); break;
        			case 9:  playBotMedium(board9x10,rows,columns, winThreshold); break;
        			}
        		break;
        		}
		case 3:
		switch(columns){
                case 7:
        		switch(rows){
        			case 6: playBotHard(board6x7,rows,columns, winThreshold); break;
        			case 7:  playBotHard(board7x7,rows,columns, winThreshold); break;
        			case 8:  playBotHard(board8x7,rows,columns, winThreshold); break;
        			case 9:  playBotHard(board9x7,rows,columns, winThreshold); break;
        			}
        		break;
                case 8:
        		switch(rows){
        			case 6: playBotHard(board6x8,rows,columns, winThreshold); break;
        			case 7:  playBotHard(board7x8,rows,columns, winThreshold); break;
        			case 8:  playBotHard(board8x8,rows,columns, winThreshold); break;
        			case 9:  playBotHard(board9x8,rows,columns, winThreshold); break;
        			}
        		break;
                case 9:
        		switch(rows){
        			case 6: playBotHard(board6x9,rows,columns, winThreshold); break;
        			case 7:  playBotHard(board7x9,rows,columns, winThreshold); break;
        			case 8:  playBotHard(board8x9,rows,columns, winThreshold); break;
        			case 9:  playBotHard(board9x9,rows,columns, winThreshold); break;
        			}
        		break;
        		case 10:
        		switch(rows){
        			case 6:  playBotHard(board6x10,rows,columns, winThreshold); break;
        			case 7:  playBotHard(board7x10,rows,columns, winThreshold); break;
        			case 8:  playBotHard(board8x10,rows,columns, winThreshold); break;
        			case 9:  playBotHard(board9x10,rows,columns, winThreshold); break;
        			}
        		break;
        		}
		}
}
void playerNames(){
	system("cls");
		for(i=0;i<5;i++)printf("\n");
	printf("		      Enter Name for");              		
	for(i=0;i<2;i++)printf("\n");
	printf("		..........................\n"
			"		|        Player 1        |\n"                
           "		..........................\n" 
           "\n\n");
	scanf("%s", player_one);
	getchar();
		   
	system("cls");
	for(i=0;i<5;i++)printf("\n");
	printf("		      Enter Name for");              		
	for(i=0;i<2;i++)printf("\n");
	printf("		..........................\n"
			"		|        Player 2        |\n"                
           "		..........................\n" 
           "\n\n");
	scanf("%s",player_two);

}
void name(){
system("cls");
		for(i=0;i<5;i++)printf("\n");
	printf("		      Enter Name for");
	for(i=0;i<2;i++)printf("\n");
	printf("		..........................\n"
			"		|        Player 1        |\n"
           "		..........................\n"
           "\n\n");
	scanf("%s", player_one);
	getchar();
	strcpy(player_two,"Computer");
}
void play(char *board, int rows, int columns, int winThreshold){
	playerNames();
	int turn, done = 0;
	memset(board, ' ', rows * columns);
	for(turn = 0; turn < rows * columns && !done; turn++){
      printBoard(board,rows,columns);   
      while(!takeTurn(board, turn % 2,rows,columns)){
      printBoard(board,rows,columns);   
         puts("**Column full!**\n");
      }
      done = checkWin(board,rows,columns, winThreshold);
   }
     printBoard(board,rows,columns);   
   
if(turn == rows * columns && !done){
      puts("It's a tie!");
   } else {
      turn--;
	  if (turn % 2 + 1 == 1){
      printf("%s (X) wins!\n", player_one);
   }
   else{
	   printf("%s (O) wins!\n", player_two);
   }
   }

	Sleep(3000);
	printf("Press Enter to return to Menu.\n");
	getch(); 
}

void playBotEasy(char *board, int rows, int columns, int winThreshold) {
	name();
	int turn, done = 0;
	memset(board, ' ', rows * columns);
	for (turn = 0; turn < rows * columns && !done; turn++) {
		printBoard(board, rows, columns);
		while (!takeTurnBotEasy(board, turn % 2, rows, columns)) {
			printBoard(board, rows, columns);
			puts("**Column full!**\n");
		}
		done = checkWin(board, rows, columns, winThreshold);
	}
	printBoard(board, rows, columns);

	if (turn == rows * columns && !done) {
		puts("It's a tie!");
	}
	else {
		turn--;
		if (turn % 2 + 1 == 1) {
			printf("%s (X) wins!\n", player_one);
		}
		else {
			printf("%s (O) wins!\n", player_two);
		}
	}

	Sleep(3000);
	printf("Press Enter to return to Menu.\n");
	getch();
}
void playBotMedium(char *board, int rows, int columns, int winThreshold) {
	name();
	int turn, done = 0;
	memset(board, ' ', rows * columns);
	for (turn = 0; turn < rows * columns && !done; turn++) {
		printBoard(board, rows, columns);
		while (!takeTurnBotMedium(board, turn % 2, rows, columns)) {
			printBoard(board, rows, columns);
			puts("**Column full!**\n");
		}
		done = checkWin(board, rows, columns, winThreshold);
	}
	printBoard(board, rows, columns);

	if (turn == rows * columns && !done) {
		puts("It's a tie!");
	}
	else {
		turn--;
		if (turn % 2 + 1 == 1) {
			printf("%s (X) wins!\n", player_one);
		}
		else {
			printf("%s (O) wins!\n", player_two);
		}
	}

	Sleep(3000);
	printf("Press Enter to return to Menu.\n");
	getch();
}
void playBotHard(char *board, int rows, int columns, int winThreshold) {
	playerNames();
	int turn, done = 0;
	memset(board, ' ', rows * columns);
	for (turn = 0; turn < rows * columns && !done; turn++) {
		printBoard(board, rows, columns);
		while (!takeTurn(board, turn % 2, rows, columns)) {
			printBoard(board, rows, columns);
			puts("**Column full!**\n");
		}
		done = checkWin(board, rows, columns, winThreshold);
	}
	printBoard(board, rows, columns);

	if (turn == rows * columns && !done) {
		puts("It's a tie!");
	}
	else {
		turn--;
		if (turn % 2 + 1 == 1) {
			printf("%s (X) wins!\n", player_one);
		}
		else {
			printf("%s (O) wins!\n", player_two);
		}
	}

	Sleep(3000);
	printf("Press Enter to return to Menu.\n");
	getch();
}

void printBoard(char *board, int rows,int columns){
	system("cls");
	int row, col;

   //system("clear");
   for(i=0;i<5;i++)printf("\n");
   switch(columns){
		  case 7:
		  puts("			Connect Four\n\n"); break;
		  case 8:
		  puts("			  Connect Four\n\n"); break;
		  case 9:
		  puts("			    Connect Four\n\n"); break; 
		  case 10:
		  puts("			      Connect Four\n\n"); break;
	  }
   for(row = 0; row < rows; row++){
	   printf("		");
      for(col = 0; col < columns; col++){
         printf("| %c ",  board[columns * row + col]);
      }
      puts("|");
	  switch(columns){
		  case 7:
		  puts("		.............................");break;
		  case 8:
		   puts("		.................................");break;
		   case 9:
		   puts("		.....................................");break;
		   case 10:
		   puts("		.........................................");break;
	  }

   }
   switch(columns){
		  case 7:
		  puts("		  1   2   3   4   5   6   7\n\n");break;
		  case 8:
		   puts("		  1   2   3   4   5   6   7   8\n\n");break;
		   case 9:
		   puts("		  1   2   3   4   5   6   7   8   9\n\n");break;
		   case 10:
		   puts("		  1   2   3   4   5   6   7   8   9   10\n\n");break;
	  }
}
int takeTurn(char *board, int player,int rows, int columns){
	  int row, col = 0;
	  if (player == 0){ printf("%s (X) Choose a column: ", player_one, PIECES[player]);}
	  else {printf("%s (O) Choose a column: ", player_two, PIECES[player]);}

   while(1){ 
      if(1 != scanf("%d", &col) || col < 1 || col > columns ){
         while(getchar() != '\n');
         puts("Number out of bounds! Try again.");
      } else { 
         break;
      }
   }
   col--;

   for(row = rows - 1; row >= 0; row--){
      if(board[columns * row + col] == ' '){
         board[columns * row + col] = PIECES[player];
         return 1;
      }
   }
   return 0;
}
int takeTurnBotEasy(char *board, int player,int rows, int columns){
	  int row, col = 0;
	  if (player == 0){
	  printf("%s (X) Choose a column: ", player_one, PIECES[player]);
	  }
	  else {
	  printf("%s (O) Choose a column: ", player_two, PIECES[player]);
	  Sleep(1000);
	  }

if (player == 0){
   while(1){
      if(1 != scanf("%d", &col) || col < 1 || col > columns ){
         while(getchar() != '\n');
         puts("Number out of bounds! Try again.");
      } else {
         break;
      }
   }
   col--;
   }

if (player != 0){
   col = rand() % columns;
   }
   for(row = rows - 1; row >= 0; row--){
      if(board[columns * row + col] == ' '){
         board[columns * row + col] = PIECES[player];
         return 1;
      }
   }
   return 0;
}

int takeTurnBotMedium(char *board, int player,int rows, int columns){
	  int row, col = 0;
	  if (player == 0){
	  printf("%s (X) Choose a column: ", player_one, PIECES[player]);
	  }
	  else {
	  printf("%s (O) Choose a column: ", player_two, PIECES[player]);
	  Sleep(1000);
	  }

if (player == 0){
   while(1){
      if(1 != scanf("%d", &col) || col < 1 || col > columns ){
         while(getchar() != '\n');
         puts("Number out of bounds! Try again.");
      } else {
         break;
      }
   }
   col--;
   }

if (player != 0){
    col = botCheck(board, rows, columns,winThreshold);
    if (col == 0){
    col = rand() % columns;
    }
    }
   for(row = rows - 1; row >= 0; row--){
      if(board[columns * row + col] == ' '){
         board[columns * row + col] = PIECES[player];
         return 1;
      }
   }
   return 0;
}


int checkThree(char *board, int a, int b, int c){
    return (board[a] == board[b] && board[b] == board[c] && board[a] != ' ');
}
int checkFour(char *board, int a, int b, int c, int d){
    return (board[a] == board[b] && board[b] == board[c] && board[c] == board[d] && board[a] != ' ');
}
int checkFive(char *board, int a, int b, int c, int d, int e){
    return (board[a] == board[b] && board[b] == board[c] && board[c] == board[d] && board[d] == board[e] && board[a] != ' ');
}

int checkWin(char *board, int rows, int columns, int winThreshold){
    int row, col, idx, count = 0;;
     const int DIAG_RGT = columns-1, DIAG_LFT = columns+1;

    for(row = 0; row < rows; row++){
       for(col = 0; col < columns - 3; col++){
          idx = columns * row + col;
		  if (winThreshold == 4){
          if(checkFour(board, idx, idx + 1, idx + 2, idx + 3)){
             return 1;
          }
          else if(checkFour(board, idx, idx + columns, idx + columns * 2, idx + columns * 3)){
          return 1;
          }
          else if(count <= 3 && checkFour(board, idx, idx + DIAG_LFT, idx + DIAG_LFT * 2, idx + DIAG_LFT * 3) || count >= 3 && checkFour(board, idx, idx + DIAG_RGT, idx + DIAG_RGT * 2, idx + DIAG_RGT * 3)){
          return 1;
          }
		  }
	
		  else if (winThreshold == 5){
          if(checkFive(board, idx, idx + 1, idx + 2, idx + 3, idx + 4 )){
             return 1;
          }
          else if(checkFive(board, idx, idx + columns, idx + columns * 2, idx + columns * 3, idx + columns * 4 )){
          return 1;
          }
          else if(count <= 4 && checkFive(board, idx, idx + DIAG_LFT, idx + DIAG_LFT * 2, idx + DIAG_LFT * 3, idx + DIAG_LFT * 4) || count >= 3 && checkFive(board, idx, idx + DIAG_RGT, idx + DIAG_RGT * 2, idx + DIAG_RGT * 3, idx + DIAG_RGT * 4)){
          return 1;
          }
		  }
		  count++;
	   }
	   count=0;
    }
    return 0;
}
int botCheck(char *board, int rows, int columns, int winThreshold){
    int row, col, idx, count = 0;
    int num=0;

     const int DIAG_RGT = columns-1, DIAG_LFT = columns+1;

    for(row = 0; row < rows; row++){
       for(col = 0; col < columns - 3; col++){
          idx = columns * row + col;
		  if (winThreshold == 4){
          if(checkThree(board, idx, idx + 1, idx + 2)){
               num = col + 3;
          }
          else if(checkThree(board, idx, idx + columns, idx + columns * 2)){
          num = col + 3;
          }
          else if(count <= 3 && checkThree(board, idx, idx + DIAG_LFT, idx + DIAG_LFT * 2)){
          num = col - 3;
          }
          else if(count >= 3 && checkThree(board, idx, idx + DIAG_RGT, idx + DIAG_RGT * 2)){
          num = col + 3;
          }
		  }

		  else if (winThreshold == 5){
          if(checkFour(board, idx, idx + 1, idx + 2, idx + 3)){
             num = col + 4;
          }
          else if(checkFour(board, idx, idx + columns, idx + columns * 2, idx + columns * 3)){
            num = col + 4;
          }
          else if(count <= 3 && checkFour(board, idx, idx + DIAG_LFT, idx + DIAG_LFT * 2, idx + DIAG_LFT * 3)){
            num = col - 4;
          }
          else if(count >= 3 && checkFour(board, idx, idx + DIAG_RGT, idx + DIAG_RGT * 2, idx + DIAG_RGT * 3)){
          num = col + 4;
          }
		  }
		  count++;
	   }
	   count=0;
    }
    return num;
}
void instructions()
{
	system("cls");
	for(i=0;i<2;i++)printf("\n");
	printf("		    Connect 4\n");
	for(i=0;i<2;i++)printf("\n");
	printf("			Rules\n");
		printf("	The Rules to Connect 4 are simple. \n	Get a line of 4 of your peices connected vertically, horizontally or diagonally. \n	Each player will take a turn to place a peice into a column.  \n\n\n");
	printf("Press Enter to return to Menu.\n");
   getch();
   menu();
}