/******************************************************************
*
* Práctica de simulación dunha xanela dun automúvil(II):
* Debemos usar dous motores, un de baixada e outro de subida que, 
* cando se pulse o botón vaia nun sentido, e cando o pulses outra 
* vez vaia no sentido contrario. Neste caso, para lograr iso imos
* executar unha situación de paro, que será realizada mediante o
* uso de finais de carreira.
*
*******************************************************************
*
* Autor: Xan Pérez Iglesias
* Data: 06/02/2025  --  Hora: 10:25
* Softwre: Visual Studio Code
*
******************************************************************/

//Sentencias de preprocesamiento
#define PULS 11
#define RELE_UP 12
#define RELE_DOWN 13
#define FC_SUPERIOR 9
#define FC_INFERIOR 10

//Declaración de ESTADO
int state = 1;
int time = 20;
int counter = -1;

void setup(){
  pinMode(PULS, INPUT);
  pinMode(RELE_UP, OUTPUT);
  pinMode(RELE_DOWN, OUTPUT);
  pinMode(FC_SUPERIOR, INPUT);
  pinMode(FC_INFERIOR, INPUT);
  Serial.begin(9600);
}

void loop(){
    //Lectura pulsador
    if(digitalRead(PULS)){
        state = (state + 1)% 4; //Obtención de resto (0, 1, 2, 3) a partir de división entera, para los estados.
        while(digitalRead(PULS)){
            delay(time);
        }
    }

    if(digitalRead(FC_INFERIOR)){
        state = 1; 
        while(digitalRead(PULS)){
            delay(time);
        }
    }
    if(digitalRead(FC_INFERIOR)){
        if(state == 0){
            state = 1;
        }
    }

    if(digitalRead(FC_SUPERIOR)){
        if(state == 2){
            state = 3;
        }
    }

    //Pulsador pulsado una vez == motor arriba
       switch(state){
         case 0:   //Caso 0: sube la ventanilla
           impulseUp;
           break;
         case 1:   //Caso 1: Baja la ventanilla
           impulseDown;
           break;
         default:  //Caso 2: Parada de la ventanilla
           stop;
       }

     
    Serial.print("Counter"); Serial.print(counter); Serial.print("  |  ");
    Serial.println("State:"); Serial.print(state);
}

void impulseUp(){
    digitalWrite(RELE_UP, HIGH);
    digitalWrite(RELE_DOWN, LOW);
    delay(time);
}

void impulseDown(){
    digitalWrite(RELE_UP, LOW);
    digitalWrite(RELE_DOWN, HIGH);
    delay(time);
}

void stop(){
    digitalWrite(RELE_UP, LOW);
    digitalWrite(RELE_DOWN, LOW);
    delay(time);
}
