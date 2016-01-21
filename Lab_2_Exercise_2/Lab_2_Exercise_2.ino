//This version is setup so that it should be easier to add in another LED

void setup() {
  //Declares the pins
  const int pin1 = 4;
  const int pin2 = 5;
  const int pin3 = 6;
  const int pin4 = 7;
  const int pot = A0;
  
  Serial.begin(9600);
  
  //Initializes the pin modes
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pot, INPUT);
  
  //Sets all LED pins to low
  //thus starting in State 1
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  
}

void loop() {
  
  //Declares the pins
  const int pin1 = 4;
  const int pin2 = 5;
  const int pin3 = 6;
  const int pin4 = 7;
  const int pot = A0;
  
  //Declares some initial variables
  long steadyTime = millis();
  int state = 1;
  int timeDifference = 100;
  int ledDuration = 3;
  
  //Sets a counter for each LED
  //so that it can be modified based
  //on the lifespan of it's duration
  //Note: the first is set to 1 because
  //LED 1 starts the pattern one cycle
  //through it's duration.
  int led1Count = 1;
  int led2Count = 0;
  int led3Count = 0;
  int led4Count = 0; 
  
  
  for (; 0 < 1;) {
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
        led1Count = 0;
      }
      if (led2Count == ledDuration) {
        digitalWrite(pin2, LOW);
        led2Count = 0;
      }
      if (led3Count == ledDuration) {
        digitalWrite(pin3, LOW);
        led3Count = 0;
      }
      if (led4Count == ledDuration) {
        digitalWrite(pin4, LOW);
        led4Count = 0;
      }
    
    
    
      
    
      //Incrementing the LED duration counters
      if (digitalRead(pin1) == HIGH) led1Count++;
      if (digitalRead(pin2) == HIGH) led2Count++;
      if (digitalRead(pin3) == HIGH) led3Count++;
      if (digitalRead(pin4) == HIGH) led4Count++;
    
    
      //Resets the benchmark time
      steadyTime = millis();
      
      //Output to Serial Monitor for debugging
      //This was to resolve the state and
      //life of each pin.
      /*Serial.print("State: ");
      Serial.println(state);
      Serial.print("1: ");
      Serial.print(digitalRead(pin1));
      Serial.print(" Life: ");
      Serial.println(led1Count);
      Serial.print("2: ");
      Serial.print(digitalRead(pin2));
      Serial.print(" Life: ");
      Serial.println(led2Count);
      Serial.print("3: ");
      Serial.print(digitalRead(pin3));
      Serial.print(" Life: ");
      Serial.println(led3Count);
      Serial.print("4: ");
      Serial.print(digitalRead(pin4));
      Serial.print(" Life: ");
      Serial.println(led4Count);
      Serial.println();*/
      
      //Output to Serial monitor to check
      //the status of the input signal 
      //from the potentiometer.
      //Serial.println(analogRead(pot));
      //timeDifference = analogRead(pot);
      /*timeDifference += analogRead(pot);
      timeDifference += analogRead(pot);
      timeDifference += analogRead(pot);
      //timeDifference += analogRead(pot);
      timeDifference = timeDifference/4;*/
      
      
      //Resetting or advancing
      if (state == 12) {
          state = 1;
      }
      else {
        state++;  
      }
      
    }
    //timeDifference = analogRead(pot);
  }

}
