# Automatic-Curtain-System
This project implements a sensor-driven curtain automation system using an Arduino Uno, LDR (Light Dependent Resistor), and an L293D H-bridge motor driver. The system supports both automatic and manual control modes.

Automatic Mode:
The LDR continuously senses ambient illumination. Its analog output is processed through the Arduino’s 10-bit ADC, where threshold-based decision logic determines whether to open or close the curtains. The L293D driver enables bi-directional control of the DC motor for curtain movement.

Manual Mode:
Two debounced push buttons provide user-controlled opening and closing. A slide switch allows seamless switching between manual and automatic modes without interrupting the control logic.


This project showcases concepts like analog signal acquisition, motor driver interfacing, threshold-based automation, and embedded system design for home automation applications.
