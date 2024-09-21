#include "vex.h"

using namespace vex;

bool motorStatus = false;
int posNeg = 1;
bool expStatus = false;
int hangDir = 1;

void spinM(motor m, int v, float waitTime){         //function to set velocity and spin motors using the motor, wait time, and velocity pct as parameters
  m.setVelocity(v, pct);
  m.spin(forward);
  wait(waitTime, sec);
  m.stop(hold);
}

void spinMotor(motor m, int v){         //function to set velocity and spin motors using the motor, wait time, and velocity pct as parameters
  m.setVelocity(v, pct);
  m.spin(forward);
}

//same but for motor groups
void spinGroup(motor_group g, int v){   
  g.setVelocity(v, pct);
  g.spin(forward);
}

void groupReverse(motor_group g, int v){
  g.setVelocity(v, pct);
  g.spin(reverse);
}

void spinG(motor_group g, int v, float waitTime){
  g.setVelocity(v, pct);
  g.spin(forward);
  wait(waitTime, sec);
  g.stop(hold);
}

void driving(int v, int v2){    //function to set velocity and spin forward using the motor group and velocity pct as parameters
  if(posNeg == -1){
    spinGroup(drivetrainL, v2);
    spinGroup(drivetrainR, v);
  }else{
    spinGroup(drivetrainL, v);
    spinGroup(drivetrainR, v2);
  }
}

//will need this method in auton, not used in this file, might move later
void braking(){
  drivetrainL.stop();
  drivetrainR.stop();
}

void expand(){
  piston1.set(true);
  piston2.set(true);
}

void noExpand(){
  piston1.set(false);
  piston2.set(false);
}

void changeDirection(){
  posNeg = posNeg * -1;
}

void changeHang(){
  hangDir = hangDir * -1;
}

void flystick(){
  //apparently it is ok without gradual increase now?

  //gradual increase code:
  int vel = 0;
  if(vel <= 90){
    vel += 3;
    spinMotor(flyStick, vel);
    wait(0.1, sec);
  }else{
    spinMotor(flyStick, 90);
  }
}

void flystickS(){
  flyStick.stop();
}

void hang(){
  hangingMech.rotateFor(90 * hangDir, deg, 180, dps);
  changeHang();
}
void userControl(void){

  while(1){

    driving(posNeg * Controller1.Axis3.position(), posNeg * Controller1.Axis2.position());
    
    //when L1 is pressing, release the pneumatics
    Controller1.ButtonL1.pressed(expand);
    Controller1.ButtonL2.pressed(noExpand);

    //if R2 pressed, drive changes directions
    Controller1.ButtonX.pressed(changeDirection);

    //Buttons Up and Down for flystick control
    Controller1.ButtonUp.pressed(flystick);
    Controller1.ButtonDown.pressed(flystickS);

    //no hang nvm
    //Controller1.ButtonB.pressed(hang);

    //Buttons R1 and R2 for intake/outtake
    if(Controller1.ButtonR1.pressing()){
      spinM(intake, 75, 0.1);
    }
    if(Controller1.ButtonR2.pressing()){
      spinM(intake, -75, 0.1);
    }

    //while button is held down, try to hang
    if(Controller1.ButtonA.pressing()){
      spinG(hangingMech, 50, 0.1);
    }
    if(Controller1.ButtonY.pressing()){
      spinG(hangingMech, -50, 0.1);
    }

  }
}
  

