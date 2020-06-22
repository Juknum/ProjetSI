//Julien CONSTANT
//TS1


//ENTREES :
//leds :
#include <Adafruit_NeoPixel.h>

#define PIN_LED 4  //broche connexion Din de l'Arduino 
#define LED_COUNT 10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN_LED, NEO_GRB + NEO_KHZ800);



//radio
#include <RH_ASK.h> //dossier radio
#include <SPI.h>

RH_ASK rf_driver;

//SORTIES :
//buzzer :
int buzzer = 2;

//AUTRES VARIABLES:
int L = -1; // compteur led
int toucher = 0;
int photodetect;
int diminution;

//SETUP :
void setup()
{
  //init de l'écran interne
  Serial.begin(9600);
  Serial.println("Start Comunication");

  //init des leds
  strip.begin(); 
  strip.show();

  //init de la radio
  rf_driver.init();

  //affectation des entrées/sorties
  pinMode(buzzer, OUTPUT);
}

//LEDS SCORE:
void ledcount(int toucher)
{
  if (toucher == 1) //si la cible est touchée
  {
    if (L != 9) //si le score n'est pas égale à 9
    {
      Serial.println("toucher et ajout");
      Serial.println(L);
      L = L + 1; //alors on ajoute 1
      Serial.println(L);
      long couleur = strip.Color(0, 0, 255);
      strip.setPixelColor(L, couleur); // et on allume la led indiquant le score
    }
    else // si supérieur aux nombres de leds
    {
      L = 0; //on remet le score à zero
      for (int i=0; i<strip.numPixels(); i ++)
        {
          long couleur = strip.Color(0, 0, 255);
          strip.setPixelColor(i, couleur);
        }
      Serial.println("Reset de L");
      Serial.println(L);
    }
  }
  if (toucher == 0) // le joueur n'a pas touché la cible, le score n'avance pas
  {
    Serial.println("non touché et stabilisation");
    Serial.println(L);
    long couleur = strip.Color(0, 0, 255);
    strip.setPixelColor(L, couleur);
  }
}

//EXE :
void loop()
{
  int j; //variable lambda

  //buffer pour la radio
  uint8_t buf[24];
  uint8_t buflen = sizeof(buf);

  //photo diode (détection du laser)
  photodetect = analogRead(1);
  diminution = photodetect*0.1; //On diminue la valeur de la photodiode pour détecter les plus grandes variations
  Serial.println(diminution);
  
  if (rf_driver.recv(buf, &buflen)) //Si signal recu on affiche les leds en vert et on exe la boucle points avec 1
  {
    Serial.println("RECU");
    if (diminution >= 60) //Si cible touchee
    {
      Serial.println("touché");

      strip.show();
      for (int i=0; i<strip.numPixels(); i ++)
      {
        long couleur = strip.Color(0, 255, 0);
        strip.setPixelColor(i, couleur);
      }
      for(j=0; j<20; j++)
      {
        digitalWrite(buzzer,HIGH);// Faire du bruit
        delay(10);// Attendre 10 ms
        digitalWrite(buzzer,LOW);// Silence
        delay(10);// Attendre 10 ms
      }
      ledcount(toucher = 1);
    }
    else //Si cible non touchee on affiche les leds en rouge et on exe la boucle points avec 0
    {
      Serial.println("non touché");
      
      strip.show();
      for (int  i=0; i<strip.numPixels(); i++)
      {
        long couleur = strip.Color(255, 0, 0);
        strip.setPixelColor(i, couleur);
      }
      for(j=0; j<10; j++)
      {
        digitalWrite(buzzer,HIGH);// Faire du bruit 
        delay(20);// Attendre 20 ms
        digitalWrite(buzzer,LOW);// Silence
        delay(20);// Attendre 20 ms
      }
      ledcount(toucher = 0);
    }
  }
  else;
  {
    //Serial.println("NON RECU"); //signal non recu
      
    strip.show(); //donc on affiche les leds en violet hormis la led des points
    for (int  i=0; i<strip.numPixels(); i++)
    {
      long couleur = strip.Color(255, 0, 255);
      strip.setPixelColor(i, couleur);
    }
    long couleur = strip.Color(0, 0, 255);
    strip.setPixelColor(L, couleur);
  }
  delay(1000); //temps entre chaque tir minimum
}
