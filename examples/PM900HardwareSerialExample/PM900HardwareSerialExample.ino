// set this to the hardware serial port you wish to use
#define HWSERIAL Serial2
#include "pm900.h"

PM900 dustSensor;
void setup() {
  Serial.begin(9600);
  dustSensor.begin(&HWSERIAL);
}

void loop() {
  // PM900 send data every 1.5 seconds. Calling read function faster than that means that your dataset will contain duplicated values
  dustSensor.read();

  if (dustSensor.isValid()) {
    Serial.println();
    Serial.print("PM10: ");
    Serial.print(dustSensor.getpm10(), DEC);
    Serial.print(" ug/m^3    PM2.5: ");
    Serial.print(dustSensor.getpm2_5(), DEC);
    Serial.print(" ug/m^3    PM1: ");
    Serial.print(dustSensor.getpm1(), DEC);
    Serial.print(" ug/m^3");
  }

  delay (1000);
}