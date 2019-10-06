//El programa se trata de una alamrma que si detecta a alguien prende el led y el zumbador y solo se apaga si uno tiene un oprime el boton.
 

#define ULTRA PC4
#define ECHO PC5
#define TRIGGER PC6

const int LED=10;
const int BOTON=7; 
int val;

void setup() {
   Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(BOTON,OUTPUT); 
  pinMode (ULTRA,OUTPUT);
  // pinMode(4,OUTPUT);
   pinMode(TRIGGER, OUTPUT);
   pinMode(ECHO, INPUT);

}
 
void loop() {
   ping(TRIGGER, ECHO);
   
   delay(100);
   
   ping(TRIGGER,ECHO);
}
 //Se crea un metodo que recibe siertas condiciones 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  
   delayMicroseconds(1);
   digitalWrite(TriggerPin, HIGH);  
   delayMicroseconds(1);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH); 
   
   distanceCm = duration * 10 / 290/ 2;   
   val=digitalRead(BOTON);
   
  
   
    if(distanceCm<50){
    
    tone(ULTRA,3800);
    digitalWrite(LED,HIGH);
    Serial.print("alerta");
    
    //2800
   
    
   } 
    if  (digitalRead(BOTON)==LOW){
    digitalWrite(LED,LOW);
    Serial.print("apagada");
     noTone(ULTRA);
    
    } 
  
}
