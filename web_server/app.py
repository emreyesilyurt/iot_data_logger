
from flask import Flask, jsonify, request, render_template
import joblib
from tensorflow.keras.models import load_model
import numpy as np

app = Flask(__name__)

# Load LSTM models and scalers for each sensor (placeholders)
models = {
    "temperature": load_model("lstm_temp_model.h5"),
    "humidity": load_model("lstm_humidity_model.h5"),
}
scalers = {
    "temperature": joblib.load("lstm_temp_scaler.pkl"),
    "humidity": joblib.load("lstm_humidity_scaler.pkl"),
}

@app.route('/predict', methods=['GET'])
def predict():
    sensor = request.args.get("sensor")
    steps = int(request.args.get("steps", 10))
    if sensor in models:
        model = models[sensor]
        scaler = scalers[sensor]
        future_X = np.arange(100, 100 + steps).reshape(-1, 1)
        scaled_X = scaler.transform(future_X)
        predictions = model.predict(scaled_X)
        return jsonify({"predictions": predictions.tolist()})
    return jsonify({"error": "Sensor not found"}), 400

if __name__ == "__main__":
    app.run(debug=True)
