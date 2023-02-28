void setup() {
  Serial.begin(9600);   
}
String message = "";
void loop() {
  if(Serial.available()>0){
    Serial.println("RECIVE");
    char  received_char = Serial.read();
    message = message + received_char;
    if(received_char == '.'){
      Serial.println(message);
      message = "";
    }
    
  }
}
