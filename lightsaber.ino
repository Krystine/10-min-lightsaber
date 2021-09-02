#include <Adafruit_NeoPixel.h>

/* USER DEFINES */
#define PIN             0           /* Using pin 0 on the Trinket m0 board */
#define NUM_PIXELS      7           /* Number of pixels on the NeoPixel strip (7 in this case for a Jewel) */
#define DELAY           75          /* Delay between color shifts (in ms) */

/* USER GLOBAL CONSTANTS */
const uint32_t RED    = 0x00FF0000; /* WRGB */
const uint32_t GREEN  = 0x0000FF00; /* WRGB */
const uint32_t BLUE   = 0x000000FF; /* WRGB */
const uint32_t PURPLE = 0x00FF00FF; /* WRGB */
const uint32_t TEAL   = 0x00009999; /* WRGB */
const uint32_t WHITE  = 0xFFFFFFFF; /* WRGB */
const uint32_t OFF    = 0x00000000; /* WRGB */

/*
 * Create the pixel object as global.
 *      NUM_PIXELS:     Number of pixels in the NeoPixel strip 
 *      PIN:            Pin connecting to "Data Input" on the NeoPixel
 *      NEO_WRGB:       The order of expected colors - white, red, green, then blue
 */
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRBW + NEO_KHZ800);
 
void setup()
{
    pixels.begin();
    pixels.setBrightness(255); // 0-255
    startup_colors();
}

void loop()
{
    /* EMPTY :) */
}

void startup_colors()
{
    for(uint16_t i = 1; i < NUM_PIXELS; i++)
    {
        pixels.setPixelColor(i, PURPLE);
        pixels.show();
        delay(DELAY);
        pixels.setPixelColor(i, OFF);
    }

    for(uint16_t j = 1; j < NUM_PIXELS; j++)
    {
        pixels.setPixelColor(j, TEAL);
        pixels.show();
        delay(DELAY);
        pixels.setPixelColor(j, OFF);
    }
    
    for(uint16_t k = 1; k < NUM_PIXELS; k++)
    {
        pixels.setPixelColor(k, WHITE);
        pixels.show();
        delay(DELAY);
    }

    pixels.setPixelColor(0, WHITE);
    pixels.show();
}

void rainbow(uint8_t wait) {
    uint16_t i, j;
 
    for(j=0; j<256; j++) {
        for(i=0; i<pixels.numPixels(); i++) {
            pixels.setPixelColor(i, Wheel((i+j) & 255));
        }
        pixels.show();
        delay(wait);
  }
}
 
void rainbowCycle(uint8_t wait) {
    uint16_t r, j;
 
    for(j=0; j<256*6; j++) { // 6 cycles of all colors on wheel
        for(r=0; r< pixels.numPixels(); r++) {
            pixels.setPixelColor(r, Wheel(((r * 256 / pixels.numPixels()) + j) & 255));
        }
        pixels.show();
        delay(wait);
    }
}

void rainbowCycleslow(uint8_t wait) {
    uint16_t r, j;
 
    for(j=0; j<256*3; j++) { // 3 cycles of all colors on wheel
        for(r=0; r< pixels.numPixels(); r++) {
            pixels.setPixelColor(r, Wheel(((r * 256 / pixels.numPixels()) + j) & 255));
        }
        pixels.show();
        delay(wait);
  }
}

void rainbowHold(uint8_t wait) {
    uint16_t r, j;
 
    for(j=0; j<256*1; j++) { // 3 cycles of all colors on wheel
        for(r=0; r< pixels.numPixels(); r++) {
            pixels.setPixelColor(r, Wheel(((r * 256 / pixels.numPixels()) + j) & 255));
        }
        pixels.show();
        delay(wait);
  }
}
 
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
    if(WheelPos < 85) {
        return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    } else if(WheelPos < 170) {
        WheelPos -= 85;
        return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else {
        WheelPos -= 170;
        return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
