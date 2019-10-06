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
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 290/ 2;   //convertimos a distancia, en cm
   if(distanceCm <=40 && distanceCm>=21){
    digitalWrite(PC4,HIGH);
    delay(10);
    digitalWrite(PC4,LOW);
    delay(10);
   }else if(distanceCm<=20){
    digitalWrite(PC4,HIGH);
    delay(1000);
   }
   else{
    digitalWrite(PC4,LOW);
    delay(1000);
   }
   return distanceCm;
}
