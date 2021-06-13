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
 *   Данный исходный код описывает реализацию интерфейсов CEcoToolchainThompson1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "CEcoToolchainThompson1.h"

#include "IEcoFSM1.h"
#include "IdEcoFSM1.h"
#include "IEcoStack1.h"
#include "IdEcoStack1.h"
#include "IdEcoString1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoToolchainThompson1
 * </описание>
 *
 */


int16_t CEcoToolchainThompson1_QueryInterface(/* in */ struct IEcoToolchainThompson1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return result;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoToolchainThompson1) ) {
        *ppv = &pCMe->m_pVTblIThompson;
        pCMe->m_pVTblIThompson->AddRef((IEcoToolchainThompson1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIThompson;
        pCMe->m_pVTblIThompson->AddRef((IEcoToolchainThompson1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoToolchainThompson1
 * </описание>
 *
 */
uint32_t CEcoToolchainThompson1_AddRef(/* in */ struct IEcoToolchainThompson1* me) {
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoToolchainThompson1
 * </описание>
 *
 */
uint32_t CEcoToolchainThompson1_Release(/* in */ struct IEcoToolchainThompson1* me) {
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoToolchainThompson1((IEcoToolchainThompson1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/* сеттеры */
int16_t CEcoToolchainThompson1_set_EscapeCharacter(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t code) {
	CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
	if (me == 0 || code == 0) {
        return -1;
    }
	
	pCMe->EscapeCharacter=code;
	return 0;
}

int16_t CEcoToolchainThompson1_set_DisjunctionCharacter(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t code) {
	CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
	if (me == 0 || code == 0) {
        return -1;
    }

	pCMe->DisjunctionCharacter=code;
	return 0;
}

int16_t CEcoToolchainThompson1_set_GroupBrakets(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t leftCode, /* in */ char_t rightCode) {
	CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
	if (me == 0 || leftCode == 0 || rightCode == 0) {
        return -1;
    }

	pCMe->LeftBracket=leftCode;
	pCMe->RightBracket=rightCode;
	return 0;
}

int16_t CEcoToolchainThompson1_set_KleeneStar(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t code) {
	CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
	if (me == 0 || code == 0) {
        return -1;
    }
	
	pCMe->KleeneStar=code;
	return 0;
}

char_t* getUniqueId(/* in */ struct IEcoToolchainThompson1* me) {
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
    char_t* strId = 0;
    int16_t len = 0;
    int16_t tmp = pCMe->UniqueStateIdentifyier;
    pCMe->UniqueStateIdentifyier++;
    while (tmp) {
        tmp = tmp/10;
        len++;
    }
    len++;
    //TO DO
    
    //strId = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, );
    return 0;
}

// основная функция строящая NFA
int16_t ConstructionByRecursiveStrategy(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t** re, /* in */ uint16_t size, /* in */ IEcoFSM1State* Source, /* in */ IEcoFSM1State* Target,/* out */ IEcoFSM1StateMachine** pIFA) {
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me; //можно ли сделать по другому?
    int16_t index = 0;
	int16_t result = 0;
	IEcoStack1* pIStack = 0;
	int16_t i=0;
	int16_t k=0;
	char_t* half1=0;
	char_t* half2=0;
	int16_t half1_size=0;
	int16_t half2_size=0;

	IEcoFSM1Event* NullEvent=0;
	//занулить
	IEcoFSM1Event* ValueEvent=0;

	IEcoFSM1State* NewState1=0;
	IEcoFSM1State* NewState2=0;
	IEcoFSM1State* NewState3=0;
	IEcoFSM1State* NewState4=0;

    /* TO DO */

	result = pCMe->m_pIBus->pVTbl->QueryComponent(pCMe->m_pIBus, &CID_EcoStack1, 0, &IID_IEcoStack1, (void**) &pIStack);

    /* Проверка */
    if (result != 0 && pIStack == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pIStack->pVTbl->Release(pIStack);
        return result;
    }

	if (size==1) {
        pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog,"Single transition processing %s", (*re));
        //pCMe->m_pILog->pVTbl->Info(pCMe->m_pILog, (*re));
		//если пришел один символ то просто надо создать транзитион, передать его как ивент
        ValueEvent = (*pIFA)->pVTbl->AddEvent((*pIFA), &(*re)[0], (int16_t)(*re)[0], 0);
		ValueEvent->pVTbl->set_Parameter(ValueEvent,&(*re)[0]);
		(*pIFA)->pVTbl->AddTransition((*pIFA),ValueEvent,Source,Target);
        pIStack->pVTbl->Release(pIStack);
		return 0;
	}
	// иначе идем по всем символам регулярного выражения
	for (i=0; i < size; i++) {
		if ((*re)[i] == pCMe->LeftBracket)
			pIStack->pVTbl->Push(pIStack, &(*re)[i]);
		else if ((*re)[i] == pCMe->RightBracket)
			pIStack->pVTbl->Pop(pIStack);
		else if (((*re)[i] == pCMe->DisjunctionCharacter || (*re)[i] == '^') && pIStack->pVTbl->Count(pIStack) == 0) {
			//нашли символ бинарной операции вне скобок
			//следовательно он "верхний" в регулярном выражении
			//разделяем выражение на 
			if ((*re)[0] == pCMe->LeftBracket && (*re)[i-1] == pCMe->RightBracket) {
                half1 = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, i - 2);
                half1_size = i - 2;
                for (k = 1; k < i - 1; k++)
                    half1[k - 1] = (*re)[k];
			} else {
                half1 = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, i);
                half1_size = i;
                for (k = 0; k < i; k++)
                    half1[k] = (*re)[k];
			}

			if ((*re)[i+1] == pCMe->LeftBracket && (*re)[size-1] == pCMe->RightBracket) {
                half2 = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, size - i - 1 - 2);
                half2_size = size - i - 1 - 2;
                for (k = i + 2; k < size - 1; k++)
                    half2[k - i - 2] = (*re)[k];
			} else {
                half2 = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, size - i - 1);
                half2_size = size - i - 1;
                for (k = i + 1; k < size; k++)
                    half2[k - i - 1] = (*re)[k];
			}

			if ((*re)[i] == pCMe->DisjunctionCharacter) {
                pCMe->m_pILog->pVTbl->Info(pCMe->m_pILog, "Disjunction processing");
				//создаем состояния и транзишены по конструкции томпсона
                NullEvent = (*pIFA)->pVTbl->AddEvent((*pIFA),"Null",1,1);
				//NullEvent->pVTbl->set_Null(NullEvent,1);
				NewState1 = (*pIFA)->pVTbl->AddState((*pIFA),"name");
				NewState2 = (*pIFA)->pVTbl->AddState((*pIFA),"name");
				NewState3 = (*pIFA)->pVTbl->AddState((*pIFA),"name");
				NewState4 = (*pIFA)->pVTbl->AddState((*pIFA),"name");
				(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,Source,NewState1);
				(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,Source,NewState2);
				(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,NewState3,Target);
				(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,NewState4,Target);
				pCMe->ConstructionByRecursiveStrategy(me,&half1,half1_size,NewState1,NewState3,pIFA); 
				pCMe->ConstructionByRecursiveStrategy(me,&half2,half2_size,NewState2,NewState4,pIFA); 
			} else if ((*re)[i] == '^') {
                pCMe->m_pILog->pVTbl->Info(pCMe->m_pILog, "Conjunction processing");
				//создать промежуточное состояние и запустить два рекурсивных вызова до него и от него
				NewState1 = (*pIFA)->pVTbl->AddState((*pIFA),"name");
				pCMe->ConstructionByRecursiveStrategy(me,&half1,half1_size,Source,NewState1,pIFA); 
				pCMe->ConstructionByRecursiveStrategy(me,&half2,half2_size,NewState1,Target,pIFA); 
			}
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem,half1); //correct?
			pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem,half2); //correct?
            pIStack->pVTbl->Release(pIStack);
			return 0;
		}

	}

	// если мы прошли весь цикл, то бинарной операции вне скобок нет
	// следовательно все выражение обернуто в скобки со звездой клини
	// то переходим к обработке звезды клини
	// MY TO DO

	if ((*re)[size-1] == pCMe->KleeneStar) {
        pCMe->m_pILog->pVTbl->Info(pCMe->m_pILog, "Klini star processing");
		if ((*re)[0] != pCMe->LeftBracket && (*re)[size-2] != pCMe->RightBracket) {
				half1 =(char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, size-1);
				half1_size=size-1;
				for (k=0; k<size-1;k++)
					half1[k]=(*re)[k];
			} else {
				half1 =(char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, size-3);
				half1_size=size-3;
				for (k=1; k<size-2;k++)
					half1[k-1]=(*re)[k];
			}
        NullEvent = (*pIFA)->pVTbl->AddEvent((*pIFA), "name", 1, 1);
		//NullEvent->pVTbl->set_Null(NullEvent,1);
		NewState1 = (*pIFA)->pVTbl->AddState((*pIFA),"name");
		NewState2 = (*pIFA)->pVTbl->AddState((*pIFA),"name");
		(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,Source,NewState1);
		(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,Source,Target);
		(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,NewState2,NewState1);
		(*pIFA)->pVTbl->AddTransition((*pIFA),NullEvent,NewState2,Target);
		pCMe->ConstructionByRecursiveStrategy(me,&half1,half1_size,NewState1,NewState2,pIFA);
		pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem,half1); //correct?
        pIStack->pVTbl->Release(pIStack);
		return 0;
	}
    pIStack->pVTbl->Release(pIStack);
    return 0;
}

/*
 *
 * <сводка>
 *   Функция ConstructionFA
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */

int16_t CEcoToolchainThompson1_ConstructionFA(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t** re, /* in */ uint16_t size, /* out */ IEcoFSM1StateMachine** pIFA) {
	CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
	IEcoFSM1State* StartState = 0;
	IEcoFSM1State* EndState = 0;
	//IEcoInterfaceBus1* pIBus = 0;
	IEcoFSM1* pIFSM = 0;
	int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 || re == 0 || pIFA == 0) {
        return -1;
    }
	
	/* Создаем конечный автомат */
    pCMe->m_pIBus->pVTbl->QueryComponent(pCMe->m_pIBus, &CID_EcoFSM1, 0, &IID_IEcoFSM1, (void**)&pIFSM);
    *pIFA = pIFSM->pVTbl->CreateStateMachine(pIFSM, "Thomson NFA");

	StartState = (*pIFA)->pVTbl->AddState(*pIFA,"Source");
	EndState = (*pIFA)->pVTbl->AddState(*pIFA,"Target");
	StartState->pVTbl->set_Initial(StartState,1);
	EndState->pVTbl->set_Final(EndState,1);
	pCMe->ConstructionByRecursiveStrategy(me,re,size,StartState,EndState,pIFA);
    pCMe->TransitionTableInfo(pCMe, (*pIFA)->pVTbl->get_TransitionTable(*pIFA));
}

int16_t TransitionTableInfo(/* in */ struct IEcoToolchainThompson1* me,/* in */ IEcoData1Table* pITransitionTable) {
    int16_t result = -1;
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
    /* Указатель на интерфейс работы со строкой */
    IEcoString1* pIString = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoFSM1* pIFSM = 0;
    //IEcoFSM1StateMachine* pIStateMachine = 0;
    IEcoFSM1State* pIState = 0;
    IEcoFSM1Transition* pITransition = 0;
    IEcoFSM1Event* pIEvent = 0;

    IEcoList1* pIColumns = 0;
    IEcoList1* pIRows = 0;
    IEcoData1Column* pIColumn = 0;
    IEcoData1Row* pIRow = 0;
    uint32_t index = 0;
    uint32_t indexColumn = 0;
    uint32_t indexRow = 0;
    char_t* Line = 0;
    char_t* Headers = 0;
    char_t* ptrStr = 0;

    pCMe->m_pIBus->pVTbl->QueryComponent(pCMe->m_pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void**)&pIString);

    /* Вывод конечного автомата */
    //pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "StateMachine [%s]", pIStateMachine->pVTbl->get_Name(pIStateMachine));

    /* Вывод управляющей таблицы */
   //pITransitionTable = pIStateMachine->pVTbl->get_TransitionTable(pIStateMachine);
    if (pITransitionTable != 0) {
        pIColumns = pITransitionTable->pVTbl->get_Columns(pITransitionTable);
        pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "Table [%s]", pITransitionTable->pVTbl->get_Name(pITransitionTable));
        Line = pIString->pVTbl->Append(pIString, Line, "+-------+");
        Headers = pIString->pVTbl->Append(pIString, Headers, "| S \\ E |");
        for (indexColumn = 0; indexColumn < pIColumns->pVTbl->Count(pIColumns); indexColumn++) {
            pIColumn = (IEcoData1Column*)pIColumns->pVTbl->Item(pIColumns, indexColumn);
            Line = pIString->pVTbl->Append(pIString, Line, "--");
            Headers = pIString->pVTbl->Append(pIString, Headers, "  ");
            Headers = pIString->pVTbl->Append(pIString, Headers, pIColumn->pVTbl->get_Name(pIColumn));
            Headers = pIString->pVTbl->Append(pIString, Headers, "  |");
            Line = pIString->pVTbl->Append(pIString, Line, "---+");
        }
        pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "%s", Line);
        pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "%s", Headers);
        pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "%s", Line);
        pIString->pVTbl->Free(pIString, Headers);
        Headers = 0;

        pIRows = pITransitionTable->pVTbl->get_Rows(pITransitionTable);
        for (indexRow = 0; indexRow < pIRows->pVTbl->Count(pIRows); indexRow++) {
            Headers = pIString->pVTbl->Append(pIString, Headers, "|");
            pIRow = (IEcoData1Row*)pIRows->pVTbl->Item(pIRows, indexRow);
            Headers = pIString->pVTbl->Append(pIString, Headers, "   ");
            ptrStr = pIString->pVTbl->ConvertIntToString(pIString, indexRow);
            Headers = pIString->pVTbl->Append(pIString, Headers, ptrStr);
            pIString->pVTbl->Free(pIString, ptrStr);
            Headers = pIString->pVTbl->Append(pIString, Headers, "   |");
            for (indexColumn = 0; indexColumn < pIColumns->pVTbl->Count(pIColumns); indexColumn++) {
                if (pIRow->pVTbl->IsNullByIndex(pIRow, indexColumn)) {
                    Headers = pIString->pVTbl->Append(pIString, Headers, "     |");
                }
                else {
                    Headers = pIString->pVTbl->Append(pIString, Headers, "  ");
                    Headers = pIString->pVTbl->Append(pIString, Headers, (char_t*)pIRow->pVTbl->get_ItemByIndex(pIRow, indexColumn));
                    Headers = pIString->pVTbl->Append(pIString, Headers, "  |");
                }
            }
            pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "%s", Headers);
            pCMe->m_pILog->pVTbl->InfoFormat(pCMe->m_pILog, "%s", Line);
            pIString->pVTbl->Free(pIString, Headers);
            Headers = 0;
        }
        pIString->pVTbl->Free(pIString, Line);
        Line = 0;
    }
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t initCEcoToolchainThompson1(/*in*/ struct IEcoToolchainThompson1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)me;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Инициализация данных */

    return 0;
}

/* Create Virtual Table */
IEcoToolchainThompson1VTbl g_x03B395DD613C4A50A65C563400076287VTbl = {
    CEcoToolchainThompson1_QueryInterface,
    CEcoToolchainThompson1_AddRef,
    CEcoToolchainThompson1_Release,
	CEcoToolchainThompson1_set_EscapeCharacter,
	CEcoToolchainThompson1_set_DisjunctionCharacter,
	CEcoToolchainThompson1_set_GroupBrakets,
	CEcoToolchainThompson1_set_KleeneStar,
    CEcoToolchainThompson1_ConstructionFA
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t createCEcoToolchainThompson1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoToolchainThompson1** ppIThompson) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoToolchainThompson1* pCMe = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;

    /* Проверка указателей */
    if (ppIThompson == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoToolchainThompson1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoToolchainThompson1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;
	pCMe->m_pIBus = pIBus;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoToolchainThompson1 */
    pCMe->m_pVTblIThompson = &g_x03B395DD613C4A50A65C563400076287VTbl;

    /* Инициализация данных */
    pCMe->m_Name = 0;
    pCMe->UniqueStateIdentifyier = 1;
    pCMe->ConstructionByRecursiveStrategy = ConstructionByRecursiveStrategy;
    pCMe->TransitionTableInfo = TransitionTableInfo;
    pCMe->getUniqueId = getUniqueId;

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**)&pCMe->m_pILog);
    if (result != 0 || pCMe->m_pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        deleteCEcoToolchainThompson1(pCMe);
    }

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**)&pIFileAffiliate);
    if (result != 0 || pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        deleteCEcoToolchainThompson1(pCMe);
    }
    pCMe->m_pILog->pVTbl->AddAffiliate(pCMe->m_pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);
    pCMe->m_pILog->pVTbl->Info(pCMe->m_pILog, "Object Create");
    /* Возврат указателя на интерфейс */
    *ppIThompson = (IEcoToolchainThompson1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void deleteCEcoToolchainThompson1(/* in */ IEcoToolchainThompson1* pIThompson) {
    CEcoToolchainThompson1* pCMe = (CEcoToolchainThompson1*)pIThompson;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIThompson != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
