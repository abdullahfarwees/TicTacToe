#include<stdio.h>
#include<stdlib.h>

#define ROW_COL 2
#define FINAL_COUNT 2

int board[3][3] ;
static count = 0 ;
char option;
int i,j;

/* ask user to continue the match */
void ContinueOrNot();

/* result of the current match */
void result(int x);

/* Display matrix current match status */
void DisplayBoard();

/* set matrix array value to 0 */
void ResetBoard();

/* Check row wise , Check coloumn wise , Check diagnolly */
void AnalyseMatrix();

/* Get values from user */
void EnterValuesCore();

/*  */
void EnterValues();

void tictactoe();
