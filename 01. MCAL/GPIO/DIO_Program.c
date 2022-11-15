/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO_Program.c
 *        \brief  General Purpose Input Output
 *
 *      \details  The Driver Configure All pins of TM4A123GH6PM, Enable the clock to the port,
									Unlock all registers before doing any thing, Disable alternative functions,
									Enable digital function on all pins.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "bit_cal.h"
#include "DIO_Interface.h"




/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	



/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void DIO_Init(void)                                      
* \Description     : initialize GPIO\Enable clock 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void MDIO_Init(void)
{
	
	/* 1- Enable the clock to the port */ 
	
	SYSCTL_RCGCGPIO_REG |= 0x00000001; //Enable clock for PORTA
  SYSCTL_RCGCGPIO_REG |= 0x00000002; //Enable clock for PORTB
  SYSCTL_RCGCGPIO_REG |= 0x00000004; //Enable clock for PORTC
  SYSCTL_RCGCGPIO_REG |= 0x00000008; //Enable clock for PORTD
  SYSCTL_RCGCGPIO_REG |= 0x00000010; //Enable clock for PORTE
  SYSCTL_RCGCGPIO_REG |= 0x00000020; //Enable clock for PORTF
	
	/* 2-Unlock all registers */                     

    GPIO_PORTA_LOCK_REG = 0x4C4F434B;
    GPIO_PORTB_LOCK_REG = 0x4C4F434B;
    GPIO_PORTC_LOCK_REG = 0x4C4F434B;
    GPIO_PORTD_LOCK_REG = 0x4C4F434B;
    GPIO_PORTE_LOCK_REG = 0x4C4F434B;
    GPIO_PORTF_LOCK_REG = 0x4C4F434B;
    
    /* 3- Disable alternative functions */

    GPIO_PORTA_AFSEL_REG &=~ ( 0x000000FF );
    GPIO_PORTB_AFSEL_REG &=~ ( 0x000000FF );
    GPIO_PORTC_AFSEL_REG &=~ ( 0x000000F0 );
    GPIO_PORTD_AFSEL_REG &=~ ( 0x000000FF );
    GPIO_PORTE_AFSEL_REG &=~ ( 0x0000003F );
    GPIO_PORTF_AFSEL_REG &=~ ( 0x0000001F );
    
    /* 4- Enable digital function on all pins */

    GPIO_PORTA_PCTL_REG &=~ ( 0x000000FF );
    GPIO_PORTB_PCTL_REG &=~ ( 0x000000FF );
    //GPIO_PORTC_PCTL_REG &=~ ( 0x000000F0 );
    GPIO_PORTD_PCTL_REG &=~ ( 0x000000FF );
    GPIO_PORTE_PCTL_REG &=~ ( 0x0000003F );
    GPIO_PORTF_PCTL_REG &=~ ( 0x0000001F );

		/* 5- Disable analog function for all ports */

    GPIO_PORTA_AMSEL_REG &=~ ( 0x000000FF );
    GPIO_PORTB_AMSEL_REG &=~ ( 0x000000FF );
    GPIO_PORTC_AMSEL_REG &=~ ( 0x000000F0 );
    GPIO_PORTD_AMSEL_REG &=~ ( 0x000000FF );
    GPIO_PORTE_AMSEL_REG &=~ ( 0x0000003F );
    GPIO_PORTF_AMSEL_REG &=~ ( 0x0000001F );
    
    /* 6-Enable writing on GPIOAFSEL, GPIOPUR, GPIOPDR */                    

    GPIO_PORTA_CR_REG = 0x000000FF;
    GPIO_PORTB_CR_REG = 0x000000FF;
    GPIO_PORTC_CR_REG = 0x000000F0;
    GPIO_PORTD_CR_REG = 0x000000FF;
    GPIO_PORTE_CR_REG = 0x0000003F;
    GPIO_PORTF_CR_REG = 0x0000001F;
		
		

  
    /* 7- Set all pins as input as an initial state */

    GPIO_PORTA_DIR_REG &=~ ( 0x000000FF ) ;
    GPIO_PORTB_DIR_REG &=~ ( 0x000000FF ) ;
    GPIO_PORTC_DIR_REG &=~ ( 0x000000F0 ) ;
    GPIO_PORTD_DIR_REG &=~ ( 0x000000FF ) ;
    GPIO_PORTE_DIR_REG &=~ ( 0x0000003F ) ;
    GPIO_PORTF_DIR_REG &=~ ( 0x0000001F ) ;


}


/******************************************************************************
* \Syntax          : void MDIO_SetPinDirection(PORTS PortNumber_a, u8 PinNumber_a, PIN_DIRECTION Direction_a )                                      
* \Description     : set pin direction 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void MDIO_SetPinDirection(PORTS PortNumber_a, u8 PinNumber_a, PIN_DIRECTION Direction_a )
{
    switch (PortNumber_a)
    {
    case PORTA:
        if( Direction_a == OUTPUT )
        {
            set_bit( GPIO_PORTA_DIR_REG , PinNumber_a );
            set_bit( GPIO_PORTA_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else if( Direction_a == INPUT )
        {
            clear_bit( GPIO_PORTA_DIR_REG , PinNumber_a ) ;
            set_bit( GPIO_PORTA_PUR_REG , PinNumber_a ); //enable pull up resistor
            set_bit( GPIO_PORTA_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else
        {
            /* do nothing*/
        }
        break;
    case PORTB:
        if( Direction_a == OUTPUT )
        {
            set_bit( GPIO_PORTB_DIR_REG , PinNumber_a );
            set_bit( GPIO_PORTB_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else if( Direction_a == INPUT )
        {
            clear_bit( GPIO_PORTB_DIR_REG , PinNumber_a );
            set_bit( GPIO_PORTB_PUR_REG , PinNumber_a ); //enable pull up resistor
            set_bit( GPIO_PORTB_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else
        {
            /* do nothing*/
        }
        break;
    case PORTC:
        if( Direction_a == OUTPUT )
        {
            set_bit( GPIO_PORTC_DIR_REG , PinNumber_a );
            set_bit( GPIO_PORTC_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else if( Direction_a == INPUT )
        {
            clear_bit( GPIO_PORTC_DIR_REG , PinNumber_a );
            set_bit( GPIO_PORTC_PUR_REG , PinNumber_a ); //enable pull up resistor
            set_bit( GPIO_PORTC_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else
        {
            /* do nothing*/
        }
        break;
    case PORTD:
        if( Direction_a == OUTPUT )
        {
            set_bit( GPIO_PORTD_DIR_REG , PinNumber_a) ;
            set_bit( GPIO_PORTD_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else if( Direction_a == INPUT )
        {
            clear_bit( GPIO_PORTD_DIR_REG , PinNumber_a) ;
            set_bit( GPIO_PORTD_PUR_REG , PinNumber_a ); //enable pull up resistor
            set_bit( GPIO_PORTD_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else
        {
            /* do nothing*/
        }
        break;
    case PORTE:
        if( Direction_a == OUTPUT )
        {
            set_bit( GPIO_PORTE_DIR_REG , PinNumber_a) ;
            set_bit( GPIO_PORTE_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else if( Direction_a == INPUT )
        {
            clear_bit( GPIO_PORTE_DIR_REG , PinNumber_a) ;
            set_bit( GPIO_PORTE_PUR_REG , PinNumber_a ); //enable pull up resistor
            set_bit( GPIO_PORTE_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else
        {
            /* do nothing*/
        }
        break;
    case PORTF:
        if( Direction_a == OUTPUT )
        {
            set_bit( GPIO_PORTF_DIR_REG , PinNumber_a) ;
            set_bit( GPIO_PORTF_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else if( Direction_a == INPUT )
        {
            clear_bit( GPIO_PORTF_DIR_REG , PinNumber_a) ;
            set_bit( GPIO_PORTF_PUR_REG , PinNumber_a ); //enable pull up resistor
            set_bit( GPIO_PORTF_DEN_REG , PinNumber_a );/*enable digital function*/
        }
        else
        {
            /* do nothing*/
        }
        break;
    }
}


/******************************************************************************
* \Syntax          : void MDIO_WritePin( PORTS PortNumber_a, u8 PinNumber_a, PIN_VALUE Value_a )                                      
* \Description     : write pin 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void MDIO_WritePin( PORTS PortNumber_a, u8 PinNumber_a, PIN_VALUE Value_a )
{
    switch ( PortNumber_a )
    {
    case PORTA:
        if( Value_a == HIGH)
        {
            set_bit(GPIO_PORTA_DATA_REG , PinNumber_a );
        }
        else if( Value_a == LOW )
        {
            clear_bit( GPIO_PORTA_DATA_REG , PinNumber_a );
        }

        break;
    case PORTB:
        if( Value_a == HIGH)
        {
            set_bit( GPIO_PORTB_DATA_REG , PinNumber_a );
        }
        else if( Value_a == LOW )
        {
            clear_bit( GPIO_PORTB_DATA_REG , PinNumber_a );
        }
        else
        {
            /*do nothing*/
        }
        break;
    case PORTC:
        if( Value_a == HIGH)
        {
            set_bit( GPIO_PORTC_DATA_REG , PinNumber_a );
        }
        else if( Value_a == LOW )
        {
            clear_bit( GPIO_PORTC_DATA_REG , PinNumber_a );
        }
        else
        {
            /*do nothing*/
        }
        break;
    case PORTD:
        if( Value_a == HIGH)
        {
            set_bit( GPIO_PORTD_DATA_REG , PinNumber_a );
        }
        else if( Value_a == LOW )
        {
            clear_bit( GPIO_PORTD_DATA_REG , PinNumber_a );
        }
        else
        {
            /*do nothing*/
        }
        break;
    case PORTE:
        if( Value_a == HIGH)
        {
            set_bit( GPIO_PORTE_DATA_REG , PinNumber_a );
        }
        else if( Value_a == LOW )
        {
            clear_bit( GPIO_PORTE_DATA_REG , PinNumber_a );
        }
        else
        {
            /*do nothing*/
        }
        break;
    case PORTF:
        if( Value_a == HIGH)
        {
            set_bit( GPIO_PORTF_DATA_REG , PinNumber_a );
        }
        else if( Value_a == LOW )
        {
            clear_bit( GPIO_PORTF_DATA_REG , PinNumber_a );
        }
        else
        {
            /*do nothing*/
        }
        break;
    }
}



/******************************************************************************
* \Syntax          : u8 MDIO_ReadPin( PORTS PortNumber_a, u8 PinNumber_a )                                     
* \Description     : read pin 
*                                                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


u8 MDIO_ReadPin( PORTS PortNumber_a, u8 PinNumber_a )
{
    u8 Ret_Val = 0;
    switch (PortNumber_a)
    {
    case PORTA:
        Ret_Val = check_bit( GPIO_PORTA_DATA_REG , PinNumber_a);
        break;
    case PORTB:
        Ret_Val = check_bit( GPIO_PORTB_DATA_REG , PinNumber_a);
        break;
    case PORTC:
        Ret_Val = check_bit( GPIO_PORTC_DATA_REG , PinNumber_a);
        break;
    case PORTD:
        Ret_Val = check_bit( GPIO_PORTD_DATA_REG , PinNumber_a);
        break;
    case PORTE:
        Ret_Val = check_bit( GPIO_PORTE_DATA_REG , PinNumber_a);
        break;
    case PORTF:
        Ret_Val = check_bit( GPIO_PORTF_DATA_REG , PinNumber_a);
        break;
    }
    return Ret_Val;
}


/**********************************************************************************************************************
 *  END OF FILE: DIO_Program.c
 *********************************************************************************************************************/
