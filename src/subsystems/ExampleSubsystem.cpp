#include "main.h"
#include "subsystems/ExampleSubsystem.h"

// Include the default command or command group
#include "commands/ExampleCommand.h"

ExampleSubsystem* ExampleSubsystem::instance = 0;

ExampleSubsystem::ExampleSubsystem() {
  // Get ExampleSubsystem motors
  exampleMotor1 = Motor::getMotor(exampleMotor1Port);
  exampleMotor2 = Motor::getMotor(exampleMotor2Port);

  // Reverse motors as necessary
  exampleMotor2->reverse();

  // Slave motors as necessary
  exampleMotor1->addFollower(exampleMotor2);

  // Initialize encoders
  exampleEncoder = encoderInit(exampleEncoderTopPort, exampleEncoderBottomPort, true);

  // Set up PID controllers
  exampleSubsystemController = new PIDController(exampleMotor1, 0.32, 0, 0.05);

  // Set PID controller sensors
  exampleSubsystemController->setSensorEncoder(exampleEncoder);
  // Alternatively, the PID controller can use an IME:
  // exampleSubsystemController->setSensorIME(exampleIMEAddress);
}

void ExampleSubsystem::initDefaultCommand() {
  setDefaultCommand(new ExampleCommand());
}

void ExampleSubsystem::move(int speed) {
  speed = threshold((int)speed);
  exampleMotor1->setSpeed(speed);
}

void ExampleSubsystem::setSetpoint(int setpoint) {
  exampleSubsystemController->setSetpoint(setpoint);
}

bool ExampleSubsystem::atSetpoint() {
  return exampleSubsystemController->atSetpoint();
}

void ExampleSubsystem::lock() {
  exampleSubsystemController->lock();
}

void ExampleSubsystem::disablePID() {
  exampleSubsystemController->enabled = false;
}

void ExampleSubsystem::enablePID() {
  exampleSubsystemController->enabled = true;
}

ExampleSubsystem* ExampleSubsystem::getInstance() {
    if (instance == 0) {
      instance = new ExampleSubsystem();
    }

    return instance;
}
