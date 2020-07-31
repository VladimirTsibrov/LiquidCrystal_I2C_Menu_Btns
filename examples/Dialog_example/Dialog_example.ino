// Пример использования меню для построения диалога
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
  sMenuItem formatConfirmation[] = { // Опишем наше меню:
    {0, 1, "Format drive C?", NULL}, // Это будет заголовок
    {1, 2, "No", NULL}, // и два пункта для выбора
    {1, 3, "Yes", NULL}
  };
  // Показываем меню и анализируем результат
  if (lcd.showMenu(formatConfirmation, 3, 1) == 3)
    lcd.print("Yes selected");
  else
    lcd.print("No selected");
  delay(2000);
}
