import { defaultTheme } from '@vuepress/theme-default'
import { defineUserConfig } from 'vuepress/cli'
import { viteBundler } from '@vuepress/bundler-vite'

export default defineUserConfig({
  lang: 'zh-cn',

  title: 'NUAAXCPC Team',
  description: '南京航空航天大学ACM集训队',

  theme: defaultTheme({
    logo: '/images/acm.png',

    navbar: ['/', '/2024fall']
  }),

  bundler: viteBundler(),
})
