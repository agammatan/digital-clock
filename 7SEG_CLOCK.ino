#include <SevSeg.h>
#include <virtuabotixRTC.h>
virtuabotixRTC RTC(A0, A1, A2); //create thee clock // clk, DAT, RST
//In this code, we will distinguish between 'NUMBER' which is from 0 to 9, and between 'DIGIT' which is the location on the display (1234)
//the dot can be within any digit. to turn it on we need to turn it on the specific digit, and then turn it off on the next digit.


int pinA = 11;int pinB = 7;int pinC = 4;int pinD = 2;
int pinE = 13;int pinF = 10;int pinG = 5;
int pinDP = 3;int D1 = 12;int D2 = 9;int D3 = 8; int D4 = 6; //pins for:dot, digit1, digit2, digit3, digit4 (by order)


void setup() {//set all segments & digits as outputs
Serial.begin(9600);
RTC.setDS1302Time(00, 25, 20, 6, 9, 12, 2024); //sec, min, hour, day of week, day of month, month, year
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
pinMode(pinE, OUTPUT);
pinMode(pinF, OUTPUT);
pinMode(pinG, OUTPUT);
pinMode(pinDP, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);
}

void displayDigit(int digit) { //display only one digit
  digitalWrite(pinA, LOW); digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW); digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW); digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  
  switch (digit) { //gets 
    case 0: //the display of the number ZERO
      digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH);
      break;
    case 1: //the display of the number ONE
      digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      break;
    case 2: //the display of the number TWO
      digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH); digitalWrite(pinG, HIGH);
      break;
    case 3:
      digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH); digitalWrite(pinG, HIGH);
      break;
    case 4:
      digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
    case 5:
      digitalWrite(pinA, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH);
      digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);
      break;
    case 6:
      digitalWrite(pinA, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);
      break;
    case 7:
      digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      break;
    case 8:
      digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
    case 9:
      digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);
      break;
  }
}

// display digits
void digit1() { digitalWrite(D1, LOW); digitalWrite(D2, HIGH); digitalWrite(D3, HIGH); digitalWrite(D4, HIGH); }
void digit2() { digitalWrite(D1, HIGH); digitalWrite(D2, LOW); digitalWrite(D3, HIGH); digitalWrite(D4, HIGH); digitalWrite(pinDP, HIGH);}
void digit3() { digitalWrite(D1, HIGH); digitalWrite(D2, HIGH); digitalWrite(D3, LOW); digitalWrite(D4, HIGH); digitalWrite(pinDP, LOW);}
void digit4() { digitalWrite(D1, HIGH); digitalWrite(D2, HIGH); digitalWrite(D3, HIGH); digitalWrite(D4, LOW); }

//displays the numbe we want
void displayNumber(int num) {
  int digits[4];
  digits[0] = num / 1000;         // the far left digit
  digits[1] = (num / 100) % 10;
  digits[2] = (num / 10) % 10;  
  digits[3] = num % 10;           // the far right digits

  // displays the correct number on the correct digit
  digit1(); //far left digit
  displayDigit(digits[0]); //the number
  delay(5);  // invisible delay

  digit2();
  displayDigit(digits[1]);
  delay(5);  

  digit3();
  displayDigit(digits[2]);
  delay(5);

  digit4();
  displayDigit(digits[3]);
  delay(5);

}
//because the digits are displays for 1 milsec only, we use delay(5) to see the number for 5 nulsecs but thats not enough
//so we use this function that delay the next display transmit and calls the displayNumber() again and again.
//this way, the digits displays on the screen again and again.
int Count(int num) {
  for (int i = 0; i<=30; i++) {
    displayNumber(num);
  }
}


void loop() {
  RTC.updateTime(); // updates the time I set in the beginning
  int min = RTC.minutes; // variable for minutes
  int hour = RTC.hours; //variable for hours
  int Time = hour*100 + min;//variable of 4 digits for the time
  Count(Time); //this func deliver the time to anouther func

  //some prints the self-checks
  Serial.println(Time);
  Serial.print("Current mins: ");
  Serial.println(min);
  Serial.print("Current hour: ");
  Serial.println(hour);
  

}
