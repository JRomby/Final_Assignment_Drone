#include <Arduino.h>
#include <string.h>
#include <drone.h>
#include <joystick.h>

String ssid = "flexlab2";
String password = "flexiwifi";//connecting to flexlab wifi

Drone drone(ssid, password);
Joystick joystick(15, 34, 35, 5); // pins: btn, x, y, potentiometerpin

void setup()
{
  Serial.begin(9600);

  drone.joystick = &joystick; 

  for (size_t i = 0; i < 5; i++)
  {
    Serial.println(i);
    delay(1000);
  }

  joystick.addButtonListener(&drone);
  
  drone.connect();
  drone.setIp ("192.168.1.110"); //Set IP så den passer til det vi skal connecte med.

  
}

void loop()
{
  joystick.loop();
  drone.loop();
} 