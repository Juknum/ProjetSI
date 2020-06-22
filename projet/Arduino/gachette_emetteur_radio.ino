//Entrées :
int button = 7;
//int button_debug = 2;

//Sorties controle de l'alimentation de la pile
int transistor = 4;

//Modules radio
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

//Setup
void setup() 
{
  //init de l'écran interne
  Serial.begin(9600);
  Serial.println("Debut Com");

  //init de la radio
  rf_driver.init();

  //affectation des entrées/sorties
  pinMode(button, INPUT_PULLUP);
  //pinMode(button_debug, INPUT);
  pinMode(transistor, OUTPUT);
  
}

//execution
void loop() 
{
  //message envoyé
  const char *msg = "Welcome to the Workshop!"; 
  //phrase du tutoriel, n'influence pas le programme ou seul la transmission est nécessaire, pas le contenu

  digitalWrite(transistor, HIGH); //le transistor étant un normalement fermé il doit etre activé en permanence

  //if (digitalRead(button) == 0 or digitalRead(button_debug) == 1) 
  if (digitalRead(button) == 0) //si le signal passant dans le bouton est nulle (bouton appuyé)
  {
    Serial.println("Bouton pressé");
    rf_driver.send((uint8_t *)msg, strlen(msg)); //envoi du message
    rf_driver.waitPacketSent(); //attente du module radio

    digitalWrite(transistor, LOW); //on ferme le transistor
    Serial.println("Etat transistor:");
    Serial.println(transistor);
    delay(50); //delai de 50ms imposé par le cahier des charges
  }
}
