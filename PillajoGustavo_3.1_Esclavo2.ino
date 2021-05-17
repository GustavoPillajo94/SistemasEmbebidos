/*
 * DEBER 3.1
 * TEMA: COMINICACION I2C
 * NOMBRE: GUSTAVO PILLAJO
 */
///////ESCLAVO 2//////////
#include<Wire.h>
char dato;
int led[]={13,12,11};
int i=0;
int j=0;
void setup() {
  Wire.begin(4);
  Wire.onReceive(secuencia2);
  Serial.begin(9600);
    for(i=0;i<3;i++){
    pinMode(led[i],OUTPUT);
    }
}

void loop() {
  
}
void secuencia2 (int bytes){
  while(Wire.available()){
    dato=Wire.read();
    switch(dato){
      case 'B':
      for(j=0;j<5;j++){
      for(i=0;i<3;i++){
              digitalWrite(led[i],HIGH);
              delay(5000);
      }
      for(i=0;i<3;i++){
              digitalWrite(led[i],LOW);
              delay(5000);
      }
      delay(1000);
      }
      break;
      default :
      for(i=0;i<3;i++){
              digitalWrite(led[i],LOW);
              delay(1000);
      }
      break;
      }
    }
  }
