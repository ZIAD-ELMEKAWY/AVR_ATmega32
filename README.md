# AVR_ATmega32 Projects

This repository contains various projects and code examples developed for the AVR ATmega32 microcontroller. It serves as a collection of embedded systems applications, demonstrations, and utilities utilizing the ATmega32's features and peripherals.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Overview

The `AVR_ATmega32` repository is dedicated to projects built around the Atmel (now Microchip) ATmega32 microcontroller. This MCU is widely used in embedded systems due to its versatility, rich set of peripherals, and ease of programming. This collection aims to provide practical examples and solutions for common embedded programming tasks, ranging from basic I/O operations to more complex peripheral interactions.

## Features

While specific features will vary by project, common functionalities you might find include:

-   **GPIO Control:** Examples for controlling digital inputs/outputs (LEDs, buttons).
-   **Timers/Counters:** Demonstrations of using timers for delays, PWM generation, and event counting.
-   **Interrupts:** Code illustrating external and internal interrupt handling.
-   **UART Communication:** Examples for serial communication with other devices (e.g., PC, other microcontrollers).
-   **SPI/I2C Communication:** Projects showcasing inter-device communication protocols.
-   **ADC Conversion:** Examples for analog-to-digital conversion using the ATmega32's ADC.
-   **EEPROM Operations:** Demonstrations of reading from and writing to the internal EEPROM.
-   **LCD/Seven-Segment Displays:** Interfacing with various display technologies.
-   **Sensor Interfacing:** Examples of connecting and reading data from different sensors.

## Getting Started

To get started with these projects, you will need the necessary hardware and software tools for AVR development.

### Prerequisites

-   **AVR ATmega32 Microcontroller:** The target hardware.
-   **Programmer/Debugger:** An AVR ISP programmer (e.g., USBasp, AVR Dragon) or an in-circuit debugger.
-   **Development Board (Optional):** A development board designed for ATmega32 can simplify prototyping.
-   **Power Supply:** A regulated 5V DC power supply for the microcontroller.

### Installation

1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/ZIAD-ELMEKAWY/AVR_ATmega32.git](https://github.com/ZIAD-ELMEKAWY/AVR_ATmega32.git)
    ```
2.  **Navigate to a Project Directory:**
    ```bash
    cd AVR_ATmega32/<project_name>
    ```
3.  **Software Tools:**
    -   **AVR-GCC Toolchain:** For compiling C/C++ code for AVR microcontrollers.
        -   On Linux: Install `avr-libc` and `binutils-avr` via your package manager.
        -   On Windows: Use Atmel Studio or install WinAVR.
    -   **Make:** A build automation tool.
    -   **AVRDude:** For flashing compiled code to the microcontroller.

## Usage

Each project within this repository will typically have its own dedicated folder containing:

-   **Source Code (.c/.h files):** The main application logic.
-   **Makefile:** For compiling and flashing the code.
-   **Schematics (Optional):** Diagrams illustrating hardware connections.
-   **Documentation (Optional):** Specific notes or instructions for the project.

To build and flash a project:

1.  Navigate to the specific project directory.
2.  Open a terminal or command prompt.
3.  Compile the code using the provided Makefile:
    ```bash
    make all
    ```
4.  Flash the compiled `.hex` file to your ATmega32 microcontroller using AVRDude (ensure your programmer is connected and configured correctly in the Makefile):
    ```bash
    make flash
    ```

Refer to the individual project folders for detailed instructions and explanations.

## Contributing

Contributions are welcome! If you have projects, bug fixes, or improvements related to the ATmega32, please feel free to:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/YourFeature`).
3.  Make your changes.
4.  Commit your changes (`git commit -m 'Add some feature'`).
5.  Push to the branch (`git push origin feature/YourFeature`).
6.  Open a Pull Request.

Please ensure your code adheres to good practices and includes appropriate documentation.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT) - see the [LICENSE](LICENSE) file for details.

## Contact

For any questions or suggestions, please open an issue on this repository or contact [ZIAD-ELMEKAWY](https://github.com/ZIAD-ELMEKAWY).
