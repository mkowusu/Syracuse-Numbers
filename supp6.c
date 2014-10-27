/*****************************************************************
 * Michael Owusu                                                 *
 * Box:  4271                                                    *
 * Supplemental Problem 6 for CSC 161                            *
 * Assignment for before the end of the semester                 *
 *****************************************************************/

/* ***************************************************************
 * Academic honesty certification:                               *
 *                                                               *
 *   Written/online sources used:                                *
 *      none                                                     *
 *                                                               *
 *   Help obtained:                                              *
 *  Professor Walker: Further explanation about what he expected *
 *  out of this assignment. Expecially in terms of a             *
 *  manageable output.                                           *
 *                                                               *
 *   My signature below confirms that the above list of sources  *
 *   is complete AND that I have not talked to anyone else       *
 *   [e.g., CSC 161 students] about the solution to this problem *
 *                                                               *
 *   Signature:                                                  *
 *****************************************************************/


#include <stdio.h>

void calc(int a, int b){
    /*
     Preconditions:
     * a should be less than or equal to b.
     * both a and b must be in the range 1-2000 (inclusive).
     Postconditions:
     * Print out statement is the calculations to get from n to 1 for the specified range.
     * There are no more than 150 calculations for any number.
     * Numbers with more than 150 calculations are not proven to be Syracuse, but may be upon more speculation.
     * Program returns noting
     */
    
    // Declarations
    int n,j,i = 0;
    
    // implement specified range
    for (n=a; n<=b; n++)
    {
        printf("n of 0 = %d\n", n);
        j = n;
        i = 0;
        
        // no more than 150 calculations
        while (i < 150)
        {
            // Check 'Syracuse'
            while (j != 1)
            {
                if (j % 2 == 0)
                {
                    j = j/2;
                }
                else
                {
                    j = 3*j +1;
                }
                printf("n now = %d\n", j);
                // no more than 150 calculations
                if ( i == 150)
                {
                    printf("\nAfter 150 calculations this n has not reached 1. This number is a potential non-'Syracuse' number.\n\n");
                    break;
                }
                i++;
            }
            // verified 'Syracuse' number
            if (j == 1)
            {
                printf("\nn finally = %d\n", j);
                printf("\nand %d is therefore a 'Syracuse' number!\n\n", n);
                i = 150;
            }
            else
            {
                break;
            }
        }
        }
    }

int main()
{
    /*
     Preconditions:
     * a should be less than or equal to b.
     * both a and b must be in the range 1-2000 (inclusive).
     Postconditions:
     * Program must return 0
     */
    // declarations
    int a,b;
    
    // Simple intro and explanation of the program
    printf("Welcome!\n\n");
    sleep(1);
    printf("This program checks that all integers between 1 and 2000 inclusive are 'Syracuse'.\n\n");
    sleep(3);
    printf("To check if a number is 'Syracuse' this program divides n by 2 when n is even.\n");
    printf("If n is odd it is multiplied by 3 and incremented by 1.\n");
    printf("This process is repeated until n reaches 1.\n\n");
    sleep(5);
    printf("If after 150 calculations n does not equal 1, calculations for that number are stopped and that number is declared a potential non-'Syracuse' number. (Further calculations needed to prove it is indeed 'Syracuse').\n\n");
    sleep(5);
    printf("Now...\n\n");
    printf("Please select the range of numbers (1-2000 inclusive) you would like to check for 'Syracuse'.\n\n");
    printf("Select your starting number:\n");
    scanf("%d", &a);
    printf("Select your ending number:\n");
    scanf("%d", &b);
    // error if b is less than a
    if (b < a)
    {
        printf("Error! Starting value must be less than or equal to ending value!\n\n");
        return 0;
    }
    // Begin calculations
        printf("Beginning calculations...\n\n\n");
        calc(a, b);
    printf("\n\nEND PROGRAM.\n\n");
    return 0;
}