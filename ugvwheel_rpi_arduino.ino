#include<Wire.h>
const int fl = 8;
const int fr = 9;
const int bl = 10;
const int br =11;
const int rbr = 4;
const int rfr = 1;
const int rfl = 0;
bool is_rbr = false;
bool is_rfr = false;
bool is_rfl = false;

const int MPU=0x68; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup() {
  pinMode(fl, OUTPUT);
  pinMode(fr, OUTPUT);
  pinMode(rbr, OUTPUT);
  pinMode(rfr, OUTPUT);
  pinMode(rfl, OUTPUT);
  pinMode(bl, OUTPUT);
  pinMode(br, OUTPUT);
  // put your setup code here, to run once:
  //Wire.beginTransmission(MPU);
  //Wire.write(0x3B);  
  //Wire.endTransmission(false);
  //Wire.requestFrom(MPU,12,true);  
  //AcX=Wire.read()<<8|Wire.read();    
  //AcY=Wire.read()<<8|Wire.read();  
  //AcZ=Wire.read()<<8|Wire.read();
  

  Serial.begin(9600);
}
void stopv(){
    analogWrite(br,0);
    analogWrite(fr,0);
    analogWrite(fl,0);
    //digitalWrite(rfr,LOW);
    digitalWrite(rfl,LOW);
    digitalWrite(rbr,LOW);
    Serial.println("stopping");
    
}
void loop() {
   if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.print("You sent me:");
    Serial.println(data);
    // put your main code here, to run repeatedly:
    //Wire.beginTransmission(MPU);
    //Wire.write(0x3B);  
    //Wire.endTransmission(false);
    //Wire.requestFrom(MPU,12,true);  
    //AcX=Wire.read()<<8|Wire.read();    
    //AcY=Wire.read()<<8|Wire.read();  
    //AcZ=Wire.read()<<8|Wire.read();  
    if (data == "a"){
      analogWrite(fl,500);
      Serial.println("a");
    }
      else if(data == "s"){
      analogWrite(fr,450);
      Serial.println("s");
      }
      else if(data == "d"){
      analogWrite(br,450);
      Serial.println("d");
      }
      else if(data == ""){
       stopv();
      }
    else{
      
    }
  }
}
