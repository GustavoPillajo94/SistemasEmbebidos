#include<MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
//reloj
int horas=12;
int minutos=4;
int segundos=5;
int bhora=14;
int bmin=15;
int ighora;
int igmin;
//interrupciones
int i=0;
int on=0;
int off=0;
int mod=0;
int cont=0;
int leds[]={7, 6, 5, 4};
//sensores
int sensor1=22;
int sensor2=23;
int sensor3=24;
int sensor4=25;
int fire;
int vibra;
int mov;
int aire;
void setup() {
lcd.begin(16,4);
MsTimer2::set(1000,reloj);
  MsTimer2::start();
attachInterrupt(digitalPinToInterrupt (21),encendido,RISING);
attachInterrupt(digitalPinToInterrupt (20),apagado,RISING);
attachInterrupt(digitalPinToInterrupt (19),seleccion,RISING);
  pinMode(bhora,INPUT);
  pinMode(bmin,INPUT);
    pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
    pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
for (cont=0;cont<4;cont++){
       pinMode(leds[cont],OUTPUT);
         }
}

void loop() {
lcd.clear();
cont=random(0,4);
fire=digitalRead(sensor1);
vibra=digitalRead(sensor2);
mov=digitalRead(sensor3);
aire=digitalRead(sensor4);
  if(off==1){
    Serial.println("Sistema Activado");
    lcd.setCursor(0,0);
    lcd.print("Sistema Activado");
    lcd.setCursor(0,1);
        lcd.print("HORA:");
        lcd.print(" ");
        if(horas<10)lcd.print("0");
        lcd.print(horas);
        lcd.print(":");
        if(minutos<10)lcd.print("0");
        lcd.print(minutos);
        lcd.print(":");
        if(segundos<10)lcd.print("0");
        lcd.print(segundos);
    switch(mod){
      case 0:
      lcd.setCursor(0,2);
      lcd.print("elija el caso");
      break;
      case 1:
      lcd.setCursor(0,2);
      lcd.print("caso 1");
     digitalWrite(leds[cont],HIGH);
     delay(100);
     digitalWrite(leds[cont],LOW);
     delay(100);
      break;
      case 2:
      lcd.setCursor(0,2);
      lcd.print("caso 2 ");
      ighora=digitalRead(bhora);
if(ighora==1){
  horas++;
  if(horas>24){
    horas=0;
    }
  }
  igmin=digitalRead(bmin);
  if(igmin==1){
  minutos++;
  if(minutos>60){
    minutos=0;
    }
  }
      break;
      case 3:
      lcd.setCursor(0,2);
      lcd.print("caso 3");
      if(fire==HIGH){
        lcd.setCursor(0,3);
        lcd.print("FUEGO!");
        }
        else if(vibra==HIGH){
          lcd.setCursor(0,3);
          lcd.print("TEMBLOR");
          }
          else if(mov==HIGH){
             lcd.setCursor(0,3);
             lcd.print("MOVIMIENTO");
            }
            else if (aire==HIGH){
               lcd.setCursor(0,3);
               lcd.print("CONTAMINADO");
              }
      
      break;
      case 4:
      mod=0;
      break;
      }
    //delay(1000);
  }
  else if(off==0){
    Serial.println("Sistema Apagado");
    lcd.setCursor(0,0);
    lcd.print("Sistema Apagado");
    off=0;
    on=0;
    mod=0;
    }
delay(500);
}

void reloj(){
  segundos++;
  if(segundos>59){
    minutos ++;
    segundos=0;
    }
    if(minutos>59){
      horas++;
      minutos=0;
      segundos=0;
      }
      if(horas>=24){
        horas=0;
        minutos=0;
        segundos=0;
        }
       
         
  }


void apagado(){
 off--;
      }
void encendido(){
off++;

    }
void modos(){
 
      
      }
void seleccion(){
        mod++;
      }

