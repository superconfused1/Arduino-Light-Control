int green = 9, red = 3, blue = 11;           // the PWM pin the LED is attached to
int brightness1 = 0, brightness2 = 220;    // how bright the LED is

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  
  // set the brightness of pins:
  analogWrite(green, brightness2);
  analogWrite(red, brightness1);
}

// the loop routine runs over and over again forever:
void loop() {

}
