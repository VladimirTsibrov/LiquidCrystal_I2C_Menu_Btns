/* Пример использования функции attachIdleFunc для привязки функции,
 * выполняемой при бездействии
 */

#include <Wire.h>
#include <LiquidCrystal_I2C_Menu_Btns.h>
LiquidCrystal_I2C_Menu_Btns lcd(0x27, 20, 4);

// Пины, к которым подключены кнопки
#define pinLeft  2
#define pinRight 3
#define pinEnter 4
#define pinBack  5 // Back - необязательная кнопка

unsigned long tm = 0;
bool ledState = false;

// Данная функции будет вызываться из библиотеки при бездействии
void myIdleFunc() {
  if (millis() - tm >= 500) {
    // Включаем и выключаем встроенный светодиод на Ардуино
    tm = millis();
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
}

void setup() {
  lcd.begin();
  lcd.attachButtons(pinLeft, pinRight, pinEnter, pinBack);
  lcd.attachIdleFunc(myIdleFunc);
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.print("Press the button");
}

int x = 0;

void loop() {
  myIdleFunc();
  if (lcd.getButtonsState() != eNone) {
    // Для проверки вызовем любую функцию библиотеки,
    // которая ожидает действий от пользователя:
    x = lcd.inputVal("Input some val", 0, 100, x);
    lcd.printMultiline("Some text here");
    lcd.clear();
    lcd.print("Press the button");
  }
}
