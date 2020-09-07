/* Пример использования функции inputStrVal для маскированного ввода. Синтаксис:
 * inputStrVal(title, buffer, len, availSymbols), где
 * title - заголовок
 * buffer - указатель на массив char для вводимых символов
 * len - длина вводимого значения
 * availSymbols - массив символов, доступных для ввода и редактирования
 */
 
#include <Wire.h>
#include <LiquidCrystal_I2C_Menu_Btns.h>
LiquidCrystal_I2C_Menu_Btns lcd(0x27, 20, 4);
#define getEncoderState getButtonsState

// Пины, к которым подключены кнопки
#define pinLeft  2
#define pinRight 3
#define pinEnter 4
#define pinBack  5 // Back - необязательная кнопка

char ip[] = "192.168.001.001"; // Массив символов с начальным значением/маской

void setup() {
  lcd.begin();
  lcd.attachButtons(pinLeft, pinRight, pinEnter, pinBack);
}

void loop() {
  if (lcd.inputStrVal("Input IP", ip, 15, "0123456789")){
    lcd.print("You entered:");
    lcd.printAt(0, 1, ip);
  }
  else
    lcd.print("Input canceled");
  while (lcd.getButtonsState() == eNone);
}
