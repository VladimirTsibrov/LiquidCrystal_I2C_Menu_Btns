/* Пример использования функции selectVal для выбора значения. Синтаксис:
 * selectVal(title, list, count, show_selected, preselected), где
 * title - заголовок
 * list - массив значений для выбора
 * count - количество элементов в массиве
 * show_selected - флаг отображения указателя на выбранном элементе
 * preselected - индекс выбранного по умолчанию элемента
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

int index = 0;

void setup() {
  lcd.begin();
  lcd.attachButtons(pinLeft, pinRight, pinEnter, pinBack);
}

void loop() {
  String list[] = {"Europa+", "Record", "DFM", "Retro FM", "Energy"};
  index = lcd.selectVal("Select station", list, 5, true, index);
  lcd.printf("%s selected", list[index].c_str());
  while (lcd.getButtonsState() == eNone);
}
