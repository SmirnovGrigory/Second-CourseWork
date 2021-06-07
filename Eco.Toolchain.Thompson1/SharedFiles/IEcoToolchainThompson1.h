/*
 * <кодировка символов>
 *   Cyrillic (Windows) - Codepage 1251
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoToolchainThompson1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoToolchainThompson1
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

#ifndef __I_ECO_TOOLCHAIN_THOMPSON_1_H__
#define __I_ECO_TOOLCHAIN_THOMPSON_1_H__

#include "IEcoBase1.h"
#include "IEcoFSM1.h"

/* IEcoToolchainThompson1 IID = {03B395DD-613C-4A50-A65C-563400076287} */
#ifndef __IID_IEcoToolchainThompson1
static const UGUID IID_IEcoToolchainThompson1 = {0x01, 0x10, 0x03, 0xB3, 0x95, 0xDD, 0x61, 0x3C, 0x4A, 0x50, 0xA6, 0x5C, 0x56, 0x34, 0x00, 0x07, 0x62, 0x87};
#endif /* __IID_IEcoToolchainThompson1 */

typedef struct IEcoToolchainThompson1VTbl {

    /* IEcoUnknown */
    int16_t (*QueryInterface)(/* in */ struct IEcoToolchainThompson1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (*AddRef)(/* in */ struct IEcoToolchainThompson1* me);
    uint32_t (*Release)(/* in */ struct IEcoToolchainThompson1* me);

    /* IEcoToolchainThompson1 */

	int16_t(*set_EscapeCharacter)(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t code);
    int16_t(*set_DisjunctionCharacter)(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t code);
    int16_t(*set_GroupBrakets)(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t leftCode, /* in */ char_t rightCode);
    int16_t(*set_KleeneStar)(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t code);

    int16_t (*ConstructionFA)(/* in */ struct IEcoToolchainThompson1* me, /* in */ char_t** re, /* in */ uint16_t size, /* out */ IEcoFSM1StateMachine** pIFA);

} IEcoToolchainThompson1VTbl, *IIEcoToolchainThompson1VTblPtr;

interface IEcoToolchainThompson1 {
    struct IEcoToolchainThompson1VTbl *pVTbl;
} IEcoToolchainThompson1;

#endif /* __I_ECO_TOOLCHAIN_THOMPSON_1_H__ */
