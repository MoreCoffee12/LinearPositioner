/*
 * Linear positioner code
 * Brian Howard
 * 6 August 2016
 */

// Motor control pins
// From https://www.bananarobotics.com/shop/How-to-use-the-HG7881-(L9110)-Dual-Channel-Motor-Driver-Module
// HG7881 (L9110) Dual Channel Motor Driver Module
//
// Truth table
// IA   IB  Description
// L    L   Off
// L    H   Forward
// H    L   Reverse
// H    H   Off
// Must be one of 3, 5, 6, 9, 10, or 11
// for Arduino Uno
int AIA_pin = 9; 
int AIB_pin = 10;

// Limit switch pins
int RS_pin_in = 8;
int LS_pin_in = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize motor control pins.
  pinMode(AIA_pin, OUTPUT);
  pinMode(AIB_pin, OUTPUT);

  // Initialize stop limit switch pins
  pinMode(RS_pin_in, INPUT_PULLUP);
  pinMode(LS_pin_in, INPUT_PULLUP);

  // initialize serial communication
  // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
  // it's really up to you depending on your project)
  Serial.begin(57600);
  delay(50);
  
}

// the loop function runs over and over again forever
void loop() {

  // Stop the motor if we have contacted the right side
  // limit switch.
  if( digitalRead(RS_pin_in) == 0 ){
    vMotorLft();
  }

  // Stop the motor if we have contacted the left side
  // limit switch.
  if( digitalRead(LS_pin_in) == 0 ){
    vMotorRgt();
  }

  delay(10);  

}

void vMotorOff(){
  
  // This is motor off
  digitalWrite(AIA_pin, LOW);
  digitalWrite(AIB_pin, LOW);

}

void vMotorRgt(){
  
  // This is forward
  digitalWrite(AIA_pin, HIGH);
  digitalWrite(AIB_pin, LOW);
  
}

void vMotorLft(){

  // This is forward
  digitalWrite(AIA_pin, LOW);
  digitalWrite(AIB_pin, HIGH);

}

