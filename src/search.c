#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "search.h"
#include "board.h"

int deepEnd = 0;

short checkSolution(short board[]) {
    for (short i = 0; i < 8; i++) {
        if (board[i] != i + 1) {
            return 0;
        }
    }
    if (board[8] != 0) {
        return 0;
    }
    return 1;
}

void printSolution(node *n) {
    while (n != NULL) {
        printBoard(n->boardState);
        n = n->solutionPath;
        printf("\n");
    }
}

void expandNodeInDirection(node * src, node * nodeList, enum MOVE dir) {
    short movedBoard[9];
    memcpy(movedBoard, src->boardState, 9 * sizeof(short));
    switch (dir)
    {
    case RIGHT:
        move(dir, movedBoard);
        break;
    case LEFT:
        move(dir, movedBoard);
        break;
    case UP:
        move(dir, movedBoard);
        break;
    case DOWN:
        move(dir, movedBoard);
        break;
    default:
        break;
    }
    node * newNode = (node*) malloc(sizeof(node)); 
    memcpy(newNode->boardState, movedBoard, 9 * sizeof(short));
    newNode->solutionPath = src;
    append(nodeList, newNode);
}

void expandNode(node * currentNode, node * nodeList) {
    short zeroPos = findZeroPostion(currentNode->boardState);
    switch (zeroPos)
    {
    case 0:
        expandNodeInDirection(currentNode, nodeList, DOWN);
        expandNodeInDirection(currentNode, nodeList, RIGHT);
        break;
    case 1:
        expandNodeInDirection(currentNode, nodeList, RIGHT);
        expandNodeInDirection(currentNode, nodeList, LEFT);
        expandNodeInDirection(currentNode, nodeList, DOWN);
        break;
    case 2:
        expandNodeInDirection(currentNode, nodeList, LEFT);
        expandNodeInDirection(currentNode, nodeList, DOWN);
        break;
    case 3:
        expandNodeInDirection(currentNode, nodeList, RIGHT);
        expandNodeInDirection(currentNode, nodeList, UP);
        expandNodeInDirection(currentNode, nodeList, DOWN);
        break;
    case 4:
        expandNodeInDirection(currentNode, nodeList, RIGHT);
        expandNodeInDirection(currentNode, nodeList, LEFT);
        expandNodeInDirection(currentNode, nodeList, UP);
        expandNodeInDirection(currentNode, nodeList, DOWN);
        break;
    case 5:
        expandNodeInDirection(currentNode, nodeList, LEFT);
        expandNodeInDirection(currentNode, nodeList, UP);
        expandNodeInDirection(currentNode, nodeList, DOWN);
        break;
    case 6:
        expandNodeInDirection(currentNode, nodeList, RIGHT);
        expandNodeInDirection(currentNode, nodeList, UP);
        break;
    case 7:
        expandNodeInDirection(currentNode, nodeList, UP);
        expandNodeInDirection(currentNode, nodeList, LEFT);
        expandNodeInDirection(currentNode, nodeList, RIGHT);
        break;
    case 8:
        expandNodeInDirection(currentNode, nodeList, LEFT);
        expandNodeInDirection(currentNode, nodeList, UP);
        break;
    default:
        break;
    }
}

void breadthSearch(node * nodeList) {
    node * newNode = (node*) malloc(sizeof(node));
    while (nodeList != NULL) {
        if (checkSolution(nodeList->boardState) == 1) {
            printf("Solution found! Printing now:\n");
            printSolution(nodeList);
            return;
        }
        expandNode(nodeList, newNode);
        nodeList = nodeList->children;
    }
    if (newNode->children != NULL) {
        breadthSearch(newNode);
    } else {
        printf("No solution! \n");
    }
}

void deepSearch(node * nodeList) {
    if (checkSolution(nodeList->boardState) == 1) {
        printf("Solution found! Printing now:\n");
        printSolution(nodeList);
        return;
    }        
    node * newNode = (node *) malloc(sizeof(node));
    expandNode(nodeList, newNode);
    while (newNode->children != NULL) {
        deepSearch(newNode->children);
        newNode = newNode->children;
    }
    printf("No solution! \n");    
}

void deepSearchB(node * nodeList, int depth, int limit) {
    if (checkSolution(nodeList->boardState) == 1) {
        printf("Solution found! Printing now:\n");
        printSolution(nodeList);
        deepEnd = 1;
        return;
    }        
    node * newNode = (node *) malloc(sizeof(node));
    expandNode(nodeList, newNode);
    while (newNode->children != NULL && depth < limit) {
        deepSearchB(newNode->children, depth + 1, limit);
        if (deepEnd == 1) {
            return;
        }
        newNode = newNode->children;
    }    
}

void iterativeDeepSearch(node* nodeList) {
    int limit = 0;
    while (deepEnd != 1) {
        limit++;
        deepSearchB(nodeList, 0, limit);
    }
    printf("Soloution found at depth of %d\n",limit);
}
