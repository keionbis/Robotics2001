#include <LiquidCrystal.h>
//*******************declarations***********************//
unsigned long time, seconds, mins, hrs;
const byte buttonPin = 2;//button pin
int prevmillis = 0;
volatile byte state = LOW;
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);//screen declaration
//*******************initializations***********************//
void setup() {
  Serial.begin(9600);//used to test output before using the screen
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  attachInterrupt(digitalPinToInterrupt(buttonPin), reset, RISING);//button interrupt
}
//*******************repeated code***********************//
void loop() {
  (0, 0);
  time = millis() - prevmillis;
  time_conversion();
  delay(250);
}
//*******************button press command***********************//
void reset()
{
  serial_printing();
}
//*******************converting from mills to seconds, mins and hours***********************//
void time_conversion()
{
  if (time > 1000)
  {
    seconds = time / 1000;
    if (seconds > 60)
    {
      mins = seconds / 60;
    }
    if (mins > 60)
    {
      hrs = mins / 60;
    }
  }
  
}
//*******************printing data to the screen***********************//
void serial_printing()
{
  if (hrs < 10)
  {
    Serial.print(0);
    Serial.print(hrs); 
  }
  else
  { 
    Serial.print(hrs);
  }
  Serial.print(":");
  if ((mins - (hrs * 60)) < 10)
  {
    Serial.print(0); 
    Serial.print(mins - (hrs * 60));
  }
  else
  { 
    Serial.print(mins - (hrs * 60));
  }
  Serial.print(":");
  if ((seconds - (mins * 60)) < 10)
  {
    Serial.print(0);
    Serial.print(seconds - (mins * 60));
  }
  else
  {
    Serial.print(seconds - (mins * 60));
  }
  Serial.print("\n");
}

