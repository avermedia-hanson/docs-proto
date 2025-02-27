# Material for MkDocs 擴充語法

??? info "給不熟悉 Markdown 基本語法的讀者"

    建議不熟悉 Markdown 基本語法的讀者，可以先閱讀 [基本語法](basic.md) 這個章節。

Material for MkDocs 提供了非常豐富的功能，以下會簡單介紹幾個筆者較常用的功能。需要更詳細的說明可以參考 [Material for MkDocs 的官方文件](https://squidfunk.github.io/mkdocs-material/reference/)。

!!! tip "關於 `mkdocs.yml` 的設定"

    以下介紹的擴充語法，大多都需要在設定檔中特別啟用某些設定才行。建議初學者可以直接複製 [這個範例](https://github.com/avermedia-hanson/some-video-sdk) 中 `mkdocs.yml` 的 `theme`、`plugins`、`markdown_extensions`、`extra` 等部分，以啟用這份教學提到的所有功能。（然後你就可以暫時無視所有關於 `mkdocs.yml` 的設定說明了）

## 表格

要啟用表格語法，需要在 `mkdocs.yml` 中加入以下設定：

```yaml
markdown_extensions:
  - tables
```

表格的語法非常直觀，並可以透過第二列的冒號位置來指定該欄的對齊方式，請見範例：

```markdown
| Default | Left-aligned | Right-aligned | Center-aligned |
| ------- | :----------- | ------------: | :------------: |
| 1       | 2            | 3             | 4              |
| 5       | 6            | 7             | 8              |
```

??? example "Preview"

    | Default | Left-aligned | Right-aligned | Center-aligned |
    | ------- | :----------- | ------------: | :------------: |
    | 1       | 2            | 3             | 4              |
    | 5       | 6            | 7             | 8              |


## 頁籤 (tabs)

筆者個人認為非常實用的功能，可以將不同情境適用的內容放在同一個頁面中，並有好看的外觀方便切換。可以應用的地方有：

- 相同 library 在不同系統的安裝方式
- 相同 library 在不同語言的 API 用法
- etc.

要啟用此功能，需要在 `mkdocs.yml` 中加入以下設定：

```yaml
markdown_extensions:
  - pymdownx.superfences
  - pymdownx.tabbed:
      alternate_style: true
```

每個 tab 在 Markdown 中看起來就像是各自獨立的區塊，這些區塊由 `=== "Tab Title"` 來開始，區塊內容則需要往右縮排（4 個空白），請見範例如下：

````markdown
=== "C++"
    ```cpp
    #include <iostream>

    int main() {
        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
    ```

=== "Python"
    ```python
    if __name__ == "__main__":
        print("Hello, World!")
    ```

=== "Rust"
    ```rust
    fn main() {
        println!("Hello, World!");
    }
    ```
````

??? example "Preview"

    === "C++"
        ```cpp
        #include <iostream>

        int main() {
            std::cout << "Hello, World!" << std::endl;
            return 0;
        }
        ```

    === "Python"
        ```python
        if __name__ == "__main__":
            print("Hello, World!")
        ```

    === "Rust"
        ```rust
        fn main() {
            println!("Hello, World!");
        }
        ```

## 各種提示方塊（admonition）

各位可能有注意到，這個頁面上存在著許多不同顏色的方塊，這些提示方塊在 `mkdocs-material` 中稱為 admonition。

要啟用此功能，需要在 `mkdocs.yml` 中加入以下設定：

```yaml
markdown_extensions:
  - admonition
  - pymdownx.details
  - pymdownx.superfences
```

### 方塊語法 - 依行為分類

要使用方塊時，首先要決定的是方塊的行為，有以下幾種：

```markdown
!!! info "這是最基本的、固定的方塊"

    最基本的固定方塊，會佔據 100% 的寬度。

??? info "這是可摺疊的方塊"

    可以摺疊起來的方塊，預設是摺疊狀態，可以從右上角展開。

???+ info "這是預設展開的可摺疊方塊"

    可以摺疊起來的方塊，但預設是展開狀態，可以從右上角摺疊。

!!! info inline end "跟文字並排、靠右的方塊"

    這會變成一個被放到右邊的小方塊，這以下的文字內容會跑到方塊左邊。

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.

Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

!!! info inline "跟文字並排、靠左的方塊"

    這會變成一個被放到左邊的小方塊，這以下的文字內容會跑到方塊右邊。

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.

Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
```

??? example "Preview"
    !!! info "這是最基本的、固定的方塊"

        最基本的固定方塊，會佔據 100% 的寬度。

    ??? info "這是可摺疊的方塊"

        可以摺疊起來的方塊，預設是摺疊狀態，可以從右上角展開。

    ???+ info "這是預設展開的可摺疊方塊"

        可以摺疊起來的方塊，但預設是展開狀態，可以從右上角摺疊。

    !!! info inline end "跟文字並排、靠右的方塊"

        這會變成一個被放到右邊的小方塊，這以下的文字內容會跑到方塊左邊。

    Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.

    Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

    !!! info inline "跟文字並排、靠左的方塊"

        這會變成一個被放到左邊的小方塊，這以下的文字內容會跑到方塊右邊。

    Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.

    Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

### 方塊類型 - 依外觀分類

Material for MkDocs 提供了許多不同外觀的方塊，每種方塊各有不同的圖示、顏色、以及預設標題，可以依照需求選擇使用。方塊類型由 `!!!`（或 `???` 等都可以）後的第一個關鍵字決定，請見範例如下：

```markdown
!!! tip

    這是 `tip` 方塊。

??? warning

    這是 `warning` 方塊。

???+ bug

    這是 `bug` 方塊。
```

??? example "Preview"
    !!! tip

        這是 `tip` 方塊。

    ??? warning

        這是 `warning` 方塊。

    ???+ bug

        這是 `bug` 方塊。

由於空間有限，這邊僅將 Material for MkDocs 提供的方塊類型列出：

- `note`（預設類型，當關鍵字無法辨識時會套用此類型）
- `abstract`
- `info`
- `tip`
- `success`
- `question`
- `warning`
- `failure`
- `danger`
- `bug`
- `example`
- `quote`

需要查看這些方塊的外觀或更詳細的說明，可以參考 [Material for MkDocs 的官方文件](https://squidfunk.github.io/mkdocs-material/reference/admonitions/)。

## 卡片排版 (card grids)

這邊簡單介紹一下現代文件很愛用的排版方式：卡片。它的本質其實很簡單，就只是把內容排成格狀，再加上外框、以及 hover 動畫(1)而已。
{ .annotate }

1.  hover 動畫指的是，當滑鼠移到網頁元素上時，元素會產生的動畫效果。

要啟用此功能，需要在 `mkdocs.yml` 中加入以下設定：

```yaml
markdown_extensions:
  - attr_list
  - md_in_html
```

在建立卡片時，首先需要用如下的 HTML `<div>` 元素包住卡片內容，而卡片內容其實就只是簡單的 Markdown 列表而已：

```html
<div class="grid cards" markdown>

- 卡片標題

    ---

    以上使用分隔線來凸顯標題。

- ### 更大的標題

    ---

    就和一般的列表一樣，你可以把其中一段文字變成 `<h3>` 標題。

- 其實卡片也不見得要用上面那種樣式
- :simple-markdown: 加上 icon 的效果看起來也不錯

</div>
```

??? example "Preview"

    <div class="grid cards" markdown>

    - 卡片標題

        ---

        以上使用分隔線來凸顯標題。

    - ### 更大的標題

        ---

        就和一般的列表一樣，你其實可以把卡片標題變成 `<h3>`，但要注意這個 `<h3>` 也會出現在網頁目錄中……。

    - 其實卡片也不見得要用上面那種樣式
    - :simple-markdown: 加上 icon 的效果看起來也不錯

    </div>

## 更多種列表

除了基本語法提供的列表以外，Material for MkDocs 還提供了另外兩種列表，可以透過以下設定啟用：

```yaml
markdown_extensions:
  - def_list
  - pymdownx.tasklist:
      custom_checkbox: true
```

### 定義列表（Definition Lists）

定義列表提供一個方便的語法，讓名詞和其定義一目瞭然，適合用在說明參數、選項等等。其語法如下

```markdown
`--my-option`

:   Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.

My Parameter Name

:   Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
```

??? example "Preview"

    `--my-option`

    :   Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.

    My Parameter Name

    :   Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.

### 任務列表（Task Lists）

這種列表也常見於 GitHub、HackMD 等服務中，用來建立一個任務清單。其語法如下：

```markdown
- [ ] 任務 1
- [x] 任務 2
- [ ] 任務 3
```

??? example "Preview"

    - [ ] 任務 1
    - [x] 任務 2
    - [ ] 任務 3

## 註解 (Annotation)

Material for MkDocs 提供的註解功能，讓我們可以在段落中的任何位置插入註解，適合用在你想補充說明一件事，但又不希望這件事太佔空間的時候(1)。
{ .annotate }

1.  比如當你突然因為某種謎之衝動突然很想插入一大段隨機拉丁文的時候 :face_with_open_eyes_and_hand_over_mouth:

    Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

要啟用此功能，需要在 `mkdocs.yml` 中加入以下設定：

```yaml
markdown_extensions:
  - attr_list
  - md_in_html
  - pymdownx.superfences
```

使用註解功能的方式稍微比較複雜一點。首先在需要插入註解的地方，在「最外側 Markdown 區塊」的最後加入一行 `{ .annotate }` 如下：

```markdown
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
{ .annotate }
```

這個語法會讓這個段落對應的 HTML 元素被加上 `annotate` 這個 class，接著我們就可以在段落中用 `(1)` 插入註解，並在後面用 `1.  ` 來完成註解內容。語法如下：

```markdown
Lorem ipsum dolor sit amet, consectetur(1) adipiscing elit, sed do eiusmod tempor(2) incididunt ut labore et dolore magna aliqua.
{ .annotate }

1.  這是放在 consectetur 後面的註解
2.  這是放在 tempor 後面的註解
```

??? example "Preview"

    Lorem ipsum dolor sit amet, consectetur(1) adipiscing elit, sed do eiusmod tempor(2) incididunt ut labore et dolore magna aliqua.
    { .annotate }

    1.  這是放在 consectetur 後面的註解
    2.  這是放在 tempor 後面的註解

## 腳註 (footnotes)

這個功能讓我們可以在文章中加入腳註，腳註的內容會出現在文章的最後面(1)，並且會附帶連結，讓我們可以在文章和腳註之間跳來跳去。要啟用此功能，需要在 `mkdocs.yml` 中加入以下設定：
{ .annotate }

1.  Material for MkDocs 其實也有讓腳註加上 hover 效果（當滑鼠移到腳註標籤上時，會顯示出腳註內容）的功能，不過這個功能是贊助者 :material-heart: 專屬的 :disguised_face:

```yaml
markdown_extensions:
  - footnotes
```

開啟功能後，我們可以在文件的任何地方使用 `[^1]` 插入腳註(1):
{ .annotate }

1.  這裡面的數字只是方便辨識（腳註的 ID），實際在產生網頁的時候會根據腳註出現的順序自動編號。但要注意這邊使用的數字不能重複，否則可能會有腳註內容被覆蓋掉。

```markdown
Lorem ipsum dolor sit amet, consectetur[^3] adipiscing elit, sed do eiusmod tempor[^4] incididunt ut labore et dolore magna aliqua.
```

而腳註內容可以在文件的任何地方補上，語法如下

```markdown
[^3]: 這是放在 consectetur 後面的腳註
[^4]:
    這是放在 tempor 後面的腳註，我們可以利用縮排方式把好幾行文字都塞進來，但只能有一個段落（中間不能空行）。
    以下假文章產生自[這邊](https://pinkylam.me/generator/chinese-lorem-ipsum/)：比化英交至園聽金想五師「眼水旦消羊雞北」很水各找那在良旁見林昌只祖雲同方，放員衣？古林哥只夕歡道重示媽信要采原犬做外裏意包，尼蝴祖何抄合高里玉坐笑從蝶什皮飯固法就九，視己又蝶苦隻尾快見。
```

??? example "Preview"

    Lorem ipsum dolor sit amet, consectetur[^3] adipiscing elit, sed do eiusmod tempor[^4] incididunt ut labore et dolore magna aliqua.

    [^3]: 這是放在 consectetur 後面的腳註
    [^4]:
        這是放在 tempor 後面的腳註，我們可以利用縮排方式把好幾行文字都塞進來，但只能有一個段落（中間不能空行）。
        以下假文章產生自[這邊](https://pinkylam.me/generator/chinese-lorem-ipsum/)：比化英交至園聽金想五師「眼水旦消羊雞北」很水各找那在良旁見林昌只祖雲同方，放員衣？古林哥只夕歡道重示媽信要采原犬做外裏意包，尼蝴祖何抄合高里玉坐笑從蝶什皮飯固法就九，視己又蝶苦隻尾快見。

## Icons

Material for MkDocs 提供了許多不同的圖示（包含 emoji 等），可以透過以下設定啟用：

```yaml
markdown_extensions:
  - attr_list
  - pymdownx.emoji:
      emoji_index: !!python/name:material.extensions.emoji.twemoji
      emoji_generator: !!python/name:material.extensions.emoji.to_svg
```

使用方式也很簡單，用 `:` 把圖示名稱給包起來，`mkdocs-material` 就可以辨識它並轉換成圖示了：

```markdown
- :material-arrow-up-left: 彎彎的箭頭
- :simple-cplusplus: C++ 圖示
- :simple-pytorch: PyTorch 圖示
```

??? example "Preview"

    - :material-arrow-up-left: 彎彎的箭頭
    - :simple-cplusplus: C++ 圖示
    - :simple-pytorch: PyTorch 圖示

據稱，Material for MkDocs 提供了超過 10000 種圖示，可以在 [官方文件](https://squidfunk.github.io/mkdocs-material/reference/icons-emojis/) 進行查詢。
