#include <Servo.h>
#define echoPin 4
#define trigPin 5
#define MOTOR1 8
#define MOTOR2 9
#define EN 10
#define POT 0
#define led 12
int POT_VAL;
Servo servo;
long duration;
int distance;
const int ldrPin = A0;  
int servopin = 11;
int servopossion = 250;
const int buzzer = 2;
int switchmotor = 6;
int switchbuzzer = 3; 
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  pinMode(ldrPin, INPUT);   
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT); 
  servo.attach(servopin); 
  pinMode(buzzer, OUTPUT); 
  Serial.begin(9600);
  pinMode(EN,OUTPUT);
  pinMode(MOTOR1,OUTPUT);
  pinMode(MOTOR2,OUTPUT);
 
}
 
void loop() {
  //code of ultrasonic
  digitalWrite(trigPin,LOW);
  delay(200);
  digitalWrite(trigPin,HIGH);
  delay(1000);
  digitalWrite(trigPin,LOW);
  duration =pulseIn(echoPin,HIGH);
  distance= (duration * 0.034 )/ 2;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");
  
  int ldr_val=analogRead(ldrPin);
  Serial.println(ldr_val);
  //code of LRD and LED  
 
  if (distance <= 10 && ldr_val <=450 ){
    digitalWrite(led, HIGH);               
    Serial.println(" LED is ON");
   
    
  }
   if (distance <= 10 && ldr_val >450 ){
    digitalWrite(led, LOW);               
    Serial.println(" LED is OFF");
  
  }
   
  

//CODE OF SERVO MOTOR
  servo.detach();
    delay(1500);
    servo.attach(servopin);
   servo.write(servopossion);
    delay(1500);
    servo.detach();
    
    servo.attach(servopin);
    servo.write(0);
    delay(1500);
    //CODE OF BUZZER
     tone(buzzer, 2900); 
  delay(1000);        
  noTone(buzzer);     
  delay(1000);
 byte switchmotorstate = digitalRead(switchmotor);
    byte switchbuzzerstate = digitalRead(switchbuzzer);

  if(switchbuzzerstate == HIGH){
        tone(buzzer, 255, 1000);
    }else{
        tone(buzzer, 0, 1000);

 
      }
   if(switchmotorstate == HIGH){
    
        analogWrite(EN,255);
  digitalWrite(MOTOR1,HIGH);
  digitalWrite(MOTOR2,LOW);
    }else{
   
    analogWrite(EN,0);
      digitalWrite(MOTOR1,LOW);
      digitalWrite(MOTOR2,HIGH);
 
      }
 
 
 
 
}
