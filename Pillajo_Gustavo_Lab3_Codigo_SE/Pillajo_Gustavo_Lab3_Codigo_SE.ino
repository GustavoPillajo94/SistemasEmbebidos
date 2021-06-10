/*
LABORATORIO 3
SISTEMAS EMBEBIDOS
NOMBRE: GUSTAVO PILLAJO
*/


int arriba = 4;   //variable de pin de entrada
int abajo = 5; //variable de pin de entrada
int izquierda = 6; //variable de pin de entrada
int derecha = 7;  //variable de pin de entrada
int seleccionar = 9; //variable de pin de entrada
int inicio = 8;  //variable de pin de entrada
void setup() {
  Serial.begin(9600); //inicia cx serial
  pinMode(arriba, INPUT); //configura pin
  pinMode(abajo, INPUT); //configura pin
  pinMode(izquierda, INPUT); //configura pin
  pinMode(derecha, INPUT);  //configura pin
  pinMode(seleccionar, INPUT); //configura pin
  pinMode(inicio, INPUT);  //configura pin
}

void loop() {
  if (digitalRead(arriba) == LOW) {    //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("a");  //envia dato por CX Serial
  }
  if (digitalRead(abajo) == LOW) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("b");  //envia dato por CX Serial
  }
  if (digitalRead(izquierda) == LOW) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("i");  //envia dato por CX Serial
  }
   if (digitalRead(derecha) == LOW) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("d");  //envia dato por CX Serial
  }
  if (digitalRead(inicio) == LOW) { //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("s");  //envia dato por CX Serial
  }
    if (digitalRead(seleccionar) == LOW) {  //condicion de activacion
    delay(250); //detiene la lectura
    Serial.write("m");  //envia dato por CX Serial
  }
}
