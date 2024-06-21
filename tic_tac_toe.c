#include <stdio.h>
#include <string.h>
#include <ctype.h>

char tile[3][3] = {\
	{' ', ' ', ' ',},\
	{' ', ' ', ' ',},\
	{' ', ' ', ' ',},\
};
int played[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


void display();
char choice();
void play(char player);

int main()
{
	printf("Loading Game");
	printf(".......\n");
	printf("Starting Game\n\n");
	printf("\t\tTIC TAC TOE\n");
	char player = choice();
	play(player);
	return 0;
}

void display()
{
	printf("\t\t  %c   |   %c   |   %c   \n", tile[0][0], tile[0][1], tile[0][2]);
	printf("\t\t -- | -- | -- \n");
	printf("\t\t  %c   |   %c   |   %c   \n", tile[1][0], tile[1][1], tile[1][2]);
	printf("\t\t -- | -- | -- \n");
	printf("\t\t  %c   |   %c   |   %c   \n", tile[2][0], tile[2][1], tile[2][2]);
}

char choice()
{
	char input[2];
	printf("\nPick X Or O.");
	printf("Enter x for [X], o for [O]\n");
	
	while (1) {
		fgets(input, sizeof(input), stdin);
		
		switch(toupper(input[0])){
			case 'X':
				return 'X';
			case 'O':
				return 'O';
			default:
				input[0] = '\0';
				break;
		}
	}
}

int end(int i)
{
	int cnt = 0, j;
	for (j = 0; j < 9; ++j) {
		if (played[j] == 1) {
			cnt += 1;
		}
	}
	if (cnt == 9)
		return 3;
	return i;
}

int game_logic(int i, char players, int pos, int pos1, int pos2) {
	if (played[pos - 1] == 0) {
		played[pos - 1] = 1;
	} else {
		return i;
	}
	tile[pos1][pos2] = players;
	return ++i;
}

int check_win(char player, char com, int n) {
	int win = 0;
	char wins[8][3] = {\
		{tile[0][0], tile[0][1], tile[0][2]},\
		{tile[1][0], tile[1][1], tile[1][2]},\
		{tile[2][0], tile[2][1], tile[2][2]},\
		{tile[0][0], tile[1][0], tile[2][0]},\
		{tile[0][1], tile[1][1], tile[2][1]},\
		{tile[0][2], tile[1][2], tile[2][2]},\
		{tile[0][0], tile[1][1], tile[2][2]},\
		{tile[0][2], tile[1][1], tile[2][0] },\
	};
	
	char opt[2] = {'X', 'O'};
	int i, j, k;
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 8; ++j) {
			for (k = 0; k < 3; ++k) {
				if (wins[j][k] == opt[i]){
					win += 1;
				}
			}
			if (win == 3) {
				if (opt[i] == player) {
					printf("CONGRATULATIONS!!!!\n");
					printf("Player[%c] Win.\n", player);
					printf("GOOD LUCK NEXT TIME\n");
					printf("Player [%c] Lose", com);
				} else if (opt[i] == com) {
					printf("CONGRATULATIONS!!!!\n");
					printf("Player[%c] Win.\n", com);
					printf("\nGOOD LUCK NEXT TIME\n");
					printf("Player [%c] Lose\n", player);
				}
				return 3;
			} else {
				win = 0;
			}
		}
	}
	return n;
}

void play(char player)
{
	char player2;
	if (player == 'X') {
		player2 = 'O';
	} else if (player == 'O') {
		player2 = 'X';
	}
	
	int pos, i;
	char players[2] = {player, player2};

	for (i = 0; i < 2;) {
		printf("Player [%c]\t:\tPlayer [%c]\n", player, player2);
		display();
		scanf("%d", &pos);
		
		switch (pos) {
			case 1:
				i = game_logic(i, players[i], pos, 0, 0);
				break;
			case 2:
				i = game_logic(i, players[i], pos, 0, 1);
				break;
			case 3:
				i = game_logic(i, players[i], pos, 0, 2);
				break;
			case 4:
				i = game_logic(i, players[i], pos, 1, 0);
				break;
			case 5:
				i = game_logic(i, players[i], pos, 1, 1);
				break;
			case 6:
				i = game_logic(i, players[i], pos, 1, 2);
				break;
			case 7:
				i = game_logic(i, players[i], pos, 2, 0);
				break;
			case 8:
				i = game_logic(i, players[i], pos, 2, 1);
				break;
			case 9:
				i = game_logic(i, players[i], pos, 2, 2);
				break;
			default:
				break;
		}
		if (i == 2) {
			i = 0;
		}
		i = check_win(player, player2, i);
		i = end(i);
	}

	printf("\nEnd Of Game.");
}