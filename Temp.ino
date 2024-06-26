#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN A5
LiquidCrystal
lcd(8,9,4,5,6,7);
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
char
temperature[]="Temp=00.0C";
char humidity[]="RH=00.0%";
void setup()
{
  lcd.begin(16,2);
  dht.begin();
}
void loop()
{
 delay(1000);
 byte RH=dht.readhumidity();
 byte Temp=dht.readtemperature();
 if(isnan(RH) || isnan(Temp))
 {
    lcd.clear();

    lcd.setCursor(5,0);
    lcd.print("Error");
    return;
 } 
 temperature[7]=Temp/10+48;
 temperature[8]=Temp%10+48;
 temperature[11]=233;
 humidity[7]=RH/10+48;
 humidity[8]=RH%10+48;
 lcd.setCursor(0,0);
 lcd.print(temperature);
 lcd.setCursor(0,1);
 lcd.print(humidity);
}
