// Embedded C program to display 0 to 99 on 7 segment display
// by using Atmega32 microcontroller with Keil and Proteus combination.

#include <reg51.h>
// delay function
void delay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1275; j++)
            ; // delay loop
}

void main()
{
    // defining two arrays to be displayed on the two 7 segment anode
    unsigned char a[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90}; // array of values from 1 to 10
    unsigned char b[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
    int j, k;

    // infinity loop
    while (1)
    {

        for (j = 0; j <= 9; j++)
        {
            P0 = a[j];

            for (k = 0; k <= 9; k++) // Nested Loop
            {
                P1 = b[k];
                delay(132); // 1 second delay
            } // end of nested loop
        } // end of for loop
    } // end of infinity loop
} // end of main function
