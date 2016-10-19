int ledcolor = 0;
int a = 1000; //this sets how long the stays one color for
int red = 6; //this sets the red led pin
int green = 5; //this sets the green led pin
int blue = 4; //this sets the blue led pin
const int sensorPin = A1;
int value;


void setup() { //this sets the output pins

pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
Serial.begin(9600); 
}

void loop(){
  
  value = analogRead(sensorPin);       //Read and save analog value from potentiometer
  Serial.println(value);               //Print value
  value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  analogWrite(blue, 0,100);          //Send PWM value to led
    analogWrite(red, 0,100);
      analogWrite(green, 0,100);
  delay(2000);                          //Small delay
}


//
//void loop() {
//int ledcolor = random(7); //this randomly selects a number between 0 and 6
//
//switch (ledcolor) {
//case 0: //if ledcolor equals 0 then the led will turn red
//analogWrite(red, 51);
//delay(a);
//analogWrite(red, 255);
//break;
//case 1: //if ledcolor equals 1 then the led will turn green
//digitalWrite(green, LOW);
//delay(a);
//digitalWrite(green, HIGH);
//break;
//case 2: //if ledcolor equals 2 then the led will turn blue
//digitalWrite(blue, LOW);
//delay(a);
//digitalWrite(blue, HIGH);
//break;
//case 3: //if ledcolor equals 3 then the led will turn yellow
//analogWrite(red, 95);
//digitalWrite(green, LOW);
//delay(a);
//analogWrite(red, 255);
//digitalWrite(green, HIGH);
//break;
//case 4: //if ledcolor equals 4 then the led will turn cyan
//analogWrite(red, 168);
//digitalWrite(blue, LOW);
//delay(a);
//analogWrite(red, 255);
//digitalWrite(blue, HIGH);
//break;
//case 5: //if ledcolor equals 5 then the led will turn magenta
//digitalWrite(green, LOW);
//digitalWrite(blue, LOW);
//delay(a);
//digitalWrite(green, HIGH);
//digitalWrite(blue, HIGH);
//break;
//case 6: //if ledcolor equals 6 then the led will turn white
//analogWrite(red, 155);
//digitalWrite(green, LOW);
//digitalWrite(blue, LOW);
//delay(a);
//analogWrite(red, 255);
//digitalWrite(green, HIGH);
//digitalWrite(blue, HIGH);
//break;
//}
//}

