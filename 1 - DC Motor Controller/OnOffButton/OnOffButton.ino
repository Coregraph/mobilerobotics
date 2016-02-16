/*
  DC Motor controller
  ON/OFF button controller
*/

int IN_PULS = 7;
int OUT_MTR = 3;

void setup() {
  pinMode(IN_PULS, INPUT);
  pinMode(OUT_MTR, OUTPUT);   
}

void loop() {
  // put your main code here, to run repeatedly:
  if( digitalRead(IN_PULS) ){
    digitalWrite( OUT_MTR, HIGH);
  }else{
    digitalWrite( OUT_MTR, LOW);
  }
}
