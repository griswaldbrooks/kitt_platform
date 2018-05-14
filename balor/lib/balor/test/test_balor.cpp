#include <catch.hpp>
#include <balor.h>
#include <string>

namespace kp = kitt_platform;

SCENARIO("balor can be created", "[balor]")
{
    GIVEN("balor is needed")
    {
        WHEN("creating balor")
        {
            THEN("creation should succeed")
            {
                REQUIRE_NOTHROW(kp::Balor());
            }
        }
    }
}
