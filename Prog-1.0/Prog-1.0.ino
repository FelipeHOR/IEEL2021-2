// C++ code
//


int PinBot = 4
int PinLED = 5
int Valv1 = 6
int Valv2 = 7

int BotFlag = 0;
  
void setup()
{
  //Declarando o modo de uso de cada pino
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  //Configurações iniciais
  digitalWrite(PinLED, LOW);
  digitalWrite(Valv1,LOW);
  digitalWrite(Valv2,LOW);
  
}

void loop()
{
  //Botão liga pressionado, inicio de rotina
  if(digitalRead(PinBot)==HIGH){
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
}
