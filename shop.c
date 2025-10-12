#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menulinelimit, menulinesinitial;

void owneraccess()
{
    int adminlimit = 6, adminsused, adminpassword;
    char adminname[20];
    char ownerselect1;
    int ownerselect2;
    printf("\nDo you wish to edit the access permissions? (y/n)\n");
    scanf(" %c", &ownerselect1);
    FILE *fp1 = fopen("adminsused.txt", "r");
    if (fp1 == NULL)
    {
        printf("Could not find the number of admins used! Please check if it is saved\n");
    }
    else
    {
        fscanf(fp1, "%d", &adminsused);
        fclose(fp1);
        switch (ownerselect1)
        {
        case 'y':
            printf("Enter your choice (number):\n1. Add admins\n2.Remove admins\n");
            scanf("%d", &ownerselect2);
            // instead of another text file you should somehow count the number of lines in access.txt to determine adminsused

            switch (ownerselect2)
            {
            case 1:
                if (adminsused < adminlimit)
                {
                    // implement a change where if the name or number length is greater than needed, it says invalid instead of just reading the amount it wants
                    printf("Enter the name of the admin you wish to add: ");
                    scanf("%20s", &adminname);
                    printf("Enter the 6-digit access password of the admin: ");
                    scanf("%6d", &adminpassword);
                    adminsused++;
                    FILE *fp2 = fopen("adminsused.txt", "w");
                    if (fp2 == NULL)
                    {
                        printf("Could not increase the number of admins used! Please check if file is saved\n");
                    }
                    else
                    {
                        fprintf(fp2, "%d", adminsused);
                    }
                    fclose(fp2);
                    FILE *fp3 = fopen("access.txt", "a");
                    if (fp3 == NULL)
                    {
                        printf("Could not write to the access file! Please check if file is saved\n");
                    }
                    else
                    {
                        fprintf(fp3, "%s %d\n", adminname, adminpassword);
                    }
                    fclose(fp3);
                    printf("The new admin has been added!\n");
                }
                else
                {
                    printf("Sorry, there can only be 6 admins including yourself!\n");
                }
                break;

            case 2:
                char adminremovename[20];
                scanf("%20s", adminremovename);
                FILE *fp4 = fopen("access.txt", "r");
                if (fp4 = NULL)
                if (fp4 == NULL)
                {
                    printf("Could not find the access file! Please check if it is saved\n");
                }
                {
                    FILE *fp5 = fopen("accesstmp.txt", "w"); // writing all admins except removed to a tmp file
                    if (fp5 == NULL)
                    {
                        printf("Could not open an access tunnel\n");
                    }
                    else
                    {
                        for (int i = 1; i <= adminsused; i++)
                        {
                            fscanf(fp4, "%20s %6d", adminname, adminpassword);
                            int result = strcmp(adminname, adminremovename); // string.h library, compares strings, we cannot use the != operator directly as it compares memory addresses not string content
                            if (result != 0)
                            {
                                fprintf(fp5, "%s %d\n", adminname, adminpassword);
                            }
                        }
                        fclose(fp5);
                    }
                    fclose(fp4);
                    FILE *fp6 = fopen("adminsused.txt", "w");
                    char no[1];
                    adminsused = (long)fgets(no, 1, fp6);
                    if (fp6 == NULL)
                    {
                        printf("Could not update fprint count!\n");
                    }
                    else
                    {
                        adminsused--;
                        fprintf(fp6, "%d", adminsused);
                        fclose(fp6);
                    }
                    FILE *fp7 = fopen("accesstmp.txt", "r");
                    if (fp7 == NULL)
                    {
                        printf("Could not open an access tunnel\n");
                    }
                    else
                    {
                        FILE *fp8 = fopen("access.txt", "w");
                        if (fp8 == NULL)
                        {
                            printf("Could not find the access file! Please check if it's saved\n");
                        }
                        else
                        {
                            for (int i = 1; i <= adminsused; i++)
                            {
                                char line[200];
                                fgets(line, 200, fp7);
                                fprintf(fp8, "%s", line);
                            }
                            printf("The admin was successfully removed!\n");
                            fclose(fp8);
                        }
                    }
                    fclose(fp7);
                    break;

                default:
                    printf("Please enter a valid input!\n");
                    break;
                }
            }
            break;
        case 'n':
            printf("Owner mode exited!\n");
            break;

        default:
            printf("Please enter a valid input!");
            break;
        }
    }
}

int adminaccess()
{
}

int menureader()
{
    FILE *fp0 = fopen("menu.txt", "r");
    if (fp0 == NULL)
    {
        printf("Could not open the menu! Please check if it is saved\n");
    }
    else
    {
        char line[200];
        for (int linecount = 1; linecount < (menulinelimit + menulinesinitial); linecount++)
        {
            fgets(line, 200, fp0);
            printf("%s", line);
        }
    }
}

int main()
{
    int pwd;
    char firstname[20], lastname[20];
    menureader();
    owneraccess();
    return 0;
}
