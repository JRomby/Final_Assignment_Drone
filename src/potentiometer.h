#ifndef A812D987_C035_417F_B3E8_E665B02237A8
#define A812D987_C035_417F_B3E8_E665B02237A8

#include <Arduino.h>

class Potentiometer 
{
    public:
        Potentiometer(int pinZ);
        void loop();
        int getZ();
        
    private:
        int pinZ;
        int z;
        bool changed = false;
        int deadZone = 5;
};

#endif /* A812D987_C035_417F_B3E8_E665B02237A8 */