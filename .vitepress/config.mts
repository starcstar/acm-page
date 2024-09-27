import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "NUAAXCPC Docs",
  description: "NUAA ACM Team",
  lang: 'zh-CN',
  sitemap: {
    hostname: 'https://acm.starcstar.club'
  },
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
              { text: '第二周', link: '/week2' }
            ]
          }
        ]
      }
    ],

    socialLinks: [
      { icon: 'github', link: 'https://github.com/starcstar/acm-page' }
    ]
  },
  markdown: {
    math: true,
    lineNumbers: true
  }
})

