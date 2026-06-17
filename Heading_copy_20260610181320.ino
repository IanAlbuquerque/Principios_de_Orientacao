#include <Wire.h>
#include <LSM303.h>
#include <Arduino.h>

LSM303 compass;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  
  //Processo de calibração feito manualmente.

  Serial.print("Gire o sensor em movimento de ∞ por 10 segundos!");  
  compass.calibrar(&compass.m_min, &compass.m_max);
}

void loop() {
  compass.read();
  
  /*
  When given no arguments, the heading() function returns the angular
  difference in the horizontal plane between a default vector and
  north, in degrees.
  
  The default vector is chosen by the library to point along the
  surface of the PCB, in the direction of the top of the text on the
  silkscreen. This is the +X axis on the Pololu LSM303D carrier and
  the -Y axis on the Pololu LSM303DLHC, LSM303DLM, and LSM303DLH
  carriers.
  
  To use a different vector as a reference, use the version of heading()
  that takes a vector argument; for example, use
  
    compass.heading((LSM303::vector<int>){0, 0, 1});
  
  to use the +Z axis as a reference.
  */
  float heading = compass.heading();  

  
  Serial.println(compass.angulos());
  delay(17); 
}
