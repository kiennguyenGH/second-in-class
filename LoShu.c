#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Checks if square is a Lo Shu magic square
void isMagicSquare(int square[3][3])
{
    int count = 0;

    printf("Testing if square is a magic square...\n");
    if ((square[0][0] + square[0][1] + square[0][2]) == 15)
        count +=1;
    if ((square[1][0] + square[1][1] + square[1][2]) == 15)
        count +=1;
    if ((square[2][0] + square[2][1] + square[2][2]) == 15)
        count +=1;

    if ((square[0][0] + square[1][0] + square[2][0]) == 15)
        count +=1;
    if ((square[0][1] + square[1][1] + square[2][1]) == 15)
        count +=1;
    if ((square[0][2] + square[1][2] + square[2][2]) == 15)
        count +=1;

    if ((square[0][0] + square[1][1] + square[2][2]) == 15)
        count +=1;
    if ((square[0][2] + square[1][1] + square[2][0]) == 15)
        count +=1;   
    
    if(count == 8){
        printf("This square is a magic square!\n");
    }
    else 
        printf("This square is not a magic square.\n");
}

//Prints out square's values
void printSquare(int square[3][3])
{
    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++){
            printf("[%d] ", square[row][column]);
        }
    printf("\n");
    }
}

void main(){
    int square[3][3] = {{1, 2, 3},{4, 5, 6},{7,8,9}};
    int square2[3][3] = {{8,3,4},{1,5,9},{6,7,2}};

    time_t t;
    srand((unsigned) time(&t));
    // for (int row = 0; row < 3; row++){
    //     for (int column = 0; column < 3; column ++){

    //     }
    // }
    printf("Square 1:\n");
    printSquare(square);
    isMagicSquare(square);
    
    printf("Square 2:\n");
    printSquare(square2);

    isMagicSquare(square2);
}
