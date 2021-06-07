/*
 * CAPITULO V: FUNCIONES ESPECIFICAS 
 * CODIGO 23: manejo de modos sleep
 * DEVER 5.2
 * NOMBRE: GUSTAVO PILLAJO
 */

 //llamado de librerias
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <MsTimer2.h>
#include <EEPROM.h>
///declaracion de variables
int dato;
int on=0;
void(*resetFunc) (void)=0;  //funcion para resetear// es un void dentro de otro void //un metodo dentro de otro metodo
void setup() {
  dato=EEPROM.read(0);  //se leera el dato en la posicion EEEPROM en la posicion 0
  Serial.begin(9600);  //inicio de la comunicacion serial
  Serial.println("setup"); //se imprime un mensaje de inicio de setup
  if(dato==0){           // se realiza una comparacion del dato de entrada si esta en 0 o 1 
    set_sleep_mode(SLEEP_MODE_STANDBY);  // se elige el modo sleep con el que se desea trabajar 
    sleep_enable();   // se activa el metodo sleep
    EEPROM.write(0,1);  // se escribe un dato en la EEPROM en la posicion 0
    wdt_enable(WDTO_8S);  // se eactiva el wdt a 8 seg
    }
    else{
      sleep_disable();  // se desactiva el modo sleep
      EEPROM.write(0,0); // se ecribe un dato 0 en la EEPROM 
      MsTimer2::set(10000,tiempo);  //configuracion de timer2 a 10 segundo 
      MsTimer2::start(); // se inicia en timer2
      }
      attachInterrupt(0,encender,LOW);  // se declara la interrupcion 

}

void loop() {
  if (dato==0){
    Serial.println("dormido");
    delay(1000);
    sleep_mode();  //entra al estado de dormido 
    }
    else{
      Serial.println("despierto");
      delay(1000);
      }
}
void tiempo (){
  Serial.println("dormido");
  delay(2000);
  sleep_mode();
  
  }
void encender(){
  resetFunc();     //llamando al metodo
  }
