#include <cs50.h>
#include <stdio.h>
//global variable cardNumber set to 0
long cardNumber = 0;
long everyOtherDigitSum = 0;
int checkSum = 0;
int length = 0;
string cardType = "";

long promptInput()
{
    //asks user for number as long integer
    cardNumber = get_long("Number: ");
    return cardNumber;
}

void getLength()
{
    //sets lengthCheck variable to cardNumber
    long lengthCheck = cardNumber;
    //while cardnumber is still positive, length is increased by 1 while cardNumber gets divided by 10
    while (lengthCheck)
    {
        length++;
        lengthCheck/=10;
    }
    printf("Length: %i\n", length);
}

long multiplyEveryOtherDigit()
{
    //checkNumber variable equal puts cardNumber end digit as second-last
    long checkNumber = (cardNumber/10);
    //while loop checks if checkNumber is greater than 0 still
    while(checkNumber > 0)
    {
        //if the product of the digit is less than ten (ie. 1 digits)
        if (((checkNumber % 10)*2) < 10)
        {
            //adds the last number of checkNumber variable, muliplied by 2, to everyOtherDigitSum
            everyOtherDigitSum += ((checkNumber%10) * 2);
        }
        //else if the product of the digit is more than ten (ie. 2 digits)
        else
        {
            //new variable created to hold checked number
            int productOfLarge = ((checkNumber%10)*2);
            //while loop gives everyOtherDigitSum the value of each digit in product
            while(productOfLarge > 0)
            {
                everyOtherDigitSum += (productOfLarge % 10);
                productOfLarge /=10;
            }

        }
        //removes last two digits from checkNumber and repeats
        checkNumber /=100;
    }
    printf("Product of Every Other Digit: %li\n", everyOtherDigitSum);
    return everyOtherDigitSum;
}

void addSumToOtherDigits()
{
    long checkNumber2 = (cardNumber);
    int secondDigitSum = 0;

    while (checkNumber2 > 0)
    {
        //adds the last number of checkNumber variable, muliplied by 2, to everyOtherDigitSum
        secondDigitSum += ((checkNumber2%10));
        checkNumber2 /=100;
    }
    printf("Product of Non-Multiplied Digits: %i\n", secondDigitSum);
    checkSum = everyOtherDigitSum + secondDigitSum;
    printf("Check Sum: %i\n", checkSum);
}

void calculateCheckSum()
{
    multiplyEveryOtherDigit();
    addSumToOtherDigits();
    //if last number in digit is 0, returns digit and leaves function
    if ((checkSum % 10 == 0))
    {
        long first = cardNumber;
        long first2 = cardNumber;
        /* Remove last digit from number till only one digit is left */
        while (first >= 10)
        {
            first = first / 10;
        }
        printf("First digit = %li\n", first);

        while(first2 > 100)
        {
            first2 = first2 / 10;
        }
        printf("First 2 digits = %li\n", first2);

        if ((length == 13 || length == 16) && (first == 4)){
            cardType = "VISA";
            printf("%s\n", cardType);
        }
        else if
        (length == 16 && (first2 == 51 || first2 == 52 || first2 == 53 || first2 == 54 || first2 == 55)) {
            printf("MASTERCARD\n");
        }
        else if
        (length == 15 && (first2 == 34 || first2 == 37)) {
            printf("AMEX\n");
        }
        else
        {
            cardType = "INVALID";
            printf("%s\n", cardType);
        }
    }
    //otherwise, card type is INVALID
    else
    {
        cardType = "INVALID";
        printf("%s\n", cardType);
    }
}


int main()
{
    promptInput();
    getLength();
    calculateCheckSum();
}