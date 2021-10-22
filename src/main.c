#include "search.h"
#include "board.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	short board[9];
	for (short i = 0; i < 8; i++) {
		board[i] = i + 1;
	}
	board[8] = 0;	
	shuffleBoard(board);
	//short board[] = {1,2,3,4,5,6,7,0,8}; //debug
	//short board[] = {2,0,4,6,7,1,8,5,3}; //easy
	//short board[] = {8.6.7.2.5.4.3.0.1}; //hard
	printf("randomly generated board:\n");
	printBoard(board);
	node * root = (node*)malloc(sizeof(node));
	memcpy(root->boardState, board, 9 * sizeof(short));
	breadthSearch(root);
	//deepSearch(root);
	//iterativeDeepSearch(root);
}
