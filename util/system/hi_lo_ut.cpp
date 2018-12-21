#include <util/system/hi_lo.h>

#include <library/unittest/registar.h>

#include "defaults.h"

Y_UNIT_TEST_SUITE(HiLo) {

Y_UNIT_TEST(HiLo32) {
    ui64 x = 0;
    Lo32(x) = 18;
    UNIT_ASSERT_VALUES_EQUAL(x, 18);

    Hi32(x) = 33;
    UNIT_ASSERT_VALUES_EQUAL(x, 141733920786);

    const ui64 y = 0x33c06196e94c03ab;
    UNIT_ASSERT_VALUES_EQUAL(Lo32(y).Get(), 0xe94c03ab);
    UNIT_ASSERT_VALUES_EQUAL(Hi32(y).Get(), 0x33c06196);

    UNIT_ASSERT_VALUES_EQUAL(LO_32(y), 0xe94c03ab);
    UNIT_ASSERT_VALUES_EQUAL(HI_32(y), 0x33c06196);
}

Y_UNIT_TEST(HiLo16) {
    ui32 x = 0;
    Lo16(x) = 18;
    UNIT_ASSERT_VALUES_EQUAL(x, 18);

    Hi16(x) = 33;
    UNIT_ASSERT_VALUES_EQUAL(x, 2162706);

    const ui32 y = 0xe94c03ab;
    UNIT_ASSERT_VALUES_EQUAL(Lo16(y).Get(), 0x03ab);
    UNIT_ASSERT_VALUES_EQUAL(Hi16(y).Get(), 0xe94c);

    UNIT_ASSERT_VALUES_EQUAL(LO_16(y), 0x03ab);
    UNIT_ASSERT_VALUES_EQUAL(HI_16(y), 0xe94c);
}

Y_UNIT_TEST(HiLo8) {
    ui16 x = 0;
    Lo8(x) = 18;
    UNIT_ASSERT_VALUES_EQUAL(x, 18);

    Hi8(x) = 33;
    UNIT_ASSERT_VALUES_EQUAL(x, 8466);

    const ui16 y = 0x03ab;
    UNIT_ASSERT_VALUES_EQUAL(Lo8(y).Get(), 0xab);
    UNIT_ASSERT_VALUES_EQUAL(Hi8(y).Get(), 0x03);

    UNIT_ASSERT_VALUES_EQUAL(LO_8(y), 0xab);
    UNIT_ASSERT_VALUES_EQUAL(HI_8(y), 0x03);
}

Y_UNIT_TEST(Combined) {
    ui32 x = 0;
    Lo8(Lo16(x)) = 18;
    UNIT_ASSERT_VALUES_EQUAL(x, 18);

    Hi8(Lo16(x)) = 33;
    UNIT_ASSERT_VALUES_EQUAL(x, 8466);

    const ui32 y = 0xe94c03ab;
    UNIT_ASSERT_VALUES_EQUAL(Lo8(Lo16(y)).Get(), 0xab);
    UNIT_ASSERT_VALUES_EQUAL(Hi8(Lo16(y)).Get(), 0x03);

    UNIT_ASSERT_VALUES_EQUAL(LO_8_LO_16(y), 0xab);
    UNIT_ASSERT_VALUES_EQUAL(HI_8_LO_16(y), 0x03);
}

}
