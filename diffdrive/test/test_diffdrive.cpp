#include <catch.hpp>
#include <diffdrive.h>

namespace kp = kitt_platform;

SCENARIO("diffdrive doesn't work", "[diffdrive]")
{
    GIVEN("testing")
    {
        WHEN("testing")
        {
            THEN("testing")
            {
                REQUIRE_FALSE(kp::to_wheel_velocity(0, 0, NULL, NULL));
            }
        }
    }
}
