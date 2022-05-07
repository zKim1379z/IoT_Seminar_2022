#define BLYNK_TEMPLATE_ID "Enter your Blynk's template ID here"
#define BLYNK_DEVICE_NAME "Enter your Blynk's device name here"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const char ssid[] = "Enter your WiFi name here";
const char pass[] = "Enter your WiFi password here";
const char auth[] = "Enter your Blynk Auth Token here";

BlynkTimer timer;
void timerEvent();

void setup(){ 
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, timerEvent);

  // sets the on-board LED pin as output
  pinMode(LED_BUILTIN, OUTPUT);           
}

void loop(){
  Blynk.run();
  timer.run();
  
  // Update on-board LED state
  Blynk.virtualWrite(V1, !digitalRead(LED_BUILTIN));
}

BLYNK_WRITE(V0){
  
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  if(value == 0)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);
}

void timerEvent(){
  // Let it empty here. There is no use right now.
}
