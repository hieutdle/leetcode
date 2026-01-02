# leetcode-cpp

> <p style = "color:red"><strong>Please note that:</strong> my solutions are not necessarily optimized for efficiency in terms of time complexity or memory consumption. Instead, my focus is on providing solutions that are clear, and are easy for others to understand and learn from.</p>

I know these problems can be challenging, and I hope these solutions help guide anyone who is struggling to find their own solutions.

## Progress

**Blind 75: 25/75** (-1 premium, + 0167)

## Categories

### Array & Hashing (7/7) (-1 premium)

| No   | Title                        | Solution                                                                                          | Difficulty |
| ---- | ---------------------------- | ------------------------------------------------------------------------------------------------- | ---------- |
| 0217 | Contains Duplicate           | <sub><div align='center'>[✔️](src/arrays-hashing/0217_contains_duplicate.h)</div></sub>           | Easy       |
| 0242 | Valid Anagram                | <sub><div align='center'>[✔️](src/arrays-hashing/0242_valid_anagram.h)</div></sub>                | Easy       |
| 0001 | Two Sum                      | <sub><div align='center'>[✔️](src/arrays-hashing/0001_two_sum.h)</div></sub>                      | Easy       |
| 0049 | Group Anagrams               | <sub><div align='center'>[✔️](src/arrays-hashing/0049_group_anagrams.h)</div></sub>               | Medium     |
| 0347 | Top K Frequent Elements      | <sub><div align='center'>[✔️](src/arrays-hashing/0347_top_k_frequent_elements.h)</div></sub>      | Medium     |
| 0238 | Product of Array Except Self | <sub><div align='center'>[✔️](src/arrays-hashing/0238_product_of_array_except_self.h)</div></sub> | Medium     |
| 0128 | Longest Consecutive Sequence | <sub><div align='center'>[✔️](src/arrays-hashing/0128_longest_consecutive_sequence.h)</div></sub> | Medium     |

### Two Pointers (4/4)

| No   | Title                              | Solution                                                                                            | Difficulty |
| ---- | ---------------------------------- | --------------------------------------------------------------------------------------------------- | ---------- |
| 0125 | Valid Palindrome                   | <sub><div align='center'>[✔️](src/two-pointers/0125_valid_palindrome.h)</div></sub>                 | Easy       |
| 0167 | Two Sum II - Input Array Is Sorted | <sub><div align='center'>[✔️](src/two-pointers/0167_two_sum_ii_input_array_is_sorted.h)</div></sub> | Medium     |
| 0015 | 3Sum                               | <sub><div align='center'>[✔️](src/two-pointers/0015_3sum.h)</div></sub>                             | Medium     |
| 0011 | Container With Most Water          | <sub><div align='center'>[✔️](src/two-pointers/0011_container_with_most_water.h)</div></sub>        | Medium     |

### Sliding Window (4/4)

| No   | Title                                          | Solution                                                                                                            | Difficulty |
| ---- | ---------------------------------------------- | ------------------------------------------------------------------------------------------------------------------- | ---------- |
| 0121 | Best Time to Buy and Sell Stock                | <sub><div align='center'>[✔️](src/sliding-window/0121_best_time_to_buy_and_sell_stock.h)</div></sub>                | Easy       |
| 0003 | Longest Substring Without Repeating Characters | <sub><div align='center'>[✔️](src/sliding-window/0003_longest_substring_without_repeating_characters.h)</div></sub> | Medium     |
| 0424 | Longest Repeating Character Replacement        | <sub><div align='center'>[✔️](src/sliding-window/0424_longest_repeating_character_replacement.h)</div></sub>        | Medium     |
| 0076 | Minimum Window Substring                       | <sub><div align='center'>[✔️](src/sliding-window/0076_minimum_window_substring.h)</div></sub>                       | Hard       |

### Stack (1/1)

| No   | Title             | Solution                                                                      | Difficulty |
| ---- | ----------------- | ----------------------------------------------------------------------------- | ---------- |
| 0020 | Valid Parentheses | <sub><div align='center'>[✔️](src/stack/0020_valid_parentheses.h)</div></sub> | Easy       |

### Binary Search (2/2)

| No   | Title                                | Solution                                                                                                 | Difficulty |
| ---- | ------------------------------------ | -------------------------------------------------------------------------------------------------------- | ---------- |
| 0153 | Find Minimum in Rotated Sorted Array | <sub><div align='center'>[✔️](src/binary-search/0153_find_minimum_in_rotated_sorted_array.h)</div></sub> | Medium     |
| 0033 | Search in Rotated Sorted Array       | <sub><div align='center'>[✔️](src/binary-search/0033_search_in_rotated_sorted_array.h)</div></sub>       | Medium     |

### Linked List (6/6)

| No   | Title                            | Solution                                                                                                   | Difficulty |
| ---- | -------------------------------- | ---------------------------------------------------------------------------------------------------------- | ---------- |
| 0206 | Reverse Linked List              | <sub><div align='center'>[✔️](src/linked-list/0206_reverse_linked_list.h)</div></sub>                      | Easy       |
| 0021 | Merge Two Sorted Lists           | <sub><div align='center'>[✔️](src/linked-list/0021_merge_two_sorted_lists.h)</div></sub>                   | Easy       |
| 0141 | Linked List Cycle                | <sub><div align='center'>[✔️](src/linked-list/0141_linked_list_cycle.h)</div></sub>                        | Easy       |
| 0143 | Reorder List                     | <sub><div align='center'>[✔️](https://leetcode.com/problems/reorder-list/)</div></sub>                     | Medium     |
| 0019 | Remove Nth Node From End of List | <sub><div align='center'>[✔️](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)</div></sub> | Medium     |
| 0023 | Merge k Sorted Lists             | <sub><div align='center'>[✔️](src/linked-list/0023_merge_k_sorted_lists.h)</div></sub>                     | Hard       |

### Trees (1/1)

| No   | Title               | Solution                                                                       | Difficulty |
| ---- | ------------------- | ------------------------------------------------------------------------------ | ---------- |
| 0226 | Invert Binary Tree  | <sub><div align='center'>[✔️](src/trees/0226_invert_binary_tree.h)</div></sub> | Easy       |

## Project Structure

```
leetcode-cpp/
├── src/                    # Solution implementations (header files)
│   ├── arrays-hashing/
│   ├── binary-search/
│   ├── linked-list/
│   ├── sliding-window/
│   ├── stack/
│   ├── trees/
│   └── two-pointers/
├── test/                   # Google Test unit tests
│   ├── arrays-hashing/
│   ├── binary-search/
│   ├── linked-list/
│   ├── sliding-window/
│   ├── stack/
│   ├── trees/
│   └── two-pointers/
├── third_party/            # External dependencies (Google Test)
└── scripts/                # Utility scripts (formatting, linting)
```

## Building and Testing

### Prerequisites

- C++20 compatible compiler (GCC 10+, Clang 10+, or MSVC 2019+)
- CMake 3.14 or higher
- Make (optional, for using Makefile shortcuts)

### Install Dependencies

```bash
./install_dependencies.sh
```

### Build

```bash
# Using Make
make build

# Or using CMake directly
mkdir -p build
cd build
cmake ..
cmake --build .
```

### Run Tests

Run a specific test:

```bash
make 0001_two_sum_test
make 0001
```

Run all tests:

```bash
make check-tests
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
