#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 2, 11, 10, 9, 8);

//Pinos digitais
int PinBot = 4;
int PinLED = 5;
int Valv1 = 6;
int Valv2 = 7;

//Variaveis
int n=0;
int m=0;
int s=0;
int flag = 0;
int state = 0;
int triggerPin = 13;
int echoPin = 12;

int botState = 0;
int prevBotState = 0;
int ledState = 0;
int ultraState = 0;
int prevUltraState = 0;

//Configuração de pinagem
void setup()
{
  lcd.begin(16, 2);
  lcd.clear();


  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(4, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

}

void loop(){

  //Desligar tudo quando 0
  if (m == 30){
    ledState = 0;
    digitalWrite(Valv1,LOW);
    digitalWrite(Valv2,LOW);
  }

  if (m >= 20){
    digitalWrite(Valv1,LOW);
  }

  if (m >= 15){
    digitalWrite(Valv2,LOW);  
  }

  state = digitalRead(PinBot);
  ultraState = (0.01723 * readUltrasonicDistance(triggerPin, echoPin) < 70);

  if (state != prevBotState){
    if(state == 1){
      ledState = !ledState;
      m = 0;
    }

    prevBotState = state;

  }
  
  if (ultraState != prevUltraState){
    if(ultraState == 1){
      ledState = !ledState;
      m = 0;
    }

    prevUltraState = ultraState;

  }
  
  
  digitalWrite(PinLED, ledState);

  
if(ledState == HIGH){
  	n = 30;
  	flag = 1;
   	digitalWrite(PinLED, HIGH);
   	digitalWrite(Valv1,HIGH);
   	digitalWrite(Valv2,HIGH);
}
if(ledState == LOW){
    	n = 0;
        m = 0;
        s = 0;
        flag = 0;
   		digitalWrite(PinLED, LOW);
   		digitalWrite(Valv1,LOW);
   		digitalWrite(Valv2,LOW);
  		lcd.clear();
}

   	

  if (flag == 1){
    if(s == 60){
      if(m<n){
        m++;
        s = 0;
      }
    }
    if (m<n){
      lcd.clear();
      lcd.print("Tempo : "); 
      lcd.print(m);
      lcd.print(":"); 
      lcd.print(s);
      s++;
    }
    if (m==n){
      lcd.clear();
      lcd.print("Tempo concluido");
      lcd.setCursor(0,1);
      lcd.print("Tire as mascaras");
    }

    delay(500);// delay de 1 s

  }
  
  delay(500);
}


long readUltrasonicDistance(int triggerPin, int echoPin){

  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // Liga o trigger

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  // Leitura do ECHO 

  return pulseIn(echoPin, HIGH);
}
