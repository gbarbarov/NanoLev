//Minimalist Ultra Sound Levitator
//by Gerardo Barbarov Rostán
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
*/

/*
This code is a simplification of the Asier Marzo version, no need to use external pins for synchronization 
and no delays with nops instructions.

This algorithm is optimized to use only a pair of ultrasonic transducers facing each other and an Arduino Nano,
using software interruptions
of an 80 kHz timer, and toggling the state of the pins.

If using  HC-SR04 sensor transducers, be sure to use the emission transducers with a T marked on the back.



                 A0  A1 
                _|___|_ 
               | +   - |
               |_______| 
              |
    1.5 cm    |    *    Node 1          
              |    *    Node 2
              | _______ 
               | +   - |
               |_______| 
                 |   | 
                A2   A3


*/

//Based on work of Asier Marzo 
//http://ieeexplore.ieee.org/document/8094247
//http://www.instructables.com/id/Acoustic-Levitator/

//Code timer interrupts by Amanda Ghassaei
//https://www.instructables.com/id/Arduino-Timer-Interrupts/


//storage variables
boolean toggle0 = 0;

void setup(){

DDRC = 0b00001111; //A0 to A3 are the signal outputs
PORTC = 0b00000000; 
 
cli();//stop interrupts

//set timer2 interrupt at 80kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  OCR2A = 24;//   (16*10^6) / (80000*8) - 1 (must be <256)   // set compare match register 
  TCCR2A |= (1 << WGM21);  // turn on CTC mode 
  TCCR2B |= (1 << CS21);    // Set CS21 bit for 8 prescaler 
  TIMSK2 |= (1 << OCIE2A);  // enable timer compare interrupt
  
  sei();//allow interrupts
  
} //end setup
  
ISR(TIMER2_COMPA_vect){//timer1 interrupt 80kHz toggles pin A0-A1 and A2-A3       
//generates pulse wave of frequency 80kHz/2 = 40kHz (takes two cycles for full wave)
 if (toggle0){
    PORTC=0x05; //01 01 outputs  
    toggle0 = 0;
  }
  else{
    PORTC=0x0A; //10 10 outputs 
    toggle0 = 1;
  }
}

void loop(){
 // don't waste your time , create things, happy coding
}
