#define ZUMBADOR PC4
#define ECHO PC5
#define TRIGGER PC6

void setup() {
   Serial.begin(9600);
   pinMode(TRIGGER, OUTPUT);
   pinMode(ECHO, INPUT);
   pinMode(ZUMBADOR,OUTPUT);
}
 
void loop() {
   ping(TRIGGER, ECHO);
   delay(100);
   ping(TRIGGER,ECHO);
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  
   delayMicroseconds(1);
   digitalWrite(TriggerPin, HIGH);  
   delayMicroseconds(1);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH); 
   
   distanceCm = duration * 10 / 290/ 2;   
   if(distanceCm<50){
    tone(ZUMBADOR,2800);
    
   }else
   noTone(ZUMBADOR);
}
