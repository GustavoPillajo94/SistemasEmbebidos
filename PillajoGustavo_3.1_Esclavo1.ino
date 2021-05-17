/*
 * DEBER 3.1
 * TEMA: COMINICACION I2C
 * NOMBRE: GUSTAVO PILLAJO
 */
///////ESCLAVO 1//////////
#include<Wire.h>                //llamado de libreria wire
char dato;                      //variable para almacenar datos
int led[]={13,12,11};           //pines de salida para los leds
int i=0;                        //variables para ciclos for y secuencia de encendido de leds
int j=0;
void setup() {
  Wire.begin(4);                //inicio de libreria wire
  Wire.onReceive(secuencia);    //llamado de metodo
  Serial.begin(9600);           // inicio de comunicacion serial
  for(i=0;i<3;i++){             //ciclo de conteo de vector de leds
    pinMode(led[i],OUTPUT);     //declarando las salidas de los leds que se van a leer dentro del vector de pines de leds
    }
}
void loop() {

}
void secuencia (int bytes){       //metodo de esclavo 
  while(Wire.available()){        //revision de si hay datos enviados desde el maestro
    dato=Wire.read();             //lecctura de datos del maestro y almacenando en la variable
    switch(dato){                 //ciclo switch con casos que se recibe del matestro
      case 'A':
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
