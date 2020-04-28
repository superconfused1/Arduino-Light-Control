int led[3] = {11, 9, 3};           // the PWM pin the LED is attached to
int brightness = 0;
int brightness2 = 220;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int fadeAmount2 = 42;

// the setup routine runs once when you press reset:
void setup() {
  //pinMode(led[2], OUTPUT);
  //pinMode(led[1], OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  for(int i = 0; i < 3; i++)
  {
    while(brightness != 0)
    {
          // change the brightness for next time through the loop:
          brightness = brightness - fadeAmount;
          // wait for 30 milliseconds to see the dimming effect
          delay(20);
          analogWrite(led[i], brightness);
    }

    while(brightness != 255)
    {
          // change the brightness for next time through the loop:
          brightness = brightness + fadeAmount;
          // wait for 30 milliseconds to see the dimming effect
          delay(20);
          analogWrite(led[i], brightness);
    }
  }

  brightness2 = 255;
  brightness = 255;
  analogWrite(led[1], brightness2);
  analogWrite(led[2], brightness);
  analogWrite(led[0], 255);

  while(brightness2 != 220)
  {
     // set the brightness of pin 9:
     analogWrite(led[1], brightness2);
     analogWrite(led[2], brightness);

     // change the brightness for next time through the loop:
     brightness2 = brightness2 - fadeAmount;
     brightness = brightness - fadeAmount2;

     delay(95);
  }

  delay(500);

  while(brightness2 != 255)
  {
     // change the brightness for next time through the loop:
     brightness2 = brightness2 + fadeAmount;
     brightness = brightness + fadeAmount2;

     // set the brightness of pin 9:
     analogWrite(led[1], brightness2);
     analogWrite(led[2], brightness);


     if(brightness > 250)
     {
	brightness2 = 255;
	brightness = 255;
	analogWrite(led[1], brightness2);
	analogWrite(led[2], brightness);
     }

     delay(95);
  }

  delay(200);

  while(brightness != 0)
  {
    analogWrite(led[0], brightness);
    analogWrite(led[1], brightness);
    analogWrite(led[2], brightness);
    brightness = brightness - fadeAmount;
    delay(20);
  }

  while(brightness != 255)
  {
    analogWrite(led[0], brightness);
    analogWrite(led[1], brightness);
    analogWrite(led[2], brightness);
    brightness = brightness + fadeAmount;
    delay(20);
  }

  analogWrite(led[1], 255);
  while(brightness != 0)
  {
    analogWrite(led[0], brightness);
    analogWrite(led[2], brightness);
    brightness = brightness - fadeAmount;
    delay(20);
  }

  while(brightness != 255)
  {
    analogWrite(led[0], brightness);
    analogWrite(led[2], brightness);
    brightness = brightness + fadeAmount;
    delay(20);
  }
}
