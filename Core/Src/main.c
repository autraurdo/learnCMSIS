#include "stm32f3xx.h"
#include "main.h"

void delay_ms(uint16_t value)
{
  TIM2->ARR = value;                  //загрузить значение задержки
  TIM2->CNT = 0;
  TIM2->CR1 = TIM_CR1_CEN;	      // запустить таймер
  while((TIM2->SR & TIM_SR_UIF)==0){} // дождаться конца задержки
  TIM2->SR &= ~TIM_SR_UIF;	      // сбросить флаг
}

int main(){
	/*кнопка PA0*/
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER &=~ GPIO_MODER_MODER0;
//	GPIOA->MODER |= GPIO_MODER_MODER0_0; // подключаем регистр режима работы для пинов 0 порта А
	GPIOA->OTYPER &=~ GPIO_OTYPER_OT_0; // подключаем регистр "подтяжки" сигнала для пинов 0 порта А
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0_0; // подключаем регистр скорости работы сигнала для пинов 0 порта А

	/*светодиод PE8*/
	RCC->AHBENR |= RCC_AHBENR_GPIOEEN; // подать тактирование на PE8
	GPIOE->MODER &= ~GPIO_MODER_MODER8; //
	GPIOE->MODER |= GPIO_MODER_MODER8_0; // MODER6[1:0] = 01 - General purpose output mode

	GPIOE->MODER &= ~GPIO_MODER_MODER9;
	GPIOE->MODER |= GPIO_MODER_MODER9_0;

//
//	GPIOE->MODER &= ~GPIO_MODER_MODER10;
//	GPIOE->MODER |= GPIO_MODER_MODER10_0;

//
//	GPIOE->MODER &= ~GPIO_MODER_MODER11;
//	GPIOE->MODER |= GPIO_MODER_MODER11_0;

//
//	GPIOE->MODER &= ~GPIO_MODER_MODER12;
//	GPIOE->MODER |= GPIO_MODER_MODER12_0;

//
//	GPIOE->MODER &= ~GPIO_MODER_MODER13;
//	GPIOE->MODER |= GPIO_MODER_MODER13_0;

//
//	GPIOE->MODER &= ~GPIO_MODER_MODER14;
//	GPIOE->MODER |= GPIO_MODER_MODER14_0;


//	GPIOE->MODER &= ~GPIO_MODER_MODER15;
//	GPIOE->MODER |= GPIO_MODER_MODER15_0;
//	GPIOE->OTYPER &= ~GPIO_OTYPER_OT_15;
//	GPIOE->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR15;
//	GPIOE->PUPDR &= ~GPIO_PUPDR_PUPDR15;
//	GPIOE->BSRR &= ~GPIO_BSRR_BS_15;

	/*delay*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;   //подать тактирование на TIM2
	TIM2->PSC = 8000-1;               //настроить делитель для формирования миллисекунд
	TIM2->CR1 = TIM_CR1_OPM;

	while(1){
		GPIOE->BSRR |= GPIO_BSRR_BS_8; // переключить состоятние порта диода
		delay_ms(500); // задержка
		GPIOE->BSRR |= GPIO_BSRR_BR_8;
		delay_ms(500);

		if ((GPIOA->IDR & GPIO_IDR_0) != 0){
			GPIOE->BSRR |= GPIO_BSRR_BS_9;
		} else {
			GPIOE->BSRR |= GPIO_BSRR_BR_9;
		}

//		GPIOE->BSRR |= GPIO_BSRR_BS_9;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BR_9;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BS_10;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BR_10;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BS_11;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BR_11;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BS_12;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BR_12;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BS_13;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BR_13;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BS_14;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BR_14;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BS_15;
//		delay_ms(500);
//		GPIOE->BSRR |= GPIO_BSRR_BR_15;
//		delay_ms(500);
	}
}
