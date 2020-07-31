/* Несколько примеров использования функций ввода inputVal и 
 * inputValBitwise для ввода чисел
 */
   
#include <Wire.h>
#include <LiquidCrystal_I2C_Menu_Btns.h>
LiquidCrystal_I2C_Menu_Btns lcd(0x27, 20, 4);

// Пины, к которым подключены кнопки
#define pinLeft  2
#define pinRight 3
#define pinEnter 4
#define pinBack  5 // Back - необязательная кнопка

void setup() {
  lcd.begin();
  lcd.attachButtons(pinLeft, pinRight, pinEnter, pinBack);
}

void loop() {
  double x = 0;
  long y = 0;

  x = lcd.inputVal("Input value", 0.0, 10.0, x, 0.25); // Ввод double от 0 до 10 с шагом 0.25
  x = lcd.inputVal<double>("Input value", 0, 10, x, 0.25); // Аналогично предыдущему вызову, но тип переменных задан явно - <double>
  lcd.inputValBitwise("Input value", x, 4, 2, 0); // Беззнаковый ввод в формате XX.XX
  lcd.inputValBitwise("Input value", x, 4, 2, 1); // Ввод числа со знаком в формате [-]XX.XX

  y = lcd.inputVal <long> ("Input value", 0, 10000, y, 100); // Ввод значения long. Тип переменной указан явно, чотбы избежать ошибок при компиляции
  lcd.inputValBitwise("Input value", y, 4); // Беззнаковый ввод целого числа длиной до 4 цифр
  lcd.inputValBitwise("Input value", y, 4, 0, 1); // Ввод целого числа длиной до 4 цифр
}
