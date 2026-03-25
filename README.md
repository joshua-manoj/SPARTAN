# SPARTAN: Smart Patient Assistant & Real-Time Analysis Network

### 1. Project Overview
[cite_start]**SPARTAN** is a comprehensive **Internet of Medical Things (IoMT)** platform designed for continuous, remote patient monitoring in safety-critical environments. [cite_start]The system bridges the gap between hardware sensors and cloud-based diagnostics, providing real-time vitals tracking and automated emergency alerts for healthcare providers.

### 2. Key Technical Capabilities
* [cite_start]**Edge Analytics:** Utilizes a **Raspberry Pi 3** gateway running **Python** logic to perform real-time anomaly detection on incoming sensor data streams.
* [cite_start]**Multi-Sensor Fusion:** Integrates heart rate, body temperature, and 3-axis accelerometer data to monitor patient health and detect physical falls.
* [cite_start]**Cloud Interoperability:** Synchronizes data with **Firebase Real-time Database** and **ThinkSpeak** for global accessibility and remote doctor intervention.
* [cite_start]**Mobile Dashboard:** Features a native **Android application** for caregivers to receive sub-second updates on patient status.

### 3. The Technical Stack
* [cite_start]**Languages:** Python (AI/Gateway Logic), Embedded C (Arduino/Sensors), Java (Android App).
* [cite_start]**Hardware:** Raspberry Pi 3, Arduino UNO, ADXL345 (Accelerometer), Pulse Sensor, LM35 (Temperature).
* [cite_start]**Cloud Infrastructure:** Firebase, ThinkSpeak IoT.

### 4. Core Logic: Anomaly Detection
[cite_start]The system uses a predictive Python engine to filter raw telemetry and identify medical emergencies based on clinical thresholds.

```python
# Core logic for monitoring vitals and updating the cloud in real-time
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

### 5. Business & Healthcare Impact
[cite_start]This project demonstrates the technical foundation required for modern Electronic Health Record (EHR) interoperability. By automating data collection and analysis, SPARTAN:
* [cite_start]**Reduces Hospital Readmissions:** Enables safe at-home recovery.
* [cite_start]**Improves Response Times:** Direct cloud-to-caregiver alerts eliminate manual reporting delays.
* [cite_start]**Ensures Data Integrity:** Validates sensor input at the edge before cloud transmission.
