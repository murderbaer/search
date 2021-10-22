#include "board.h"
#include <stdarg.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


short findZeroPostion(short board[]) {
	for (short i = 0; i < 9; i++) {
		if (board[i] == 0) {
			return i;
		}
	}
	return -1;
}

void printBoard(short board[]) {
	for (short i = 0; i < 9; i += 3) {
		printf("%hu %hu %hu\n", board[i], board[i + 1], board[i + 2]);
	}
}

enum MOVE selectDirection(short count, ... ) {
	va_list argList;
	va_start(argList, count);
	short directionSelector = (rand() % count) + 1;
	enum MOVE direction;
	while (count--) {
		direction = va_arg(argList, enum MOVE);
		if (directionSelector == count) return direction;
	}
	va_end(argList);
	return direction;
}

void move(enum MOVE direction, short board[]) {
	short oldZeroPos = findZeroPostion(board);
	switch (direction)
	{
	case LEFT:
		board[oldZeroPos] = board[oldZeroPos - 1];
		board[oldZeroPos - 1] = 0;
		break;
	case RIGHT:
		board[oldZeroPos] = board[oldZeroPos + 1];
		board[oldZeroPos + 1] = 0;
		break;
	case UP:
		board[oldZeroPos] = board[oldZeroPos - 3];
		board[oldZeroPos - 3] = 0;
		break;
	case DOWN:
		board[oldZeroPos] = board[oldZeroPos + 3];
		board[oldZeroPos + 3] = 0;
		break;
	default:
		break;
	}
}

void shuffleBoard(short board[]){
	srand(time(NULL));
	short shuffleSteps = 30;
	short whitePos = 8;
	for (short i = 0; i < shuffleSteps; i++) {
		switch (whitePos) {
			case 0:
				move(selectDirection(2, DOWN, RIGHT), board);
				break;
			case 1:
				move(selectDirection(3, DOWN, RIGHT, LEFT), board);
				break;
			case 2:
				move(selectDirection(2, DOWN, LEFT), board);
				break;
			case 3:
				move(selectDirection(3, DOWN, UP, RIGHT), board);
				break;
			case 4:
				move(selectDirection(4, DOWN, UP, RIGHT, LEFT), board);
				break;
			case 5:
				move(selectDirection(3, DOWN, UP, LEFT), board);
				break;
			case 6:
				move(selectDirection(2, UP, RIGHT), board);
				break;
			case 7:
				move(selectDirection(3, UP, RIGHT, LEFT), board);
				break;
			case 8:
				move(selectDirection(2, UP, LEFT), board);
				break;
		}
		whitePos = findZeroPostion(board);
	}

}
