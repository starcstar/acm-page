import DefaultTheme from "vitepress/theme";
import Layout from "./Layout.vue";
import CodeforcesUser from "./components/CodeforcesUser.vue";

export default {
  extends: DefaultTheme,
  // 使用注入插槽的包装组件覆盖 Layout
  Layout: Layout,
  enhanceApp({ app }) {
    // 注册自定义全局组件
    app.component("CodeforcesUser", CodeforcesUser);
  },
};
