//Made by Franklin Tavares Jr
//UTFPR - CAMPO MOURAO
//PROJETO INTEGRADOR URNA ELETRONICA

#ifndef URNKEYBOARD_H
#define URNKEYBOARD_H

#include <Arduino.h>
#include <Keypad.h>

//======================================================================================
//abstract class that manipulates a keyboard
class KeyboardController
{

protected:

    //takes a keyboard for it to control
    Keypad* assignedKeyboard;

public:

    //reads keyboard input
    virtual char readKeyboard(){};

    //assign an kayboard to the class
    virtual void assign(Keypad* kb){};
};
//======================================================================================

//======================================================================================
//class that constrols an Arduino keyboard
class KeyboardControllerArduino : public KeyboardController
{
public:

    //returns the digit pressed at the moment
    //will be '\0' case any key is pressed
    char readKeyboard();

    void assign(Keypad* kb);
};
//======================================================================================

//======================================================================================
class UrnKeyboard
{

private:

    KeyboardController* assignedControllerKb;

public:

    //returns the digit pressed at the moment
    char takeDigit();

    void assign(KeyboardController* controllerToAssign);

};
//======================================================================================

#endif // URNKEYBOARD_H
