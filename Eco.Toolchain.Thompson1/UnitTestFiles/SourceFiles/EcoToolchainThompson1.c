/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   EcoToolchainThompson1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoInterfaceBus1.h"
#include "IdEcoToolchainThompson1.h"
#include "IdEcoFSM1.h"
#include "IdEcoData1.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"
#include "IdEcoStack1.h"
#include "IEcoLog1FileAffiliate.h"
#include "IdEcoLog1.h"

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoToolchainThompson1* pIThompson = 0;
    IEcoFSM1StateMachine* pINFA = 0;
    char_t* R1 = "x*y*";
    char_t* R2 = "(xvy)*x";
    char_t* arr_R[2];
	//TO DO
	IEcoData1Table* pITransitionTable = 0;

	//my test regulars
	char_t* mR1 = "a";
	char_t* mR2 = "avb";
	char_t* mR3 = "a^b";
	char_t* mR4 = "avbvc";
	char_t* mR5 = "a^(bvc)";
	char_t* mR6 = "a*";

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

#ifdef ECO_LIB

    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoToolchainThompson1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_2F557A53EB7B42AD849CD8EC16CF5C5D);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

        /* Регистрация статического компонента для работы с конечным автоматом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoFSM1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5E7C610CB846447DB59A3C5A2C4F446F);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;

    }

    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoList1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_53884AFC93C448ECAA929C8D3A562281);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы со строкой */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с таблицами */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoData1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_5A0F0DD57E6448EC9EE0E5D67572B47E);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с таблицами */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoStack1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_18129B1DCF9248D9A7787F9206E2D6DC);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с журналом */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLog1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_97322B6765B74342BBCE38798A0B40B5);
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

#endif

    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoToolchainThompson1, 0, &IID_IEcoToolchainThompson1, (void**) &pIThompson);
    if (result != 0 && pIThompson == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* TO DO */
    //arr_R[0] = R1;
    //arr_R[1] = R2;
	pIThompson->pVTbl->set_DisjunctionCharacter(pIThompson,'v');
	pIThompson->pVTbl->set_GroupBrakets(pIThompson,'(',')');
	pIThompson->pVTbl->set_KleeneStar(pIThompson,'*');

    result = pIThompson->pVTbl->ConstructionFA(pIThompson, &mR2, 3, &pINFA);
	//pITransitionTable = pINFA->pVTbl->get_TransitionTable(pINFA);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIThompson != 0) {
        pIThompson->pVTbl->Release(pIThompson);
    }

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

