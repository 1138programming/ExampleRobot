#include "commands/LoopPID.h"
#include "Robot.h"

LoopPID::LoopPID() {
  this->priority = DefaultCommandPriority;
}

bool LoopPID::canRun() {;
  return true;
}

void LoopPID::initialize() {
}

void LoopPID::execute() {
  PIDController::loopAll();
}

bool LoopPID::isFinished() {
  return true;
}

void LoopPID::end() {
}

void LoopPID::interrupted() {
}
