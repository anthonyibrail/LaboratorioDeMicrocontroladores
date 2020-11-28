/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC18F4550
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc.h"
#include "stdio.h"
#include "stdlib.h"
#include <xlcd.h>

/*
                         Main application
 */

unsigned char D_Buffer[2];
unsigned char buffer[5];
unsigned int repeticion = 1;
unsigned int puntos = 0;
unsigned int posDrive;
unsigned int posEnemy;
unsigned int posEne1 = 20;
unsigned int posEne2 = 92;

void marcador(){
         
        if (repeticion <= 15){                                    
            if(repeticion == 1){
                PORTBbits.RB0 = 1;
            }
                    
            puntos = puntos++;
            __delay_ms(167);
            repeticion++;
            if(repeticion == 15){
                PORTBbits.RB0 = 0;
                PORTBbits.RB1 = 1;

            }
        }
        if (repeticion > 15 && repeticion <= 30){
            puntos = puntos + 2;
            __delay_ms(167);
            repeticion++;
            if(repeticion == 30){
                PORTBbits.RB1 = 0;
                PORTBbits.RB2 = 1;
            }
        }
        if (repeticion > 30 && repeticion <= 45){
            puntos = puntos + 3;
            __delay_ms(167);
            repeticion++;
            if(repeticion == 45){
                PORTBbits.RB2 = 0;
                PORTBbits.RB3 = 1;
            }
            
        }
        if(repeticion > 45 && repeticion <= 60){
            puntos = puntos + 4;
            __delay_ms(167);
            repeticion++;
            if(repeticion == 60){
                PORTBbits.RB3 = 0;
                PORTBbits.RB4 = 1;
            }
        }
        if (repeticion > 60 && repeticion <= 75){
            puntos = puntos + 5;
            __delay_ms(167);
            repeticion++;
            if(repeticion == 75){
                PORTBbits.RB4 = 0;
                PORTBbits.RB5 = 1;
            }
        }
        if (repeticion > 75 && repeticion <= 90){
            puntos = puntos + 6;
            __delay_ms(167);
            repeticion++;
            if(repeticion == 90){
                PORTBbits.RB5 = 0;
                PORTBbits.RB6 = 1;
            }
        }
        
}

void restarPuntos(){        
    if (repeticion <= 15){                                    
            puntos = puntos--;
        }
        if (repeticion > 15 && repeticion <= 30){
            puntos = puntos - 2;
        }
        if (repeticion > 30 && repeticion <= 45){
            puntos = puntos - 3;
        }
        if(repeticion > 45 && repeticion <= 60){
            puntos = puntos - 4;
        }
        if (repeticion > 60 && repeticion <= 75){
            puntos = puntos - 5;
        }
        if (repeticion > 75 && repeticion <= 90){
            puntos = puntos - 6;
        }
        
}

void enemigo1(){
    
        while(BusyXLCD());
        SetDDRamAddr(posEne1);

        while(BusyXLCD());
        putrsXLCD("O");     

}

void enemigo2(){
    
        while(BusyXLCD());
        SetDDRamAddr(posEne2);

        while(BusyXLCD());
        putrsXLCD("O");     
}

void drive(){
    
    while(repeticion <= 90){
        if(ADC_Flag == 1){
            
            //Start reading ADC value 
            ADC_Flag = 0;
            ADC_StartConversion(0);
            
            //Print Baches
            enemigo1();
            enemigo2();
            
                if(ADC_Value > 511){
                    
                    posDrive = 64;
                    while(BusyXLCD());
                    SetDDRamAddr(posDrive);

                    while(BusyXLCD());
                    putrsXLCD(">");     
                    
                    marcador();
                    
                    if(posEne1 > 0){
                        posEne1--;
                    }
                    else{
                        posEne1 = 15;
                    }
                    
                    if(posEne2 > 64){
                        posEne2--;
                    }
                    else{
                        posEne2 = 79;
                    }
                    
                    if(posDrive == posEne2){
                        restarPuntos();
                    }

                }
                else{
                    posDrive = 0;
                    
                    while(BusyXLCD());
                    SetDDRamAddr(posDrive);
                    
                    sprintf(D_Buffer, ">");
                    while(BusyXLCD());
                    putsXLCD(D_Buffer); 
                    
                    marcador(); 
                    
                    if(posEne1 > 0){
                        posEne1--;
                    }
                    else{
                        posEne1 = 15;
                    }
                    
                    if(posEne2 > 64){
                        posEne2--;
                    }
                    else{
                        posEne2 = 79;
                    }
                    
                    if(posDrive == posEne1){
                        restarPuntos();
                    }
                }
            }
        
        //Clean LCD 
        while(BusyXLCD()); 
        WriteCmdXLCD(0x01);
    }
    
    //Print Score
    while(BusyXLCD());
    SetDDRamAddr(75);
       
    sprintf(buffer, "P:%d", puntos);
    while(BusyXLCD());
    putsXLCD(buffer);
    __delay_ms(1000);
    
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //start first ADC conversion with AN0
    ADC_StartConversion(0);
    
    while (1)
    {
        drive();
    }
}

/**
 End of File
*/