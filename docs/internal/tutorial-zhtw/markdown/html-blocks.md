# HTML 區塊

這邊的內容還很少，未來如果發現了其他好用的 HTML 區塊，會集中在這邊。

## 可點擊的卡片

不同於官方文件中介紹的卡片，這個卡片本身就是個連結，點擊後會跳轉到其他頁面。以下範例中，前兩張卡片是可點擊的卡片，第三張是普通的卡片，第四張則不是卡片。

```html
<div class="grid">

  <a class="card" href="../../../..">
    <h3>Home Page</h3>
    <hr>
    <p>This card links to the home page and uses the "h3 + horizontal rule + paragraph" style.</p>
  </a>

  <a class="card" href="https://www.avermedia.com" target="_blank">
    <h2>This Card Links to AVerMedia homepage</h2>
    <p>It is nice to have a consistent style, but actually you can put any content here.</p>
    <img src="https://picsum.photos/400/200" alt="Placeholder">
  </a>

  <div class="card">
    <p>You can also put a unclickable card in the grid. There are still some hover effects, but they do not make the card look clickable.</p>
  </div>

  <div>
    <img src="https://picsum.photos/400/100" alt="Placeholder">
    <p>Even an element which does not have the `card` class can be put in the grid. It will not have the appearance of a card, just aligned to the grid.</p>
  </div>

</div>
```

!!! warning

    -   在 MkDocs 中，生成出來的 html 檔所在位置，會和 Markdown 文件不太一樣，因此使用相對路徑時需要特別注意，要以生成出來的 html 檔為基準。舉例來說，`docs/foo/bar.md` 生成的 html 檔會位在 `/foo/bar/index.html`，因此雖然根目錄對 `bar.md` 來說是位在 `../`，但對 html 檔來說卻是位在 `../../`。
    -   使用此卡片時，請務必搭配自定義的 CSS 樣式，否則會有以下問題
        -   卡片文字會全部變成超連結的藍色，很醜。
        -   預設的卡片 hover 效果看起來並不像可以點擊的樣子。

    以下是筆者使用的 CSS 樣式，可以自行調整。

    ??? example "CSS 範例"

        ```css title="docs/assets/stylesheets/extra.css"
        /* Card colors */
        [data-md-color-scheme="default"] {
            --card-bg-color: hsl(var(--md-hue), 15%, 97%);
            --card-link-bg-color-hover: hsl(var(--md-hue), 15%, 92%);
        }

        [data-md-color-scheme="slate"] {
            --card-bg-color: hsl(var(--md-hue), 15%, 20%);
            --card-link-bg-color-hover: hsl(var(--md-hue), 15%, 25%);
        }

        /* Grid styles */
        .md-typeset .grid {
            grid-gap: .6rem;
        }

        /* Common styles for all the cards */
        .md-typeset .grid>.card, .md-typeset .grid.cards>ul>li {
            background-color: var(--card-bg-color);
            border: 0.1rem solid transparent;
            border-radius: 8px;
            padding: 1.5rem;
            transition:
                border-color 250ms ease,
                box-shadow 250ms ease,
                background-color 250ms ease;

            &:hover {
                border-color: var(--md-default-fg-color--lightest);
            }
        }

        /* Clickable cards */
        .md-typeset .grid>a.card {
            color: var(--md-default-fg-color);
            transition:
                box-shadow 250ms ease,
                background-color 250ms ease;

            &:hover {
                color: var(--md-default-fg-color);
                background-color: var(--card-link-bg-color-hover);
                border-color: transparent !important;
            }
        }
        ```

效果如下：

<div class="grid">

  <a class="card" href="../../../..">
    <h2>Home Page</h2>
    <p>This card links to the home page and uses the "h2 + paragraph" style.</p>
  </a>

  <a class="card" href="https://www.avermedia.com" target="_blank">
    <p>Link to AVerMedia homepage</p>
    <hr>
    <img src="https://picsum.photos/400/200" alt="Placeholder">
    <p>It is nice to have a consistent style, but actually you can put any content here. This card uses a `&lt;p&gt;` and a `&lt;hr&gt;` to make the title.</p>
  </a>

  <div class="card">
    <h2>Unclickable Card</h2>
    <p>You can also put a unclickable card in the grid. There are still some hover effects, but they do not make the card look clickable.</p>
  </div>

  <div>
    <img src="https://picsum.photos/400/100" alt="Placeholder">
    <p>Even an element which does not have the `card` class can be put in the grid. It will not have the appearance of a card, just aligned to the grid.</p>
  </div>

</div>

使用 HTML 來寫卡片還有另一個好處是，即使在卡片中使用了標題元素（如 `h2`），這個標題也不會出現在頁面目錄中。

!!! note

    目前有發現一個需要特別注意的限制是，將可點擊的卡片（`<a class="card">`）放到 Material for MkDocs 的提醒方塊（如現在這個）中時，卡片的樣式會整個跑掉，標題不知道為什麼會跑出卡片外。

## 帶說明文字（Caption）的圖片

使用時需要修改：

<div class="annotate" markdown>

- `src`: 圖片的路徑（網頁 URL 或本地路徑）
- `alt`: 圖片的替代文字(1)
- `<figcaption>` 的內容: 圖片的說明文字

</div>

1.  替代文字是當圖片無法顯示時，會顯示的文字。

```html
<figure>
    <img src="https://picsum.photos/600/200" alt="A Random Image">
    <figcaption>The caption for the image.</figcaption>
</figure>
```

??? example "Preview"

    <figure>
        <img src="https://picsum.photos/600/200" alt="A Random Image">
        <figcaption>The caption for the image.</figcaption>
    </figure>

