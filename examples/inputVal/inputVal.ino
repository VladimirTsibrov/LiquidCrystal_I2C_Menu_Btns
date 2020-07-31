/* Пример использования функций inputVal и inputValAt для ввода значений. Синтаксис:
 * inputVal(title, min, max, default, [step = 1]), где 
 * title - заголовок
 * min и max - минимальное и максимальное значения для задания диапазона ввода
 * default - начальное значение
 * step - шаг приращения, по умолчанию = 1
 * 
 * inputValAt(x, y, min, max, default, step = 1), где 
 * x и y - позиция на дисплее для ввода значения
 * остальные параметры аналогичны описанным ранее для функции inputVal
 * 
 * Функция inputVal очищает дисплей перед вводом. inputValAt не очищает дисплей
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
  // Для примера запросим длину массива
  uint8_t len = lcd.inputVal("Input array len", 5, 10, 8);
  uint8_t A[len];
  uint8_t t;
  
  // Затем элементы массива
  for (uint8_t i = 0; i < len; i++) {
    lcd.printfAt(0, 0, "Input A[%d]: ", i); // Приглашение для ввода
    A[i] = lcd.inputValAt(12, 0, 0, 9, 5);  // Ввод значения
  }
  
  // Отсортируем массив
  for (uint8_t i = 0; i < len - 1; i++) {
    for (uint8_t j = i + 1; j < len; j++) {
      if(A[i] > A[j]){
        t = A[i];
        A[i] = A[j];
        A[j] = t;
      }
    }
  }
  
  // И выведем на дисплей
  lcd.clear();
  lcd.print("Sorted array:");
  lcd.setCursor(0, 1);
  for (uint8_t i = 0; i < len; i++)
    lcd.printf("%d ", A[i]);
  
  // Ожидаем нажатия кнопки для продолжения
  while (lcd.getButtonsState() != eButton);
}
