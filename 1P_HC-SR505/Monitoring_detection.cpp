int led = 13;
int pir = 7;
int pirdato;
  
void setup()
{
  	Serial.begin(9600);
    pinMode(pir, INPUT);
}

void loop()
{
  pirdato = digitalRead(pir);
  if(pirdato == HIGH) 
    {
      Serial.println("Motion detected.");
      digitalWrite(led, HIGH);
    }
  else
    {
      Serial.println(pirdato);
      digitalWrite(led, LOW);
    }
  delay(100);  
}