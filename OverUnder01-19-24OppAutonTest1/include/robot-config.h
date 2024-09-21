using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor_group drivetrainL;
extern motor_group drivetrainR;
extern digital_out piston1;
extern digital_out piston2;
extern motor_group hangingMech;
extern motor flyStick;
extern motor intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );