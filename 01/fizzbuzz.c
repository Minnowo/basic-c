#include <stdio.h>

int 
strToInt(char* word)
{
    int result = 0;

    const char IS_NEGATIVE = word[0] == '-';

    for(int i = IS_NEGATIVE; word[i] != '\0'; i++)
    {
        char c = word[i];

        if('0' <= c && c <= '9')
        {
            result = result* 10 + (c - '0');
        }
        else
        {
            break;
        }
    }

    if(IS_NEGATIVE == 1)
    {
        return - result;
    }

    return result;
}


void 
printStartArgs(int argc, char *argv[])
{
    printf("Start arguments: [");
    for(int i = 0; i < argc; i++)
    {
        printf("%s, ", argv[i]);
    }
    printf("]\r\n");
}


int
main(int argc, char *argv[] )
{
    printStartArgs(argc, argv);

    int loopCount = 100;

    if(argc == 2)
    {
        loopCount = strToInt(argv[1]);

        printf("Input argument %d\r\n", loopCount);
    }

    for(int i = 1; i <= loopCount; i++)
    {
        printf("[%d] ", i);

        if(i % 3 == 0 && i % 5 == 0)
        {
            printf("FizzBUZZ\r\n");
        }
        else if(i % 5 == 0)
        {
            printf("Buzz\r\n");
        }
        else if (i % 3 == 0) 
        {
            printf("Fizz\r\n");
        }
        else{
            printf("\r\n");
        }
    }

	return 0;
}
