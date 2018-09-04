/*  globales  */
int g_testVar = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  g_testVar = analogRead(A0);
  g_testVar = map(g_testVar, 0, 1023, 0, 180);
  Serial.print("Val: ");
  Serial.println(g_testVar);
}
