#ifndef C8C7268F_7308_4565_BA1F_FDBA5EBBD88F
#define C8C7268F_7308_4565_BA1F_FDBA5EBBD88F

#include <Arduino.h>
#include <string.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <ButtonListener.h>
#include <joystick.h>
#include <potentiometer.h>

using namespace std;

class Drone : public ButtonListener
{
    public:
        Drone(String ssid , String password);
        void connect();
        void sendCommand(String commmand);
        void setIp(String ip);
        bool connected;
        String myIp;
        void ButtonPressed();
        void loop();
        Joystick *joystick;
        Potentiometer *potentiometer;
    private:
        void commandResponse(String response);
        String ssid;
        String password;
        AsyncUDP udp;
        WiFiUDP udpSender;
        const int udpPort = 8889; 
        String droneIp = "192.168.1.146";
        bool flying = false;
        int potValue;
        int height;
        int posX;
        int posY;
        int xVal;
        int yVal;
};

#endif /* C8C7268F_7308_4565_BA1F_FDBA5EBBD88F */