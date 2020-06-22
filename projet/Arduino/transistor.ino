//Entrées :
int button = 3;

//Sorties
int transistor = 4;

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
  pinMode(transistor, OUTPUT);
  
}

//execution
void loop() 
{
  const char *msg = "Welcome to the Workshop!";
  
  digitalWrite(transistor, HIGH);
  
  if (digitalRead(button) == HIGH)
  {
    Serial.println("button = HIGH");
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();

    digitalWrite(transistor, LOW);
    Serial.println(transistor);
    delay(50);
  }
}
