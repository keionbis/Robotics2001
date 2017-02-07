#define output 13
int timehigh, timelow, freqtime;
void setup() {
 pinMode(output, OUTPUT);
 freqtime = (timehigh)/(timehigh+timelow);

}

void loop() {
 digitalWrite(output,HIGH);
 delayMicroseconds(timehigh);
 digitalWrite(output,LOW);
 delayMicroseconds(timelow);

}
