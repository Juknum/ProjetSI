 //Julien CONSTANT
//TS1


//ENTREES :

//leds :
#include <Adafruit_NeoPixel.h>

#define PIN_LED 4  //broche connexion Din de l'Arduino 
#define LED_COUNT 10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN_LED, NEO_GRB + NEO_KHZ800);

int photodetect;
int diminution;

//radio
#include <RH_ASK.h> //dossier radio
#include <SPI.h>

RH_ASK rf_driver;

//SETUP :
void setup()
{
  Serial.begin(9600);
  Serial.println("Start Comunication");
  
  strip.begin(); //init des leds
  strip.show();
  
  rf_driver.init();
}

//EXE :
void loop()
{
  uint8_t buf[24];
  uint8_t buflen = sizeof(buf);
  
  photodetect = analogRead(0);
  diminution = photodetect*0.1; //On diminue la valeur de la photodiode pour détecter les plus grandes variations
  
  if (rf_driver.recv(buf, &buflen)) //Si signal recu
  {
    Serial.println("RECU");
    if (diminution >= 60) //Si cible touchee
    {
      Serial.println("toucher");

      strip.show();
      for (int i=0; i<strip.numPixels(); i ++)
      {
        long couleur = strip.Color(0, 255, 0);
        strip.setPixelColor(i, couleur);
      }
    }
    else //Si cible non touchee
    {
      Serial.println("pas toucher");
      
      strip.show();
      for (int  i=0; i<strip.numPixels(); i++)
      {
        long couleur = strip.Color(0, 0, 255);
        strip.setPixelColor(i, couleur);
      }
    }
  }
  else;
  {
    Serial.println("NON RECU"); //signal non recu
      
    strip.show();
    for (int  i=0; i<strip.numPixels(); i++)
    {
      long couleur = strip.Color(255, 0, 0);
      strip.setPixelColor(i, couleur);
    }
  }
  delay(1000);
}
