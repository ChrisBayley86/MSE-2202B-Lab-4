//Knightrider LEDs

void setup() {
  //Declares the pins
  int pin1 = 4;
  int pin2 = 5;
  int pin3 = 6;
  int pin4 = 7;
  
  Serial.begin(9600);
  
  //Declares the benchmark time and the initial state
  int steadyTime = millis();
  int state = 1;
  int timeDifference = 500;
  
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
}

void loop() {
  
  int pin1 = 4;
  int pin2 = 5;
  int pin3 = 6;
  int pin4 = 7;
  
  long steadyTime = millis();
  int state = 1;
  int timeDifference = 500;
  
  for (;0 < 1;) {
  
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
    
    
    //Conditions for turning off
    if (state == 3 || state == 3) {
      digitalWrite(pin1, LOW);
    }
    if (state == 5 || state == 12) {
      digitalWrite(pin2, LOW);
    }
    if (state == 7 || state == 11) {
      digitalWrite(pin3, LOW); 
    }
    if (state == 9) {
      digitalWrite(pin4, LOW);
    }
    
    //Resetting the state
    if (state >= 12) {
        state = 1;
    }
    else {
        state++;  
    }
    
    /*if (state < 12) {
      state++;
    }
    else {
      state == 1;
    }*/
    
    //Resets the benchmark time
    steadyTime = millis();
    
  }
  
  
  Serial.print("State: ");
  Serial.println(state);
  }

}
