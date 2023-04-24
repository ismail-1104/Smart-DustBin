#include <LiquidCrystal_I2C.h>

#include <Servo.h>


LiquidCrystal_I2C lcd(32,16,2); 
const int trig1 = 10;
const int echo1 = 9;
const int trig2 = 12;
const int echo2 = 11;
int moisture = 13;
int ir = 7;
int servo = 8;
Servo myservo;

void setup() {
  // put you
  lcd.begin(16,2);
lcd.init();
    lcd.backlight();
  // 1st NUmber
pinMode(ir,INPUT);
  pinMode(moisture,INPUT);
Serial.begin(9600);
myservo.attach(8);
pinMode(echo1,INPUT);
pinMode(trig1,OUTPUT);
pinMode(echo2,INPUT);
pinMode(trig2,OUTPUT);
myservo.write(90);
}

void loop() {
myservo.write(90);
  lcd.setCursor(0,0);
  lcd.print("smart dustbin");
  
digitalWrite(trig1,LOW);
digitalWrite(trig1,HIGH);
digitalWrite(trig1,LOW);
digitalWrite(trig2,LOW);
digitalWrite(trig2,HIGH);
digitalWrite(trig2,LOW);

int system1= pulseIn(9,HIGH);
int distance1 = (0.034*system1)/2;
int system2= pulseIn(11,HIGH);
int distance2 = (0.034*system2)/2;

int irsystem= digitalRead(7);
  int drop= digitalRead(13);
  Serial.println(irsystem);
    Serial.println(drop);

if(distance1 < 15 && distance2 < 15){
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.println("Dustbin full");
  Serial.println("Dustbin full") ;
  delay(200); 
 
}else  if (irsystem == 0 && drop == 0){
  lcd.clear();
  myservo.write(180); 
   lcd.setCursor(0,0);
  lcd.println("Wet Garbage Detected");
    Serial.println("Wet Garbage Detected") ;
  delay(200);
   
}else if(irsystem == 0  && drop == 1){
  lcd.clear();
   myservo.write(0);
    lcd.setCursor(0,0);
  lcd.println("Dry Garbage Detected");
    Serial.println("Dry Garbage Detected") ;
  delay(200);  
}else{
   lcd.clear();
   myservo.write(90);
      lcd.setCursor(0,0);
  lcd.println("NO Garbage Detected");
    Serial.println("No Garbage Detected") ;
  delay(200); 
 
}
}