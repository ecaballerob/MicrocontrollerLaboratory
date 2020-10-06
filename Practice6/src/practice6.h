/* 
 * File:   practice6.h
 * Author: ecaballero
 *
 * Created on 6 de octubre de 2020, 01:26 PM
 */

#define _XTAL_FREQ 1000000
#define DELAY_SWEEP 300

void portInit(void);
void __interrupt(high_priority) high_isr(void);
void larsonDisplay(void);