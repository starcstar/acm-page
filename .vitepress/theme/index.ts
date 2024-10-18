import { h } from 'vue';
import Theme from 'vitepress/theme';
import GiscusComment from './components/comment.vue';

export default {
    ...Theme,
    Layout() {
        return h(Theme.Layout, null, {
            'doc-after': () => h(GiscusComment),
        });
    },
};