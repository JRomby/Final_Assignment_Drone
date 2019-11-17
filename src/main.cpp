#include <Arduino.h>
#include <string.h>
#include <drone.h>
#include <potentiometer.h>
#include <joystick.h>

String ssid = "CableBox-B078";
String password = "gjz2ymm0kd";//connecting to wifi

Drone drone(ssid, password);
Joystick joystick(15, 34, 35); // pins: btn, x, y
Potentiometer pot(32);

void setup()
{
  Serial.begin(9600);

  drone.joystick = &joystick;
  drone.potentiometer =&pot; 

  joystick.addButtonListener(&drone);
  
  drone.connect();
  drone.setIp ("192.168.1.108"); //Set IP så den passer til det vi skal connecte med.

  
}

void loop()
{
  joystick.loop();
  drone.loop();
  pot.loop();
} 