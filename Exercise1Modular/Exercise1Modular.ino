//This version is setup so that it should be easier to add in another LED

void setup() {
  //Declares the pins
  const int pin1 = 4;
  const int pin2 = 5;
  const int pin3 = 6;
  const int pin4 = 7;
  
  
  Serial.begin(9600);
  
  //Initializes the pin modes
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
  //Sets all LED pins to low
  //thus starting in State 1
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  
}

void loop() {
  int numPins = 4;
  int pins[numPins][3]; 
  //Zero-th row is pin locations
  //1st row is pin state
  //2nd row is pin life
  
  //Filling the pins array
  for (int i = 0; i < numPins; i++){
    pins[i][0] = i+4; //Starts at pin 4;
    pins[i][1] = 0; //State defaults to 0 - low
    pins[i][2] = 0; //Life starts at 0 active counts
  }
  
  pins[0][2] = 1; //Pin 1 starts at life of 1 because it
  //is on at state 12
  
  
  //Declares some initial variables
  long steadyTime = millis();
  int state = 1;
  int timeDifference = 250;
  int ledDuration = 3;
  
  
  

}
