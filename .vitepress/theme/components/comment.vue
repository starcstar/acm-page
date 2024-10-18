<template>
    <div style="margin-top: 24px">
        <Giscus
            id="comments"
            repo="starcstar/acm-page"
            repoid="R_kgDOM3nDrA"
            category="Announcements"
            categoryid="DIC_kwDOM3nDrM4CjeF-"
            mapping="title"
            term="Welcome to giscus!"
            reactionsenabled="1"
            emitmetadata="0"
            inputposition="top"
            loading="lazy"
            lang="zh-CN"
            :theme="isDark ? 'dark' : 'light'"
            :key="route.path"
        ></Giscus>
    </div>
</template>

<script setup>
import Giscus from '@giscus/vue';
import { useRoute, useData } from 'vitepress';

const route = useRoute();
const { isDark } = useData();
</script>