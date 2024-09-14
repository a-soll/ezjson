#include <ezjson/json.h>
#include <iostream>

using namespace ezjson;

const padded_string ALL_TYPES_JSON = R"(
    {
      "array": [],

      "object": {},

      "string": "foo",

      "0": 0,
      "1": 1,
      "-1": -1,
      "9223372036854775807": 9223372036854775807,
      "-9223372036854775808": -9223372036854775808,

      "9223372036854775808": 9223372036854775808,
      "18446744073709551615": 18446744073709551615,

      "0.0": 0.0,
      "0.1": 0.1,
      "1e0": 1e0,
      "1e100": 1e100,

      "true": true,
      "false": false,

      "null": null
    }
  )"_padded;

int main() {
    json j(ALL_TYPES_JSON);
    int i = j.get_int32("1");
}
