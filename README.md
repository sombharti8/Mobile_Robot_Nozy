
# Mobile_Robot_Nozy

To create a mobile robot that can connected through sim-card module. Using Arduino uno for processing that robot


## Introduction
This is an Arduino sketch that can be used to control a robotic car using a mobile phone. The code uses the SoftwareSerial library to communicate with a GSM module to receive incoming calls and to send DTMF (dual-tone multi-frequency) tones. Based on the DTMF tones received, the code controls the direction of the robot car.
## Setup
The sketch requires the following libraries to be installed in the Arduino IDE:
•	SoftwareSerial
You also need to connect the following pins on the Arduino board to the respective pins on the GSM module and motor driver:

•	GSM Module
1.	RX: Arduino pin 9
2.	TX: Arduino pin 10

•	Motor Driver
1.	Left motor direction control pins (FL1, FL2): Arduino pins 2, 3
2.	Right motor direction control pins (FR3, FR4): Arduino pins 8, 7
3.	Left motor speed control pin: Arduino pin 11
4.	Right motor speed control pin: Arduino pin 6
5.	Backward left motor direction control pin (BL3, BL4): Arduino pins 4, 5
6.	Backward right motor direction control pin (BR1, BR2): Arduino pins 13, 12


The sketch also expects you to enter your phone number in the phone_no variable.

## Usage
Once the setup is complete and the sketch is uploaded to the Arduino board, you can call the GSM module from your phone. When the call is received, the sketch will answer the call and start listening for DTMF tones. Depending on the DTMF tone received, the sketch will control the direction of the robot car as follows:
1.	Tone 2: Move forward
2.	Tone 4: Turn left
3.	Tone 6: Turn right
4.	Tone 8: Move backward
5.	Tone 5: Stop
6.	TOne 1: Cancel the call
