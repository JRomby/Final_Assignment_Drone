#include "potentiometer.h"

Potentiometer::Potentiometer(int pinZ)
{
    this->pinZ = pinZ;

    pinMode(this->pinZ, INPUT);

}
void Potentiometer::loop() {

    this->z = analogRead(this->pinZ);

}
int Potentiometer::getZ()
{
    return this->z;
}