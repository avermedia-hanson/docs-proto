@page examples Examples
<!-- # Examples -->

The subpages for each example can be handled with the `@subpage` command in Doxygen.

Unfortunately, although the markdown file path can be directly used in the `@subpage` command, the sub-pages specified in this way will be at the top level, instead of being nested in the current page. The use case 2 is an example for this case.

To have a nested structure, the writers have to:

1. Define the page ID in the markdown file for each example like the following:
   ```markdown
   @page use-case-1 Use Case 1
   ```
   Note that the `@page` command already defines the title (`Use Case 1`), so you should not add a markdown-style title again in the file.

2. In the parent page, use the `@subpage` command to link to the sub-page like:
   ```markdown
   - @subpage use-case-1
   ```

### Example subpages

- @subpage use-case-1
- @subpage examples/use-case-2.md

BTW, it seems like a subpage will have the same level as a 2nd-level heading of this page. Therefore, if the "Example subpages" heading above (it's h3) is changed to h2, the "Example subpages" will appear as a section in the sidebar, at the same level as the subpages.
