// Libraries/headers section
#include "device_config.h"

// Directives section
#define _XTAL_FREQ 1000000
#define ONE_SECOND 1000

// Data Type section

enum port_dir {output, input}; // output = 0, input = 1
enum port_ACDC {digital, analog};// digital = 0, analog = 1
enum resistor_state {set_ON, res_ON};// set_ON = 0, res_ON = 1
enum led_state {led_OFF, led_ON};// led_OFF = 0, led_ON = 1
enum butto_state {pushed, no_pushed};// pushed = 0, no_pushed = 1


// ISR for high-priority
void __interrupt (high_priority ) high_isr ( void );

//ISR for low-priority
void __interrupt (low_priority) low_isr (void);

//Functions declaration
void portsInit( void );  // Ports configuration

// Main Section
void main(void){
    // Configuration
    portsInit();
    
    //Infinite Cycle
    while(1){
        // If button is pushed then:
        // Turn on the RA4 LED, otherwise turn off RA4 LED
        if(PORTBbits.RB4 == pushed) {  
            LATAbits.LATA7 = leds_OFF;
        } else {
            LATAbits.LATA7 = leds_ON;
        }

        LATAbits.LATA7 = leds_ON;
        __delay_ms(ONE_SECOND);     // Delay function XC8 Compiler
        LATAbits.LATA7 = leds_OFF;
        __delay_ms(ONE_SECOND);
    }
}

// Functions Section

//Ports configuration.
void portsInit(void){
    // Set PORTA as digital port also set RA4 and RA7 as output
    ANSELA = digital;
    TRISAbits.TRISA4 = output;
    TRISAbits.TRISA7 = output;
    
    // Set PORTB as digital port also set RA4 as input 
    ANSELB = digital;
    TRISBbits.TRISB4 = input;

}
