#include <TFT_eSPI.h>  // Include TFT LCD library.
#include "spongebobImage.h"
#include "lcd_backlight.hpp"

TFT_eSPI tft;  // Initialize TFT LCD.
TFT_eSprite spr = TFT_eSprite(&tft); // Buffer

static LCDBackLight backLight;

//========================================================================= SETUP
void setup()
{
  tft.begin();  // Start TFT LCD.
  tft.setRotation(3);  // Set screen rotation.
  spr.createSprite(TFT_HEIGHT, TFT_WIDTH); // Create buffer

  backLight.initialize();
  backLight.setBrightness(25); // Max brightness is 100.
  
  spr.fillSprite(tft.color565(0, 0, 255));
  
  // Draw the image.
  displayImage();
}


//========================================================================= Functions
void displayImage()
{
  spr.fillSprite(tft.color565(0, 0, 255));
  spr.pushImage(0, 0, spongebobWidth, spongebobHeight, spongebob);
  spr.pushSprite(0, 0);
}


//========================================================================= LOOP
void loop()
{ 
  
}
