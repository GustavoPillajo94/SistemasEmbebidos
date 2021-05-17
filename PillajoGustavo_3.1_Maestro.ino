/*
 * DEBER 3.1
 * TEMA: COMUNICACION I2C
 * NOMBRE: Gustavo Pillajo
 */
            ///////////MAESTRO/////////////
#include <Wire.h>                // libreria i2c
char dato;                       //variable de almacenamiento
void setup() {
  Wire.begin();                  //inicio de comunicacion serial
  Serial.begin(9600);            //inicio de comunicacion serial
}

void loop() {
  if (Serial.available()>0){      //verificar si hay datos existentes
    dato=Serial.read();           //almacena el dato en la variable
    Wire.beginTransmission(4);    //empieza la comunicacion i2c
    Wire.write(dato);             // envio de dao 
    Wire.endTransmission();       //fin de transmision i2c
    }
}
