// C++ code
// ir sensor

int ir = 7;
void setup()
{
  pinMode(INPUT,ir);
  Serial.begin(9600);
}

void loop()
{
  int system = digitalRead(ir);
  Serial.println(system);
  delay(500);
}