#include "IRremote.h"
int receiver = 13;
IRrecv irrecv(receiver);   
decode_results results; 

bool on = false;
int mode = 0;
//connect leds to 2 - 11 to the long side of led.

int led3 = 2;
int led4 = 3;
int led5 = 4;
int led6 = 5;
int led7 = 6;
int led8 = 7;
int led9 = 8;
int led10 = 9;
int led11 = 10;
//time for spins
int sp = 300;
int sps = 100;
int x = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver


pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
pinMode(led9, OUTPUT);
pinMode(led10, OUTPUT);
pinMode(led11, OUTPUT);
}
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
  case 0xFFA25D: Serial.println("POWER"); 
  if (on){
    digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  on = false;
  mode = 100;
  break;
  }if (!on){

  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  on = true;
  break;
  
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0 mode normal"); 
  mode = 0;
  zero();
  break;
  case 0xFF30CF: Serial.println("1 mode fast");
  mode = 1;
//  one();
  break;
  case 0xFF18E7: Serial.println("2 mode slow "); 
  mode = 2;
  two();
  break;
  case 0xFF7A85: Serial.println("3 mode sprinkels"); 
  mode = 3;
  three();
  break;
  case 0xFF10EF: Serial.println("4 mode sprinkels other way"); 
  mode = 4;
  four();
  break;
  case 0xFF38C7: Serial.println("5 mode right side on"); 
  mode = 5;
  five();
  break;
  case 0xFF5AA5: Serial.println("6 mode right side left"); 
  mode = 6;
  six();
  break;
  case 0xFF42BD: Serial.println("7 going threw all modes"); 
  mode = 7;
  break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button   ");
}else {

  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  on = false;
  }
  }}// End Case
    

/* --(end main loop )-- */

void one(){
  
 
   
      
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  delay(1000);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  delay(1000);
   }
  

void two(){

    digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  delay(10000);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  delay(1000);  
    
}
void three(){
  
   digitalWrite(led3, HIGH);
   delay(sp);
  digitalWrite(led4, HIGH);
  delay(sp);
  digitalWrite(led3, LOW);
  delay(sps);
  digitalWrite(led4, LOW);
  delay(sps);
  digitalWrite(led5, HIGH);
   delay(sp);
  digitalWrite(led6, HIGH);
  delay(sp);
  digitalWrite(led5, LOW);
  delay(sps);
  digitalWrite(led6, LOW);
  delay(sps);
  digitalWrite(led7, HIGH);
   delay(sp);
  digitalWrite(led8, HIGH);
  delay(sp);
  digitalWrite(led7, LOW);
  delay(sps);
  digitalWrite(led8, LOW);
  delay(sps);
  digitalWrite(led9, HIGH);
   delay(sp);
  digitalWrite(led10, HIGH);
  delay(sp);
  digitalWrite(led11, HIGH);
  delay(sp);
  digitalWrite(led9, LOW);
  delay(sps);
  digitalWrite(led10, LOW);
  delay(sps);
  digitalWrite(led11, LOW);
  delay(sps);
 
  
}
void four(){
      
        digitalWrite(led11, HIGH);
  delay(sp);
   digitalWrite(led10, HIGH);
  delay(sp);
  digitalWrite(led9, HIGH);
   delay(sp);
   digitalWrite(led11, LOW);
  delay(sp);
   digitalWrite(led10, LOW);
  delay(sp);
  digitalWrite(led9, LOW);
  delay(sp);
  digitalWrite(led8, HIGH);
  delay(sp);
  digitalWrite(led7, HIGH);
   delay(sp);
   digitalWrite(led8, LOW);
  delay(sp);
  digitalWrite(led7, LOW);
  delay(sp);
  digitalWrite(led6, HIGH);
  delay(sp);
  digitalWrite(led5, HIGH);
   delay(sp);
   digitalWrite(led6, LOW);
  delay(sp);
  digitalWrite(led5, LOW);
  delay(sp);
  digitalWrite(led4, HIGH);
  delay(sp);
  digitalWrite(led3, HIGH);
   delay(sp);
   digitalWrite(led4, LOW);
  delay(sp);
  digitalWrite(led3, LOW);
  delay(sp);
       
}
void five(){   
   if (mode == 5){
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
   }
}
  void six(){
   if (mode == 6){
    digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
     digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
   
    }
  }
  void zero(){
    if(mode == 0){
      digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
      
      }
  }  
void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  delay(500);
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume();// receive the next value
    x=0;
    
  }  
  switch(mode){
    case 1:
    one();
    break;
    case 2:
    two();
    break;
    case 3:
    three();
    break;
    case 4:
    four();
    break;
    case 7:
    one();
    two();
    three();
    four();
    break;
    // this switch is to go back to the code if no new buttons where pressed otherwise  chage THIS was the hardest part 
  }
 
}
/*/while (mode == 1){/*/
