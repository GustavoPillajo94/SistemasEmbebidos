/*
 * DEBER 4.3
 * TEMA: TIMER 2
 * NOMBRE: GUSTAVO PILLAJO
 * La modificacion que se realizo fue colocar lineas de codigo con la informacion 
 * que solicita en la activida de mensaje de bienvenida, nombre y apellido.
 */
 #include <MsTimer2.h>    //libreria timer 2
 #include <LiquidCrystal.h>  //libreria lcd

 LiquidCrystal lcd(13,12,11,10,9,8);

 int segundos=0;  //variables para reloj
 int minutos=0;
 int horas=0;
void setup() {
  lcd.begin(20,4);
  MsTimer2::set(1000,reloj);
  MsTimer2::start();

  
}

void loop() {
}
void reloj(){
  if(segundos<60){
    segundos++;       //
    }
    else{
      segundos=0;
      if(minutos<60){  //condicion de minitos
        minutos++;     //incremento de minutos
        }
        else{
          minutos=0;
          if(horas<24){     //condicion de horas
            horas++;       //incremento de horas
            }
            else{
              horas=0;   //reinicio de horas
              }
          }
      }
      lcd.clear();   //borrar el mensaje anterior
      lcd.setCursor(3,0);
      lcd.print("Hola Bienvenido");
      lcd.setCursor(3,1);
      lcd.print("Gustavo Pillajo");
      lcd.setCursor(2,2);  //ubicacion de lcd
      lcd.print(String("Horas:  ")+String("Min: ")+String("Seg: ")); //mensaje de impresion
      lcd.setCursor(4,3);  //ubicacion de lcd
      lcd.print(String(horas)+String("  :  ")+String(minutos)+String("  :  ")+String(segundos));
  }
