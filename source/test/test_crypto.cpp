/**************************************************************************/
/* Copyright (c) 2021-present Craig Stoneham.                             */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "test_crypto.h"

PACKER_NAMESPACE_BEGIN

TestResult TestCrypto::test(uint32_t p_initial, size_t p_num_tests) {

    std::srand(p_initial);

    for (size_t i = 0; i < p_num_tests; ++i) {
        int value = std::rand();
        CryptoKey key(value);
        String test_key = "test_key " + std::to_string(value);
        String encrypted_key = Crypto::encrypt_decrypt(test_key, key);
        String decrypted_key = Crypto::encrypt_decrypt(encrypted_key, key);
        if (decrypted_key != test_key) {
            return TEST_FAILED("The data does not match after undergoing encryption and decryption with the key '" + std::to_string(value) + "'.");
        }
    }
    return TEST_PASSED();
}

TestCrypto::TestCrypto() {
    ADD_TEST("Crypto", [this]() { return test(); });
}

PACKER_NAMESPACE_END