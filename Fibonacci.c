//Midterm Fibonacci Number Generator
//Lew Piper III | Palomar ID 011263249

#include <stdio.h>
#include <stdlib.h>
void Fibonacci (int userInputNumber);
void UserInput (int* userInputNumber);

FILE *fpOut;
int main(int argc, const char * argv[]) {
    //Creating global variable for userInput to be passed from function to function
    int userInputNumber = 0;
    
    //Opening file for writing output to
    if (!(fpOut = fopen("csis.txt", "w"))) {
        printf("csis.text could not be opened for output");
        exit(1);
    }
    
    //Calling two functions and passing appropriate vaiables to each
    UserInput(&userInputNumber);
    Fibonacci(userInputNumber);
    
    fclose(fpOut);
    return 0;
}

void UserInput (int* userInputNumber) {
    //Asks the user for a number for the generator
    printf("Enter a number into the Fibonacci Generator: ");
    scanf("%d", &*userInputNumber);
    fprintf(fpOut,"Enter a number into the Fibonacci Generator: %d\n", *userInputNumber);
    
    //While the user continues to enter a negative number it forces the user to enter a new number
    while (*userInputNumber < 0) {
        printf("Invalid user input, enter a positive number\n\n");
        fprintf(fpOut,"Invalid user input, enter a positive number\n\n");
        printf("Enter a number into the Fibonacci Generator: ");
        scanf("%d", &*userInputNumber);
        fprintf(fpOut,"Enter a number into the Fibonacci Generator: %d\n", *userInputNumber);
    }
}

void Fibonacci (int userInputNumber) {
    //Defines variables used in this function
    int firstNumber, secondNumber, i, seriesNumber, length;
    firstNumber = 0;
    secondNumber = 1;
    seriesNumber = 0;
    i = 0;
    length = 0;
    
    //For loop that adds the two previous number in the series and prints it and then updates the previous numbers
    for (i = 0; seriesNumber < userInputNumber; i++) {
        if (i <= 1) {
            seriesNumber = i;
            length++;
        } else {
            seriesNumber = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = seriesNumber;
            length++;
        }
        
        //Statement to break the loop when the next number in the series goes above the user input
        if (seriesNumber > userInputNumber) {
            length -= 1;
            break;
        }
        
        //Printing the sequence
        printf("%d\n",seriesNumber);
        fprintf(fpOut,"%d\n",seriesNumber);
    }
    
    //Printing the length of the sequence
    printf("Length of the sequence: %d", length);
    fprintf(fpOut,"Length of the sequence: %d", length);
}