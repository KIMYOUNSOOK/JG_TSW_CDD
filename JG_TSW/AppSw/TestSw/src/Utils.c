/*******************************************************************************
**                                                                            **
** Copyright (C) Hyundai Mobis                                                **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Hyundai Mobis  **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            
**          FILE  : Utils.c
** 
**       PROJECT  : BMS_STANDLAONE_TC375                                       
**       
**        AUTHOR  : Hyun Kang
**                                                                    
**       VERSION  : V1.0
** 
**      PLATFORM  : Infineon Aurix 375T                                         
**                                                                       
**   DESCRIPTION  :                                          
**                                                                            
*******************************************************************************/


/*******************************************************************************
**  Revision History                                                          **
********************************************************************************
 *  ----------------------------------------------------------------------------
 *  Version Date        Author      Change Id   Description
 *  ----------------------------------------------------------------------------

 *  V1.0    20190701    Hyun Kang   -           First Implementation


*******************************************************************************/






/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcu.h"
#include "Utils.h"
#if 0 // using STM
#include "TestStm.h"
#else
#include "TestApp.h"
#endif


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/



/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/



/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/




/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


  
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/



/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/



/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/



/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Function Name    : Delay
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void Delay(uint32 count)
{
    uint32  i;

    if(count == 0) return;

    for (i = 0; i < count; i++)
    {
        NOP();
    }
}

/*******************************************************************************
** Function Name    : Delay_ms
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void Delay_ms(uint32 delay_ms)
{
#if 0 // using STM
    uint32 Current_Tick = 0u;
    uint32 waitTickCnt = 0u;
    if(delay_ms == 0) return;
    Current_Tick = TestStm_GetTimestampMs();
    while ((TestStm_GetTimestampMs() - Current_Tick) < delay_ms)
    {
        waitTickCnt++;
    }
#else
    uint32 Current_Tick=0u;

    if(delay_ms == 0) return;

    Current_Tick = TestApp_GetTick();

    while ((TestApp_GetTick() - Current_Tick) < (delay_ms*100)) /* 1ms = 10us tick * 100 */
    {
        ;
    }
#endif
}

/*******************************************************************************
** Function Name    : Delay_us
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : None
**
*******************************************************************************/
void Delay_us(uint32 delay_us)
{
#if 0 // using STM
    uint64 Current_Tick = 0u;
    uint32 waitTickCnt = 0u;
    if(delay_us == 0) return;
    Current_Tick = TestStm_GetTimestampUs();
    while ((TestStm_GetTimestampUs() - Current_Tick) < delay_us)
    {
        waitTickCnt++;
    }
#else
    uint32 Current_Tick=0u;

    Current_Tick = TestApp_GetTick();

    while ((TestApp_GetTick() - Current_Tick) < (delay_us/10)) /* 1ms = 10us tick * 100 */
    {
        ;
    }
#endif
}

/*******************************************************************************
** Function Name    : Get_Tick
**
** Return Value     : None
**
** Parameter        : None
**
** Description      : 1Tick = 1us
**
*******************************************************************************/
uint32 Get_Tick(void)
{
#if 0 // using STM
    return (uint32)TestStm_GetTimestampUs();
#else
    return TestApp_GetTick();
#endif
}

