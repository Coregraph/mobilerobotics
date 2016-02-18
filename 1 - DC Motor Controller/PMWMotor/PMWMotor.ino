/* ---------------------------------------------
Control por PWM de un motor
---------------------------------------------
Programa que hace uso de un motor y la Consola serial de Arduino, tiene la posiblidad de configurar al motor
5 velocidades distintas, desde el teclado del PC puedes enviarle la velocidad deseada. Las 5 velocidades se
configuran con 5 PWM distintos. */
//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int motor=3; //Declara Pin del motor
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
  Serial.begin(9600); //Inicia la comunicacion serial Arduino-PC
}

//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{
  //Si hay algun valor en la Consola Serial
  if (Serial.available()){
    //Variable donde se guarda el caracter enviado desde teclado
    char a = Serial.read();
    // Si el caracter ingresado esta entre 0 y 5
    if (a>='0' && a<='5'){
      //Variable para escalar el valor ingresado a rango de PWM
      int velocidad = map(a,'0','5',0,255);
      //Escritura de PWM al motor
      analogWrite(motor,velocidad);
      //Mensaje para el usuario
      Serial.print("El motor esta girando a la velocidad ");
      Serial.println(a);
    }else{ // Si el caracter ingresado NO esta entre 0 y 5
      //Mensaje para el usuario
      Serial.print("Velocidad invalida");
      Serial.println(a);
    }
  }
}
//Fin programa
