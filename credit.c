#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long ccNum;
    int digits;
    long ccNumCounter;
    long long validNum;
    int firstDigit;
    int remaind;
    int runningTotal;
    int multNum;
    long newCalcNum;
    int sumOne;
    int sumTwo;
    int lastDigit;

    //Get CC Number from user
    do
    {
        ccNum = get_long("Enter Credit Card Number: \n");
        ccNumCounter = ccNum;
    }
    while (ccNum < 0);

    //Counts the digits of the CC Number
    for (digits = 0; ccNumCounter > 0; digits++)
    {
        ccNumCounter = (ccNumCounter / 10);
    }
  
 
    //Determine if the number of digits is a valid length
    if (digits == 15 || digits == 13 || digits == 16)
    {
        validNum = ccNum;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
    
    //First part of the checksum
    for (int digitCounter = 0; digitCounter < digits / 2; digitCounter++)
    {
        if (digitCounter < 1)
        {
            remaind = validNum % 100;
            firstDigit = remaind / 10;
            multNum = firstDigit * 2;
            newCalcNum = validNum;
        }
        else 
        {
            remaind = newCalcNum % 100;
            firstDigit = remaind / 10;
            multNum = firstDigit * 2;
        }
        
        if (multNum > 9)
        {
            sumOne = multNum / 10;
            sumTwo = multNum % 10;
            runningTotal = runningTotal + sumOne + sumTwo;
            newCalcNum = newCalcNum / 100;
        }
        else 
        {
            runningTotal = runningTotal + multNum;
            newCalcNum = newCalcNum / 100;
        }
    }
    
    // Second part of the checksum
    for (int digitCounter2 = 0; digitCounter2 < digits / 2; digitCounter2++)
    {
        if (digitCounter2 < 1)
        {
            newCalcNum = validNum;
            lastDigit = validNum % 10;
            runningTotal = runningTotal + lastDigit;
            newCalcNum = newCalcNum / 100;
        }
        
        else 
        {
            lastDigit = newCalcNum % 10;
            runningTotal = runningTotal + lastDigit;
            newCalcNum = newCalcNum / 100;
        
            if (newCalcNum < 10)
            {
                runningTotal = runningTotal + newCalcNum;
            }
        }
    }
    long get_first = validNum;
    
    do
    {
        get_first = get_first / 10;
    }
    while (get_first > 100);
    
    // Final check & reporting of CC type, or if it's invalid
    if (runningTotal % 10 == 0)
    {
        if (digits == 15)
        {
            if (get_first == 34 || get_first == 37)
            {
                printf("AMEX\n");
            }
            else 
            {
                printf("INVALID\n");
            }
                
        }
        else if (get_first >= 40 && get_first <= 49)
        {
            if (digits == 13 || digits == 16)
            {
                printf("VISA\n");  
            }
            else 
            {
                printf("INVALID\n");
            }
                
        }
        else if (get_first >= 51 && get_first <= 55)
        {
            printf("MASTERCARD\n");
        }
            
        else
        {
            printf("INVALID\n");
            return 0;
        } 
            
    }
    else 
    {
        printf("INVALID\n");
        return 0;
    }
        
}