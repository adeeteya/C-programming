#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int initialize();
	int main();
	int game();
	int winner();
	int disbox();
	int names();
	int box[3][3];
	int playerflag = 0;
	int playflag1 = 1;
	int playflag2 = 5;
	char player1[50];
	char player2[50];
	int disbox() {
	  int x, y;
	  for (x = 0; x < 3; x++) {
	    for (y = 0; y < 3; y++)
	      printf("%c ",(*(*(box+x)+y)==0)?'-':(*(*(box+x)+y)==1)?'x':'o');
	    printf("\n");
	  }
	  return (0);
	}
	int names() {
	  printf("Enter name of player 1:");
	  scanf("%s", player1);
	  printf("Enter name of player 2:");
	  scanf("%s", player2);
	}
	int initialize() {
	  int x, y;
	  /* initialize matrix */
	  for (x = 0; x < 3; x++)
	    for (y = 0; y < 3; y++)
	      *(*(box+x)+y) = 0;
	  return (0);
	}
	int main() {
	  names();
	  initialize();
	  game();
	  disbox();
	  return (0);
	}
	int game() {
	  printf("%s is player 1\n", player1);
	  printf("%s is player 2\n", player2);
	  printf("%s to play first\n", player1);
	  int i, j, k, n;
	  for (i = 1; i <= 9; i++) {
	    disbox();
	    if (i % 2 != 0) {
	      printf("%s: Enter the number of the box in which you want to play:", player1);
	      playerflag = playflag1;
	      printf("\n");
	    } else {
	      printf("%s: Enter the number of the box in which you want to play:", player2);
	      playerflag = playflag2;
	      printf("\n");
	    }
	    scanf("%d", & n);
	    switch (n) {
	    case 1:
	      *(*(box)) = playerflag;
	      winner();
	      break;
	    case 2:
	      *(*(box)+1) = playerflag;
	      winner();
	      break;
	    case 3:
	      *(*(box)+2) = playerflag;
	      winner();
	      break;
	    case 4:
	      *(*(box+1)) = playerflag;
	      winner();
	      break;
	    case 5:
	      *(*(box+1)+1) = playerflag;
	      winner();
	      break;
	    case 6:
	      *(*(box+1)+2) = playerflag;
	      winner();
	      break;
	    case 7:
	      *(*(box+2)) = playerflag;
	      winner();
	      break;
	    case 8:
	      *(*(box+2)+1) = playerflag;
	      winner();
	      break;
	    case 9:
	      *(*(box+2)+2) = playerflag;
	      winner();
	      break;
	    default:
	      printf("It is a draw");
	    }
	    printf("\n");
	  }
	}
	int winner() {
	  if (*(*(box)) + *(*(box)+1) + *(*(box)+2) == 3 || *(*(box+1)) + *(*(box+1)+1) + *(*(box+1)+2) == 3 || *(*(box+2)) + *(*(box+2)+1) + *(*(box+2)+2) == 3 || *(*(box)) + *(*(box+1)) + *(*(box+2)) == 3 || *(*(box)+1) + *(*(box+1)+1) + *(*(box+2)+1) == 3 || *(*(box)+2) + *(*(box+1)+2) + *(*(box+2)+2) == 3 || *(*(box)) + *(*(box+1)+1) + *(*(box+2)+2) == 3 || *(*(box)+2) + *(*(box+1)+1) + *(*(box+2)) == 3) {
      disbox();
      printf("%s wins", player1);
	    printf("\n");
	    exit(0);}
	else if (*(*(box)) + *(*(box)+1) + *(*(box)+2) == 15 || *(*(box+1)) + *(*(box+1)+1) + *(*(box+1)+2) == 15 || *(*(box+2)) + *(*(box+2)+1) + *(*(box+2)+2) == 15 || *(*(box)) + *(*(box+1)) + *(*(box+2)) == 15 || *(*(box)+1) + *(*(box+1)+1) + *(*(box+2)+1) == 15 || *(*(box)+2) + *(*(box+1)+2) + *(*(box+2)+2) == 15 || *(*(box)) + *(*(box+1)+1) + *(*(box+2)+2) == 15 || *(*(box)+2) + *(*(box+1)+1) + *(*(box+2)) == 15)
	{
      disbox();
      printf("%s wins", player2);
	    printf("\n");
	    exit(0);
	  }
	}
