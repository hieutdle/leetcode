#include <gtest/gtest.h>

#include "0271_encode_and_decode_strings.h"

class EncodeDecodeStringsTest : public ::testing::Test {
 protected:
  Codec codec;
};

TEST_F(EncodeDecodeStringsTest, TestCase1) {
  std::vector<std::string> strs = {"Hello", "World"};
  std::string encoded = codec.encode(strs);
  std::vector<std::string> decoded = codec.decode(encoded);

  EXPECT_EQ(decoded, strs);
}

TEST_F(EncodeDecodeStringsTest, TestCase2) {
  std::vector<std::string> strs = {""};
  std::string encoded = codec.encode(strs);
  std::vector<std::string> decoded = codec.decode(encoded);

  EXPECT_EQ(decoded, strs);
}