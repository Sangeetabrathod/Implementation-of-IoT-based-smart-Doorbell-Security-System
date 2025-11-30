# 📘 IoT Based Smart Doorbell Security System

## 🏠 Project Overview
The **IoT-Based Smart Doorbell Security System** is a smart home-security solution that allows users to monitor visitors remotely through real-time alerts, video/image streaming, and motion detection.  
This system uses **ESP32-CAM / Raspberry Pi**, **PIR motion sensors**, and **cloud platforms** (MQTT, Firebase, Blynk) to ensure continuous monitoring and instant notifications.

This project integrates both **Electronics (ECE)** and **Computer Science (IoT + Embedded + Networking)** skills, making it ideal for academic submissions and placement portfolios.

---

## 🎯 Key Features
- ✔ Real-time camera streaming (ESP32-CAM or Pi Camera)  
- ✔ Motion Detection using PIR sensor  
- ✔ Instant notifications to mobile (MQTT, Blynk, Telegram, Firebase)  
- ✔ Doorbell press detection + automatic snapshot  
- ✔ Cloud-based visitor logging  
- ✔ Night vision support (IR LEDs)  
- ✔ Low-power and cost-effective system  
- ✔ Remote monitoring from anywhere  

---

## 🛠 Technologies Used

### **Hardware**
- ESP32-CAM / Raspberry Pi  
- PIR Motion Sensor (HC-SR501)  
- Push Button (Doorbell)  
- Buzzer  
- Jumper wires  
- 5V Power supply  

### **Software / Cloud**
- Arduino IDE / Python  
- MQTT Protocol  
- Firebase / Thingspeak / Blynk  
- HTML Web Server (optional)  
- Embedded C / C++  

---

## 🔁 System Architecture

1. PIR sensor detects motion or the doorbell is pressed.  
2. ESP32/Raspberry Pi captures an image or starts live video.  
3. Device sends a real-time alert to the cloud.  
4. Cloud pushes a mobile notification.  
5. User logs in to view the visitor via live stream.  
6. Event stored in cloud for security logging.

---

## 📡 Workflow Diagram

[PIR Sensor / Doorbell Button]
↓
[ESP32-CAM]
↓
Capture Image / Video
↓
Send Data to Cloud Platform
↓
Mobile Notification to User
↓
Remote Live Monitoring

yaml
Copy code

---

## 🧰 Installation & Setup

### **1️⃣ Hardware Connections**

| Component | ESP32-CAM Pin |
|----------|----------------|
| PIR OUT  | GPIO 13        |
| Button   | GPIO 14        |
| Buzzer   | GPIO 12        |
| 5V Input | 5V             |
| Ground   | GND            |

---

### **2️⃣ Software Setup (ESP32-CAM)**

1. Install the **Arduino IDE**.  
2. Install the **ESP32 Board Package** from Boards Manager.  
3. Install required libraries:  
   - WiFi.h  
   - ESPAsyncWebServer  
   - PubSubClient (MQTT)  
4. Add your Wi-Fi credentials in the code.  
5. Upload code using **FTDI USB-to-Serial Programmer**.  
6. Open Serial Monitor → Note the IP Address.  

---

### **3️⃣ Cloud Setup Options**

### ▶ Using **Blynk**  
- Create a new device  
- Add:  
  - Notification widget  
  - Image frame widget  
- Copy Auth Token → Paste in code  

### ▶ Using **Firebase**  
- Create Firebase project  
- Enable Realtime Database  
- Add API Keys into code  

### ▶ Using **MQTT (HiveMQ/AdafruitIO)**  
- Create broker  
- Create topic:  
  `/doorbell/alert`  

---

## 📸 Output

- Live camera stream accessible on mobile  
- Real-time motion alerts  
- Doorbell-triggered snapshot  
- Cloud-stored visitor logs  
- Accessible anywhere via Internet  

---

## 📂 Project Structure

Smart-Doorbell-Security/
│── code/
│ ├── esp32_cam_doorbell.ino
│ ├── mqtt_config.h
│
│── images/
│ ├── system_architecture.png
│
│── README.md

yaml
Copy code

---

## 💡 Applications

- Home door security  
- Apartments & PG hostels  
- Offices & shops  
- Remote monitoring systems  
- Smart home automation  

---

## 🎓 Learning Outcomes

- IoT system architecture  
- Embedded systems with ESP32  
- Sensor interfacing  
- Real-time notifications  
- Cloud platform integration  
- Wireless networking  
- Video streaming over Wi-Fi  

---

## 💼 Resume Bullet Points

- Designed and developed an **IoT-based Smart Doorbell Security System** using ESP32-CAM for live video streaming and visitor monitoring.  
- Implemented **motion detection, mobile push notifications**, and **cloud storage** using MQTT/Firebase.  
- Built a **real-time monitoring dashboard** for remote accessibility via smartphone.  
- Integrated camera module with embedded C/C++ for **edge-based image capture and processing**.  

---

## 🙌 Contributions
Feel free to fork this repository, open issues, or submit pull requests to enhance the project.

---

## 📧 Contact
For doubts or improvements, connect anytime!
