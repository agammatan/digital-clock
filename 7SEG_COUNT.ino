#include <SevSeg.h>


int pinA = 11;int pinB = 7;int pinC = 4;int pinD = 2;
int pinE = 13;int pinF = 10;int pinG = 5;
int pinDP = 3;int D1 = 12;int D2 = 9;int D3 = 8; int D4 = 6;


void setup() {//set all segments & digits as outputs
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
  
  switch (digit) { //the numbers
    case 0:
      digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH);
      break;
    case 1:
      digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH);
      break;
    case 2:
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

  // הצגת הספרות אחת אחת עם בחירת דיגיט
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

//count up to 9999
void countUp() {
  for (int i = 0; i <= 9999; i++) {
    for (int j = 0; j < 50; j++) { //speed of the count, j(50) == 1sec
      displayNumber(i);
    }
  }
}

void loop() {
  countUp();  // להתחיל את הספירה
}
