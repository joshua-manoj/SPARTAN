SPARTAN: Smart Patient Assistant & Real-Time Analysis Network
Project Overview
SPARTAN is a comprehensive Internet of Medical Things (IoMT) platform designed for continuous, remote patient monitoring in safety-critical environments. The system bridges the gap between hardware sensors and cloud-based diagnostics, providing real-time vitals tracking and automated emergency alerts for healthcare providers.

Key Technical Capabilities
Edge Analytics: Utilizes a Raspberry Pi 3 gateway running Python logic to perform real-time anomaly detection on incoming sensor data streams.

Multi-Sensor Fusion: Integrates heart rate, body temperature, and 3-axis accelerometer data to monitor patient health and detect physical falls.

Cloud Interoperability: Synchronizes data with Firebase Real-time Database and ThinkSpeak for global accessibility and remote doctor intervention.

Mobile Dashboard: Features a native Android application for caregivers to receive sub-second updates on patient status.

The Technical Stack
Languages: Python (AI/Gateway Logic), Embedded C (Arduino/Sensors), Java (Android App).

Hardware: Raspberry Pi 3, Arduino UNO, ADXL345 (Accelerometer), Pulse Sensor, LM35 (Temperature).

Cloud Infrastructure: Firebase, ThinkSpeak IoT.

Core Logic: Anomaly Detection
The system uses a predictive Python engine to filter raw telemetry and identify medical emergencies based on clinical thresholds:

Python
# From ai.py: Monitoring vitals and updating the cloud in real-time
def monitor_vitals(heart_rate, temperature):
    status = "Normal"
    if heart_rate > 100 or temperature > 38:
        status = "CRITICAL: EMERGENCY DETECTED"
    
    # Syncing with Firebase for remote interoperability
    db.reference('Patient_Vitals').update({
        'BPM': heart_rate,
        'Temp': temperature,
        'Status': status
    })
Business & Healthcare Impact
This project demonstrates the technical foundation required for modern Electronic Health Record (EHR) interoperability. By automating data collection and analysis, SPARTAN:

Reduces Hospital Readmissions: Enables safe at-home recovery.

Improves Response Times: Direct cloud-to-caregiver alerts eliminate manual reporting delays.

Ensures Data Integrity: Validates sensor input at the edge before cloud transmission.
