int buzzer =2;//borne de sortie

void setup() 
{
pinMode(buzzer,OUTPUT);// Définir la sortie du buzzer)
}

void loop() 
{
int i;// Définir 1 variable pour des boucles


While(1)
{

  for(i=0; i<80; i++)// Premier son de fréquence 
  {
    digitalWrite(buzzer,HIGH);// Faire du bruit
    delay(10);// Attendre 10 ms
    digitalWrite(buzzer,LOW);// Silence
    delay(10);// Attendre 10 ms
  }

  for(i=0; i<40; i++)// Deuxieme son a une autre fréquence
  {
    digitalWrite(buzzer,HIGH);// Faire du bruit 
    delay(20);// Attendre 20 ms
    digitalWrite(buzzer,LOW);// Silence
    delay(20);// Attendre 20 ms
  }   

}
}
