#include <Arduino.h>
#include <joystick.h>

Joystick::Joystick(int pinBtn, int pinX, int pinY)
{
    this->pinBtn = pinBtn;
    this->pinX = pinX;
    this->pinY = pinY;

    pinMode (this->pinBtn, INPUT_PULLUP);
    pinMode (this->pinX, INPUT);
    pinMode (this->pinY, INPUT);
}

void Joystick::addButtonListener(ButtonListener *btnLsn)
{
    this->buttonListener = btnLsn; 
    this->listenerIsSet = true;
    Serial.println("done setting listener");
}

void Joystick::loop()
{
    // if joystick btn is pressed and not already set as pressed
    if (digitalRead(this->pinBtn) == 0 && this->buttonIsPressed == false)
    {
        this->buttonIsPressed = true;
        
        if (this->listenerIsSet)
        {
            this->buttonListener->ButtonPressed();
        }
    }    
    else if (digitalRead(this->pinBtn) == 1 && this->buttonIsPressed == true)
    {
        this->buttonIsPressed = false;
    }


    this->x = analogRead(this->pinX);
    this->y = analogRead(this->pinY);
    jChanged = false;

     if (this->x > conX + deadZone)
    {
        conX = this->x;
        jChanged = true;
    }
    
    if(this->y < conY - deadZone)
    {
        conY = this->y;
        jChanged = true;
    }

}

Position Joystick::getPosition()
{
    this->position = Position(this->x, this->y);
    return this->position;
}

int Joystick::getX()
{
    return this->x;
}
int Joystick::getY()
{
    return this->y;
}
bool getjChanged(){
    return this->jChanged;
}