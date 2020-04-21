#include <Adafruit_NeoPixel.h>

#define PIN_LED 4  //broche connexion Din de l'Arduino 
#define LED_COUNT 10

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN_LED, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  //Allumer toutes les leds en vert
  for (int i=0; i<strip.numPixels(); i++) {
    long couleur = strip.Color(255, 255, 0);
    strip.setPixelColor(i, couleur);
  }
  strip.show();
  delay(1000);

  //Allumer toutes les leds en rouge
  for (int i=0; i<strip.numPixels(); i++) {
    long couleur = strip.Color(255, 0, 0);
    strip.setPixelColor(i, couleur);
  }
  strip.show();
  delay(1000);

  //Allumer toutes les leds en blanc
   for (int i=0; i<strip.numPixels(); i++) {
    long couleur = strip.Color(255, 255, 255);
    strip.setPixelColor(i, couleur);
  }
  strip.show();
  delay(1000);

  //Allumer toutes les leds en noir
   for (int i=0; i<strip.numPixels(); i++) {
    long couleur = strip.Color(0, 0, 0);
    strip.setPixelColor(i, couleur);
  }
  strip.show();
  delay(1000);
}
