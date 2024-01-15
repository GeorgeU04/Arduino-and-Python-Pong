int xValuePin = A0;
int yValuePin = A1;
int xValue = 0;
int yValue = 0;
bool up = false;
bool down = false;
bool active = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(xValuePin, INPUT);
  pinMode(yValuePin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if(yValue > 530){
    active = true;
    down = true;
    up = false;
  }

  if(yValue < 515){
    active = true;    
    down = false;
    up = true;
  }

  if (yValue == 519 || yValue == 520 || yValue == 521){
    active = false;    
    down = false;
    up = false;
  } 

  yValue = analogRead(yValuePin);
  Serial.print(up); 
  Serial.print(","); 
  Serial.print(down); 
  Serial.print(","); 
  Serial.print(active); 
  Serial.println(",");   
  delay(10);
}
