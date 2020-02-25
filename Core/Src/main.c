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

int i=0;

int main(){
//	__enable_irq ();
	NVIC_EnableIRQ (EXTI0_IRQn);
	/*кнопка PA0*/
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER &=~ GPIO_MODER_MODER0;
	GPIOA->OTYPER &=~ GPIO_OTYPER_OT_0;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0_0;

	/*светодиод PE8*/
	RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
	GPIOE->MODER &= ~GPIO_MODER_MODER8;
	GPIOE->MODER |= GPIO_MODER_MODER8_0;

	GPIOE->MODER &= ~GPIO_MODER_MODER9;
	GPIOE->MODER |= GPIO_MODER_MODER9_0;

	GPIOE->MODER &= ~GPIO_MODER_MODER10;
	GPIOE->MODER |= GPIO_MODER_MODER10_0;

	GPIOE->MODER &= ~GPIO_MODER_MODER11;
	GPIOE->MODER |= GPIO_MODER_MODER11_0;

	GPIOE->MODER &= ~GPIO_MODER_MODER12;
	GPIOE->MODER |= GPIO_MODER_MODER12_0;

	/*delay*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = 8000-1;
	TIM2->CR1 = TIM_CR1_OPM;
	while(1){
		switch(i){
		case 0:
			GPIOE->BSRR |= GPIO_BSRR_BS_8;
			delay_ms(1000);
			GPIOE->BSRR |= GPIO_BSRR_BR_8;
			delay_ms(1000);
			break;
		case 1:
			GPIOE->BSRR |= GPIO_BSRR_BS_9;
			delay_ms(1000);
			GPIOE->BSRR |= GPIO_BSRR_BR_9;
			delay_ms(1000);
			break;
		case 2:
			GPIOE->BSRR |= GPIO_BSRR_BS_10;
			delay_ms(1000);
			GPIOE->BSRR |= GPIO_BSRR_BR_10;
			delay_ms(1000);
			break;
		case 3:
			GPIOE->BSRR |= GPIO_BSRR_BS_11;
			delay_ms(1000);
			GPIOE->BSRR |= GPIO_BSRR_BR_11;
			delay_ms(1000);
			break;
		EXTI0_IRQHandler(EXTI0_IRQn);
		}
		if((GPIOA->IDR & GPIO_IDR_0) != 0){
			while (1){
				EXTI->IMR |= EXTI_IMR_MR0;
			}
		}
	}
}
void EXTI0_IRQHandler(){
	if (EXTI->IMR & EXTI_IMR_MR0){
		EXTI->IMR &=~EXTI_IMR_MR0;
		i++;
	}
}
