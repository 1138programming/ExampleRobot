#include "Robot.h"
#include "events/EventScheduler.h"
#include "events/JoystickButton.h"
#include "events/JoystickChannel.h"

// Include commands and command groups here
#include "commands/ExampleCommand.h"
#include "commands/ExampleCommandGroup.h"
#include "commands/LoopPID.h"

Robot* Robot::instance = 0;

// Define pointers to subsystems here
ExampleSubsystem*  Robot::exampleSubsystem = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  exampleSubsystem = ExampleSubsystem::getInstance();

  // Initialize joystick buttons and channels
  JoystickChannel* exampleJoystickChannel = new JoystickChannel(MainJoystick, ChRightY);
  JoystickButton* exampleJoystickButton = new JoystickButton(MainJoystick, Btn5U);

  // Add commands to buttons and channels when certain events occur
  exampleJoystickChannel->whilePastThreshold(new ExampleCommand());
  exampleJoystickButton->whenPressed(new ExampleCommandGroup());
}

void Robot::robotInit() {
  //printf("Robot created.\n");
}

void Robot::autonInit() {
  // Initialize any commands to run throughout auton
  LoopPID* loopPID = new LoopPID();
  loopPID->run();
}

void Robot::autonPeriodic() {
  EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
}

void Robot::teleopInit() {
  // Initialize any commands to run throughout teleop
  LoopPID* loopPID = new LoopPID();
  loopPID->run();
}

void Robot::teleopPeriodic() {
  EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
}

void Robot::disabledInit() {
}

void Robot::disabledPeriodic() {
}

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
