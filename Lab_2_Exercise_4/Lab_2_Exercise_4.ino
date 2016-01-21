//Lab 2 Exercise 4
//by Chris Bayley

//This version is setup so that it should be easier to add in another LED

void setup() {
  //Declares the pins
  const int pin1 = 4;
  const int pin2 = 5;
  const int pin3 = 6;
  const int pin4 = 7;
  const int pot = A0;
  const int dpdtSwitch = 3;
  const int button = 2;
  
  Serial.begin(9600);
  
  //Initializes the pin modes
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(button, INPUT);
  pinMode(dpdtSwitch, INPUT);
  
  //Sets all LED pins to low
  //thus starting in State 1
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(button, HIGH); 
  //the above line enables the internal
  //pull-up resistor.
  
}

void loop () {
  
  
  
const int ledLifeDuration = 2;
  int numPins = 4;
  int pins[numPins][5]; 
  //Zero-th row is pin locations
  //1st row is pin state
  //2nd row is pin life
  //3rd row is turn-on state 1
  //4th row is turn-on state 2
  
  
  
  
  //Filling the pins array
  for (int i = 0; i < numPins; i++){ //Begin for 1
    pins[i][0] = i+4; //Starts at pin 4; 
    //This runs off the assumption that the arduino
    //can handle i number of pins...
    pins[i][1] = 0; //State defaults to 0 - low
    pins[i][2] = 0; //Life starts at 0 active counts
    pins[i][3] = 2*i; //state to turn on (1)
    pins[i][4] = (numPins*3) - (2*i); //state to turn on (2)
  } //end for 1
  
  pins[0][2] = 1; //Pin 1 starts at life of 1 because it
  //is turned back on at state 12
  
  
  
  
  //Declares some initial variables
  long steadyTime = millis();
  //int state = 0;
  int timeDifference = 200;
  int ledDuration = 3;
  
  //Potentiometer pin setup
  const int pot = A0;
  pinMode(pot, INPUT);
  const int dpdtSwitch = 3;
  const int button = 2;
  
  
  
  
  
  for (int state = 0; state <= numPins*3;){ //begin for 2
    if ((millis() - steadyTime) >= timeDifference){ //begin if 1
      
      
      /*
      Serial.print("State: ");
      Serial.println(state);
      */
      
      
      //Loop-checking of the i-th pin's state.
      for (int i = 0; i <= numPins; i++){ //begin for 4
        
        if ( (state == pins[i][3]) || (state == pins[i][4]) ){ //begin if 2
          digitalWrite(pins[i][0],HIGH);
          
          /*Serial.println();
          Serial.println(state);
          Serial.println();*/
          
        } // end if 2
        
        
        //Resetting the LED life
        if ( pins[i][2] > ledLifeDuration ){ //begin if 3
          digitalWrite(pins[i][0], LOW);
          pins[i][2] = 0;
        } //end if 3
        //Incrementing the pin life if it's currently
        //turned on.
        else if ( digitalRead(pins[i][0]) == HIGH ){ //begin if 4
          pins[i][2] = pins[i][2]+1;
        } //end if 4
        
       /*
      Serial.print(i);
      Serial.print(": ");
      Serial.print(digitalRead(pins[i][0]));
      Serial.print(" Life: ");
      Serial.println(pins[i][2]);
      */
        
        
    
      } //end for 4
      
      
      //Reset the state counter
      if (state == (numPins*3 /*- 1*/)){ //begin if 5
        state = 0;
      } //end if 5
      steadyTime = millis(); 
      state++;
    } //end if 1
   Serial.print("B: ");
   Serial.println(digitalRead(button));
   Serial.print("S: ");
   Serial.println(digitalRead(dpdtSwitch));
   
   //Changes the method of setting the timeDifference
   if (digitalRead(dpdtSwitch) == HIGH){ //begin if 6
     timeDifference = analogRead(pot);
   }
   else if (digitalRead(dpdtSwitch) == LOW && digitalRead(button) == LOW) {
     timeDifference += 5;//digitalRead(button);
     
   }
   
   
   
   
  } //end for 2
  
}

