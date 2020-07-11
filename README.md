# Automatic-Water-Level-Controller

## Components used:
<ul>
  <li>Arduino Uno x 2</li>
  <li>9g Servo Motor</li>
  <li>HC-SR04</li>
  <li>433Mhz Transmitter and Receiver Module</li>
  <li>Buzzer</li>
  <li>LED</li>
</ul>
 
## SETUP:
Excuse me for the bad setup.
<img src="https://github.com/adimehta03/Automatic-Water-Level-Controller/blob/master/setup.jpeg" />
<img src="https://github.com/adimehta03/Automatic-Water-Level-Controller/blob/master/waterlevel.jpeg" />

## Explanation:

Based on the dimensions of the overhead tank(in my case, a bucket) I've written the code such that if the water level is more than 90% the transmitter sends a signal to the receiver, which turns on the led and triggers the buzzer and turns off the switch of the Water Pump via the servo motor. To be sure that my code is running perfectly I've logged the percentage of water on the serial monitor.

<img src="https://github.com/adimehta03/Automatic-Water-Level-Controller/blob/master/serial_com/serial3.jpeg" />

#### Date Created: 20 March, 2020
