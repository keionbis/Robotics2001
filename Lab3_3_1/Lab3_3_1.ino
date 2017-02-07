void setup()
{ 
  DDRB = DDRB | B110000;
  }
int T = 50;
void loop()
{  
  
    
  PORTB = B100000;         
   delayMicroseconds(T);  
   PORTB = B000000;       
   delayMicroseconds(T);
   
}

