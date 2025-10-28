# The path planning of mobile robot by hierarchical reinforcement-learning 🚀  

### Project Overview  
This repository contains the source code, hardware schematics, and documentation for an **autonomous mobile robot** designed to **mitigate infection transmission in healthcare environments**.  

By leveraging **Hierarchical Reinforcement Learning (HRL)**, the robot autonomously navigates **complex, dynamic environments** (such as hospital wards) to deliver essential items like food and medicine directly to patients’ beds — minimizing physical interaction between patients and nursing staff during infectious outbreaks.  

This project was developed as part of the **Final Year Interim Report** for the **Bachelor of Science in Engineering (Electronics & Telecommunication)** at **Sri Lanka Technological Campus (SLTC)**.

---

## ✨ Key Features
- **Infection Risk Mitigation** — Reduces high-risk contact between healthcare workers and infected patients.  
- **Autonomous Navigation** — Navigates cluttered and dynamic hospital environments safely.  
- **Hierarchical Reinforcement Learning (HRL)** — Divides learning into layered sub-tasks for faster, more adaptive decision-making.  
- **Real-Time Adaptation** — Reacts to sudden dynamic obstacles using computer vision and optimization algorithms.  

---

## 💻 Technology Stack

| **Category** | **Component / Technique** | **Purpose** |
|---------------|---------------------------|--------------|
| **Control Board** | ESP32 DevKit | Main controller for processing sensor data and motor control |
| **Path Planning Core** | Hierarchical Reinforcement Learning (HRL) | Core AI for multi-step navigation and decision-making |
| **Obstacle Detection** | HC-SR04 Ultrasonic Sensor | Real-time proximity detection and static obstacle avoidance |
| **Shortest Path** | Zigbee Modules | Wireless communication and triangulation for efficient routing |
| **Dynamic Navigation** | 5MP Camera + Simulated Annealing Algorithm | Visual obstacle detection and optimized evasive pathfinding |
| **Motor Driver** | L298N | Speed and direction control of DC motors |
| **Simulation Tools** | MATLAB / V-REP (CoppeliaSim) | Simulation, validation, and testing of navigation algorithms |

---

## 🧠 Hierarchical Reinforcement Learning (HRL) Approach  

The HRL framework divides the robot’s overall “delivery” task into smaller, structured phases for faster learning and adaptability:

### **Phase 1: Static Obstacle Identification & Avoidance**
- **Goal:** Establish safe mobility in a static environment.  
- **Mechanism:** Uses ultrasonic sensors and HRL-based rules to detect, stop, and avoid obstacles.

### **Phase 2: Shortest Path Planning (Static Environment)**
- **Goal:** Optimize travel path for minimal distance and time.  
- **Mechanism:** Integrates Zigbee-based position tracking and HRL policies for efficient navigation.

### **Phase 3: Dynamic Environment Navigation**
- **Goal:** Handle moving obstacles and sudden changes in real-time.  
- **Mechanism:** A 5MP camera captures dynamic scenes while the HRL model, enhanced with the **Simulated Annealing Algorithm**, computes optimal paths instantly.

---

## 🛠️ Setup and Installation

### **Hardware Prerequisites**
- ESP32 Development Board  
- L298N Motor Driver  
- HC-SR04 Ultrasonic Sensor  
- Two Zigbee transceiver modules  
- 5MP USB Camera  
- Four-motor differential drive mobile robot chassis  

### **Software Requirements**
- **Arduino IDE / PlatformIO** → ESP32 firmware development  
- **Python 3.x** → HRL training and simulation scripts  
- **MATLAB / V-REP (CoppeliaSim)** → Simulation and performance testing  

**Python Libraries:**  
`TensorFlow` / `PyTorch`, `NumPy`, `Matplotlib`, and optionally `ROS` or `OMPL` for path planning frameworks.  

---

## 📊 Results and Validation  
- Tested in simulated healthcare environments representing hospital wards.  
- The robot accurately identified and reached target beds autonomously.  
- Navigation precision and speed were **comparable to or better than** manual operation.  
- The HRL model successfully balanced **long-term navigation goals** and **immediate obstacle avoidance**.  

---
