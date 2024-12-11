
unsigned long currentTime = 0;
unsigned long lastTime = 0;
const unsigned long intervalBetweenData = 1000;

unsigned long value = 0;

const int len = 300; 

//Arrays for time difference and outputs 
int timeDiff[len];
//int times[len];
int outputs[len];

int i = 0;

void setup() {
  
  // initialize serial communication at 500000 bits per second:
  Serial.begin(500000);
  Serial.print("Time");
  Serial.print(',');
  Serial.println("A0");
}


// The loop() function runs over and over so whatever is contained
// therein will be repeated until while the arduino is on. 

void loop() {
  //This the current time
     long now = micros();
//
     int sensorValue = analogRead(A0);
     
    //times[i]=now;

//Store timeDiff and outputs in array 
    timeDiff[i] = now-lastTime;

    outputs[i] = sensorValue;
    
    lastTime=now;
     
    i=i+1; 
  
//when arrays are full print contents and set back to start
    if (i == len) {
      for (int j = 0; j <= len; j++) { 
        Serial.print(timeDiff[j]);
//        Serial.print(',');
//        Serial.print(times[j]);
        Serial.print(',');
        Serial.println(outputs[j]);
      }
      i=0;
      return;
    }
    
//    }
 }
