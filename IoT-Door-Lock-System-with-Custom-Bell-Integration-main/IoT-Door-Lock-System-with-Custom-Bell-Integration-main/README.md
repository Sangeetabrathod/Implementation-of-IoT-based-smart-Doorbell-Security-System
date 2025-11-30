# IoT Door Lock System with Custom Bell Integration 🚪🔒

This repository showcases the implementation of an **IoT-based Door Lock System** integrated with a **custom doorbell trigger system**. The system combines the power of the **ESP32 Cam Dev Board**, **Blynk IoT App**, and embedded programming to provide a secure and efficient door-locking mechanism. It enables **real-time password authentication** for unlocking the door, while capturing and transmitting doorbell-triggered photos for enhanced security.

---

## 🌟 Key Features

1. **Secure Door Unlocking**:
   - Unlock the door by securely entering a **password** via the **Blynk IoT App**.
   - Password-based authentication ensures robust protection.

2. **Custom Bell Integration**:
   - Utilizes the **ESP32's GPIO pins** to detect doorbell activation.
   - Automatically triggers the **OV2640 camera module** to capture images upon doorbell press.

3. **Image Transmission**:
   - Captured images are seamlessly transmitted to the **Blynk IoT App**, allowing for **immediate viewing** on a smartphone.

4. **IoT Connectivity**:
   - Fully integrated with the **Blynk IoT platform** for remote control and monitoring.
   - Real-time synchronization between the ESP32 Cam and the Blynk app.

---

## 🔑 Technical Highlights

- **ESP32 Cam Development Board**: Core microcontroller for IoT and camera functionalities.
- **OV2640 Camera Module**: High-quality image capture upon doorbell press.
- **Blynk IoT App**: User-friendly interface for password input, image viewing, and system control.
- **Real-Time Trigger System**: Responsive activation of the camera and GPIO monitoring for doorbell events.
- **Embedded Programming**: Efficient implementation in **C** for real-time IoT operations.

---

## 🛠 System Workflow

1. **Door Lock Mechanism**:
   - Users can securely unlock the door using the **Blynk IoT App** by entering the correct password.

2. **Doorbell Integration**:
   - Pressing the doorbell triggers:
     - Activation of the **OV2640 camera module** via the **ESP32 GPIO pins**.
     - Capture of the visitor's image, which is then transmitted to the **Blynk IoT App**.

3. **Real-Time Feedback**:
   - The Blynk app displays the captured images for immediate security checks.
   - Users can remotely monitor and control the door-lock system.

---

## 🚀 How to Use

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/IoT-Door-Lock-System.git
   cd IoT-Door-Lock-System
