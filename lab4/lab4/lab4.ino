

unsigned long currentTime = 0;
unsigned long lastTime = 0;
const unsigned long intervalBetweenData = 1000;


void setup() {
  
  // initialize serial communication at 500000 bits per second:
  Serial.begin(500000);
}

// The loop() function runs over and over so whatever is contained
// therein will be repeated until while the arduino is on. 

void loop() {
  
  // The function analogRead() will
    
  int sensorValue = analogRead(A0);
  
  // get the current time in microseconds
  currentTime = micros();

  
  if (currentTime - lastTime >= intervalBetweenData ) {
    int sensorValue = analogRead(A0);
    lastTime+=intervalBetweenData;
    //time in milliseconds
    Serial.print(currentTime/1000);
    Serial.print(',');
    Serial.println(sensorValue);
   }
 }
