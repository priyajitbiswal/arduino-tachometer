SEM-2 Engineering Physics Group Project

# 🔁 Tachometer using Arduino & LCD (Contactless)

This project is a **contactless tachometer** that measures the **rotational speed (RPM)** of a rotating object, such as a wheel or motor shaft, using an **infrared sensor or magnetic switch** connected to an Arduino. The measured RPM is displayed in real time on a **16x2 I2C LCD display**.

## 🚀 Features

* Real-time **RPM (Revolutions Per Minute)** measurement
* Display output via **I2C LCD**
* Simple, clean, and contactless design using sensor-based detection
* Lightweight and portable setup

## 🧾 How It Works

1. A sensor (like IR sensor or magnetic reed switch) is connected to analog pin **A0**.
2. Each time the sensor detects a revolution, the count (`x`) is incremented.
3. After every **5 seconds**, the RPM is calculated using:

   ```
   RPM = (12 * x) / 4
   ```

   *(This assumes 12 signal pulses per revolution; adjust according to your setup.)*
4. The calculated RPM is displayed on the **LCD**.

> ℹ️ You can calibrate the `12` in the formula depending on the number of pulses generated per revolution by your specific sensor setup.

---

## 🧠 Components Used

* Arduino Uno (or any compatible board)
* IR sensor / Hall effect sensor / magnetic reed switch
* 16x2 I2C LCD Display (address: 0x27)
* Jumper wires

---

## ⚙️ Wiring

| Component          | Arduino Pin |
| ------------------ | ----------- |
| IR/Magnetic Sensor | A0          |
| I2C LCD SDA        | A4 (Uno)    |
| I2C LCD SCL        | A5 (Uno)    |

---

## 🧪 Sample Output (on LCD)

```
 Tachometer (WC)
 1200     =RPM
```

---

## 📋 Arduino Code Overview

```cpp
int input = A0;
long pt = millis();  // previous timestamp
int x = 0;           // pulse count
...
rev = 12 * x / 4;    // RPM calculation formula
```

* `x`: Counts pulses from the sensor
* `pt` and `ct`: Time tracking for 5-second intervals
* `rev`: Calculated RPM displayed on LCD

---

## 🔧 Calibration Notes

* Adjust the formula `rev = 12 * x / 4` if:

  * You get 1 pulse per revolution → `rev = (60 / 5) * x = 12 * x`
  * You get **N** pulses per revolution → `rev = (60 / 5) * (x / N)`

---

## 📈 Applications

* Motor speed monitoring
* Windmill RPM measurement
* Automotive wheel speed detection
* Rotating machinery diagnostics

---

## 🛠 Future Improvements

* Add serial plotter for graphical RPM tracking
* Include button to reset RPM
* Display average/max RPM during session
* Bluetooth/IoT integration for remote monitoring
