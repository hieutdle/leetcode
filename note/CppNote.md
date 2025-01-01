# 217

```cpp
s.find(nums[i]) != s.end()
```

`s.find(value)` searches the `std::unordered_set` for the element value. It returns an iterator:

* If the element exists in the set, the iterator points to that element.
* If the element does not exist, the iterator is equal to `s.end()`.
* `s.end()` is a special iterator that points to the past-the-end position of the set.

```cpp
!s.insert(num).second
```

* `s.insert(num)` tries to insert the element num into the set `s`.
* It returns a `std::pair`:
  * First element (`iterator`): An iterator pointing to the position of the element in the set.
  * Second element (`bool`): A boolean that indicates whether the insertion was successful:
    * `true`: The element was successfully inserted because it didn’t already exist in the set.
    * `false`: The insertion failed because the element already existed in the set.

