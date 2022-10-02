// Program to make a pyramid of hashes just like in Super Mario Brother's Game
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Ask how tall will the pyramid be
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // For each row
    for (int i = 0; i < height; i++)
    {
        // For each column, print a space
        for (int j = ((height - 1) - i); j > 0; j--)
        {
            printf(" ");
        }

        // For each column, print also "#"
        for (int k = 0; k < height; k++)
        {
            printf("#");

            if (k == i)
            {
                break;
            }
        }

        printf("\n");
    }
}

