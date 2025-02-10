@page getting-started Getting Started
<!-- # Getting Started -->

This getting started guide is also a markdown file rendered by Doxygen.

<!-- The special link `[TOC]` will generate a table of contents for the current file just like the `@tableofcontents` command in Doxygen. -->
[TOC]

## Markdown features (extensions)

### Bullets

- Item 1
- Item 2
- Item 3

### Numbered list


1. Item 1
2. Item 2
3. Item 3

### Code block

It looks like the highlighting works well for C++ and Python.

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

```python
from some_audio_sdk import SomeClass

if __name__ == "__main__":
    some_class = SomeClass()
    some_class.do_something()
```

### Inline code

By default, the inline code like `int a = 1;` does not have a background color. You will have to add a custom stylesheet (a CSS file) and define the styles for the `code` element yourself, which is too deep so I am not going to the details here.

### Table

Markdown tables, along with the column alignment, are supported.

| Align left | Align center | Align right |
| :--------- | :----------: | ----------: |
| Cell 1     | Cell 2       | Cell 3      |
| Cell 4     | Cell 5       | Cell 6      |

## Non-markdown Doxygen features

@note This is a note.

@warning This is a warning.

@attention This is an attention.
