const int led = 13;
int       a0_val = 0, bSpeed = 0;

void setup(void)
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop(void)
{
  a0_val = analogRead(A0);
  Serial.println(a0_val);
  blinky_13(a0_val);
}

void blinky_13(int aValue)
{
    if (aValue > 400)
      bSpeed = 400;
    else
      bSpeed = (aValue < 100) ? 100 : aValue;

    digitalWrite(led, HIGH);
    delay(bSpeed);
    digitalWrite(led, LOW);
    delay(bSpeed);
}
