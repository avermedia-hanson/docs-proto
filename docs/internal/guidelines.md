# 文件撰寫規範

## 一、文件標題

### (1) 導覽列 (`nav`) 中的標題長度，原則上請保持在 30 個字元以內。

### (2) 文件的標題，請盡量與導覽列保持一致。

如有必要，可以擴寫導覽列的標題，例如將 "How to build" 擴寫成 "How to build GStreamer app on QL601"，但仍以簡潔清晰為原則。

## 二、軟體文件內容

### (1) 軟體專案的文件必須要提供隨處可見（如顯示在頂端列）的版本號

Doxygen 需要在 Doxyfile 中設定，MkDocs 請看版本管理教學（待補）。

### (2) 每個專案的入口頁，請簡述文件中有哪些內容，讓使用者有大概概念

可以參考[這邊](index.md)用卡片來排版

### (3) 每個專案的文件都必須要提供一份 "Getting Started" 文件

其中軟體專案的 "Getting Started" 需要包含以下內容：

-   安裝及環境設置
-   (非必要) 可以快速確認安裝是否成功的小程式（如 `qpycam-hello`）
-   hello-world 等級的簡易範例「程式碼」

上述內容可以寫在同一個頁面中，也可以分成數個頁面呈現。

### (4) （非必要）每個專案的文件可以分成以下三類

| 分類名稱      | 在 MkDocs 中的檔案位置        | 說明 |
| ------------- | ----------------------------- | -------------------------- |
| User Guide    | `docs/` 或 `docs/user-guide/` | 無法分到以下兩類的所有文件。建議把 "Getting Started" 放在此分類下的第一個頁面。 |
| Examples      | `docs/examples/`              | 包含「完整」程式碼的範例。 |
| API Reference | `docs/api/`                   | 針對 API 的詳細說明。     |

但若文件數量不足，可以暫時不進行分類。

### (5) "Examples" 分類中的文件規範

放在 "Examples" 分類中的文件，需要遵守以下規範：

-   所有範例都必須能夠編譯成可執行檔或函式庫
-   一個範例可以包含多個程式碼檔案
-   程式碼可以重點說明，不用全部嵌入文件，但完整檔案需要放在 SDK 中，且檔案位置需要在文件中註明

其餘（如是否註解、字數等）則沒有硬性規定。不符合以上規範的文件，請放在 User Guide。

### (6) "API Reference" 分類中的文件規範

放在 "API Reference" 分類中的文件，需要遵守以下規範：

-   function 的文件必須包含：
    -   簡述 function 功能
    -   簡述每個 argument 的功能
    -   簡述每個 return value 為何
    -   (非必要) 列出這個 function 可能會丟出的 exceptions
    -   (非必要) 使用此 function 的簡易 example

-   class 必須包含：
    -   簡述 class 功能
    -   (C/C++) 簡述每個 public member 的功能（如果有）
    -   (Python) 簡述每個 "property" 功能（一般的 attribute 不用）
    -   指向每個 method 文件的連結
    -   (非必要) 除了文件連結，也可以提供 method 功能簡述

可以參考 Matplotlib 文件 [Matplotlib API Reference](https://matplotlib.org/stable/api/index).

## 三、MkDocs 專案相關

### (1) 不要在主要的設定檔中使用 `offline` plugin

主要的 MkDocs 設定檔請以線上發布為前提，不要使用 `offline` plugin。

### (2) 資料夾與檔案命名使用小寫的 "kebab-case"

由於 MkDocs 專案中的路徑會直接被轉成網址，因此資料夾與檔案命名採用小寫的 "kebab-case" 以符合常見慣例：

-   全部使用小寫
-   使用連字號（hyphen）連接單字
-   不要在開頭或結尾使用連字號

## 四、Markdown 撰寫風格

### (1) 固定使用 4 個空格進行縮排

這是 Python-Markdown 軟體的限制，2 或 3 個空格可能會導致錯誤結果。

??? example "使用 2 個空格進行縮排可能產生的問題"

    以下例子中，由於使用 2 個空格進行縮排，所以導致原本有三層的列表，變成只有兩層。

    === "Markdown"

        ```markdown
        - In a nested list:
          - Don't do this. This will not be rendered correctly.
            - Do this instead.
        ```

    === "Preview"

        - In a nested list:
          - Don't do this. This will not be rendered correctly.
            - Do this instead.

    使用 4 個空格進行縮排，則不會有這個問題。

    === "Markdown"

        ```markdown
        -   First level
            -   Second level
                -   Third level
        ```

    === "Preview"

        -   First level
            -   Second level
                -   Third level

    之所以把 `- ` 改成 `-   ` 單純只是為了可讀性（讓文字內容和縮排對齊），實際上多餘的空格會被忽略，所以功能上沒有任何差異。

### (2) 避免在標題中使用強調語法

請避免在標題中使用強調語法（包含粗體、斜體、底線等），因為這可能會導致不同頁面之間的標題風格不一致。

??? example

    !!! danger "Don't do this"

        ```markdown title="Markdown"
        # **Some Important Heading**
        ```

    !!! success "Do this instead"

        ```markdown title="Markdown"
        # Some Important Heading
        ```

    !!! info "Acceptable"

        只強調標題中的某些字是可以接受的，但一般來說也不建議。

        ```markdown title="Markdown"
        # Some **Important** Heading
        ```

若有必要修改標題風格，請使用自定義 CSS 來進行全域的修改。

??? example "自定義 CSS"

    ```css title="assets/stylesheets/extra.css"
    .md-typeset h1 {
        font-weight: 700;
    }
    ```

### (3) 在 Markdown 區塊之間添加空白行

一份 Markdown 文件，可以被視為是一個個區塊組成的，這個區塊可以是一個段落、一個標題、一個列表項目、一個程式碼區塊等等。

在這些區塊之間添加空白行，除了可以讓文件更易讀（Markdown 設計的初衷就是讓原始碼也變得易讀），另外也能避免一些預期外的行為，因為沒有空白行時，相鄰的區塊可能會被視為同一個區塊。

??? example "沒有空白行可能產生的問題"

    在以下例子中，由於列表和段落間沒有空行，所以段落被當成列表項目的一部分了。

    === "Markdown"

        ```markdown title="Markdown"
        - 這是列表項目
        這是一個段落才對。
        ```

    === "Preview"

        - 這是列表項目
        這是一個段落才對。

    只要在列表項目和段落間添加一個空白行，就能避免這個問題。

    === "Markdown"

        ```markdown title="Markdown"
        - 這是列表項目

        這是一個段落才對。
        ```

    === "Preview"

        - 這是列表項目

        這是一個段落才對。

雖然最保險的作法是每個區塊都添加空白行，但確實也有些時候空白行是多餘的，例如列表項目只有一行時。以下是個兼顧可讀性又正確的例子：

??? example

    ````markdown title="Markdown"
    # Heading

    Add a blank line between the heading and the paragraph, the paragraph and the code block, etc.

    ```sh
    echo "Hello, world!"
    echo "Bye, world!"
    ```

    - Add a blank line before the list.
    - But if each list item only contains a single line,
    - it is fine to not add any blank lines.

    -   If the list item is very complex, including code blocks:

        ```python
        def hello():
            print("Hello, world!")
        ```

    -   Or admonitions:

        !!! note

            Some random notes.

    -   Or tables or whatever else. It is recommended to write the Markdown code in this way.

        | Left   | Center | Right  |
        | :----- | :----: | -----: |
        | Cell 1 | Cell 2 | Cell 3 |
        | Cell 4 | Cell 5 | Cell 6 |
    ````

### (4) 避免使用 HTML `<img>` 來插入本地圖片

假設我們的文件結構如下：

```
docs/
├── examples/
│   ├── use-case-1.md
│   └── images/
│       └── screenshot.png
```

那麼我們應該使用以下 Markdown 語法以在 `use-case-1.md` 中插入 `screenshot.png`：

```markdown title="use-case-1.md"
![alt text](images/screenshot.png){ #some-id .some-class width="75%" }
```

其中 `{ #some-id .some-class width="75%" }` 是 Python-Markdown 的 "attribute list" 語法，相當於 HTML `<img>` 中的 `id="some-id" class="some-class" width="75%"`。

??? info "為什麼要避免使用 raw HTML `<img>` tag?"

    在 MkDocs 中使用 HTML 時，相對路徑會出現一些小問題。因為 `docs/examples/use-case-1.md` 會被渲染成 `/examples/use-case-1/index.html`，所以對於這個 HTML 檔來說，這張圖片的相對路徑會從 `images/screenshot.png` 變成 `../images/screenshot.png`，即使 Markdown 檔案和 `images/` 資料夾實際上位在同一個目錄。

    只要有注意上述的相對路徑問題，`<img>` 仍然是可以使用的。但由於 HTML 能做到的所有功能，都能藉由 "attribute list" 語法達成，所以原則上還是建議使用 Markdown 語法，避免路徑的不一致造成閱讀上的困擾（語法也比較簡潔）。

### (5) 避免使用 HTML 來撰寫標題

使用 HTML 來寫標題（如 `<h1>`、`<h2>` 等）雖然不像圖片一樣會有路徑問題，但 MkDocs 在生成目錄時會漏掉它們，導致這些標題不會出現在目錄中。
