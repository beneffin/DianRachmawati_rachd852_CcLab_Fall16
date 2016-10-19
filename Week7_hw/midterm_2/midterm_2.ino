  //Setup all pins
int sensPin = 2;    // set the touch sensor (analog) input pin on Arduino
int redPin = 7;    // set the PWM (analog) output pin on Arduino controlling the red anode
int grnPin = 6;        // set the PWM (analog) output pin on Arduino controlling the green anode
int bluPin = 5;    // set the PWM (analog) output pin on Arduino controlling the blue anode

//Initialize variables
int redVal;         // pulse width variable for red anode
int grnVal;         // pulse width variable for green anode
int bluVal;         // pulse width variable for blue anode

void setup() 
{
  pinMode(redPin, OUTPUT);   // set the LED pins as output
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int val = analogRead(sensPin);           // read touch sensor values
  Serial.println(val); 
  if (val < 256)
  {
  redVal = val;  // 0 - 256 => (val, 0 , 0)
  grnVal = 0;
  bluVal = 0;
  }
  else if (val < 512) 
  {
  redVal = 512 - val; // 256 - 512 => ((512-val), (val- 256), 0)
  grnVal = val-256;
  bluVal = 0;
  }
  else if (val < 768)
  {
  redVal = 0;
  grnVal = 768-val;
  bluVal = val-512;
   }
  else
  {
  redVal = 1023-val;
  grnVal = 1023-val;
  bluVal = 255;
  }
    display(redVal, grnVal, bluVal);
  }

void display(int r, int g, int b) 
{
  analogWrite(redPin, r);
  analogWrite(grnPin, g);
  analogWrite(bluPin, b);
}
