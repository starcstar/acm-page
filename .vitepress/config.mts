import { defineConfig } from "vitepress";
import { generateSidebar } from "vitepress-sidebar";

const vitepressSidebarOptions = {
  /* Options... */
  useTitleFromFrontmatter: true,
  useTitleFromFileHeading: true,
  useFolderTitleFromIndexFile: true,
  //includeFolderIndexFile: true,
  //includeRootIndexFile: true,
  useFolderLinkFromIndexFile: true,
  excludeFilesByFrontmatterFieldName: "marp",
  frontmatterTitleFieldName: "name",
  excludePattern: ["README.md"],
};

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "NUAAXCPC Wiki",
  description: "NUAA*CPC Team",
  lang: "zh-CN",
  sitemap: {
    hostname: "https://acm.starcstar.club",
  },
  lastUpdated: true,
  cleanUrls: true,
  head: [
    ["link", { rel: "icon", href: "/acm.png" }],
    [
      "script",
      {
        async: "",
        src: "https://www.googletagmanager.com/gtag/js?id=G-G8GBZPDD1F",
      },
    ],
    [
      "script",
      {},
      `window.dataLayer = window.dataLayer || [];
      function gtag(){dataLayer.push(arguments);}
      gtag('js', new Date());
      gtag('config', 'G-G8GBZPDD1F');`,
    ],
  ],
  themeConfig: {
    logo: "/acm.png",
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "主页", link: "/" },
      { text: "2024秋 新生培训", link: "/2024fall" },
      { text: "2024 新生赛", link: "/2024fc" },
      { text: "2025 寒假线上培训", link: "/2025wcamp" },
    ],
    outlineTitle: "目录",
    sidebar: generateSidebar(vitepressSidebarOptions),

    socialLinks: [
      { icon: "github", link: "https://github.com/starcstar/acm-page" },
    ],
    darkModeSwitchTitle: "切换主题",
    editLink: {
      pattern: "https://github.com/starcstar/acm-page/edit/main/:path",
      text: "在 GitHub 上编辑此页",
    },
    // 文章翻页
    docFooter: {
      prev: "上一篇",
      next: "下一篇",
    },

    // 移动端 - 外观
    darkModeSwitchLabel: "外观",

    // 移动端 - 返回顶部
    returnToTopLabel: "返回顶部",

    // 移动端 - menu
    sidebarMenuLabel: "菜单",
    lastUpdated: {
      text: "上次更新于 ",
      formatOptions: {
        dateStyle: "full",
        timeStyle: "medium",
      },
    },
    search: {
      provider: "local",
    },
  },
  markdown: {
    math: true,
    lineNumbers: true,
  },
});
