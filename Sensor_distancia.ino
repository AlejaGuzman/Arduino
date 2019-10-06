//DECLARA PUERTOS
#define LED PC4
const int EchoPin = 5;
const int TriggerPin = 6;
 
void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
 
void loop() {
   int cm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);
   delay(1000);
   ping(TriggerPin,EchoPin);
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
  
   digitalWrite(TriggerPin, LOW);  
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH); 
    
   distanceCm = duration * 10 / 290/ 2; 
   //SI LA DISTANCIA REGISTRADA ESTA ENTRE 21 Y 40 EL LED PARPADEA  
   if(distanceCm <=40 && distanceCm>=21){
    digitalWrite(PC4,HIGH);
    delay(10);
    digitalWrite(PC4,LOW);
    delay(10);
    //Y SI LA DISTANCIA ES MENOR O IGUAL A 20 QUEDA ENCENDIDO 
   }else if(distanceCm<=20){
    digitalWrite(PC4,HIGH);
    delay(1000);
   }
   //Y SI NO SE CUMPLE NINGUNA EL LED SE APAGA
   else{
    digitalWrite(PC4,LOW);
    delay(1000);
   }
   return distanceCm;
}
