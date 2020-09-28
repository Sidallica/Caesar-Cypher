#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char caesar(char alpha, int key);

int main(int argc, string argv[])
{
    //Checking for correct number of command line arguments
    if (argc == 2)
    {
        //Checking if key is numeric
        for (int i = 0, length = strlen(argv[1]); i < length; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");

        //Algorithm for caesar cipher
        for (int i = 0, length = strlen(plaintext); i < length; i++)
        {
            //Handling alphabets
            if (isalpha(plaintext[i]))
            {
                printf("%c", caesar(plaintext[i], key));
            }
            else
                //Handling punctuations etc.
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//Function for caesar's cipher
char caesar(char alpha, int key)
{
    //Handing upper case letters
    if (isupper(alpha))
    {
        int ascii = ((int) alpha - 65 + key) % 26;
        return (char) ascii + 65;
    }
    else
        //Handling lower case letters
    {
        int ascii = ((int) alpha - 97 + key) % 26;
        return (char) ascii + 97;
    }
}