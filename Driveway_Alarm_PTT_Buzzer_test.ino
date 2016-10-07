int PTTPin = 2;
int SpeakerPin= 8;
int sensorPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Driveway Alarm - Test2");

  pinMode(SpeakerPin, OUTPUT);

  pinMode(PTTPin, OUTPUT);
  digitalWrite(PTTPin, LOW);
}

void loop() {

  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if(sensorValue > 100){
    digitalWrite(PTTPin, HIGH);   // PTT Start
    
    delay(1500);              // TX Delay time
  
    //Make a beep
    //=================================================
    for(int i=0; i<250; i++){
      digitalWrite(SpeakerPin, HIGH);
      delayMicroseconds(400);
      digitalWrite(SpeakerPin, LOW);
      delayMicroseconds(400);
    }
    delay(20);
    for(int i=0; i<250; i++){
      digitalWrite(SpeakerPin, HIGH);
      delayMicroseconds(600);
      digitalWrite(SpeakerPin, LOW);
      delayMicroseconds(600);
    }
    //=================================================
    delay(1000);//Hang time
    digitalWrite(PTTPin, LOW);    // turn the LED off by making the voltage LOW
    //delay(10000);              // wait for a second
  }
}
