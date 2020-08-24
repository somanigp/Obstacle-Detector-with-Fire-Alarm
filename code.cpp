int left_trigPin = 5;    
int left_echoPin = 6;   

int centre_trigPin = 2;    
int centre_echoPin = 3; 

int right_trigPin = 13;    
int right_echoPin = 12; 

int flame = 7;
int buzzer = 8;
int left_motor1 = A0; 
int left_motor2 = A1;
int right_motor1 = A2;
int right_motor2 = A3;
long duration1;
int distance1;
long duration2;
int distance2;
long duration3;
int distance3;
int pre;
int flame_detected;


void forward(){
  analogWrite(left_motor1,150);
  analogWrite(left_motor2,0);
  analogWrite(right_motor1,150);
  analogWrite(right_motor2,0);
  
 }

void backward(){
  analogWrite(left_motor1,0);
  analogWrite(left_motor2,150);
  analogWrite(right_motor1,0);
  analogWrite(right_motor2,150);  
 }
void leftward(){
  analogWrite(left_motor1,0);
  analogWrite(left_motor2,150);
  analogWrite(right_motor1,150);
  analogWrite(right_motor2,0);
 }

void rightward(){
  analogWrite(left_motor1,150);
  analogWrite(left_motor2,0);
  analogWrite(right_motor1,0);
  analogWrite(right_motor2,150); 
 }

void stop(){
  digitalWrite(left_motor1,LOW);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
}    
void setup() {

  // put your setup code here, to run once:
  Serial.begin(9500);
pre = -1;  
pinMode(left_motor1,OUTPUT);
pinMode(left_motor2,OUTPUT);
pinMode(right_motor1,OUTPUT);
pinMode(right_motor2,OUTPUT);
pinMode(left_echoPin,INPUT);
pinMode(left_trigPin,OUTPUT);
pinMode(centre_echoPin,INPUT);
pinMode(centre_trigPin,OUTPUT);
pinMode(right_echoPin,INPUT);
pinMode(right_trigPin,OUTPUT);
pinMode(flame,INPUT);
pinMode(buzzer,OUTPUT);

}

void loop() {
  
forward();

// Clears the trigPin
digitalWrite(left_trigPin, LOW);
digitalWrite(right_trigPin, LOW);
digitalWrite(centre_trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(left_trigPin, HIGH);
digitalWrite(right_trigPin, HIGH);
digitalWrite(centre_trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(left_trigPin, LOW);
digitalWrite(right_trigPin, LOW);
digitalWrite(centre_trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(left_echoPin, HIGH);
duration2 = pulseIn(right_echoPin, HIGH);
duration3 = pulseIn(centre_echoPin, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
distance2= duration2*0.034/2;
distance3= duration3*0.034/2;
Serial.println(distance1);
Serial.println(distance2);
Serial.println(distance3);
Serial.println("****");


  flame_detected = digitalRead(flame);
Serial.println(flame_detected);
Serial.println("****");
  if (flame_detected == 0)
  { 
    stop();
    digitalWrite(buzzer, HIGH);
    delay(10000);
    Serial.println("Flame detected...! take action immediately.");
    digitalWrite(buzzer, LOW);
    
  }

else if(distance1<20 && distance2<20 && distance3<20){
  rightward();
  delay(2000);/////turn_around
  
  /*digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
delay(500);
  stop();
  delay(5000);*/
  
}

else if(distance1>20 && distance2<20 && distance3<20){
  leftward();
  delay(500);
  pre = 0;
  forward();
  delay(500);
  leftward();
  delay(500);
/*digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
delay(500);
  stop();
  delay(5000);*/
  }

else if(distance1<20 && distance2<20 && distance3>20){
  rightward();
  delay(500);
  pre = 1;
  forward();
  delay(500);
  rightward();
  delay(500);
/*digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
delay(500);
  stop();
  delay(5000);*/
  }
else if(distance1>20 && distance2<20 && distance3<20){
  leftward();
  delay(500);
  pre = 0;
  forward();
  delay(500);
  leftward();
  delay(500);
/*digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
delay(500);
  stop();
  delay(5000);*/
  }
else if(distance1>20 && distance2<20 && distance3>20 && pre==-1){
  rightward();
  delay(500);
  pre = 1;
  forward();
  delay(500);
  rightward();
  delay(500);
 /*digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
delay(500); 
  stop();
0  delay(5000);*/
  }  
else if(distance1>20 && distance2<20 && distance3>20 && pre==0){
  rightward();
  delay(500);
  pre = 1;
  forward();
  delay(500);
  rightward();
  delay(500);
/*digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
delay(500);  
  stop();
  delay(5000);*/
  }  

else if(distance1>20 && distance2<20 && distance3>20 && pre==1){
  leftward();
  delay(500);
  pre = 0;
  forward();
  delay(500);
  leftward();
  delay(500);
/*digitalWrite(led,HIGH);
delay(500);
digitalWrite(led,LOW);
delay(500); 
  stop();
  delay(5000);*/
  }    



  
}