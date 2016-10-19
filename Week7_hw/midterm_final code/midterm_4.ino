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
  if (val < 50)
  {
  redVal = 0;  // 0 - 256 => (0, 0 , 0)
  grnVal = 0;
  bluVal = 0;
  }
  else if (51 < val < 200) 
  {
  redVal = 500 - val; // red 251 - 500 => ((512-val), (val- 256), 0)
  grnVal = val - 256 ;
  bluVal = 0;
  }
  else if (201 < val < 400) 
  {
  redVal = 0; // 256 - 512 => ((512-val), (val- 256), 0)
  grnVal = 700-val;
  bluVal = val-501;
  }
  else if (401 < val < 700)
  {
  redVal = 0;
  grnVal = 1000-val;
  bluVal = 255;
  }
  else if (701 < val)
  {
  redVal = 204;
  grnVal = 0;
  bluVal = 204;
  }
  display(redVal, grnVal, bluVal);
}

void display(int r, int g, int b) 
{
  analogWrite(redPin, r);
  analogWrite(grnPin, g);
  analogWrite(bluPin, b);
}
