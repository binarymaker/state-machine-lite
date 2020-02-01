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

#ifndef STATE_MACHINE_1ca22bb4_44b8_11ea_91cf_705a0f25cb51
#define STATE_MACHINE_1ca22bb4_44b8_11ea_91cf_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __STATE_MACHINE_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
typedef void (*task_handler)(void *);

typedef struct{
    task_handler handler;
    task_handler last_handler;
    uint8_t entry;
}stateMachine_st;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define STATE_MACHINE_State(task)               void task(stateMachine_st *_sm_)

#define STATE_MACHINE_StateChange(task)                                        \
{                                                                              \
  _sm_->last_handler = _sm_->handler;                                          \
  _sm_->handler = (task_handler)task;                                          \
}

#define STATE_MACHINE_Init(sm,task)                                            \
{                                                                              \
  sm.handler = (task_handler)task;                                             \
  sm.last_handler = NULL;                                                      \
  sm.entry = 1u;                                                               \
}

#define STATE_MACHINE_Exec(sm)                                                 \
{                                                                              \
  sm.last_handler = sm.handler;                                                \
  sm.handler(&sm);                                                             \
  sm.entry = (sm.last_handler != sm.handler);                                  \
}

#define STATE_ENTRY                                                (_sm_->entry)
#define STATE_EXIT                         (_sm_->last_handler != _sm_->handler)

#define STATE_MACHINE_StateCompare(sm,task)   (sm.handler == (task_handler)task)

/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* STATE_MACHINE_1ca22bb4_44b8_11ea_91cf_705a0f25cb51 */

