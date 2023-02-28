//#include <SoftwareSerial.h>
//SoftwareSerial XBee(2, 3);


void setup() {
//  XBee.begin(9600);
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int sensorVal = analogRead(A0);
  int percentageHumididy = map(sensorVal, 0, 1024, 100, 0);
  Serial.print(percentageHumididy);
  Serial.println("%");
  delay(3000);
  
}
