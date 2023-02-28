/*************************************************************
  

  You can use this sketch as a debug tool that prints all incoming values
  sent by a widget connected to a Virtual Pin 1 in the Blynk App.

  App dashboard setup:
    Slider widget (0...100) on V1
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPLPwVUlBcF"
#define BLYNK_TEMPLATE_NAME         "Blynk"
#define BLYNK_AUTH_TOKEN            "fg44_qOt1ktWFj_M5zFsHR7yDUHVCpC0"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial1


#include <BlynkSimpleStream.h>


// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(22, HIGH);
  delay(1000);
  digitalWrite(22, LOW);
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial1.print("V0 Slider value is: ");
  Serial1.println(pinValue);
}

void setup()
{
  // Debug console
  Serial1.begin(115200);
  pinMode(22, OUTPUT);
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, BLYNK_AUTH_TOKEN);
}

void loop()
{
  Blynk.run();
}
