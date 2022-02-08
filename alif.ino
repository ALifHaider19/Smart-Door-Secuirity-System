#include <LiquidCrystal.h>
#include <Servo.h>
int buzzer = 7;
int inputPin = A1;            
int pirState = LOW;  
int val = 0;   
#define trigPin 9
#define echoPin 8
#define dhtpin A0
Servo servo;

int sound = 250;
int Contrast=80;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

 void setup()
 {
  Serial.begin (9600);
  
   pinMode(buzzer, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
     pinMode(inputPin, INPUT);

servo.attach(10);
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
  } 
     void loop()
 { 


  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1; if (distance < 80) {

Serial.print(distance);

Serial.println(" cm");

servo.write(00);

}
if (distance<20) {

Serial.print(distance);

Serial.println(" cm");
servo.write(180);
+lcd.print("opening the door");
lcd.setCursor(1,1);
delay(2000);
lcd.print("You'r Welcome");
delay(2000);
servo.write(180);
lcd.clear();


}

else {

Serial.println("The distance is more than 180cm");

}

delay(500);
 val = digitalRead(inputPin);  // read input value
  
  if (val == HIGH)  // check if the input is HIGH
  {            
  
    if (pirState == LOW) 
  {
      Serial.println("Motion detected!"); // print on output change
      pirState = HIGH;
      digitalWrite(buzzer, HIGH);
      
      


    }
  } 
  else 
  {
  
    if (pirState == HIGH)
  {
      Serial.println("Motion ended!");  // print on output change
      pirState = LOW;
       digitalWrite(buzzer, LOW);

    }
  }


 }
