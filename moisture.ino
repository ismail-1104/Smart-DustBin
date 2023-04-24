// C++ code
// moisture sensor

int moisture = 13;
void setup()
{
  pinMode(INPUT,moisture);
  Serial.begin(9600);
}

void loop()
{
  int system = digitalRead(moisture);
  Serial.println(system);
  delay(500);
}