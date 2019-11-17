#ifndef A812D987_C035_417F_B3E8_E665B02237A4
#define A812D987_C035_417F_B3E8_E665B02237A4

#include <Arduino.h>
#include <ButtonListener.h>

class Joystick 
{
    public:
        Joystick(int pinBtn, int pinX, int pinY);
        void loop();
        void addButtonListener(ButtonListener *btnLsn);
        int getX();
        int getY();
        bool getjChanged();
        bool jChanged = false;
    private:
        int deadZone = 100;
        int pinBtn;
        int pinX;
        int pinY;
        int y;
        int x;
        int conX;
        int conY;
        bool listenerIsSet = false;
        ButtonListener *buttonListener;
        bool buttonIsPressed = false;
};

#endif /* A812D987_C035_417F_B3E8_E665B02237A4 */