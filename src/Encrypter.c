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

//                                                      Function To Encrypt The File
int encrypt()
{
    FILE *file1, *file2;
    integer desg;
    int character;
    desg.pattern = 2;
    design(desg.pattern, 30);
    printf("\t\t\tENTER THE FILENAME TO ENCRYPT:- \n");
    design(desg.pattern, 30);
    scanf("%s", &desg.filename);
    system("cls");
    file1 = fopen(desg.filename, "r");
    if (file1 == NULL)
    {
        printf("\t\t\tTHERE'S NO SUCH FILE WITH NAME \"%s\"\n", desg.filename);
        return 0;
    }
    file2 = fopen("temporary.txt", "w");
    if (file2 == NULL)
    {
        printf("\t\t\tUnable To Proceed !\n");
        return 0;
    }
    character = fgetc(file1);
    while (character != EOF)
    {
        character = character + 100;
        fputc(character, file2);
        character = fgetc(file1);
    }
    fclose(file1);
    fclose(file2);

    file1 = fopen(desg.filename, "w");
    if (file1 == NULL)
    {
        printf("\t\t\tUnable To Proceed With File\n");
        return 0;
    }
    file2 = fopen("temporary.txt", "r");
    if (file2 == NULL)
    {
        printf("\t\t\tUnable To Proceed \n");
        return 0;
    }
    character = fgetc(file2);
    while (character != EOF)
    {
        fputc(character, file1);
        character = fgetc(file2);
    }
    fclose(file1);
    fclose(file2);
    remove("temporary.txt");
    design(desg.pattern, 40);
    printf("\t\t\tFILE %s Successfully Encrypted !\n", desg.filename);
    return design(desg.pattern, 40);
}

//                                                              Function To Decrypt The File
int decrypt()
{
    integer desg2;
    desg2.pattern = 3;
    int character;
    FILE *file1, *file2;
    design(desg2.pattern, 30);
    printf("\t\t\tENTER THE FILENAME TO DECRYPT:- \n");
    design(desg2.pattern, 30);
    scanf("%s", &desg2.filename);
    system("cls");
    file1 = fopen(desg2.filename, "r");
    if (file1 == NULL)
    {
        printf("\t\t\t THERE'S NO SUCH FILE WITH NAME \"%s\"\n", desg2.filename);
        return 0;
    }
    file2 = fopen("temporary.txt", "w");
    if (file2 == NULL)
    {
        printf("\t\t\tUnable To Proceed !\n");
        return 0;
    }
    character = fgetc(file1);
    while (character != EOF)
    {
        character = character - 100;
        fputc(character, file2);
        character = fgetc(file1);
    }
    fclose(file1);
    fclose(file2);

    file1 = fopen(desg2.filename, "w");
    if (file1 == NULL)
    {
        printf("\t\t\tUnable To Proceed With File\n");
        return 0;
    }
    file2 = fopen("temporary.txt", "r");
    if (file2 == NULL)
    {
        printf("\t\t\tUnable To Proceed \n");
        return 0;
    }
    character = fgetc(file2);
    while (character != EOF)
    {
        fputc(character, file1);
        character = fgetc(file2);
    }
    fclose(file1);
    fclose(file2);
    remove("temporary.txt");
    design(desg2.pattern, 40);
    printf("\t\t\tFILE %s Successfully Decryypted !\n", desg2.filename);
    return design(desg2.pattern, 40);
}

//                                              Function To Print Patterns In Between
int design(int n, int limit)
{
    integer desg3;
    desg3.pattern = n;
    int number = limit;
    printf("\t\t\t");
    for (int i = 0; i <= limit; i++)
    {
        printf("%c", desg3.pattern);
    }
    printf("\n");
}