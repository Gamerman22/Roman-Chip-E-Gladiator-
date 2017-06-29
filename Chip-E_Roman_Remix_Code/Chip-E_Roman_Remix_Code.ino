#include <IRGamepad.h>
#include <Servo.h> 

#define IR_INPUT_PIN 2
bool useModeB = false; //Set to true if your controller is switched to mode B

IR_Gamepad my_gamepad(IR_INPUT_PIN, useModeB);
Servo myServo;  // create servo object to control a servo 
int speed;       // Number of degrees to move each time a left/right button is pressed
int pos;         // variable to store the servo position 

void setup()
{
  myServo.attach(10);      // attaches the servo on pin 9 to the servo object 
  pos = 90;               // start at midpoint 90 degrees
  speed = 5;              // servo moves 3 degrees each time left/right is pushed
  myServo.write(pos);     // Set initial position
  
 Serial.begin(115200);
  while (!Serial);
  my_gamepad.enable();
}

void loop()
{
  if ( my_gamepad.update_button_states() )
  {
    if ( my_gamepad.button_press_up() ) {
      speed=min(10, speed+1);
      Serial.print( "UP" );
    }
    if ( my_gamepad.button_press_down() ) {
      speed=max(1, speed-1);
      Serial.print( "DOWN" );
    }
    if ( my_gamepad.button_press_left() ) { 
      pos=min(180,pos+speed);
      Serial.print( "LEFT" );
    }
    if ( my_gamepad.button_press_right() ) { 
      pos=max(0,pos-speed);
      Serial.print( "RIGHT" );
    }
//
//    if ( my_gamepad.button_press_start() ) Serial.print( "START" );
//    if ( my_gamepad.button_press_select() ) Serial.print( "SELECT" );
//
//    if ( my_gamepad.button_press_b() ) Serial.print( "B" );
//    if ( my_gamepad.button_press_tb() ) Serial.print( "TB" );
//    if ( my_gamepad.button_press_a() ) Serial.print( "A" );
//    if ( my_gamepad.button_press_ta() ) Serial.print( "TA" );
//
//    Serial.println( " button" );
  }
   myServo.write(pos); 
  delay(20);
}

