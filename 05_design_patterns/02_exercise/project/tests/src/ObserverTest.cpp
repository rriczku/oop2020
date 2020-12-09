#include "observer/Acceleration.h"
#include "observer/Displacement.h"
#include "observer/Speed.h"
#include <gtest/gtest.h>

TEST(Observer, SpeedAcceleration) {
    observer::Displacement displacement;

    observer::Speed speed;
    observer::Acceleration acceleration;

    displacement.registerObserver(&speed);
    displacement.registerObserver(&acceleration);

    displacement.set(10);
    displacement.set(11);
    displacement.set(13);
    EXPECT_EQ(2, speed.get());
    EXPECT_EQ(1, acceleration.get());
}
