/*
DO NOT CHANGE THE CONTENTS OF THIS FILE IN CASE A NEW VERSION IS DISTRIBUTED.
PUT YOUR OWN TEST CASES IN student_tests.c
*/
// commands to run from test:
// gcc -c -o str.o ../Part1/str.c
// gcc -c -o ceasar.o ../Part2/ceasar.c
// gcc -o tests unit_tests.c str.o ceasar.o -lcriterion

#include "unit_tests.h"

// Test cases for strglen
Test(base_suite, strglen_full_str, .description="string len function works for full string") {
    char* plaintext = "Stony Brook";
    int key_act = strgLen(plaintext);
    int key_exp = 11;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

Test(base_suite, strglen_number_str, .description="string len function works for string with numbers") {
    char* plaintext = "CSE220";
    int key_act = strgLen(plaintext);
    int key_exp = 6;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}
Test(base_suite, strglen_basic, .description="string len function works for basic string") {
    char* plaintext = "C";
    int key_act = strgLen(plaintext);
    int key_exp = 1;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}
Test(base_suite, strgLen_empty_str, .description="String length function works for empty string") {
    char* plaintext = "";
    int key_act = strgLen(plaintext);
    int key_exp = 0;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}
// Test cases for strgCopy
Test(base_suite, strgCopy_basic, .description="string copy function works for basic input") {
    char source[] = "Computer Science";
    char destination[50];
    strgCopy(source, destination);
    cr_expect_str_eq(destination, source, "Expected: \"%s\", Actual: \"%s\"\n", source, destination);
}
Test(base_suite, strgCopy_complex, .description="string copy function works for complex input") {
    char source[] = "CSE-220";
    char destination[50];
    strgCopy(source, destination);
    cr_expect_str_eq(destination, source, "Expected: \"%s\", Actual: \"%s\"\n", source, destination);
}
Test(base_suite, strgCopy_empty, .description="String copy function works for empty string") {
    char* source = "";
    char destination[50];
    strgCopy(source, destination);
    cr_expect_str_empty(destination, "Expected: \"\", Actual: \"%s\"\n", destination);
}

// Test cases for strgChangeCase
Test(base_suite, strgChangeCase_basic, .description="String change case function works for basic string") {
    char str[] = "Stony Brook";
    char expected[] = "sTONY bROOK";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}
Test(base_suite, strgChangeCase_complex, .description="String change case function works for complex string") {
    char str[] = "CSE220";
    char expected[] = "cse220";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}
Test(base_suite, strgChangeCase_empty, .description="String change case function works for empty string") {
    char str[] = "";
    char expected[] = "";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}

// Test cases for strgDiff
Test(base_suite, strgDiff_same_strings, .description="String difference function works for identical strings") {
    char* s1 = "Hello";
    char* s2 = "Hello";
    int diff = strgDiff(s1, s2);
    cr_expect_eq(diff, -1, "Expected: -1, Actual: %d\n", diff);
}

Test(base_suite, strgDiff_diff_strings, .description="String difference function works for different strings") {
    char* s1 = "CSE-220";
    char* s2 = "CSE220";
    int diff = strgDiff(s1, s2);
    int expected = 3;
    cr_expect_eq(diff, expected, "Expected: %d, Actual: %d\n", expected, diff);
}
Test(base_suite, strgDiff_empty, .description="String difference function works for empty strings") {
    char* s1 = "";
    char* s2 = "";
    int diff = strgDiff(s1, s2);
    int expected = 0;
    cr_expect_eq(diff, expected, "Expected: %d, Actual: %d\n", expected, diff);
}

// Test cases for strgInterleave
Test(base_suite, strgInterleave_basic, .description="String interleaving function works for basic strings") {
    char* s1 = "abc";
    char* s2 = "123";
    char d[50];
    strgInterleave(s1, s2, d);
    char* expected = "a1b2c3";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

Test(base_suite, strgInterleave_diff_lengths, .description="String interleaving function works for strings with different lengths") {
    char* s1 = "abcdef";
    char* s2 = "123";
    char d[50];
    strgInterleave(s1, s2, d);
    char* expected = "a1b2c3def";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

Test(base_suite, strgInterleave_empty, .description="String interleaving function works for empty strings") {
    char* s1 = "";
    char* s2 = "123";
    char d[50];
    strgInterleave(s1, s2, d);
    char* expected = "123";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

// encrypt
Test(base_suite, encrypt_full_msg, .description="A full plaintext message can be encrypted.") {
    const char *plaintext = "System Fundamentals";
    char ciphertext_act[] = "I can store any message!";
    int count_act = encrypt(plaintext, ciphertext_act, 1);
    char *ciphertext_exp = "Tztufn Gvoebnfoubmt__EOM__";
    int count_exp = 18;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was:          %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}
Test(base_suite, encrypt_full_msg_numbers, .description="A full plaintext message with numbers can be encrypted.") {
    const char *plaintext = "Cse220";
    char ciphertext_act[] = "I can store any message!";
    int count_act = encrypt(plaintext, ciphertext_act, 1);
    char *ciphertext_exp = "Dtf331__EOM__";
    int count_exp = 6;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was:          %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

// decrypt
Test(base_suite, decrypt_full_msg, .description="A full ciphertext message can be decrypted.") {
    const char *ciphertext = "Tztufn Gvoebnfoubmt__EOM__";
    char plaintext_act[] = "I can store any message!";
    int count_act = decrypt(ciphertext, plaintext_act, 1);
    char *plaintext_exp = "System Fundamentals";
    int count_exp = 18;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was:          %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}
Test(base_suite, decrypt_full_msg_numbers, .description="A full ciphertext message with numbers can be decrypted.") {
    const char *ciphertext = "Dtf331__EOM__";
    char plaintext_act[] = "I can store any message!";
    int count_act = decrypt(ciphertext, plaintext_act, 1);
    char *plaintext_exp = "Cse220";
    int count_exp = 6;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was:          %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}