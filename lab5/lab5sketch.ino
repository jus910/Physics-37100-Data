  const int ledPin = 9;       // pin that the LED is attached to
  const int TWOPI = 2*3.1415926;
  unsigned long currentTime = 0;
  int brightness;


  const int numReadings1 = 1;
  int readings1[numReadings1];  // the readings from the analog input
  int readIndex1 = 0;          // the index of the current reading
  int total1 = 0;              // the running total
  int average1 = 0;            // the average

  

  const int numReadings5 = 5;
  int readings5[numReadings5];  // the readings from the analog input
  int readIndex5 = 0;          // the index of the current reading
  int total5 = 0;              // the running total
  int average5 = 0;            // the average

  const int numReadings10 = 10;
  int readings10[numReadings10];  // the readings from the analog input
  int readIndex10 = 0;          // the index of the current reading
  int total10 = 0;              // the running total
  int average10 = 0;            // the average
  
  int inputPin = A0;

  void setup() {
    pinMode(ledPin, OUTPUT);
    for (int thisReading = 0; thisReading < numReadings1; thisReading++) {
      readings1[thisReading] = 0;
     }

     
    for (int thisReading = 0; thisReading < numReadings5; thisReading++) {
      readings5[thisReading] = 0;
     }
    
     
    for (int thisReading = 0; thisReading < numReadings10; thisReading++) {
      readings10[thisReading] = 0;
     }
     
    Serial.begin(9600);
  }

  void loop() {
    
    // subtract the last reading:
    total1 = total1 - readings1[readIndex1];
    // read from the sensor:
    readings1[readIndex1] = analogRead(inputPin);
    // add the reading to the total:
    total1 = total1 + readings1[readIndex1];
    // advance to the next position in the array:
    readIndex1 = readIndex1 + 1;
  
    // if we're at the end of the array...
    if (readIndex1 >= numReadings1) {
      // ...wrap around to the beginning:
      readIndex1 = 0;
    }
    
    // calculate the average:
    average1 = total1 / numReadings1;
    // send it to the computer as ASCII digits

    // subtract the last reading:
    total5 = total5 - readings5[readIndex5];
    // read from the sensor:
    readings5[readIndex5] = analogRead(inputPin);
    // add the reading to the total:
    total5 = total5 + readings5[readIndex5];
    // advance to the next position in the array:
    readIndex5 = readIndex5 + 1;
  
    // if we're at the end of the array...
    if (readIndex5 >= numReadings5) {
      // ...wrap around to the beginning:
      readIndex5 = 0;
    }
    
    // calculate the average:
    average5 = total5 / numReadings5;
    // send it to the computer as ASCII digits

    
    // subtract the last reading:
    total10 = total10 - readings10[readIndex10];
    // read from the sensor:
    readings10[readIndex10] = analogRead(inputPin);
    // add the reading to the total:
    total10 = total10 + readings10[readIndex10];
    // advance to the next position in the array:
    readIndex10 = readIndex10 + 1;
  
    // if we're at the end of the array...
    if (readIndex10 >= numReadings10) {
      // ...wrap around to the beginning:
      readIndex10 = 0;
    }
    
    // calculate the average:
    average10 = total10 / numReadings10;
    // send it to the computer as ASCII digits

    
      
    brightness = 100+4*sin(1.0*TWOPI*millis()/1000);
    analogWrite(ledPin,brightness);

    

    currentTime = millis();

    //time in millisecondsseconds 
    Serial.print(currentTime);
    Serial.print(',');
    Serial.print(average1);
    Serial.print(',');
    Serial.print(average5);
    Serial.print(',');
    Serial.println(average10);
    delay(1);
  }
