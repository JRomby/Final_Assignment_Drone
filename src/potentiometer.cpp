#include "potentiometer.h"

Potentiometer::Potentiometer(int pinZ)
{
    this->pinZ = pinZ;
    pinMode(pinZ, INPUT);
    c = this->z;

}
void Potentiometer::loop() {

    this->z = analogRead(this->pinZ);
    changed = false;

     if (this->z > c + deadZone)
    {
        c = this->z;
        changed = true;
    }
    
    if(this->z < c - deadZone)
    {
        c = this->z;
        changed = true;
    }
    
}
int Potentiometer::getZ()
{
    return this->c;
}
bool Potentiometer::getChanged(){
    return this->changed;
}