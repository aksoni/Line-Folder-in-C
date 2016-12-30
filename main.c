#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 10 /* max length of output line */

/* Write a program to "fold" long input lines into two or more shorter lines
after the last non-blank character that occurs before the n-th column of input.
Make sure your program does something intelligent with very long lines, and if
there are no blanks or tabs before the specified column. */

int main()
{
    int c, wordLength, linePosition;
    wordLength = 0;
    char word[MAXLENGTH];
    for(linePosition = 0; (c = getchar()) != EOF; ++linePosition)
    {
        if(linePosition == MAXLENGTH) /* check if line has reached maximum length */
        {
            if(wordLength == MAXLENGTH)
            {
                int i;
                for(i = 0; i < wordLength; i++)
                    putchar(word[i]);
                wordLength = 0;
            }
            putchar('\n');
            linePosition = 0; /* reset character counter */
        }

        if(c == ' ' || c == '\n')
        {
            int i;
            for(i = 0; i < wordLength; i++)
                putchar(word[i]);
            putchar(c);
            wordLength = 0;
            if(c == '\n')
                linePosition = 0;
        }

        else
        {
           word[wordLength] = c;
           ++wordLength;
        }

    }

    return 0;
}
