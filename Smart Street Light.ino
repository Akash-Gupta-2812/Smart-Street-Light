 int relay =6 ;
  int ldr=A0;
  int ir1=12;
 // int ir2=13;  //in case another infrared sensor is used
  int pir=10;
  int brightness=0;
  int irstat1=0;
 // int irstat2=0;
  int pirstat=0;
  
    void setup() {
      Serial.begin(9600);
      pinMode(relay , OUTPUT);
      pinMode(ldr , INPUT );
      pinMode(ir1 , INPUT );
     // pinMode(ir2 , INPUT );
      pinMode(pir , INPUT );
      }

void loop() {
  int ldrstatus=analogRead(ldr);
  if( ldrstatus<=400){
pirstat=digitalRead(pir);    
irstat1=digitalRead(ir1);
//irstat2=digitalRead(ir2);
if(irstat1==LOW ||  pirstat==LOW){
  brightness=255;
 analogWrite(relay,brightness);
 } 
else if(irstat1==HIGH &&  pirstat==HIGH)
{brightness=80;
 analogWrite(relay,brightness);
  }
else{return(0);}    
  }
  else{
    digitalWrite(relay,LOW);
    }   

  Serial.println("ldrstatus=");
Serial.println(ldrstatus);
Serial.println("led brightness=");
Serial.println(brightness);
Serial.println("ir status=");
Serial.println(irstat1);
//Serial.println(irstat2);
Serial.println("pirstat=");
Serial.println(pirstat);
}
