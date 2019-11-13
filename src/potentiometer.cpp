#include "potentiometer.h"

Potentiometer::Potentiometer(int pinZ)
{
    this->pinZ = pinZ;
    pinMode(pinZ, INPUT);

}
void Potentiometer::loop() {

    this->z = analogRead(this->pinZ);
    if (this->changed)
    {
    Serial.println(this->z);
    }
}
int Potentiometer::getZ()
{
    return this->z;
}