/**
 * Vishal Chandra
 * 3/28/19
 * Controlling motor speed with pwm
 */

#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT

#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6d7d57fceee549a2a67f6c3ec7d50b5b";
#define motorPin 16

//pwm properties
const int freq = 5000;
const int channel = 0;
const int resolution = 8;

BLYNK_WRITE(V0)
{
  //get and send slider info
  int dutyCycle = param.asInt();
  ledcWrite(channel, dutyCycle);
}

void setup()
{
  //setup pwm to transistor
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(motorPin, channel);
  
  Serial.begin(9600);
  Serial.println("Waiting for connections...");
  Blynk.setDeviceName("Blynk");
  Blynk.begin(auth);
}

void loop()
{
  Blynk.run();
}
