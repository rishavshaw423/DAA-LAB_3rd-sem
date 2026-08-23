 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int number;
    char colour[10];
} Pair;

int main()
{
    int n;

    printf("Enter number of pairs: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of pairs.\n");
        return 1;
    }

    Pair *red = malloc(n * sizeof(Pair));
    Pair *blue = malloc(n * sizeof(Pair));
    Pair *yellow = malloc(n * sizeof(Pair));

    if (red == NULL || blue == NULL || yellow == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int r = 0, b = 0, y = 0;

    printf("\nEnter %d pairs in increasing order of number:\n", n);

    for (int i = 0; i < n; i++)
    {
        int number;
        char colour[10];

        printf("Pair %d: ", i + 1);
        scanf("%d %s", &number, colour);

        if (strcmp(colour, "Red") == 0 ||
            strcmp(colour, "red") == 0)
        {
            red[r].number = number;
            strcpy(red[r].colour, "Red");
            r++;
        }
        else if (strcmp(colour, "Blue") == 0 ||
                 strcmp(colour, "blue") == 0)
        {
            blue[b].number = number;
            strcpy(blue[b].colour, "Blue");
            b++;
        }
        else if (strcmp(colour, "Yellow") == 0 ||
                 strcmp(colour, "yellow") == 0)
        {
            yellow[y].number = number;
            strcpy(yellow[y].colour, "Yellow");
            y++;
        }
        else
        {
            printf("Invalid colour: %s\n", colour);

            free(red);
            free(blue);
            free(yellow);

            return 1;
        }
    }

    printf("\n========== SORTED BY COLOUR ==========\n");

    printf("\nRed:\n");
    for (int i = 0; i < r; i++)
    {
        printf("(%d, %s)\n", red[i].number, red[i].colour);
    }

    printf("\nBlue:\n");
    for (int i = 0; i < b; i++)
    {
        printf("(%d, %s)\n", blue[i].number, blue[i].colour);
    }

    printf("\nYellow:\n");
    for (int i = 0; i < y; i++)
    {
        printf("(%d, %s)\n", yellow[i].number, yellow[i].colour);
    }

    free(red);
    free(blue);
    free(yellow);

    return 0;
}