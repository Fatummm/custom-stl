# Contributing Guidelines

This document describes the rules of formatting commits, naming branches and pull requests

# Table of Contents
- [Branch naming](#1-branch-naming)
- [Commit formatting](#2-commit-formatting)
- [Code Style](#3-code-style)
  - [Downloading `clang-format`](#downloading-clang-format)
  - [How to format one file](#formatting-one-file)
  - [How to format all files](#formatting-all-files)


## 1. Branch naming

All branches should be forked from `develop` and named by the prefix and branch specification on `kebab-case`:

**Template:** `<prefix>/<short task description>`

### Valid prefixes
* `feature/` - adding new functionality
* `hotfix/` - fixing bugs
* `refactor/` - changing the code structure without changing its logic
* `test/` - implementing/changing tests and benchmarks
* `docs/` - updating documentation or comments
* `ci/` - setting CI/CD (GitHub Actions, CMake)

**Example:** `feature/binary-search`, `docs/contributing`

**Note:** features can be united in some groups, e. g. `feature/bst/avl-tree`, `feature/containers/vector`


## 2. Commit formatting

Any commit should be designed in the following format:

**Template:** 
```text
<type>: <short changelog description>

[optional detailed description]

Signed-off-by: <name> <email>
```

**Note:** email is enclosed in angle brackets.

### Valid commit types
* `feat` - adding new functionality
* `fix` - fixing bugs
* `refactor` - optimizations and improving the readability of the code
* `docs` - documentation changing
* `chore` - updating building scripts, auxiliary files etc.

**Example**
```text
feat: add heap functionality

implement all methods of heap: insert, delete, increase 

Signed-off-by: fatum <lumik2006@gmail.com>
```

## 3. Code style

Code style of the project is based on the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) with some changes. The linter is enabled in GitHub Actions.
All changes you can find in `.clang-format` file in the root of the project.

### Downloading `clang-format`
If you want to format local files, firstly you should install utility for formatting:

For Linux:
```
sudo apt update
sudo apt install clang-format
```

For Windows:
```
winget install LLVM.LLVM
```

For macOS:
```
brew install clang-format
```

### Formatting one file

If you want to format one exact file, run from the root of the project:
```
clang-format -i path/to/file
```

### Formatting all files

If you want to format the whole C++ code in the project, firstly you should find all of `*.ipp/*.cpp/*.cc/*.c/*.hpp/*.h` files:
```
git ls-files -- '*.ipp' '*.cpp' '*.cc' '*.c' '*.hpp' '*.h' | xargs clang-format -i
```
**Note**: `xargs` is available only on Unix-like systems. To use this command on Windows, run it in **Git Bash** or **WSL**.