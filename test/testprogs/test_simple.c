/*
 * Copyright (c) 2009 Petri Lehtinen <petri@digip.org>
 *
 * Jansson is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include <string.h>
#include <jansson.h>
#include "util.h"

/* Call the simple functions not covered by other tests of the public API */
int main()
{
    json_t *value;

    value = json_integer(1);
    if(json_typeof(value) != JSON_INTEGER)
        fail("json_typeof failed");

    if(json_is_object(value))
        fail("json_is_object failed");

    if(json_is_array(value))
        fail("json_is_array failed");

    if(json_is_string(value))
        fail("json_is_string failed");

    if(!json_is_integer(value))
        fail("json_is_integer failed");

    if(json_is_real(value))
        fail("json_is_real failed");

    if(!json_is_number(value))
        fail("json_is_number failed");

    if(json_is_true(value))
        fail("json_is_true failed");

    if(json_is_false(value))
        fail("json_is_false failed");

    if(json_is_boolean(value))
        fail("json_is_boolean failed");

    if(json_is_null(value))
        fail("json_is_null failed");

    json_decref(value);


    value = json_string("foo");
    if(!value)
        fail("json_string failed");
    if(strcmp(json_string_value(value), "foo"))
        fail("invalid string value");
    json_decref(value);

    value = json_string(NULL);
    if(value)
        fail("json_string(NULL) failed");

    value = json_integer(123);
    if(!value)
        fail("json_integer failed");
    if(json_integer_value(value) != 123)
        fail("invalid integer value");
    if(json_number_value(value) != 123.0)
        fail("invalid number value");
    json_decref(value);

    value = json_real(123.123);
    if(!value)
        fail("json_real failed");
    if(json_real_value(value) != 123.123)
        fail("invalid integer value");
    if(json_number_value(value) != 123.123)
        fail("invalid number value");
    json_decref(value);

    value = json_true();
    if(!value)
        fail("json_true failed");
    json_decref(value);

    value = json_false();
    if(!value)
        fail("json_false failed");
    json_decref(value);

    value = json_null();
    if(!value)
        fail("json_null failed");
    json_decref(value);

    return 0;
}