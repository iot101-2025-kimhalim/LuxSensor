#include <Arduino.h>
#include <TFT_eSPI.h>
#include <BH1750.h>


#define SDA_PIN 44
#define SCL_PIN 43

TFT_eSPI  tft = TFT_eSPI();
char  buf[20] = "";
BH1750  LightMeter;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN); // Initialize I2C with custom pins
  LightMeter.begin();
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("BH1750 Lux Meter", 120, 20, 2);
  tft.drawString("Lux : ", 30, 60, 4);
}

void loop() {
  float lux = LightMeter.readLightLevel();
  sprintf(buf, "%.2f", lux);
  tft.fillRect(90, 60, 240, 240, TFT_BLACK);
  tft.drawString(buf, 90, 60, 4);
  delay(500);
}
