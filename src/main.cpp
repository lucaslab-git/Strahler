#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 60

#define PIN_PANEL_1 5
#define PIN_PANEL_2 17
#define PIN_PANEL_3 16
#define PIN_PANEL_4 4
#define PIN_PANEL_5 15

CRGB PANEL_1[NUM_LEDS];
CRGB PANEL_2[NUM_LEDS];
CRGB PANEL_3[NUM_LEDS];
CRGB PANEL_4[NUM_LEDS];
CRGB PANEL_5[NUM_LEDS];

#define POTI_R 13
#define POTI_G 12
#define POTI_B 14
#define POTI_H 11

int POTI_VALUES_NEW[3];
int POTI_VALUES_OLD[3];

void updateled(){
  for (size_t	 i = 0; i <= 60; i++)
  {
    PANEL_1[i] = CRGB(POTI_VALUES_NEW[0], POTI_VALUES_NEW[1], POTI_VALUES_NEW[2]);
    //PANEL_1[i] = CRGB(POTI_VALUES_NEW[0], POTI_VALUES_NEW[1], POTI_VALUES_NEW[2]);
    //PANEL_1[i]=  CRGB(POTI_VALUES_NEW[0], POTI_VALUES_NEW[1], POTI_VALUES_NEW[2]);
    //PANEL_1[i] = CRGB(POTI_VALUES_NEW[0], POTI_VALUES_NEW[1], POTI_VALUES_NEW[2]);
    //PANEL_1[i] = CRGB(POTI_VALUES_NEW[0], POTI_VALUES_NEW[1], POTI_VALUES_NEW[2]);
  } 
}

void setup() {
  Serial.begin(9600);

  FastLED.addLeds<WS2812B, PIN_PANEL_1>(PANEL_1, NUM_LEDS);
  //FastLED.addLeds<WS2812B, PIN_PANEL_2>(PANEL_2, NUM_LEDS);
  //FastLED.addLeds<WS2812B, PIN_PANEL_3>(PANEL_3, NUM_LEDS);
  //FastLED.addLeds<WS2812B, PIN_PANEL_4>(PANEL_4, NUM_LEDS);
  //FastLED.addLeds<WS2812B, PIN_PANEL_5>(PANEL_5, NUM_LEDS);

  POTI_VALUES_OLD[0] = map(analogRead(POTI_R), 0, 4095, 0, 255);
  POTI_VALUES_OLD[1] = map(analogRead(POTI_G), 0, 4095, 0, 255);
  POTI_VALUES_OLD[2] = map(analogRead(POTI_B), 0, 4095, 0, 255);
  POTI_VALUES_OLD[3] =  0;

}

void loop() {
  
  POTI_VALUES_NEW[0] = map(analogRead(POTI_R), 0, 4095, 0, 255);
  POTI_VALUES_NEW[1] = map(analogRead(POTI_G), 0, 4095, 0, 255);;
  POTI_VALUES_NEW[2] = map(analogRead(POTI_B), 0, 4095, 0, 255);;
  POTI_VALUES_NEW[3] = 3;
  
  
  for (int i = 0; i < 3; i++)
  {
    //Serial.println(POTI_VALUES_NEW[i]);
    if (POTI_VALUES_NEW[i] != POTI_VALUES_OLD[i])
    {
      POTI_VALUES_OLD[i] = POTI_VALUES_NEW[i];
      updateled();
    }
    
  }
  //Serial.println("--------");
  FastLED.show();
  //delay(500);
}