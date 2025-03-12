# 基本語法

!!! note

    對 Markdown 語法已有基本熟悉度的讀者，可以直接跳到 [Material for MkDocs 擴充語法](extensions.md) 章節。

這邊列舉的大部分都是基本的語法，符合 [CommonMark](https://commonmark.org/) 的規範，因此在絕大多數的 Markdown processor 中都能正常運作。本段參考 [Markdown Guide](https://www.markdownguide.org/basic-syntax/) 的內容，並挑選出較常用的語法進行介紹。

## 標題

標題的語法很簡單，就是在標題文字前方加上數個 `#` 符號，數量越多，標題的層級愈低（通常字體也愈小）。

```markdown
# Heading level 1

Lorem ipsum dolor sit amet, consectetur adipiscing elit.

## Heading level 2

Habitant cras sagittis rutrum; porttitor faucibus augue class venenatis penatibus.

### Heading level 3

Luctus justo aptent enim auctor, lacinia velit risus torquent.
```

??? example "Preview"

    由於在這個區塊內展示標題效果似乎會導致頁面目錄無法正常運作，因此就不在此展示了。:person_bowing:

<!--
??? example "Preview"

    # Heading level 1

    Lorem ipsum dolor sit amet, consectetur adipiscing elit.

    ## Heading level 2

    Habitant cras sagittis rutrum; porttitor faucibus augue class venenatis penatibus.

    ### Heading level 3

    Luctus justo aptent enim auctor, lacinia velit risus torquent.
-->

## 段落

在 Markdown 中，只要兩行文字間沒有空行，就會被視為同一個段落。
因此當你需要進入下一段時，記得插入空行。

```markdown
This
is
the first
paragraph.

This is the
second paragraph.
```

??? example "Preview"

    This
    is
    the first
    paragraph.

    This is the
    second paragraph.

??? warning "撰寫中文時請注意"

    從目前的實驗結果看起來，MkDocs 會將同個段落內的所有換行符號替換成空白。
    這符合英文的語法（每個單字都用空白隔開），但不適用於中文等東亞語言。
    因此當你撰寫中文時，若需要換行，請盡量讓每一行都結束在句號、逗號等標點符號，
    以讓空白看起來不那麼突兀。（當然你可以選擇不要換行）

    （上面段落中被插入了三個空白，可以找找看）

    === "Markdown"

        ```markdown
        中間會
        跑出空白
        ```

    === "Preview"

        中間會
        跑出空白

## 各種強調效果

Markdown 標準的強調效果有**粗體**、*斜體*、和***粗斜體***。其語法如下：

```markdown
**bold**

*italic*

***bold italic***
```

??? example "Preview"

    **bold**

    *italic*

    ***bold italic***

## 列表

列表分為有序列表和無序列表，語法如下：

```markdown
這是有序列表：

1. 第一項
2. 第二項

這是無序列表：

* 第一項
* 第二項

這也是無序列表：

- 第一項
- 第二項
```

??? example "Preview"

    這是有序列表：

    1. 第一項
    2. 第二項

    這是無序列表：

    * 第一項
    * 第二項

    這也是無序列表：

    - 第一項
    - 第二項

若你想要把段落加到列表中，只要使用 4 個空白來縮排，代表此段落是列表的一部分即可。

```markdown
- 第一項

    這是第一項的內文。

- 第二項

    ```
    這是第二項的內文。
    ```

    - 第二項的子項

        這是第二項的子項的內文。
```

??? example "Preview"

    - 第一項

        這是第一項的內文。

    - 第二項

        ```
        這是第二項的內文。
        ```

        - 第二項的子項

            這是第二項的子項的內文。

## 程式碼

程式碼分為行內程式碼（inline code）和程式碼區塊（code block），語法如下：

````markdown
這是一段 `inline code`。

以下則是一個程式碼區塊，並註明程式語言為 Python。

```python
print("Hello, World!")
```
````

??? example "Preview"

    這是一段 `inline code`。

    以下則是一個程式碼區塊，並註明程式語言為 Python。

    ```python
    print("Hello, World!")
    ```

!!! tips "關於程式碼 highlight"

    CommonMark 容許在程式碼區塊的開頭註明程式語言，但支援哪些語言、語言該怎麼拼（比如 `python` 能不能縮寫成 `py`），則由各家 Markdown processor 自行決定。`mkdocs-material` 預設使用 Pygments 來進行語法 highlight，其支援的語言列表可以參考 [Pygments 的文件](https://pygments.org/languages/)，這邊列出幾個常用的語言和常用別稱：

    | 語言       | 常用別稱                          |
    | :--------- | :------------------------------- |
    | Python     | `python`, `py`, `python3`, `py3` |
    | C          | `c`                              |
    | C++        | `cpp`, `c++`[^1]                 |
    | JavaScript | `js`, `javascript`               |

    [^1]: 需要注意支援的 C++ 別稱並不包含 `cxx`。

## 連結

只要在文字前後加上 `[` 和 `]`，並在後方加上 `(URL)`，就可以建立一個連結。

```markdown
[圓剛官網](https://www.avermedia.com)
```

??? example "Preview"

    [圓剛官網](https://www.avermedia.com)

!!! tip "MkDocs 文件間的連結"

    在 MkDocs 中，你可以使用相對路徑來建立通往其他 Markdown 文件的連結。根據目前的實驗結果，MkDocs 不支援使用絕對路徑來連結文件。

    === "Markdown"

        ```markdown
        [通往首頁的相對路徑](../../../index.md)
        ```

    === "Preview"

        <div class="result" markdown>
            [通往首頁的相對路徑](../../../index.md)
        </div>

## 圖片

圖片的語法和連結很相似，只是前面多了一個 `!` 符號，而 `[]` 內的文字則會成為圖片的替代文字。

??? note "替代文字"

    替代文字是當圖片無法顯示時，或是使用者將滑鼠移到圖片上時，會顯示的文字。其餘正常情況下，替代文字不會顯示出來。

```markdown
以下這張圖片是從一個隨機提供圖片的網站，透過 URL 取得的：

![網頁 URL: 一張隨機圖片](https://picsum.photos/400/200)

以下這張圖片是從本地取得的，位於 `docs/assets/images/logo.png`：

![本地相對路徑: 圓剛 logo](../../../assets/images/logo.png)
```

??? example "Preview"

    以下這張圖片是從一個隨機提供圖片的網站，透過 URL 取得的：

    ![網頁 URL: 一張隨機圖片](https://picsum.photos/400/200)

    以下這張圖片是從本地取得的，位於 `docs/assets/images/logo.png`：

    ![本地相對路徑: 圓剛 logo](../../../assets/images/logo.png)

## 分隔線

只要在新的一行輸入三個 `-` 符號，就可以建立一個分隔線。為了可讀性及相容性，建議分隔線前後各插入一行空行。

```markdown
下有分隔線

---

上有分隔線
```

??? example "Preview"

    下有分隔線

    ---

    上有分隔線
