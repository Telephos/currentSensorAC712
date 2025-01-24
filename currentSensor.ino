#include "ADS1X15.h"

ADS1115 ADS(0x49);

void setup() 
{
  Serial.begin(115200);
  //Serial.println(__FILE__);
  //Serial.print("ADS1X15_LIB_VERSION: ");
  //Serial.println(ADS1X15_LIB_VERSION);

  Wire.begin();
  ADS.begin();
  ADS.setGain(1);  // Set gain to ±4.096V range

}

void loop() 
{
  int noSamples = 50;
  float sensorValue = 0.0;  // Declare sensorValue here
  float sumSquare = 0.0;
  float rmsCurrent = 0.0;
  float mTime;
  

  //This is suppose to be the starting point of the ADC when NO CURRENT flows through
  int zeroPoint = 20109;

  //Attempting to treat the change in sensor value the same as we do the RMS current. 
  //Since average value only gives us the zero point
  float rmsSensorVal = 0.0;
  float sumSquareSensor = 0.0;

  // Calibration factor based on data (1850 counts per ampere)
  //THIS IS WHAT WE NEED TO CHANGE
  //We need to calibrate this with a power rheostat and power resistor such that we can vary the current (AC rms) to any 
  float countsPerAmpere = 1000.0;

  for(int i = 0; i < noSamples; i++) {
    int16_t val_0 = ADS.readADC(0);  // Read ADC value
    sensorValue = val_0;
    
    // Calculate current based on calibration
    float instantCurrent = (sensorValue - zeroPoint) / countsPerAmpere;  // Subtract zero-current offset and scale
    sumSquare += instantCurrent * instantCurrent;  // Accumulate square of current

    //float instantSensor =()
    //float instantSensor = sensorValue - zeroPoint;
    //sumSquareSensor += instantSensor * instantSensor;

  }

  rmsCurrent = sqrt(sumSquare / noSamples);

  mTime = millis();

  // Print results
  Serial.print(mTime);
  Serial.print(",");
  //Serial.print(sumSquareSensor, 0);
  //Serial.print(",");
  Serial.print(rmsCurrent, 3);
  Serial.println();

  delay(10);  // Short delay before next reading
}
