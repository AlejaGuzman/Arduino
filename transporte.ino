#define LED PC4
#define ECHO PC5
#define TRIGGER PC6
int cont=0,valor=0;

void setup() {
   Serial.begin(9600);
   pinMode(TRIGGER, OUTPUT);
   pinMode(ECHO, INPUT);
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
   if(distanceCm<100){
    cont=cont+1;
    valor=valor+5200;
    digitalWrite(PC4,HIGH);
    delay(1000);
    digitalWrite(PC4,LOW);
   }
   delay(500);
   Serial.print("Numero de personas: ");
   Serial.println(cont);
   Serial.print("Costo total: ");
   Serial.print(valor);
   Serial.println("$");
}
