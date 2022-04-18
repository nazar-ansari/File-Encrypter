//                                                  Header Files Required For Program
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//                                                   Function Prototype Declaration
int encrypt();
int decrypt();
int design();

//                                                  Initialization Of User Defined Data Types
typedef struct stored_variable
{
    char filename[30];
    int pattern;
    int choice;
} integer;
//                                                   Initialization Of Main Function
int main()
{
    integer new;
    new.pattern = 1;
    design(new.pattern, 54);
    printf("\t\t\t%c DO YOU WANT TO ENCRYPT THE FILE OR DECRYPT THE FILE %c\n", new.pattern, new.pattern);
    design(new.pattern, 54);
    printf("\n");
    design(new.pattern, 54);
    printf("\t\t\t%c   CHOOSE \"1\" FOR ENCRYPTION & \"2\" FOR DECRYPTION    %c\n", new.pattern, new.pattern);
    design(new.pattern, 54);
    scanf("%d", &new.choice);
    system("cls");
    switch (new.choice)
    {
    case 1:
        encrypt();
        break;
    case 2:
        decrypt();
        break;
    default:
        printf("\t\t\tOOPS ! IT SEEMS YOU PRESS SOMETHING WRONG TRY AGAIN\n");
    }
    return 0;
}
