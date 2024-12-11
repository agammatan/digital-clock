#include <virtuabotixRTC.h>
virtuabotixRTC RTC(A0, A1, A2); //create thee clock // sclk, DAT, RST

void setup() {
  Serial.begin(9600);
  RTC.setDS1302Time(22, 22, 15, 6, 10,12, 2024); //sec, min, hour, day of week, day of month, month, year

}

void loop()  {

  RTC.updateTime(); // updates the time I set in the beginning
  int min = RTC.minutes; // variable for min
  int secs = RTC.seconds; //variable for seconds
  int hour = RTC.hours; //variable for hours
  
  Serial.print("Current mins: ");
  Serial.println(min);
  Serial.print("Current second: ");
  Serial.println(secs);
  Serial.print("Current hour: ");
  Serial.println(hour);
  delay(1000);
}