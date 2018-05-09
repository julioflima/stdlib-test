//Load the xc.h golibrary, globally,  to set the frequency configurations.  
#include <xc.h>

//Load the usart_pic16.h golibrary, locally,  to set and use the USART configurations.  
#include "usart_pic16.h"

//Load the stdlib.h golibrary, globally,  to use the functions.  
#include <stdlib.h>

#include <stdio.h>



// Configuration Byte
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

void testStdlib(uint8_t option);

void main()
{
    //Initialize USART with baud rate 9600.
    USARTInit(9600);

    //Write intro text
    USARTWriteLine("*****************************************************************************************************");
    USARTWriteLine("Welcome to the test of stdlib.h functions.");
    USARTWriteLine("Type one of those functions in below to enter in test of that function mode");  
    USARTWriteLine("1 - abs();");
    USARTWriteLine("2 - labs();");
    USARTWriteLine("3 - fabs();");
    USARTWriteLine("4 - ftoa();");
    USARTWriteLine("5 - itoa();");
    USARTWriteLine("6 - ltoa();");
    USARTWriteLine("7 - utoa();");
    USARTWriteLine("8 - atof();");
    USARTWriteLine("9 - atoi();");
    USARTWriteLine("10 - atol();");
    USARTWriteLine("11 - strtol();");
    USARTWriteLine("12 - xtoi();");
    USARTWriteLine("13 - rand();");
    USARTWriteLine("14 - srand();");
    USARTWriteLine("*****************************************************************************************************");
    USARTGotoNewLine();
    USARTGotoNewLine();

    //Declare the buffer;
    uint8_t buffer = 0;
    //Declare the content received;
    char content[2];
    while(1)
    {
        //Get the amount of data waiting in USART queue.
        uint8_t n= USARTDataAvailable();
        //If we have some data.
        if(n!=0)
        {
            uint8_t unit = 1;            
            uint8_t decimal = 10;

            char data=USARTReadData();
            //If enter pressed.
            if(data == '\r'){
                if(content[1] == 0){
                    unit = 0;
                    decimal = 1;
                }
                uint8_t option = (uint8_t)((content[0]-48)*decimal+(content[1]-48)*unit);
                testStdlib(option);
                USARTGotoNewLine();
                //Reset variables.
                buffer = 0;
                content[0] = 0;
                content[1] = 0;
            }
            else{
                //Storage data.
                content[buffer] = data;
                //Plot received data.
                USARTWriteChar(content[buffer]);
                //Increment buffer.
                buffer++;
            }                        
        }
    }
}

void testStdlib(uint8_t option){
    char buffer[70];
    for(char i = 0 ; buffer[0] != '\0' ; i++){
        buffer[i] = "";
    }
    switch(option){
    case 1:
        USARTWriteLine("You enter in the test of abs():");        
        USARTWriteLine("Returns the absolute value of as int x.");
        USARTWriteLine("If we do abs(-5), the return it's gonna be: ");
        sprintf(buffer, "%i", abs(-5));
        USARTWriteLine(buffer);
        USARTGotoNewLine();
    break;
    
    case 2:
        USARTWriteLine("You enter in the test of labs():");        
        USARTWriteLine("Returns the absolute value of as long x.");
        USARTWriteLine("If we do labs(-147483648), the return it's gonna be: ");
        sprintf(buffer, "%ld", labs(-147483648));
        USARTWriteLine(buffer);
        USARTGotoNewLine();
    break;
    
    case 3:
        USARTWriteLine("You enter in the test of fabs():");        
        USARTWriteLine("Returns the absolute value of as float x.");
        USARTWriteLine("If we do fabs(-45645.36545), the return it's gonna be: ");
        USARTWriteLine("sprintf(buffer, ""%ld"", fabs(-45645.36545));");      
        USARTWriteLine("/opt/microchip/xc8/v1.45/sources/common/fabs.c:4: error: (1098) conflicting declarations for variable ""_fabs"" (main.c:120)");
        USARTWriteLine("Not implemented in stdlib.");
        USARTGotoNewLine();
    break;
    
    case 4:
        USARTWriteLine("You enter in the test of ftoa():");
        USARTWriteLine("Converts an integer value to a null-terminated string using the specified base and stores the result in the array given by str parameter.");
        USARTWriteLine("If we pass the number 3.1415, the return it's gonna be: ");        
        USARTWriteLine("In decimal: ");
        //ftoa (3.1,buffer);
        USARTWriteLine(buffer);
        USARTWriteLine("Not working");
        USARTGotoNewLine();
    break;
    
    case 5:
        USARTWriteLine("You enter in the test of itoa():");
        USARTWriteLine("Converts an integer value to a null-terminated string using the specified base and stores the result in the array given by str parameter.");
        USARTWriteLine("If we pass the number 654, the return it's gonna be: ");        
        itoa (buffer,654,10);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer);
        itoa (buffer,654,16);
        USARTWriteLine("In hexadecimal: ");
        USARTWriteLine(buffer);
        itoa (buffer,654,2);
        USARTWriteLine("In binary: ");
        USARTWriteLine(buffer);
        USARTGotoNewLine();
    break;
    
    case 6:
        USARTWriteLine("You enter in the test of ltoa():");
        USARTWriteLine("Converts an long integer value to a null-terminated string using the specified base and stores the result in the array given by str parameter.");
        USARTWriteLine("If we pass the number -483648, the return it's gonna be: ");        
        ltoa (buffer,-483648,10);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer);
        ltoa (buffer,-483648,16);
        USARTWriteLine("In hexadecimal: ");
        USARTWriteLine(buffer);
        ltoa (buffer,-483648,2);
        USARTWriteLine("In binary: ");
        USARTWriteLine(buffer);
        USARTGotoNewLine();
    break;
    
    case 7:
        USARTWriteLine("You enter in the test of utoa():");
        USARTWriteLine("Converts an long integer value to a null-terminated string using the specified base and stores the result in the array given by str parameter.");
        USARTWriteLine("If we pass the number 483648, the return it's gonna be: ");        
        USARTWriteLine("In decimal: ");
        utoa (buffer,483648,10);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer);
        utoa (buffer,483648,16);
        USARTWriteLine("In hexadecimal: ");
        USARTWriteLine(buffer);
        utoa (buffer,483648,2);
        USARTWriteLine("In binary: ");
        USARTWriteLine(buffer);
        USARTWriteLine("Not working");
        USARTGotoNewLine();
    break;
    
    case 8:
        USARTWriteLine("You enter in the test of atoi():");
        USARTWriteLine("The string pointed to by the argument str is converted to an integer (type int).");
        USARTWriteLine("If the number cannot be converted, then 0 is returned.");
        USARTWriteLine("If we pass the number 2, the return it's gonna be: ");
        *buffer = "2.15";
        int value = atoi (buffer);
        char buffer_2[10];
        itoa (buffer_2,value,16);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer_2);
        USARTGotoNewLine();
        USARTWriteLine("Not working");
    break;
    
    case 9:
        USARTWriteLine("You enter in the test of atoi():");
        USARTWriteLine("The string pointed to by the argument str is converted to an integer (type int).");
        USARTWriteLine("If the number cannot be converted, then 0 is returned.");
        USARTWriteLine("If we pass the number 2, the return it's gonna be: ");
        *buffer = "2";
        int value = atoi (buffer);
        char buffer_2[10];
        itoa (buffer_2,value,16);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer_2);
        USARTGotoNewLine();
        USARTWriteLine("Not working");
    break;
    
    case 10:
        USARTWriteLine("You enter in the test of atol():");
        USARTWriteLine("The string pointed to by the argument str is converted to an integer (type long).");
        USARTWriteLine("If the number cannot be converted, then 0 is returned.");
        USARTWriteLine("If we pass the number 2, the return it's gonna be: ");
        *buffer = "2";
        int value = atol (buffer);
        char buffer_2[10];
        itoa (buffer_2,value,16);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer_2);
        USARTWriteLine("Not working");
        USARTGotoNewLine();
    break;
    
    case 11:
        USARTWriteLine("You enter in the test of strtol():");
        USARTWriteLine("The string pointed to by the argument str is converted to an integer (type long).");        
        USARTWriteLine("If the number cannot be converted, then 0 is returned.");
        USARTWriteLine("If we pass the number ""2261465 this is a test"", the return it's gonna be: ");
        *buffer = "2261465 this is a test";
        char *ptr;
        long value2;
        value2 = strtol (buffer, &ptr, 10);
        ltoa (buffer_2,value2,10);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer_2);
        USARTWriteLine("In string: ");
        USARTWriteLine(ptr);
        USARTWriteLine("Not working");
        USARTGotoNewLine();
    break;
    
    case 12:
          USARTWriteLine("You enter in the test of xtoi():");
        USARTWriteLine("The string pointed to by the argument str is converted to an integer (type long).");
        USARTWriteLine("If the number cannot be converted, then 0 is returned.");
        USARTWriteLine("If we pass the number 2, the return it's gonna be: ");
        *buffer = "2";
        int value = xtoi (buffer);
        char buffer_2[10];
        itoa (buffer_2,value,16);
        USARTWriteLine("In decimal: ");
        USARTWriteLine(buffer_2);
        USARTWriteLine("Not working");
        USARTGotoNewLine();
    break;
    
    case 13:
        USARTWriteLine("You enter in the test of rand():");
        USARTWriteLine("The C library function int rand(void) returns a pseudo-random number in the range of 0 to RAND_MAX.");
        ltoa (buffer,rand(),10);
        USARTWriteLine(buffer);
    break;
    
    case 14:
        USARTWriteLine("You enter in the test of srand():");
        USARTWriteLine("The C library function void srand(unsigned int seed) seeds the random number generator used by the function rand.");
        USARTWriteLine("If we seed them with 152, the return it's gonna be: ");
        srand((unsigned) 152);
        ltoa (buffer,rand(),10);
        USARTWriteLine(buffer);
        USARTGotoNewLine();
    break;
    
    default:
        USARTWriteLine("Type some valid option for the test.");
        USARTGotoNewLine();
        rand();
    break;
    }
}