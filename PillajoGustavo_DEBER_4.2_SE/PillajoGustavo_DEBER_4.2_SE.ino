/* DEBER 4.2
 *  TEMA: INTERRUPCIONES 
 * NOMBRE: GUSTAVO PILLAJO
 * 
 * La modificacion que se realizo es en la interrupcion de activacion se cambio de low por rising
 * ya que si se lo dejaba en low a penas se iniciaba el sistema ya aparecia el mensaje y no podiamos 
 * iniciar el juego, ahora el funcionamiento es: iniciamos proeus en el visula terminal aparece la
 * la pantalla negra mientras no presionemos el boton de de inicio de juego y ahi recien empezara 
 * y podremos elegir el numero de veces.
 */
 const int leds[]={13,12,11,10,9,8};
 int on=0;
 int cont;
 int i;
 int j=0;
void setup() {
  for(i=0;i<6;i++){
    pinMode(leds[i],OUTPUT);
    }
    i=0;
    Serial.begin(9600);          //ativacion de serial
    attachInterrupt(0,activacion,RISING);          //pin con que comienza
    attachInterrupt(1,contador,LOW); 
}

void loop() {
  if(on==2){
    for(;i<cont;i++){
      for(j=0;j<6;j++){
        digitalWrite(leds[j],HIGH);
        delay(200);
        digitalWrite(leds[j],LOW);
        delay(200);
        }
      }
    }
}
void activacion(){
  switch(on){
    case 0:
    Serial.println("inicio del sistema");
    Serial.println("ingrese el numero de veces a jugar");
       on++;
    break;
    case 1:
        Serial.println("inicio de juego");
    on++;
    break;
    case 2:
    Serial.println("fin de juego");
    cont=0;
    on=0;
    i=0;
    break;
    }
}
void contador(){
  if(on==1){
    cont++;
    Serial.println(String("juega")+String(cont)+String("veces"));
    }
  }
