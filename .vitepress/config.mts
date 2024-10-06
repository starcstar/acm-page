import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "NUAAXCPC Wiki",
  description: "NUAA*CPC Team",
  lang: 'zh-CN',

  sitemap: {
    hostname: 'https://acm.starcstar.club'
  },
  lastUpdated: true,
  head: [
    ['link', { rel: 'icon', href: '/acm.png' }]
  ],
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: '主页', link: '/' },
      { text: 'ACM 竞赛队新生培训 2024秋', link: '/2024fall' }
    ],

    sidebar: [
      {
        text: 'NUAAXCPC Docs',
        items: [
          { text: '主页', link: '/' },
          {
            text: 'ACM 竞赛队新生培训 2024秋', link: '/2024fall/', items: [
              { text: 'Week2 C++ 语法基础 I', link: '/2024fall/week2' },
              { text: 'Week3 C++ 语法基础 Ⅱ', link: '/2024fall/week3' },
            ]
          }
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/starcstar/acm-page' }
    ],
    darkModeSwitchTitle: '切换主题',
    editLink: {
      pattern: 'https://github.com/starcstar/acm-page/edit/main/:path',
      text: '在 GitHub 上编辑此页'
    },
    // 文章翻页
    docFooter: {
      prev: '上一篇',
      next: '下一篇'
    },

    // 移动端 - 外观
    darkModeSwitchLabel: '外观',

    // 移动端 - 返回顶部
    returnToTopLabel: '返回顶部',

    // 移动端 - menu
    sidebarMenuLabel: '菜单',
    lastUpdated: {
      text: '上次更新于 ',
      formatOptions: {
        dateStyle: 'full',
        timeStyle: 'medium'
      }
    },
    search: {
      provider: 'local'
    },
  },
  markdown: {
    math: true,
    lineNumbers: true
  },

})

