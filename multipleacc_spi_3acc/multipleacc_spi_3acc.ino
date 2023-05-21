#include <SPI.h>
#include <SparkFun_ADXL345.h>

// Constants for SPI communication
const int CS_PIN1 = 10; // Chip Select (CS) pin for ADXL345 module 1
const int CS_PIN2 = 9;  // Chip Select (CS) pin for ADXL345 module 2
const int CS_PIN3 = 8;  // Chip Select (CS) pin for ADXL345 module 3

// Create instances for ADXL345 modules
ADXL345 adxl1(CS_PIN1);
ADXL345 adxl2(CS_PIN2);
ADXL345 adxl3(CS_PIN3);

void setup() {
  Serial.begin(9600);
  Serial.println("SparkFun ADXL345 Accelerometer Example");

  // Initialize SPI communication
  SPI.begin();

  // Power on ADXL345 modules
  adxl1.powerOn();
  adxl2.powerOn();
  adxl3.powerOn();

  // Configure ADXL345 settings for module 1
  adxl1.setRangeSetting(2); // +/- 2g range

  // Configure ADXL345 settings for module 2
  adxl2.setRangeSetting(4); // +/- 4g range

  // Configure ADXL345 settings for module 3
  adxl3.setRangeSetting(8); // +/- 8g range

  // Other configuration settings can be applied similarly for each module

  delay(100);
}

void loop() {
  // Read accelerometer values from module 1
  int x1, y1, z1;
  adxl1.readAccel(&x1, &y1, &z1);

  // Read accelerometer values from module 2
  int x2, y2, z2;
  adxl2.readAccel(&x2, &y2, &z2);

  // Read accelerometer values from module 3
  int x3, y3, z3;
  adxl3.readAccel(&x3, &y3, &z3);

  // Output results to serial
  Serial.print("Module 1: ");
  Serial.print("X = "); Serial.print(x1);
  Serial.print(", Y = "); Serial.print(y1);
  Serial.print(", Z = "); Serial.println(z1);

  Serial.print("Module 2: ");
  Serial.print("X = "); Serial.print(x2);
  Serial.print(", Y = "); Serial.print(y2);
  Serial.print(", Z = "); Serial.println(z2);

  Serial.print("Module 3: ");
  Serial.print("X = "); Serial.print(x3);
  Serial.print(", Y = "); Serial.print(y3);
  Serial.print(", Z = "); Serial.println(z3);

  delay(500); // Adjust delay as needed
}
