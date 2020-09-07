/* Пример использования функции selectVal для выбора значения. Синтаксис:
 * selectVal(title, list, count, show_selected, preselected), где
 * title - заголовок
 * list - массив значений для выбора
 * count - количество элементов в массиве
 * show_selected - флаг отображения указателя на выбранном элементе
 * preselected - индекс выбранного по умолчанию элемента. По умолчанию -1 - ничего не выбрано
 * Функция возвращает индекс выбранного значения
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
  int index;
  String list[] = {"Off", "On"};
  index = lcd.selectVal("Turn backlight", list, 2, false);
  lcd.setBacklight(index);
  lcd.printf("Backlight turned %s", list[index].c_str());
  while (lcd.getButtonsState() == eNone);
}
