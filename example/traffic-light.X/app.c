/**\cond
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2020 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  \endcond*/

/* Includes ------------------------------------------------------------------*/
#include "app.h"
#include "mcu.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
time_t start_time;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

STATE(GREEN)
{
  if (ENTRY)
  {
    GPIO_PinWrite(P_B0, HIGH);
    start_time = SYSTIMER_Millis();
  }
  
  if ((SYSTIMER_Millis() - start_time) > 5000)
  {
    NEXT_STATE(YELLOW);
  }
  
  if (EXIT)
  {
    GPIO_PinWrite(P_B0, LOW);
  }
}

STATE(YELLOW)
{
  if (ENTRY)
  {
    GPIO_PinWrite(P_B2, HIGH);
    start_time = SYSTIMER_Millis();
  }
  
  if ((SYSTIMER_Millis() - start_time) > 2000)
  {
    NEXT_STATE(RED);
  }
  
  if (EXIT)
  {
    GPIO_PinWrite(P_B2, LOW);
  }
}

STATE(RED)
{
  if (ENTRY)
  {
    GPIO_PinWrite(P_B1, HIGH);
    start_time = SYSTIMER_Millis();
  }
  
  if ((SYSTIMER_Millis() - start_time) > 5000)
  {
    NEXT_STATE(GREEN);
  }
  
  if (EXIT)
  {
    GPIO_PinWrite(P_B1, LOW);
  }
}