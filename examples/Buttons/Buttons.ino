/* Пример использования функции getButtonsState для работы с кнопками. 
 * Функция вовращает одно из следующих значений:
 * eNone, eLeft, eRight, eButton, eBack.
 * Для привязки используемых кнопками пинов вызывается функция attachButtons.
 */
#include <Wire.h>
#include <LiquidCrystal_I2C_Menu_Btns.h>
LiquidCrystal_I2C_Menu_Btns lcd(0x27, 20, 4);

// Пины, к которым подключены кнопки
#define pinLeft  2
#define pinRight 3
#define pinEnter 4
#define pinBack  5 // Back - необязательная кнопка

int x = 0;

void setup() {
  lcd.begin();
  lcd.attachButtons(pinLeft, pinRight, pinEnter, pinBack);
  lcd.printfAt(0, 0, "%d ", x);
}

void loop() {
  // Опрашиваем кнопки
  eButtonsState ButtonsState = lcd.getButtonsState();
  switch (ButtonsState) {
    case eLeft:   // Нажали влево - уменьшаем значение переменной
      x--;
      break;
    case eRight:  // Нажали вправо - увеличиваем значение переменной
      x++;
      break;
    case eButton: // Нажата кнопка Enter
      x = 0;
      break;
    case eNone:   // Нет нажатых кнопок, выходим из функции
      return;
  }
  lcd.printfAt(0, 0, "%d ", x); // Покажем новое значение x
}
