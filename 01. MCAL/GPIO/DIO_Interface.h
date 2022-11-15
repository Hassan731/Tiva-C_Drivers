/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO_Program.c
 *        \brief  General Purpose Input Output
 *
 *      \details  The Driver Configure All pins of TM4A123GH6PM, Enable the clock to the port,
									Unlock all registers before doing any thing, Disable alternative functions,
									Enable digital function on all pins.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "bit_cal.h"
#include "tm4c123gh6pm_registers.h"




/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	INPUT,
	OUTPUT

}PIN_DIRECTION;

typedef enum
{
	LOW,
	HIGH
	
}PIN_VALUE;

typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
	
}PORTS;

typedef enum

{
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7
	
}PORTA_PINS;

typedef enum
{
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7
	
}PORTB_PINS;

typedef enum
{
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7
	
}PORTC_PINS;

typedef enum
{
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7
	
}PORTD_PINS;

typedef enum
{
	PINE0,
	PINE1,
	PINE2,
	PINE3,
	PINE4,
	PINE5
	
}PORTE_PINS;

typedef enum
{
	PINF0,
	PINF1,
	PINF2,
	PINF3,
	PINF4
	
}PORTF_PINS;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
 /******************************************************************************
* \Syntax          : void GPIO_Init(void)                                      
* \Description     : initialize GPIO\Enable clock 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void MDIO_Init(void);

/******************************************************************************
* \Syntax          : vvoid GPIO_SetPinDirection(PORTS PortNumber_a, u8 PinNumber_a, PIN_DIRECTION Direction_a )                                      
* \Description     : set pin direction 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void MDIO_SetPinDirection(PORTS PortNumber_a, u8 PinNumber_a, PIN_DIRECTION Direction_a );

/******************************************************************************
* \Syntax          : void GPIO_WritePin( PORTS PortNumber_a, u8 PinNumber_a, PIN_VALUE Value_a )                                      
* \Description     : write pin 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void MDIO_WritePin( PORTS PortNumber_a, u8 PinNumber_a, PIN_VALUE Value_a );

/******************************************************************************
* \Syntax          : u8 GPIO_ReadPin( PORTS PortNumber_a, u8 PinNumber_a )                                     
* \Description     : read pin 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

u8 MDIO_ReadPin( PORTS PortNumber_a, u8 PinNumber_a );


#endif /* GPIO_H_ */
