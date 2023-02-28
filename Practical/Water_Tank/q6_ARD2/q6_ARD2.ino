#define BUZZER 8
String message = "";

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    char  received_char = Serial.read();
    if(received_char == '%'){
      if (message.toInt() >= 95){
        Serial.print("WARRNING! HIGHER THAN [95%] - ");
        digitalWrite(BUZZER, HIGH);
        delay(1000);
        digitalWrite(BUZZER, LOW);
      }
      else if(message.toInt() <= 10){
        Serial.print("WARRNING! LOWER THAN [10%] - ");
        digitalWrite(BUZZER, HIGH);
        delay(1000);
        digitalWrite(BUZZER, LOW);
      }
      Serial.println(message + received_char);
      message = "";
    }else{
      message = message + received_char;
    }
  }
}
