// The outpin is 9 
const int outPin = 9;

//start at 50 Hz
int frequency1 = 50;

unsigned long currentTime = 0;
unsigned long lastTime = 0;
// 1 ms
const unsigned long intervalBetweenData = 1000;

unsigned long lastTimeChanged = 0;
//100 ms
const unsigned long intervalBetweenChanges = 100000;

void setup() {
  // put your setup code here, to run once:
  pinMode(outPin, OUTPUT);
  Serial.begin(500000);
  tone(outPin, frequency1);
}

void loop() {
   // put your main code here, to run repeatedly:

   // get the current time in microseconds
   currentTime = micros();
   
   // Every 100 ms increase the frequency by 10 Hz
   if (currentTime - lastTimeChanged >= intervalBetweenChanges ) {
    noTone(outPin);
    frequency1+=10;
    tone(outPin, frequency1);
    lastTimeChanged+=intervalBetweenChanges;
   }
   
   

   if (currentTime - lastTime >= intervalBetweenData ) {
    int sensorValue = analogRead(A0);
    lastTime+=intervalBetweenData;
    //time in milliseconds
    Serial.print(currentTime/1000);
    Serial.print(',');
    Serial.print(frequency1);
    Serial.print(',');
    Serial.println(sensorValue);
   }
   
}
