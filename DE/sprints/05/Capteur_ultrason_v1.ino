const int ECHO    = 4;
const int TRIGGER = 3;
const int NUM_OF_READINGS = 5;

unsigned long sumDist;
unsigned long sumPulse;     // NEW: accumulates pulse durations
int nbRead;

unsigned long pulseTimeLast;   // NEW: stores the latest Echo duration (µs)

void setup()
{
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  // pinMode(LED, OUTPUT); -> LED
  Serial.begin(9600);
  sumDist  = 0;
  sumPulse = 0;
  nbRead   = 0;
}

unsigned long mesureDistance()
{
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  unsigned long pulseTime = pulseIn(ECHO, HIGH);
  pulseTimeLast = pulseTime;      // NEW: save it for display

  unsigned long distance = pulseTime / 58;
  return distance;
}

void loop()
{
  unsigned long d = mesureDistance();
  sumDist  += d;
  sumPulse += pulseTimeLast;      // NEW
  nbRead++;

  if (nbRead == NUM_OF_READINGS)
  {
    int averageDistance        = sumDist  / NUM_OF_READINGS;
    unsigned long averagePulse = sumPulse / NUM_OF_READINGS;   // NEW

    Serial.print("Distance = ");
    Serial.print(averageDistance);

   // if (averageDistance < 10)
   // {
   //   Serial.println("ALERTE");
   //   digitalWrite(LED, HIGH);
   //   delay(500);
   //   digitalWrite(LED, LOW);
   //   delay(500);
   // }
   // else if (averageDistance < 20)
   // {
   //   Serial.println("ALERTE");
   //   digitalWrite(LED, HIGH);
   // }
   // else
   // {
   //   digitalWrite(LED, LOW);
   // }

    Serial.print(" cm   Duree Echo = ");
    Serial.print(averagePulse);
    Serial.println(" us");

    sumDist  = 0;
    sumPulse = 0;
    nbRead   = 0;
  }

  delay(100);
}
