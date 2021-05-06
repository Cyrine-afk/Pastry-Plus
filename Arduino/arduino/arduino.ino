int capteur = 8;

void setup() {
  // put your setup code here, to run once:
pinMode(capteur,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(capteur)==HIGH)
{
  Serial.println("1");
  delay(1000);
  
 }
 else 
 {Serial.println("0");}
 delay(1000);
}
