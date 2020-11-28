
#include "pin_manager.h"
#include "mcc.h"

void PIN_MANAGER_Initialize(void)
{
    //configure ports below this line
    TRISAbits.TRISA0 = 1; //RA/0AN0 is an input
    TRISBbits.TRISB0 = 0; //RBO is output
    TRISBbits.TRISB1 = 0; //RB1 is output
    TRISBbits.TRISB2 = 0; //RB2 is output
    TRISBbits.TRISB3 = 0; //RB3 is output
    TRISBbits.TRISB4 = 0; //RB4 is output
    TRISBbits.TRISB5 = 0; //RB5 is output
    TRISBbits.TRISB6 = 0; //RB5 is output
    //RA0/AN0 is the only analog pin
    ADCON1bits.PCFG = 0xE; 
}

void PIN_MANAGER_IOC(void)
{
    
    
}

void PIN_MANAGER_INT0(void)
{
    
}

void PIN_MANAGER_INT1(void)
{
    
}

void PIN_MANAGER_INT2(void)
{
    
}