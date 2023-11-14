/*
Collecting IMU data for Kalman Filter algorithm.

Author: Gavin Furtado
*/

// Include Arduino Framework
#include <Arduino.h>

// MPU6050 library and dependencies
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Include Wire Library for I2C communication
#include <Wire.h>

// Creating an object/instance of the class Adafruit_MPU6050
// Class mpu further uses methods and properties
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);

  // Initialising the MPU6050 chip
  if(!mpu.begin()){
    Serial.println("Failed to intitalize MPU6050!");
    while(1){
      delay(10);
    }
  }  
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
}

void loop() {
  // Read sensor data and print it
  
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  Serial.print("G_x: ");
  Serial.print(g.gyro.x);
  Serial.print("  ");

  Serial.print("G_y: ");
  Serial.print(g.gyro.y);
  Serial.print("  ");
  
  Serial.print("G_z: ");
  Serial.print(g.gyro.z);
  Serial.print("\n");

  delay(1500);
}




