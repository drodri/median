#include "median.h"
#include "google/gtest/gtest.h"


TEST(Sum, Normal) {
  MobileAverageFilter median(10);
  float a = 1.0f;
  float vf = median.filter(a);
  EXPECT_EQ(a/10, vf);
} 

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
