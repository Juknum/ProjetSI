int pinBouton = 7;
int etatBouton ;

void setup()
{
  pinMode(pinBouton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() 
{
  etatBouton = digitalRead(pinBouton);
  Serial.println(etatBouton);
}
