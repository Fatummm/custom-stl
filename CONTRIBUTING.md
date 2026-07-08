# Contributing Guidelines

This document describes the rules of formatting commits, naming branches and pull requests

---

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

---

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