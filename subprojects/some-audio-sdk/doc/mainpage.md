@mainpage

# Home

The is the main page of the documentation for Some Audio SDK, and all the documentation is generated by Doxygen. The version is 0.7.

This is a markdown file. Normal markdown links to other markdown files will work properly:

```markdown
- [Getting Started](getting-started.md)
- [Examples](examples.md)
```

However, using the `@subpage` command to organize the pages makes them appear in the desired order in the sidebar, instead of the default alphabetical order:

- @subpage getting-started : the markdown features supported by Doxygen are demonstrated here.
- @subpage examples : some examples of how to use the `@subpage` command to organize the pages.

You can see the order of the subpages in the sidebar is the same as the order above, instead of the alphabetical order.

For the usage of the `@subpage` command, please refer to the @ref examples page.

### Pros

- All the pages are properly versioned by the configuration in `Doxyfile`.

### Cons

- The look and feel is too outdated for the tutorial- and guide-style documentation, which makes it look less professional.
- Only the main page, not the sub-sections, can be properly integrated into the sidebar of the site.
  > It is still possible to put the links of sub-sections in the site's sidebar, but users will feel like they just jump to another site.<br/>
  > Therefore, I personally prefer to just put the main page link in the sidebar, as an entry point.
- The markdown features supported by Doxygen are limited compared to `mkdocs-material`.
