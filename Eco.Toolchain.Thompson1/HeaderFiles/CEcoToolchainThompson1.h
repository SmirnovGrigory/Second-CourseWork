/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoToolchainThompson1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoToolchainThompson1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_TOOLCHAIN_THOMPSON_1_H__
#define __C_ECO_TOOLCHAIN_THOMPSON_1_H__

#include "IEcoToolchainThompson1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IdEcoLog1.h"

typedef struct CEcoToolchainThompson1 {

    /* Таблица функций интерфейса IEcoToolchainThompson1 */
    IEcoToolchainThompson1VTbl* m_pVTblIThompson;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    //вспомогательная функцуия(рекурсивна)
    int16_t(*ConstructionByRecursiveStrategy)(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t** re, /* in */ uint16_t size,  /* in */ IEcoFSM1State* Source, /* in */ IEcoFSM1State* Target, /* out */ IEcoFSM1StateMachine** pIFA);

    int16_t(*TransitionTableInfo)(/* in */ struct IEcoToolchainThompson1* me,/* in */ IEcoData1Table* pITransitionTable);

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

	/* Системный интерфейс */
    IEcoInterfaceBus1* m_pIBus;

    /* Данные экземпляра */
    char_t* m_Name;

	//поля для хранения символов
	char_t EscapeCharacter;
	char_t DisjunctionCharacter;
	char_t LeftBracket;
	char_t RightBracket;
	char_t KleeneStar;

	// 
	char_t* UniqueStateIdentifyier;

    IEcoLog1* m_pILog;
	

} CEcoToolchainThompson1, *CEcoToolchainThompson1Ptr;

/* Инициализация экземпляра */
int16_t initCEcoToolchainThompson1(/*in*/ struct IEcoToolchainThompson1* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t createCEcoToolchainThompson1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoToolchainThompson1** ppIThompson);
/* Удаление */
void deleteCEcoToolchainThompson1(/* in */ IEcoToolchainThompson1* pIThompson);

#endif /* __C_ECO_TOOLCHAIN_THOMPSON_1_H__ */
