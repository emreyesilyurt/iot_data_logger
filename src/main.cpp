
#include "sensors/dht22.h"
#include "sensors/bmp280.h"
#include "sensors/mpu6050.h"
#include "sensors/bh1750.h"
#include "sensors/mq135.h"
#include "sensors/sds011.h"
#include "sensors/hc_sr04.h"
#include "sensors/vl53l0x.h"
#include "comm/lora.h"

int main() {
    // Initialize sensors and communication
    init_dht22();
    init_bmp280();
    init_mpu6050();
    init_bh1750();
    init_mq135();
    init_sds011();
    init_hc_sr04();
    init_vl53l0x();
    init_lora();

    // Main application loop
    while (1) {
        float temp = read_dht22_temperature();
        float humidity = read_dht22_humidity();
        float pressure = read_bmp280_pressure();
        float accel = read_mpu6050_acceleration();
        float gyro = read_mpu6050_gyroscope();
        float light = read_bh1750_light();
        float air_quality = read_mq135_air_quality();
        float pm25 = read_sds011_pm25();
        float pm10 = read_sds011_pm10();
        float distance_hc = read_hc_sr04_distance();
        float distance_vl = read_vl53l0x_distance();

        // Send all data via LoRa
        send_lora(temp);
        send_lora(humidity);
        send_lora(pressure);
        send_lora(accel);
        send_lora(gyro);
        send_lora(light);
        send_lora(air_quality);
        send_lora(pm25);
        send_lora(pm10);
        send_lora(distance_hc);
        send_lora(distance_vl);
    }

    return 0;
}
