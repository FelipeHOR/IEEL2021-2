//Disp 7 seg 1

int a1 = 0; //Bit 0 Decoder 1
int a2 = 1; //Bit 1 Decoder 1
int a3 = 2; //Bit 2 Decoder 1
int a4 = 3; //Bit 3 Decoder 1

//Disp 7 seg 2
int b1 = 8; //Bit 0 Decoder 2
int b2 = 9; //Bit 1 Decoder 2
int b3 = 10; //Bit 2 Decoder 2
int b4 = 11; //Bit 3 Decoder 2

//Pinos digitais
int PinBot = 4;
int PinLED = 5;
int Valv1 = 6;
int Valv2 = 7;

//Variaveis
int n=30; //Setting initial value of n to 0
int d1;
int d2;
int s;
int BotFlag=0;
int state = 0;

//Configuração de pinagem
void setup()
{
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
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

}

void loop(){
  //Desligar tudo quando 0
  if (n == 0){
  	digitalWrite(PinLED, LOW);
  	digitalWrite(Valv1,LOW);
   	digitalWrite(Valv2,LOW);
  }
  
  if (n <= 20){
  	digitalWrite(Valv1,LOW);
  }
  if (n <= 15){
  	digitalWrite(Valv2,LOW);  
  }
  
  state = digitalRead(PinBot);
  if(state == HIGH){
    //Se o flag for 0, (estado inicial) Liga as Válvulas e o Led de aviso
     if(BotFlag==0){
    	BotFlag = 1;
    	digitalWrite(PinLED, HIGH);
    	digitalWrite(Valv1,HIGH);
    	digitalWrite(Valv2,HIGH);
    }
    //Se o flag for 1, desliga as Válvulas e o Led de aviso
    else{
    	digitalWrite(PinLED, LOW);
  		digitalWrite(Valv1,LOW);
   		digitalWrite(Valv2,LOW);
    }
    
    
 }
  
 if (BotFlag == 1){
 	if(s == 60){
    	n--;
   		s == 0;
 	}
 
 d1=n%10; // Resto da divisão acumulado em d1 
 d2=n/10; // Resultado da divisão acumulado em d2
 disp1(d1); // Chama a função
 disp2(d2); // Chama a função
 
 delay(1000);// delay de 1 s
 s = 60;
 }
}

void disp1(int num){
  if(num == 0){
    digitalWrite(a1, LOW); 
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 1){
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 2){
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, LOW);//0
  }
  if(num == 3){
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, LOW);//0
  }
  if(num == 4){
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 5){
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 6){
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 7){
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, HIGH);//1
    digitalWrite(a3, HIGH);//1
    digitalWrite(a4, LOW);//0
  }
  if(num == 8){
    digitalWrite(a1, LOW);//0
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, HIGH);//1
  }
  if(num == 9){
    digitalWrite(a1, HIGH);//1
    digitalWrite(a2, LOW);//0
    digitalWrite(a3, LOW);//0
    digitalWrite(a4, HIGH);//1
  }
}

void disp2(int num){
  if(num == 0){
    digitalWrite(b1, LOW);//
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 1){
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 2){
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 3){
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, LOW);//0
  }
  if(num == 4){
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 5){
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 6){
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 7){
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, HIGH);//1
    digitalWrite(b3, HIGH);//1
    digitalWrite(b4, LOW);//0
  }
  if(num == 8){
    digitalWrite(b1, LOW);//0
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, HIGH);//1
  }
  if(num == 9){
    digitalWrite(b1, HIGH);//1
    digitalWrite(b2, LOW);//0
    digitalWrite(b3, LOW);//0
    digitalWrite(b4, HIGH);//1
  }
}
