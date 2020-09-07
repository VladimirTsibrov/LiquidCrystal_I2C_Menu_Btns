/* Использование функции inputValBitwise для поразрядного ввода чисел. Синтаксис:
 * inputValBitwise(title, value, precision, [scale = 0], [signed = 0]), где
 * title - заголовок
 * value - ссылка на переменную, в которой будет сохранено введенное значение
 * precision - общее количество цифр (до и после запятой)
 * scale - количество цифр после запятой, по умолчанию 0
 * signed - признак ввода со знаком. По умолчанию 0 - беззнаковый ввод
 */
#include <Wire.h>
#include <LiquidCrystal_I2C_Menu_Btns.h>
LiquidCrystal_I2C_Menu_Btns lcd(0x27, 20, 4);

// Пины, к которым подключены кнопки
#define pinLeft  2
#define pinRight 3
#define pinEnter 4
#define pinBack  5 // Back - необязательная кнопка

double val = 0;

void setup() {
  lcd.begin();
  lcd.attachButtons(pinLeft, pinRight, pinEnter, pinBack);
}

void loop() {
  // Ввод 5-значного числа со знаком, 2 цифры после запятой:
  if (lcd.inputValBitwise("Input value", val, 5, 2, 1)) {
    lcd.print("You entered: ");
    lcd.print(val);
  }
  else
    lcd.print("Input canceled");
  while (lcd.getButtonsState() == eNone);
}
