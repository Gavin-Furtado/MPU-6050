'''

Created on: 14 november 2023
Author: Gavin Furtado
'''

import serial

serialport = serial.Serial('COM3',9600)

text_file = open(r'C:\Users\gavin\Desktop\Gavin\Self Projects\MPU-6050\IMU\Data collection\data.txt','w')

for i in range(100):
    gyro_data = serialport.readline().decode('ascii')
    print(gyro_data)
    text_file.write(gyro_data)

text_file.close()