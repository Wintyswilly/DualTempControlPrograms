#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS_S1 4
#define ONE_WIRE_BUS_S2 5

OneWire oneWire_1(ONE_WIRE_BUS_S1);
OneWire oneWire_2(ONE_WIRE_BUS_S2);


DallasTemperature sensors_1(&oneWire_1);
DallasTemperature sensors_2(&oneWire_2);
 
 float Celcius_1=0;
 float Fahrenheit_1=0;
 float Celcius_2=0;
 float Fahrenheit_2=0;
void setup(void)
{
  
  Serial.begin(9600);
  sensors_1.begin();
}

void loop(void)
{ 
  sensors_1.requestTemperatures(); 
  Celcius_1=sensors_1.getTempCByIndex(0);
  Fahrenheit_1=sensors_1.toFahrenheit(Celcius_1);
  Serial.print(" C  ");
  Serial.print(Celcius_1);
  Serial.print(" F  ");
  Serial.println(Fahrenheit_1);
  delay(1000);

  if (Celcius_1 > 10)
    {
    Serial.print("Sensor 1 too hot Turn on Fan = ");  
    }
  if (Celcius_1 < 8)
    {
    Serial.print("Sensor 1 To cold Turn on heat mat = ");
    }  
   if ((Celcius_1 >= 8) && (Celcius_1 <= 10)) 
    {
    Serial.print("Sensor 1 perfect temp, turn off both = "); 
    }
  sensors_2.requestTemperatures(); 
  Celcius_2=sensors_2.getTempCByIndex(0);
  Fahrenheit_2=sensors_2.toFahrenheit(Celcius_2);
  Serial.print(" C  ");
  Serial.print(Celcius_2);
  Serial.print(" F  ");
  Serial.println(Fahrenheit_2);
  delay(1000);

  if (Celcius_2 > 10)
  {
    Serial.print("Sensor 2 too hot Turn on Fan = ");  
  }
  if (Celcius_2 < 8)
  {
    Serial.print("Sensor 2 To cold Turn on heat mat = ");
  }  
   if ((Celcius_2 >= 8) && (Celcius_2 <= 10)) 
  {
    Serial.print("Sensor 2 perfect temp, turn off both = "); 
  }
}
