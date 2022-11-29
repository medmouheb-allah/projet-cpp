
#include <DFRobot_DHT11.h>

char data;
#define ventilo  11 
#define temp_pin 2  
DFRobot_DHT11 DHT;


  

void setup() 
{
  pinMode(ventilo,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{

if (Serial.available())
  {      
    data=Serial.read();  
    
     if(data=='1') 
    { 
      DHT.read(temp_pin);
      Serial.print(DHT.temperature);

    
    }
     else if ( data == '2')
    {
      digitalWrite(ventilo,HIGH);
    }

     else if ( data =='3')
    {
      digitalWrite(ventilo,LOW);
    }


 }


}
