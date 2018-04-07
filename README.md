# NanoLev
Minimalist ultrasound levitator

This code is a simplification of the minilev.ino Asier Marzo version (http://www.instructables.com/id/Acoustic-Levitator/).

This algorithm is optimized to use only a pair of ultrasonic transducers facing each other and an Arduino Nano, using software interruptions of an 80 kHz timer, and toggling the state of the pins.

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
                
                
                Connect one transducer to A0 and A1; and another transducer to A2 and A3.

Put the transducers opposite to each other to levitate a particle between them, it is easier to place the particle with a metallic grid.

You can use 3D-printed case designed by IB-as https://www.tinkercad.com/things/9uXNA47qORj#/
