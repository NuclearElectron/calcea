
int LastTime=0;
bool BPMTiming=false;
bool BeatComplete=false;
int BPM=0;
int value=analogRead(0);

#define UpperThreshold 550

void setup() {
  Serial.begin(9600);
}

void loop() {

 if(value>UpperThreshold) {
    if(BeatComplete) {
      BPM=millis()-LastTime;
      BPM=int(60/(float(BPM)/1000));
      Serial.println(BPM);
      BPMTiming=false;
      BeatComplete=false;
    }
    
    if(BPMTiming==false) {
      LastTime=millis();
      BPMTiming=true;
    }
  }
  else {
    Serial.println("check wiring");
  }
}
