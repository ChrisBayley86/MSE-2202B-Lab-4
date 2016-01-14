//Knightrider LEDs Effect
//MSE 2202 Lab 2 Pre-lab

void setup() {
  //Declares the pins
  int pin1 = 4;
  int pin2 = 5;
  int pin3 = 6;
  int pin4 = 7;
  
  //Declares the benchmark time and the initial state
  int steadyTime = millis();
  int state = 1;
  int timeDifference = 100;
  
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
  
  //Declares the pins
  int pin1 = 4;
  int pin2 = 5;
  int pin3 = 6;
  int pin4 = 7;
  
  //Declares the benchmark time and the initial state
  int steadyTime = millis();
  int state = 1;
  int timeDifference = 100;
  
  
  for (; 0 < 1;){
  
  
  if ((millis() - steadyTime) >= timeDifference){
    //Conditions for turning on
    if (state == 2 || state == 13) {
      digitalWrite(pin1, HIGH);
    }
    if (state == 3 || state == 12) {
      digitalWrite(pin2, HIGH);
    }
    if (state == 4 || state == 11) {
      digitalWrite(pin3, HIGH); 
    }
    if (state == 5 || state == 10) {
      digitalWrite(pin4, HIGH);
    }
    //Conditions for turning off
    if (state == 6 || state == 1) {
      digitalWrite(pin1, LOW);
    }
    if (state == 7 || state == 16) {
      digitalWrite(pin2, LOW);
    }
    if (state == 8 || state == 15) {
      digitalWrite(pin3, LOW); 
    }
    if (state == 9 || state == 14) {
      digitalWrite(pin4, LOW);
    }
    
    //Resetting the state
    if (state == 16) {
        state = 1;
    }
    else {
        state++;  
    }
    
    //Resets the benchmark time
    steadyTime = millis();
  }
  }

}
