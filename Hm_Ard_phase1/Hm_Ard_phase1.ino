int forceSensorPin = A0; // set the analog pin connected to the force sensor
float referenceVoltage = 5.0; // set the reference voltage used for the force sensor
float forceSensorResistance = 0; // initialize variable for the force sensor resistance
float forceSensorVoltage = 0; // initialize variable for the force sensor voltage
float forceSensorForce = 0; // initialize variable for the force sensor force
float bottleVolume = 500; // set the volume of the water bottle in milliliters
float calibrationFactor = 10; // set the calibration factor (depends on the specific force sensor)
float currentVolume = bottleVolume; // initialize variable for the current water volume

void setup() {
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  forceSensorVoltage = (referenceVoltage * (analogRead(forceSensorPin) / 1023.0));
  forceSensorResistance = forceSensorVoltage * 10000.0 / (referenceVoltage - forceSensorVoltage);
  forceSensorForce = forceSensorResistance / calibrationFactor; // convert the resistance to force using the calibration factor
  currentVolume = (forceSensorForce / 1000.0) * bottleVolume; // convert force to volume in milliliters
  
  if (currentVolume < 500) {
    Serial.println("Keep Drinking! Current volume: " + String(currentVolume) + " ml");
    // send a message to the computer (can be modified to send an email or trigger an alert)
  }
  
  delay(1000); // wait for 1 second before checking the water level again
}
