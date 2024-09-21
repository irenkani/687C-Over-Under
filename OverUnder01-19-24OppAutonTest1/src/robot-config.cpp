#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor drivetrainLMotorA = motor(PORT16, ratio18_1, false);
motor drivetrainLMotorB = motor(PORT19, ratio18_1, false);
motor_group drivetrainL = motor_group(drivetrainLMotorA, drivetrainLMotorB);
motor drivetrainRMotorA = motor(PORT5, ratio18_1, true);
motor drivetrainRMotorB = motor(PORT18, ratio18_1, true);
motor_group drivetrainR = motor_group(drivetrainRMotorA, drivetrainRMotorB);
digital_out piston1 = digital_out(Brain.ThreeWirePort.A);
digital_out piston2 = digital_out(Brain.ThreeWirePort.B);
motor hangingMechMotorA = motor(PORT13, ratio18_1, false);
motor hangingMechMotorB = motor(PORT14, ratio18_1, true);
motor_group hangingMech = motor_group(hangingMechMotorA, hangingMechMotorB);
motor flyStick = motor(PORT12, ratio6_1, false);
motor intake = motor(PORT4, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}