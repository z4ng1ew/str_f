#include "advanced.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int counter = 0;  // счетчик для возврата функции
  const char *p_start_str = str;
  const char *temp_str = str;

  while (*format != '\0') {
    flags full_flags = {0};
    if (*format != '%') {
      format++;
      str++;
    } else {
      format = get_full_flags(format, &full_flags, args);
      read_text_with_flags(full_flags, (char **)&temp_str, args, &counter, (char *)p_start_str);  // Изменение здесь
    }
  }

  va_end(args);
  return counter;  // вернем значение количества символов в строке
}