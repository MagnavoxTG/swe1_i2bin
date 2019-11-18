#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int x = 0;
    char intreadout[255], bin_array[255];
    long long int number = 0;
    int counter = 0;

    while (x != 1) {
        // printf shows a message asking you to enter a positive number
        printf("\nPlease enter a positive number (f.e. 202): ");
        //scanf writes the input into a string (char array)
        scanf("%s", intreadout);
        //gets(intreadout);
        // strspan checks how many of the specified character are inside the string and gives an integer
        // strlen checks how long the string (char array) is and gives an integer
        // if they are the same then there are only allowed characters in the string
        if (strspn(intreadout, "0123456789") == strlen(intreadout)) {
            number = (long long int)atoll(intreadout);

            //goes through every number one by one divides it by 16 takes the remainder and uses the defined HEX to assign the correct symbol
            while(number)
            {

                bin_array[counter] = number % 2;

                counter++;
                number /= 2;
            }
            // write the end of string symbol into the string
            bin_array[counter] = '\0';

            char bin_array_inverted[counter];

            // inverts the array
            for (int c = 0; c < counter; c++){
                bin_array_inverted[c] = bin_array[counter - (1+c)];
            }

            for (int c = 0; c < counter; c++) {
                putc(bin_array_inverted[c],stdout);
            }
            // prints result
            //printf("Your number in Binary: %s", bin_array_inverted);

            //breaks while
            x = 1;
        } else {
            printf("invalid input");
        }
    }
}