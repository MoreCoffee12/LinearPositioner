/*
 * Linear positioner code
 * Brian Howard
 * 6 August 2016
 */

// Must be one of 3, 5, 6, 9, 10, or 11
// for Arduino Uno
int AIA_pin = 9; 
int AIB_pin = 10;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(AIA_pin, OUTPUT);
  pinMode(AIB_pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  // From https://www.bananarobotics.com/shop/How-to-use-the-HG7881-(L9110)-Dual-Channel-Motor-Driver-Module
  //
  // Truth table
  // IA   IB  Description
  // L    L   Off
  // L    H   Forward
  // H    L   Reverse
  // H    H   Off

  // This should be off
  //digitalWrite(AIA_pin, LOW);
  //digitalWrite(AIB_pin, LOW);

  // This is forward
  //digitalWrite(AIA_pin, LOW);
  //digitalWrite(AIB_pin, HIGH);
    
  // This is backward
  //digitalWrite(AIA_pin, HIGH);
  //digitalWrite(AIB_pin, LOW);

  // Motor off
  vMotorOff();  

//  digitalWrite(DIR_out, LOW);
//  analogWrite(PWM_out_pin, 20);

//  digitalWrite(PWM_out_pin, HIGH);
//  analogWrite(DIR_out, 20);
}

void vMotorOff(){
  // This is motor off
  digitalWrite(AIA_pin, HIGH);
  digitalWrite(AIB_pin, HIGH);

}

