import matplotlib.pyplot as plt

file_path = r'C:\Users\gavin\Desktop\Gavin\Self Projects\MPU-6050\IMU\Data collection\data.txt'

with open(file_path, 'r') as file:
    lines = file.readlines()

gyro_data = {'G_x':[], 'G_y':[], 'G_z':[]}

for line in lines:
    # Spliting the data
    data_pack = line.split()

    # Storing into dictionary
    gyro_data['G_x'].append(float(data_pack[1]))
    gyro_data['G_y'].append(float(data_pack[3]))
    gyro_data['G_z'].append(float(data_pack[5]))

# plt.plot(gyro_data['G_x'])
# plt.show()

for key, value in gyro_data.items():
    plt.plot(value, label=key)

plt.xlabel('Sample number/Time period')
plt.ylabel('Gyro_value')
plt.title('Gyroscope values from MPU-6050')
plt.legend()
plt.show()