//Пример для подключения дисплея по шине I2C 
// 
//Тип подключения дисплея: 1 - по шине I2C, 2 - десятиконтактное. Обязательно указывать ДО подключения библиотеки 
//Если этого не сделать, при компиляции возникнет ошибка: "LCD type connect has not been declared" 
#define _LCD_TYPE 1 
#include <LCD_1602_RUS_ALL.h> 

 
LCD_1602_RUS lcd(0x27, 16, 2);

int time1 = 400;
int time2 = 100;
int time0 = 1000;
int rand1 = random(10, 120);
int rand2 = analogRead(0);
int moduleWater = analogRead(A0);
 
void setup() { 
  lcd.init(); //Инициализация LCD (по умолчанию для ESP8266: 4 - SDA, 5 - SCL) 
  Serial.begin(9600);
  Serial.print(rand1);
  pinMode(A0, INPUT);
   
  // Печать сообщения на LCD 

  lcd.backlight(); 
  lcd.setCursor(0, 0); 
  lcd.print("Arduino");
  delay(500);
  lcd.setCursor(0, 0); 
  lcd.print("Загруска"); 
  delay(5000);
  lcd.setCursor(0, 0);
  lcd.print("  Проверка ");
  pinMode(A0, INPUT);
} 
 
void loop() { 
  if(analogRead(A0)) {
    lcd.clear();
    lcd.print("water вода");
    delay(1000);
    lcd.clear();
    loop();
  }
}