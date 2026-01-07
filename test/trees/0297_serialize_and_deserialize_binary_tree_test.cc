#include <gtest/gtest.h>

#include "0297_serialize_and_deserialize_binary_tree.h"
#include "tree_test_utils.h"

class SerializeAndDeserializeBinaryTreeTest : public ::testing::Test {
 protected:
  Codec codec;
};

TEST_F(SerializeAndDeserializeBinaryTreeTest, TestCase1) {
  // Tree:    1
  //         / \
  //        2   3
  //           / \
  //          4   5
  TreeNode* root = createTree({1, 2, 3, std::nullopt, std::nullopt, 4, 5});

  // Convert both trees to vectors and compare
  auto expected = treeToVector(root);

  std::string serialized = codec.serialize(root);
  TreeNode* deserialized = codec.deserialize(serialized);

  auto output = treeToVector(deserialized);
  EXPECT_EQ(output, expected);

  auto serialized2 = codec.serialize2(root);
  auto deserialized2 = codec.deserialize2(serialized);

  auto output2 = treeToVector(deserialized);
  EXPECT_EQ(output2, expected);

  deleteTree(root);
  deleteTree(deserialized);
  deleteTree(deserialized2);
}

TEST_F(SerializeAndDeserializeBinaryTreeTest, TestCase2) {
  TreeNode* root = nullptr;

  std::string serialized = codec.serialize(root);
  EXPECT_EQ(serialized, "");

  TreeNode* deserialized = codec.deserialize(serialized);
  EXPECT_EQ(deserialized, nullptr);

  std::string serialized2 = codec.serialize2(root);
  EXPECT_EQ(serialized2, "");

  TreeNode* deserialized2 = codec.deserialize2(serialized2);
  EXPECT_EQ(deserialized2, nullptr);
}