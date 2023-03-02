#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define X_PIECE 'x'
#define O_PIECE 'o'
#define INDEX_2D(ptr, x, y, height) (ptr[x * height + y])

void drawBoard(const char *board)
{
    printf("   ");
    for(int x = 0; x < BOARD_SIZE; x++)
        printf(" %d", x);
    printf("\r\n");

    for(int x = 0; x < BOARD_SIZE; x++)
    {
        printf("%d [ ", x);
        for(int y = 0; y < BOARD_SIZE; y++)
        {
            printf("%c ", INDEX_2D(board, x, y, BOARD_SIZE));
        }

        printf("]\r\n");
    }
}


void clearBoard(char *board)
{
    for(int x = 0; x < BOARD_SIZE; x++)
    for(int y = 0; y < BOARD_SIZE; y++)
    {
        INDEX_2D(board, x, y, BOARD_SIZE) = ' ';
    }
}

char checkWin(const char *board)
{
    char checking;

    // vertical check
    for(int x = 0; x < BOARD_SIZE; x++)
    {
        int y = 0;
        
        for(checking = ' '; y < BOARD_SIZE; y++)
        {
            const char VALUE = INDEX_2D(board, x, y, BOARD_SIZE);

            if(VALUE == ' ')
                break;

            if(checking == ' ')
            {
                checking = VALUE;
                continue;
            }

            if(checking != VALUE)
                break;
        }

        if(y == BOARD_SIZE)
        {
            return checking;
        }
    }

    // horizontal check
    for(int y = 0; y < BOARD_SIZE; y++)
    {
        int x = 0;
        for(checking = ' '; x < BOARD_SIZE; x++)
        {
            const char VALUE = INDEX_2D(board, x, y, BOARD_SIZE);

            if(VALUE == ' ')
                break;

            if(checking == ' ')
            {
                checking = VALUE;
                continue;
            }

            if(checking != VALUE)
                break;
        }

        if(x == BOARD_SIZE)
        {
            return checking;
        }
    }

    
    // diagonal 1
    int x = 0, y = 0;
    for(checking = ' '; x < BOARD_SIZE; x++, y++)
    {
        const char VALUE = INDEX_2D(board, x, y, BOARD_SIZE);

        if(VALUE == ' ')
            break;

        if(checking == ' ')
        {
            checking = VALUE;
            continue;
        }

        if(checking != VALUE)
            break;
    }

    if(x == BOARD_SIZE)
    {
        return checking;
    }

    // diagonal 2
    for(checking = ' ', x = 0, y = BOARD_SIZE-1; x < BOARD_SIZE; x++, y--)
    {
        const char VALUE = INDEX_2D(board, x, y, BOARD_SIZE);

        if(VALUE == ' ')
            break;

        if(checking == ' ')
        {
            checking = VALUE;
            continue;
        }

        if(checking != VALUE)
            break;
    }

    if(x == BOARD_SIZE)
    {
        return checking;
    }

    return ' ';
}

int getInput()
{
    char input;
    int x;
    do 
    {
        printf("\rEnter x position: ");
        scanf("%c", &input);
    } 
    while(!('0' <= input && input <= '9') || (input - '0' >= BOARD_SIZE));

    x = input - '0';

    do 
    {
        printf("\rEnter y position: ");
        scanf("%c", &input);
    } 
    while(!('0' <= input && input <= '9') || (input - '0' >= BOARD_SIZE));

    // we're swapping where you'd put x and y here because the board is rendered like sideways
    return (input - '0') * BOARD_SIZE + x;
}

int main(int argc, char *argv[])
{
    const int BOARD_LENGTH = BOARD_SIZE * BOARD_SIZE;

    char *board = malloc((BOARD_LENGTH) * sizeof(char));
 
    if(board == NULL)
    {
        printf("Could not malloc size of: %d x %d", BOARD_SIZE, BOARD_SIZE);
        return 1;
    }

    clearBoard(board);

    char c;
    int turn = 0;
    for(;;)
    {
        printf("\r\n\r\n%c to play\r\n\r\n", turn == 0 ? X_PIECE : O_PIECE);
        drawBoard(board);

        int index = getInput();

        if(board[index] != ' ')
            continue;

        if(turn == 0)
        {
            board[index] = X_PIECE;
        }
        else 
        {
            board[index] = O_PIECE;
        }

        c = checkWin(board);

        if(c == ' ')
        {
            turn = (turn + 1) % 2;
        }
        else 
        {
            break;
        }
    }

    printf("\r\n");
    printf("*********\r\n");
    printf("winner: %c\r\n", c);
    printf("*********\r\n");

    free(board);

    return 0;
}