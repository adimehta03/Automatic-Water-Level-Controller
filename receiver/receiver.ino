#include <VirtualWire.h>
#include <ServoTimer2.h>  

#define rollPin  7
int buzzer=9;
const int led_pin = 2;
const int transmit_pin = 12;
const int receive_pin = 11;
const int transmit_en_pin = 3;

ServoTimer2 servoRoll;

void setup()
{
    servoRoll.attach(rollPin);
    delay(1000);
    Serial.begin(9600);	
    Serial.println("setup");
    vw_set_tx_pin(transmit_pin);
    vw_set_rx_pin(receive_pin);
    vw_set_ptt_pin(transmit_en_pin);
    vw_set_ptt_inverted(true); 
    vw_setup(2000);	 
    vw_rx_start();      
    pinMode(led_pin, OUTPUT);
    pinMode(buzzer, OUTPUT); 
}
int incPulse(int val, int inc){
   if( val + inc  > 2000 )
      return 1000 ;
   else
       return val + inc;  
}

void loop()
{
    int val;
    
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    uint8_t buf[buflen];

    if (vw_get_message(buf, &buflen)) 
    {
	      int i;
	      Serial.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{
	    Serial.print(char(buf[i]));
	    Serial.print(' ');
      if(char(buf[8])=='0'){
        val = incPulse( servoRoll.read(), 1);
        servoRoll.write(val);
        digitalWrite(led_pin, HIGH);.
        delay(10); 
        tone(buzzer, 1000);
        delay(1000);       
        noTone(buzzer);    
        delay(1000);
        digitalWrite(led_pin, LOW);
      }
	}
	Serial.println();
    }
}
