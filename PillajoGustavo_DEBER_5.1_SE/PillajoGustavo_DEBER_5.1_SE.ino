/*
 * CAPITULO V: FUNCIONES ESPECIALES 
 * DEBER 5.1
 * NOMBRE: GUSTAVO PILLAJO
 */
#include<EEPROM.h>
#include <Key.h>               //Incluir Libreria Keypad
#include <Keypad.h>       
#include <LiquidCrystal.h>      //Incluir libreria del LCD
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);   //declarar la variable y pines del lcd

const byte fila = 4;            //Declarar variable y el numero de filas
const byte columna = 4;         //Declarar variable y el numero de columnas

char keys[fila][columna] = {    //matriz de caracteres
  { '7', '8', '9', 'A' },
  { '4', '5', '6', 'B' },
  { '1', '2', '3', 'C' },
  { '#', '0', '*', 'D' }
};

const byte rowPins[fila] = { 29, 28, 27, 26 };        //Asignar los pines para las filas
const byte colPins[columna] = { 25, 24, 23, 22 };     //Asignar los pines para las columnas

Keypad teclado = Keypad(makeKeymap(keys), rowPins, colPins, fila, columna);

int k = 0 ;           //variable de conteo
int tam = 0;          //variable tamano del vector
int contador = 0;     //variable de conteo
int estado = 0;       //variable de cambio de estado
int asignar = 0;      //varaible de conteo
char comprobar[7];    //variable contraseña ingresada
String item, texto;     //variable de almacenado
int num = 0;            //variable de conteo
char key2;              //varaible de cambio de estado
char key;               //varaible ingreso de dato
String lectura;
String dato;
const int led1=7;

void setup() {
  Serial.begin(9600);   //inicializar CX Serial
  lcd.begin(16, 4);     //inicializar lcd 16x4
  pinMode(led1,OUTPUT);  //salida para encendido de led1

}

void loop() {

  char key = teclado.getKey();        //variable de ingreso de dato
  if (key) {                          //condicion de ingreso de daro
    if (asignar <= 2) {               //condicion de lectura de letras
      if (key != key2) {              //condicion de cambio de ingreso
        contador = 0;                 //reinicia variable
        asignar++;                    //incrementa el valor de la variable
      }
      key2 = key;                     //asigna cambio de estado-valor
      letras(key);                    //llama al metodo
    }
  }

  if (asignar > 2) {                    //condicion ingreso de numeros
    if (key) {                          //condicion de ingreso de dato
      if (num <= 6) {                   //condicion de acceso
        num++;                          //incrementa valor
        lcd.setCursor(num + 1, 1);      //Posicionar cursor
        lcd.print(key);                 //Imprime dato 
        comprobar[num + 1] = key;       //almacena el dato
      }
    }
  }
 
  if (key == '#') {                                  //condicion de verificacion
    lcd.setCursor(0, 2);      //Posicionar cursor
    lcd.print("datos escritos");                 //Imprime dato 
    Serial.println("datos escritos");                //imprime mensaje
     for(int i=0;i<=9;i++){
        lectura=EEPROM.read(i);
        lcd.setCursor(0,3);
         
        }
        lcd.print(lectura);  
  }
   lcd.setCursor(0,0);
   lcd.print("ESCRIBIR DATOS");

}

void letras(char letra) {           //metodo de conversion a letras
  switch (letra) {                  //ciclo
    case '1':                     
      contador++;                   //incrementa contador
      if (contador == 1) {          //condicion de verificacion
        letra = 'a';                //asigna el dato
      }
      else if (contador == 2) {     //condicion de verificacion
        letra = 'b';                //asigna el dato
      }
      else if (contador == 3) {     //condicion de verificacion
        letra = 'c';                //asigna el dato
        contador = 0;               //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(0,letra);
      break;

    case '2':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'd';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'e';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'f';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(1,letra);
      break;
    case '3':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'g';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'h';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'i';              //asigna el dato
        contador = 0;             //reinicia variable
      }
      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(2,letra);
      break;
    case '4':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'j';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'k';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'l';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(3,letra);
      break;
    case '5':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'm';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'n';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'ñ';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(4,letra);
      break;
    case '6':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'o';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'p';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'q';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(5,letra);
      break;
    case '7':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'r';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 's';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 't';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(6,letra);
      break;
    case '8':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'u';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'v';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'w';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(7,letra);
      break;
    case '9':
      contador++;
      if (contador == 1) {        //condicion de verificacion
        letra = 'x';              //asigna el dato
      }
      else if (contador == 2) {   //condicion de verificacion
        letra = 'y';              //asigna el dato
      }
      else if (contador == 3) {   //condicion de verificacion
        letra = 'z';              //asigna el dato
        contador = 0;             //reinicia variable
      }

      comprobar[asignar - 1] = letra; //almacena caracter
      lcd.setCursor(asignar - 1, 0);  //posiciona cursor
      lcd.print(letra);               //imprime el dato
      EEPROM.write(8,letra);
      break;
  }
}

