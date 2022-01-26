int btn  = 7;

void setup() {
  //boton
   pinMode(btn, OUTPUT);
  //luces
  for(int led = 11 ; led  <= 13 ;  led++){
    pinMode(led, OUTPUT);
  }

  //serial
  Serial.begin(9600);

}
void activar(int luz){
   for(int led = 11 ; led  <= 13 ;  led++){
      if(led == luz){
        digitalWrite(led, HIGH);
       
        }else{
          digitalWrite(led, LOW);
          }
  }
}
void encender (){
  Serial.println("");
  Serial.println("------------------------------");
  Serial.println("led rojo encendido");
  activar(13);
  delay(1000);
  activar(12);
  Serial.println("led amarillo encendido");
  delay(600);
  activar(11);
  Serial.println("led verde encendido");
  delay(1000);
   Serial.println("------------------------------");
   Serial.println("");
}

void apagar(){
  activar(15);
  }


void loop() {
  int isPulsado = digitalRead(btn);
  
  if(isPulsado){ 
     
    if (Serial.available()){
        Serial.println("");
        Serial.println("------------------------------");
       
          String text = Serial.readString();
          Serial.println("presionado");
          if(text =="encender"){
            encender ();
             Serial.println("ciclo terminado");
             Serial.println("todos fueron encendidos");
             Serial.println("");
            
            }

            if(text =="apagar"){
            apagar();
            Serial.println("");
             Serial.println("todos fueron apagados");
             Serial.println("");
            
            }
      }
  
  }

}
