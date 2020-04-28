String incoming,
incomingOLD;

int green = 9,
red = 3,
blue = 11,
initBrightness = 255,
brightness = 0,
brightness1 = 0,
brightness2 = 220,
fadeAmount = 5,
fadeAmount2 = 42;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  analogWrite(green, initBrightness);
  analogWrite(red, initBrightness);
  analogWrite(blue, initBrightness);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incoming = Serial.readString();
  }           
  if(incoming.equals("green"))
  {
    OFF();
    GREEN();
  }

  if(incoming.equals("green fade"))
  {
    OFF();
    while(Serial.available() < 1)
    {
      GREEN_FADE();
    }
    incoming = Serial.readString();
  }

  if(incoming.equals("blue"))
  {
    OFF();
    BLUE();
  }

  if(incoming.equals("blue fade"))
  {
    OFF();
    while(Serial.available() < 1)
    {
      BLUE_FADE();
    }
    incoming = Serial.readString();
  }

  if(incoming.equals("red"))
  {
    OFF();
    RED();
  }

  if(incoming.equals("red fade"))
  {
    OFF();
    while(Serial.available() < 1)
    {
      RED_FADE();
    }
    incoming = Serial.readString();
  }

  if(incoming.equals("white"))
  {
    OFF();
    WHITE();
  }

  if(incoming.equals("white fade"))
  {
    OFF();
    while(Serial.available() < 1)
    {
      WHITE_FADE();
    }
    incoming = Serial.readString();
  }

  if(incoming.equals("yellow"))
  {
    OFF();
    YELLOW();
  }

  if(incoming.equals("yellow fade"))
  {
    OFF();
    while(Serial.available() < 1)
    {
      YELLOW_FADE();
    }
    incoming = Serial.readString();
  }

  if(incoming.equals("cycle"))
  {
    OFF();
    while(Serial.available() < 1)
    {
      CYCLE();
    }
    incoming = Serial.readString();
  }

  if(incoming.equals("purple"))
  {
    OFF();
    PURPLE();
  }

  if(incoming.equals("purple fade"))
  {
    OFF();
    while(Serial.available() < 1)
    {
      PURPLE_FADE();
    }
    incoming = Serial.readString();
  }

  if(incoming.equals("off"))
  {
    OFF();
  }
  Serial.flush();
  incoming = "";
}
/////////////////////////////////////////////////////////////////
//                          LIGHTS                             //
/////////////////////////////////////////////////////////////////
void RED(){
  analogWrite(red, 0);
}
void BLUE(){
  analogWrite(blue, 0);
}
void GREEN(){
  analogWrite(green, 0);
}
void WHITE(){
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}
void YELLOW(){
  analogWrite(green, 220);
  analogWrite(red, 0);
  analogWrite(blue, 255);
}
void PURPLE(){
  analogWrite(red, 0);
  analogWrite(blue, 0);
}
/////////////////////////////////////////////////////////////////
//                          FADES                              //
/////////////////////////////////////////////////////////////////
void WHITE_FADE(){
  analogWrite(red, brightness);
  analogWrite(green, brightness);
  analogWrite(blue, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
void RED_FADE(){
  analogWrite(red, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
void BLUE_FADE(){
  analogWrite(blue, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
void GREEN_FADE(){
  analogWrite(green, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
void PURPLE_FADE(){
  analogWrite(red, brightness);
  analogWrite(blue, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
void YELLOW_FADE(){
  int led[3] = { 11, 9, 3 };
  
  brightness2 = 255;
  brightness = 255;
  analogWrite(led[0], 255);
  analogWrite(led[1], brightness2);
  analogWrite(led[2], brightness);

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
}
void CYCLE(){
  int led[3] = { 11, 9, 3 };
  //Sequence: blue, green, red.

  ////////////////////////////////////////////////////////////
  //                 Cycles through RGB start               //
  ////////////////////////////////////////////////////////////
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
  ////////////////////////////////////////////////////////////
  //                 Cycles through RGB end                 //
  ////////////////////////////////////////////////////////////
  
  YELLOW_FADE();

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
  brightness = 255;
  brightness2 = 255;
  analogWrite(led[0], brightness);
  analogWrite(led[1], brightness);
  analogWrite(led[2], brightness);
}

void OFF(){
  brightness = 0;
  analogWrite(green, initBrightness);
  analogWrite(red, initBrightness);
  analogWrite(blue, initBrightness); 
}

