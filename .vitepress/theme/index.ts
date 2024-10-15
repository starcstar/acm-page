import DefaultTheme from 'vitepress/theme';
import './styles/custom.css';
import googleAnalytics from 'vitepress-plugin-google-analytics'

export default {
    ...DefaultTheme,
    enhanceApp: (ctx) => {
        googleAnalytics({
            id: 'GTM-KVJF8W5L', // Replace with your GoogleAnalytics ID, which should start with the 'G-'
        })
    }
}