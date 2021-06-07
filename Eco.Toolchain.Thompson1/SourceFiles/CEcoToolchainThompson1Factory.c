/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoToolchainThompson1Factory
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию фабрики для компонента
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "CEcoToolchainThompson1.h"
#include "CEcoToolchainThompson1Factory.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция возвращает указатель на интерфейс
 * </описание>
 *
 */
int16_t CEcoToolchainThompson1Factory_QueryInterface(IEcoComponentFactory* me, const UGUID* riid, void** ppv) {
    if ( IsEqualUGUID(riid, &IID_IEcoUnknown) || IsEqualUGUID(riid, &IID_IEcoComponentFactory) ) {
        *ppv = me;
    }
    else {
        *ppv = 0;
        return -1;
    }
    ((IEcoUnknown*)(*ppv))->pVTbl->AddRef((IEcoUnknown*)*ppv);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция увеличивает количество ссылок на интерфейс
 * </описание>
 *
 */
uint32_t CEcoToolchainThompson1Factory_AddRef(/* in */ IEcoComponentFactory* me) {
    CEcoToolchainThompson1Factory* pCMe = (CEcoToolchainThompson1Factory*)me;

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
 *   Функция уменьшает количество ссылок на интерфейс
 * </описание>
 *
 */
uint32_t CEcoToolchainThompson1Factory_Release(/* in */ IEcoComponentFactory* me) {
    CEcoToolchainThompson1Factory* pCMe = (CEcoToolchainThompson1Factory*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        //deleteCEcoToolchainThompson1Factory(&pCMe->m_VtblICF);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализирует компонент с параметрами
 * </описание>
 *
 */
int16_t CEcoToolchainThompson1Factory_Init(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pIUnkSystem, /* in */ void* pv) {
    CEcoToolchainThompson1Factory* pCMe = (CEcoToolchainThompson1Factory*)me;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    /* Инициализация компонента */
    result = pCMe->m_pInitInstance(pv, pIUnkSystem);

    return result;
}

/*
 *
 * <сводка>
 *   Функция Alloc
 * </сводка>
 *
 * <описание>
 *   Функция создает компонент
 * </описание>
 *
 */
int16_t CEcoToolchainThompson1Factory_Alloc(/* in */ struct IEcoComponentFactory* me, /* in */ struct IEcoUnknown *pISystem, /* in */ struct IEcoUnknown *pIUnknownOuter, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoToolchainThompson1Factory* pCMe = (CEcoToolchainThompson1Factory*)me;
    IEcoUnknown* pIUnk = 0;
    int16_t result = -1;

    if (me == 0 ) {
        return -1;
    }

    /* Агрегирование при условии если IID это IID_IEcoUnknown */
    if ( ( pIUnknownOuter != 0 ) && !IsEqualUGUID(riid, &IID_IEcoUnknown ) ) {
        /* не поддерживает агрегирование */
        return -1;
    }

    /* Создание компонента */
    result = pCMe->m_pInstance(pISystem, pIUnknownOuter, (void**)&pIUnk);
    if ( result != 0 || pIUnk == 0) {
        return -1;
    }

    /* Инициализация компонента */
    result = me->pVTbl->Init(me, pISystem, pIUnk);

    /* Получение указателя на интерфейс */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, riid, ppv);

    /* Уменьшение ссылки запрошенной Фабрикой компонентов */
    pIUnk->pVTbl->Release(pIUnk);

    return result;
}

/*
 *
 * <сводка>
 *   Функция get_Name
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование компонента
 * </описание>
 *
 */
char_t* CEcoToolchainThompson1Factory_get_Name(/* in */ struct IEcoComponentFactory* me) {
    CEcoToolchainThompson1Factory* pCMe = (CEcoToolchainThompson1Factory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Name;
}

/*
 *
 * <сводка>
 *   Функция get_Version
 * </сводка>
 *
 * <описание>
 *   Функция возвращает версию компонента
 * </описание>
 *
 */
char_t* CEcoToolchainThompson1Factory_get_Version(/* in */ struct IEcoComponentFactory* me) {
    CEcoToolchainThompson1Factory* pCMe = (CEcoToolchainThompson1Factory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Version;
}

/*
 *
 * <сводка>
 *   Функция get_Manufacturer
 * </сводка>
 *
 * <описание>
 *   Функция возвращает наименование производителя компонента
 * </описание>
 *
 */
char_t* CEcoToolchainThompson1Factory_get_Manufacturer(/* in */ struct IEcoComponentFactory* me) {
    CEcoToolchainThompson1Factory* pCMe = (CEcoToolchainThompson1Factory*)me;

    if (me == 0 ) {
        return 0;
    }

    return pCMe->m_Manufacturer;
}

/* Create Virtual Table */
IEcoComponentFactoryVTbl g_x2F557A53EB7B42AD849CD8EC16CF5C5DFactoryVTbl = {
    CEcoToolchainThompson1Factory_QueryInterface,
    CEcoToolchainThompson1Factory_AddRef,
    CEcoToolchainThompson1Factory_Release,
    CEcoToolchainThompson1Factory_Alloc,
    CEcoToolchainThompson1Factory_Init,
    CEcoToolchainThompson1Factory_get_Name,
    CEcoToolchainThompson1Factory_get_Version,
    CEcoToolchainThompson1Factory_get_Manufacturer
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция 
 * </описание>
 *
 */
CEcoToolchainThompson1Factory g_x2F557A53EB7B42AD849CD8EC16CF5C5DFactory = {
    &g_x2F557A53EB7B42AD849CD8EC16CF5C5DFactoryVTbl,
    0,
    (CreateInstance)createCEcoToolchainThompson1,
    (InitInstance)initCEcoToolchainThompson1,
    "EcoToolchainThompson1\0",
    "1.0.0.0\0",
    "CompanyName\0"
};

#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr() {
    return (IEcoComponentFactory*)&g_x2F557A53EB7B42AD849CD8EC16CF5C5DFactory;
};
#elif ECO_LIB
IEcoComponentFactory* GetIEcoComponentFactoryPtr_2F557A53EB7B42AD849CD8EC16CF5C5D = (IEcoComponentFactory*)&g_x2F557A53EB7B42AD849CD8EC16CF5C5DFactory;
#endif