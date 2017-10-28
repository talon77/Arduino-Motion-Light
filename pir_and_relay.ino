
int pir = 2;
int relay = 9;
int led = 13;
int photo = A7;
int numVal = 0;

void setup(){
  Serial.begin(9600);
  pinMode(photo, INPUT);
  pinMode(pir, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(pir, LOW);
  digitalWrite(relay, HIGH);
  
  longdelay(5);
}

void shortdelay(){
 delay(25); 
}

void longdelay(int mytime){
  Serial.println("Starting Timer!");
  digitalWrite(pir, LOW);
  for(int i = 0; i < mytime; i++){
    Serial.println(i);
    while(digitalRead(pir) == HIGH){
      Serial.print(".");
      i = 0;
      delay(1000);
    }
   delay(1000); 
  }
  Serial.println("Time Done!");
}

void blinky(){
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  delay(500);
}

void loop(){
 numVal = analogRead(photo);
 Serial.println(numVal);
 while(analogRead(photo) > 300){
    blinky();
    Serial.println("Daylight ");  
    Serial.println(analogRead(photo));
    Serial.println("");
 }
 
 if(digitalRead(pir) == HIGH){
  digitalWrite(led, HIGH);
  digitalWrite(relay, LOW);
   longdelay(5);
 }
 if(digitalRead(pir) == LOW){
   digitalWrite(led, LOW);
   digitalWrite(relay, HIGH);
   shortdelay();
 }
 
}
