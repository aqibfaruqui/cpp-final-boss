# FileGuard

## Overview
`FileGuard` is a small C++ RAII wrapper for managing `FILE*` handles safely
- Ensures that files are automatically closed when a FILE* goes out of scope
- Prevents resource leaks even in the presence of exceptions

This pattern replicates the implementation and behaviour of `std::unique_ptr` for raw files

> **Note:** In modern C++, you would typically use `std::ifstream` / `std::ofstream` for file I/O, which already manage resources safely via RAII 

`FileGuard` is primarily an educational example :D

---

## Usage

Just compile and run:
```
clang++ -std=c++17 -fsanitize=address -g -O1 FileGuard.cpp -o FileGuard
./FileGuard
```

ASan will report nothing, because RAII is correctly closing the file