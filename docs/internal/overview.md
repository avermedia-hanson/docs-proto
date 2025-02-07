# Overview

## Theme/Plugin Features

Here lists some of the enabled features in this demo site. For the full list of features enabled, please take a look at the `mkdocs.yml` file.

### Navigation

- **Instant loading**: while navigating to an internal page, instead of reloading the whole page, only the content of the new page will be loaded. (The common elements like the header will stay the same, which makes the site look like a single-page application.)
- **Progress indicator**: a progress indicator will be shown at the top of the page if the page hasn't finished loading after 400 ms.
- **Tabs**: the top-level sections are rendered as tabs below the header. The left sidebar will only contain the sub-sections of the current tab.
- **Sticky tabs**: the tabs will stick to the top of the page when scrolling down.
- **Navigation sections**: the top-level sections are rendered as groups in the sidebar.
- **Back-to-top button**: a back-to-top button will be shown at the top of the page if the page is scrolled down.

For more details, please refer to the [Material for MkDocs](https://squidfunk.github.io/mkdocs-material/setup/setting-up-navigation/) documentation.

### Site Search

The built-in search plugin is enabled.

- **Search suggestions**: when typing in the search box, the search plugin will show the most likely completion which can be accepted with `→ Right` key.
- **Search highlight**: the search results will be highlighted with the color of the theme.
