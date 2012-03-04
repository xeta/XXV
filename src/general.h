/* Набор прототипов функций и общих констатнт
 */

#ifndef GENERAL_H_
#define GENERAL_H_

// Размер типа данных int
#define _INT sizeof(int)

// Функция сравнения
typedef int (*__comporator)(__const void *, __const void *);
// Рассматривается в контексте приведение типа данных в bool
typedef bool(*__is_true)(const void* pt);
// Вывод значения в консоль
typedef void(*__printer)(const void* pt);

/* Byte-wise swap two items of size SIZE. */
#define SWAP(a, b, size)						      \
  do									      \
    {									      \
      register size_t __size = (size);					      \
      register char *__a = (a), *__b = (b);				      \
      do								      \
	{								      \
	  char __tmp = *__a;						      \
	  *__a++ = *__b;						      \
	  *__b++ = __tmp;						      \
	} while (--__size > 0);						      \
    } while (0)

#endif
