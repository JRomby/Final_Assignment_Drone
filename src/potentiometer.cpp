#include "potentiometer.h"

Potentiometer::Potentiometer(int pinZ)
{
    this->pinZ = pinZ;
    pinMode(pinZ, INPUT);

}
void Potentiometer::loop() {

    this->z = analogRead(this->pinZ);

     if (z > this->z + this->deadZone || z < this->z - this->deadZone)
    {
        this->z = z;
        changed = true;
    }
    else z = z;
}
int Potentiometer::getZ()
{
    return this->z;
}