#include "potentiometer.h"

Potentiometer::Potentiometer(int pinZ)
{
    this->pinZ = pinZ;
    pinMode(pinZ, INPUT);
    c = this->z;

}
void Potentiometer::loop() {

    this->z = analogRead(this->pinZ);

     if (this->z > c + deadZone)
    {
        c = this->z;
        Serial.println("+");
    }
    if(this->z < c - deadZone)
    {
        c = this->z;
        Serial.println("-");
    }
}
int Potentiometer::getZ()
{
    return this->c;
}