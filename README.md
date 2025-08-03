#AVR_ATmega32
Drivers for peripherals in ATmega32
This repository contains C language drivers and modules for the ATmega32 microcontroller 
GitHub
+13
GitHub
+13
GitHub
+13
.

🚀 Overview
Organized in a modular architecture, this repo includes:

MCAL (Microcontroller Abstraction Layer): GPIO, UART, SPI, I2C, ADC, Timers, EEPROM, Seven‑segment, Keypad, etc.

HAL/Application layer modules built upon the MCAL drivers for easy interfacing.

Common utilities such as std_macros, std_types, and configuration headers in a LIB folder.

📁 Repository Structure
bash
نسخ
تحرير
AVR_ATmega32/
├── MCAL/                  # Low-level peripheral drivers
│   ├── GPIO/
│   ├── UART/
│   ├── SPI/
│   ├── I2C/
│   ├── ADC/
│   ├── Timer0/
│   ├── EEPROM/
│   └── Seven_seg/
├── HAL/                   # Higher-level modules and applications
├── LIB/                   # Shared headers, types, macros, config
└── README.md              # This file
📦 Included Drivers & Modules
GPIO (digital I/O)

SPI (Serial Peripheral Interface)

I2C (TWI interface)

UART (serial communication)

ADC (analog-to-digital conversion)

Timer0 (system timing)

EEPROM (on-chip non-volatile memory)

Seven‑segment display

Keypad input module

HAL-level drivers built on top of these (e.g. LCD, buzzer, motor control)

This folder layout mirrors other ATmega32 driver repos such as those by Esraa‑alii, Mohamed Ghoraba, Ahmed Elmougy, etc. 
GitHub
+1
GitHub
+1
GitHub
+5
GitHub
+5
GitHub
+5
GitHub
GitHub
GitHub
+1
GitHub
+1

