#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define Sensor 13

boolean estado;
TinyGPS gps;
SoftwareSerial serialgps(4,3);

void setup() {
  serialgps.begin(9600);
  Serial.begin(9600);
  
  pinMode(Sensor, INPUT);
  
  estado = false;
}

void loop() {
  if (!digitalRead(Sensor) && !estado) {
      delay(500);
      char comand = Serial.read();
      gps_data();
      estado = true;
    }
  if (digitalRead(Sensor)) {
      estado = false;
    }
  
}

void gps_data() {
  smartdelay(500);
  
  float flat, flon;
  unsigned long age;
  int year;
  byte month, day, hour, minute, second, hundredths;
  
  gps.f_get_position(&flat, &flon, &age);
  
  Serial.print("Lat/Lon:");
  if (flat == TinyGPS::GPS_INVALID_F_ANGLE) {
    Serial.print("Invalid");
  } else {
    Serial.print(flat,2);
    smartdelay(0);
  }
  Serial.print("/");
  
  if (flon == TinyGPS::GPS_INVALID_F_ANGLE) {
    Serial.print("Invalid");
  } else {
    Serial.print(flon,2);
    smartdelay(0);
  }
  Serial.print("   TIME: ");
  
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  
  if (age == TinyGPS::GPS_INVALID_AGE) {
    Serial.println("UNKNOWN");
  } else {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d %02d:%02d:%02d ", day, month, year, hour, minute, second);
    Serial.println(sz);
    smartdelay(0);
  }
  
}

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (serialgps.available())
      gps.encode(serialgps.read());
  } while (millis() - start < ms);
}
