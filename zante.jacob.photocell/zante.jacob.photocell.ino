/*
Student Name: Jacob Zante
Teacher Name: Hayden So
Title of Project: Photocell Distance Sensor
Brief Description of Project: This project uses a photocell connected to an analog pin that will 
make the arduino turn on a certain number of LEDs depending on how close your are to the photocell.
Date of Completion: Oct 30, 2024
*/

const int ledPins[6] = {6, 7, 8, 9, 10, 11}; // array to store the pin values for each LED output

int ledCount = 0; // int to count how many LEDs should be turned on depending on the analong pin value

bool ledOutputs[6] = {false, false, false, false, false, false}; // array to store boolean values that each coorespond to an LED, representing what state that LED should be in



void ledController() {
	
  ledCount = analogRead(A0); // read analong pin 0
  
  ledCount = map(ledCount, 0, 1023, 0, 6); // reduce value to a range of 0 to 6
  
  Serial.print("photocell value: ");
  Serial.println(ledCount);
  
  
  for (int i = 0; i < sizeof(ledPins); i++) { // repeat loop for the length of 'ledPins' array
    
    if (ledCount <= 0) { // check if 'ledCount' is less than or equal to 0
      
      ledOutputs[i] = false; // set 'ledOutputs' at current index to 'false'
      
    } else { // only triggers if 'ledCount' is greater than 0
      
      ledOutputs[i] = true; // set 'ledOutputs' at current index to 'true'
      
    }
    
    ledCount--; // subtract one from 'ledCount'
  }
  
  for (int i = 0; i < sizeof(ledPins); i++) { // repeat loop for the length of 'ledPins' array\
    
    digitalWrite(ledPins[i], ledOutputs[i]); // write to 'ledPins' at index the value of 'ledOutputs' at index
  }
}



void setup() {

    Serial.begin(9600); // initialize the serial monitor with 9600 baud

    pinMode(A0, INPUT); // initialize pin AO as an input

    // initialize all pins in the 'ledPins' array as outputs
    for (int i : ledPins) {
        pinMode(i, OUTPUT);
    }
}


void loop() {
  
  delay(50); // 50ms delay for stability
  
  ledController(); // run 'ledController' function

}
