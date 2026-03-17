# ⚠️ Multi-Language Gotchas (C++ vs Java vs C#)

A growing list of common operations that behave differently across C++, Java, and C#.  
Useful for competitive programmers and multi-language developers.

---

## 📊 Comparison Table

| Topic | C++ | Java | C# |
|------|-----|------|-----|
| Post-decrement in loop `while(t--)` | ✅ Works | ❌ Error (must be boolean) | ❌ Error (must be boolean) |
| Condition type in `if/while` | `int` allowed (0 = false) | Only `boolean` | Only `bool` |
| Implicit double → int `int a = 20.5;` | ✅ Allowed (truncates) | ❌ Compile error | ❌ Compile error |
| Integer division `5/2` | `2` | `2` | `2` |
| String comparison | `==` works (`std::string`) | ❌ `==` compares reference → use `.equals()` | ✅ `==` compares value |
| Memory management | Manual (`new/delete`) | Automatic (GC) | Automatic (GC) |
| Pointers | ✅ Full support | ❌ Not allowed | ⚠️ Limited (`unsafe`) |
| Array size | Fixed | Fixed | Fixed |
| Dynamic arrays | `vector` | `ArrayList` | `List<T>` |
| Default values | Garbage (uninitialized) | Default (0, null, false) | Default (0, null, false) |
| Multiple inheritance | ✅ Supported | ❌ Not allowed | ❌ Not allowed |
| Operator overloading | ✅ Yes | ❌ No | ✅ Yes |
| Switch with string | ❌ (before C++20) | ✅ Yes | ✅ Yes |
| Pass by reference | ✅ (`&`) | ❌ (pass by value only) | ✅ (`ref`, `out`) |
| Struct behavior | Like class | ❌ No real struct | ✅ Value type |
| Checked exceptions | ❌ No | ✅ Must handle | ❌ No |
| Type inference | `auto` | `var` | `var` |
| Boolean literals | `true/false` | `true/false` | `true/false` |

---

