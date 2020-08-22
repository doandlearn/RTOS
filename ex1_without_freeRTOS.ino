void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8)==0)
  {
    while(digitalRead(8) == 0);
    digitalWrite(13,LOW); //turn OFF LED
  }
  else digitalWrite(13,HIGH);
 
  Serial.println("PRINTLN"); 

  delay(1000);

}
