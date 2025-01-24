![currentSensor](https://github.com/user-attachments/assets/5c241b1c-ebe2-499f-a19f-a1f04cfac854)


# Arduino AC Current Measurement with ADS1115 and ACS712 (5A ver)
This project uses an Arduino and the ADS1115 ADC to calculate the RMS (Root Mean Square) current from an AC signal. The script demonstrates how to read high-precision ADC values, calibrate the sensor, and compute RMS current in real-time.

A Fluke 17B+ was placed on the single phase line to compare the results. It was accurate to within 2mA in the range of 1mA to 1.2A

# Features
RMS Current Measurement: Captures AC current measurements and calculates the RMS value.

Custom Calibration: Includes adjustable parameters for calibration (zero-point and counts per ampere).

Real-Time Output: Outputs results via the Arduino Serial Monitor (baud rate 115200)

# Components
Arduino: Microcontroller to process the ADC data and calculate RMS current.

ADS1115: High-resolution ADC for precise signal conversion.

ADS712: Hall-effect linear current sensor (5 amp version)

# Wiring Diagram (see picture)
Connect the analog output of the current sensor to channel 0 (AIN0) on the ADS1115.
Connect the ADS1115 to the Arduino via I2C (SDA and SCL pins).
Ensure proper power connections for the ADS1115 and Arduino.

# Output
The output is printed to the serial monitor as comma-sperated values.

Timestamp (milliseconds) - Time since arduino powered up

RMS current (in amperes) - To 3 decimal values



