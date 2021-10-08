#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Checks if square is a Lo Shu magic square, returns 8 if square is Magic Square
int isMagicSquare(int square[3][3])
{
    int count = 0;

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
    
    return count;
}

//Prints out square's values
void printSquare(int square[3][3])
{
    for (int row = 0; row < 3; row++){
        printf("[");
        for (int column = 0; column < 3; column++){
            if (column == 2)
                printf("%d", square[row][column]);
            else
                printf("%d ", square[row][column]);
        }
        printf("]\n");
    }
}

void main(){
    int square[3][3] = {{1, 2, 3},{4, 5, 6},{7,8,9}};
    int square2[3][3] = {{8,3,4},{1,5,9},{6,7,2}};
    int square3[3][3];
    int count = 0;
    srand(time(NULL));

    printf("Square 1:\n");
    printSquare(square);
    if (isMagicSquare(square) == 8){
        printf("This square is a magic square!\n");
    }
    else
        printf("This square is not a magic square.\n");    

    printf("\n");
    printf("Square 2:\n");
    printSquare(square2);
    if (isMagicSquare(square2) == 8){
        printf("This square is a magic square!\n");
    }
    else
        printf("This square is not a magic square.\n");

    //Create a random magic square
    while (isMagicSquare(square3) != 8){
        int array[9];
        int index = 0;
        array[0] = (rand() % 9) + 1;
        for (int i = 1; i < 9; i++)
        {
            int num = (rand() % 9) + 1;
            for (int k = 0; k < i; k++)
            {
                if (array[k] == num)
                {
                    num = (rand() % 9) + 1;
                    k = -1;
                }
            }
            array[i] = num;
        }
        for (int row = 0; row < 3; row++){
            for (int column = 0; column < 3; column ++){
                square3[row][column] = array[index];
                index++;
            }
        }
        count += 1;
    }

    printf("\n");
    printf("Square 3 (Randomly generated square):\n");
    printSquare(square3);
    if (isMagicSquare(square3) == 8){
        printf("This square is a magic square!\n");
    }
    else
        printf("This square is not a magic square.\n");
    printf("Number of squares generated before success: %d", count);
}
