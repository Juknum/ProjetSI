# Pistolet Laser - Projet SI - Terminale SSI
Réalisation d'un pistolet laser, détection du tir et si la cible a été touchée  

Membres du projet :
- Enzo Allamassey  
- Julien Constant  
- Pierre Renault  

## Pré-requis :
- Arduino pour pouvoir load les programmes  
- 2 modules Arduino Uno  
- Matériel d'électronique  

## Documentations : 
- Base Arduino : [ici](https://www.supinfo.com/articles/single/2721-bases-programmation-arduino)
- Module Radio : [ici](https://simple-duino.com/arduino-et-radiofrequence/)

## Informations :
Les bibliothèques présentes dans `/ressources` sont nécessaires au bon fonctionnement des programmes. Le fusil laser a été entièrement imprimé par nos soins selon une arme réelle, tout en retirant le percuteur de cette dernière. Le laser est un laser de classe III utilisé dans la chasse et le domaine du tir.

## But du programme :
L'utilisateur actionne le levier afin de mettre sous tension le laser, il vise la cible et appui sur la gachette. Dès lors, la gachette appuye sur un bouton activant à l'aide d'un transitor, le laser présent dans le canon du pistolet et envoyant un message radio.  
La cible cherche en permanence si elle reçoit un signal lumineux et radio, si les deux sont positifs, alors la barre de Leds s'incrémente, si le tir est manqué (aucune détection de changement de luminosité avec la photodiode), le buzzer retentit et les leds s'allume en rouge.

N'hésitez pas à me MP pour plus d'informations sur ce projet !

> Note obtenue au bac de SI : `15/20`
