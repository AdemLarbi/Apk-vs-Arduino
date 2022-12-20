#include <AFMotor.h>
#include <SoftwareSerial.h>
AF_DCMotor motor_av1(1);
AF_DCMotor motor_av2(2);
AF_DCMotor motor_ar3(3);
AF_DCMotor motor_ar4(4);

SoftwareSerial ESPserial(9, 2); // RX | TX
/*< UltraSon >*/

//#define TRIGG 11 // Broche TRIGGER
//#define ECHO 6    // Broche ECHO

int bleu = 13;
int red =5;
int green=10;
int titit=3;
int led=red;

/*</UltraSon >*/


String NomduReseauWifi = "RObot"; 
String MotDePasse      = "123456789"; 

void Forward();
void Backward();
void Right();
void Left();
void Stop();
void BackwardLeft();
void BackwardRight();
void ForwardRight();
void ForwardLeft();
 void b();
void r();
void g();
void ledon();
void ledoff();

void setup() 
{
  pinMode(bleu, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(titit, OUTPUT);
  digitalWrite(titit, HIGH);
  digitalWrite(bleu, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  /*<UltraSon >*/
//pinMode(TRIGG, OUTPUT); //Configuration des broches
//pinMode(ECHO, INPUT);
/*</UltraSon >*/

Serial.begin(115200);            
ESPserial.begin(115200);     
initESP8266(); 
Serial.println("");
Serial.println("Ready");
Serial.println("");   
} 
 
void loop() 
{  
 char var;
 
 if ( Serial.available() ){
  var= ESPserial.read();
  switch (var) { 
    case '0' : digitalWrite(titit, LOW); break;
   
    case '5' : digitalWrite(titit, HIGH); break;
  }
  
  }
  
   if ( Serial.available() )       {  
    var= ESPserial.read();  
    switch (var) { 
    case '0' : digitalWrite(titit, LOW); break;
    case '5' : digitalWrite(titit, HIGH); break;
    case '7' : led=green; break;
    case '8' : led=red;break;
    case '9' : led=bleu; break;
 }
  }
  //  Serial.println(ultrasonic.distanceRead());*/

    if ( ESPserial.available() )   {  
      var= ESPserial.read();    
      
   switch (var) {
    case 'a' : Forward(); ledon(); break;
             
    case 'r' : Backward();ledon();break;
    
    case 'd' : Right();ledon(); break;
    
    case 'g' : Left();ledon();break;
    
    case 'k' : ForwardLeft();ledon(); break;
    
    case 'l' : ForwardRight();ledon(); break;
    
    case 'j' : BackwardLeft();ledon(); break;

    case 'm' : BackwardRight();ledon(); break;
    
    case 's' : Stop();ledoff(); break;
    
   
}
}
}
void initESP8266()
{  
  Serial.println("**********************************************************");  ! 
  Serial.println("**************** DEBUT DE L'INITIALISATION ***************");
  Serial.println("**********************************************************");  
  envoieAuESP8266("AT+RST");
  recoitDuESP8266(2000);
  Serial.println("**********************************************************");
  envoieAuESP8266("AT+CWMODE=3");
  recoitDuESP8266(5000);
  Serial.println("**********************************************************");
  envoieAuESP8266("AT+CWSAP=\"RObot\",\"123456789\",3,3");
  recoitDuESP8266(10000);
  Serial.println("**********************************************************");
  envoieAuESP8266("AT+CIPMUX=1");   
  recoitDuESP8266(1000);
  Serial.println("**********************************************************");
  envoieAuESP8266("AT+CIPSERVER=1,80");
  recoitDuESP8266(1000);
  Serial.println("**********************************************************");
  envoieAuESP8266("AT+CIFSR");   
  recoitDuESP8266(1000);
  Serial.println("**********************************************************");
  Serial.println("***************** INITIALISATION TERMINEE ****************");
  Serial.println("**********************************************************");
  Serial.println("");  
}


void envoieAuESP8266(String commande)
{  
  ESPserial.println(commande);
}
/****************************************************************/
/*Fonction qui lit et affiche les messages envoyés par l'ESP8266*/
/****************************************************************/
void recoitDuESP8266(const int timeout)
{
  String reponse = "";
  long int time = millis();
  while( (time+timeout) > millis())
  {
    while(ESPserial.available())
    {
      char c = ESPserial.read();
      reponse+=c;
    }
  }
  Serial.print(reponse);   
}
void Forward(){ 
motor_av1.setSpeed(255);
motor_av2.setSpeed(255);
motor_ar3.setSpeed(255);
motor_ar4.setSpeed(255);
              motor_av1.run(FORWARD);
              motor_av2.run(FORWARD);
              motor_ar3.run(FORWARD);
              motor_ar4.run(FORWARD);
} 
 void Backward(){
motor_av1.setSpeed(255);
motor_av2.setSpeed(255);
motor_ar3.setSpeed(255);
motor_ar4.setSpeed(255);
              motor_av1.run(BACKWARD);
              motor_av2.run(BACKWARD);
              motor_ar3.run(BACKWARD);
              motor_ar4.run(BACKWARD);
 }  
 void Left(){ 
motor_av1.setSpeed(255);
motor_av2.setSpeed(255);
motor_ar3.setSpeed(255);
motor_ar4.setSpeed(255);
              motor_av1.run(RELEASE);
              motor_av2.run(BACKWARD);
              motor_ar3.run(BACKWARD);
              motor_ar4.run(RELEASE);
 }  
 void Right(){ 
motor_av1.setSpeed(255);
motor_av2.setSpeed(255);
motor_ar3.setSpeed(255);
motor_ar4.setSpeed(255);
              motor_av1.run(BACKWARD);
              motor_av2.run(RELEASE);
              motor_ar3.run(RELEASE);
              motor_ar4.run(BACKWARD);
 }  
 void Stop(){ 
motor_av1.setSpeed(255);
motor_av2.setSpeed(255);
motor_ar3.setSpeed(255);
motor_ar4.setSpeed(255);
              motor_av1.run(RELEASE);
              motor_av2.run(RELEASE);
              motor_ar3.run(RELEASE);
              motor_ar4.run(RELEASE);
 }
 void ForwardLeft(){ 
motor_av1.setSpeed(255);
motor_av2.setSpeed(150);
motor_ar3.setSpeed(150);
motor_ar4.setSpeed(255);
              motor_av1.run(FORWARD);
              motor_av2.run(FORWARD);
              motor_ar3.run(FORWARD);
              motor_ar4.run(FORWARD);
 }  
 void ForwardRight(){ 
motor_av1.setSpeed(150);
motor_av2.setSpeed(255);
motor_ar3.setSpeed(255);
motor_ar4.setSpeed(150);
              motor_av1.run(FORWARD);
              motor_av2.run(FORWARD);
              motor_ar3.run(FORWARD);
              motor_ar4.run(FORWARD);
 }
  void BackwardLeft(){ 
motor_av1.setSpeed(255);
motor_av2.setSpeed(150);
motor_ar3.setSpeed(150);
motor_ar4.setSpeed(255);
              motor_av1.run(BACKWARD);
              motor_av2.run(BACKWARD);
              motor_ar3.run(BACKWARD);
              motor_ar4.run(BACKWARD);
 }  
 void BackwardRight(){ 
motor_av1.setSpeed(150);
motor_av2.setSpeed(255);
motor_ar3.setSpeed(255);
motor_ar4.setSpeed(150);
              motor_av1.run(BACKWARD);
              motor_av2.run(BACKWARD);
              motor_ar3.run(BACKWARD);
              motor_ar4.run(BACKWARD);
 }  

  void ledon(){
               digitalWrite(bleu, HIGH);
               digitalWrite(red, HIGH);
               digitalWrite(green, HIGH);
               digitalWrite(led, LOW);
               }
  void ledoff(){
               digitalWrite(bleu, HIGH);
               digitalWrite(red, HIGH);
               digitalWrite(green, HIGH);
            
               }



