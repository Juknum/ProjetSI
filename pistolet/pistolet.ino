//Entrées :
const int button = 2;

#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

//Setup
void setup() 
{
  Serial.begin(9600);
  Serial.println("Debut Com");

  rf_driver.init();
  
  pinMode(button, INPUT);
  
}

//execution
void loop() 
{
  int btn = digitalRead(button);
  const char *msg = "Welcome to the Workshop!";

  if (btn == HIGH)
  {
    Serial.println("Btn = HIGH");
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
  }
}

