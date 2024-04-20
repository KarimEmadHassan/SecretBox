Secret Box Monitor

This project is a security device designed to monitor a box's status and send notifications via Telegram when it's opened or falls. It utilizes an ESP32 microcontroller and various sensors to achieve this functionality.

Hardware Components:

1. ESP32 Microcontroller
2. Built-in Rechargeable Battery
3. LCD Display
4. Buzzer
5. Ultrasonic Sensor
6. MPU6050 Accelerometer and Gyroscope

How it Works:
The Secret Box Monitor operates in two primary scenarios:

Box Opened: The ultrasonic sensor detects a change in distance (increase in height) when the box is opened. This triggers the following actions:

            A Telegram bot notification is sent to the user's device.

            The buzzer sounds as an alert until the box is closed again, resetting the ultrasonic sensor.

Box Falling: The MPU6050 sensor detects an inclination angle exceeding the fall threshold, indicating the box is about to fall. This prompts:

             A Telegram notification is sent to the user's device.

             The buzzer activates as an alert.

Upcoming Features:

OLED Screen Replacement: The current crystal LCD display will be upgraded to an OLED screen for improved visibility and potentially lower power consumption.

Reset Button Implementation: A reset button will be added to allow manual resetting of the device's status or configuration.

Telegram Command Interface: Users will be able to send commands to the device via Telegram for remote interaction (exact functionality to be determined).

Firebase Notification Uploads: Notifications will be uploaded to a Firebase database for potential logging, analysis, or integration with other systems.

Notification Confirmation with EEPROM: The internal EEPROM memory of the ESP32 will be used to store a flag indicating a notification has been sent successfully, preventing redundant transmissions.

Wi-Fi Network Scanning and Bluetooth Connection: The device will be able to scan for available Wi-Fi networks and connect to one using Bluetooth for configuration or data transfer (specific implementation details to be explored).
