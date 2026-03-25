# SPARTAN: Smart Patient Assistant & Real-Time Analysis Network

## Project Overview
An end-to-end **Internet of Medical Things (IoMT)** platform designed for continuous, remote patient monitoring in safety-critical environments. The goal was to transition from a reactive emergency response to **proactive health monitoring** — identifying medical anomalies and physical falls in real-time with automated, cloud-based alerts.

The project combines **Embedded C hardware integration** with a **Python-based analysis engine** and a **Firebase real-time dashboard** to give caregivers and doctors an immediate view of a patient’s vitals.

## Business & Healthcare Problem
Traditional healthcare monitoring often suffers from a "response-time gap" where emergency services are only notified after a patient or bystander manually calls for help. There was a critical need for a centralized, autonomous system to monitor vitals and detect accidents (like falls) simultaneously.

**Key questions this project answers:**
* Is the patient’s heart rate or temperature within safe clinical thresholds right now?
* Has a sudden impact or fall occurred that requires immediate intervention?
* Can doctors access live telemetry remotely to make informed decisions before arriving on-site?

## Data & Hardware Source
* **Sensors:** ADXL345 (3-axis Accelerometer), Pulse Sensor, and LM35 (Temperature Sensor)
* **Edge Gateway:** Raspberry Pi 3 and Arduino UNO
* **Cloud Platform:** Firebase Real-time Database and ThinkSpeak IoT
* **Application:** Native Android Mobile Dashboard for real-time alerts

## Python Analysis — Core Anomaly Detection Logic
The central monitoring engine uses a threshold-based predictive check to classify patient status and synchronize vitals with the cloud:

```python
# Core logic for monitoring vitals and updating the cloud in real-time
def monitor_patient_status(heart_rate, temperature):
    # Step 1: Assign business/health status for the dashboard
    status = "Normal"
    if heart_rate > 100 or temperature > 38:
        status = "CRITICAL: EMERGENCY DETECTED"
    
    # Step 2: Synchronize with Firebase for remote interoperability
    db.reference('Patient_Vitals').update({
        'BPM': heart_rate,
        'Temp': temperature,
        'Status': status,
        'Last_Updated': datetime.now().strftime("%H:%M:%S")
    })
```

**How the logic works:**
* **Heart Rate > 100 BPM** → High-intensity cardiac activity detected → **CRITICAL**
* **Temperature > 38°C** → Potential fever or physiological stress → **CRITICAL**
* **3-Axis Impact (Z-Axis Shift)** → Detected via ADXL345 → **FALL DETECTED**
* **Real-time Sync** → Sub-second latency between sensor read and cloud update

## System Dashboard
**SPARTAN Mobile & Cloud Interface**
The system provides:
* **Vitals Heat-map** — A live-streaming view of heart rate and temperature history
* **Emergency Alert System** — Instant push notifications triggered by anomaly detection logic
* **Remote Diagnostic Log** — A history of vitals stored in Firebase for doctor review

## Key Findings
* **High Accuracy:** The fall detection algorithm demonstrated high reliability using 3-axis acceleration thresholds.
* **Reduced Latency:** Edge processing allowed for local data validation before cloud transmission, ensuring high data integrity.
* **Scalability:** The architecture supports interoperability with multiple wearable devices, providing a scalable foundation for regional health monitoring.

## Tools Used
| Tool | Purpose |
| :--- | :--- |
| **Python** | Edge analytics, cloud synchronization, and anomaly logic |
| **Embedded C** | Sensor calibration and hardware-level data acquisition |
| **Firebase** | Real-time NoSQL database for cloud-to-mobile interoperability |
| **ThinkSpeak** | Secondary IoT data visualization and channel management |
| **Android / Java** | Mobile application development for caregiver alerts |

## Files in This Repository

├── src/
│   ├── main_gateway.py        # Python logic for anomaly detection & Firebase sync
│   └── sensor_integration.c   # Embedded C for sensor acquisition & calibration
├── docs/
│   ├── SPARTAN_Thesis.pdf     # 2021 Engineering Thesis (Methodology & Results)
│   └── Final_Review.pdf       # Technical presentation deck for final defense
├── images/
│   ├── System_Architecture.jpg # High-level IoMT data flow diagram
│   ├── Hardware_Prototype.jpg # Physical assembly (Jetson Nano + Sensors)
│   ├── qt1.jpg                # GUI for real-time vitals monitoring
│   └── qt2.png                # Dashboard for historical tracking & alerts
└── README.md                  # Main documentation and business-case summary


## The Team
This project was developed as a collaborative final year Capstone Project:
* **Joshua Manoj**
* **Roshan Raj A**
* **Kishore M**

**Supervisor:** Dr. D. Egfin Nirmala, Prof & Head, ECE Department.

## Author
**Joshua Manoj**
Data Analyst | B.Eng Electronics & Communications | Business Management Diploma | Google Data Analytics Certified
LinkedIn · Tableau Public
