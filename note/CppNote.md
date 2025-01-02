# Cpp Leetcode note

## 217

### find()

```cpp
s.find(nums[i]) != s.end()
```

`s.find(value)` searches the `std::unordered_set` for the element value. It returns an iterator:

- If the element exists in the set, the iterator points to that element.
- If the element does not exist, the iterator is equal to `s.end()`.
- `s.end()` is a special iterator that points to the past-the-end position of the set.

```cpp
!s.insert(num).second
```

### insert()

- `s.insert(num)` tries to insert the element num into the set `s`.
- It returns a `std::pair`:
  - First element (`iterator`): An iterator pointing to the position of the element in the set.
  - Second element (`bool`): A boolean that indicates whether the insertion was successful:
    - `true`: The element was successfully inserted because it didn’t already exist in the set.
    - `false`: The insertion failed because the element already existed in the set.

## 49

### & as Reference and Address-of Operator

`&` as Reference:

When used in a declaration, & signifies that the variable is a reference to another object. A reference is essentially an alias for an existing object.

```cpp
int a = 10;
int &ref = a; // ref is a reference to a
ref = 20; // This changes a to 20
```

`&` as Address-of Operator:

When used in an expression, `&` fetches the memory address of a variable.

```cpp
int a = 10;
int *ptr = &a; // ptr stores the address of a
```

In for `(auto &n : m)`, the `&` means that `n` is a reference to each element of the container `m` during iteration. This avoids making a copy of the element.
If you use for `(auto n : m)` instead, `n` becomes a copy of each element. This can be less efficient for large or complex objects.

### [emplace_back vs. push_back](https://yasenh.github.io/post/cpp-diary-1-emplace_back)

- `push_back`: Adds a new element at the end of the container, after its current last element. The content of val is copied (or moved) to the new element.
- `emplace_back`: Inserts a new element at the end of the container, right after its current last element. This new element is constructed in place using args as the arguments for its constructor.

To be more clear, what will happen if we call push_back?

- A constructor will be called to create a temporary object.
- A copy of the temporary object will be constructed in the memory for the container. Note that the move constructor will be called if exist because the temporary object is an rvalue, otherwise the copy constructor should be called.
- The destructor will be called to destroy the temporary object after copy.

```cpp
class MyClass {
public:
    MyClass(int x, int y) : x_(x), y_(y) {
        std::cout << "Create class" << std::endl;
    }

    ~MyClass() {
        std::cout << "Destroy class" << std::endl;
    }

    // Copy Constructor
    MyClass(const MyClass& my_class) {
        std::cout << "Copy Constructor Called" << std::endl;
        x_ = my_class.x_;
    }

    // Move Constructor
    MyClass (MyClass&& my_class) noexcept {
        std::cout << "Move Constructor Called" << std::endl;
        x_ = std::move(my_class.x_);
    }

private:
    int x_ = 0;
    int y_ = 0;

};


int main() {
    std::vector<MyClass> vector;
    // Reserve space to avoid reallocation
    vector.reserve(2);

    std::cout << "\n--- push_back ---" << std::endl;
    vector.push_back(MyClass(1, 2));

    std::cout << "\n--- emplace_back ---" << std::endl;
    vector.emplace_back(1, 2);

    std::cout << "\n--- Finish ---" << std::endl;
    return 0;
}

```

Output:

--- push_back ---
Create Class
Move Constructor Called
Destroy Class

--- emplace_back ---
Create Class

--- Finish ---
Destroy Class
Destroy Class

`push_back` method calls the move constructor to make a copy and the destructor to destroy the temporary object. But `emplace_back` construct the object directly.

With the simple benchmark here, we notice that `emplace_back` is 7.62% faster than `push_back` when we insert 1,000,000 object (MyClass) into an vector.

```bash
Insert 1,000,000 objects.

--- push_back ---
push_back takes 0.00665344 seconds.

--- emplace_back ---
emplace_back takes 0.00614631 seconds.
```

Why not use emplace_back all the time?
We elaborate some of benefits of emplace_back method above, you might want to ask - Can we just get rid of the push_back method of containers?

1. Ambiguity of Constructor Calls

   ```cpp
   std::vector<std::vector<int>> vec1, vec2;
   // vec1.push_back(1000000); // compile error
   vec2.emplace_back(1000000);
   ```

- `push_back(1000000)` fails because push_back requires a fully constructed object. A single integer `(1000000)` is not a `std::vector<int>`.

- `emplace_back(1000000)` succeeds because emplace_back directly calls a constructor of `std::vector<int>` that takes an `integer`. This constructs a `std::vector<int>` of size `1,000,000`.

In some cases the transformation would be valid, but the code wouldn’t be exception safe. In this case the calls of `push_back` won’t be replaced.

```cpp
std::vector<std::unique_ptr<int>> v;
v.push_back(std::unique_ptr<int>(new int(0)))
```

This is because replacing it with `emplace_back` could cause a leak of this pointer if emplace_back would throw exception before emplacement (e.g. not enough memory to add a new element).

**Backwards compatibility with pre-C++11 compilers (no emplace_back).**

`push_back` always allows the use of **uniform initialization**, which I'm very fond of. For instance:

```cpp
struct aggregate {
    int foo;
    int bar;
};

std::vector<aggregate> v;
v.push_back({ 42, 121 });
```

On the other hand, `v.emplace_back({ 42, 121 });` will not work.
