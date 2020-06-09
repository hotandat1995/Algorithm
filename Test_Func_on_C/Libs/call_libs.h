#pragma once

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

/* UNION */
union UNI_Test{
  char String[10];
  char Char;
  int Int;
  bool Bool_T;
}__attribute__((packed));

/* Multi-argument test func */
void test_multi_arg();

/* memmove test func */
void memmove_test();

/* Union test func */
void test_union();

/* Static cast test func */
int64_t test_static_cast();
void get_address_of_struct_after_convert();

/* Struct test func */
void test_struct();
