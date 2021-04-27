#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <math.h>

unsigned int Rs = 10000;
double Vcc = 3.3;
char auth[] = "AUTH"; // enter the unique authorization token you received via email from Blynk
char ssid[] = "SSID";  // enter your Wifi SSID
char pass[] = "PASSWORD"; // enter your Wifi password

BlynkTimer timer;
void myTimerEvent()
{
Blynk.virtualWrite(V0, String(Thermister(AnalogRead()),1)); // This sends data to the Blynk virtual 0 (V0) pin. Note that I convert the Thermister(AnalogRead) value to a string and truncate it to one decimal place.
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);   // Setup a function to be called every second
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}

int AnalogRead() {
  int val = 0;
  for(int i = 0; i < 20; i++) {
    val += analogRead(A0); // Setup to read from the analog 0 (A0) pin
    delay(.25);
  }

  val = val / 20;
  return val;
}

double Thermister(int val) {
  double V_NTC = (double)val / 1024;
  double R_NTC = (Rs * V_NTC) / (Vcc - V_NTC);
  R_NTC = log(R_NTC);
  float Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * R_NTC * R_NTC ))* R_NTC );
  Temp = Temp - 273.15;
  Temp = (Temp-32)*.5556; // converts the temperature value to Celsius, because I live in a civilized part of the world.  Otherwise, comment this out.
  return Temp;

}
