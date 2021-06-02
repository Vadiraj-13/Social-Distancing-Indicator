int buzzerPin= 2;
int echoPin= 6;
int trigPin= 5;
int A = 4;
int B = 8;
int C = 9;
int minDistance = 100;
int maxDistance = 200;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (A,OUTPUT);
  pinMode (B,OUTPUT);
  pinMode (C,OUTPUT);
 
}

void loop() 
{
  int distance = calcDistance();
  if (distance<minDistance)//Red
  {digitalWrite(A,HIGH);
  digitalWrite(buzzerPin,HIGH);  
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  }
  else if (distance>=minDistance&&distance<=maxDistance)//yellow
   { 
    digitalWrite(B,HIGH); 
      digitalWrite(A,LOW);
      digitalWrite(C,LOW);
      digitalWrite(buzzerPin,LOW);
   }
   
  else if (distance>maxDistance)//green
   { 
    digitalWrite(C,HIGH);
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(buzzerPin,LOW);
    }
    delay(1000);
}

int calcDistance()
{ 
  long distance,duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  return distance;
}
