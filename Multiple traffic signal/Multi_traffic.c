// 4. Multiple traffic signal programming for microcontroller using keil and proteus.

#include <reg51.h>
// First traffic light
sbit red1 = P1 ^ 7; // signed bit
sbit yellow1 = P1 ^ 6;
sbit green1 = P1 ^ 5;

// Second traffic light
sbit red2 = P1 ^ 4;
sbit yellow2 = P1 ^ 3;
sbit green2 = P1 ^ 2;

// Third traffic light
sbit red3 = P3 ^ 5;
sbit yellow3 = P3 ^ 6;
sbit green3 = P3 ^ 7;

// Fourth traffic light
sbit red4 = P3 ^ 4;
sbit yellow4 = P3 ^ 3;
sbit green4 = P3 ^ 2;

void main()
{
    unsigned int i;

    // Intially all traffic lights are off
    red1 = yellow1 = green1 = 0;
    red2 = yellow2 = green2 = 0;
    red3 = yellow3 = green3 = 0;
    red4 = yellow4 = green4 = 0;

    // Infinity Loop
    while (1)
    {

        green1 = green4 = 1;
        yellow1 = yellow2 = yellow3 = yellow4 = 0;
        red2 = red3 = 1;
        for (i = 0; i < 60000; i++)
            ; // delay of 6 seconds

        green1 = green4 = red2 = red3 = 0;
        yellow1 = yellow2 = yellow3 = yellow4 = 1;
        for (i = 0; i < 40000; i++)
            ; // delay of 4 seconds

        yellow1 = yellow2 = yellow3 = yellow4 = 0;
        red1 = red4 = 1;
        green2 = green3 = 1;

        for (i = 0; i < 60000; i++)
            ;
        red1 = red4 = green2 = green3 = 0;
        yellow1 = yellow2 = yellow3 = yellow4 = 1;

        for (i = 0; i < 40000; i++)
            ;

    } // end of Infinity Loop
} // end of main function
