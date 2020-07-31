/* Пример использования обработчиков меню.
 * Использование функций-обаботчиков позволяет выполнять действия
 * при выборе пунктов меню, не покидая само меню
 */
#include <Wire.h>
#include <LiquidCrystal_I2C_Menu_Btns.h>
LiquidCrystal_I2C_Menu_Btns lcd(0x27, 20, 4);

// Пины, к которым подключены кнопки
#define pinLeft  2
#define pinRight 3
#define pinEnter 4
#define pinBack  5 // Back - необязательная кнопка


int brightness = 50;
int _delay = 10;

// Обработчики пунктов меню SetBrightness и SetDelay
// Используются для ввода значений brightness и _delay
void SetBrightness() {
  brightness = lcd.inputVal("Input brightness(%)", 0, 100, brightness, 5);
}

void SetDelay() {
  _delay = lcd.inputVal("Input delay(ms)", 0, 20, _delay);
}

// Объявим перечисление, используемое в качестве ключа пунктов меню
enum {mkBack, mkRoot, mkOptions, mkSetBrightness, mkSetDelay};

// Описание меню
// структура пункта меню: {ParentKey, Key, Caption, [Handler]}
sMenuItem menu[] = {
  {mkBack, mkRoot, "Main menu", NULL},
  {mkRoot, mkOptions, "Options", NULL},
  {mkOptions, mkSetBrightness, "SetBrightness", SetBrightness},
  {mkOptions, mkSetDelay, "SetDelay", SetDelay},
  {mkOptions, mkBack, "Back", NULL},
  {mkRoot, mkBack, "Back", NULL}
};

uint8_t menuLen = sizeof(menu) / sizeof(sMenuItem);

void setup() {
  lcd.begin();
  lcd.attachButtons(pinLeft, pinRight, pinEnter, pinBack);
}

void loop() {
  uint8_t selectedMenuItem = lcd.showMenu(menu, menuLen, 1); // Вызываем меню
  /* Реакция на выбор пунктов меню SetBrightness и SetDelay реализована
   * в функциях-обработчиках.
   * При необходимости здесь может располагаться анализ значения selectedMenuItem 
   * для пунктов, не имеющих обработчиков:
     if (selectedMenuItem == ...) {...}
  */
}
