#include <SoftwareSerial.h>
SoftwareSerial GSM(9,10);
char *phone_no = "Enter Your Phone Number";
unsigned long currentTime;
unsigned long loopTime1;
unsigned long loopTime2;
int FL1 = 2;
int FL2 = 3;
int FR3 = 8;
int FR4 = 7;
int BL3 = 4;
int BL4 = 5;
int BR1 = 13;
int BR2 = 12;
int SpeedL = 11;
int SpeedR = 6;
int Speed = 175;

void setup() {
  Serial.begin(9600);
  GSM.begin(9600);
  Serial.println("Initializing....");
  initModule("AT", "OK", 300);
  initModule("ATE0", "OK", 300);
  initModule("AT+CPIN?", "READY", 300);
  initModule("AT+CLIP=1", "OK", 300);
  initModule("AT+DDET=1", "OK", 300);
  Serial.println("Initialized Successfully");
  pinMode(13,OUTPUT);
  pinMode(FL1, OUTPUT);
  pinMode(FL2, OUTPUT);
  pinMode(FR3, OUTPUT);
  pinMode(FR4, OUTPUT);
  pinMode(BL3, OUTPUT);
  pinMode(BL4, OUTPUT);
  pinMode(BR1, OUTPUT);
  pinMode(BR2, OUTPUT);
}

void loop() {
  currentTime = millis();
  if (GSM.find("CLIP:")){
    Serial.println("RING!");
    delay(200);
    if (GSM.find(phone_no)) {
       initModule("ATA", "OK", 300);
       delay(1500);
       while (1) {
         if (GSM.find("+DTMF:")){
           int Data = GSM.parseInt();
           if (Data == 1) {
            Stop();
            Serial.println(Data);
            initModule("AT+CHUP;", "OK", 300);
            break;
           }
           if (Data == 2) {
            Serial.println(Data);
            Stop();
            delay(100);
            forward();
           }
           if (Data == 4){
            Serial.println(Data);
            Stop();
            delay(100);
            left();
           }
           if (Data == 6){
            Serial.println(Data);
            Stop();
            delay(100);
            right();
           }
           if (Data == 8){
            Serial.println(Data);
            Stop();
            delay(100);
            back();
           }
           if (Data == 5){
            Serial.println(Data);
            Stop();
           }
         }
       }
    }
  }
  else {
    if (currentTime >= (loopTime1 + 2000)) {
      initModule("AT", "OK", 300);
      loopTime1 = currentTime;
    }
  }
}

void initModule(String cmd, char *res, int t) {
  while (1) {
    Serial.println(cmd);
    GSM.println(cmd);
    delay(100);
    while (GSM.available() > 0) {
      if (GSM.find(res)) {
        Serial.println(res);
        delay(t);
        return;
      } else {
        Serial.println("Error");
      }
    }
    delay(t);
  }
}
void forward() {
  digitalWrite(FL1,HIGH);
  digitalWrite(FL2,LOW);
  digitalWrite(FR3,HIGH);
  digitalWrite(FR4,LOW);
  digitalWrite(BL3,HIGH);
  digitalWrite(BL4,LOW);
  digitalWrite(BR1,HIGH);
  digitalWrite(BR2,LOW);
  analogWrite(SpeedL,Speed);
  analogWrite(SpeedR,Speed);
}

void back() {
  digitalWrite(FL1,LOW);
  digitalWrite(FL2,HIGH);
  digitalWrite(FR3,LOW);
  digitalWrite(FR4,HIGH);
  digitalWrite(BL3,LOW);
  digitalWrite(BL4,HIGH);
  digitalWrite(BR1,LOW);
  digitalWrite(BR2,HIGH);
  analogWrite(SpeedL,Speed);
  analogWrite(SpeedR,Speed);
}

void left() {
  digitalWrite(FL1,LOW);
  digitalWrite(FL2,HIGH);
  digitalWrite(FR3,HIGH);
  digitalWrite(FR4,LOW);
  digitalWrite(BL3,LOW);
  digitalWrite(BL4,HIGH);
  digitalWrite(BR1,HIGH);
  digitalWrite(BR2,LOW);
  analogWrite(SpeedL,Speed);
  analogWrite(SpeedR,Speed);
}

void right() {
  digitalWrite(FL1,HIGH);
  digitalWrite(FL2,LOW);
  digitalWrite(FR3,LOW);
  digitalWrite(FR4,HIGH);
  digitalWrite(BL3,HIGH);
  digitalWrite(BL4,LOW);
  digitalWrite(BR1,LOW);
  digitalWrite(BR2,HIGH);
  analogWrite(SpeedL,Speed);
  analogWrite(SpeedR,Speed);
}

void Stop() {
  digitalWrite(FL1,LOW);
  digitalWrite(FL2,LOW);
  digitalWrite(FR3,LOW);
  digitalWrite(FR4,LOW);
  digitalWrite(BL3,LOW);
  digitalWrite(BL4,LOW);
  digitalWrite(BR1,LOW);
  digitalWrite(BR2,LOW);
}
