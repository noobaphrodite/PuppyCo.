#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insert();
void search();
void update();

struct puppies
{
    int pupcode;
    int birthdate;
    int pupage;
    char pupname[20];
    char ownername[20];
    float price;
};
struct puppies puppy;

void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\t**********************************\n");
        printf("\t  'WELCOME TO PUPPY.CO DATABASE'\n");
        printf("\t**********************************\n\n\n");

        printf("\t****What would you like to do?****\n\n");
        printf("\t~1: Insert Puppy record~\n");
        printf("\t~2: Search Puppy record~\n");
        printf("\t~3: Update Puppy record~\n");
        printf("\t~4: Exit~\n\n");
        printf("\tEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            insert();
            break;
        case 2:
            system("cls");
            search();
            break;
        case 3:
            system("cls");
            update();
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("\n\t\t!!! You Entered The Wrong Choice !!!\n\n");
        }
        getchar();
    }
}

void insert()
{
    FILE *fp;
    fp = fopen("puppyco.txt", "a+");
    printf("\n\n\t~~~ENTER NEW PUPPY DATA~~~");
    printf("\n\n\tEnter Puppy Code : ");
    scanf("%d", &puppy.pupcode);

    printf("\n\tEnter Birth Date : ");
    scanf("%d", &puppy.birthdate);

    printf("\n\tEnter Puppy Age : ");
    scanf("%d", &puppy.pupage);
    fflush(stdin);

    printf("\n\tEnter Puppy Name : ");
    gets(puppy.pupname);

    printf("\n\tEnter Owner Name : ");
    gets(puppy.ownername);

    printf("\n\tEnter Price : ");
    scanf("%f", &puppy.price);

    fwrite(&puppy, sizeof(puppy), 1, fp);
    {
        printf("\n\n\tPuppy Details Recorded Sucessfully !!!\n");
    }
    fclose(fp);
    fflush(stdin);
    printf("\n\t\tRecord Updated !!!\n\n");
}
void search()
{
    int code, flag = 0;

    FILE *fp;
    fp = fopen("puppyco.txt", "r");

    if (fp == NULL)
    {
        printf("\n\t\tError : File Does Not Exist !!! ");
        return;
    }

    printf("\n\n\tEnter Puppy Code To Search : ");
    scanf("%d", &code);
    while (fread(&puppy, sizeof(puppy), 1, fp) > 0 && flag == 0)
    {
        if (puppy.pupcode == code)
        {
            flag = 1;
            printf("\n\tSearch Sucessfull And Puppy Details Is as follows");
            printf("\n\n\tPuppy Code\tBirth Date\tAge\tPuppy Name\tOwner Name\tPrice\n");
            printf("\t%d\t\t%d\t\t%d\t%s\t\t%s\t\t%.4f\n\n\n", puppy.pupcode, puppy.birthdate, puppy.pupage, puppy.pupname, puppy.ownername, puppy.price);
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\t!!! No Record Found !!!\n\n");
    }
    fclose(fp);
}
void update()
{
    int code, flag = 0;

    FILE *fp;
    fp = fopen("puppyco.txt", "r+");
    if (fp == NULL)
    {
        printf("\n\t\tError : File Does Not Exist");
        return;
    }

    printf("\n\n\tEnter Puppy Code of the Puppy Details To Update : ");
    scanf("%d", &code);

    printf("\n\n\t\t *** Previously Stored Puppy Details for the Puppy Code ***\n");
    while (fread(&puppy, sizeof(puppy), 1, fp) > 0 && flag == 0)
    {
        if (puppy.pupcode == code)
        {
            flag = 1;
            printf("\n\n\tPuppy Code\tBirth Date\tAge\tPuppy Name\tOwner Name\t\tPrice\n");
            printf("\t%d\t\t%d\t\t%d\t\t%s\t\t%s\t\t\t%.4f\n\n\n", puppy.pupcode, puppy.birthdate, puppy.pupage, puppy.pupname, puppy.ownername, puppy.price);

            printf("\n\t\t*** Update the Puppy Details ***\n\n");
            printf("\n\tEnter Puppy Code : ");
            scanf("%d", &puppy.pupcode);

            printf("\n\tEnter Birth Date : ");
            scanf("%d", &puppy.birthdate);

            printf("\n\tEnter Puppy Age : ");
            scanf("%d", &puppy.pupage);
            fflush(stdin);

            printf("\n\tEnter Puppy Name : ");
            gets(puppy.pupname);

            printf("\n\tEnter Owner Name : ");
            gets(puppy.ownername);

            printf("\n\tEnter Price : ");
            scanf("%f", &puppy.price);

            fseek(fp, -(long)sizeof(puppy), 1);

            fwrite(&puppy, sizeof(puppy), 1, fp);
            printf("\n\n\t\tDetails Updated\n\n\n");
        }
    }
    if (flag == 0)
    {
        printf("\n\t\tError : Something Went Wrong !!!\n\n");
    }
    {
        printf("\n\n\tPuppy Details Recorded Sucessfully !!!\n");
    }
    fclose(fp);
    fflush(stdin);
    printf("\n\t\tRecord Updated !!!\n\n");
}
