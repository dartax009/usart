#ifndef F_USRT_H
#define F_USRT_H

#include <stdint.h>


/**
 * @brief Инициализация USART.
 * Реализация для МК на 16МГц.
 */
void init_usart ();

/**
 * @brief Отправка по USART.
 *
 * @param mas   [in] - указатель на массив данных
 * @param n     [in] - размер отправляемых данных
 */
void write_usart (char * mas, uint16_t n);

/**
 * @brief Чтение по USART
 *
 * @param mas   [out] - указатель куда будут записаны данные
 * @param n     [in] - размер принимаемых данных
 */
void read_usart (void *mas, uint16_t n);


#endif