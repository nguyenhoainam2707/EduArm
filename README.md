# EduArm - 5-DOF Robot Arm with Bare Metal Programming# EduArm - 5-DOF Robot Arm with Bare Metal Programming



![Project Banner](path/to/your/image.jpg)![Project Banner](path/to/your/image.jpg)



## 📋 Overview## 📋 Overview



A 5-DOF (5 Degrees of Freedom) robot arm control project using ATmega328P microcontroller with **bare-metal programming** (direct register manipulation). The system features an innovative control method using a miniature replica of the robot arm equipped with potentiometers at each joint to measure rotation angles, which then drives the full-scale robot arm to mimic the corresponding movements in real-time.A 5-DOF (5 Degrees of Freedom) robot arm control project using ATmega328P microcontroller with **bare-metal programming** (direct register manipulation). The system features an innovative control method using a miniature replica of the robot arm equipped with potentiometers at each joint to measure rotation angles, which then drives the full-scale robot arm to mimic the corresponding movements in real-time.



------



## ✨ Key Features## ✨ Key Features



- 🤖 **5 Degrees of Freedom** - Control 6 independent servo motors- 🤖 **5 Degrees of Freedom** - Control 6 independent servo motors

- 🎮 **Intuitive Control** - Physical miniature model with potentiometers at each joint- 🎮 **Intuitive Control** - Physical miniature model with potentiometers at each joint

- ⚙️ **Bare Metal Programming** - Low-level programming on ATmega328P with direct register manipulation- ⚙️ **Bare Metal Programming** - Low-level programming on ATmega328P with direct register manipulation

- 🔧 **Dual Implementation** - Both bare-metal and high-level (Arduino) versions available- 🔧 **Dual Implementation** - Both bare-metal and high-level (Arduino) versions available

- ⏱️ **Timer Interrupt Driven** - Uses Timer1 CTC mode for precise PWM signal generation- ⏱️ **Timer Interrupt Driven** - Uses Timer1 CTC mode for precise PWM signal generation

- 📊 **High ADC Precision** - Reads 6 ADC channels from potentiometers with 10-bit resolution- 📊 **High ADC Precision** - Reads 6 ADC channels from potentiometers with 10-bit resolution



------



## 🎬 Demo## 🎬 Demo



<!-- Add your demo video link here --><!-- Add your demo video link here -->

[![Demo Video](https://img.youtube.com/vi/YOUR_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID)[![Demo Video](https://img.youtube.com/vi/YOUR_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID)



📹 [Watch demo video on YouTube](YOUR_YOUTUBE_LINK)📹 [Watch demo video on YouTube](YOUR_YOUTUBE_LINK)



------



## 🖼️ Product Images## 🖼️ Product Images



<!-- Add your images here --><!-- Add your images here -->

<table><table>

  <tr>  <tr>

    <td><img src="path/to/image1.jpg" alt="Robot Arm Front View" width="300"/></td>    <td><img src="path/to/image1.jpg" alt="Robot Arm Front View" width="300"/></td>

    <td><img src="path/to/image2.jpg" alt="Mini Controller" width="300"/></td>    <td><img src="path/to/image2.jpg" alt="Mini Controller" width="300"/></td>

  </tr>  </tr>

  <tr>  <tr>

    <td align="center"><b>Main Robot Arm</b></td>    <td align="center"><b>Main Robot Arm</b></td>

    <td align="center"><b>Miniature Controller</b></td>    <td align="center"><b>Miniature Controller</b></td>

  </tr>  </tr>

  <tr>  <tr>

    <td><img src="path/to/image3.jpg" alt="Full System" width="300"/></td>    <td><img src="path/to/image3.jpg" alt="Full System" width="300"/></td>

    <td><img src="path/to/image4.jpg" alt="Circuit Board" width="300"/></td>    <td><img src="path/to/image4.jpg" alt="Circuit Board" width="300"/></td>

  </tr>  </tr>

  <tr>  <tr>

    <td align="center"><b>Complete System</b></td>    <td align="center"><b>Complete System</b></td>

    <td align="center"><b>Control Circuit</b></td>    <td align="center"><b>Control Circuit</b></td>

  </tr>  </tr>

</table></table>



------



## 🔧 Hardware## 🔧 Hardware



### Main Components### Main Components



- **Microcontroller:** ATmega328P (Arduino Uno/Nano)- **Microcontroller:** ATmega328P (Arduino Uno/Nano)

- **Servo Motors:** 6x Servo (MG996R or equivalent)- **Servo Motors:** 6x Servo (MG996R or equivalent)

- **Potentiometers:** 6x 10kΩ- **Potentiometers:** 6x 10kΩ

- **Power Supply:** 5-6V (separate for servos)- **Power Supply:** 5-6V (separate for servos)



### Connection Diagram### Connection Diagram



#### Servo Motors#### Servo Motors

| Servo | Pin | Description || Servo | Pin | Description |

|-------|-----|-------------||-------|-----|-------------|

| S0 | D2 | Base rotation || S0 | D2 | Base rotation |

| S1 | D3 | Shoulder || S1 | D3 | Shoulder |

| S2 | D4 | Elbow || S2 | D4 | Elbow |

| S3 | D5 | Wrist || S3 | D5 | Wrist |

| S4 | D6 | Wrist rotation || S4 | D6 | Wrist rotation |

| S5 | D7 | Gripper || S5 | D7 | Gripper |



#### Potentiometers (Analog Input)#### Potentiometers (Analog Input)

| Potentiometer | Pin | Corresponding Joint || Potentiometer | Pin | Corresponding Joint |

|---------------|-----|---------------------||---------------|-----|---------------------|

| POT0 | A0 | Base || POT0 | A0 | Base |

| POT1 | A1 | Shoulder || POT1 | A1 | Shoulder |

| POT2 | A2 | Elbow || POT2 | A2 | Elbow |

| POT3 | A3 | Wrist || POT3 | A3 | Wrist |

| POT4 | A4 | Wrist rotation || POT4 | A4 | Wrist rotation |

| POT5 | A5 | Gripper || POT5 | A5 | Gripper |



------



## 💻 Software## 💻 Software



### Project Structure### Project Structure



``````

EduArm/EduArm/

├── EduArm_Bare_Metal_Programming.ino    # Bare-metal implementation├── EduArm_Bare_Metal_Programming.ino    # Bare-metal implementation

├── EduArm_High_Level_Programming.ino    # Arduino library implementation├── EduArm_High_Level_Programming.ino    # Arduino library implementation

└── README.md└── README.md

``````



### 1. Bare Metal Programming (EduArm_Bare_Metal_Programming.ino)### 1. Bare Metal Programming (EduArm_Bare_Metal_Programming.ino)



This version uses low-level programming with the following features:This version uses low-level programming with the following features:



- **Timer1 CTC Mode**: Generates PWM signals for 6 servos with 20ms period- **Timer1 CTC Mode**: Generates PWM signals for 6 servos with 20ms period

- **Interrupt Service Routine (ISR)**: Implements state machine to control each servo- **Interrupt Service Routine (ISR)**: Implements state machine to control each servo

- **ADC Manual Configuration**: Configures and reads ADC through direct register manipulation- **ADC Manual Configuration**: Configures and reads ADC through direct register manipulation

- **Direct Register Manipulation**: No Arduino libraries used- **Direct Register Manipulation**: No Arduino libraries used



#### Working Principle#### Working Principle



```cpp```cpp

// Timer1 CTC mode with prescaler = 8// Timer1 CTC mode with prescaler = 8

// OCR1A determines interrupt timing// OCR1A determines interrupt timing

// State machine toggles between ON/OFF states for each servo// State machine toggles between ON/OFF states for each servo

ISR(TIMER1_COMPA_vect) {ISR(TIMER1_COMPA_vect) {

    // Toggle servo state    // Toggle servo state

    // Update OCR1A for next interrupt    // Update OCR1A for next interrupt

}}

``````



**Technical Specifications:****Technical Specifications:**

- CPU Frequency: 16MHz- CPU Frequency: 16MHz

- Prescaler: 8 (Timer ticks every 0.5μs)- Prescaler: 8 (Timer ticks every 0.5μs)

- PWM Period: ~20ms (50Hz)- PWM Period: ~20ms (50Hz)

- Pulse Width: 460μs - 2520μs (servo dependent)- Pulse Width: 460μs - 2520μs (servo dependent)



### 2. High-Level Programming (EduArm_High_Level_Programming.ino)### 2. High-Level Programming (EduArm_High_Level_Programming.ino)



Simplified version using Arduino's Servo library:Simplified version using Arduino's Servo library:



- **Servo Library**: Uses `Servo.h` for control- **Servo Library**: Uses `Servo.h` for control

- **analogRead()**: Reads potentiometer values- **analogRead()**: Reads potentiometer values

- **map()**: Converts ADC values to microseconds- **map()**: Converts ADC values to microseconds

- **Easier to understand and maintain**- **Easier to understand and maintain**



------



## 🚀 Installation & Usage## 🚀 Installation & Usage



### Requirements### Requirements



- Arduino IDE 1.8+ or PlatformIO- Arduino IDE 1.8+ or PlatformIO

- Board: Arduino Uno/Nano (ATmega328P)- Board: Arduino Uno/Nano (ATmega328P)

- Libraries: Servo (only for high-level version)- Libraries: Servo (only for high-level version)



### Instructions### Instructions



1. **Clone repository:**1. **Clone repository:**

```bash```bash

git clone https://github.com/nguyenhoainam2707/EduArm.gitgit clone https://github.com/nguyenhoainam2707/EduArm.git

cd EduArmcd EduArm

``````



2. **Open code file:**2. **Open code file:**

   - Bare-metal: `EduArm_Bare_Metal_Programming.ino`   - Bare-metal: `EduArm_Bare_Metal_Programming.ino`

   - High-level: `EduArm_High_Level_Programming.ino`   - High-level: `EduArm_High_Level_Programming.ino`



3. **Calibration:**3. **Calibration:**

   - Measure min/max ADC values for each potentiometer   - Measure min/max ADC values for each potentiometer

   - Measure min/max pulse width for each servo   - Measure min/max pulse width for each servo

   - Update macros `MIN_A0`, `MAX_A0`, `MIN_S0`, `MAX_S0`, etc.   - Update macros `MIN_A0`, `MAX_A0`, `MIN_S0`, `MAX_S0`, etc.



4. **Upload code:**4. **Upload code:**

   - Select board: Arduino Uno/Nano   - Select board: Arduino Uno/Nano

   - Select COM port   - Select COM port

   - Upload code   - Upload code



5. **Testing:**5. **Testing:**

   - Open Serial Monitor (9600 baud)   - Open Serial Monitor (9600 baud)

   - Rotate joints on the miniature model   - Rotate joints on the miniature model

   - Observe the robot arm moving accordingly   - Observe the robot arm moving accordingly



------



## 📚 Applied Knowledge## 📚 Applied Knowledge



### Bare-Metal Programming Concepts### Bare-Metal Programming Concepts



1. **Timer/Counter Configuration**1. **Timer/Counter Configuration**

   - CTC Mode (Clear Timer on Compare)   - CTC Mode (Clear Timer on Compare)

   - Output Compare Register (OCR1A)   - Output Compare Register (OCR1A)

   - Timer Interrupts   - Timer Interrupts



2. **ADC (Analog-to-Digital Converter)**2. **ADC (Analog-to-Digital Converter)**

   - Reference voltage selection   - Reference voltage selection

   - Channel multiplexing   - Channel multiplexing

   - Prescaler configuration   - Prescaler configuration

   - Conversion timing   - Conversion timing



3. **Register Manipulation**3. **Register Manipulation**

   - TCCR1B, TIMSK1 (Timer registers)   - TCCR1B, TIMSK1 (Timer registers)

   - ADMUX, ADCSRA (ADC registers)   - ADMUX, ADCSRA (ADC registers)

   - DDRD, PORTD (I/O registers)   - DDRD, PORTD (I/O registers)



4. **PWM Signal Generation**4. **PWM Signal Generation**

   - Software PWM using interrupts   - Software PWM using interrupts

   - State machine implementation   - State machine implementation

   - Precise timing control   - Precise timing control



------



## 🎯 Advanced Features (Future Work)## 🎯 Advanced Features (Future Work)



- [ ] Inverse Kinematics- [ ] Inverse Kinematics

- [ ] Position memory/playback- [ ] Position memory/playback

- [ ] Bluetooth/WiFi control- [ ] Bluetooth/WiFi control

- [ ] PC GUI interface- [ ] PC GUI interface

- [ ] Multi-point trajectory planning- [ ] Multi-point trajectory planning



------



## 📖 References## 📖 References



- [ATmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)- [ATmega328P Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)

- [Servo Motor Control Theory](https://learn.adafruit.com/adafruit-arduino-lesson-14-servo-motors)- [Servo Motor Control Theory](https://learn.adafruit.com/adafruit-arduino-lesson-14-servo-motors)

- [AVR Timer Programming](http://ww1.microchip.com/downloads/en/appnotes/doc8453.pdf)- [AVR Timer Programming](http://ww1.microchip.com/downloads/en/appnotes/doc8453.pdf)



------



## 👨‍💻 Author## 👨‍💻 Tác giả / Author



**Nguyen Hoai Nam****Nguyen Hoai Nam**



- GitHub: [@nguyenhoainam2707](https://github.com/nguyenhoainam2707)- GitHub: [@nguyenhoainam2707](https://github.com/nguyenhoainam2707)

- Email: your.email@example.com- Email: your.email@example.com



------



## 📄 License## � Giấy phép / License



This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.



------



## 🙏 Acknowledgments## � Lời cảm ơn / Acknowledgments



- Thanks to the Arduino and AVR community- Cảm ơn cộng đồng Arduino và AVR

- Reference documentation from Microchip/Atmel- Tài liệu tham khảo từ Microchip/Atmel

- Inspiration from open-source robot arm projects- Inspiration từ các dự án robot arm mã nguồn mở



------



## 📞 Contact## � Liên hệ / Contact



If you have any questions or suggestions, please create an issue or contact me directly!Nếu bạn có câu hỏi hoặc đề xuất, vui lòng tạo issue hoặc liên hệ trực tiếp!



---If you have any questions or suggestions, please create an issue or contact me directly!



<div align="center">---

  

**⭐ If you find this project useful, please give it a star! ⭐**<div align="center">

  

Made with ❤️ and ⚙️**⭐ Nếu bạn thấy project hữu ích, hãy cho một star nhé! ⭐**



</div>**⭐ If you find this project useful, please give it a star! ⭐**


Made with ❤️ and ⚙️

</div>