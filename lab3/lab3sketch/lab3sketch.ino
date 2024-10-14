// The outpin is 9 
const int outPin = 9;
// Output level starts at 0 
int outputLevel=0;


void setup() {
  //define the pin mode for the digital output
  pinMode(outPin, OUTPUT);
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// The loop() function runs over and over so whatever is contained
// therein will be repeated until while the arduino is on. 

void loop() {
      
  int sensorValue = analogRead(A0);
  int potValue = analogRead(A1);

  //map the pot value to a value
  outputLevel = map(potValue,0,1023,0,255);
  
  //write outputLevel to digital output pin
  analogWrite(outPin, outputLevel);
  
  //This writes the outputLevel variable to the output pin 
  
  Serial.print(millis());
  Serial.print(',');
  Serial.print(potValue);
  Serial.print(',');
  Serial.println(sensorValue);
  // 200 ms
  
  delay(200);
}
