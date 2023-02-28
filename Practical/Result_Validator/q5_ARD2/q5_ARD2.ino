//[0,1,2,3,4,5,6,7,8,9][+,-,*,/][0,1,2,3,4,5,6,7,8,9]...[=][0,1,2,3,4,5,6,7,8,9]

#define RED_LED 34
#define GREEN_LED 36

#define array_size 30

String answer = "";
String input = "";
String pointer[array_size];
int counter = 0;

bool end_input = false;

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.println("Enter c to calculate terms");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.print(c);
    if(end_input == false){
        if(c == '='){
          end_input = true;
          pointer[counter] = input;
//          Serial.print(pointer[counter]);
          counter++;
          input = "";
        }
        else if((c=='+')||(c=='-')||(c=='/')||(c=='*')){
           pointer[counter] = input;
//           Serial.print(pointer[counter]);
           counter++;
           pointer[counter] = c;
//           Serial.print(pointer[counter]);
           counter++;
           input = "";
        }
        else{
          input = input + c;
        }
    }
    else{
      if(c == 'c'){
        Serial.println();
//        print_array(pointer);

        //calculate + , - first
        for(int i=1; i<counter; i=i+2){
          if(pointer[i]=="+" || pointer[i]=="-"){
            int num1 = pointer[i-1].toInt();
            String op = pointer[i];
            int num2 = pointer[i+1].toInt();
            int result = calculate( num1, op, num2 );
            pointer[i-1] = "0";
            pointer[i] = "0";
            pointer[i+1] = String(result);
          }
        }
        
        shift_array(pointer);
//        print_array(pointer);

        //calculate * , / next
        for(int i=1; i<counter; i=i+2){
          if(pointer[i]=="*" || pointer[i]=="/"){
            int num1 = pointer[i-1].toInt();
            String op = pointer[i];
            int num2 = pointer[i+1].toInt();
            int result = calculate( num1, op, num2 );
            pointer[i-1] = "0";
            pointer[i] = "0";
            pointer[i+1] = String(result);
          }
        }
        Serial.println();
        if(answer.toInt() == pointer[counter-1].toInt()){
           Serial.print(pointer[counter-1].toInt());
           Serial.print("==");
           Serial.println(answer.toInt());
           Serial.println("Correct Answer");
           digitalWrite(GREEN_LED, HIGH);
           delay(2000);
           digitalWrite(GREEN_LED, LOW);

        }
        else{
           Serial.print(pointer[counter-1].toInt());
           Serial.print("!=");
           Serial.println(answer.toInt());
           Serial.println("Wrong Answer");
           digitalWrite(RED_LED, HIGH);
           delay(2000);
           digitalWrite(RED_LED, LOW);
        }
        Serial.print("-----------------------");
        //reset everything
        answer = "";
        clear_array(pointer);
        counter = 0;
        end_input = false;
      }
      else{
         answer = answer + c;
      }
    }
    
  }//end available if
    
}

//-------------------------------------------
int calculate(int num1,String operation, int num2){
  int result;
  if(operation =="/"){
     result = num1/num2;
  }
  else if(operation =="*"){
     result = num1*num2;
  }
  else if(operation =="+"){
     result = num1+num2;
  }
  else if(operation =="-"){
     result = num1-num2;
  }
//  Serial.println("calculate");
//  Serial.print(num1);
//  Serial.print(operation);
//  Serial.print(num2);
//  Serial.print("=");
//  Serial.println(result);
  return result;
}


void print_array(String *arr){
   Serial.println();
   Serial.println("ARRAY: ");
   for(int i=0; i<counter; i++){
      Serial.print(arr[i]);
   }
   Serial.println();
}


void shift_array(String *arr){
  int temp_counter = 0;
  for(int i=0; i<counter; i++){
    if(arr[i]!="0"){
      arr[temp_counter]=arr[i];
      temp_counter++;
    }
   }
   counter = temp_counter;
}


void clear_array(String *arr){
  for(int i=0; i<array_size; i++){
     arr[i]="";
   }
}
