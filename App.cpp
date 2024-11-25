const int trigPin = 10;  
const int echoPin = 11;  
const int ledPin = 13;   
const int buzzerPin = 5;
 
long duration;
int distance;
 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2;
 
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");
 
  if (distance > 0 && distance <= 5) {
    digitalWrite(ledPin, HIGH); 
    tone(buzzerPin, 1000);       
  } else {
    digitalWrite(ledPin, LOW);   
    noTone(buzzerPin);          
  }
  delay(100); 
}
