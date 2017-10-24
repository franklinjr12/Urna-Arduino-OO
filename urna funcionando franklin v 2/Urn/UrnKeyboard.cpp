#include "UrnKeyboard.h"

//======================================================================================
//KeyboardControllerArduino methods
void KeyboardControllerArduino::assign(Keypad* kb)
{
    this->assignedKeyboard = kb;
}

char KeyboardControllerArduino::readKeyboard()
{
    return this->assignedKeyboard->getKey();
}
//======================================================================================


//======================================================================================
//UrnKeyboard methods
void UrnKeyboard::assign(KeyboardController* controllerToAssign)
{
    this->assignedControllerKb = controllerToAssign;
}

char UrnKeyboard::takeDigit()
{
    return assignedControllerKb->readKeyboard();
}
//======================================================================================
