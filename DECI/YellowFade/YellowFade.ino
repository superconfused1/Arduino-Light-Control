int green = 9 ,red = 3;           // the PWM pin the LED is attached to
int brightness1 = 0, brightness2 = 220;    // how bright the LED is
int fadeAmount1 = 42, fadeAmount2 = 5;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
    brightness1 = 0;
    brightness2 = 220;
    // set the brightness of pin 9:
    analogWrite(red, brightness1);
    analogWrite(green, brightness2);
   
   while(brightness1 < 255)
   {
       // set the brightness of pin 9:
       analogWrite(red, brightness1);
       analogWrite(green, brightness2);

       // change the brightness for next time through the loop:
       brightness1 = brightness1 + fadeAmount1;
       brightness2 = brightness2 + fadeAmount2;

       if(brightness1 > 250)
       {
          brightness2 = 255;
          brightness1 = 255;
          analogWrite(red, brightness1);
          analogWrite(green, brightness2);
       }
       delay(80);
   }

   while(brightness1 > 0)
   {
     // set the brightness of pin 9:
     analogWrite(red, brightness1);
     analogWrite(green, brightness2);

     // change the brightness for next time through the loop:
     brightness1 = brightness1 - fadeAmount1;
     brightness2 = brightness2 - fadeAmount2;

     delay(80);
    }

  delay(2000);
}
