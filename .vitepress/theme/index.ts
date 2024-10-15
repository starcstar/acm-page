import DefaultTheme from 'vitepress/theme';
import './styles/custom.css';
import googleAnalytics from 'vitepress-plugin-google-analytics'

export default {
    ...DefaultTheme,
    enhanceApp: (ctx) => {
        googleAnalytics({
            id: 'G-G8GBZPDD1F', // Replace with your GoogleAnalytics ID, which should start with the 'G-'
        })
    }
}