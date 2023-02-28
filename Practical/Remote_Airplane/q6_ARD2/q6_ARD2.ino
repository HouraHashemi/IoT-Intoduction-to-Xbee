#include <Servo.h>

#define VERTICAL_SERVO_PIN 35
#define HORIZONTAL_SERVO_PIN 46
#define OFF_ON_MOTOR 52

Servo vertical_servo;
Servo horizontal_servo;


void setup() {
  Serial.begin(9600);

  vertical_servo.attach(VERTICAL_SERVO_PIN);
  vertical_servo.write(0);

  horizontal_servo.attach(HORIZONTAL_SERVO_PIN);
  horizontal_servo.write(0);

  pinMode(OFF_ON_MOTOR, OUTPUT);
}


void loop() {
  if(Serial.available()>0){
   
    char  received_char = Serial.read();
    Serial.println(received_char);
    if(received_char=='5'){
      if(digitalRead(OFF_ON_MOTOR)== HIGH){
        Serial.println("Off");
        digitalWrite(OFF_ON_MOTOR, LOW);
      }else{
        digitalWrite(OFF_ON_MOTOR, HIGH);
        Serial.println("On");
      }
    }
    else if(received_char=='4'){
      Serial.println("Left");
      if(horizontal_servo.read()<=180){
        horizontal_servo.write( horizontal_servo.read() + 5);
      }
    }
    else if(received_char=='6'){
      Serial.println("Right");
      if(horizontal_servo.read()>=-180){
        horizontal_servo.write( horizontal_servo.read() - 5);
      }
    }
    else if(received_char=='2'){
      Serial.println("Up");
      if(vertical_servo.read()<=180){
        vertical_servo.write(vertical_servo.read() + 5);
      }    
    }
    else if(received_char=='8'){
      Serial.println("Down");
      if(vertical_servo.read()<=180){
        vertical_servo.write(vertical_servo.read() + 5);
      }        
    }
  }
  delay(100);
  
}
