import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "NUAAXCPC Wiki",
  description: "NUAA ACM Team",
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
            text: 'ACM 竞赛队新生培训 2024秋', link: '/2024fall',
            items: [
              { text: '第二周 C++语言基础', link: '/week2' }
            ]
          }
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/starcstar/acm-page' }
    ],
    docFooter: {
      prev: '上一篇',
      next: '下一篇'
    },
    darkModeSwitchTitle: '切换主题',
    editLink: {
      pattern: 'https://github.com/starcstar/acm-page/edit/main/:path',
      text: '在 GitHub 上编辑此页'
    },
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
    returnToTopLabel: '返回顶部',
    sidebarMenuLabel: '目录',
  },
  markdown: {
    math: true,
    lineNumbers: true
  }
})

