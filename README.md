# Password-based-Door-Lock-System
(Done as a semester project for the course 'Microprocessors and Computer Architecture')

This project is a password-based door lock system implemented using Arduino Uno microcontroller. The system utilizes a 4x3 keypad, a 10k potentiometer, a 16x2 i2c LCD display, a servo motor, a 5V active buzzer and 3 kinds of connecting wires.  

The system requires the user to enter a correct password on the keypad to unlock the door. On correct entry, the servo motor turns and the LCD display shows a welcome message. If the user enters the wrong password, they are allowed to retry up to three 
times. 

On the third unsuccessful attempt, the buzzer sounds and an appropriate message is displayed on the LCD.  

The project uses Arduino's digital input/output pins and libraries to interface the components.   

The keypad is connected to the digital pins on the Arduino, and the LCD display is connected via the i2c bus. The servo motor is controlled by the Arduino using a PWM signal, and the 5V active buzzer is connected to a digital output pin. The potentiometer is connected to the LCD display to adjust the contrast.  

The system is designed to provide a simple and secure method of access control using Arduino microcontroller and basic electronic components. It can be used for home security, office access control, or any other application requiring password-based authentication.

## Circuit Diagram:
![image](https://github.com/sreenidhi-n/Password-based-Door-Lock-System/assets/95966587/3dbeb49e-72fc-4cc7-98b3-74009d88e3f0)

## Connections:   

LCD - Arduino  

GND - gnd  

VCC – 5V  

SDA - A4  

SCL - A5  




Keypad - Arduino  

    R1 – Pin 8  
    
    R2 – Pin 7  
    
    R3 – Pin 6  
    
    R4 - Pin 5  
    
    C1 - Pin 4  
    
    C2 – Pin 3  
    
    C3 – Pin 2  
    

  
Buzzer - Arduino  

    Positive (+) – Pin 10  
    
    Negative (-) - gnd   
    

  
Servo - Arduino  

    Ground Wire (Brown) - gnd  
    
    Power Wire (Red) – 5V  
    
    Signal Wire (Orange) – 9
