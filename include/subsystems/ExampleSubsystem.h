#include "abstractBaseClasses/PIDController.h"

#ifndef EXAMPLESUBSYSTEM_H
#define EXAMPLESUBSYSTEM_H

#include "main.h"

class ExampleSubsystem : public Subsystem {
  private:
    static ExampleSubsystem* instance;

    // ExampleSubsystem motors
    Motor* exampleMotor1;
    Motor* exampleMotor2;

    // ExampleSubsystem encoder
    Encoder exampleEncoder;

    // ExampleSubsystem PIDControllers
    PIDController* exampleSubsystemController;

    ExampleSubsystem();
  public:
    void initDefaultCommand();
    void move(int speed);

    // PID functions
    void setSetpoint(int setpoint);
    bool atSetpoint();
    void lock();
    void disablePID(); // PID starts off disabled
    void enablePID();

    static ExampleSubsystem* getInstance();
};

#endif
