//This version is setup so that it should be easier to add in another LED

void setup() {
  //Declares the pins
  /*const int pin1 = D4;
  const int pin2 = D5;
  const int pin3 = D6;
  const int pin4 = D7;*/
  
  const int pin1 = 4;
  const int pin2 = 5;
  const int pin3 = 6;
  const int pin4 = 7;
  
  
  //Declares some initial variables
  /*int steadyTime = millis();
  int state = 1;
  int timeDifference = 100;
  int ledDuration = 3;*/
  
  //Initializes the pin modes
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
  //Sets all pins to low
  //thus starting in State 0
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  
  //Sets a counter for each LED
  //so that it can be modified based
  //on the lifespan of it's duration
  //Note: the first is set to 1 because
  //LED 1 starts the pattern one cycle
  //through it's duration.
  /*int led1Count = 1;
  int led2Count = 0;
  int led3Count = 0;
  int led4Count = 0; */
}

void loop() {
  
  int steadyTime = millis();
  int state = 1;
  int timeDifference = 100;
  int ledDuration = 3;
  
  const int pin1 = 4;
  const int pin2 = 5;
  const int pin3 = 6;
  const int pin4 = 7;
  
  int led1Count = 1;
  int led2Count = 0;
  int led3Count = 0;
  int led4Count = 0;
  
  while (0 < 1) {
  if ((millis() - steadyTime) >= timeDifference){
    //Conditions for turning on
    if (state == 1 || state == 12) {
      digitalWrite(pin1, HIGH);
    }
    if (state == 2 || state == 10) {
      digitalWrite(pin2, HIGH);
    }
    if (state == 4 || state == 8) {
      digitalWrite(pin3, HIGH); 
    }
    if (state == 6) {
      digitalWrite(pin4, HIGH);
    }
    
    //This will allow the lights to turn
    //off when they're count has hit
    //the maximum duration.
    if (led1Count == ledDuration) {
      digitalWrite(pin1, LOW);
    }
    if (led2Count == ledDuration) {
      digitalWrite(pin2, LOW);
    }
    if (led3Count == ledDuration) {
      digitalWrite(pin3, LOW);
    }
    if (led4Count == ledDuration) {
      digitalWrite(pin4, LOW);
    }
    
    
    
    //Resetting or advancing
    if (state == 16) {
        state == 1;
    }
    else {
        state++;  
    }
    
    //Incrementing the LED duration counters
    if (digitalRead(pin1) == HIGH) led1Count++;
    if (digitalRead(pin2) == HIGH) led2Count++;
    if (digitalRead(pin2) == HIGH) led3Count++;
    if (digitalRead(pin2) == HIGH) led4Count++;
    
    
    //Resets the benchmark time
    steadyTime = millis();
  }
  }

}
