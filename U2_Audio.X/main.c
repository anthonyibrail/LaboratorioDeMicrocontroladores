/*
 * File:   main.c
 * Author: Anthony
 *
 * Created on 5 de octubre de 2020, 10:03 AM
 */

// PIC18F45K50 Configuration Bit Settings

// 'C' source line config statements


// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = INTOSC_HS // Oscillator Selection bits (Internal oscillator, HS oscillator used by USB (INTHS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ  4000000ul

const int A_LA = 1136;    //1136us - 440Hz
const int B_SI = 1012;    //1012us - 493.88Hz        
const int C_DO = 1911;    //1911us - 261.63Hz
const int D_RE = 1703;    //1703us - 293.66Hz
const int E_MI = 1517;    //1517us - 329.63Hz    
const int F_FA = 1432;    //1432us - 349.23Hz
const int G_SOL = 1276;   //1276us - 392Hz

int s_corchea = 15, corchea = 30, fusa = 6;
long negra = 50, blanca = 10, redonda = 20;

void tono_LA(int duracion);
void tono_SI(int duracion);
void tono_DO(int duracion);
void tono_RE(int duracion);
void tono_MI(int duracion);
void tono_FA(int duracion);
void tono_SOL(int duracion);
void canciones(int cancion);

void main(void){
    
    TRISB = 0xFE;
    ADCON1bits.PCFG = 0xF;
    
    while(1){
    
        if(PORTBbits.RB1 == 1){
            negra = 50;
            blanca = 10;
            canciones(3);
        }
        if(PORTBbits.RB2 == 1){
            negra = 45;
            blanca = 9;
            canciones(3);
        }
        if(PORTBbits.RB3 == 1){
            negra = 40;
            blanca = 8;
           canciones(3);
        }
        if(PORTBbits.RB4 == 1){
            negra = 35;
            blanca = 7;
           canciones(3);
        }
        if(PORTBbits.RB5 == 1){
            negra = 30;
            blanca = 6;
           canciones(3);
        }
        if(PORTBbits.RB6 == 1){
            negra = 25;
            blanca = 5;
           canciones(3);
        }
        if(PORTBbits.RB7 == 1){
            canciones(4);
        }
    }
    //return;
}

void tono_LA(int duracion){
    
    do{
        PORTBbits.RB0 = 1;      // Altavoz encendido
        __delay_us(A_LA);             // espera  uS
        PORTBbits.RB0 = 0;      // Altavoz encendido
        __delay_us(A_LA);             // Nota SOL
        
        duracion--;
        
    }while(duracion>0);
}

void tono_SI(int duracion){
    
    do{
        PORTBbits.RB0 = 1;      // Altavoz encendido
        __delay_us(B_SI);             // espera 1276 uS
        PORTBbits.RB0 = 0;      // Altavoz encendido
        __delay_us(B_SI);             // Nota SOL
        
        duracion--;
        
    }while(duracion>0);
}

void tono_DO(int duracion){
    
    do{
        PORTBbits.RB0 = 1;      // Altavoz encendido
        __delay_us(C_DO);             // espera 1276 uS
        PORTBbits.RB0 = 0;      // Altavoz encendido
        __delay_us(C_DO);             // Nota SOL
        
        duracion--;
        
    }while(duracion>0);
}

void tono_RE(int duracion){
    
    do{
        PORTBbits.RB0 = 1;      // Altavoz encendido
        __delay_us(D_RE);             // espera 1276 uS
        PORTBbits.RB0 = 0;      // Altavoz encendido
        __delay_us(D_RE);             // Nota SOL
        
        duracion--;
        
    }while(duracion>0);
}

void tono_MI(int duracion){
    
    do{
        PORTBbits.RB0 = 1;      // Altavoz encendido
        __delay_us(E_MI);             // espera 1276 uS
        PORTBbits.RB0 = 0;      // Altavoz encendido
        __delay_us(E_MI);             // Nota SOL
        
        duracion--;
        
    }while(duracion>0);
}

void tono_FA(int duracion){
    
    do{
        PORTBbits.RB0 = 1;      // Altavoz encendido
        __delay_us(F_FA);             // espera 1276 uS
        PORTBbits.RB0 = 0;      // Altavoz encendido
        __delay_us(F_FA);             // Nota SOL
        
        duracion--;
        
    }while(duracion>0);
}

void tono_SOL(int duracion){
    
    do{
        PORTBbits.RB0 = 1;      // Altavoz encendido
        __delay_us(G_SOL);             // espera 1276 uS
        PORTBbits.RB0 = 0;      // Altavoz encendido
        __delay_us(G_SOL);             // Nota SOL
        
        duracion--;
        
    }while(duracion>0);
}
void canciones(int cancion){
    switch(cancion){
        case 1:
            tono_SOL(negra);
            __delay_ms(10);
            tono_SOL(negra);
            __delay_ms(10);
            tono_SOL(negra);
            __delay_ms(10);
            tono_DO(negra);
            __delay_ms(10);
            tono_MI(negra);
            //__delay_ms(10);
            tono_SOL(negra);
            __delay_ms(10);
            tono_SOL(negra);
            __delay_ms(10);
            tono_SOL(negra);
            __delay_ms(10);
            tono_DO(negra);
            __delay_ms(10);
            tono_MI(negra);
            //__delay_ms(10);
            tono_DO(negra);
            __delay_ms(10);
            tono_DO(negra);
            __delay_ms(10);
            tono_SI(negra);
            __delay_ms(10);
            tono_SI(negra);
            __delay_ms(10);
            tono_LA(negra);
            __delay_ms(10);
            tono_LA(negra);
            __delay_ms(10);
            tono_SOL(negra);
            //__delay_ms(10);
            tono_SOL(negra);
            tono_SOL(negra);
            tono_SOL(negra);
            tono_SI(negra);
            tono_RE(negra);
            //__delay_ms(10);
            tono_SOL(negra);
            tono_SOL(negra);
            tono_SOL(negra);
            tono_SI(negra);
            tono_RE(negra);
            //__delay_ms(10);
            tono_SOL(negra);
            tono_LA(negra);
            tono_SOL(negra);
            tono_FA(negra);
            tono_MI(negra);
            tono_RE(negra);
            __delay_ms(10);
            tono_DO(negra);
        break;
        
        case 2:
            tono_RE(negra);
            tono_RE(negra);
            //__delay_ms(100);
            tono_SOL(negra);
            tono_SOL(corchea);
            tono_FA(negra);
            tono_SOL(negra);
            //__delay_ms(100);
            tono_LA(negra);
            tono_FA(corchea);
            tono_SOL(negra);
            tono_LA(negra);
            //__delay_ms(100);
            tono_SI(negra);
            tono_SOL(corchea);
            tono_LA(negra);
            tono_SI(negra);
            tono_DO(blanca);
            tono_DO(negra);
            tono_DO(negra);
            //__delay_ms(100);
            tono_SI(negra);
            tono_LA(corchea);
            tono_SOL(negra);
            tono_FA(negra);
            //__delay_ms(100);
            tono_LA(negra);
            tono_SOL(negra);
            tono_FA(negra);
            tono_SOL(negra);
            tono_LA(negra);
            //__delay_ms(100);
            tono_SI(negra);
            tono_DO(negra);
            tono_LA(negra);
            //__delay_ms(100);
            tono_SOL(blanca);
            tono_RE(negra);
        break;
        
        case 3:
            tono_DO(negra);
            tono_DO(negra);
            tono_SOL(negra);
            tono_SOL(negra);
            //__delay_ms(100);
            tono_LA(negra);
            tono_LA(negra);
            tono_SOL(blanca);
            tono_FA(negra);
            tono_FA(negra);
            tono_MI(negra);
            tono_MI(negra);
            //__delay_ms(100);
            tono_RE(negra);
            tono_RE(negra);
            tono_DO(blanca);    
        break;
        
        case 4:
            
        break;
    }
}