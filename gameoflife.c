#include <stdio.h>
#include <stdlib.h>

static int board[12][12];

void init_board(int board[12][12]) {
    int y;
    int x;
    srand((unsigned) time(&x));
    for (x=0;x<12;x++) {
        for (y=0;y<12;y++) {
            if (x==0||x==11||y==0||y==11){
                board[x][y] = 0;
            }
            else {

                board[x][y] = rand()%2;
                printf("%d ",board[x][y]);
            }
        }

        printf("\n");
    }
}

void update(int board[12][12]){
    int neighbors;
    int x;
    int y;
    for (x=1;x<11;x++) {
        for (y=1;y<11;y++){
            neighbors = board[x+1][y]+board[x-1][y]+board[x][y+1]+board[x][y-1]+board[x-1][y+1]+board[x+1][y+1]+board[x-1][y-1]+board[x+1][y-1]; 

            if (neighbors < 2 || neighbors > 3){
                board[x][y] = 0;
            }
            else if ((neighbors == 3) && (board[x][y] == 0)) {
                board[x][y] = 1;
            }
            else if ((neighbors == 2||neighbors == 3) && (board[x][y]==1)) {
                board[x][y] = 1;
            }
            printf("%d ",board[x][y]);
            neighbors = 0;        
        }
        printf("\n");
    }
}

void main() {
    int i;

    init_board(board);
    
    for (i=0;i<10;i++){
        update(board);
        printf("\n--------------------------------\n");
    }
}
