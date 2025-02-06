<template>
    <a :href="`https://codeforces.com/profile/${username}`" target="_blank"
        :style="{ color: textColor, fontWeight: 'bold', textDecoration: 'none' }">{{ username }}</a>
</template>

<script>
export default {
    props: {
        username: {
            type: String,
            required: true
        }
    },
    data() {
        return {
            textColor: '#000000'
        }
    },
    async mounted() {
        try {
            const response = await fetch(`https://codeforces.com/api/user.info?handles=${this.username}`)
            const data = await response.json()

            if (data.status === 'OK' && data.result.length > 0) {
                const user = data.result[0]
                this.textColor = this.getRankColor(user.rank || user.titlePhoto)
            }
        } catch (error) {
            console.error('Failed to fetch Codeforces data:', error)
        }
    },
    methods: {
        getRankColor(rank) {
            const colorMap = {
                'legendary grandmaster': '#FF0000',
                'international grandmaster': '#FF0000',
                'grandmaster': '#FF0000',
                'international master': '#FF8C00',
                'master': '#FF8C00',
                'candidate master': '#AA00AA',
                'expert': '#0000FF',
                'specialist': '#03A89E',
                'pupil': '#008000',
                'newbie': '#808080'
            }

            return colorMap[rank.toLowerCase()] || '#808080'
        }
    }
}
</script>