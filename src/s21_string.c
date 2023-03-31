#include "s21_string.h"

#if defined(__APPLE__)
#define MAX 106
#define UNKNOWN "Unknown error: "
static const char *errors_array[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};

#elif defined(__linux__)
#define MAX 133
#define UNKNOWN "Unknown error "

static const char *errors_array[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#endif

s21_size_t for_rev(const char *str1, const char *str2, s21_size_t len,
                   s21_size_t str1_len, s21_size_t str2_len);
char for_insert(char *pointer, const char *src, const char *str,
                s21_size_t start_index, s21_size_t len_src, s21_size_t len_str);
char for1(char *index, char *str, const char *delim);

char *s21_strerror(int errnum) {
  static char res[128] = {'\0'};

  if (errnum < 0 || errnum > MAX) {
    s21_sprintf(res, "%s%d", UNKNOWN, errnum);

    int ernnum_len = integer_length(errnum);
    int res_len = s21_strlen(UNKNOWN);

    res[ernnum_len + res_len] = '\0';
  } else {
    s21_strcpy(res, ((char *)errors_array[errnum]));
  }

  return res;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t lenght = 0;
  for (s21_size_t i = 0; str[i]; i++) {
    lenght++;
  }
  return lenght;
}

int s21_strcmp(const char *str1, const char *str2) {
  s21_size_t i = 0;
  int diff = 0;
  while (str1[i] != '\0' || str2[i] != '\0') {
    diff = str1[i] - str2[i];
    if (diff != 0) {
      break;
    }
    i++;
  }
  return diff;
}

char *s21_strcpy(char *dest, const char *src) {
  char *ret = dest;
  while (*src != '\0') {
    *dest = *src;
    ++dest;
    ++src;
  }
  *dest = *src;
  return ret;
}

char *s21_strcat(char *dest, const char *src) {
  char *ret = dest;

  while (*ret) {
    ret++;
  }
  while (*src != '\0') {
    *ret++ = *src++;
  }
  return dest;
}
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ret = dest;
  while (*ret) {
    ret++;
  }
  s21_size_t len_src = s21_strlen(src);
  s21_size_t i = 0;
  while (i < n) {
    if (i == len_src) {
      break;
    }
    *ret++ = src[i];
    i++;
  }
  *ret = '\0';
  return dest;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  int flag = 0;
  for (i = 0; i < n; i++) {
    if (*((char *)str + i) == c) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    str = S21_NULL;
  } else {
    str = (char *)str + i;
  }
  return (char *)str;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  const unsigned char *char1 = str1;
  const unsigned char *char2 = str2;
  if (str1 == str2) {
    res = 0;
  } else {
    while (n > 0) {
      n--;
      res = *char1 - *char2;
      char1++;
      char2++;
      if (res != 0) {
        break;
      }
    }
  }

  return res;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *ret = dest;
  const unsigned char *sr = src;
  unsigned char arr[n];
  s21_size_t i = 0;
  while (i < n) {
    arr[i] = sr[i];

    i++;
  }
  i = 0;
  while (i < n) {
    ret[i] = arr[i];
    i++;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  char *sr = str;
  while (i < n) {
    sr[i] = c;
    i++;
  }
  return str;
}

char *s21_strchr(const char *str, int c) {
  char *sr = S21_NULL;
  s21_size_t i = 0;
  s21_size_t len_str = s21_strlen(str);
  while (i <= len_str) {
    if (str[i] == c) {
      sr = (char *)&str[i];
      break;
    }
    i++;
  }
  return sr;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  const char *char1 = str1;
  const char *char2 = str2;
  if (str1 == str2) {
    res = 0;
  } else {
    while (n > 0) {
      n--;
      res = *char1 - *char2;
      char1++;
      char2++;
      if (res != 0) {
        break;
      }
    }
  }
  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ret = dest;
  s21_size_t len_src = s21_strlen(src);
  s21_size_t i = 0;
  while (i < n) {
    if (i >= len_src) {
      ret[i] = '\0';
    } else {
      ret[i] = src[i];
    }
    i++;
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  if ((str1 != S21_NULL) && (str2 != S21_NULL)) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) != S21_NULL) {
        break;
      } else {
        str1++;
        i++;
      }
    }
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = S21_NULL;
  if ((str1 != S21_NULL) && (str2 != S21_NULL)) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) != S21_NULL) {
        res = (char *)str1;
        break;
      } else {
        str1++;
      }
    }
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *sr = S21_NULL;

  s21_size_t len_str = s21_strlen(str);
  s21_size_t i = len_str;
  while (i != 0) {
    if (str[i] == c) {
      sr = (char *)&str[i];
      break;
    }
    i--;
  }
  return sr;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *ch1 = dest;
  const unsigned char *ch2 = src;
  for (s21_size_t i = 0; i < n; i++) {
    ch1[i] = ch2[i];
  }
  return dest;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  if ((str1 != S21_NULL) && (str2 != S21_NULL)) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) == S21_NULL) {
        break;
      } else {
        str1++;
        i++;
      }
    }
  }
  return i;
}
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  s21_size_t len_n = s21_strlen(needle);
  if (len_n == 0) {
    res = (char *)haystack;
  }
  while (*haystack != '\0') {
    if ((*haystack == *needle) && s21_strncmp(haystack, needle, len_n) == 0) {
      res = (char *)haystack;
      break;
    }
    haystack++;
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *index = S21_NULL;
  if (str != S21_NULL) {
    str += s21_strspn(str, delim);
    index = str;
  } else {
    index += s21_strspn(index, delim);
    str = index;
  }
  if (index != S21_NULL) {
    if (*index != '\0') {
      while (*index != '\0') {
        for1(index, str, delim);

        if (*index == '\0') {
          if (*str == '\0') {
            str = S21_NULL;
          }
          index++;
          break;
        }
        index++;
      }
    } else {
      str = S21_NULL;
    }
  } else {
    str = S21_NULL;
  }
  return str;
}
char for1(char *index, char *str, const char *delim) {
  char ind = *index;
  for (int i = 0; delim[i] != '\0'; i++) {
    if (*index == delim[i]) {
      if (index == str) {
        index++;
        str++;
      } else {
        *index = '\0';
        break;
      }
    }
  }
  return ind;
}
// bonus

void *s21_to_upper(const char *str) {
  char *pointer = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);
    pointer = calloc((len + 1), sizeof(char));
    if (pointer != S21_NULL) {
      for (s21_size_t i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          pointer[i] = (char)(str[i] - 32);
        } else {
          pointer[i] = (char)(str[i]);
        }
      }
    }
  }
  return pointer;
}

void *s21_to_lower(const char *str) {
  char *pointer = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str);
    pointer = calloc((len + 1), sizeof(char));
    if (pointer != S21_NULL) {
      for (s21_size_t i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          pointer[i] = (char)(str[i] + 32);
        } else {
          pointer[i] = (char)(str[i]);
        }
      }
    }
  }
  return pointer;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *pointer = S21_NULL;
  if (src != S21_NULL) {
    if (str != S21_NULL) {
      s21_size_t len_src = s21_strlen(src);
      s21_size_t len_str = s21_strlen(str);
      s21_size_t len = len_src + len_str;
      if (start_index <= len_src) {
        pointer = calloc((len + 1), sizeof(char));
        for_insert(pointer, src, str, start_index, len_src, len_str);
      }
    }
  }
  return pointer;
}

char for_insert(char *pointer, const char *src, const char *str,
                s21_size_t start_index, s21_size_t len_src,
                s21_size_t len_str) {
  char poin = *pointer;

  if (pointer != S21_NULL) {
    for (s21_size_t i = 0; i < start_index; i++) {
      pointer[i] = src[i];
    }
    for (s21_size_t i = 0; i < len_str; i++) {
      pointer[i + start_index] = str[i];
    }
    for (s21_size_t i = start_index; i < len_src; i++) {
      pointer[i + len_str] = src[i];
    }
  }
  return poin;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *pointer = S21_NULL;
  if (src != S21_NULL) {
    s21_size_t len_src = s21_strlen(src);

    if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) {
      trim_chars = "\n\t\v\f\r";
    }
    s21_size_t start = s21_strspn(src, trim_chars);
    s21_size_t end = s21_rev_strspn(src, trim_chars);
    s21_size_t new = len_src - start - end;
    if (len_src != start) {
      pointer = calloc(new + 1, sizeof(char));
      if (pointer != S21_NULL) {
        for (s21_size_t i = 0; i < new; i++) {
          pointer[i] = src[i + start];
        }
      }
    } else {
      pointer = calloc(1, sizeof(char));
    }
  }
  return pointer;
}

s21_size_t s21_rev_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0L;
  if ((str1 != NULL) && (str2 != NULL)) {
    s21_size_t str1_len = s21_strlen(str1);
    s21_size_t str2_len = s21_strlen(str2);
    len = for_rev(str1, str2, len, str1_len, str2_len);
  }
  return len;
}

s21_size_t for_rev(const char *str1, const char *str2, s21_size_t len,
                   s21_size_t str1_len, s21_size_t str2_len) {
  if (str1_len != 0) {
    for (s21_size_t i = str1_len - 1;; i--) {
      int flag = 0;
      for (s21_size_t j = 0; j < str2_len; j++) {
        if (str1[i] == str2[j]) {
          flag = 1;
          break;
        }
      }
      if (flag != 0) {
        len++;
      } else {
        break;
      }
    }
  }
  return len;
}
