#include "stm32f4xx.h"



#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define DIER_UIE	 (1U<<0)

void tim2_1hz_init(void)
{
	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1
	/*Clear counter*/
	TIM2->CNT = 0;

	/*Enable timer*/
	TIM2->CR1 = CR1_CEN;
}


void tim2_1hz_interrupt_init(void)
{
	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1
	/*Clear counter*/
	TIM2->CNT = 0;

	/*Enable timer*/
	TIM2->CR1 = CR1_CEN;

	/*Enable TIM interrupt*/
	TIM2->DIER |=DIER_UIE;

	/*Enable TIM interrupt in NVIC*/
	 NVIC_EnableIRQ(TIM2_IRQn);
}
