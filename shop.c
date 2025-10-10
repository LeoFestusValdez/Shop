/**
*@brief This program emulates a shop making use of a while loop and a switch statement
*The program first checks if the entered UID is correct- if it is not it repeatedly prompts for the correct one, also giving the option to exit
*The shop has 3 items, and the facility to check your bill after making purchases
*The while loop keeps prompting the user until they decide to exit
*
*@var UID       		Input password
*@var reqUID    		Required password
*@var selector  		Switch statement option
*@var notebooks 		Number of notebooks purchased
*@var pens      		Number of pens purchased
*@var erasers   		Number of erasers purhcased
*@var notebooksprice    Individual price of a notebook
*@var pensprice 		Individual price of a pen
*@var erasersprice 	    Individual price of an eraser
*@var firstname         First name of shopper
*@var lastname          Last name of shopper
*@author Leo Valdez
*
*/
#include <stdio.h>
#include <stdlib.h> //kept for future use of strtol

int main()
{
    int UID, reqUID, selector, quantity;
    int notebooks=0, pens=0, erasers=0;
    int notebooksprice=40, pensprice=10, erasersprice=5;
    reqUID=632;
    char firstname[15]="Leo"; char secondname[15]="Valdez";
    printf("Kindly enter your password(UID) to begin shopping: ");
    scanf("%d",&UID);
    while (UID!=reqUID)//checks if the password is correct and repeatedly prompts for correct password
    {
        printf("Please enter the correct UID or type '0' to exit: ");
        scanf("%d",&UID);
        if (UID==0){return 0;}
    }
    printf("\nWelcome %s %s,\n",firstname, secondname);
    printf("------- Menu -------\n");
    printf("1. Buy Pen (Rs.10)\n");
    printf("2. Buy Notebook (Rs.40)\n");
    printf("3. Buy Eraser (Rs.5)\n");
    printf("4. Remove Pen (Rs.10)\n");
    printf("5. Remove Notebook (Rs.40)\n");
    printf("6. Remove Erasers (Rs.5)\n");
    printf("7. Generate bill\n");
    printf("8. Exit\n");
    printf("\nEnter your choice (1-8) based on the menu options: ");
    scanf("%d",&selector);
    while (selector!=8)//keeps looping until the user wishes to exit
    {
        switch(selector)
            {
                case 1:
                    {
                        printf("How many pens do you want to buy?\n");
                        scanf("%d" ,&quantity);
                        if(quantity>0)
                        {
                            printf("You bought %d pens\n" ,quantity);
                            pens=pens+quantity;
                        }
                        else
                        {
                            printf("Sorry you have entered an invalid input\n");
                        }
                        break;
                    }
                case 2:
                    {
                        printf("How many notebooks do you want to buy?\n");
                        scanf("%d" ,&quantity);
                        if(quantity>0)
                        {
                            printf("You bought %d notebooks\n" ,quantity);
                            notebooks=notebooks+quantity;
                        }
                        else
                        {
                            printf("Sorry you have entered an invalid input\n");
                        }
                        break;
                    }
                case 3:
                    {
                        printf("How many erasers do you want to buy?\n");
                        scanf("%d" ,&quantity);
                        if(quantity>0)
                        {
                            printf("You bought %d erasers\n" ,quantity);
                            erasers=erasers+quantity;
                        }
                        else
                        {
                            printf("Sorry you have entered an invalid input\n");
                        }
                        break;
                    }
                case 4:
                    {
                        printf("How many pens do you want to remove?\n");
                        scanf("%d" ,&quantity);
                        if(quantity>0)
                        {
                            if(pens>=quantity)
                            {
                                printf("You removed %d pens\n" ,quantity);
                                pens=pens-quantity;
                            }
                            else
                            {
                                printf("You don't have enough pens to remove\n");
                            }      
                        }
                        else
                        {
                            printf("Sorry you have entered an invalid input\n");
                        }
                        break;
                    }
                case 5:
                    {
                        printf("How many notebooks do you want to remove?\n");
                        scanf("%d" ,&quantity);
                        if(quantity>0)
                        {
                            if(notebooks>=quantity)
                            {
                                printf("You removed %d notebooks\n" ,quantity);
                                notebooks=notebooks-quantity;
                            }
                            else
                            {
                                printf("You don't have enough notebooks to remove\n");
                            }      
                        }
                        else
                        {
                            printf("Sorry you have entered an invalid input\n");
                        }
                        break;
                    }
                case 6:
                    {
                         printf("How many erasers do you want to remove?\n");
                        scanf("%d" ,&quantity);
                        if(quantity>0)
                        {
                            if(erasers>=quantity)
                            {
                                printf("You removed %d erasers\n" ,quantity);
                                erasers=erasers-quantity;
                            }
                            else
                            {
                                printf("You don't have enough erasers to remove\n");
                            }      
                        }
                        else
                        {
                            printf("Sorry you have entered an invalid input\n");
                        }
                        break;
                    }
                case 7://display the bill
                    {
                        printf("\n============Bill============\n");
                        printf("Item\t\tQty\t\tPrice\t\tTotal\n");
                        printf("Pen\t\t%d\t\t%d\t\t%d\n",pens, pensprice, pens*pensprice);
                        printf("Notebook\t%d\t\t%d\t\t%d\n",notebooks, notebooksprice, notebooks*notebooksprice);
                        printf("Eraser\t\t%d\t\t%d\t\t%d\n",erasers, erasersprice, erasers*erasersprice);
                        printf("-----------------------------\n");
                        printf("Grand Total= %d\n",pens*pensprice+notebooks*notebooksprice+erasers*erasersprice);
                        break;
                    }
                default:
                    {
                        printf("Invalid choice!\n");
                    }
            }
        printf("\nEnter your choice (1-8) based on the menu options: ");
        scanf("%d",&selector);
    }
    printf("\t*****Thank you for shopping, %s. We look forward to your next visit!*****\n",firstname);
    return 0;
}