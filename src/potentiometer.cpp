#include "potentiometer.h"

Potentiometer::Potentiometer(int pinZ)
{
    this->pinZ = pinZ;
    pinMode(pinZ, INPUT);
    c = this->z;

}
void Potentiometer::loop() {

    this->z = analogRead(this->pinZ);
    pChanged = false;

     if (this->z > c + deadZone)
    {
        c = this->z;
        pChanged = true;
    }
    
    if(this->z < c - deadZone)
    {
        c = this->z;
        pChanged = true;
    }
    
}
int Potentiometer::getZ()
{
    return this->c;
}
bool Potentiometer::getpChanged(){
    return this->pChanged;
}