s/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       irenka                                                    */
/*    Created:      Thu Sep 22 2022                                           */
/*    Description:  V5 project  spin up                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// drivetrainL          motor_group   16, 19          
// drivetrainR          motor_group   5, 18           
// piston1              digital_out   A               
// piston2              digital_out   B               
// hangingMech          motor_group   13, 14          
// flyStick             motor         12              
// intake               motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

// ---- START WORKING PORTS -- BRAIN ----
// Not working:
// Ports 4, 5, 6, 7, 10, 11, 12, 13
// Working: 1, 2, 3, 8, 14, 15, 16, 17, 18, 19, 20, 21, 22
// ---- END WORKING PORTS -- BRAIN ----

#include "vex.h"
//including other files
competition Competition;
#include "driverControl.h" 

void preAuton() {
  expStatus = false;
}

//will work on this later
void auton() {
  driving(-80,-80);
  wait(1.5, sec);
  driving(80, 80);
  wait(0.75, sec);
  driving(-80,-80);
  wait(0.85, sec);
  driving(80, 80);
  wait(1.5, sec);
  driving(-50, 0);
  wait(0.7, sec);
  driving(60, 60);
  spinM(intake, -50, 0.1);
  wait(1.3, sec);
  intake.stop();
  braking();
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  Competition.autonomous(auton);
  Competition.drivercontrol(userControl);
}
