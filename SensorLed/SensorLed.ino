
int trigPin = 9;
int echoPin = 2;
int ledPin = 13;
int led1Pin = 12;

int maxRange = 100;  

int getdistance(int trigPin, int echoPin){
  long duration;                   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  duration = duration / 59;
  if ((duration < 2) || (duration > maxRange)) return false;
  return duration;                                    
}


void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(led1Pin,OUTPUT);
  digitalWrite(trigPin,LOW);
  Serial.begin(9600);
}

void loop()
{
  int x = getdistance(trigPin,echoPin);
  int y = maxRange-x;
  int fade = map(y,0,maxRange,0,255);//Maps the brightness to be lowest just before reaching maxRange
  int flash = map(x,0,maxRange,0,1000);//Maps LED to blink in intervals up to one second. 
  
  if (x!=0){
    analogWrite(led1Pin,fade); //Dimming part
    digitalWrite(ledPin,HIGH);
    delay(flash);
    digitalWrite(ledPin,LOW);
    delay(flash);
    Serial.print("ON!");
  }
  else { //If the distance is outside of maxRange, the LED will turn off.
    digitalWrite(led1Pin, LOW);
    digitalWrite(ledPin,LOW);
    Serial.print("OFF!");

  }
  delay(10);
}
  
