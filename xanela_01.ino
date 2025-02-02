/******************************************************************
*
* Práctica de simulación dunha xanela dun automúvil(I):
* Debemos usar dous motores, un de baixada e outro de subida que, 
* cando se pulse o botón vaia nun sentido, e cando o pulses outra 
* vez vaia no sentido contrario. 
*
*******************************************************************
*
* Autor: Xan Pérez Iglesias
* Data: 30/01/2025  --  Hora: 09:36
*
******************************************************************/

//Nemónicos (Sentencia Preprocesamiento)
#define PULS 11
#define RELE_UP 12
#define RELE_DOWN 13

//Declaración variables globales
bool stateup = false;
int time = 20;
int counter = -1; 

void setup (){
  pinMode(PULS, INPUT);
  pinMode(RELE_UP, OUTPUT);
  pinMode(RELE_DOWN, OUTPUT);
  Serial.begin(9600);
}

void loop (){
  //Lectura del pulsador
  if(digitalRead(PULS)){
    stateup = !stateup;
    while(digitalRead(PULS)){ //Asegurar lectura única
      delay(20);
    }
  }
  digitalRead(PULS);
  //Si PULS una vez, motor sube. Si PULS +1, motor baja
  //Motor esperará 7 segundos antes de parar
  if (counter > 0){
    if (stateup == true){
      digitalWrite(RELE_UP, HIGH);
      digitalWrite(RELE_DOWN, LOW);
      delay(time);
    } else {
      digitalWrite(RELE_UP, LOW);
      digitalWrite(RELE_DOWN, HIGH);
      delay(time);
    }
    counter -= 1; //Asignación para no infinito (counter)
    
  } else {
    digitalWrite(RELE_UP, LOW);
    digitalWrite(RELE_DOWN, LOW);
  }
}
