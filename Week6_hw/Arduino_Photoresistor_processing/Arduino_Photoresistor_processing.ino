int val; 
int inputPin = 0;                // Set the input to analog in pin 0
 
void setup() { 
  Serial.begin(9600);            // Start serial communication at 9600 bps 
} 
 
void loop() { 
  val = analogRead(inputPin)/4;  // Read analog input pin, put in range 0 to 255
  Serial.write(val);             // Send the value
  delay(100);                    // Wait 100ms for next reading 
}

