#include <VirtualWire.h>
int trig = 13;
int echo = 12;
const int transmit_pin = 12;
const int receive_pin = 2;
const int transmit_en_pin = 3;

void setup()
{
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    vw_set_ptt_inverted(true); 
    vw_setup(2000);     
    pinMode(trig, OUTPUT); 
    pinMode(echo, INPUT);   
}

void loop()
{
  long t = 0, h = 0, hp = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
 
  t = pulseIn(echo, HIGH);
  
  h = t/22.6;//height of the bucket=22.6cm
  //h=distance of the water from the sensor
  h = h - 6;  //here 6=radius of the bucket
  //max of h here = 50
  h = 50 - h; //here h<=50 
  
  hp = 2 * h;//percentage of water
  char msg[9] = {'w','a','t','e','r',' ','%',' ','=',' '};
  if(hp>=0 && hp<=100){
    delay(1000);
    msg[8]=1;
    if(hp>=90 && hp<=100){
       msg[8]=0;
      }
  }vw_send((uint8_t *)msg, 9);
  vw_wait_tx(); 
  delay(1000);
}
