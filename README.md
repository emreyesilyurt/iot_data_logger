
# IoT Data Logger with LSTM-Based Predictions

This project integrates IoT sensor data acquisition with LSTM-based machine learning predictions for time-series forecasting.

## Features
- Sensor drivers for 8 popular IoT sensors.
- Flask-based web server for data simulation and visualization.
- LSTM models for real-time predictions.
- Mobile-friendly dashboard for viewing real-time data and predictions.

## Prerequisites
- Python 3.8 or later.
- Required libraries:
  ```bash
  pip install flask tensorflow numpy pandas scikit-learn matplotlib joblib
  ```

## Project Structure
```
iot_data_logger_complete/
├── src/                 # STM32 firmware source files
│   ├── sensors/         # Sensor driver implementations
│   │   ├── dht22.cpp    # DHT22 driver
│   │   ├── bmp280.cpp   # BMP280 driver
│   │   ├── mpu6050.cpp  # MPU6050 driver
│   │   ├── bh1750.cpp   # BH1750 driver
│   │   ├── mq135.cpp    # MQ135 driver
│   │   ├── sds011.cpp   # SDS011 driver
│   │   ├── hc_sr04.cpp  # HC-SR04 driver
│   │   ├── vl53l0x.cpp  # VL53L0X driver
│   ├── main.cpp         # Entry point for STM32 firmware
├── web_server/          # Flask server and templates
│   ├── app.py           # Main Flask application
│   ├── templates/       # HTML templates for dashboard
├── models/              # Placeholder LSTM models and scalers
├── README.md            # Project documentation
```

## How to Run the Project
### Simulating Without Sensors
1. Clone or unzip the project.
2. Navigate to the `web_server` directory:
   ```bash
   cd iot_data_logger_complete/web_server
   ```
3. Run the Flask server:
   ```bash
   python app.py
   ```
4. Access the dashboard:
   - Open `http://127.0.0.1:5000` in your browser.
5. View predictions by accessing the `/predict` endpoint:
   ```bash
   curl "http://127.0.0.1:5000/predict?sensor=temperature&steps=10"
   ```

### Using Real Sensors
- Flash the C++ firmware from the `src/` folder to your STM32 or ESP32 board.
- Connect the sensors to your microcontroller.
- Extend the Flask server to receive real sensor data.

### Training New LSTM Models
1. Train models using the provided training script.
2. Replace the placeholder models in the `models/` folder with your trained models.

## Future Enhancements
- Deploy the project to the cloud for real-world use.
- Integrate real sensors with the Flask server.

## License
This project is licensed under the MIT License.
