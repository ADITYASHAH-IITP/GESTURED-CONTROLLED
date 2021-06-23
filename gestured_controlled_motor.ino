


// include the library code:
#include <LiquidCrystal.h>
int f1 = 0; 
int f2 = 1; 
int f3 = 2; 
int f4 = 3; 
int f5 = 4; 
int val1; 
int val2;
int val3;
int val4;
int val5;
int motor1 = 6; 
int motor2 = 9; 
int valm1;
int valm2;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600); 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  lcd.print("Gesture controlled");
}

void loop() {
  val1 = analogRead(f1);
  val2 = analogRead(f2);
  val3 = analogRead(f3);
  val4 = analogRead(f4);
  val5 = analogRead(f5);
  
  //Serial.println(val1);
  Serial.println(val2);
  //Serial.println(val3);
  //Serial.println(val4);
  //Serial.println(val5);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  if (val1<7){
  lcd.print("o");
  }
  else {
  lcd.print("I");
}
  lcd.setCursor(1, 1);
  // print the number of seconds since reset:
  if (val2<7){
  lcd.print("o");
  }
  else {
  lcd.print("I");
}
  lcd.setCursor(2, 1);
  // print the number of seconds since reset:
  if (val3<7){
  lcd.print("o");
  }
  else {
  lcd.print("I");
}
  lcd.setCursor(3, 1);
  // print the number of seconds since reset:
  if (val4<7){
  lcd.print("o");
  }
  else {
  lcd.print("I");
}
  lcd.setCursor(4, 1);
  // print the number of seconds since reset:
  if (val5<7){
  lcd.print("o");
  }
  else {
  lcd.print("I");
}
  if (val1<7){
    int speed = (12-val2);  //Receive Value from serial monitor
    valm1 = map(speed, 0, 12, 0, 255);
    analogWrite(motor1, valm1);
    analogWrite(motor2, 0);
    Serial.println("valm1");
    Serial.println(valm1);
    Serial.print(" ");
  }
  else {
    
    int speed = (12-val2);  //Receive Value from serial monitor
    valm1 = map(speed, 0, 12, 0, 255);
    analogWrite(motor1, 0);
    analogWrite(motor2, valm1);
    Serial.println("valm1");
    Serial.println(valm1);
    Serial.print(" ");
  }
}
 