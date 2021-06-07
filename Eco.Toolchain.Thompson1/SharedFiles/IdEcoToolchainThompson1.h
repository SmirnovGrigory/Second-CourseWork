/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoToolchainThompson1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoToolchainThompson1
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_ECO_TOOLCHAIN_THOMPSON_1_H__
#define __ID_ECO_TOOLCHAIN_THOMPSON_1_H__

#include "IEcoBase1.h"
#include "IEcoToolchainThompson1.h"

/* EcoToolchainThompson1 CID = {2F557A53-EB7B-42AD-849C-D8EC16CF5C5D} */
#ifndef __CID_EcoToolchainThompson1
static const UGUID CID_EcoToolchainThompson1 = {0x01, 0x10, 0x2F, 0x55, 0x7A, 0x53, 0xEB, 0x7B, 0x42, 0xAD, 0x84, 0x9C, 0xD8, 0xEC, 0x16, 0xCF, 0x5C, 0x5D};
#endif /* __CID_EcoToolchainThompson1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_2F557A53EB7B42AD849CD8EC16CF5C5D;
#endif

#endif /* __ID_ECO_TOOLCHAIN_THOMPSON_1_H__ */
