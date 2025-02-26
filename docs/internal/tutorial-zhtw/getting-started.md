# 快速開始

## 安裝

??? Note "Windows 使用者別怕"
    以下的終端機指令除了 macos/Linux shell 以外，在 Windows 的 PowerShell 中也可以正常運作。

    若 `pip` 和 `mkdocs` 指令無法使用，請將 Python 安裝路徑中的 `Scripts` 目錄加入系統環境變數 `Path` 中。
    例如若 Python 安裝在 `C:\path\to\Python311`，則需要將 `C:\path\to\Python311\Scripts` 加入 `Path` 中。

官方最推薦的安裝方式是使用 `pip` 安裝，以下會以此方式為主。關於其他安裝方式，請直接參考 [官方文件](https://squidfunk.github.io/mkdocs-material/getting-started/)。

```bash
pip install mkdocs-material
```

透過以上指令，`pip` 會幫我們把所有的相關套件 (如 `mkdocs`) 都安裝好，不需要擔心。安裝完成後，可以先建立一個基本的專案，並用 `mkdocs serve` 確認效果。

```bash
mkdocs new my-docs
cd my-docs
mkdocs serve
```

透過上述指令，`mkdocs` 會在 `my-docs` 目錄下建立一個基本的專案。

接著在專案目錄中，`mkdocs serve` 可以啟動一個測試用的伺服器，
預設會在 `http://localhost:8000` 開啟。我們對專案做的所有更動（包含 Markdown 文件和設定檔等）都會即時反映在該網址上，
並自動重新載入，方便我們即時查看效果。在終端機中，`mkdocs` 也會顯示目前的建置狀態（有時會花比較多時間），或是語法、設定錯誤等等。

## 專案基本概念

### 目錄結構

一個簡易的 `mkdocs` 專案結構大致如下：

```
my-docs/
├── docs/
│   ├── assets/
│   │   └── images/
│   │       └── logo.png
│   ├── index.md
│   └── section_1/
│       ├── index.md
│       ├── page_1.md
│       └── page_2.md
│       └── ...
└── mkdocs.yml
```

- `mkdocs.yml`: 是 `mkdocs` 的設定檔，包含要啟用哪些功能、外觀配色、導覽列等等。
- `docs/`: 可以想像成 `mkdocs` 的原始碼目錄，**所有要出現在網頁中的文件、圖片、CSS 等，都要放在這個目錄下**。
    `mkdocs` 會自動將 `docs` 目錄下的所有 Markdown 文件編譯成靜態網頁。
- `docs/section_1/`: 放在 `docs` 的子目錄中的 Markdown 文件，在網站上也會被放在子目錄中。
- `docs/assets/`: 其實並沒有硬性規定要建立這個目錄，但把靜態資源（如圖片、CSS 等）放在這個目錄下是常見的作法，
    這樣專案目錄會比較乾淨。

這個專案渲染出來的網頁，和 Markdown 文件的對應關係大致如下（假設網頁被放到 `https://www.example.com/` ）：

| 網址                                      | 對應的 Markdown 文件          |
| :---------------------------------------- | :--------------------------- |
| https://www.example.com/                  | docs/index.md                |
| https://www.example.com/section_1/        | docs/section_1/index.md      |
| https://www.example.com/section_1/page_1/ | docs/section_1/page_1.md     |
| https://www.example.com/section_1/page_2/ | docs/section_1/page_2.md     |


### 設定檔

如上所述 `mkdocs.yml` 是 `mkdocs` 的設定檔，建議初學者可以先直接複製既有專案的設定檔
（如[這個範例](https://github.com/avermedia-hanson/some-video-sdk)），只修改以下幾個部分：

- `site_name`: 網站名稱
- `site_url`: 網站 URL（需要先確認這份文件未來打算放在哪個位置，如果沒設定好的話，有些連結會無法正確運作）
- `nav`: 用來定義網站的「導覽列」（navigation），導覽列視設定而定，可能會出現在網頁的左側或上側。

以 [目錄結構](#目錄結構) 中的專案為例，`nav` 的設定方式大致如下：

```yaml
nav:
  - Home: index.md
  - My Section 1:
    - section_1/index.md
    - My Page 1: section_1/page_1.md
    - My Page 2: section_1/page_2.md
```

如此你就會看到導覽列中有兩個 top-level 的連結，分別是 `Home` 和 `My Section 1`，
`My Section 1` 底下會有兩個子連結 `My Page 1` 和 `My Page 2`，而 `My Section 1` 本身
也會連結到 `section_1/index.md`。

## 撰寫 Markdown 文件

這邊僅提供一個簡單的 Markdown 文件範例：

```markdown
# Your title

Some text at the beginning of the document.

## Chapter 1

Some text at the beginning of Chapter 1.

### Section 1.1

Some text at the beginning of Section 1.1.

- Item 1
- Item 2
- Item 3
```

!!! tips
    雖然還有比 `h3` (`###`) 層級更低的標題（如 `####`），但一般來說前三層的效果會是最明顯的。

關於 Markdown 語法，這邊不多贅述，請直接參考 [如何撰寫 Markdown 文件](markdown.md)。

## 發布

關於發布，由於我們希望文件都能包含版本資訊，因此請直接參考 [建立不同版本的文件](versioning.md)。

## 其他注意事項

- 如果需要產生離線文件（不是放在線上），請務必參考 [設定 MkDocs 專案](configuration.md) 中有關離線文件的說明，否則網頁間的連結會無法正常運作。
- 熟悉 Markdown 語法的各位請特別注意，在 `mkdocs-material` 的語法中，所有巢狀列表使用的縮排都是 4 個空白，而不是常見的 2/3 個。
