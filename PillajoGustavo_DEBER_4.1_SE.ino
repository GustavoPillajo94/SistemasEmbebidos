/* 
 *  DEBER 4.1
 * TEMA: CAD Y PWM
 * NOMBRE: Gustavo Pillajo
 */
 #include <LiquidCrystal.h>
 LiquidCrystal lcd(13,12,11,10,9,8);    // seleccion de pines para lcd
 int conversor1;                        // variable para adquirir datos del conversor
 int conversor2; 
 float vol1;                            //variable de conversion del conversor 
 float vol2;
 int dutty1;                            //variable para el uso de pwm
 int dutty2;
 int st;
 const int btn=4;
 const int sw=3;
 int i=0;
void setup() {
    lcd.begin(16,4);                      //inicializando lcd
    pinMode(btn,INPUT);
    pinMode(sw,INPUT);
  
}
void loop() {
  if(digitalRead(btn)==HIGH){
       delay(300);
       i=1-i;
       if(i==0){
          conversor1=analogRead(A0);           //lectura del canal A0 
          vol1=(conversor1*5.0)/1023.0;        //conversor de voltaje (formula)
          dutty1=conversor1/4;                 //cambio la escala para el ciclo de dutty
          analogWrite(6,st);
          analogWrite(5,st);
          lcd.setCursor(0,0);                   //cursor de lcd
          lcd.print("MOTOR1");
          lcd.setCursor(7,0);
          lcd.print("CAD:");
          lcd.setCursor(11,0);
          lcd.print(conversor1);
          lcd.setCursor(0,1);
          lcd.print("V:");
          lcd.setCursor(3,1);
          lcd.print(vol1);
          lcd.setCursor(9,1);
          lcd.print("PWM:");
          lcd.setCursor(13,1);
          lcd.print((dutty1*100)/255);
        }  
          else {
             analogWrite(6,dutty1);
             }
        }
    
       if(digitalRead(sw)==LOW){
            conversor2=analogRead(A0);          //lectura del canal A0 
            vol2=(conversor2*5.0)/1023.0;       //conversor de voltaje (formula)
            dutty2=conversor2/4;                //cambio la escala para el ciclo de dutty
            analogWrite(5,dutty1);              //envio de valor al pin 5
            analogWrite(6,st);
            lcd.setCursor(0,2);                 //cursor de lcd
            lcd.print("MOTOR2");
            lcd.setCursor(7,2);             
            lcd.print("CAD:");
            lcd.setCursor(11,2);
            lcd.print(conversor2);
            lcd.setCursor(0,3);
            lcd.print("V:");
            lcd.setCursor(3,3);
            lcd.print(vol2);
            lcd.setCursor(9,3);
            lcd.print("PWM:");
            lcd.setCursor(13,3);
            lcd.print((dutty2*100)/255);
            delay(300); 
          }
      else{       
        analogWrite(5,st);                    //envio de valor al pin 5
        delay(300);
       } 
}

