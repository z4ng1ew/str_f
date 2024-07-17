#include "advanced.h"

int s21_sscanf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int counter = 0;  // счетчик для возврата функции
  char *p_start_str = str;
  while (*format != '\0') {
    flags full_flags = {0};
    if (*format != '%') {
      format++;
      str++;
    } else {
      format = get_full_flags(format, &full_flags, args);
      read_text_with_flags(full_flags, &str, args, &counter, p_start_str);
    }
  }

  va_end(args);
  return counter;  // вернем значение количества символов в строке
}