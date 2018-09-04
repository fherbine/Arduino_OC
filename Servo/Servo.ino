#include <Servo.h>

/*  class     */
Servo M1;
/*  globales  */
int  g_potVal = 0;
short  g_pwmServo = 3;
int g_period = 20000;


void servoMotorSetAngle(int rotation)
{
  rotation = map(rotation, 0, 180, 500, 2500);

  digitalWrite(g_pwmServo, LOW);

  for (int t = 0; t < 300; t++)
  {
    digitalWrite(g_pwmServo, HIGH);
    delayMicroseconds(rotation);
    digitalWrite(g_pwmServo, LOW);
    delayMicroseconds(g_period - rotation);
  }
}

void setup()
{
  pinMode(g_pwmServo, OUTPUT);
  digitalWrite(g_pwmServo, LOW);
  M1.attach(8);
  Serial.begin(9600);
}

void loop()
{
  g_potVal = analogRead(A0);
  g_potVal = map(g_potVal, 0, 1023, 0, 180);
  Serial.print("Val: ");
  Serial.println(g_potVal);
  //servoMotorSetAngle(g_potVal);
  M1.write(g_potVal);
  delay(1000);
}
