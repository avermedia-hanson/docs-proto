# HTML 區塊

這邊的內容還很少，未來如果發現了其他好用的 HTML 區塊，會集中在這邊。

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

