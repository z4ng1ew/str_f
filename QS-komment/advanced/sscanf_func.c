#include "advanced.h"

void str_to_int(long long int *val, char **str, int shirina, int *err) {
  int minus = 0;

  if (**str == '-') {
    minus = 1;
    (*str)++;
    shirina--;
  } else if (**str == '+') {
    (*str)++;
    shirina--;
  }
  if (shirina < 1) shirina = MD_10;

  while (s21_isdigit(**str, 10)) {
    long long int digit = **str - '0';
    *val = *val * 10 + digit;
    (*str)++;
    if (shirina-- < 0) {
      *err = 1;
      break;
    }
  }
  if (!*err) {
    *val = minus ? (*val) * -1 : *val;
  }
}

void change_length_int(long long int *val, va_list args, char dlina) {
  if (dlina == 'h') {
    *(va_arg(args, short *)) = (short)*val;
  } else if (dlina == 'l') {
    *(va_arg(args, long *)) = (long)*val;
  } else if (dlina == 'L') {
    *(va_arg(args, long long *)) = (long long)*val;
  } else {
    *(va_arg(args, int *)) = (int)*val;
  }
}

s21_size_t convert_to_digit(char c, int base) {
  s21_size_t res = 0;
  if (c >= '0' && c <= '9') {
    res = c - '0';
  } else if (base > 10 && c >= 'A' && c <= 'A' + base - 11) {
    res = c - 'A' + 10;
  } else if (base > 10 && c >= 'a' && c <= 'a' + base - 11) {
    res = c - 'a' + 10;
  }
  return res;
}

int get_max_digit(int base) {
  int shirina = 0;
  switch (base) {
    case 10:
      shirina = MD_10;
      break;
    case 16:
      shirina = MD_16;
      break;
    case 8:
      shirina = MD_8;
      break;
    default:
      shirina = MD_10;
      break;
  }
  return shirina;
}

void str_to_uint(unsigned long long *val, char **str, int shirina, int *err,
                 int base) {
  if (!shirina) shirina = get_max_digit(base);

  while (s21_isdigit(**str, base)) {
    unsigned long long digit = convert_to_digit(**str, base);
    *val = *val * base + digit;
    (*str)++;
    if (shirina-- < 0) {
      *err = 1;
      break;
    }
  }
}
void change_length_uint(unsigned long long *val, va_list args, char dlina) {
  if (dlina == 'h') {
    *(va_arg(args, unsigned short *)) = (unsigned short)*val;
  } else if (dlina == 'l') {
    *(va_arg(args, unsigned long *)) = (unsigned long)*val;
  } else if (dlina == 'L') {
    *(va_arg(args, unsigned long long *)) = (unsigned long long)*val;
  } else {
    *(va_arg(args, unsigned int *)) = (unsigned int)*val;
  }
}

void get_mantissa(long double *val, char **str, int *shirina, int *err,
                  const char specifikator, int *found_dot, int *found_eE) {
  while (**str != ' ') {
    if (s21_isdigit(**str, 10)) {
      int digit = **str - '0';
      if (*val > LDBL_MAX / 10) {
        *err = 1;
        break;
      }
      *val = *val * 10 + digit;
    } else if (**str == '.') {
      *found_dot = 1;
      (*str)++;
      break;
    } else if (s21_strrchr("eE", **str) != s21_NULL &&
               s21_strrchr("eEgG", specifikator) != s21_NULL) {
      *found_eE = 1;
      (*str)++;
      (*shirina)--;
      break;
    }
    (*str)++;
  }
}
void get_fraction(long double *val, char **str, const char specifikator,
                  int *shirina, int *found_eE) {
  long double fraction = 1;
  fraction /= 10;
  while (s21_isdigit(**str, 10)) {
    int digit = **str - '0';
    *val += (long double)digit * fraction;
    fraction /= 10;
    (*str)++;
    (*shirina)--;
    if (s21_strrchr("eE", **str) != s21_NULL &&
        s21_strrchr("eEgG", specifikator) != s21_NULL) {
      *found_eE = 1;
      (*str)++;
      (*shirina)--;
      break;
    }
  }
}

void str_to_float(long double *val, char **str, const flags full_flags,
                  int *err) {
  int minus = 0;
  int found_dot = 0;
  int found_eE = 0;
  int shirina = full_flags.shirina;
  char specifikator = full_flags.specifikator;

  if (**str == '-') {
    minus = 1;
    (*str)++;
    shirina--;
  } else if (**str == '+') {
    (*str)++;
    shirina--;
  }

  if (shirina < 1) shirina = LDBL_DIG;

  get_mantissa(val, str, &shirina, err, specifikator, &found_dot, &found_eE);

  if (found_dot) {
    get_fraction(val, str, specifikator, &shirina, &found_eE);
  }

  if (!*err && found_eE) {
    long long int val_exp = 0;
    str_to_int(&val_exp, str, shirina, err);
    *val *= pow(10, val_exp);
  }

  if (!*err) {
    *val = minus ? (*val) * -1 : *val;
  }
}

void change_length_float(long double *val, va_list args, char dlina) {
  if (dlina == 'h') {
    *(va_arg(args, float *)) = (float)*val;
  } else if (dlina == 'l') {
    *(va_arg(args, double *)) = (double)*val;
  } else if (dlina == 'L') {
    *(va_arg(args, long double *)) = (long double)*val;
  } else {
    *(va_arg(args, float *)) = (float)*val;
  }
}

unsigned long int str_to_ptr(char **str, int *err) {
  if (**str == '0' && *(*str + 1) == 'x') {
    *str += 2;
  } else {
    *err = 1;
  }
  unsigned long long tmp = 0;
  str_to_uint(&tmp, str, 0, err, 16);

  return tmp;
}

void str_to_str(char *val, char **str, int shirina, int one_char) {
  if (!shirina && one_char)
    shirina = 1;
  else if (!shirina && !one_char)
    shirina = (int)MAX_ARRAY_COUNT;

  while (shirina--) {
    *val = **str;
    val++;
    (*str)++;
    if (!one_char && **str == ' ') break;
  }
}

void read_text_with_flags(const flags full_flags, char **str, va_list args,
                          int *counter, char *p_start_str) {
  int err = 0;
  switch (full_flags.specifikator) {
    case 'c': {
      char *val_c = va_arg(args, char *);
      str_to_str(val_c, str, full_flags.shirina, 1);
      break;
    }
    case 'd':
    case 'i': {
      long long int val = 0;
      str_to_int(&val, str, full_flags.shirina, &err);
      change_length_int(&val, args, full_flags.dlina);
      break;
    }
    case 's': {
      char *val_s = va_arg(args, char *);
      str_to_str(val_s, str, full_flags.shirina, 0);
      break;
    }
    case 'u': {
      unsigned long long val_u = 0;
      str_to_uint(&val_u, str, full_flags.shirina, &err, 10);
      change_length_uint(&val_u, args, full_flags.dlina);
      break;
    }
    case '%':
      (*str)++;
      break;
    case 'f':
    case 'g':
    case 'G':
    case 'e':
    case 'E': {
      long double val_f = 0;
      str_to_float(&val_f, str, full_flags, &err);
      change_length_float(&val_f, args, full_flags.dlina);
      break;
    }
    case 'x':
    case 'X': {
      unsigned long long val_x = 0;
      str_to_uint(&val_x, str, full_flags.shirina, &err, 16);
      change_length_uint(&val_x, args, full_flags.dlina);
      break;
    }
    case 'o': {
      unsigned long long val_o = 0;
      str_to_uint(&val_o, str, full_flags.shirina, &err, 8);
      change_length_uint(&val_o, args, full_flags.dlina);
      break;
    }
    case 'p': {
      *(va_arg(args, unsigned long *)) = str_to_ptr(str, &err);
      break;
    }
    case 'n': {
      int *num = va_arg(args, int *);
      int length = (int)(*str - p_start_str);
      *(num) = length;
      err = 1;
      break;
    }
  }
  if (!err) (*counter)++;
}
