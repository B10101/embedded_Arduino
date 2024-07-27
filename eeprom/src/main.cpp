#include <Arduino.h>

#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  
  // Uncomment the line below if you want to write data to EEPROM on every reset
  // writeDataToEEPROM();
  
  // Read data from EEPROM and print it
  readDataFromEEPROM();
}

void loop() {
  // Your main code goes here
}

void writeDataToEEPROM() {
  // Write sample data to EEPROM
  int dataToWrite = 42;
  EEPROM.put(0, dataToWrite);
  EEPROM.commit(); // For ESP8266/ESP32, commit is necessary after put
  delay(10); // EEPROM write cycle delay
}

void readDataFromEEPROM() {
  // Read data from EEPROM
  int dataRead;
  EEPROM.get(0, dataRead);
  
  Serial.print("Data read from EEPROM: ");
  Serial.println(dataRead);
}
