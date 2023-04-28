   #include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 12;  // Analog output pin that the LED is attached to

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[ROW_NUM] = {13, 0, A5, A4}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {A3, A2, A1}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

String password0 = "1734"; // change your password here
String password1 = "5834"; // change your password here
String password2 = "1730"; // change your password here
String password3 = "1037"; // change your password here
String password4 = "1833"; // change your password here
String password5 = "1873"; // change your password here
String password6 = "8830"; // change your password here
String password7 = "8374"; // change your password here
String password8 = "1744"; // change your password here
String password9 = "1887"; // change your password here
String password10 = "384666256"; // change your  self destruct password here

String input_password;
//const char* const passes[] = { "1234","4567","8675" };

void setup(){
  Serial.begin(9600);
  input_password.reserve(32); // maximum input characters is 33, change if needed
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
   pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
   pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
   pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
   pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
   pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
   pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
   pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
   pinMode(10, OUTPUT);
  digitalWrite(12, LOW);
   pinMode(11, OUTPUT);
  digitalWrite(11, LOW);



}

void loop(){
    if(outputValue>1550){
    digitalWrite(12, LOW);

  }
  char key = keypad.getKey();
  int sensorValue = 0;  // value read from the pot
    // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = (sensorValue * 2.93);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);
  if(outputValue<1600){
    digitalWrite(12, LOW);

  }
   if(outputValue>1550){
    digitalWrite(12, LOW);

  }
  if (key){
    Serial.println(key);

    if(key == '*') {
      input_password = ""; // clear input password
    } else if(key == '#') {
      if(password0 ||password1||password2||password3||password4||password5||password6||password7||password8||password9||password10 == input_password) {
        
        // DO YOUR WORK HERE
        if(input_password == password0){
          Serial.println("password0 is correct");
          digitalWrite(2, HIGH);
          delay(200);
          digitalWrite(2, LOW);
        }
                if(input_password == password1){
          Serial.println("password1 is correct");
           digitalWrite(3, HIGH);
          delay(200);
          digitalWrite(3, LOW);
        }
                if(input_password == password2){
          Serial.println("password2 is correct");
           digitalWrite(4, HIGH);
          delay(200);
          digitalWrite(4, LOW);
        }
                if(input_password == password3){
          Serial.println("password3 is correct");
              digitalWrite(5, HIGH);
          delay(200);
          digitalWrite(5, LOW);
          delay(66);
          digitalWrite(5, HIGH);
          delay(84);
          digitalWrite(5, LOW);
        }
                if(input_password == password4){
          Serial.println("password4 is correct");
              digitalWrite(6, HIGH);
          delay(200);
          digitalWrite(6, LOW);
        }
                if(input_password == password5){
          Serial.println("password5 is correct");
              digitalWrite(7, HIGH);
          delay(200);
          digitalWrite(7, LOW);
          delay(100);
          digitalWrite(7, HIGH);
          delay(200);
          digitalWrite(7, LOW);
        }
                if(input_password == password6){
          Serial.println("password6 is correct");
              digitalWrite(8, HIGH);
          delay(200);
          digitalWrite(8, LOW);
        }
                if(input_password == password7){
          Serial.println("password7 is correct");
              digitalWrite(9, HIGH);
          delay(200);
          digitalWrite(9, LOW);
           delay(200);
          digitalWrite(9, HIGH);
          delay(200);
          digitalWrite(9, LOW);
        }
                if(input_password == password8){
          Serial.println("password8 is correct");
              digitalWrite(10, HIGH);
          delay(200);
          digitalWrite(10, LOW);
        }
                if(input_password == password9){
          Serial.println("password9 is correct");
              digitalWrite(11, HIGH);
          delay(200);
          digitalWrite(11, LOW);
        }
                if(input_password == password10){
          Serial.println("admin command recoqnized");
            Serial.print("\t battvolt = ");
            Serial.println(outputValue);
              digitalWrite(11, HIGH);
          delay(200);
          digitalWrite(11, LOW);
          delay(200);

              digitalWrite(10, HIGH);
          delay(200);
          digitalWrite(10, LOW);
          delay(200);

              digitalWrite(9, HIGH);
          delay(200);
          digitalWrite(9, LOW);
          delay(200);

              digitalWrite(8, HIGH);
          delay(200);
          digitalWrite(8, LOW);
          delay(200);

              digitalWrite(7, HIGH);
          delay(200);
          digitalWrite(7, LOW);
          delay(200);

              digitalWrite(6, HIGH);
          delay(200);
          digitalWrite(6, LOW);
          delay(200);

              digitalWrite(5, HIGH);
          delay(200);
          digitalWrite(5, LOW);
          delay(200);
          digitalWrite(5, HIGH);
          delay(84);
          digitalWrite(5, LOW);

              digitalWrite(4, HIGH);
          delay(200);
          digitalWrite(4, LOW);
          delay(200);

              digitalWrite(3, HIGH);
          delay(200);
          digitalWrite(3, LOW);
          delay(200);

              digitalWrite(2, HIGH);
          delay(200);
          digitalWrite(2, LOW);
          delay(200);


        }
        
        
      } else {
        Serial.println("password is incorrect, try again");
      }

      input_password = ""; // clear input password
    } else {
      input_password += key; // append new character to input password string
    }
  }
}
