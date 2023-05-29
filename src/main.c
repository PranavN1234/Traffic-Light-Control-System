#include <stdio.h>
#include "header1.h"

// We first define the different STATES

typedef enum
{
    BOTH_RED,
    NS_GREEN_EW_RED,
    NS_YEL,
    EW_GREEN_NS_RED,
    EW_YEL,

} State;

// The Pedestrian function takes in an input from the greenstates and then depending on whether the user presses from NS_Green or EW_Green will change that Yellow
void Pedestrian(int checkWhichGreen)
{
    // Logic for changing to Pedestrian Mode from NS_green
    if (checkWhichGreen == 1)
    {

        // Logic for Blinking
        for (int i = 0; i < 5; ++i)
        {
            setLED(NS_YELLOW, ON);
            delay(DELAY5);
            setLED(NS_YELLOW, OFF);
            delay(DELAY5);
        }
        // Configuring the LEDs
        setLED(NS_RED, ON);
        setLED(PED_GREEN, ON);
        setLED(PED_RED, OFF);
        delay(DELAY6);
        setLED(NS_RED, OFF);
        setLED(PED_GREEN, OFF);
        setLED(PED_RED, ON);
    }
    // Logic for changing to Pedestrian Mode from EW_green
    else
    {
        // Logic Blinking
        for (int i = 0; i < 5; ++i)
        {
            setLED(EW_YELLOW, ON);
            delay(DELAY5);
            setLED(EW_YELLOW, OFF);
            delay(DELAY5);
        }
        // Configuring the LEDs
        setLED(EW_RED, ON);
        setLED(PED_GREEN, ON);
        setLED(PED_RED, OFF);
        delay(DELAY6);
        setLED(EW_RED, OFF);
        setLED(PED_GREEN, OFF);
        setLED(PED_RED, ON);
    }

    return;
}

int main()
{

    int error = 0;

    // initital State
    State currentState = BOTH_RED;

    setupGPIO();

    while (!error)
    {

        switch (currentState)
        {

        case BOTH_RED:
            // We first turn on the Ped red, NS red and EW red for the initial state
            setLED(PED_RED, ON);
            setLED(NS_RED, ON);
            setLED(EW_RED, ON);
            delay(DELAY1);
            setLED(NS_RED, OFF);
            currentState = NS_GREEN_EW_RED;

            break;

        case NS_GREEN_EW_RED:
            setLED(NS_GREEN, ON);
            delay(DELAY2);
            setLED(NS_GREEN, OFF);

            // If pedestrian button is pressed then we call the function
            if (!checkBot(PB1))
            { // parameter signifies from which state it is going
                Pedestrian(1);
                currentState = NS_YEL;
                break;
            }
            currentState = NS_YEL;

            break;

        case NS_YEL:
            // Turning the NS Yellow normally
            setLED(NS_YELLOW, ON);
            delay(DELAY4);
            setLED(NS_YELLOW, OFF);
            setLED(NS_RED, ON);
            delay(DELAY3);
            currentState = EW_GREEN_NS_RED;
            break;

        case EW_GREEN_NS_RED:
            // We switch off the EW RED and open the EW Green
            setLED(EW_RED, OFF);
            setLED(EW_GREEN, ON);
            delay(DELAY2);
            setLED(EW_GREEN, OFF);
            if (!checkBot(PB1))
            {
                Pedestrian(0);
                currentState = EW_YEL;
                break;
            }
            currentState = EW_YEL;
            break;

        case EW_YEL:
            setLED(EW_GREEN, OFF);
            setLED(EW_YELLOW, ON);
            delay(DELAY4);
            setLED(EW_YELLOW, OFF);
            setLED(EW_RED, ON);
            currentState = BOTH_RED;
            break;
        }
    }

    return 0;
}