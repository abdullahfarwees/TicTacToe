#include "TicTacToe.h"

/*  */
void referenceBoard()
{

printf("\nReference Matrix for input\n");

  for(i = 0; i <= 2 ; i++)
  {
    for(j = 0; j <= 2 ; j++)
    {
      printf("	%d%d",i+1,j+1);
    }
    printf("\n");
  }

}

/* ask user to continue the match */
void ContinueOrNot()
{

	printf("\n\nEnter 'y' to Continue (or) 'n' to Stop \n\n");
	scanf("%s",&option);

	if('y' == option )
	{
	tictactoe();
	}
	else if( 'n' == option )
	{
	exit(0);
	}

}


/* result of the current match */
void result(int x)
{

	if(x == 1)
	{
	printf("\n\nplayer ONE won !");
	}
	else if( x == 2 )
	{
	printf("\n\nplayer TWO won !");
	}
	else
	{
	printf("\n\nmatch DRAW !");
	}

	ContinueOrNot();
}

/* Display matrix current match status */
void DisplayBoard()
{

  system("clear");

  for(i = 0; i <= 2 ; i++)
  {
    for(j = 0; j <= 2 ; j++)
    {
      printf("  %d",board[i][j]);
    }
    printf("\n");
  }

printf("\n\n");

referenceBoard();
}

/* set matrix array value to 0 */
void ResetBoard()
{

  for(i = 0; i <= 2 ; i++)
  {
    for(j = 0; j <= 2 ; j++)
    {
      board[i][j] = 0;
    }
  }

DisplayBoard();
}

/* Check row wise , Check coloumn wise , Check diagnolly */
void AnalyseMatrix()
{

      	/* Check row wise */
	if(board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1 )
	{
		result(1);
	}
	else if(board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1 )
	{
		result(1);
	}
	else if(board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1 )
	{
		result(1);
	}

	if(board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2 )
	{
		result(2);
	}
	else if(board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2 )
	{
		result(2);
	}
	else if(board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2 )
	{
		result(2);
	}

	/* Check coloumn wise */

	if( board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1 )
	{
		result(1);
	}
	else if( board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1 )
	{
		result(1);
	}
	else if( board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1 )
	{
		result(1);
	}

	if( board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2 )
	{
		result(2);
	}
	else if( board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2 )
	{
		result(2);
	}
	else if( board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2 )
	{
		result(2);
	}

	/* Check diagnolly */
	if( board[0][0] == 1 &&  board[1][1] == 1 && board[2][2] == 1)
	{
	result(1);
	}
	else if( board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1 )
	{
	result(1);
	}

	if( board[0][0] == 2 &&  board[1][1] == 2 && board[2][2] == 2)
	{
	result(2);
	}
	else if( board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)
	{
	result(2);
	}


	printf("\nNo of moves remaining : %d", 9 - count );

	/* to check each matrix element for game draw */
	if( count == 9 )
	{
	result(3);
	}

	/* shows each players turn */
	if(count % 2 == 0)
	{
	printf("\nPlayer 1's turn :");
	}
	else
	{
	printf("\nPlayer 2's turn :");
	}

}

/* Get values from user */
void EnterValuesCore()
{

  int value ,row ,col;
  printf("\nEnter Row Value [1-3] : ");
  scanf("%d", &row);
  printf("\nEnter Col Value [1-3] : ");
  scanf("%d", &col);
  printf("\nEnter value  : ");
  scanf("%d", &value);


  if( ((row >= 0 && row <= 3) || ( col >= 0 && col <= 3 )) && (board[row-1][col-1] == 0) && ( value == 1 || value == 2) )
  {
    board[row-1][col-1] = value;
    count++;
    DisplayBoard();
  }
  else
  {
    printf("\nError...................\n\n");
  }


}

/*  */
void EnterValues()
{

    while(1)
    {
	EnterValuesCore();
        DisplayBoard();
        AnalyseMatrix();
    }
}

void tictactoe()
{

	ResetBoard();
	printf("\n\nPlayer 1's turn :");

	while(1)
	{

	  EnterValues();
	  AnalyseMatrix();
	  DisplayBoard();

	}


}

int main()
{

tictactoe();


printf("\n\n----Program Ends !----");
  return 0;
}
